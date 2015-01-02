// wxshowmath.cpp

/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 *"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* $Id: wxshowmath.cpp 2387 2014-03-01 20:45:16Z arthurcnorman $ */


// The first few lines are essentially taken from the wxWidgets documentation
// and will be the same for almost all wxWidgets code.

#include"wx/wxprec.h"

#ifndef WX_PRECOMP
#include"wx/wx.h"
#endif

#include <wx/display.h>
#include <wx/graphics.h>
#include <wx/filename.h>

#include"config.h"

#ifdef WIN32

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <wingdi.h>
#include <gdiplus.h>
#include <io.h>

#endif  // WIN32

// I may be old fashioned, but I will be happier using C rather than C++
// libraries here.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>
#include <stdint.h>
#include <inttypes.h>

#if HAVE_UNISTD_H
#include <unistd.h>
#else
#ifndef _MSC_VER
extern char *getcwd(char *s, size_t n);
#endif
#endif // HAVE_UNISTD_H

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#ifndef WIN32
#include <sys/dir.h>
#else
#include <direct.h>
#endif
#endif // HAVE_DIRENT_H

#if !defined __WXMSW__ && !defined __WXPM__
#include"fwin.xpm" // Icon to use in non-Windows cases
#endif

// I have a generated file that contains the widths of all the fonts
// I am willing to use here.

#include"uninames.h"
#include"charmetrics.h"

static FILE *logfile = NULL;

static void logprintf(const char *fmt, ...)
{
    va_list a;
    if (logfile == NULL) logfile = fopen("wxshowmath.log","w");
    if (logfile != NULL)
    {   va_start(a, fmt);
        vfprintf(logfile, fmt, a);
        fflush(logfile);
        va_end(a);
    }
#ifndef MACINTOSH
// On systems other than the Mac I expect I can (sometimes!) have a console
// attached to my program, and in that case it will be convenient to sent the
// trace output there as well as to a file.
    va_start(a, fmt);
    vprintf(fmt, a);
    va_end(a);
    fflush(stdout);
#endif
}



class showmathApp : public wxApp
{
public:
    virtual bool OnInit();
};

class showmathPanel : public wxPanel
{
public:
    showmathPanel(class showmathFrame *parent, const char *showmathfilename);

    void OnPaint(wxPaintEvent &event);

// The event handling is not really needed for this application, but I
// am putting some in so I can experiment with it!
    void OnChar(wxKeyEvent &event);
    void OnKeyDown(wxKeyEvent &event);
    void OnKeyUp(wxKeyEvent &event);
    void OnMouse(wxMouseEvent &event);

private:
    wxGraphicsFont graphicsFixedPitch;
    bool fixedPitchValid;

    void RenderDVI();        // sub-function used by OnPaint
    wxGraphicsContext *gc;   // ditto but in wxGraphics mode

    unsigned char *showmathData;  // the .showmath file's contents are stored here
    unsigned const char *stringInput;

    int u2();                // read 1-4 bytes as signed or unsigned value
    int u3();
    int s1();
    int s2();
    int s3();
    int s4();

    void DefFont(int k);     // showmath file font definition
    void SelectFont(int k);
    void SetChar(int c);     // showmath display charcter and move on
    void PutChar(int c);     // showmath just display character
    void SetRule(int height, int width);
    double DVItoScreen(int n);  // map coordinates
    double DVItoScreenUP(int n);// ditto but used for rule widths

    int32_t h, v, w, x, y, z;// working values used in DVI decoding

    int32_t C[10], p;        // set by start of a page and not used!

// showmath files can call for an essentially unlimited number of distinct
// fonts - where one"font" here is not just to do with shape but also with
// size. If I pre-scanned the showmath data I could identify the largest font
// number used and allocate a table of exactly the right size. But for now
// I will use a fixed limit.
//
#define MAX_FONTS 32
    wxGraphicsFont graphicsFont[MAX_FONTS];       // the fonts I use here
    bool graphicsFontValid[MAX_FONTS];            // the fonts I use here
    double em;

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(showmathPanel, wxPanel)
    EVT_PAINT(           showmathPanel::OnPaint)
    EVT_CHAR(            showmathPanel::OnChar)
//  EVT_KEY_DOWN(        showmathPanel::OnKeyDown)
//  EVT_KEY_UP(          showmathPanel::OnKeyUp)
    EVT_LEFT_UP(         showmathPanel::OnMouse)
END_EVENT_TABLE()

class showmathFrame : public wxFrame
{
public:
    showmathFrame(const char *showmathfilename);

    void OnClose(wxCloseEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);

private:
    int screenWidth, screenHeight;

