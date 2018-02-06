/******************************************************************************
*
* File:         $PXK/OS-HOOKS.C
* Description:  OS specific startup and cleanup hooks.
* Author:       RAM, HP/FSD
* Created:      9-Mar-84
* Modified:    15-Jul-85 10:10:51 (RAM)
* Mode:         Text
* Package:
* Status:       Experimental (Do Not Distribute)
*
*  (c) Copyright 1983, Hewlett-Packard Company, see the file
*             HP_disclaimer at the root of the PSL file tree
*
*
******************************************************************************
* Revisions:
*
* Jan-2018 (Arthur Norman) refresh the C code somewhat.
* 23-Feb-89 (Chris Burdorf)
*  Made  call to psl_main in main call copy_argv to pass the static
*  copy of argv to get around unexec problems.
* 15-Jun-88, (Tsuyoshi Yamamoto)
*  Added init-malloc-param(), _iob[] initializer, _dtabsize for SUN4 PORT.
* 21-Sep-86 (Leigh Stoller)
*  Removed calls to the io-map functions. None of this was needed for the Sun.
*  Removed the 68020_advise function.
* 07-Jul-86 (Leigh Stoller)
*  Removed Calls to echooff and echoon since they are not needed for the top
*   loop, only for Nmode. Who knows why HP used them in the first place.
* 30-Apr-86 (Leigh Stoller)
* Copied this file from gator kernel directory and changed calls to terminal-
*  state to echooff and echoon, which are contained in echo.c
*
******************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>

#ifndef LINUX
//#include <ieeefp.h>
#endif

jmp_buf mainenv;
char *abs_execfilepath;

int main(int argc, char *argv[])
{   int val;

    clear_iob();             /* clear garbage pointer in _iob[]    */
    clear_dtabsize();
    /* fpsetround(FP_RZ);  */
    /*  init_malloc_param();        /* reset malloc parameters.        */
    setvbuf(stdout,NULL,_IOLBF,BUFSIZ);
    /* Record path to exec file */
    if (argc > 0)
        abs_execfilepath = realpath(argv[0],NULL);

    val=setjmp(mainenv);        /* set non-local return point for exit    */

    if (val == 0)
        psl_main(argc,copy_argv(argc,argv));

    exit(0);

}


void os_startup_hook(int argc, char *argv[])
{   setupbpsandheap(argc, argv);   /* Allocate bps and heap areas. */
}

void os_cleanup_hook()
{   longjmp(mainenv,1);
}

char *get_execfilepath()
{   return abs_execfilepath;
}

void clear_iob()
{
}

/*
 *    Some static area must be initialized on hot start.
 *    There may be other area to be initialized but we have no idea
 *    to know them.
 *
 *    _dtabsize ----_end
 */


extern char *end;
/*
 *     Size of dtabsize is 0x34c bytes.
 */
void clear_dtabsize()
{   int i;
}

#ifndef LINUX
#ifndef __CYGWIN__

/* look for the last occurrence of character c in string s;
   if found, return pointer to string part, NULL otherwise */
char *rindex(const char *s, int c)
{   int i,l; char x;
    for (i=0; s[i]!='\000'; i++);
    for (i=i-1; (s[i] !=c) && (i>=0) ; i--);
    if (i<0) return(NULL); else return (char *)&s[i];
}

/* look for the first occurrence of character c in string s;
   if found, return pointer to string part, NULL otherwise */

char *index(const char *s, int c)
{   int i,l; char x;
    for (i=0; (s[i] !=c) && (s[i]!='\000') ; i++);
    if (s[i]=='\000') return(NULL); else (char *)return &s[i];
}

void bzero(void *b, size_t length)
{   for (size_t i=0; i<length; i++) ((char *)b)[i]='\000';
}

#endif
#endif