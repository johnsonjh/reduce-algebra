(setf *writingasmfile t)
(reload sys-consts)
(off pcmac)
(off usermode)
(on verboseload)
(asmout "main")
(dskin "$pk/firstkernel.sl")
(dskin "/root/psl/dist/kernel/AMD64/main-start.sl")
(dskin "/root/psl/dist/kernel/AMD64/io.sl")
(dskin "/root/psl/dist/kernel/AMD64/intern.sl")
(dskin "/root/psl/dist/kernel/AMD64/faslin.sl")
(dskin "/root/psl/dist/kernel/AMD64/alloc.sl")
(dskin "/root/psl/dist/kernel/support.sl")
(dskin "/root/psl/dist/kernel/AMD64/sys-support.sl")
(dskin "/root/psl/dist/kernel/AMD64/externals.sl")
(dskin "$pk/lastkernel.sl")
(asmend)
(exitlisp)
