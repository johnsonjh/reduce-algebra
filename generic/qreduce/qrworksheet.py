#!/usr/bin/env python
# ----------------------------------------------------------------------
# $Id$
# ----------------------------------------------------------------------
# Copyright (c) 2009-2010 Thomas Sturm
# ----------------------------------------------------------------------
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#    * Redistributions of source code must retain the relevant
#      copyright notice, this list of conditions and the following
#      disclaimer.
#    * Redistributions in binary form must reproduce the above
#      copyright notice, this list of conditions and the following
#      disclaimer in the documentation and/or other materials provided
#      with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

import sys

from types import StringType
from types import IntType

from PySide.QtCore import Qt
from PySide.QtCore import Signal
from PySide.QtCore import QObject

from PySide.QtGui import QTextEdit
from PySide.QtGui import QFont
from PySide.QtGui import QTextCursor
from PySide.QtGui import QMessageBox

from reduce import Reduce

from qrformats import ReduceBlockFormat
from qrformats import ReduceCharFormat

from qrxml import ReduceXmlReader
from qrxml import ReduceXmlWriter

from types import DictType
from types import StringType
from types import IntType


class QtReduceWorksheet(QTextEdit):
    fileName = ''
    modified = False
    fileNameChanged = Signal(StringType,IntType)
    newComputation = Signal(object)
    newResult = Signal(object)

    def __init__(self,parent=None):
        QTextEdit.__init__(self)
        self.parent = parent
        self.__initSignals()
        self.__initReduce()
        self.__initFont()
        self.__initFirstBlock()

    def __initSignals(self):
        self.textChanged.connect(self.textChangedHandler,
                                 type=Qt.DirectConnection)
        self.cursorPositionChanged.connect(self.cursorPositionChangedHandler,
                                           type=Qt.DirectConnection)

    def __initFont(self):
        self.setupFont(14)

    def setupFont(self,pt):
        font = self.font()
        font.setFamily('Courier')
        font.setFixedPitch(True)
        font.setKerning(0)
        font.setPixelSize(pt)
        font.setWeight(QFont.Normal)
        font.setItalic(False)
        self.setFont(font)

    def __initReduce(self):
        print "in __initReduce"
        self.reduce = Reduce(self)
        self.reduce.newResult.connect(self.newReduceResultHandler,
                                      type=Qt.DirectConnection)
        self.reduce.newComputation.connect(self.newReduceComputationHandler,
                                           type=Qt.DirectConnection)
        self.compute("load_package utf8;",True)
        self.compute("on utf8;",True)
        self.compute("on utf8exp;",True)
        self.compute("off utf82d;",True)
        self.compute("on utf8pad;",True)
        self.compute('lisp procedure lr_aprint(u); mathprint u;',True)
        self.compute("lisp if 'psl memq lispsystem!* then remd 'break;",True)

    def compute(self,c,silent=False):
        self.setReadOnly(True)
        self.reduce.compute(c,silent)
        self.setReadOnly(False)

    def newReduceResultHandler(self,rc):
        print "catching newReduceResult", rc.statCounter
        self.newResult.emit(rc)
        self.__renderOutput(rc)

    def newReduceComputationHandler(self,rc):
        self.newComputation.emit(rc)

    def __initFirstBlock(self):
        print "initFirstBlock"
        cursor = self.textCursor()
        cursor.movePosition(QTextCursor.Start)
        ReduceBlockFormat.labelBlock(cursor,0)
        self.setTextCursor(cursor)

    def keyPressEvent(self,ev):
        state = self.textCursor().block().userState()
        if state == 0:
            return self.__keyPressEvent0(ev)
        if state >= 1 and state <= 3:
            return self.__keyPressEvent1(ev)
        print "something's wrong: state = ", state

    def __keyPressEvent0(self,ev):
        if ev.key() == Qt.Key_Backspace:
            cursor = self.textCursor()
            block = cursor.block()
            if cursor.position()==block.position():
                return
        if (ev.key() == Qt.Key_Return or ev.key() == Qt.Key_Enter) and \
                not (ev.modifiers() & Qt.ShiftModifier):
            return self.__keyPressEvent0Return(ev)
        QTextEdit.keyPressEvent(self,ev)

    def __keyPressEvent0Return(self,ev):
        cursor = self.textCursor()
        block = cursor.block()
