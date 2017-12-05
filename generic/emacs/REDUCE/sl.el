;;; sl.el --- Standard LISP emulation

;; Copyright (C) 2017 Francis J. Wright

;;; Primitive Data Types
;;; ====================

;; integer -- probably OK

;; floating -- 1. is an integer in elisp but a float in sl. Otherwise probably OK.

;; id -- symbol in elisp. The sl escape chacacter is ! but the elisp
;; escape character is \. This may be a problem, but elisp allows any
;; character in a symbol, so any ! characters will just be part of the
;; symbol name. The distinction probably only matters for functions
;; like EXPLODE and COMPRESS. In sl, lower case letters are
;; automatically converted to upper case when the !*RAISE flag is
;; T. ***Requires modification of the elisp reader!***

;; string -- To include a double quote character in a string in sl
;; double it, but in elisp escaped it with \. ***Requires modification
;; of the elisp reader!***

;; dotted-pair, vector, function-pointer -- probably OK.

;; T and NIL -- elisp only recognises t and nil, not T and NIL. Let's
;; hope these symbols don't appear in source code!

;; ftype -- in sl, the set of ids {EXPR, FEXPR, MACRO} represents the
;; class of definable function types. ***I don't think elisp has this concept!***

;; comments -- in sl these begin with % but in elisp they begin with ;.

;; REMARK -- very little of REDUCE is written in Lisp notation and the
;; rest uses its own reader. I only need to be able to read the
;; bootstrap code, boot.sl, that defines RLISP. It is probably better
;; to edit boot.sl than to hack the elisp reader. Hence, probably only
;; some functions need defining or redefining.

;; Syntax tables are not used by the Emacs Lisp reader, which has its
;; own built-in syntactic rules which cannot be changed!

;;; FUNCTIONS
;;; =========


;;; Elementary Predicates
;;; =====================

;; ATOM(U:any):boolean eval, spread -- OK
;; Returns T if U is not a pair.
;; EXPR PROCEDURE ATOM(U);
;; NULL PAIRP U;

