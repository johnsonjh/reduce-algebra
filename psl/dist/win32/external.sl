%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXK:EXTERNALS.SL
% Description:  Definitions of foreign language functions
% Author:       Brian Beach, Hewlett-Packard CRC
% Created:      19-Apr-84
% Modified:     15-Feb-85 13:25:43
% Mode:         Lisp
% Package:
% Status:       Experimental (Do Not Distribute)
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%

%

% (c) Copyright 1982, University of Utah

%

% Redistribution and use in source and binary forms, with or without

% modification, are permitted provided that the following conditions are met:
%

%
    * Redistributions of source code must retain the relevant copyright

%      notice, this list of conditions and the following disclaimer.

%
%    * Redistributions in binary form must reproduce the above copyright

%      notice, this list of conditions and the following disclaimer in the

%      documentation and/or other materials provided with the distribution.

%

% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"

% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,

% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR

% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR

% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR

% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF

% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS

% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN

% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)

% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE

% POSSIBILITY OF SUCH DAMAGE.

%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 
%
% Revisions:
%
% 17-Feb-89 (Chris Burdorf)
% Changed name of sigset to sun3_sigset for sun os/4.
% 05-Apr-88 (Julian Padget)
%  Once more reinstated handle for alarm and ualarm.
% 29-May-87 (Harold Carr & Leigh Stoller)
%  Added external definition for setenv.
% 05-May-87 (Leigh Stoller)
%  Added external definitions for fast-math.sl. They are in float.c
% 13-Apr-87 (Leigh Stoller & Harold Carr)
%  Added external definition of allocatemorebps, defined in bpsheap.c.
% 26-Sep-86 (Leigh Stoller)
%  Added external entry for exit which is needed on the sun to pass an exit
%  code back to unix.
% 01-Sep-86 (Leigh Stoller)
%  Added external-system to do a standard system call from C.
% 19-Aug-86 (Leigh Stoller)
%  Added entries for get_file_status, sigrelse, and sigset.
% 15-Feb-85 13:25:18 (Brian Beach)
%  Commented out a couple of functions for Pisces.
% 01-Feb-85 (Bill Williams)
%  Add external entries for Lisp terminal emulator.
% 24-Jan-85 (Vicki O'Day)
%  Added sleep entry.
% 7-Jan-85 (Vicki O'Day)
%  Removed nmodekeys entry.
% 17-Dec-84 (Vicki O'Day)
%  Added setlinebuf entry.
%  Added syscall entry, for access to HP-UX system calls.  The syntax
%  of this command is (syscall <system call #> <arg1> <arg2> ...).
%  Currently, a limit of four arguments to the system call is imposed,
%  since no system calls that we can use have more than this.  The
%  various forms of execl do, but since we can't use fork now, we don't
%  need this.  When we can use fork, the number of arguments allowed
%  by syscall should be increased.
% 7-Dec-84 (Vicki O'Day)
%  Added nmodekeys entry, so 9836-users can call it.
% 27-Sep-84 19:57:38 (Dave Matthews)
%  Added an external function declaration for the new alterheapsize function.
% 17-Jul-84 22:51:12 (RAM)
%  Changed chdir to unixcd and time to external_time.
%  Added external_stat, link, and unlink.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(compiletime
 (setf *foreign-functions* nil)
 )
 
(compiletime 
  (flag '(unixfread unixfputc unixfgetc unixfgets unixfwrite unixfflush
          whatsup ) % WN 
	'protected))               
	

(compiletime
 (defmacro external-function (name args)
    (let ((*lower t)) 
     (setf *foreign-functions* (cons name *foreign-functions*))
     (flag1 name 'foreignfunction)
     (when (null (get name 'symbol))
	   (put name 'symbol (bldmsg "_%w" name)))
     (if (flagp name 'protected)
     
     `(de ,name ,args
	(if (wlessp bruch_bruch 0) 
	    (terminal-interrupt)
	    (,name ,@args))
      )

     `(de ,name ,args
	(,name ,@args)
	)
     )
 )))
 
(off r2i)
%
% For asking for interrupts
%
(external-function whatsup             (x))

(external-function getpid               ())

% Defined in echo.c
%
(external-function echoon               ())
(external-function echooff              ())
(external-function external_charsininputbuffer    (chan))
(external-function flushstdoutputbuffer ())
(external-function external_user_homedir_string    ())
% (external-function external_anyuser_homedir_stringgggggg (user))


% Defined in bpsheap.c
%
(external-function alterheapsize        (integer))
(external-function allocatemorebps    (amount))
 
% Defined in file-status.c
%
(external-function get_file_status      (filename block flag))
 
 
% Defined in os-hooks.c
%
(external-function os_startup_hook      (pargc pargv))
(external-function os_cleanup_hook      ())
 
 
% Defined in pslextras.c
%
(external-function external_alarm      (sec))
(external-function external_ualarm     (usec repeat))
(external-function external_time       (buffer))
(external-function external_timc       (buffer))
(external-function external_stat       (path buf))
(external-function external_link       (path1 path2))
(external-function external_unlink     (path))
%  (external-function external_strlen     (strptr))
(external-function external_setenv     (varstring valstring))
(external-function external_getenv     (envstring))
(external-function uxfloat             (buffer integer))
(external-function uxfix               (buffer))
(external-function uxassign            (arg1-buffer arg2-buffere))
(external-function uxplus2             (result-buffer arg1-buffer arg2-buffer))
(external-function uxdifference        (result-buffer arg1-buffer arg2-buffer))
(external-function uxtimes2            (result-buffer arg1-buffer arg2-buffer))
(external-function uxquotient          (result-buffer arg1-buffer arg2-buffer))
(external-function uxgreaterp          (arg1-buffer arg2-buffer tee nill))
(external-function uxlessp             (arg1-buffer arg2-buffer tee nill))
(external-function uxwritefloat        (buffer floatptr convstr))
(external-function uxdoubletofloat     (x y))
(external-function uxfloattodouble     (y y))
(external-function uxsin           (r x))
(external-function uxcos           (r x))
(external-function uxtan           (r x))
(external-function uxasin           (r x))
(external-function uxacos           (r x))
(external-function uxatan           (r x))
(external-function uxsqrt           (r x))
(external-function uxexp           (r x))
(external-function uxlog           (r x))
(external-function uxatan2           (r y x))
 
 
% Defined in pwd-fn.c
%
(external-function external_pwd         ())
 
 
% Defined in sigs.c
%
(external-function sun3_sigset               (signame handler))
(external-function sigrelse             (signame handler))
 
 
% Defined In unexec.c
%
(external-function unexec               (newname aname dstart bstart))
 
 
% Defined in unix-io.c
%
(external-function unixputc             (ch))
(external-function unixputs             (str))
(external-function unixputn             (num))
(external-function unixcleario          ())
(external-function expand_file_name     (str))
(external-function unixopen             (name mode))
(external-function unixcd               (dir))

(external-function unixfread                (buf size count fp))
(external-function unixfputc                (ch fp))
(external-function unixfgetc                (fp))
(external-function unixfgets                (buf count fp))
(external-function unixfwrite               (str strlen count fp))
(external-function unixfflush               (fp))

(external-function ctime                (buffer))
(external-function external_system      (command))
 
 
% Defined In the C Library
%
(external-function external_exit        (status))
(external-function fopen                (name mode))
(external-function fclose               (fp))
(external-function fseek                (fp offset ptrname))
(external-function clearerr             (fp))
(external-function getw                 (fp))
(external-function putw                 (w fp))
(external-function signal               (signame handler))
(external-function sleep        (sec))
(external-function ieee_handler (str1 str2 handl)) 
(external-function ieee_flags           (str1 str2 str3 str4))
 
%% See $pxnk/sys-io.sl for the call to this. In SYS V, it may have to be
%% moved into the microkernel since it is not directly supported. Under
%% SYS V, buffering can only be changed before any writes on the stream,
%% which means it must be called before setupbpsandheap. Also, under BSD,
%% setlinebuf is a system call, while under SYS V, it must be written using
%% setbuf and setvbuf. See the Bobcat version of setlinebuf.c in $pb.
(external-function setlinebuf           (iobuff))
(external-function profil               (a b c d)) 
 
(external-function datetag() )

% for windows interfacing

(external-function psll_call (p1 p2 p3 p4))

(on r2i)
 
(compiletime
 (for (in name *foreign-functions*)
      (do (remflag1 name 'foreignfunction))
      ))

 (de unix-profile(a b c d)(profil a b c d))

% redirect file io to routines with names prefixed by "unix"

(de fread(buf size count fp) (unixfread buf size count fp))
(de fputc(ch fp) (unixfputc ch fp))
(de fgetc(fp) (unixfgetc fp))
(de fgets (buf count fp) (unixfgets buf count fp))
(de fwrite (str strlen count fp) (unixfwrite str strlen count fp))
(de fflush (fp) (unixfflush fp))