#        command = block.text().simplified().__str__().strip()
        command = block.text().__str__().strip()
        if command != '' and not command[-1] in [';','$']:
            command += ';'
        print "before compute(command)"
        output = self.compute(command)

    def __renderOutput(self,computation):
        here = self.textCursor().position()
        cursor = self.textCursor()
        block = cursor.block()
        nextblock = self.__getNextBlock(cursor,[1,2,3])
        if computation.error:
            ReduceBlockFormat.labelBlock(cursor,3)
            outp = computation.errorText
            outp = self.__filterOutput(outp)
            outp = self.__colorOutput(outp,"black")
            cursor.insertHtml(outp)
            cursor.setPosition(here)
            self.setTextCursor(cursor)
            return
        if computation.result:
            ReduceBlockFormat.labelBlock(cursor,1)
            outp = computation.result
            outp = outp.decode('utf-8')
            outp = self.__filterOutput(outp)
            outp = self.__colorOutput(outp,"blue")
            cursor.insertHtml(outp)
        else:
            ReduceBlockFormat.labelBlock(cursor,2)
            outp = self.__colorOutput("[no output]","gray")
            nextblock.setUserState(2)
            cursor.insertHtml(outp)
        nextblock = self.__getNextBlock(cursor,[0])
        ReduceBlockFormat.labelBlock(cursor,0)
        cursor.setPosition(nextblock.position())
        self.setTextCursor(cursor)

    def __keyPressEvent1(self,ev):
        if ev.key() in [Qt.Key_Left,Qt.Key_Up,Qt.Key_Right,Qt.Key_Down]:
            QTextEdit.keyPressEvent(self,ev)
        return

    def __getNextBlock(self,cursor,format):
        cursor.movePosition(QTextCursor.EndOfBlock)
        block = cursor.block()
        nextblock = block.next()
        if nextblock and nextblock.userState() in format:
            cursor.movePosition(QTextCursor.Right)
#            print "reusing block", nextblock, nextblock.userState()
        else:
            cursor.insertBlock()
            nextblock = cursor.block()
#            print "new block", nextblock, format
        cursor.movePosition(QTextCursor.EndOfBlock)
        cursor.movePosition(QTextCursor.StartOfBlock,QTextCursor.KeepAnchor)
	return nextblock

    def __filterOutput(self,s):
        result = ""
        for c in s:
            if c == '\n':
                result += "<br>"
            elif c == ' ':
                result += "&nbsp;"
            elif c == '<':
                result += "&lt;"
            else:
                result += c
        return result

    def __colorOutput(self,s,c):
        if c == "blue":
            color = "color:#0000cc;"
        elif c == "gray":
            color = "color:#a0a0a0;"
        else:
            color = "color:black;"
        fontFamily = "" # "font-family:Courier,monospace;"
        size = "" # "size:14;"
        return '<span style="' + color + fontFamily + size + '">' + s + "</span>"

    def open(self,fileName):
        tempFileName = fileName
        if tempFileName == '':
            tempFileName = self.fileName
        xmlReader = ReduceXmlReader(self.document())
        try:
            xmlReader.open(tempFileName)
        except:
            QMessageBox.information(self,self.tr("Unable to open file"),
                                    str(sys.exc_info()[1]))
            return False
        self.modified = False
        self.fileName = tempFileName
        self.fileNameChanged.emit(self.fileName,0)
        self.parent.statusBar().showMessage("Read " + self.fileName)
        self.ensureCursorVisible()
        return True

    def save(self,fileName):
        tempFileName = fileName
        if tempFileName == '':
            tempFileName = self.fileName
        xmlWriter = ReduceXmlWriter(self.document())
        try:
            xmlWriter.save(tempFileName)
        except:
            QMessageBox.information(self,self.tr("Unable to save file"),
                                    str(sys.exc_info()[1]))
            return False
        self.modified = False
        self.fileName = tempFileName
        self.fileNameChanged.emit(self.fileName,0)
        self.parent.statusBar().showMessage("Wrote " + self.fileName)
        return True

    def textChangedHandler(self):
        print "in textChangedHandler", self.modified
        if not self.modified:
            self.modified = True
            self.parent.setTitle(self.fileName,1)

    def cursorPositionChangedHandler(self):
        self.parent.statusBar().clearMessage()

    def abortEvaluation(self):
        self.reduce.abortEvaluation()
       

# Python 2.5.4 (r254:67916, Jul  7 2009, 23:51:24) 
# [GCC 4.2.1 (Apple Inc. build 5646)] on darwin
# Type "help", "copyright", "credits" or "license" for more information.
# >>> import sys
# >>> from PySide import QtCore, QtGui
# >>> app = QtGui.QApplication(sys.argv)
# >>> ed = QtGui.QPlainTextEdit()
# >>> b = ed.textCursor().block()
# >>> b.setUserState(42)
# >>> b.userState()
# 42
# >>> print b.userState()
# 42