(defalias 'codep 'functionp
  "CODEP(U:any):boolean eval, spread
Returns T if U is a function-pointer.")

(defun constantp (u)
  "CONSTANTP(U:any):boolean eval, spread
Returns T if U is a constant (a number, string, function-pointer, or vector).
EXPR PROCEDURE CONSTANTP(U);
   NULL OR(PAIRP U, IDP U);"
  (null (or (consp u) (symbolp u))))

;; EQ(U:any, V:any):boolean eval, spread -- OK
;; Returns T if U points to the same object as V. EQ is not a reliable
;; comparison between numeric arguments.

(defalias 'eqn 'eql
  "EQN(U:any, V:any):boolean eval, spread
Returns T if U and V are EQ or if U and V are numbers and have
the same value and type.")

;; EQUAL(U:any, V:any):boolean eval, spread -- OK
;; Returns T if U and V are the same. Dotted-pairs are compared
;; recursively to the bottom levels of their trees. Vectors must have
;; identical dimensions and EQUAL values in all positions. Strings
;; must have identical characters. Function pointers must have EQ
;; values. Other atoms must be EQN equal.

(defalias 'fixp 'integerp
  "FIXP(U:any):boolean eval, spread
Returns T if U is an integer (a fixed number).")

;; FLOATP(U:any):boolean eval, spread -- OK
;; Returns T if U is a floating point number.

(defalias 'idp 'symbolp
  "IDP(U:any):boolean eval, spread
Returns T if U is an id.")

(defun minusp (u)
  "MINUSP(U:any):boolean eval, spread
Returns T if U is a number and less than 0. If U is not a number or
is a positive number, NIL is returned.
EXPR PROCEDURE MINUSP(U);
   IF NUMBERP U THEN LESSP(U, 0) ELSE NIL;"
  (if (numberp u) (< u 0)))

;; NULL(U:any):boolean eval, spread -- OK
;; Returns T if U is NIL.
;; EXPR PROCEDURE NULL(U);
;; U EQ NIL;

;; NUMBERP(U:any):boolean eval, spread -- OK
;; Returns T if U is a number (integer or floating).
;; EXPR PROCEDURE NUMBERP(U);
;; IF OR(FIXP U, FLOATP U) THEN T ELSE NIL;

(defun onep (u)
  "ONEP(U:any):boolean eval, spread.
Returns T if U is a number and has the value 1 or 1.0. Returns NIL
otherwise.
EXPR PROCEDURE ONEP(U);
   OR(EQN(U, 1), EQN(U, 1.0));"
  ((or (eql u 1) (eql u 1.0))))

(defalias 'pairp 'consp
  "PAIRP(U:any):boolean eval, spread
Returns T if U is a dotted-pair.")

;; STRINGP(U:any):boolean eval, spread -- OK
;; Returns T if U is a string.

;; VECTORP(U:any):boolean eval, spread -- OK
;; Returns T if U is a vector.

;; ZEROP(U:any):boolean eval, spread -- OK
;; Returns T if U is a number and has the value 0 or 0.0. Returns NIL
;; otherwise.
;; EXPR PROCEDURE ZEROP(U);
;; OR(EQN(U, 0), EQN(U, 0.0));


;;; Functions on Dotted-Pairs
;;; =========================

;; CAR(U:dotted-pair ):any eval, spread -- OK
;; CAR(CONS(a, b)) --> a. The left part of U is returned. The type
;; mismatch error occurs if U is not a dotted-pair.

;; CDR(U:dotted-pair ):any eval, spread -- OK
;; CDR(CONS(a, b)) --> b. The right part of U is returned. The type
;; mismatch error occurs if U is not a dotted-pair.

;; The composites of CAR and CDR are supported up to 4 levels, namely: -- OK
;; CAAAAR CAAAR CAAR
;; CAAADR CAADR CADR
;; CAADAR CADAR CDAR
;; CAADDR CADDR CDDR
;; CADAAR CDAAR
;; CADADR CDADR
;; CADDAR CDDAR
;; CADDDR CDDDR
;; CDAAAR
;; CDAADR
;; CDADAR
;; CDADDR
;; CDDAAR
;; CDDADR
;; CDDDAR
;; CDDDDR

;; CONS(U:any, V:any):dotted-pair eval, spread -- OK
;; Returns a dotted-pair which is not EQ to anything and has U as its
;; CAR part and V as its CDR part.

;; LIST([U:any]):list noeval, nospread, or macro -- OK
;; A list of the evaluation of each element of U is returned. The order of
;; evaluation need not be first to last as the following definition implies.
;; FEXPR PROCEDURE LIST(U);
;; EVLIS U;

(defun sl--rplaca-override (u v)
  ;; Redefinition because elisp rplaca returns the wrong value.
  ;; rplaca is not used in Emacs source.
  ;; rplaca in elisp is an alias for ‘setcar’.
  "RPLACA(U:dotted-pair, V:any):dotted-pair eval, spread
The CAR portion of the dotted-pair U is replaced by V. If dotted-
pair U is (a . b) then (V . b) is returned. The type mismatch error
occurs if U is not a dotted-pair."
  (setcar u v)
  u)

(defun sl--rplacd-override (u v)
  ;; Redefinition because elisp rplacd returns the wrong value.
  ;; rplacd is used occasionally in Emacs source.
  ;; rplacd in elisp is an alias for ‘setcdr’.
  "RPLACD(U:dotted-pair, V:any):dotted-pair eval, spread
The CDR portion of the dotted-pair U is replaced by V. If dotted-
pair U is (a . b) then (a . V) is returned. The type mismatch error
occurs if U is not a dotted-pair."
  (setcdr u v)
  u)


;;; Identifiers
;;; ===========

(defun compress (u)
  "COMPRESS(U:id-list):{atom-vector} eval, spread
U is a list of single character identifiers which is built into a Standard
LISP entity and returned. Recognized are numbers, strings, and
identifiers with the escape character prefixing special characters. The
formats of these items appear in \"Primitive Data Types\" section 2.1
on page 3. Identifiers are not interned on the OBLIST. Function
pointers may be compressed but this is an undefined use. If an entity
cannot be parsed out of U or characters are left over after parsing
an error occurs:
***** Poorly formed atom in COMPRESS"
  ;; Compress a list of ids into a single (uninterned) id.
  (make-symbol (mapconcat 'symbol-name u "")))

(defun explode (u)
  "EXPLODE(U:{atom}-{vector}):id-list eval, spread
Returned is a list of interned characters representing the characters to
print of the value of U. The primitive data types have these formats:
integer -- Leading zeroes are suppressed and a minus sign prefixes the
  digits if the integer is negative.
floating -- The value appears in the format [-]0.nn...nnE[-]mm if the
  magnitude of the number is too large or small to display in
  [-]nnnn.nnnn format. The crossover point is determined by the
  implementation.
id -- The characters of the print name of the identifier are produced
  with special characters prefixed with the escape character.
string -- The characters of the string are produced surrounded by
  double quotes \"...\".
function-pointer -- The value of the function-pointer is created as a
  list of characters conforming to the conventions of the system site.
The type mismatch error occurs if U is not a number, identifier,
string, or function-pointer."
  (seq-map (lambda (x) (intern (string x))) (prin1-to-string u)))

;; GENSYM():identifier eval, spread -- OK
;; Creates an identifier which is not interned on the OBLIST and con-
;; sequently not EQ to anything else.

;; INTERN(U:{id,string}):id eval, spread -- *maybe* OK (elisp does not allow id)
;; INTERN searches the OBLIST for an identifier with the same print
;; name as U and returns the identifier on the OBLIST if a match
;; is found. Any properties and global values associated with U may
;; be lost. If U does not match any entry, a new one is created and
;; returned. If U has more than the maximum number of characters
;; permitted by the implementation (the minimum number is 24) an
;; error occurs:
;; ***** Too many characters to INTERN

(defun remob (u)
  "REMOB(U:id):id eval, spread
If U is present on the OBLIST it is removed. This does not affect U
having properties, flags, functions and the like. U is returned."
  (unintern u)
  u)


;;; Property List Functions
;;; =======================

(defun flag (u v)
  "FLAG(U:id-list, V:id):NIL eval, spread
U is a list of ids which are flagged with V. The effect of FLAG is
that FLAGP will have the value T for those ids of U which were
flagged. Both V and all the elements of U must be identifiers or the
type mismatch error occurs."
  (mapc u (lambda (x) (put x v t))))	; SLISP mapc!

(defun flagp (u v)
  "FLAGP(U:any, V:any):boolean eval, spread
Returns T if U has been previously flagged with V, else NIL. Returns
NIL if either U or V is not an id."
  (get u v))

;; GET(U:any, IND:any):any eval, spread -- OK
;; Returns the property associated with indicator IND from the prop-
;; erty list of U. If U does not have indicator IND, NIL is returned.
;; GET cannot be used to access functions (use GETD instead).

;; PUT(U:id, IND:id, PROP:any):any eval, spread -- OK
;; The indicator IND with the property PROP is placed on the property
;; list of the id U. If the action of PUT occurs, the value of PROP is
;; returned. If either of U and IND are not ids the type mismatch error
;; will occur and no property will be placed. PUT cannot be used to
;; dene functions (use PUTD instead).

(defun remflag (u v)
  "REMFLAG(U:any-list, V:id):NIL eval, spread
Removes the flag V from the property list of each member of the
list U. Both V and all the elements of U must be ids or the type
mismatch error will occur."
  (mapc u (lambda (x) (put x v nil))))	; SLISP mapc!

(defun remprop (u ind)
  "REMPROP(U:any, IND:any):any eval, spread
Removes the property with indicator IND from the property list of U.
Returns the removed property or NIL if there was no such indicator."
  (prog1
	  (get u ind)
	(put u ind nil)))


;;; Function Definition
;;; ===================

(defmacro de (fname params fn)
  "DE(FNAME:id, PARAMS:id-list, FN:any):id noeval, nospread
The function FN with the formal parameter list PARAMS is added to
the set of defined functions with the name FNAME. Any previous
definitions of the function are lost. The function created is of
type EXPR. If the !*COMP variable is non-NIL, the EXPR is first
compiled. The name of the defined function is returned.
FEXPR PROCEDURE DE(U);
   PUTD(CAR U, 'EXPR, LIST('LAMBDA, CADR U, CADDR U));"
  (put fname 'type 'EXPR)
  `(defun ,fname ,params ,fn))

;; *** I'm hoping df is not actually required! ***
;; DF(FNAME:id, PARAM:id-list, FN:any):id noeval, nospread
;; The function FN with formal parameter PARAM is added to the set
;; of defined functions with the name FNAME. Any previous definitions
;; of the function are lost. The function created is of type FEXPR. If
;; the !*COMP variable is T the FEXPR is first compiled. The name
;; of the defined function is returned.
;; FEXPR PROCEDURE DF(U);
;;    PUTD(CAR U, 'FEXPR, LIST('LAMBDA, CADR U, CADDR U));

(defmacro dm (mname param fn)
  "DM(MNAME:id, PARAM:id-list, FN:any):id noeval, nospread
The macro FN with the formal parameter PARAM is added to the set
of defined functions with the name MNAME. Any previous
definitions of the function are overwritten. The function created
is of type MACRO. The name of the macro is returned.
FEXPR PROCEDURE DM(U);
   PUTD(CAR U, 'MACRO, LIST('LAMBDA, CADR U, CADDR U));"
  (put mname 'type 'MACRO)
  `(defmacro ,mname ,param ,fn))

(defun getd (fname)
  "GETD(FNAME:any):{NIL, dotted-pair} eval, spread
If FNAME is not the name of a defined function, NIL is returned. If
FNAME is a defined function then the dotted-pair
\(TYPE:ftype . DEF:{function-pointer, lambda})
is returned."
  (let ((def (symbol-function fname)))
	(if def (cons (get fname 'type) def))))

(defun putd (fname type body)
  "PUTD(FNAME:id, TYPE:ftype, BODY:function):id eval, spread
Creates a function with name FNAME and definition BODY of type
TYPE. If PUTD succeeds the name of the defined function is
returned. The effect of PUTD is that GETD will return a
dotted-pair with the functions type and definition. Likewise the
GLOBALP predicate will return T when queried with the function
name. If the function FNAME has already been declared as a
GLOBAL or FLUID variable the error:
***** FNAME is a non-local variable
occurs and the function will not be defined. If function FNAME
already exists a warning message will appear:
*** FNAME redefined
The function defined by PUTD will be compiled before definition if
the !*COMP global variable is non-NIL."
  (put fname 'type type)
  (fset fname body)
  fname)

(defun remd (fname)
  "REMD(FNAME:id):{NIL, dotted-pair} eval, spread
Removes the function named FNAME from the set of defined func-
tions. Returns the (ftype . function) dotted-pair or NIL as does
GETD. The global/function attribute of FNAME is removed and
the name may be used subsequently as a variable."
  (prog1
	  (get fname 'type)
	(fmakunbound fname)))


;;; Variables and Bindings
;;; ======================

(defun fluid (idlist)					; really almost a no-op!
  "FLUID(IDLIST:id-list):NIL eval, spread
The ids in IDLIST are declared as FLUID type variables (ids not
previously declared are initialized to NIL). Variables in IDLIST
already declared FLUID are ignored. Changing a variable's type
from GLOBAL to FLUID is not permissible and results in the error:
***** ID cannot be changed to FLUID"
  (mapc idlist							; SLISP mapc!
		(lambda (x)
		  (if (globalp x) (error "ID cannot be changed to FLUID"))
		  (if (not (fluidp x)) (set x nil))
		  (put x 'FLUID t))))

(defun fluidp (u)
  "FLUIDP(U:any):boolean eval, spread
If U has been declared FLUID (by declaration only) T is returned,
otherwise NIL is returned."
  (get u 'FLUID))

(defun global (idlist)					; really almost a no-op!
  "GLOBAL(IDLIST:id-list):NIL eval, spread
The ids of IDLIST are declared global type variables. If an id
has not been declared previously it is initialized to
NIL. Variables already declared GLOBAL are ignored. Changing a
variables type from FLUID to GLOBAL is not permissible and
results in the error:
***** ID cannot be changed to GLOBAL"
  (mapc idlist							; SLISP mapc!
		(lambda (x)
		  (if (fluidp x) (error "ID cannot be changed to GLOBAL"))
		  (if (not (globalp x)) (set x nil))
		  (put x 'GLOBAL t))))

(defun globalp (u)
  "GLOBALP(U:any):boolean eval, spread
If U has been declared GLOBAL or is the name of a defined function,
T is returned, else NIL is returned."
  (or (get u 'GLOBAL) (symbol-function u)))

;; SET(EXP:id, VALUE:any):any eval, spread -- OK
;; EXP must be an identifier or a type mismatch error occurs. The
;; effect of SET is replacement of the item bound to the identifier
;; by VALUE. If the identifier is not a local variable or has not
;; been declared GLOBAL it is automatically declared FLUID with the
;; resulting warning message:
;; *** EXP declared FLUID
;; EXP must not evaluate to T or NIL or an error occurs:
;; ***** Cannot change T or NIL

;; SETQ(VARIABLE:id, VALUE:any):any noeval, nospread -- OK
;; If VARIABLE is not local or GLOBAL it is by default declared
;; FLUID and the warning message:
;; *** VARIABLE declared FLUID
;; appears. The value of the current binding of VARIABLE is replaced
;; by the value of VALUE. VARIABLE must not be T or NIL or an
;; error occurs:
;; ***** Cannot change T or NIL
;; MACRO PROCEDURE SETQ(X);
;; LIST('SET, LIST('QUOTE, CADR X), CADDR X);

(defun unfluid (idlist)					; really a no-op!
  "UNFLUID(IDLIST:id-list):NIL eval, spread
The variables in IDLIST that have been declared as FLUID
variables are no longer considered as fluid variables. Others are
ignored. This affects only compiled functions as free variables
in interpreted functions are automatically considered fluid."
  (mapc idlist							; SLISP mapc!
		(lambda (x)
		  (if (fluidp x) (put x 'FLUID nil)))))

  
;;; Program Feature Functions
;;; =========================

;; (eval-when-compile (require 'cl-lib))
(require 'cl-lib)						; for now!

;; GO(LABEL:id) noeval, nospread -- OK in cl-tagbody
;; GO alters the normal flow of control within a PROG function. The
;; next statement of a PROG function to be evaluated is immediately
;; preceded by LABEL. A GO may only appear in the following situations:
;; 1. At the top level of a PROG referencing a label which also
;;    appears at the top level of the same PROG.
;; 2. As the consequent of a COND item of a COND appearing on the
;;    top level of a PROG.
;; 3. As the consequent of a COND item which appears as the
;;    consequent of a COND item to any level.
;; 4. As the last statement of a PROGN which appears at the top
;;    level of a PROG or in a PROGN appearing in the consequent of a
;;    COND to any level subject to the restrictions of 2 and 3.
;; 5. As the last statement of a PROGN within a PROGN or as the
;;    consequent of a COND in a PROGN to any level subject to the
;;    restrictions of 2, 3 and 4.
;; If LABEL does not appear at the top level of the PROG in which
;; the GO appears, an error occurs:
;; ***** LABEL is not a known label
;; If the GO has been placed in a position not defined by rules 1-5,
;; another error is detected:
;; ***** Illegal use of GO to LABEL

(defmacro prog (vars &rest program)
  "PROG(VARS:id-list, [PROGRAM:{id, any}]):any noeval, nospread
VARS is a list of ids which are considered fluid when the PROG is
interpreted and local when compiled. The PROGs variables are
allocated space when the PROG form is invoked and are deallocated
when the PROG is exited. PROG variables are initialized to
NIL. The PROGRAM is a set of expressions to be evaluated in order
of their appearance in the PROG function. Identifiers appearing
in the top level of the PROGRAM are labels which can be
referenced by GO. The value returned by the PROG function is
determined by a RETURN function or NIL if the PROG \"falls
through\"."
  `(let ,vars							; support local variables
	 (cl-block PROG						; support return
	   (cl-tagbody ,@program))))		; support labels

;; PROGN([U:any]):any noeval, nospread -- OK
;; U is a set of expressions which are executed sequentially. The value
;; returned is the value of the last expression.

;; PROG2(A:any, B:any)any eval, spread -- OK
;; Returns the value of B.
;; EXPR PROCEDURE PROG2(A, B);
;;    B;

(defmacro return (u)
  ;; Needs to be a macro to expand WITHIN the above prog form!
  "RETURN(U:any) eval, spread
Within a PROG, RETURN terminates the evaluation of a PROG
and returns U as the value of the PROG. The restrictions on the
placement of RETURN are exactly those of GO. Improper placement
of RETURN results in the error:
***** Illegal use of RETURN"
  `(cl-return-from PROG ,u))


;;; Error Handling
;;; ==============

(defun sl--error-override (&rest args)
  "ERROR(NUMBER:integer, MESSAGE:any) eval, spread
NUMBER and MESSAGE are passed back to a surrounding ERRORSET (the
Standard LISP reader has an ERRORSET). MESSAGE is placed in the
global variable EMSG!* and the error number becomes the value of
the surrounding ERRORSET. FLUID variables and local bindings are
unbound to return to the environment of the ERRORSET. Global
variables are not affected by the process."
  (if (integerp (car args))
	  ;; Standard Lisp mode
	  (let ((number (car args)) (message (cadr args)))
		(setq EMSG!* message)
		(signal 'user-error args))
	;; Emacs-Lisp mode
	(apply 'error args)))

(defun errorset (u msgp tr)
  "ERRORSET(U:any, MSGP:boolean, TR:boolean):any eval, spread
If an error occurs during the evaluation of U, the value of
NUMBER from the ERROR call is returned as the value of
ERRORSET. In addition, if the value of MSGP is non-NIL, the
MESSAGE from the ERROR call is displayed upon both the standard
output device and the currently selected output device unless the
standard output device is not open. The message appears prefixed
with 5 asterisks. The MESSAGE list is displayed without top level
parentheses. The MESSAGE from the ERROR call will be available in
the global variable EMSG!*. The exact format of error messages
generated by Standard LISP functions described in this document
are not fixed and should not be relied upon to be in any
particular form. Likewise, error numbers generated by Standard
LISP functions are implementation dependent.
If no error occurs during the evaluation of U, the value of
  (LIST (EVAL U)) is returned.
If an error has been signaled and the value of TR is non-NIL a
trace-back sequence will be initiated on the selected output
device. The traceback will display information such as unbindings
of FLUID variables, argument lists and so on in an implementation
dependent format."
  ;; Ignore tr argument for now!
  (condition-case err					; error description variable
	  (list (eval u))					; protected form
	(user-error						; Standard LISP error
	 (if msgp (let ((msg (cddr err)))
				(message "***** %s"
						 (if (listp msg)
							 (mapconcat 'identity msg " ")
						   msg))))
	 (cadr err))
	(error								; Emacs-Lisp error
	 (let ((msg (error-message-string err)))
	   (if msgp (message "***** %s" msg))
	   ;; Should return the error number, but internal elisp errors
	   ;; will not have one, so return the error message string
	   ;; instead. What matters is that an atom is returned.
	   msg))))


;;; Vectors
;;; =======

(defun getv (v index)
  "GETV(V:vector, INDEX:integer):any eval, spread
Returns the value stored at position INDEX of the vector V. The
type mismatch error may occur. An error occurs if the INDEX does
not lie within 0...UPBV(V) inclusive:
***** INDEX subscript is out of range"
  (aref v index))

(defun mkvect (uplim)
  "MKVECT(UPLIM:integer):vector eval, spread
Defines and allocates space for a vector with UPLIM+1 elements
accessed as 0...UPLIM. Each element is initialized to NIL. An error
will occur if UPLIM is < 0 or there is not enough space for a vector
of this size:
***** A vector of size UPLIM cannot be allocated"
  (make-vector (1+ uplim) nil))

(defun putv (v index value)
  "PUTV(V:vector, INDEX:integer, VALUE:any):any eval, spread
Stores VALUE into the vector V at position INDEX. VALUE is
returned. The type mismatch error may occur. If INDEX does not
lie in 0...UPBV(V) an error occurs:
***** INDEX subscript is out of range"
  (aset v index value))

(defun upbv (u)
  "UPBV(U:any):NIL,integer eval, spread
Returns the upper limit of U if U is a vector, or NIL if it is not."
  (if (vectorp u) (1- (length u))))


;;; Boolean Functions and Conditionals
;;; ==================================

;; AND([U:any]):extra-boolean noeval, nospread -- OK
;; AND evaluates each U until a value of NIL is found or the end of the
;; list is encountered. If a non-NIL value is the last value it is returned,
;; or NIL is returned.
;; FEXPR PROCEDURE AND(U);
;; BEGIN
;;    IF NULL U THEN RETURN NIL;
;; LOOP: IF NULL CDR U THEN RETURN EVAL CAR U
;;       ELSE IF NULL EVAL CAR U THEN RETURN NIL;
;;    U := CDR U;
;;    GO LOOP
;; END;

;; COND([U:cond-form]):any noeval, nospread -- OK
;; The antecedents of all U's are evaluated in order of their
;; appearance until a non-NIL value is encountered. The consequent
;; of the selected U is evaluated and becomes the value of the
;; COND. The consequent may also contain the special functions GO
;; and RETURN subject to the restraints given for these functions in
;; \"Program Feature Functions\", section 3.7 on page 22. In these
;; cases COND does not have a defined value, but rather an
;; effect. If no antecedent is non-NIL the value of COND is NIL. An
;; error is detected if a U is improperly formed:
;; ***** Improper cond-form as argument of COND

;; NOT(U:any):boolean eval, spread -- OK
;; If U is NIL, return T else return NIL (same as function NULL).
;; EXPR PROCEDURE NOT(U);
;;    U EQ NIL;

;; OR([U:any]):extra-boolean noeval, nospread -- OK
;; U is any number of expressions which are evaluated in order of their
;; appearance. When one is found to be non-NIL it is returned as the
;; value of OR. If all are NIL, NIL is returned.
;; FEXPR PROCEDURE OR(U);
;; BEGIN SCALAR X;
;; LOOP: IF NULL U THEN RETURN NIL
;;        ELSE IF (X := EVAL CAR U) THEN RETURN X;
;;    U := CDR U;
;;    GO LOOP
;; END;


;;; Arithmetic Functions
;;; ====================

;; ABS(U:number):number eval, spread -- OK
;; Returns the absolute value of its argument.
;; EXPR PROCEDURE ABS(U);
;;    IF LESSP(U, 0) THEN MINUS(U) ELSE U;

(defalias 'add1 '1+
  "ADD1(U:number):number eval, spread
Returns the value of U plus 1 of the same type as U (fixed or floating).
EXPR PROCEDURE ADD1(U);
   PLUS2(U, 1);")

(defalias 'difference '-
  "DIFFERENCE(U:number, V:number):number eval, spread
The value U - V is returned.")

(defun divide (u v)
  "DIVIDE(U:number, V:number):dotted-pair eval, spread
The dotted-pair (quotient . remainder) is returned. The quotient
part is computed the same as by QUOTIENT and the remainder
the same as by REMAINDER. An error occurs if division by zero is
attempted:
***** Attempt to divide by 0 in DIVIDE
EXPR PROCEDURE DIVIDE(U, V);
   (QUOTIENT(U, V) . REMAINDER(U, V));"
  (cons (/ u v) (% u v)))

;; EXPT(U:number, V:integer):number eval, spread -- OK
;; Returns U raised to the V power. A floating point U to an integer
;; power V does not have V changed to a floating number before
;; exponentiation.

(defalias 'fix 'truncate
  "FIX(U:number):integer eval, spread
Returns an integer which corresponds to the truncated value of U.
The result of conversion must retain all significant portions of U. If
U is an integer it is returned unchanged.")

;; FLOAT(U:number):floating eval, spread -- OK
;; The floating point number corresponding to the value of the
;; argument U is returned.  Some of the least significant digits of
;; an integer may be lost do to the implementation of floating point
;; numbers.  FLOAT of a floating point number returns the number
;; unchanged.  If U is too large to represent in floating point an
;; error occurs:
;; ***** Argument to FLOAT is too large

(defalias 'greaterp '>
  "GREATERP(U:number, V:number):boolean eval, spread
Returns T if U is strictly greater than V, otherwise returns NIL.")

(defalias 'lessp '<
  "LESSP(U:number, V:number):boolean eval, spread
Returns T if U is strictly less than V, otherwise returns NIL.")

;; MAX([U:number]):number noeval, nospread, or macro -- OK
;; Returns the largest of the values in U. If two or more values are the
;; same the first is returned.
;; MACRO PROCEDURE MAX(U);
;;    EXPAND(CDR U, 'MAX2);

(defalias 'max2 'max
  "MAX2(U:number, V:number):number eval, spread
Returns the larger of U and V. If U and V are the same value U is
returned (U and V might be of different types).
EXPR PROCEDURE MAX2(U, V);
   IF LESSP(U, V) THEN V ELSE U;")

;; MIN([U:number]):number noeval, nospread, or macro -- OK
;; Returns the smallest of the values in U. If two or more values are the
;; same the first of these is returned.
;; MACRO PROCEDURE MIN(U);
;;    EXPAND(CDR U, 'MIN2);

(defalias 'min2 'min
  "MIN2(U:number, V:number):number eval, spread
Returns the smaller of its arguments. If U and V are the same value,
U is returned (U and V might be of different types).
EXPR PROCEDURE MIN2(U, V);
   IF GREATERP(U, V) THEN V ELSE U;")

(defalias 'minus '-
  "MINUS(U:number):number eval, spread
Returns -U.
EXPR PROCEDURE MINUS(U);
   DIFFERENCE(0, U);")

(defalias 'plus '+
  "PLUS([U:number]):number noeval, nospread, or macro
Forms the sum of all its arguments.
MACRO PROCEDURE PLUS(U);
   EXPAND(CDR U, 'PLUS2);")

(defalias 'plus2 '+
  "PLUS2(U:number, V:number):number eval, spread
Returns the sum of U and V.")

(defalias 'quotient '/
  "QUOTIENT(U:number, V:number):number eval, spread
The quotient of U divided by V is returned. Division of two positive
or two negative integers is conventional. When both U and V are
integers and exactly one of them is negative the value returned is
the negative truncation of the absolute value of U divided by the
absolute value of V. An error occurs if division by zero is attempted:
***** Attempt to divide by 0 in QUOTIENT")

(defalias 'remainder '%
  "REMAINDER(U:number, V:number):number eval, spread
If both U and V are integers the result is the integer remainder of
U divided by V. If either parameter is floating point, the result is
the difference between U and V*(U/V) all in floating point. If either
number is negative the remainder is negative. If both are positive or
both are negative the remainder is positive. An error occurs if V is
zero:
***** Attempt to divide by 0 in REMAINDER
EXPR PROCEDURE REMAINDER(U, V);
   DIFFERENCE(U, TIMES2(QUOTIENT(U, V), V));")

(defalias 'sub1 '1-
  "SUB1(U:number):number eval, spread
Returns the value of U less 1. If U is a FLOAT type number, the
value returned is U less 1.0.
EXPR PROCEDURE SUB1(U);
   DIFFERENCE(U, 1);")

(defalias 'times '*
  "TIMES([U:number]):number noeval, nospread, or macro
Returns the product of all its arguments.
MACRO PROCEDURE TIMES(U);
   EXPAND(CDR U, 'TIMES2);")

(defalias 'times2 '*
  "TIMES2(U:number, V:number):number eval, spread
Returns the product of U and V.")


;;; MAP Composite Functions
;;; =======================

(defun map (x fn)
  "MAP(X:list, FN:function):any eval, spread
Applies FN to successive CDR segments of X. NIL is returned.
EXPR PROCEDURE MAP(X, FN);
   WHILE X DO << FN X; X := CDR X >>;"
  (while x
	(fn x)
	(setq x (cdr x))))

(defun sl--mapc-filter-args (args)
  "Swap args if function is not first."
  (if (functionp (car args))
	  args								; Elisp mode
	(reverse args)))					; Standard Lisp mode

(defun sl--mapc-filter-return (value)
  "Return nil."
  nil)

;; MAPC(X:list, FN:function):any eval, spread -- OK except for arg order & value!
;; FN is applied to successive CAR segments of list X. NIL is returned.
;; EXPR PROCEDURE MAPC(X, FN);
;;    WHILE X DO << FN CAR X; X := CDR X >>;

;; MAPCAN(X:list, FN:function):any eval, spread -- OK except for arg order!
;; A concatenated list of FN applied to successive CAR elements of X
;; is returned.
;; EXPR PROCEDURE MAPCAN(X, FN);
;;    IF NULL X THEN NIL
;;       ELSE NCONC(FN CAR X, MAPCAN(CDR X, FN));

;; MAPCAR(X:list, FN:function):any eval, spread -- OK except for arg order!
;; Returned is a constructed list of FN applied to each CAR of list X.
;; EXPR PROCEDURE MAPCAR(X, FN);
;;    IF NULL X THEN NIL
;;       ELSE FN CAR X . MAPCAR(CDR X, FN);

(defun mapcon (x fn)
  "MAPCON(X:list, FN:function):any eval, spread
Returned is a concatenated list of FN applied to successive CDR
segments of X.
EXPR PROCEDURE MAPCON(X, FN);
   IF NULL X THEN NIL
      ELSE NCONC(FN X, MAPCON(CDR X, FN));"
  (if x	(nconc (fn x) (mapcon (cdr x) fn))))

(defun maplist (x fn)
  "MAPLIST(X:list, FN:function):any eval, spread
Returns a constructed list of FN applied to successive CDR segments
of X.
EXPR PROCEDURE MAPLIST(X, FN);
   IF NULL X THEN NIL
      ELSE FN X . MAPLIST(CDR X, FN);"
  (if x (cons (fn x) (maplist (cdr x) fn))))


;;; Composite Functions
;;; ===================

;; APPEND(U:list, V:list):list eval, spread -- OK
;; Returns a constructed list in which the last element of U is followed
;; by the first element of V. The list U is copied, V is not.
;; EXPR PROCEDURE APPEND(U, V);
;;    IF NULL U THEN V
;;       ELSE CAR U . APPEND(CDR U, V);

;; ASSOC(U:any, V:alist):{dotted-pair, NIL} eval, spread -- OK
;; If U occurs as the CAR portion of an element of the alist V, the
;; dotted-pair in which U occurred is returned, else NIL is
;; returned.  ASSOC might not detect a poorly formed alist so an
;; invalid construction may be detected by CAR or CDR.
;; EXPR PROCEDURE ASSOC(U, V);
;;    IF NULL V THEN NIL
;;       ELSE IF ATOM CAR V THEN
;;          ERROR(000, LIST(V, "is a poorly formed alist"))
;;       ELSE IF U = CAAR V THEN CAR V
;;       ELSE ASSOC(U, CDR V);

(defun deflist (u ind)
  "DEFLIST(U:dlist, IND:id):list eval, spread
A \"dlist\" is a list in which each element is a two element list: (ID:id
PROP:any). Each ID in U has the indicator IND with property
PROP placed on its property list by the PUT function. The value
of DEFLIST is a list of the first elements of each two element list.
Like PUT, DEFLIST may not be used to define functions.
EXPR PROCEDURE DEFLIST(U, IND);
   IF NULL U THEN NIL
      ELSE << PUT(CAAR U, IND, CADAR U);
              CAAR U >> . DEFLIST(CDR U, IND);"
  (when u
	(put (caar u) ind (cadar u))
	(cons (caar u) (deflist (cdr u) ind))))

;; DELETE(U:any, V:list ):list eval, spread -- OK except for multiple deletion!
;; Returns V with the first top level occurrence of U removed from it.
;; EXPR PROCEDURE DELETE(U, V);
;;    IF NULL V THEN NIL
;;       ELSE IF CAR V = U THEN CDR V
;;       ELSE CAR V . DELETE(U, CDR V);

(defun digit (u)
  "DIGIT(U:any):boolean eval, spread
Returns T if U is a digit, otherwise NIL.
EXPR PROCEDURE DIGIT(U);
   IF MEMQ(U, '(!0 !1 !2 !3 !4 !5 !6 !7 !8 !9))
      THEN T ELSE NIL;"
  (if (memq u '(!0 !1 !2 !3 !4 !5 !6 !7 !8 !9)) t))

;; LENGTH(X:any):integer eval, spread -- OK
;; The top level length of the list X is returned.
;; EXPR PROCEDURE LENGTH(X);
;;    IF ATOM X THEN 0
;;       ELSE PLUS(1, LENGTH CDR X);

(defun liter (u)
  "LITER(U:any):boolean eval, spread
Returns T if U is a character of the alphabet, NIL otherwise.
EXPR PROCEDURE LITER(U);
   IF MEMQ(U, '(!A !B !C !D !E !F !G !H !I !J !K !L !M
                !N !O !P !Q !R !S !T !U !V !W !X !Y !Z
                !a !b !c !d !e !f !g !h !i !j !k !l !m
                !n !o !p !q !r !s !t !u !v !w !x !y !z))
      THEN T ELSE NIL;"
  (if (memq u '(!A !B !C !D !E !F !G !H !I !J !K !L !M
                !N !O !P !Q !R !S !T !U !V !W !X !Y !Z
                !a !b !c !d !e !f !g !h !i !j !k !l !m
                !n !o !p !q !r !s !t !u !v !w !x !y !z))
	  t))

;; MEMBER(A:any, B:list):extra-boolean eval, spread -- OK
;; Returns NIL if A is not a member of list B, returns the remainder of
;; B whose first element is A.
;; EXPR PROCEDURE MEMBER(A, B);
;;    IF NULL B THEN NIL
;;       ELSE IF A = CAR B THEN B
;;       ELSE MEMBER(A, CDR B);

;; MEMQ(A:any, B:list):extra-boolean eval, spread -- OK
;; Same as MEMBER but an EQ check is used for comparison.
;; EXPR PROCEDURE MEMQ(A, B);
;;    IF NULL B THEN NIL
;;       ELSE IF A EQ CAR B THEN B
;;       ELSE MEMQ(A, CDR B);

;; NCONC(U:list, V:list):list eval, spread -- OK
;; Concatenates V to U without copying U. The last CDR of U is
;; modified to point to V.
;; EXPR PROCEDURE NCONC(U, V);
;; BEGIN SCALAR W;
;;    IF NULL U THEN RETURN V;
;;    W := U;
;;    WHILE CDR W DO W := CDR W;
;;    RPLACD(W, V);
;;    RETURN U
;; END;

(defun pair (u v)
  "PAIR(U:list, V:list):alist eval, spread
U and V are lists which must have an identical number of elements.
If not, an error occurs (the 000 used in the ERROR call is arbitrary
and need not be adhered to). Returned is a list where each element
is a dotted-pair, the CAR of the pair being from U, and the CDR
the corresponding element from V.
EXPR PROCEDURE PAIR(U, V);
   IF AND(U, V) THEN (CAR U . CAR V) . PAIR(CDR U, CDR V)
      ELSE IF OR(U, V) THEN ERROR(000,
         \"Different length lists in PAIR\")
      ELSE NIL;"
  (cond ((and u v) (cons (cons (car u) (car v)) (pair (cdr u) (cdr v))))
		((or u v) (error "%s" "000 Different length lists in PAIR"))))

;; REVERSE(U:list):list eval, spread -- OK
;; Returns a copy of the top level of U in reverse order.
;; EXPR PROCEDURE REVERSE(U);
;; BEGIN SCALAR W;
;;    WHILE U DO << W := CAR U . W;
;;                  U := CDR U >>;
;;    RETURN W
;; END;

(defun sassoc (u v fn)
  "SASSOC(U:any, V:alist, FN:function):any eval, spread
Searches the alist V for an occurrence of U. If U is not in the alist
the evaluation of function FN is returned.
EXPR PROCEDURE SASSOC(U, V, FN);
   IF NULL V THEN FN()
      ELSE IF U = CAAR V THEN CAR V
      ELSE SASSOC(U, CDR V, FN);"
  (cond ((null v) (fn))
		((equal u (caar v)) (car v))
		(t (sassoc u (cdr v) fn))))

(defun sublis (x y)
  "SUBLIS(X:alist, Y:any):any eval, spread
The value returned is the result of substituting the CDR of each
element of the alist X for every occurrence of the CAR part of that
element in Y.
EXPR PROCEDURE SUBLIS(X, Y);
   IF NULL X THEN Y
      ELSE BEGIN SCALAR U;
                 U := ASSOC(Y, X);
                 RETURN IF U THEN CDR U
                        ELSE IF ATOM Y THEN Y
                        ELSE SUBLIS(X, CAR Y) .
                             SUBLIS(X, CDR Y)
                 END;"
  (if (null x)
	  y
	(let ((u (assoc y x)))
	  (cond (u (cdr u))
			((atom y) y)
			(t (cons (sublis x (car y)) (sublis x (cdr y))))))))

(defun subst (u v w)
  "SUBST(U:any, V:any, W:any):any eval, spread
The value returned is the result of substituting U for all occurrences
of V in W.
EXPR PROCEDURE SUBST(U, V, W);
   IF NULL W THEN NIL
      ELSE IF V = W THEN U
      ELSE IF ATOM W THEN W
      ELSE SUBST(U, V, CAR W) . SUBST(U, V, CDR W);"
  (cond ((null w) nil)
		((equal v w) u)
		((atom w) w)
		(t (cons (subst u v (car w)) (subst u v (cdr w))))))


;;; The Interpreter
;;; ===============

;; APPLY(FN:{id,function}, ARGS:any-list):any eval, spread -- OK
;; APPLY returns the value of FN with actual parameters ARGS. The
;; actual parameters in ARGS are already in the form required for
;; binding to the formal parameters of FN. Implementation specific
;; portions described in English are enclosed in boxes.
;; EXPR PROCEDURE APPLY(FN, ARGS);
;; BEGIN SCALAR DEFN;
;;    IF CODEP FN THEN RETURN
;;       | Spread the actual parameters in ARGS
;; 	  | following the conventions: for calling
;; 	  | functions, transfer to the entry point
;; 	  | of the function, and return the value
;; 	  | returned by the function.;
;;    IF IDP FN THEN RETURN
;; 	  IF NULL(DEFN := GETD FN) THEN
;; 	     ERROR(000, LIST(FN, "is an undefined function"))
;; 	  ELSE IF CAR DEFN EQ 'EXPR THEN
;; 	     APPLY(CDR DEFN, ARGS)
;; 	  ELSE ERROR(000,
;; 	     LIST(FN, "cannot be evaluated by APPLY"));
;;    IF OR(ATOM FN, NOT(CAR FN EQ 'LAMBDA)) THEN
;;       ERROR(000,
;;          LIST(FN, "cannot be evaluated by APPLY"));
;;    RETURN
;;       | Bind the actual parameters in ARGS to
;;       | the formal parameters of the lambda
;;       | expression. If the two lists are not
;;       | of equal length then ERROR(000, \"Number
;;       | of parameters do not match\"); The value
;;       | returned is EVAL CADDR FN.
;; END;

;; EVAL(U:any):any eval, spread -- OK
;; The value of the expression U is computed. Error numbers are
;; arbitrary. Portions of EVAL involving machine specific coding are
;; expressed in English enclosed in boxes.
;; EXPR PROCEDURE EVAL(U);
;; BEGIN SCALAR FN;
;;    IF CONSTANTP U THEN RETURN U;
;;    IF IDP U THEN RETURN
;;       | U is an id. Return the value most
;;       | currently bound to U or if there
;;       | is no such binding: ERROR(000,
;;       | LIST(\"Unbound:\", U));
;;    IF PAIRP CAR U THEN RETURN
;; 	  IF CAAR U EQ 'LAMBDA THEN APPLY(CAR U, EVLIS CDR U)
;; 	  ELSE ERROR(000, LIST(CAR U,
;; 	     \"improperly formed LAMBDA expression\"))
;; 	  ELSE IF CODEP CAR U THEN
;; 	     RETURN APPLY(CAR U, EVLIS CDR U);
;;    FN := GETD CAR U;
;;    IF NULL FN THEN
;;       ERROR(000, LIST(CAR U, \"is an undefined function\"))
;;    ELSE IF CAR FN EQ 'EXPR THEN
;;       RETURN APPLY(CDR FN, EVLIS CDR U)
;;    ELSE IF CAR FN EQ 'FEXPR THEN
;;       RETURN APPLY(CDR FN, LIST CDR U)
;;    ELSE IF CAR FN EQ 'MACRO THEN
;;       RETURN EVAL APPLY(CDR FN, LIST U)
;; END;

(defun evlis (u)
  "EVLIS(U:any-list):any-list eval, spread
EVLIS returns a list of the evaluation of each element of U.
EXPR PROCEDURE EVLIS(U);
   IF NULL U THEN NIL
      ELSE EVAL CAR U . EVLIS CDR U;"
  (if u (cons (eval car u) (evlis (cdr u)))))

(defun expand (l fn)
  "EXPAND(L:list, FN:function):list eval, spread
FN is a defined function of two arguments to be used in the expansion
of a MACRO. EXPAND returns a list in the form:
   (FN L0 (FN L1 ... (FN Ln-1 Ln) ... ))
where n is the number of elements in L, Li is the ith element of L.
EXPR PROCEDURE EXPAND(L,FN);
   IF NULL CDR L THEN CAR L
      ELSE LIST(FN, CAR L, EXPAND(CDR L, FN));"
  (if (null (cdr l))
	  (car l)
	(list fn (car l) (expand (cdr l) fn))))

;; FUNCTION(FN:function):function noeval, nospread -- OK
;; The function FN is to be passed to another function. If FN is to have
;; side effects its free variables must be fluid or global. FUNCTION is
;; like QUOTE but its argument may be affected by compilation. We
;; do not consider FUNARGs in this report.

;; QUOTE(U:any):any noeval, nospread -- OK
;; Stops evaluation and returns U unevaluated.
;; FEXPR PROCEDURE QUOTE(U);
;;    CAR U;


;;; Input and Output
;;; ================

(defun close (filehandle)
  "CLOSE(FILEHANDLE:any):any eval, spread
Closes the file with the internal name FILEHANDLE writing any
necessary end of file marks and such. The value of FILEHANDLE
is that returned by the corresponding OPEN. The value returned is
the value of FILEHANDLE. An error occurs if the file can not be
closed.
***** FILEHANDLE could not be closed"
  filehandle)

(defun eject ()
  "EJECT():NIL eval, spread
Skip to the top of the next output page. Automatic EJECTs are
executed by the print functions when the length set by the PAGE-
LENGTH function is exceeded."
  nil)

(defun linelength (len)
  "LINELENGTH(LEN:{integer, NIL}):integer eval, spread
If LEN is an integer the maximum line length to be printed before
the print functions initiate an automatic TERPRI is set to the value
LEN. No initial Standard LISP line length is assumed. The previous
line length is returned except when LEN is NIL. This special case
returns the current line length and does not cause it to be reset. An
error occurs if the requested line length is too large for the currently
selected output file or LEN is negative or zero.
***** LEN is an invalid line length"
  nil)

(defun lposn ()
  "LPOSN():integer eval, spread
Returns the number of lines printed on the current page. At the top
of a page, 0 is returned."
  0)

(defun open (file how)
  "OPEN(FILE:any, HOW:id):any eval, spread
Open the file with the system dependent name FILE for output if
HOW is EQ to OUTPUT, or input if HOW is EQ to INPUT. If the
file is opened successfully, a value which is internally associated with
the file is returned. This value must be saved for use by RDS and
WRS. An error occurs if HOW is something other than INPUT or
OUTPUT or the file can't be opened.
***** HOW is not option for OPEN
***** FILE could not be opened"
  nil)

(defun pagelength (len)
  "PAGELENGTH(LEN:{integer, NIL}):integer eval, spread
Sets the vertical length (in lines) of an output page. Automatic page
EJECTs are executed by the print functions when this length is
reached. The initial vertical length is implementation specific. The
previous page length is returned. If LEN is 0, no automatic page
ejects will occur."
  nil)

(defun posn ()
  "POSN():integer eval, spread
Returns the number of characters in the output buffer. When the
buffer is empty, 0 is returned."
  0)

;; PRINC(U:id):id eval, spread -- OK probably
;; U must be a single character id such as produced by EXPLODE or
;; read by READCH or the value of !$EOL!$. The effect is the character
;; U displayed upon the currently selected output device. The value of
;; !$EOL!$ causes termination of the current line like a call to TERPRI.

;; PRINT(U:any):any eval, spread -- OK probably
;; Displays U in READ readable format and terminates the print line.
;; The value of U is returned.
;; EXPR PROCEDURE PRINT(U);
;; << PRIN1 U; TERPRI(); U >>;

;; PRIN1(U:any):any eval, spread -- OK probably
;; U is displayed in a READ readable form. The format of display is
;; the result of EXPLODE expansion; special characters are prefixed
;; with the escape character !, and strings are enclosed in "...". Lists
;; are displayed in list-notation and vectors in vector-notation.

(defalias 'prin2 'princ
  "PRIN2(U:any):any eval, spread
U is displayed upon the currently selected print device but output is
not READ readable. The value of U is returned. Items are displayed
as described in the EXPLODE function with the exceptions that
the escape character does not prefix special characters and strings
are not enclosed in \"...\". Lists are displayed in list-notation and
vectors in vector-notation. The value of U is returned.")

(defun rds (filehandle)					; temporary no-op
  "RDS(FILEHANDLE:any):any eval, spread
Input from the currently selected input file is suspended and
further input comes from the file named. FILEHANDLE is a system
dependent internal name which is a value returned by OPEN. If
FILEHANDLE is NIL the standard input device is selected. When end
of file is reached on a non-standard input device, the standard
input device is reselected. When end of file occurs on the
standard input device the Standard LISP reader terminates. RDS
returns the internal name of the previously selected input file.
***** FILEHANDLE could not be selected for input"
  nil)

;; READ():any -- OK probably
;; The next expression from the file currently selected for
;; input. Valid input forms are: vector-notation, dot-notation,
;; list-notation, numbers, function-pointers, strings, and
;; identifiers with escape characters. Identifiers are interned on
;; the OBLIST (see the INTERN function in "Identifiers"). READ
;; returns the value of !$EOF!$ when the end of the currently
;; selected input file is reached.

(defun readch ()			  ; *Standard LISP* buffer only at present!
  "READCH():id
Returns the next interned character from the file currently selected
for input. Two special cases occur. If all the characters in an input
record have been read, the value of !$EOL!$ is returned. If the file
selected for input has all been read the value of !$EOF!$ is returned.
Comments delimited by % and end-of-line are not transparent to READCH."
  (with-current-buffer "*Standard LISP*"
	(goto-char sl-marker)
	(cond ((eobp) !$eof!$)
		  ((eolp) (forward-line)
		   (set-marker sl-marker (point)) !$eol!$)
		  (t (let ((ch (char-after sl-marker)))
			   (set-marker sl-marker (1+ sl-marker))
			   (intern (if (or (and (>= ch ?A) (<= ch ?Z))
							   (and (>= ch ?a) (<= ch ?z)))
						   (string ch)
						 (string ?! ch)))
			   )))))

;; TERPRI():NIL -- OK probably
;; The current print line is terminated.

(defun wrs (filehandle)					; temporary no-op
  "WRS(FILEHANDLE:any):any eval, spread
Output to the currently active output file is suspended and further
output is directed to the file named. FILEHANDLE is an internal
name which is returned by OPEN. The file named must have been
opened for output. If FILEHANDLE is NIL the standard output
device is selected. WRS returns the internal name of the previously
selected output file.
***** FILEHANDLE could not be selected for output"
  nil)


;;; LISP Reader
;;; ===========

(defun standard-lisp ()
  "EXPR PROCEDURE STANDARD!-LISP();
BEGIN SCALAR VALUE;
   RDS NIL; WRS NIL;
   PRIN2 \"Standard LISP\"; TERPRI();
   WHILE T DO
      << PRIN2 \"EVAL:\"; TERPRI();
    	 VALUE := ERRORSET(QUOTE EVAL READ(), T, T);
	     IF NOT ATOM VALUE THEN PRINT CAR VALUE;
	     TERPRI() >>;
END;"
  (sl-begin)
  (let (value)
	(rds nil) (wrs nil)
	(prin2 "Standard LISP") (terpri)
	(catch 'quit
	  (while t
		(prin2 "EVAL: ") (terpri)
		(setq value (errorset '(eval (read)) t t))
		(if (not (atom value)) (print (car value)))
		(terpri))))
  (sl-end))

(defun quit ()
  "QUIT()
Causes termination of the LISP reader and control to be transferred
to the operating system."
  (throw 'quit nil))


;;; System GLOBAL Variables
;;; =======================

(defvar !*comp nil						; currently ignored!
  "*COMP = NIL global
The value of !*COMP controls whether or not PUTD compiles the
function defined in its arguments before defining it. If !*COMP is
NIL the function is defined as an EXPR. If !*COMP is something
else the function is first compiled. Compilation will produce certain
changes in the semantics of functions particularly FLUID type access.")

(defvar emsg!* nil
  "EMSG* = NIL global
Will contain the MESSAGE generated by the last ERROR call.")

(defconst !$eof!$ :!$EOF!$
  "$EOF$ = <an uninterned identifier> global
The value of !$EOF!$ is returned by all input functions when the end
of the currently selected input file is reached.")

(defconst !$eol!$ :!$EOL!$
  "$EOL$ = <an uninterned identifier> global
The value of !$EOL!$ is returned by READCH when it reaches the
end of a logical input record. Likewise PRINC will terminate its
current line (like a call to TERPRI) when !$EOL!$ is its argument.")

(defvar !*gc nil						; currently ignored!
  "*GC = NIL global
!*GC controls the printing of garbage collector messages. If NIL
no indication of garbage collection may occur. If non-NIL various
system dependent messages may be displayed.")

;; NIL = NIL global -- OK
;; NIL is a special global variable. It is protected from being modified
;; by SET or SETQ.

(defvar !*raise nil						; currently ignored!
  "*RAISE = NIL global
If !*RAISE is non-NIL all characters input through Standard LISP
input/output functions will be raised to upper case. If !*RAISE is
NIL characters will be input as is.")

;; T = T global -- OK
;; T is a special global variable. It is protected from being modified by
;; SET or SETQ.


;;; Emacs Support
;;; =============

(defun sl-begin ()
  (advice-add 'rplaca :override #'sl--rplaca-override)
  (advice-add 'rplacd :override #'sl--rplacd-override)
  (advice-add 'error :override #'sl--error-override)
  (advice-add 'mapc :filter-args #'sl--mapc-filter-args)
  (advice-add 'mapc :filter-return #'sl--mapc-filter-return)
  (advice-add 'mapcan :filter-args #'sl--mapc-filter-args)
  (advice-add 'mapcar :filter-args #'sl--mapc-filter-args))

(defun sl-end ()
  (advice-remove 'rplaca #'sl--rplaca-override)
  (advice-remove 'rplacd #'sl--rplacd-override)
  (advice-remove 'error #'sl--error-override)
  (advice-remove 'mapc #'sl--mapc-filter-args)
  (advice-remove 'mapc #'sl--mapc-filter-return)
  (advice-remove 'mapcan #'sl--mapc-filter-args)
  (advice-remove 'mapcar #'sl--mapc-filter-args))

;;; Code that must be evaluated in Standard LISP mode:
(sl-begin)
(global '(!*comp emsg!* !$eof!$ !$eol!$ !*gc !*raise))
(sl-end)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; (define-derived-mode sl-interaction-mode
;;   lisp-interaction-mode "SLISP Interaction"
;;   "Major mode for entering and evaluating Standard LISP forms.")

;; (defun sl-run ()
;;   "Run Standard LISP with input via the minbuffer and output via a buffer."
;;   (interactive)
;;   (switch-to-buffer (get-buffer-create "*Standard LISP*"))
;;   (sl-interaction-mode)
;;   (sl-begin)
;;   (unwind-protect
;; 	  ;; Set IO to use this buffer:
;; 	  (let* ((m (set-marker (make-marker) 1)) ; IO marker
;; 			 ;; (standard-input m)
;; 			 (standard-output m)
;; 			 value)						; value of last sexp
;; 		;; (rds nil) (wrs nil)
;; 		(princ "Standard LISP") (terpri)
;; 		(catch 'quit
;; 		  (while t
;; 			(princ "EVAL: ") (terpri)
;; 			(setq value (errorset '(eval (read)) t t))
;; 			(if (not (atom value)) (print (car value)))
;; 			(terpri))))
;; 	(sl-end)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defvar sl-interaction-mode-map
  (let ((map (make-sparse-keymap)))
    (define-key map "\e\C-x" 'sl-read-eval-print)
    (define-key map "\C-j" 'sl-read-eval-print)
    map)
  "Keymap for Standard LISP interaction mode.
Most commands are inherited from `lisp-interaction-mode-map'.")

(define-derived-mode sl-interaction-mode
  lisp-interaction-mode "SLISP Interaction"
  "Major mode for entering and evaluating Standard LISP forms."
  (make-local-variable 'comment-start)
  (setq comment-start "%")
  ;; Always advance point in this buffer's window when text is inserted:
  (make-local-variable 'window-point-insertion-type)
  (setq window-point-insertion-type t)
  )

(defvar sl-marker (make-marker)
  "Marker from which the next input should be read.")

(defun sl-run ()
  "Run Standard LISP with IO via a buffer."
  (interactive)
  (switch-to-buffer (get-buffer-create "*Standard LISP*"))
  (sl-interaction-mode)
  (let ((standard-output (set-marker sl-marker 1)))
	(princ "Standard LISP") (terpri)
	(terpri) (princ "Eval: ")))

(defun sl-read-eval-print ()
  "Read input after `sl-marker', eval it and print the result."
  (interactive)
  (sl-begin)
  (unwind-protect
	  (let ((standard-input sl-marker)
			(standard-output sl-marker)
			value)
		(setq value (errorset '(eval (read)) t t))
		(unless (atom value)
		  (terpri) (terpri) (princ "====> ") (princ (car value)))
		(terpri) (terpri) (princ "Eval: ")
		;; Output does not necessarily advance point, so...
		(goto-char sl-marker))
	(sl-end)))

(defun sl-eval-print-last-sexp ()
  "Copy sexp before point to end of *Standard LISP* buffer.
Then evaluate it and print value into *Standard LISP* buffer."
  (interactive)
  (let ((sexp (buffer-substring-no-properties
			   (save-excursion (backward-sexp) (point))
			   (point))))
	(save-current-buffer
	  (set-buffer "*Standard LISP*")
	  (insert sexp)
	  (sl-read-eval-print)
	  )))

(global-set-key "\C-c\C-j" 'sl-eval-print-last-sexp)

(defun sl-load-file ()
  "Load the Standard LISP file named FILE."
  (interactive)
  (sl-begin)
    (unwind-protect
		(call-interactively 'load-file)
	  (sl-end)))
