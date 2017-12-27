#! /bin/bash -v

# Investigate cross-building PSL using a different Lisp as base.


# First make the "vsl" mini-lisp with an option that causes its readee
# to be broadly compatible with PSL. Specifically most punctuation
# characters must be constituents of symbols, and a sequence that starts
# off looking like a number can end up as a symbol if continued with
# characters that are neither whitespace nor brackets (or otherwise special).

# The resulting system is copied to the top-level directory for later use.

make clean
make psl

# Load in (interpreted forms of) the PSL compiler and some associated
# utilities, and checkpoint the result.

script -c "./vsl psl-compiler.lsp" psl-compiler.log

# Test it

./vsl <<EOF |& tee test-compiler.log 

(setq !*echo t) (setq !*plap t) (setq !*pgwd t)

(de foo (n)
  (if (zerop n)
      1
      (times n (foo (sub1 n)))))

(trace '(lap))
(setq *test-lap t)
(setq *lapopt t)
(setq *trlapopt t)

(compile '(foo))

(dm codeprintf (x) (list 'fprintf 'codeout* (cadr x) (cons 'list (cddr x))))
(dm dataprintf (x) (list 'fprintf 'dataout* (cadr x) (cons 'list (cddr x))))

% This is needed for ASM generation, see $pxk/main-start.sl
(put 'symnam 'symbol 'symnam)
(put 'symfnc 'symbol 'symfnc)
(put 'symget 'symbol 'symget)
(put 'symval 'symbol 'symval)
(put 'symprp 'symbol 'symprp)

(setq !*writingasmfile t) (setq !*plap t) (setq !*pgwd t)

(asmout "foo")

(de foo (n)
  (if (zerop n)
      1
      (times n (foo (sub1 n)))))

(asmend)

EOF
