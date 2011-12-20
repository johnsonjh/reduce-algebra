#! /bin/sh

# Extract for buildsh to only save a new image.
# Takes image file dir and toplevel pslbuild dir pathname as arguments
#
# Usage:
#         .../psl/saveimage.sh .../imagedir /usr/lib/reduce/pslbuild

# This script must live in the PSL directory, but it builds things in the
# current directory.

a=$0
c=unknown
case $a in
/* )
  c=$a  
  ;;
*/* )
  case $a in
  ./* )
    a=`echo $a | sed -e s+./++`
    ;;
  esac
  c=`pwd`/$a
  ;;
* ) 
  for d in $PATH
  do
    if test -x $d/$a
    then
      c=$d/$a
    fi
  done
  if test $c = "unknown" ;then
    echo "Unable to find full path for script. Please re-try"
    echo "launching it using a fully rooted path."
    exit 1
  fi
  ;;
esac

cpsldir=`echo $c | sed -e 's+/[^/]*$++'`
creduce=$cpsldir/..
chere=`pwd`
cfasl=$chere/red

if test -x /usr/bin/cygpath
then
  psldir=`cygpath -m "$cpsldir"`
  reduce=`cygpath -m "$creduce"`
  here=`cygpath -m "$chere"`
  fasl=`cygpath -m "$cfasl"`
else
  psldir="$cpsldir"
  reduce="$creduce"
  here="$chere"
  fasl="$cfasl"
fi

imagedir="$1"
if test -d "$imagedir"
then
  :
else
  mkdir -p "$imagedir"
fi

if test -z "$2"
then
  topdir="$here"
else
  topdir="$2"
fi

if test -f psl/64
then
STORE=600
else
STORE=64000000
fi

export here fasl psldir reduce

if test -d "$chere/log"
then
  :
else
  mkdir -p "$chere/log"
fi

cd psl

./bpsl -td $STORE <<XXX > $chere/log/reduce.blg
% This re-starts a bare reduce and loads in the modules compiled
% by the very first step. It then checkpoints a system that can be
% used to rebuild all other modules.

(setq symbolfilename!* "$here/psl/bpsl")
(setq loaddirectories!* (quote ("" "$here/red/" "$here/psl/")))

(reclaim)
(setq !*init!-stats!* (list (time) (gtheap nil) (free-bps) nextsymbol))

(setq !*usermode nil)
(setq !*verboseload t)
(setq !*argnochk t)                % Check argument count.
(setq prolog_file 'pslprolo)
(setq rend_file 'pslrend)

(cond ((filep "symget.b")
       (dskin "$reduce/psl/symget.dat")))

(cond ((filep "addr2id.b")
       (load addr2id)))            % For debugging purposes.

(cond ((filep "pipes.b")
       (load pipes)))              % Unix pipes.

(load zbig)                        % PSL bignums.
(errorset '(load compat) nil nil)  % Load PSL-based functions if there.
(load module)                      % Contains definition of load-package.
(load pslprolo)                    % PSL specific code.

(load!-package 'rlisp)
(load!-package rend_file)
(load!-package 'poly)
(load!-package 'arith)
(load!-package 'alg)
(load!-package 'mathpr)
(load!-package 'entry)
(setq version!* "REDUCE Experimental Version") (setq date!* (date))
(initreduce)

(setq !*loadversion t)             % Load entry module during BEGIN.
(setq !*verboseload nil)           % Inhibit loading messages.

(cond ((and (memq (quote sparc) lispsystem!*)
            (getd (quote supersparc)))
       (supersparc)))

(prog nil
   (reclaim)
   (terpri)
   (prin2 "Time for build: ")
   (prin2 (quotient (difference (time) (car !*init!-stats!*)) 1000.0))
   (prin2t " secs")
   (prin2 "Symbols used:   ")
   (prin2t (difference nextsymbol (cadddr !*init!-stats!*)))
   (prin2 "Heap used:      ")
   (prin2t (difference (cadr !*init!-stats!*) (gtheap nil)))
   (prin2 "BPS used:       ")
   (prin2t (difference (caddr !*init!-stats!*) (free-bps)))
   (prin2 "Heap left:      ")
   (prin2t (gtheap nil))
   (prin2 "BPS left:       ")
   (prin2t (free-bps))
  (setq !*init!-stats!* nil))

(setq symbolfilename!* "$topdir/psl/bpsl")
(setq loaddirectories!* (quote ("" "$topdir/red/" "$topdir/psl/")))

(savesystem "REDUCE" "$imagedir/reduce" (quote ((read-init-file "reduce"))))
(bye)

XXX