    showmathPanel *panel;
    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(showmathFrame, wxFrame)
    EVT_CLOSE(           showmathFrame::OnClose)
    EVT_MENU(wxID_EXIT,  showmathFrame::OnExit)
    EVT_MENU(wxID_ABOUT, showmathFrame::OnAbout)
    EVT_SIZE(            showmathFrame::OnSize)
END_EVENT_TABLE()

int get_current_directory(char *s, int n)
{
    if (getcwd(s, n) == 0)
    {   switch(errno)
        {
    case ERANGE: return -2; // negative return value flags an error.
    case EACCES: return -3;
    default:     return -4;
        }
    }
    else return strlen(s);
}

/*
 * The next procedure is responsible for establishing information about
 * both the"short-form" name of the program launched and the directory
 * it was found in. This latter directory may be a good place to keep
 * associated resources. Well many conventions would NOT view it as a
 * good place, but it is how I organise things!
 *
 * The way of finding the information concerned differs between Windows and
 * Unix/Linux, as one might expect.
 *
 * return non-zero value if failure.
 */

#ifndef LONGEST_LEGAL_FILENAME
#define LONGEST_LEGAL_FILENAME 1024
#endif

const char *fullProgramName ="./wxshowmath.exe";
const char *programName     ="wxshowmath.exe";
const char *programDir      =".";

/*
 * getenv() is a mild pain: Windows seems
 * to have a strong preference for upper case names.  To allow for
 * all this I do not call getenv() directly but go via the following
 * code that can patch things up.
 */

const char *my_getenv(const char *s)
{
#ifdef WIN32
    char uppercasename[LONGEST_LEGAL_FILENAME];
    char *p = uppercasename;
    int c;
    while ((c = *s++) != 0) *p++ = toupper(c);
    *p = 0;
    return getenv(uppercasename);
#else
    return getenv(s);
#endif
}

#ifdef WIN32

int program_name_dot_com = 0;

static char this_executable[LONGEST_LEGAL_FILENAME];

int find_program_directory(const char *argv0)
{
    char *w;
    int len, ndir, npgm;
/*
 * In older code I believed that I could rely on Windows giving me
 * the full path of my executable in argv[0]. With bits of mingw/cygwin
 * anywhere near me that may not be so, so I grab the information directly
 * from the Windows APIs.
 */
    char execname[LONGEST_LEGAL_FILENAME];
    GetModuleFileNameA(NULL, execname, LONGEST_LEGAL_FILENAME-2);
    strcpy(this_executable, execname);
    argv0 = this_executable;
    program_name_dot_com = 0;
    if (argv0[0] == 0)      // should never happen - name is empty string!
    {   programDir =".";
        programName ="wxshowmath";  // nothing really known!
        fullProgramName =".\\wxshowmath.exe";
        return 0;
    }

    fullProgramName = argv0;
    len = strlen(argv0);
/*
 * If the current program is called c:\aaa\xxx.exe, then the directory
 * is just c:\aaa and the simplified program name is just xxx
 */
    if (len > 4 &&
        argv0[len-4] == '.' &&
        ((tolower(argv0[len-3]) == 'e' &&
          tolower(argv0[len-2]) == 'x' &&
          tolower(argv0[len-1]) == 'e') ||
         (tolower(argv0[len-3]) == 'c' &&
          tolower(argv0[len-2]) == 'o' &&
          tolower(argv0[len-1]) == 'm')))
    {   program_name_dot_com = (tolower(argv0[len-3]) == 'c');
        len -= 4;
    }
    for (npgm=0; npgm<len; npgm++)
    {   int c = argv0[len-npgm-1];
        if (c == '\\') break;
    }
    ndir = len - npgm - 1;
    if (ndir < 0) programDir =".";  // none really visible
    else
    {   if ((w = (char *)malloc(ndir+1)) == NULL) return 1;
        strncpy(w, argv0, ndir);
        w[ndir] = 0;
        programDir = w;
    }
    if ((w = (char *)malloc(npgm+1)) == NULL) return 1;
    strncpy(w, argv0 + len - npgm, npgm);
    w[npgm] = 0;
    programName = w;
    return 0;
}

#else // !WIN32
// Now for Unix, Linux, BSD (and hence Macintosh) worlds.


/*
 * Different systems put or do not put underscores in front of these
 * names. My adaptation here should give me a chance to work whichever
 * way round it goes.
 */

#ifndef S_IFMT
# ifdef __S_IFMT
#  define S_IFMT __S_IFMT
# endif
#endif

#ifndef S_IFDIR
# ifdef __S_IFDIR
#  define S_IFDIR __S_IFDIR
# endif
#endif

#ifndef S_IFREG
# ifdef __S_IFREG
#  define S_IFREG __S_IFREG
# endif
#endif

#ifndef S_ISLNK
# ifdef S_IFLNK
#  ifdef S_IFMT
#   define S_ISLNK(m) (((m) & S_IFMT) == S_IFLNK)
#  endif
# endif
#endif


/*
 * The length set here is at least the longest length that I
 * am prepared to worry about. If anybody installs the program in a
 * very deep directory such that its fully rooted name is over-long
 * things may not behave well. But I am not going to fuss with dynamic
 * allocation of or expansion of the arrays I use here.
 */

int find_program_directory(const char *argv0)
{
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
    const char *cw;
    int n, n1;
/*
 * If the main reduce executable is has a full path-name /xxx/yyy/zzz then
 * I will use /xxx/yyy as its directory To find this I need to find the full
 * path for the executable. I ATTEMPT to follow the behaviour of"sh",
 *"bash" and"csh".  But NOTE WELL that if anybody launches this code in
 * an unusual manner (eg using an"exec" style function) that could confuse
 * me substantially. What comes in via argv[0] is typically just the final
 * component of the program name - what I am doing here is scanning to
 * see what path it might have corresponded to.
 *
 *
 * If the name of the executable starts with a"/" it is already an
 * absolute path name. I believe that if the user types (to the shell)
 * something like $DIR/bin/$PGMNAME or ~user/subdir/pgmname then the
 * environment variables and user-name get expanded out by the shell before
 * the command is actually launched.
 */
    if (argv0 == NULL || argv0[0] == 0) // Information not there - return
    {   programDir = (const char *)"."; // some sort of default.
        programName = (const char *)"wxshowmath";
        fullProgramName = (const char *)"./wxshowmath";
        return 0;
    }
/*
 * I will treat 3 cases here
 * (a)   /abc/def/ghi      fully rooted: already an absolute name;
 * (b)   abc/def/ghi       treat as ./abc/def/ghi;
 * (c)   ghi               scan $PATH to see where it may have come from.
 */
    else if (argv0[0] == '/') fullProgramName = argv0;
    else
    {   for (cw=argv0; *cw!=0 && *cw!='/'; cw++);   // seek a"/" *
        if (*cw == '/')      // treat as if relative to current dir
        {   // If the thing is actually written as"./abc/..." then
            // strip of the initial"./" here just to be tidy.
            if (argv0[0] == '.' && argv0[1] == '/') argv0 += 2;
            n = get_current_directory(pgmname, sizeof(pgmname));
            if (n < 0) return 1;    // fail! 1=current directory failure
            if (n + strlen(argv0) + 2 >= sizeof(pgmname) ||
                pgmname[0] == 0)
                return 2; // Current dir unavailable or full name too long
            else
            {   pgmname[n] = '/';
                strcpy(&pgmname[n+1], argv0);
                fullProgramName = pgmname;
            }
        }
        else
        {   const char *path = my_getenv("PATH");
/*
 * I omit checks for names of shell built-in functions, since my code is
 * actually being executed by here. So I get my search path and look
 * for an executable file somewhere on it. I note that the shells back this
 * up with hash tables, and so in cases where"rehash" might be needed this
 * code may become confused.
 */
            struct stat buf;
            uid_t myuid = geteuid(), hisuid;
            gid_t mygid = getegid(), hisgid;
            int protection;
            int ok = 0;
/*
 * I expect $PATH to be a sequence of directories with":" characters to
 * separate them. I suppose it COULD be that somebody used directory names
 * that had embedded colons, and quote marks or escapes in $PATH to allow
 * for that. In such case this code will just fail to cope.
 */
            if (path != NULL)
            {   while (*path != 0)
                {   while (*path == ':') path++; // skip over":"
                    n = 0;
                    while (*path != 0 && *path != ':')
                    {   pgmname[n++] = *path++;
                        if (n > (int)(sizeof(pgmname)-3-strlen(argv0)))
                            return 3; // fail! 3=$PATH element overlong
                    }
/*
 * Here I have separated off the next segment of my $PATH and put it at
 * the start of pgmname. Observe that to avoid buffer overflow I
 * exit abruptly if the entry on $PATH is itself too big for my buffer.
 */
                    pgmname[n++] = '/';
                    strcpy(&pgmname[n], argv0);
// see if the file whose name I have just built up exists at all.
                    if (stat(pgmname, &buf) == -1) continue;
                    hisuid = buf.st_uid;
                    hisgid = buf.st_gid;
                    protection = buf.st_mode; // info about the file found
/*
 * I now want to check if there is a file of the right name that is
 * executable by the current (effective) user.
 */
                    if (protection & S_IXOTH ||
                        (mygid == hisgid && protection & S_IXGRP) ||
                        (myuid == hisuid && protection & S_IXUSR))
                    {   ok = 1;   // Haha - I have found the one we ...
                        break;    // are presumably executing!
                    }
                }
            }
            if (!ok) return 4;    // executable not found via $PATH
/*
 * Life is not yet quite easy! $PATH may contain some items that do not
 * start with"/", ie that are still local paths relative to the
 * current directory. I want to be able to return an absolute fully
 * rooted path name! So unless the item we have at present starts with"/"
 * I will stick the current directory's location in front.
 */
            if (pgmname[0] != '/')
            {   char temp[LONGEST_LEGAL_FILENAME];
                strcpy(temp, pgmname);
                n = get_current_directory(pgmname, sizeof(pgmname));
                if (n < 0) return 1;    // fail! 1=current directory failure
                if ((n + strlen(temp) + 1) >= sizeof(pgmname)) return 9;
                pgmname[n++] = '/';
                strcpy(&pgmname[n], temp);
            }
            fullProgramName = pgmname;
        }
    }
/*
 * Now if I have a program name I will try to see if it is a symbolic link
 * and if so I will follow it.
 */
    {   struct stat buf;
        char temp[LONGEST_LEGAL_FILENAME];
        if (lstat(fullProgramName, &buf) != -1 &&
            S_ISLNK(buf.st_mode) &&
            (n1 = readlink(fullProgramName,
                           temp, sizeof(temp)-1)) > 0)
        {   temp[n1] = 0;
            strcpy(pgmname, temp);
            fullProgramName = pgmname;
        }
    }
/*
 * Now fullProgramName is set up, but may refer to an array that
 * is stack allocated. I need to make it proper.
 */
    w = (char *)malloc(1+strlen(fullProgramName));
    if (w == NULL) return 5;           // 5 = malloc fails
    strcpy(w, fullProgramName);
    fullProgramName = w;
#ifdef __CYGWIN__
/*
 * Now if I built on raw cygwin I may have an unwanted".com" or".exe"
 * suffix, so I will purge that! This code exists here because the raw
 * cygwin build has a somewhat schitzo view as to whether it is a Windows
 * or a Unix-like system.
 */
    if (strlen(w) > 4)
    {   w += strlen(w) - 4;
        if (w[0] == '.' &&
            ((tolower(w[1]) == 'e' &&
              tolower(w[2]) == 'x' &&
              tolower(w[3]) == 'e') ||
             (tolower(w[1]) == 'c' &&
              tolower(w[2]) == 'o' &&
              tolower(w[3]) == 'm'))) w[0] = 0;
    }
#endif
/*
 * OK now I have the full name, which is of the form
 *   abc/def/fgi/xyz
 * and I need to split it at the final"/" (and by now I very fully expect
 * there to be at least one"/".
 */
    for (n=strlen(fullProgramName)-1; n>=0; n--)
        if (fullProgramName[n] == '/') break;
    if (n < 0) return 6;               // 6 = no"/" in full file path
    w = (char *)malloc(1+n);
    if (w == NULL) return 7;           // 7 = malloc fails
    strncpy(w, fullProgramName, n);
    w[n] = 0;
/*
 * Note that if the executable was"/foo" then programDir will end up as""
 * so that programDir +"/" + programName works out properly.
 */
    programDir = w;
    n1 = strlen(fullProgramName) - n;
    w = (char *)malloc(n1);
    if (w == NULL) return 8;           // 8 = malloc fails
    strncpy(w, fullProgramName+n+1, n1-1);
    w[n1-1] = 0;
    programName = w;
    return 0;                          // whew!
}

#endif // WIN32


int main(int argc, char *argv[])
{
    int i;
    int usegui = 1;
// I have had a case where my code appears to run happily when I run it
// under gdb or when I have compiled it with full debugging options, but
// where it crashes on Windows if build in"release" mode. To try to debug
// in a case like that I add explicit print statements as follows...
#if DEBUG
    logprintf("Starting wxshowmath program\n");
#endif
// Find where I am invoked from before doing anything else
    find_program_directory(argv[0]);
    for (i=1; i<argc; i++)
    {   if (strncmp(argv[i],"-w", 2) == 0) usegui = 0;
    }
#if !defined WIN32 && !defined MACINTOSH
// Under X11 I will demote to being a console mode application if DISPLAY
// is not set. This is not a perfect test but it will spot the simple
// cases. Eg I could look at stdin & stdout and check if it looks as if
// they are pipes of they have been redirected...
    {   const char *s = my_getenv("DISPLAY");
        if (s==NULL || *s == 0) usegui = 0;
    }
#endif
#if DEBUG
    logprintf("usegui=%d\n", usegui);
#endif
    if (usegui)
    {
#ifdef MACINTOSH
// If I will be wanting to use a GUI and if I have just loaded an
// executable that is not within an application bundle then I will
// use"open" to launch the corresponding application bundle. Doing this
// makes resources (eg fonts) that are within the bundle available and
// it also seems to cause things to terminate more neatly.
        char xname[LONGEST_LEGAL_FILENAME];
        sprintf(xname,"%s.app", programName);
        if (strstr(fullProgramName, xname) == NULL)
        {
// Here the binary I launched was not located as
//      ...foo.app../.../foo
// so I will view it is NOT being from an application bundle. I will
// re-launch it so it is! This may be a bit of a hacky way to decide!
            struct stat buf;
            sprintf(xname,"%s.app", fullProgramName);
            if (stat(xname, &buf) == 0 &&
                (buf.st_mode & S_IFDIR) != 0)
            {
// Well foo.app exists and is a directory, so I will try to use it
                char **nargs = (char **)malloc(sizeof(char *)*(argc+3));
                int i;
                nargs[0] ="/usr/bin/open";
                nargs[1] = xname;
                nargs[2] ="--args";
                for (i=1; i<argc; i++)
                    nargs[i+2] = argv[i];
                nargs[argc+2] = NULL;
// /usr/bin/open foo.app --args [any original arguments]
                return execv("/usr/bin/open", nargs);
            }
        }
#endif
        wxDISABLE_DEBUG_SUPPORT();
#if DEBUG
    logprintf("calling wxEntry\n");
#endif

        return wxEntry(argc, argv);
    }
//
// The following is a bit silly but is here to prove that I can launch this
// code in console mode if I wish to. In this case it is not very useful!
//
    printf("This program has been launched asking for use in a console\n");
    printf("type a line of text please\n");
    while ((i = getchar()) != '\n' && i != EOF) putchar(i);
    putchar('\n');
    printf("Exiting from demonstration of console mode use!\n");
    return 0;
}

IMPLEMENT_APP_NO_MAIN(showmathApp)


// The fontNames here are the file-names for the fonts that I will use.
// On windows I will use ".ttf" and elsewhere ".otf". That is because
// I (slighly) suspect that the .otf versions of many of the fonts are the
// original versions and have the best hinting information, however
// GDI+ on Wiindows can then not cope, so either I would need to move
// to alternate technology there - mainly that should be possible once
// wxWidgets has moved to use of DirectWrite and omce I feel happy abandoning
// support for versions of Windows prior to Windows 7. I note that a Google
// Summer of Code project to work on the DirectWrite support for wxWidgets
// was scheduled for Summer 2014... and these days perhaps Windows XP will be
// fading in importance and perhaps Vista never was important?

static const char *fontNames[] =
{
    "cmuntt",
// It appears (empirically) that I NEED to add the Regular font before
// the Bold one for Windows (at least) to be able to find it.
    "STIXGeneral-Regular",
    "STIXGeneral-Bold",
    "STIXGeneral-Italic",
    "STIXGeneral-BoldItalic",

    "STIXIntegralsD-Regular",
    "STIXIntegralsD-Bold",

    "STIXIntegralsSm-Regular",
    "STIXIntegralsSm-Bold",

    "STIXIntegralsUp-Regular",
    "STIXIntegralsUp-Bold",

    "STIXIntegralsUpD-Regular",
    "STIXIntegralsUpD-Bold",

    "STIXIntegralsUpSm-Regular",
    "STIXIntegralsUpSm-Bold",

    "STIXNonUnicode-Regular",
    "STIXNonUnicode-Bold",
    "STIXNonUnicode-Italic",
    "STIXNonUnicode-BoldItalic",

    "STIXSizeOneSym-Regular",
    "STIXSizeTwoSym-Regular",
    "STIXSizeThreeSym-Regular",
    "STIXSizeFourSym-Regular",
    "STIXSizeFiveSym-Regular",

    "STIXSizeOneSym-Bold",
    "STIXSizeTwoSym-Bold",
    "STIXSizeThreeSym-Bold",
    "STIXSizeFourSym-Bold",

    "STIXVariants-Regular",
    "STIXVariants-Bold",

    "fireflysung" 
};

#ifndef fontsdir
#define fontsdir reduce.wxfonts
#endif

#define toString(x) toString1(x)
#define toString1(x) #x

void add_custom_fonts()
{
#ifndef MACINTOSH
// Note that on a Mac I put the required fonts in the Application Bundle.
    for (int i=0; i<(int)(sizeof(fontNames)/sizeof(fontNames[0])); i++)
    {   char nn[LONGEST_LEGAL_FILENAME];
#ifdef WIN32
        sprintf(nn,"%s/%s/%s.ttf",
                    programDir, toString(fontsdir), fontNames[i]);
#else
        sprintf(nn,"%s/%s/%s.otf",
                    programDir, toString(fontsdir), fontNames[i]);
#endif
        wxString widename(nn);
        if (!wxFont::AddPrivateFont(widename))
            logprintf("Adding font %s failed\n", nn);
    }
    if (!wxFont::ActivatePrivateFonts())
            logprintf("Activating private fonts failed\n");
#endif // MACINTOSH
}




//
// Now that start of my code in a proper sense!
//
//


double showmathPanel::DVItoScreen(int n)
{
// At present this is a fixed scaling. I may well want to make it variable
// at some later stage. The scaling here, which is based on an assumption
// I make about the dots-per-inch resolution of my display, will end up
// important when establishing fonts.
    return (double)n/65536.0;
}

double showmathPanel::DVItoScreenUP(int n)
{
// This ROUND UP to the next integer, and that is needed so that (eg)
// very thin rules end up at least one pixel wide. Well I round up by
// adding a value just under 1.0 then truncating. That recipe works OK for
// positive arguments!
// well using wxGraphicsContext I do not need to round.
    return (double)n/65536.0;
}

void showmathPanel::SetChar(int32_t c)
{
#if 0
    logprintf("SetChar%d [%c] %d %d\n", (int)c, (c <  0x20 || c >= 0x7f ? ' ' : (int)c), (int)h, (int)v);
#endif
    wxString s = (wchar_t)c;
    double width, height, descent, xleading;
    gc->GetTextExtent(s, &width, &height, &descent, &xleading);
    gc->DrawText(s, DVItoScreen(h), DVItoScreen(v)-(height-descent));
// Now I must increase h by the width (in scaled points) of the character
// I just set. This is not dependent at all on the way I map DVI internal
// coordinates to screen ones.

//??     int32_t ww = currentFontWidth->charwidth[c & 0x7f];
//??     int32_t design = currentFontWidth->designsize;
//?? // ww is now the width as extracted from the .tfm file, and that applies
//?? // to the glyph if it is set at its standard size. So adjust for all of
//?? // that and end up in TeX coordinate units.
//??     int32_t texwidth =
//??         (int32_t)(0.5 + (double)design*(double)ww/
//??                         (double)(1<<24));
//??     h += texwidth;
#if 0
// Now I want to compare the width that TeX thinks the character has with
// what wxWidgets thinks. So I convert the TeX width to pixels.
    double twp = (double)(1024*1024)*(double)texwidth/
                 (72.0*65536.0*1000.0);
    logprintf("TeX says %#.6g wxWidgets says %.6g (%.6g)\n",
        twp, (double)width, twp/(double)width);
#endif
}

void showmathPanel::SetRule(int height, int width)
{
#if 0
    logprintf("SetRule %d %.3g %d %.3g\n", width, (double)width/65536.0,
                                        height, (double)height/65537.0);
#endif
// The curious re-scaling here is so that the border of the rectangle does not
// end up fatter than the rectangle itself.
    wxGraphicsMatrix xform = gc->GetTransform();
    gc->Scale(0.01, 0.01);
    gc->DrawRectangle(100.0*DVItoScreen(h), 100.0*DVItoScreen(v-height),
                      100.0*DVItoScreenUP(width), 100.0*DVItoScreenUP(height));
    gc->SetTransform(xform);
}



bool showmathApp::OnInit()
{
// I find that the real type of argv is NOT "char **" but it supports
// the cast indicated here to turn it into what I expect.
    char **myargv = (char **)argv;

#if DEBUG
    logprintf("in showmathApp::OnInit\n");
#endif
    add_custom_fonts();
#if DEBUG
    logprintf("fonts added\n");
#endif

    const char *showmathfilename = NULL;
    if (argc > 1) showmathfilename = myargv[1];
    
#if DEBUG
    logprintf("showmathfilename=%s\n",
              showmathfilename == NULL ?"<null>" : showmathfilename);
#endif

    showmathFrame *frame = new showmathFrame(showmathfilename);
    frame->Show(true);
#if DEBUG
    logprintf("OnInint complete\n");
#endif
    return true;
}

showmathFrame::showmathFrame(const char *showmathfilename)
       : wxFrame(NULL, wxID_ANY,"wxshowmath")
{
    SetIcon(wxICON(fwin));
    int numDisplays = wxDisplay::GetCount(); // how many displays?
// It is not clear to me what I should do if there are several displays,
// and if there are none I am probably in a mess!
    if (numDisplays != 1)
    {   logprintf("There seem to be %d displays\n", numDisplays);
    }
    wxDisplay d0(0);                         // just look at display 0
    wxRect screenArea(d0.GetClientArea());   // omitting task bar
    screenWidth = screenArea.GetWidth();
    screenHeight = screenArea.GetHeight();
    logprintf("Usable area of screen is %d by %d\n", screenWidth, screenHeight);
// I will want to end up saving screen size (and even position) between runs
// of this program.
    int width = 1280;      // default size.
    int height = 1024;
// If the default size would fill over 90% of screen width or height I scale
// down to make it fit better.
    if (10*width > 9*screenWidth)
    {   height = height*9*screenWidth/(10*width);
        width = 9*screenWidth/10;
        logprintf("reset to %d by %d to fix width\n", width, height);
    }
    if (10*height > 9 * screenHeight)
    {   width = width*9*screenHeight/(10*height);
        height = 9*screenHeight/10;
        logprintf("reset to %d by %d to fix height\n", width, height);
    }
    panel = new showmathPanel(this, showmathfilename);
    SetMinClientSize(wxSize(400, 100));
    SetSize(width, height);
    wxSize client(GetClientSize());
    int w = client.GetWidth() % 80;
    if (w != 0) SetSize(width-w, height);
    Centre();
}


static unsigned char default_data[4] = "x";

// When I construct this I must avoid the wxTAB_TRAVERSAL style since that
// tends to get characters passed to child windows not this one. Avoiding
// that is the reason behind providing so many arguments to the parent
// constructor

showmathPanel::showmathPanel(showmathFrame *parent, const char *showmathfilename)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
                 wxDefaultSize, 0L,"showmathPanel")
{
// I will read in any data once here and put it in a character buffer.
    FILE *f = NULL;
    if (showmathfilename == NULL) showmathData = default_data;
    else
    {   stringInput = NULL;
        f = fopen(showmathfilename,"r");
        if (f == NULL)
        {   logprintf("File \"%s\" not found\n", showmathfilename);
            exit(1);
        }
        fseek(f, (off_t)0, SEEK_END);
        off_t len = ftell(f);
        showmathData = (unsigned char *)malloc((size_t)len);
        fseek(f, (off_t)0, SEEK_SET);
        for (int i=0; i<len; i++) showmathData[i] = getc(f);
        fclose(f);
    }
    for (int i=0; i<MAX_FONTS; i++) graphicsFontValid[i] = false;
    fixedPitchValid = false;
}


void showmathFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{
    Destroy();
#ifdef WIN32
// Otherwise under XP bad things happen for me. Like the application
// re-launching. I do not think I understand, but the extreme action of
// utterly killing the process does what I need!
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void showmathFrame::OnExit(wxCommandEvent &WXUNUSED(event))
{
    Destroy();
#ifdef WIN32
    TerminateProcess(GetCurrentProcess(), 1);
#else
    exit(0);    // I want the whole application to terminate here!
#endif
}

void showmathFrame::OnAbout(wxCommandEvent &WXUNUSED(event))
{
// At present this never gets activated!
    wxMessageBox(
       wxString::Format(
"wxshowmath (A C Norman 2015)\nwxWidgets version: %s\nOperating system: %s",
           wxVERSION_STRING,
           wxGetOsDescription()),
       "About wxshowmath",
       wxOK | wxICON_INFORMATION,
       this);
}

void showmathFrame::OnSize(wxSizeEvent &WXUNUSED(event))
{
    wxSize client(GetClientSize());
    panel->SetSize(client);
    panel->Refresh();
}

void showmathPanel::OnChar(wxKeyEvent &event)
{
// This merely records the character in the log file.
    const char *msg ="OnChar", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
}

void showmathPanel::OnKeyDown(wxKeyEvent &event)
{
// Again merely log the event.
    const char *msg ="OnKeyDown", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void showmathPanel::OnKeyUp(wxKeyEvent &event)
{
// Merely log the event.
    const char *msg ="OnKeyUp", *raw ="";
    int c = event.GetUnicodeKey();
    if (c == WXK_NONE) c = event.GetKeyCode(), raw ="Raw";
    if (0x20 < c && c < 0x7f) logprintf("%s%s %x (%c)\n", msg, raw, c, c);
    else logprintf("%s%s %x\n", msg, raw, c);
    event.Skip();
}

void showmathPanel::OnMouse(wxMouseEvent &event)
{
// Log but take no action.
    logprintf("Mouse event\n");
    event.Skip();
//  Refresh();     // forces redraw of everything
}

void showmathPanel::OnPaint(wxPaintEvent &event)
{
    wxPaintDC mydc(this);
    gc = wxGraphicsContext::Create(mydc);
    logprintf("OnPaint: graphicsContext created at %p\n", gc);
    if (gc == NULL) return;
// The next could probably be done merely by setting a background colour
    wxColour c1(230, 200, 255);
    wxBrush b1(c1);
    logprintf("colour and brush made\n");
    gc->SetBrush(b1);
    logprintf("setbrush done\n");
    wxSize window(mydc.GetSize());
    logprintf("Window is %d by %d\n", window.GetWidth(), window.GetHeight());
    gc->DrawRectangle(0.0, 0.0,
                      (double)window.GetWidth(),
                      (double)window.GetHeight());
    logprintf("background drawn\n");

#if defined WIN32 && 0
// The Windows default behaviour fails to antialias some of the cmex10
// tall characters, and so unless I force antialiasing here I get MOST
// symbols rendered nicely, but big integral signs and parentheses badly
// blocky when the display exceeds a certain size. This is clearly down to
// the system default smoothing switching off for characters over a certain
// size, but it is far from clear that there is a trivial place where I
// can adjust for that, and anyway nobody wants to have to set a system-
// wide option just for the benefit of this application. I will need to
// review this when I test using the STIX fonts, but given that my diagnosis
// is that it is GDI+ hurting me I will leave this code in place for now.
    Gdiplus::Graphics *g = (Gdiplus::Graphics *)gc->GetNativeContext();
    g->SetTextRenderingHint(Gdiplus::TextRenderingHintAntiAlias);
#endif
    logprintf("Need to create fixed pitch font\n");
// The graphicsFixedPitch font will be for a line spacing of exactly 10
// pixels. This is of course TINY, but I will scale it as relevant. Note
// also that I will need to check font names since exactly the same font
// files may end up needing different names to refer to them as between
// Windows, Linux and OSX.
    graphicsFixedPitch = gc->CreateFont(10.0, wxT("CMU Typewriter Text"));
    double dwidth, dheight, ddepth, dleading;
    gc->SetFont(graphicsFixedPitch);
    gc->GetTextExtent(wxT("M"), &dwidth, &dheight, &ddepth, &dleading);
    em = dwidth;
    logprintf("(D)em=%#.3g\n", em);
    logprintf("(D)height = %#.3g total height = %#.3g leading = %#.3g\n",
        dheight-ddepth-dleading, dheight, dleading);

    double screenWidth = (double)window.GetWidth();
    double lineWidth = 80.0*em;
    double scale = screenWidth/lineWidth;
// This will now scale everything so that I end up with 80 characters from
// that fixed-pitch font across the width of my window.
    gc->Scale(scale, scale);
    logprintf("Scale now %.6g\n", scale);

// Sort of for fun I put a row of 80 characters at the top of the screen
// so I can show how fixed pitch stuff might end up being rendered.
    gc->SetFont(graphicsFixedPitch);
    for (int i=0; i<80; i++)
    {   wxString c1 = (wchar_t)(i+0x21);
        gc->DrawText(c1, (double)i*em, 10.0);
    }

// Now I need to do something more serious!
    wxGraphicsFont general =
        gc->CreateFont(wxFont(wxFontInfo(10).FaceName(wxT("STIXGeneral"))));
    if (general.IsNull()) logprintf("STIXGeneral font not created\n");
    wxGraphicsFont symbols =
        gc->CreateFont(wxFont(wxFontInfo(10).FaceName(wxT("STIXSizeOneSym"))));
    if (symbols.IsNull()) logprintf("STIXSizeOneSym font not created\n");
    else logprintf("Sym font should be OK\n");
    gc->SetFont(general);
    gc->DrawText(wxString((wchar_t)unicode_GREEK_SMALL_LETTER_PI), 100.0, 100.0);
    gc->SetFont(symbols);
    gc->DrawText(wxString((wchar_t)unicode_LEFT_CURLY_BRACKET_UPPER_HOOK), 130.0, 90.0);
    gc->DrawText(wxString((wchar_t)unicode_LEFT_CURLY_BRACKET_MIDDLE_PIECE), 130.0, 100.0);
    gc->DrawText(wxString((wchar_t)unicode_CURLY_BRACKET_EXTENSION), 130.0, 110.0);
    gc->DrawText(wxString((wchar_t)unicode_LEFT_CURLY_BRACKET_LOWER_HOOK), 130.0, 120.0);
    gc->SetFont(general);
    gc->DrawText(wxString((wchar_t)unicode_GREEK_SMALL_LETTER_OMEGA), 130.0, 140.0);
    gc->DrawText(wxString((wchar_t)0x237c), 160.0, 130.0);
    gc->DrawText(wxString((wchar_t)0x3c0), 180.0, 130.0);

//  RenderDVI();

// I will mark all the fonts I might have created as invalid now
// that the context they were set up for is being left.
    for (int i=0; i<MAX_FONTS; i++) graphicsFontValid[i] = false;
    logprintf("About to delete gc\n");
    delete gc;
    gc = NULL; // just to be tidy!
    return;
}


// end of wxshowmath.cpp

