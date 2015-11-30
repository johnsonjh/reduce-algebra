% ----------------------------------------------------------------------
% $Id$
% ----------------------------------------------------------------------
% Copyright (c) 1995-2009 A. Dolzmann and T. Sturm, 2010-2011 T. Sturm
% ----------------------------------------------------------------------
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

lisp <<
   fluid '(cl_qe_rcsid!* cl_qe_copyright!*);
   cl_qe_rcsid!* := "$Id$";
   cl_qe_copyright!* := "(c) 1995-2009 A. Dolzmann, T. Sturm, 2010-2012 T. Sturm"
>>;

module clqe;
% Common logic quantifier elimination by elimination sets. Submodule of [cl].
% Currently limited to quadratic formulas.

%DS
% TaggedContainerElementL ::= Status . ContainerElementL
% Status ::= "elim" | "failed" | "local" | "nonocc"
% ContainerElementL ::= (ContainerElement, ...)
% ContainerElement ::= ('ce, VarList, QfFormula, Kernel, SubstTriplet,
% Answer, Vector)
% VarList ::= VariableL | "'break"
% Answer ::= (SubstTriplet, ...) (* "nil" if not ans *)
% SubstTriplet ::= (Variable, SubstFunction, ArgumentList)

struct TaggedContainerElementL asserted by taggedContainerElementLP;
struct ContainerElementL asserted by listp;
struct ContainerElement asserted by containerElementP;
struct VarList asserted by varListP;
struct Answer asserted by listp;
struct SubstTriplet asserted by substTripletP;

procedure taggedContainerElementLP(x);
   pairp x and car x memq '(elim failed local nonocc) and listp cdr x;

procedure containerElementP(x);
   eqcar(x, 'ce);

procedure varListP(x);
   x eq 'break or listp x;

procedure substTripletP(x);
   listp x and eqn(length x,3);


%DS
% Container ::= (ContainerElementL . QfFormulaL)

struct Container asserted by pairp;


%DS
% Point ::= (Coordinate, ...)
% Coordinate ::= Equation (* Kernel = Integer *)

struct Point asserted by listp;

%%%%%%%MAX
%DS
% InfCoreData ::= [InfCore, FalseVect, EvTPList, MaxFalse, Coverage,
%                  CurrentFVect, GuardList, Knowl, EssentialVect, VarList, CADCellList]
% InfCore ::= (QFFormula,...)
% FalseVect ::= [Integer,...]
% EvTPList ::= (EvTP,...)
% EvTP ::= [T | nil, ...]
% MaxFalse ::= Integer . Integer
% Coverage ::= Integer
% CurrentFVect ::= [QFFormula,...]
% GuardList ::= (QFFormula,...)
% Knowl ::= (IR,...)
% EssentialVect ::= [T | nil,...]
% VarList ::= VariableL
% CADCellList ::= (ACell,...)


struct InfCoreData asserted by listp;

asserted procedure ic_init(f: Formula): InfCoreData;
   % Infeasible Core Initialize. Create, initialize and return
   % infeasible core data from a fully existentially quantified
   % formula [f].
   begin scalar icdata, fList, k;
      icdata := mkvect 14;
      fList :=cl_ftol(f);
      k := length fList - 1;
      putv(icdata, 1, list2vector for i := 0 : k collect 0);
      putv(icdata, 4, 0);
      putv(icdata, 5, list2vector flist);
      %putv(icdata, 6, mkvect k);
      putv(icdata, 8, mkvect k);
      putv(icdata, 12, list2vector flist);
      return icdata
   end;

procedure cl_ftol(f);
   begin scalar flist;
      fList :=caddr cl_split(f);
      if rl_op fList = 'and  then
      	 return rl_argn fList
      else return {fList}
   end;

asserted procedure ic_setoffsetlist(icdata: InfCoreData, l:List): Any;
   putv(icdata, 13, l);

asserted procedure ic_offsetlist(icdata: InfCoreData): List;
   getv(icdata, 13);


asserted procedure ic_infcore(icdata: InfCoreData): List;
   % Infeasible Core Data Infeasible Core. Contains a subset of the
   % elements in the formula vector which, at the end of the
   % computation, will be unsatisfiable.
   getv(icdata, 0);

asserted procedure ic_setinfcore(icdata: InfCoreData, l: List): List;
   % Infeasible Core Data Infeasible Core. Contains a subset of the
   % elements in the formula vector which, at the end of the
   % computation, will be unsatisfiable.
   putv(icdata, 0,l);

asserted procedure ic_taglist(icdata: InfCoreData): List;
   getv(icdata, 11);

asserted procedure ic_originalfvect(icdata: InfCoreData): List;
   getv(icdata, 12);


asserted procedure ic_taglistremfalse(icdata: InfCoreData): List;
begin scalar l;
   l := getv(icdata,11);
   if caar l = 'false then <<
      putv(icdata,11,cdr l);
      return cdar l
   >>;
   return nil
end;

asserted procedure ic_settaglist(icdata: InfCoreData, l): List;
   putv(icdata, 11,l);

asserted procedure ic_appendtaglist(icdata: InfCoreData, p): List;
   putv(icdata, 11, p . getv(icdata, 11));

asserted procedure ic_appendinfcore(icdata: InfCoreData, k:Integer);
   putv(icdata, 0, k . getv(icdata, 0));

asserted procedure ic_falsevect(icdata: InfCoreData): Vector;
   % Infeasible Core Data False Vector. The Vector contains the number
   % of test points that evaluate to false for each formula in the
   % formula vector.
   getv(icdata, 1);

asserted procedure ic_addtofalsevect(icdata: InfCoreData, k: Integer, j:Integer): Vector;
   putv(ic_falseVect rlqeicdata!*, k,
      getv(ic_falsevect rlqeicdata!*, k) + j);

asserted procedure ic_evtplist(icdata: InfCoreData): List;
   % Infeasible Core Evaluated Test Point List. Each test point
   % consists of a vector of truth values. The ith truth value is T if
   % the ith formula in the formula vector gives true when evaluated
   % at the test point represented by this list.
   getv(icdata, 2);

asserted procedure ic_appendevtplist(icdata: InfcoreData, tpl: List): Any;
   putv(icdata, 2, tpl . getv(icdata, 2));

asserted procedure ic_maxfalseel(icdata: InfCoreData): Integer;
   % Infeasible Maximal False Element. Index of the formula in the
   % formula vector that gives false for the most test points that are
   % not yet covered by the current infeasible core.
   getv(icdata, 3);

asserted procedure ic_coverage(icdata: InfCoreData): Integer;
   % Infeasible Core Coverage. The number of test points that have yet
   % to be covered by the infeasible core.
   getv(icdata, 4);

asserted procedure ic_addcoverage(icdata: InfCoreData, k: Integer): Any;
   putv(icdata, 4, getv(icdata, 4) + k);

asserted procedure ic_currentfvect(icdata: InfCoreData): Vector;
   % Infeasible Core Current Formula Vector. Each entry represents one
   % of the input constraints at the current virtual substitution step.
   getv(icdata, 5);

asserted procedure ic_setcurrentfvect(icdata: InfCoreData, v: Vector): Any;
   putv(icdata, 5, v);

asserted procedure ic_guardList(icdata: InfCoreData): List;
   % Infeasible Core Guard List. An AList which associates guards with
   % the formulas from which they emerged.
   getv(icdata, 6);

asserted procedure ic_clearguardList(icdata: InfCoreData): List;
   % Infeasible Core Guard List. An AList which associates guards with
   % the formulas from which they emerged.
   putv(icdata, 6, nil);

asserted procedure ic_appendguardlist(icdata: InfcoreData, el: Any): Any;
   putv(icdata, 6, el . getv(icdata, 6));

asserted procedure ic_knowl(icdata: InfCoreData): List;
   % Infeasible Core Knowledge. Contains currently known bounds for
   % the simplification process.
   getv(icdata, 7);

asserted procedure ic_setknowl(icdata: InfCoreData, knowl: Any): List;
   putv(icdata, 7, knowl);

asserted procedure ic_essentialvect(icdata: InfCoreData): Vector;
   % Infeasible Core Essential List. Contains indices of formulas in
   % the formula vector that are known to be a necessary part of the
   % infeasible core.
   getv(icdata, 8);

asserted procedure ic_varlist(icdata: InfCoreData): List;
   % Infeasible Core Variable List.
   getv(icdata, 9);

asserted procedure ic_setvarlist(icdata: InfCoreData, l: List): List;
   putv(icdata,9,l);

asserted procedure ic_insertvarlist(icdata: InfCoreData, v: Pair): List;
   putv(icdata, 9, lto_insertqcar(v, getv(icdata, 9)));

asserted procedure ic_resetcadcellList(icdata: InfCoreData): Any;
   putv(icdata, 10, nil);

asserted procedure ic_cadcellList(icdata: InfCoreData): List;
   % Infeasible Core CAD Cell List. Contains all the leafs of the CAD tree
   % after a CAD call.
   getv(icdata, 10);

asserted procedure ic_appendcadcellList(icdata: InfCoreData, cell: Any): List;
   % Infeasible Core CAD Cell List. Contains all the leafs of the CAD tree
   % after a CAD call.
   putv(icdata, 10, cell . getv(icdata, 10));

%DS
% EliminationResult ::= (Theory . ExtendedQeResult)
% ExtendedQeResult ::= (..., (QfFormula, SamplePoint), ...)
% SamplePoint ::= EquationL (* with equations of the form kernel = ... *)

struct EliminationResult asserted by pairp;
struct ExtendedQeResult asserted by alistp;

declare ce_mk: (VarList, QfFormula, Kernel, List, Answer, List) -> ContainerElement;
inline procedure ce_mk(vl, f, v, eterm, an, fvect); %%%%%%%MAX
   % Container element make.
   {'ce, vl, f, v, eterm, an, fvect};

declare ce_vl: (ContainerElement) -> VarList;
inline procedure ce_vl(x);
   % Container element variable list.
   car cdr x;

declare ce_f: (ContainerElement) -> QfFormula;
inline procedure ce_f(x);
   % Container element formula.
   cadr cdr x;

declare ce_v: (ContainerElement) -> Kernel;
inline procedure ce_v(x);
   % Container element variable.
   caddr cdr x;

declare ce_eterm: (ContainerElement) -> List;
inline procedure ce_eterm(x);
   % Container element substitution triplet.
   cadddr cdr x;

declare ce_ans: (ContainerElement) -> Answer;
inline procedure ce_ans(x);
   % Container element answer.
   nth(cdr x, 5);

declare ce_fvect: (ContainerElement) -> Vector;%%%%%%%MAX
inline procedure ce_fvect(x);
   % Container element formula vector. Only used for infeasible core computation.
   nth(cdr x, 6);

asserted procedure co_new(): Container;
   % Container make.
   nil . nil;

inline procedure co_data(co);
   car co;

inline procedure co_dynl(co);
   cdr co;

inline procedure co_setData(co,data);
   rplaca(co,data);

inline procedure co_setDynl(co,dynl);
   rplacd(co,dynl);

asserted procedure co_save(co: Container, dol: ContainerElementL): Container;
   % Container save.
   if !*rlqedfs and !*rlqedyn then
      co_dynpush(co,dol)
   else if !*rlqedfs then
      co_push(co,dol)
   else
      co_enqueue(co,dol);

asserted procedure co_dynPush(co: Container, dol: ContainerElementL): Container;
   % Container dynamic programming push.
   <<
      for each ce in dol do
      	 co := co_dynPush1(co,ce);
      co
   >>;

asserted procedure co_dynPush1(co: Container, ce: ContainerElement): Container;
   % Container dynamic programming push 1 element.
   begin scalar f,vl;
      f := ce_f ce;
      vl := ce_vl ce;
      if lto_hmember(vl . f,co_dynl co,'co_hfn) then <<
	 if !*rlverbose and !*rlqevb and !*rlqevbold then
	    ioto_prin2 "@";
	 return co
      >>;
      co_setDynl(co,lto_hinsert(vl . f,co_dynl co,'co_hfn));
      co_setData(co,ce . co_data co);
      return co
   end;

asserted procedure co_hfn(item: ContainerElement): List2;
   % Container hash function.
   {cl_fvarl1 cdr item,rl_atnum cdr item};

asserted procedure co_push(co: ContainerElementL, dol: ContainerElementL): Container;
   % Container push.
   <<
      for each ce in dol do
      	 co := co_push1(co,ce);
      co
   >>;

asserted procedure co_push1(co: Container, ce: ContainerElement): Container;
   % Insert 1 element into container.
   co_setData(co,co_push2(co_data co,ce));

asserted procedure co_push2(co: Container, ce: ContainerElement): Container;
   %TODO: REENABLE %%%%%%%MAX
   % Insert 1 element into container.
   % if co_member(ce,co) then <<
   %    if !*rlverbose and !*rlqevb and !*rlqevbold then
   % 	 ioto_prin2 "@";
   %    co
   % >> else
      ce . co;

asserted procedure co_enqueue(co: Container, dol: ContainerElementL): Container;
   % Container enqueue.
   co_setData(co,co_enqueue1(co_data co,dol));

asserted procedure co_enqueue1(co: Container, dol: ContainerElementL): Container;
   % Container enqueue.
   <<
      if null co and dol then <<
	 co := {nil,car dol};
	 car co := cdr co;
	 dol := cdr dol
      >>;
      for each x in dol do
	 if not co_member(x,cdr co) then
	    car co := (cdar co := {x});
      co
   >>;

asserted procedure co_get(co: Container): DottedPair;
   % Container get. Returns $(e . c)$ where $e$ is a container element and $c$
   % is the container [co] without the entry $e$.
   if !*rlqedfs then co_pop co else co_dequeue co;

asserted procedure co_pop(co: Container): DottedPair;
   % Container pop. Returns $(e . c)$ where $e$ is a container element and $c$
   % is the container [co] without the entry $e$.
   begin scalar a;
      a := car co_data co ;
      co_setData(co,cdr co_data co);
      return a . co
   end;

asserted procedure co_dequeue(co: Container): DottedPair;
   begin scalar a,d;
      a . d := co_dequeue1 co_data co;
      co_setData(co,d);
      return a . co
   end;

asserted procedure co_dequeue1(co: Container): DottedPair;
   % Container dequeue. Returns $(e . c)$ where $e$ is a container element and
   % $c$ is the container [co] without the entry $e$.
   if co then cadr co . if cddr co then (car co . cddr co);

asserted procedure co_length(co: Container): Integer;
   % Container length. Returns the number of elements in [co].
   if !*rlqedfs or null co_data co then
      length co_data co
   else
      length co_data co - 1;

asserted procedure co_member(ce: ContainerElement, l: ContainerElementL): ExtraBoolean;
   % Container member. Returns non-[nil], if there is an container element $e$
   % in [l], such that the formula and the variable list of $e$ are equal to the
   % formula and variable list of [ce]. This procedure does not use the access
   % functions.
   l and (ce_vl ce = ce_vl car l and ce_f ce = ce_f car l
      or co_member(ce,cdr l));

asserted procedure co_stat(co: Container): AList;
   begin scalar al,w; integer n;
      for each ce in co_data co do <<
	 n := length ce_vl ce;
	 w := assoc(n,al);
	 if w then cdr w := cdr w + 1 else al := (n . 1) . al
      >>;
      return sort(al,function(lambda(x,y); car x >= car y))
   end;

%DS
% JunctionL ::= (Junction, ...)
% Junction ::= QfFormula . Answer

struct JunctionL asserted by listp;
struct Junction asserted by pairp;


declare cl_mkJ: (QfFormula,Answer) -> Junction;
inline procedure cl_mkJ(f,an);
   % Make junction.
   f . an;


declare cl_jF: (Junction) -> QfFormula;
inline procedure cl_jF(j);
   % Junction formula.
   car j;


declare cl_jA: (Junction) -> Answer;
inline procedure cl_jA(j);
   % Junction answer.
   cdr j;


declare cl_co2J: (ContainerElement) -> Junction;
inline procedure cl_co2J(x);
   % Container to junction. Returns the S-expression [ce_f(x) . ce_ans(x)]
   ce_f x . ce_ans x;


declare cl_erTh: (EliminationResult) -> Theory;
inline procedure cl_erTh(er);
   % Elimination result theory.
   car er;


declare cl_erEQR: (EliminationResult) -> ExtendedQeResult;
inline procedure cl_erEQR(er);
   % Elimination result extended qe result.
   cdr er;


declare cl_mkER: (Theory,ExtendedQeResult) -> EliminationResult;
inline procedure cl_mkER(theo,eqr);
   % Make elimination Result.
   theo . eqr;


declare cl_mk1EQR: (Formula,EquationL) -> ExtendedQeResult;
inline procedure cl_mk1EQR(f,eql);
   % Make singleton extended qe result.
   {{f,eql}};

asserted procedure cl_gqe(f: Formula, theo: Theory, xbvl: KernelL): TheoryFormulaPair;
   % Generic quantifier elimination. Returns a pair $\Theta . \phi$. $\Theta$ is
   % a THEORY extending [theo] by assumptions on free variables of [f] that are
   % not in [xbvl]; $\phi$ is a formula. We have $\Theta \models [f]
   % \longleftrightarrow \phi$. $\phi$ is obtained from [f] by eliminating as
   % many quantifiers as possible. Accesses the switch [rlqepnf]; if [rlqepnf]
   % is on, then [f] must be prenex.
   begin scalar er,theo,!*rlqegen,!*rlsipw,!*rlsipo;
      !*rlsipw := !*rlqegen := T;
      er := cl_qe1(f,theo,xbvl);
      if rl_exceptionp er then
	 return er;
      theo := rl_thsimpl cl_erTh er;
      return theo . rl_simpl(caar cl_erEQR er,theo,-1)
   end;

asserted procedure cl_gqea(f: Formula, theo: Theory, xbvl: KernelL): EliminationResult;
   % Generic quantifier elimination with answer. Returns a pair $\Theta . \Phi$.
   % $\Theta$ extends [theo] by assumptions on free variables of [f] that are
   % not in [xbvl]; $\Phi$ is a list $(..., (c_i, A_i), ...)$, where the $c_i$
   % are QfFormula, and the $A_i$ are lists of equations. We have $\Theta
   % \models \bigvee_i c_i \longleftrightarrow [f]$. Whenever some $c_i$ holds
   % for an interpretation of the parameters, then [f] holds, and $A_i$
   % describes a satisfying sample point. Accesses the switch [rlqepnf]; if
   % [rlqepnf] is on, then [f] must be prenex.
   begin scalar er,!*rlqegen,!*rlsipw,!*rlsipo,!*rlqeans;
      !*rlsipw := !*rlqegen := !*rlqeans := T;
      er := cl_qe1(f,theo,xbvl);
      if rl_exceptionp er then
	 return er;
      return cl_mkER(rl_thsimpl cl_erTh er,cl_erEQR er)
   end;

asserted procedure cl_lqe(f: Formula, theo: Theory, pt: Point): TheoryFormulaPair;
   % Local quantifier elimination. [pt] is the suggested value for the local
   % parameter $v$. Returns a pair $\Theta . \phi$. $\Theta$ extends [theo];
   % $\phi$ is a formula. We have $\Theta \models [f] \longleftrightarrow \phi$.
   % $\phi$ is obtained from [f] by eliminating as much quantifiers as possible.
   % Accesses the switch [rlqepnf]; if [rlqepnf] is on, then [f] has to be
   % prenex. Accesses the fluids [cl_pal!*], [cl_lps!*], and [cl_theo!*].
   % [cl_lps!*] is the list of local parameters; [cl_pal] is an Alist containing
   % the suggested values for the local parameters; and [cl_theo!*] is the
   % theory generated by the local quantifier elimination.
   begin scalar w,er,theo,!*rlqelocal,!*rlsipw,!*rlsipo,cl_pal!*,cl_lps!*,
	 cl_theo!*;
      !*rlsipw := !*rlqelocal := T;
      cl_pal!* := pt;
      cl_lps!* := for each x in pt collect car x;
      cl_theo!* := nil;
      w := for each x in theo collect rl_subat(cl_pal!*,x);
      w := rl_simpl(rl_smkn('and,w),nil,-1);
      if w eq 'false then
	 rederr "rllqe: inconsistent theory";
      er := cl_qe1(f,theo,nil);
      theo := nconc(cl_theo!*,theo);
      cl_pal!* := cl_lps!* := cl_theo!* := nil;
      if rl_exceptionp er then
	 return er;
      return rl_lthsimpl(theo) . rl_simpl(caar cl_erEQR er,theo,-1)
   end;

asserted procedure cl_aqe(f: Formula, theo: Theory, pt: Point): TheoryFormulaPair;
   % Approximate quantifier elimination. [f] is a formula; [theo] is a
   % THEORY; [pt] is a list of equations $v=z$, where $v$ is a variable
   % and $z$ is an SQ encoding a rational number, namely the suggested
   % value for the existential variable $v$. Returns a pair $\Theta .
   % \phi$. $\Theta$ is a THEORY extending [theo]; $\phi$ is a formula.
   % Accesses the switch [rlqepnf]; if [rlqepnf] is on, then [f] must be
   % prenex. Accesses the fluids [cl_pal!*], [cl_lps!*], and
   % [cl_theo!*]. [cl_lps!*] is the list of existential variables for
   % which values are suggested; [cl_pal!*] is a corresponding ALIST
   % containing also the suggested values; [cl_theo!*] is the theory
   % generated by the local quantifier elimination. These 3 fluids have
   % been hijacked from cl_lqe, where they have got a different
   % semantics.
   begin scalar w,theo,!*rlqeapprox,cl_pal!*,cl_lps!*,cl_theo!*;
      !*rlqeapprox := t;
      cl_pal!* := pt;
      cl_lps!* := for each x in pt collect car x;
      cl_theo!* := nil;
      w := rl_simpl(rl_smkn('and,w),nil,-1);
      if w eq 'false then
	 rederr "rllqe: inconsistent theory";
      w := cl_qe1(f,theo,nil);
      theo := nconc(cl_theo!*,theo);
      w := cl_erEQR w;
      cl_pal!* := cl_lps!* := cl_theo!* := nil;
      return rl_lthsimpl(theo) . rl_simpl(w,theo,-1)
   end;

asserted procedure cl_qe(f: Formula, theo: Theory): Formula;
   % Quantifier elimination. Returns a formula $\phi$ such that $[theo] \models
   % [f] \longleftrightarrow \phi$. $\phi$ is obtained from [f] by eliminating
   % as many quantifiers as possible. Accesses the switch [rlqepnf]; if
   % [rlqepnf] is on, then [f] has to be prenex.
   begin scalar er,!*rlsipw,!*rlsipo;
      !*rlsipw := !*rlsipo := T;
      er := cl_qe1(f,theo,nil);
      if rl_exceptionp er then
	 return er;
      return caar cl_erEQR er
   end;

asserted procedure cl_qea(f: Formula, theo: Theory): ExtendedQeResult;
   % Quantifier elimination with answer. Returns a list of pairs $(..., (c_i,
   % A_i), ...)$. The $c_i$ are quantifier-free formulas, and the $A_i$ are
   % lists of equations. We have $[theo] \models \bigvee_i c_i
   % \longleftrightarrow [f]$. Whenever some $c_i$ holds for an interpretation
   % of the parameters, [f] holds, and $A_i$ describes a satisfying sample
   % point. Accesses the switch [rlqepnf]; if [rlqepnf] is on, then [f] has to
   % be prenex.
   begin scalar er,!*rlsipw,!*rlsipo,!*rlqeans,ic;
      !*rlsipw := !*rlsipo := !*rlqeans := T;
      !*rlqestdans:=T;
      % Initialize infeasible core data structure
      if !*rlqeinfcore then << %%%%%%%MAX
	 !*rlqesr := t;
	 !*rlataltheo:=nil;
	 !*rlqestdans:=T;
	 rlqeicdata!* := ic_init f;
	 %TODO: REENABLE
	 !*rlqedyn:=nil
      >>;
      er := cl_qe1(f,theo,nil);
      if rl_exceptionp er then
	 return er;
      % Infeasible core computation
      if !*rlqeinfcore then %%%%%%%MAX
	 if er={nil} or caadr er eq 'false then <<
	    ic_computeinfcore rlqeicdata!*;
	    ic := ic_infcore rlqeicdata!*;
	    ioto_tprin2t {"infcore: ", ic_infcore rlqeicdata!*};
	    ioto_tprin2t {"infcore length: ", length ic_infcore rlqeicdata!*};
	    rlqeicdata!* := ic_init f;
	    ioto_tprin2t {"input length: ",upbv(ic_currentfvect rlqeicdata!*)+1};
      	    % newF:=nil;
	    % for each n in ic do <<
	    %    newF:=getv(ic_currentfvect rlqeicdata!*,n) . newF;
	    % >>;
	    % newF:=rl_ex(rl_smkn('and,newF),nil);
	    % !*rlqeinfcore:=nil;
	    % ioto_tprin2t{"test: ",cl_qea(newF,nil)}
      	 >> else ioto_tprin2t{"model: ",cadar cl_erEQR er};
      return cl_erEQR er
   end;

%%%%%%%MAX
asserted procedure ic_computeInfCore(icdata: InfCoreData): Any;
   begin scalar essential,l;
      integer k,chosen;
      essential := ic_essentialvect icdata;
      for i := 0 : upbv essential do
	 if getv(essential, i) then <<
	    chosen := getv(ic_falsevect icdata, i);
	    ic_addcoverage(icdata, -chosen);
	    ic_appendinfcore(icdata, i);
 	    ic_updateevtpList(icdata, chosen, i);
	    ic_updatefalsevect(icdata)
	 >>;
      while ic_coverage icdata > 0 do <<
	 {chosen,k} := ic_maxfalse icdata;
	 ic_addcoverage(icdata, -chosen);
	 ic_appendinfcore(icdata, k);
	 ic_updateevtplist(icdata, chosen, k);
	 ic_updatefalsevect icdata
      >>;
      l:=nil;
      if ic_offsetlist icdata then <<
      	 for each e in ic_infcore icdata do 
      	    for each n in cadr assoc(e,ic_offsetlist(icdata)) do l:=lto_insertq(n,l);
      	 ic_setinfcore(icdata,l);
      >>
   end;

asserted procedure ic_updateevtplist(icdata: InfCoreData, chosen: Integer, k: Integer): Any;
   begin scalar evtplist;
      for each tp in ic_evtplist(rlqeicdata!*) do
	 if not (getv(tp, k) eq 'false) then 
	    evtpList := tp . evtplist;
      putv(icdata, 2, evtplist)
   end;

asserted procedure ic_updatefalsevect(icdata: InfCoreData): Any;
   begin
      putv(icdata, 1, list2vector for i := 0 : upbv ic_falsevect icdata collect 0);
      for each tp in ic_evtplist icdata do
	 for i := 0 : upbv tp do
	    if getv(tp, i) eq 'false then
	       ic_addtofalsevect(icdata, i, 1)
   end;

asserted procedure ic_maxfalse(icdata: InfCoreData): List;
   begin scalar falsevect; integer chosen,k,current;
      falsevect := ic_falsevect icdata;
      for i := 0 : upbv falsevect do <<
	 current := getv(falsevect, i);
	 if current > chosen then <<
	    chosen := current;
	    k := i
	 >>
      >>;
      return {chosen, k}
   end;

asserted procedure cl_qe1(f: Formula, theo: Theory, xbvl: KernelL): EliminationResult;
   % Quantifier elimination. [f] must be prenex if the switch [rlqepnf] is off;
   % [theo] serves as background theory.
   begin scalar q,ql,varl,varll,bvl,svf,result,w,ww,k,rvl,jl,f2,offset,offset2; integer n;
      if !*rlqepnf then
	 f := rl_pnf f;
      f2:=f;
      if !*rlqeinfcore then << %%%%%%%MAX
      	 !*rlqeicsimpl:=T;
	 !*icinitsimpl:=T;
      	 f:={f};
      	 f2:={{}};
      	 while not (car f2 = car f or car f eq 'false) do <<
      	    f2:=f;
      	    f := cl_simpl(car f2,theo,-1);
	    if offset then <<
	       if not (car f2 = car f) and not (car f = 'false) then <<
	       	  if not (car f2 = car f or car f eq 'false) then <<
	    	     offset2:=ic_offsetlist(rlqeicdata!*);
	    	     for each i in offset2 do <<
	    	     	w:= cadr i;
	    	     	ww:=nil;
	    	     	for each j in w do <<
	    		   for each k in cadr assoc(j,offset) do ww:=k.ww;
	    	     	>>;
	    	    	cadr i:=ww
	    	     >>
	       	  >>;
		  offset:=offset2
	       >>
	    >> else <<
 	       offset:=ic_offsetlist(rlqeicdata!*)
	    >>;
	    ic_setoffsetlist(rlqeicdata!*,nil)
      	 >>;
      	 !*rlqeicsimpl:=nil;
	 !*icinitsimpl:=nil;
      	 if car f eq 'false and cdr f then <<
      	    rlqeicdata!*:=ic_init(car f2);
      	    cl_filterlocalcore(list2vector(cl_ftol(car f2)),cadr f);
	    ic_setoffsetlist(rlqeicdata!*, offset);
      	    f:= car f
      	 >> else <<
      	    rlqeicdata!*:=ic_init(car f);
	    ic_setoffsetlist(rlqeicdata!*, offset);
	    f:=car f;
      	    if f eq ' false then putv(ic_essentialvect(rlqeicdata!*),0,T)
      	 >>
      >> else f:=rl_simpl(f,theo,-1);
      if f eq 'inctheo then
	 return rl_exception 'inctheo;
      if not rl_quap rl_op f then
	 return cl_mkER(theo,cl_mk1EQR(f,nil));
      {ql,varll,f,bvl} := cl_split f;
      % Remove from the theory atomic formulas containing quantified variables:
      theo := for each atf in theo join
	 if null intersection(rl_varlat atf,bvl) then {atf};
      bvl := union(bvl,xbvl);
      {ql,varll,q,rvl,jl,theo,svf} := cl_qe1!-iterate(ql,varll,f,theo,bvl);
      jl := cl_qe1!-requantify(ql,varll,q,rvl,jl);
      if !*rlqeans and null ql then <<
	 if !*rlverbose then <<
	    ioto_tprin2 "+++ Postprocessing answer:";
	    n := length jl
	 >>;
 	 result := for each j in jl join <<
	    if !*rlverbose then ioto_prin2 {" [",n:=n-1};
 	    w := cl_mk1EQR(cl_jF j,rl_qemkans(cl_jA j,svf));
	    if !*rlverbose then ioto_prin2 {"]"};
	    w
	 >>;
      >> else <<
	 f := cl_jF car jl;
	 if !*rlverbose then
	    ioto_tprin2 {"+++ Final simplification ... ",cl_atnum f," -> "};
	 f := rl_simpl(f,theo,-1);
	 if !*rlverbose then
 	    ioto_prin2t cl_atnum f;
	 if !*rlqefb and rvl then <<
	    if not rl_quap rl_op f then <<
	       if !*rlverbose then
 		  ioto_tprin2t "++++ No more quantifiers after simplification";
	       result := f
	    >> else <<
	       if !*rlverbose then
		  ioto_tprin2 {"++++ Entering fallback QE: "};
	       theo . result := rl_fbqe(f, theo)
	    >>
	 >> else
	    result := f;
	 result := cl_mk1EQR(result,nil);
      >>;
      return cl_mkER(theo,result)
   end;

asserted procedure cl_split(f: Formula): List4;
   % Split. [f] is a prenex formula. Returns a list of length 4 splitting [f]
   % into a quantifier list, a list of lists of quantified variables, the
   % matrix, and a flat list of all quantified variables.
   begin scalar q,op,ql,varl,varll,bvl;
      q := op := rl_op f;
      if not rl_quap q then
	 return {nil,nil,f,nil};
      repeat <<
   	 if op neq q then <<
      	    push(q,ql);
	    push(varl,varll);
      	    q := op;
      	    varl := nil
   	 >>;
	 push(rl_var f,varl);
	 push(rl_var f,bvl);
   	 f := rl_mat f
      >> until not rl_quap(op := rl_op f);
      push(q,ql);
      push(varl,varll);
      return {ql,varll,f,bvl}
   end;

asserted procedure cl_unsplit(ql: List, varll: List, f: Formula): Formula;
   begin scalar res,varl;
      res := f;
      for each q in ql do <<
	 varl := pop varll;
	 for each v in varl do
	    res := rl_mkq(q,v,res)
      >>;
      return res
   end;

asserted procedure cl_qe1!-iterate(ql: List, varll: List, f: Theory, theo: Theory, bvl: KernelL): List6;
   % Iteratively apply [cl_qeblock] to the quantifier blocks.
   begin scalar svrlidentify,svrlqeprecise,svrlqeaprecise,q,varl,svf,rvl,jl;
      svrlidentify := !*rlidentify;
      jl := {cl_mkJ(f,nil)};
      while null rvl and ql do <<
      	 f := cl_jF car jl;
      	 q := pop ql;
      	 varl := pop varll;
	 if !*rlqeans and null ql then
	    svf := f;
      	 if !*rlverbose then
      	    ioto_tprin2 {"---- ",(q . reverse varl)};
	 svrlqeprecise := !*rlqeprecise;
	 svrlqeaprecise := !*rlqeaprecise;
	 if ql then <<  % Should better be an argument of qeblock ...
	    off1 'rlqeprecise;
	    off1 'rlqeaprecise
	 >>;
      	 {rvl,jl,theo} := cl_qeblock(f,q,varl,theo,!*rlqeans and null ql,bvl);
	 if ql then <<
	    onoff('rlqeprecise,svrlqeprecise);
	    onoff('rlqeaprecise,svrlqeaprecise)
	 >>;
      >>;
      onoff('rlidentify,svrlidentify);
      return {ql,varll,q,rvl,jl,theo,svf}
   end;

asserted procedure cl_qe1!-requantify(ql: List, varll: List, q: Quantifier, rvl: KernelL, jl: JunctionL): JunctionL;
   % Requantify with the variables that could not be eliminated.
   begin scalar xx,xxv,scvarll,varl;
      if not rvl then
	 return jl;
      if !*rlverbose then
	 ioto_tprin2 "+++ Requantification ... ";
      jl := for each j in jl collect <<
	 xx := cl_jF j;
	 xxv := cl_fvarl xx;
	 for each v in rvl do
	    if v memq xxv then
	       xx := rl_mkq(q,v,xx);
	 scvarll := varll;
	 for each q in ql do <<
	    varl := car scvarll;
	    scvarll := cdr scvarll;
	    for each v in varl do
	       if v memq xxv then
		  xx := rl_mkq(q,v,xx)
	 >>;
	 cl_mkJ(xx,cl_jA j)
      >>;
      if !*rlverbose then
	 ioto_prin2t "done";
      return jl
   end;

asserted procedure cl_qeblock(f: QfFormula, q: Quantifier, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % Quantifier elimination for one block. The result contains the list of
   % variables for which elimination failed, the (possibly partial) elimination
   % result as a JunctionL, and the new theory.
   begin scalar rvl,jl;
      if q eq 'ex then
	 return cl_qeblock1(rl_simpl(f,theo,-1),varl,theo,ans,bvl);
      % [q eq 'all]
      {rvl,jl,theo} := cl_qeblock1(rl_simpl(rl_nnfnot f,theo,-1),varl,theo,ans,bvl);
      return {rvl, for each x in jl collect rl_nnfnot car x . cdr x, theo}
   end;

asserted procedure cl_qeblock1(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % Quantifier elimination for one block subroutine. The result contains the
   % list of variables for which elimination failed, the (possibly partial)
   % possibly negated elimination result as a JunctionL, and the new theory.
   if !*rlqeheu then
      cl_qeblock2(f,varl,theo,ans,bvl)
   else
      cl_qeblock3(f,varl,theo,ans,bvl);

asserted procedure cl_qeblock2(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   % Quantifier elimination for one block subroutine. The result contains the
   % list of variables for which elimination failed, the (possibly partial)
   % possibly negated elimination result as a JunctionL, and the new theory.
   % With [rlqeheu] on, this is in intermediate step checking for decision
   % problems and switching to DFS in the positive case.
   begin scalar !*rlqedfs,atl;
      atl := cl_atl1 f;
      !*rlqedfs := T;
      while atl do
	 if setdiff(rl_varlat car atl,varl) then
	    !*rlqedfs := atl := nil
	 else
	    atl := cdr atl;
      return cl_qeblock3(f,varl,theo,ans,bvl)
   end;

asserted procedure cl_qeblock3(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL): List3;
   begin scalar w; integer vlv, dpth;
      if !*rlverbose then <<
      	 if !*rlqedfs then <<
	    ioto_prin2 {" [DFS"};
	    if !*rlqedyn then
	       ioto_prin2 {" DYN"};
	    if !*rlqevbold then  <<
	       dpth := length varl;
	       vlv :=  dpth / 4;
	       ioto_prin2t {": depth ",dpth,", watching ",dpth - vlv,"]"}
	    >> else
	       ioto_prin2t {"]"}
      	 >> else
	    ioto_prin2t {" [BFS: depth ",dpth,"]"}
      >>;
      return cl_qeblock4(f,varl,theo,ans,bvl,dpth,vlv)
   end;

asserted procedure cl_qeblock4(f: QfFormula, varl: KernelL, theo: Theory, ans: Boolean, bvl: KernelL, dpth: Integer, vlv: Integer): List3;
   % Quantifier elimination for one block soubroutine. Arguments are as in
   % [cl_qeblock], where [q] has been dropped. Return value as well.
   begin scalar w,co,remvl,newj,cvl,coe,ww,cadf,cadcells,cadres,celleval,fvect,sf,!*rlcadans,falseFound;
      integer c,count,delc,oldcol,comax,comaxn,vl,vl2,subst;
      if !*rlqegsd then
 	 f := rl_gsd(f,theo);
      cvl := varl;
      co := co_new();
      if rl_op f eq 'or then
	    for each x in rl_argn f do
	    co := co_save(co,{ce_mk(cvl,x,nil,nil,nil,ic_currentfvect rlqeicdata!*)})
      else if !*rlqeinfcore then %%%%%%%MAX
	 % If we compute an infeasible core, the list of input
	 % constraints is added to the container.
	 co := co_save(co, {ce_mk(cvl, f, nil, nil, nil, ic_currentfvect rlqeicdata!*)})
      else
      	 co := co_save(co, {ce_mk(cvl, f, nil, nil, nil, nil)});
      while co_data co do <<
	 if !*rlverbose and !*rlqedfs and not !*rlqevbold then <<
	    ww := car co_stat co;
	    if comax = 0 or car ww < comax or
	       (car ww = comax and cdr ww < comaxn)
	    then <<
	       comax := car ww;
	       comaxn := cdr ww;
	       ioto_prin2 {"[",comax,":",comaxn,"] "}
	    >>
	 >>;
	 if !*rlqeidentify then on1 'rlidentify;
	 coe . co := co_get co;
	 % If we compute an infeasible core, then get the current
	 % formula vector from the container element.
	 if !*rlqeinfcore then %%%%%%%MAX
	    ic_setcurrentfvect(rlqeicdata!*, ce_fvect coe);
    	 cvl := ce_vl coe;
	 count := count + 1;
         if !*rlverbose then
   	    if !*rlqedfs then
 	       (if !*rlqevbold then <<
 	       	  if vlv = length cvl then
	       	     ioto_tprin2t {"-- crossing: ",dpth - vlv};
	       	  ioto_prin2 {"[",dpth - length cvl}
	       >>)
	    else <<
	       if c=0 then <<
	       	  ioto_tprin2t {"-- left: ",length cvl};
		  c := co_length(co) + 1
	       >>;
	       ioto_nterpri(length explode c + 4);
	       ioto_prin2 {"[",c};
	       c := c - 1
	    >>;
	 w . theo := cl_qevar(ce_f coe,ce_vl coe,ce_ans coe,theo,ans,bvl);
	 if car w then <<  % We have found a suitable variable.
	    w := cdr w;
	    if w then
	       if ce_vl car w eq 'break then <<
	       	  co := co_new();
	       	  newj := {cl_co2J car w}
	       >> else if cdr cvl then <<
		  if !*rlverbose then oldcol := co_length co;
	       	  co := co_save(co,w);
 		  if !*rlverbose then
		     delc := delc + oldcol + length w - co_length(co)
	       >> else
   		  for each x in w do newj := lto_insert(cl_co2J x,newj)
	 >> else <<
	    % There is no eliminable variable. Invalidate this entry, and save
	    % its variables for later requantification.
	    if !*rlqeinfcore then << %%%%%%%MAX
	       cadf := rl_ex(rl_smkn('and, vector2list (ce_fvect coe)),nil);
	       !*rlcadtrimtree := nil;
	       ic_resetcadcelllist rlqeicdata!*;
	       cadres := ofsf_cad(cadf, ofsf_cadporder cadf, theo);
	       if cdr cadres eq 'false then <<
	    	  fvect := ce_fvect coe;
	       	  for each cell in ic_cadcelllist rlqeicdata!* do <<
	       	     falseFound := nil;
	       	     celleval := mkvect upbv fvect;
	       	     for i := 0 : upbv fvect do <<
	       	     	sf := getv(fvect, i);
			vl:=cl_fvarl sf;
			subst:=T;
			vl2:=nil;
			for each sp in acell_getsp cell do 
	      		   for each vari in aex_fvarl cadr sp do
			      vl2:=vari.vl2;
			for each vari in vl do
			   if not (vari memq vl2) then subst:=nil;
			for each vari in vl2 do
			   if not (vari memq vl) then <<
			      vl:= vari . vl;
			      sf:= rl_smkn('and,{sf,{'geq,((((vari . 1) . 1)).1),nil}})
			   >>;
			if subst then 
			   cadres:=ofsf_trialeval(sf, acell_getsp cell)
			else cadres:='true;
	       	     	putv(celleval, i, cadres);
	       	     	if cadres eq 'false then <<
	       		    falseFound := t;
	       		    ic_addtofalsevect(rlqeicdata!*, i, 1)
	       		>>
	       	     >>;
	       	     if falseFound then <<
	    		for i:=0:upbv(celleval) do 
	    		   if not (getv(celleval,i) eq 'false) then putv(celleval,i,'true);
	    		ic_addcoverage(rlqeicdata!*, 1);
	       	     	ic_appendevtplist(rlqeicdata!*, celleval)
	    	     >> else <<
	    		!*rlqeicsimpl:=T;
	    		cl_filterlocalcore(fvect,cadr
	    		   rl_simpl(rl_smkn('and,vector2list celleval), nil,
	    		      -1));
	    		!*rlqeicsimpl:=nil
	       	     >>
	       	  >>
	       >>
	       else if cdr cadres eq 'true then <<
	       	  co := co_new();
	       	  newJ := {'true . nil}
	       >>
   	    >> else <<
	       if !*rlverbose then ioto_prin2 append("[Failed:" . cdr w,{"] "});
	       remvl := union(cvl,remvl);
	       newj := lto_insert(cl_co2J coe,newj);
	       if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then <<
		  ioto_prin2 "] ";
		  if !*rlqedfs and null cvl then ioto_prin2 ". "
	       >>
	    >>
	 >>
      >>;
      if !*rlverbose then ioto_prin2{"[DEL:",delc,"/",count,"]"};
      if ans then return {remvl, newj, theo};
      % I am building the formula here rather than later because one might want
      % to do some incremental simplification at some point.
      return {remvl,
	 {cl_mkJ(rl_smkn('or,for each x in newj collect car x),nil)}, theo}
   end;

asserted procedure cl_qevar(f: QfFormula, vl: KernelL, an: Answer, theo: Theory, ans: Boolean, bvl: KernelL): DottedPair;
   % Quantifier eliminate one variable. [f] is a quantifier-free formula; [vl]
   % is a non-empty list of variables; [an] is an answer; [theo] is a list of
   % atomic formulas; [ans] is Boolean. Returns a pair $a . p$. Either $a=[T]$
   % and $p$ is a pair of a list of container elements and a theory or $a=[nil]$
   % and $p$ is an error message. If there is a container element with ['break]
   % as varlist, this is the only one.
   begin scalar w,candvl,status; integer len;
      % Infeasible core computation is not yet implemented for the methods. %%%%%%%MAX
      if not !*rlqeinfcore and (w := cl_transform(f,vl,an,theo,ans,bvl)) then
       	 {f,vl,an,theo,ans,bvl} := w;
      if not !*rlqeinfcore and (w := cl_gauss(f,vl,an,theo,ans,bvl)) then
       	 return w;
      if not !*rlqeinfcore and (w := rl_specelim(f,vl,theo,ans,bvl)) neq 'failed then
       	 return w;
      % Elimination set method
      candvl := cl_varsel(f,vl,theo);
      if !*rlverbose and !*rlqevb and (not !*rlqedfs or !*rlqevbold)
 	 and (len := length candvl) > 1
      then
	 ioto_prin2 {"{",len,":"};
      status . w := cl_process!-candvl(f,vl,an,theo,ans,bvl,candvl);
      if !*rlverbose and !*rlqevb and (not !*rlqedfs or !*rlqevbold)
 	 and len>1
      then
	 ioto_prin2 {"}"};
      if status eq 'nonocc then
	 return (t . w) . theo;
      if status eq 'failed then
	 return (nil . w) . theo;
      if status eq 'local then
      	 return (t . car w) . cl_theo!*;
      if status eq 'elim then
	 return (t . car w) . cdr w;
      rederr {"cl_qevar: bad status",status}
   end;

asserted procedure cl_transform(f: QfFormula, vl: KernelL, an: Answer, theo: Theory, ans: Boolean, bvl: KernelL): List6;
   begin scalar w;
      for each v in vl do <<
	 w := rl_transform(v, f, vl, an, theo, ans, bvl);
	 if w then
 	    {f, vl, an, theo, ans, bvl} := w
      >>;
      return {f, vl, an, theo, ans, bvl}
   end;

asserted procedure cl_gauss(f: QfFormula, vl: KernelL, an: Answer, theo: Theory, ans: Boolean, bvl: KernelL): DottedPair;
   begin scalar w,ww;
      w := rl_trygauss(f,vl,theo,ans,bvl);
      if w neq 'failed then <<
	 theo := cdr w;
	 w := car w;
      	 if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then ioto_prin2 "g";
	 vl := delq(car w,vl);
	 ww := cl_esetsubst(f,car w,cdr w,vl,an,theo,ans,bvl);
	 if !*rlqelocal then
	    return (T . car ww) . cl_theo!*
	 else
	    return (T . car ww) . cdr ww
      >>
   end;

asserted procedure cl_varsel(f: QfFormula, vl: KernelL, theo: Theory): KernelL;
   begin scalar candvl; integer len;
      if null cdr vl then
      	 candvl := vl
      else if !*rlqevarsel then
      	 candvl := rl_varsel(f,vl,theo)
      else
	 candvl := {car vl};
      return candvl
   end;

% reduce local core by repeated simplification. unoptimized
procedure cl_filterlocalcore(fl,core);%%%%%%%MAX
   begin scalar f,l,ww,evect;
      evect:=ic_essentialvect(rlqeicdata!*);
      for i:=0:upbv(evect) do
	 if getv(evect,i) then 
	    f:=getv(fl,i).f;
      if f then f:=cl_simpl(rl_smkn('and,f),nil,-1);
      if not (f eq 'false) then <<
	 l:=length(core)+1;
	 ww:=copy(core);
	 while length(core) < l do <<
	    l:=length(core);
	    f:=nil;
	    while not (null core) do <<
	       f:=getv(fl,car core) . f;
	       core:=cdr core
	    >>;
	    f:=rl_smkn('and,reverse f);
	    !*rlqeicsimpl := t;
	    f := cl_simpl(f, nil, -1);
	    !*rlqeicsimpl := nil;
	    core:=list2vector(ww);
	    ww:=nil;
	    for each i in cadr f do ww:=getv(core,i) . ww;
	    core:=ww
	 >>;
	 while not (null core) do <<
	    putv(evect,car core,T);
	    core:=cdr core
	 >>
      >>
   end;

asserted procedure cl_process!-candvl(f: QfFormula, vl: KernelL, an: Answer, theo: Theory, ans: Boolean, bvl: KernelL, candvl: KernelL): TaggedContainerElementL;
   begin scalar
      w,ww,v,alp,hit,ww,status,newForm,sf,ww2,elimset,ww3,l,wwt,tpl;
      while candvl do <<
	 v := pop candvl;
      	 alp := cl_qeatal(f,v,theo,ans);
      	 if alp = '(nil . nil) then <<  % [v] does not occur in [f].
      	    if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
 	       ioto_prin2 "*";
      	    if !*rlqeinfcore then %%%%%%%MAX
	       w := {ce_mk(delq(v, vl), f, nil, nil, ans and cl_updans(v, 'arbitrary, nil, nil, an, ans), ic_currentfvect rlqeicdata!*)}
      	    else  
	       w := {ce_mk(delq(v,vl),f,nil,nil,ans and cl_updans(v,'arbitrary,nil,nil,an,ans),nil)};
	    status := 'nonocc;
	    candvl := nil
      	 >> else if car alp = 'failed then
	    (if null w then <<
	       w := cdr alp;
	       status := 'failed
	    >>)
	 else <<
	    if !*rlqeinfcore then << %%%%%%%MAX
   	       elimset := rl_elimset(v, alp);
	       while alp do
	       	  if caar alp eq 'equal1 then <<
		     if not ('(ofsf_qesubi (pinf)) member elimset) then
   			elimset:='(ofsf_qesubi (pinf)) . elimset;
		     if not ('(ofsf_qesubi (minf)) member elimset) then
   			elimset:='(ofsf_qesubi (minf)) . elimset;
	       	     alp:=nil
	       	  >> else alp:=cdr alp;
   	       ww := cl_esetvectsubst(f, ic_currentfvect rlqeicdata!*, v, elimset,
   		  delq(v, vl), an, ans, bvl);
	       ic_clearguardList(rlqeicdata!*);
	       if car ww then <<
	       	  if cadaar ww eq 'true then <<
		     candvl:=nil;
		     ww:={{ce_mk('break, 'true, nil, nil, car cddaar ww, nil)}}
	       	  >> else <<
   	       	     vl := cadr ww;
   	       	     ww := car ww;
   	       	     for each triple in ww do <<
		     	tpl := car triple;
   	       	     	newForm := cadr triple;
		     	an := caddr triple;
   	       	     	ic_setcurrentfvect(rlqeicdata!*, tpl);
   	       	     	if rl_op newForm eq 'or then
   	       	     	   for each subf in rl_argn newForm do
   		     	      ww2 := ce_mk(vl, subf, nil, nil, an, tpl) . ww2
   	       	     	else
			   if not (newForm eq 'false) then
   		     	      ww2 := ce_mk(vl, newForm, nil, nil, an, tpl) . ww2
   	       	     >>;
   	       	     ww := {ww2}
	       	  >>
	       >> else <<
		  ww:={nil}
	       >>
	    >> else <<
      	       if !*rlverbose and (not !*rlqedfs or !*rlqevbold) then
 	       	  ioto_prin2 "e";
      	       ww := cl_esetsubst(f,v,rl_elimset(v,alp),delq(v,vl),an,
	       	  theo,ans,bvl)
	    >>;
	    if !*rlqelocal then <<
	       candvl := nil;
	       w := ww;
	       status := 'local
	    >> else if rl_betterp(ww,w) then <<
	       w := ww;
	       status := 'elim
	    >>
      	 >>
      >>;
      return status . w
   end;

%%%%%%%MAX
asserted procedure cl_esetvectsubst(form, fvect: Vector, v: Kernel, eset:
   List, vl: KernelL, an: List, ans: Boolean, bvl:
      KernelL): DottedPair;
   % Elimination Set Vector Substitution. For infeasible core
   % computation only. [fvect] is a vector of quantifier-free formula;
   % [v] is a kernel; [eset] is an elimination set; [an] is an answer;
   % [ans] is Boolean. Returns a pair $l . nvl$, where $nvl$ is the
   % new variable list and $l$ is a list of Vectors, each representing
   % an elimination term. A vector contains the elimination results
   % for the specific elimination term when substituted into the
   % formulas of the formula vector. Guards are only added to the
   % formulas from which the elimination term emerged.
   begin scalar a, d, u, elimres, junct, w, f, u2, sf, resvect,res,falseFound;
      while eset do <<
	 a . d := pop eset;
	 while d do <<
	    u := pop d;
	    if cdr u then <<
	      f := assoc(u, ic_guardList rlqeicdata!*);
	      if f then 
	    	 f := cadr f;
	      u2 := 'true . cdr u
	    >> else u2 := u;
	    resvect := mkvect upbv fvect;
	    falseFound:=nil;
	    for i := 0 : upbv fvect do <<
	       sf := getv(fvect, i);
	       if f and cl_subformulap(sf, f) then <<
	       	 w := apply(a, bvl . nil . sf . v . u);
	       	 f := nil
	       >> else 
		  w := apply(a, bvl . nil . sf . v . u2);
	       elimres := rl_simpl(cdr w, nil, -1);
	       if !*rlqegsd then
		  elimres := rl_gsd(elimres, nil);
	       if elimres eq 'false then <<
		  if not falseFound then <<
		     ic_addcoverage(rlqeicdata!*, 1);
		     falseFound := t
	       	  >>;
		  ic_addtofalsevect(rlqeicdata!*, i, 1)
	       >>;
	       putv(resvect, i, elimres)
	    >>;
	    if falseFound then ic_appendevtplist(rlqeicdata!*, resvect);
	    !*rlqeicsimpl := t;
	    res := cl_simpl(rl_smkn('and, vector2list resvect), nil, -1);
	    !*rlqeicsimpl := nil;
	    if car res eq 'false then <<
	       if not falseFound then cl_filterlocalcore(resvect,cadr res);
	    >> else <<
	       res:=car res;
	       if res eq 'true then <<
	       	  eset:=d:=nil;
		  an:=cl_updans(v,a,u,form,an,ans);
		  for each vv in vl do
		     an := cl_updans(vv,'arbitrary,nil,nil,an,ans);
	       	  junct:={{resvect,'true,an}};
	       >> else junct := {resvect,res,cl_updans(v,a,u,form,an,ans)}
   		  . junct
	    >>
	 >>
      >>;
      return junct . {vl}
   end;

%%%%%%%MAX
procedure cl_subformulap(sf, f);
   begin scalar w;
      if not (sf eq 'true) then <<
      	 if (car sf eq 'or) or (car sf eq 'and) then  <<
	    for each ssf in rl_argn sf do
	       if not w then 
 		  w := cl_subformulap(ssf, f);
	    return w
      	 >> else <<
      	    w := car ofsf_at2ir(sf, -1);
      	    return (f = sf)
      	 >>
      >>;
      return nil
   end;

asserted procedure cl_esetsubst(f: QfFormula, v: Kernel, eset: List, vl: KernelL, an: List, theo: Theory, ans: Boolean, bvl: KernelL): DottedPair;
   % Elimination set substitution. [f] is a quantifier-free formula; [v] is a
   % kernel; [eset] is an elimination set; [an] is an answer; [theo] is the
   % current theory; [ans] is Boolean. Returns a pair $l . \Theta$, where
   % $\Theta$ is the new theory and $l$ is a list of container elements. If
   % there is a container element with ['break] as varlist, this is the only
   % one.
   begin scalar a,d,u,elimres,junct,bvl,w;
      while eset do <<
	 a . d := pop eset;
	 while d do <<
	    u := pop d;
	    w := apply(a,bvl . theo . f . v . u);
	    theo := union(theo,car w);
	    elimres := rl_simpl(cdr w,theo,-1);
	    if !*rlqegsd then
	       elimres := rl_gsd(elimres,theo);
	    if elimres eq 'true then <<
	       an := cl_updans(v,a,u,f,an,ans);
	       for each vv in vl do
		  an := cl_updans(vv,'arbitrary,nil,nil,an,ans);
	       junct := {ce_mk('break,elimres,nil,nil,an,nil)};
	       eset := d := nil
	    >> else if elimres neq 'false then
	       if rl_op elimres eq 'or then
		  for each subf in rl_argn elimres do
		     junct := ce_mk(vl,subf,nil,nil,cl_updans(v,a,u,f,an,ans),nil) . junct
	       else
		  junct :=
		     ce_mk(vl,elimres,nil,nil,cl_updans(v,a,u,f,an,ans),nil)
			. junct;
      	 >>
      >>;
      return junct . theo
   end;

procedure cl_updans(v,a,u,f,an,ans);
   if ans then {v, a, u, if !*rlqestdans then f} . an;

procedure cl_qeatal(f,v,theo,ans);
   % Quantifier elimination atomic formula list. [f] is a formula; [v]
   % is a variable; [theo] is the current theory, [ans] is Boolean.
   % Returns an ALP.
   cl_qeatal1(f,v,theo,T,ans);

switch rlataltheo;
on1 'rlataltheo;

procedure cl_qeatal1(f,v,theo,flg,ans);
   % Quantifier elimination atomic formula list. [f] is aformula; [v] is a
   % variable; [theo] is the current theory, [flg] and [ans] are Boolean.
   % Returns an ALP. If [flg] is non-[nil] [f] has to be considered negated.
   begin scalar op,w,ww;
      op := rl_op f;
      w := if rl_tvalp op then
	 {nil . nil}
      else if op eq 'not then
      	 {cl_qeatal1(rl_arg1 f,v,theo,not flg,ans)}
      else if op eq 'and then <<
	 if !*rlataltheo then
	    for each subf in rl_argn f do
	       if cl_atfp subf and not memq(v, rl_varlat subf) then
	       	  theo := lto_insert(subf, theo);
      	 for each subf in rl_argn f collect
      	    cl_qeatal1(subf,v,theo,flg,ans)
      >> else if op eq 'or then <<
	 if !*rlataltheo then
	    for each subf in rl_argn f do
	       if cl_atfp subf and not memq(v, rl_varlat subf) then
	       	  theo := lto_insert(rl_negateat subf, theo);
      	 for each subf in rl_argn f collect
      	    cl_qeatal1(subf,v,theo,flg,ans)
      >> else if op eq 'impl then
      	 {cl_qeatal1(rl_arg2l f,v,theo,not flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,flg,ans)}
      else if op eq 'repl then
	 {cl_qeatal1(rl_arg2l f,v,theo,flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,not flg,ans)}
      else if op eq 'equiv then
	 {cl_qeatal1(rl_arg2l f,v,theo,not flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,flg,ans),
            cl_qeatal1(rl_arg2l f,v,theo,flg,ans),
	    cl_qeatal1(rl_arg2r f,v,theo,not flg,ans)}
      else if rl_quap op then
	 rederr "argument formula not prenex"
      else  % [f] is an atomic formula.
      	 if !*rlqeinfcore then <<%%%%%%%MAX
	    ww:=rl_translat(f,v,theo,flg,ans);
	    if not (car ww eq 'failed) then <<
	       for each a in car ww do <<
	       	  for each g in cdr a do <<
		     ic_appendguardList(rlqeicdata!*,g.{f});
		  >>;
	       >>;
	    >>;
	    {ww}
	 >> else
   	 {rl_translat(f,v,theo,flg,ans)};
      if (ww := atsoc('failed,w)) then return ww;
      return cl_alpunion w
   end;

procedure cl_alpunion(pl);
   % Alp union. [pl] is a list of ALP's. Returns the union of all ALP's
   % in [pl].
   begin scalar uall,pall;
      for each pair in pl do <<
	 uall := car pair . uall;
	 pall := cdr pair . pall
      >>;
      return lto_alunion(uall) . lto_almerge(pall,'plus2)
   end;

procedure cl_betterp(new,old);
   begin integer atn;
      atn := cl_betterp!-count car new;
      if !*rlverbose and !*rlqevb and (not !*rlqedfs or !*rlqevbold) then
 	 ioto_prin2 {"(",atn,")"};
      return null old or atn < cl_betterp!-count car old
   end;

procedure cl_betterp!-count(coell);
   % [coell] is a list of container elements.
   for each x in coell sum rl_atnum ce_f x;

procedure cl_qeipo(f,theo);
   % Quantifier elimination in position. [f] is a positive formula;
   % [theo] is a THEORY. Returns a quantifier-free formula equivalent to
   % [f] wrt. [theo] by recursively making [f] anti-prenex and
   % eliminating the quantifiers.
   begin scalar w,!*rlqeans;
      repeat <<
	 w := cl_qeipo1(cl_apnf rl_simpl(f,theo,-1),theo);
	 f := cdr w
      >> until not car w;
      return f
   end;

procedure cl_qeipo1(f,theo);
   % Quantifier eliminate in position subroutine.
   begin scalar op,nf,a,argl,ntheo;
      op := rl_op f;
      if rl_quap op then <<
	 for each subf in theo do
	    if not(rl_var f memq rl_varlat subf) then
 	       ntheo := subf . ntheo;
	 nf := cl_qeipo1(rl_mat f,ntheo);
	 if car nf then
	    return T . rl_mkq(op,rl_var f,cdr nf);
	 a := rl_qe(rl_mkq(op,rl_var f,cdr nf),ntheo);
	 if rl_quap rl_op a then
	    rederr "cl_qeipo1: Could not eliminate quantifier";
	 return T . a
      >>;
      if rl_junctp op then <<
      	 argl := rl_argn f;
	 if op eq 'and then
	    for each subf in argl do
	       if cl_atfp subf then theo := subf . theo;
	 if op eq 'or then
	    for each subf in argl do
	       if cl_atfp subf then theo := rl_negateat subf . theo;
	 while argl do <<
	    a := cl_qeipo1(car argl,theo);
	    nf := cdr a . nf;
	    argl := cdr argl;
	    if car a then <<
	       nf := nconc(reversip nf,argl);
	       argl := nil
	    >>
	 >>;
	 return
	    if car a then
	       T . rl_mkn(op,nf)
	    else
 	       nil . rl_mkn(op,reversip nf)
      >>;
      % f is atomic.
      return nil . f
   end;

procedure cl_qews(f,theo);
   % Quantifier elimination with selection. [f] is a formula; [theo] is
   % a THEORY. Returns a quantifier-free formula equivalent to [f] wrt.
   % [theo] by selecting a quantifier from the innermost block, moving
   % it inside as far as possible and eliminating it. Accesses the
   % switch [rlqepnf]; if [rlqepnf] is on, then [f] has to be prenex.
   begin scalar q,op,ql,varl,varll,!*rlqeans;
      if !*rlqepnf then
	 f := rl_pnf f;
      f := rl_simpl(f,theo,-1);
      if not rl_quap rl_op f then
	 return f;
      {ql,varll,f} := cl_split f;  % drop bvl
      while ql do <<
	 q := pop ql;
	 varl := pop varll;
	 f := if q eq 'ex then
	    cl_qews1(varl,f,theo)
	 else
	    rl_nnfnot cl_qews1(varl,rl_nnfnot f,theo)
      >>;
      return f
   end;

procedure cl_qews1(varl,mtx,theo);
   % Quantifier eliminate with selection subroutine. [varl] is a list of
   % variables; [mtx] is a quantifier-free formula; [theo] is a list of
   % atomic formulas. Returns a formula, where all existentially
   % quantified variables from [varl] are eliminated.
   begin scalar v,w;
      while varl do <<
	 w := rl_trygauss(mtx,varl,theo,nil,nil);
	 if w eq 'failed then <<
	    v := rl_varsel(mtx,varl,theo);
 	    mtx := cl_qeipo(rl_mkq('ex,v,mtx),theo)
	 >> else <<
	    v := caar w;
	    mtx := rl_qe(rl_mkq('ex,v,mtx),theo)
	 >>;
	 varl := delete(v,varl)
      >>;
      return mtx
   end;

%DS
% <GRV> ::= ['failed] | (<KERNEL> . <ELIMINATION SET>) . <THEORY>
% <IGRV> ::= (['failed] . [nil]) |
%    ['gignore] . ([nil] . <THEORY SUPPLEMENT>) |
%    <GAUSS TYPE IDENTIFICATION> . (<ELIMINATION SET> . <THEORY SUPPLEMENT>)
% <GAUSS TYPE IDENTIFICATION> ::= ("verbose output", <DATA>,...)

procedure cl_trygauss(f,vl,theo,ans,bvl);
   % Try Gauss elimination. [f] is a quantifier-free formula; [vl] is a
   % list of variables existentially quantified in the current block;
   % [theo] a THEORY; [ans] is bool; [bvl] is a list of variables.
   % Returns a GRV, where no assumption on the variables in [bvl] are
   % made.
   begin scalar w;
      w := cl_trygauss1(f,vl,theo,ans,bvl);
      if w eq 'failed then return 'failed;
      return car w . union(cdr w,theo)
   end;

switch rlgaussdebug;

procedure cl_trygauss1(f,vl,theo,ans,bvl);
   % Try deep Gauss elimination. [f] is a quantifier-free formula; [vl] is
   % the current existential variable block; [theo] is a list of
   % atomic formulas, the current theory; [ans] is Boolean; [bvl] is a
   % list of variables that are considered non-parametric. Returns
   % a GRV.
   begin scalar w,v,csol,ev;
      csol := '(failed . nil);
      if null !*rlqevarsel then
	 vl := {car vl};
      while vl do <<
	 v := pop vl;
	 w := cl_trygaussvar(f,v,theo,ans,bvl);
	 if car w neq 'gignore and rl_bettergaussp(w,csol) then <<
	    csol := w;
	    ev := v;
	    if rl_bestgaussp csol then
	       vl := nil
	 >>
      >>;
      if car csol eq 'failed then
 	 return 'failed;
      if !*rlverbose and !*rlqevb and (not !*rlqedfs or !*rlqevbold) then
	 ioto_prin2 caar csol;
      if !*rlgaussdebug then
	 ioto_tprin2t {"DEBUG: cl_trygauss1 eliminates ", ev,
 	    " with verbose output ", caar csol};
      return (ev . cadr csol) . cddr csol
   end;

procedure cl_trygaussvar(f,v,theo,ans,bvl);
   % Try Gauss elimination wrt. one variable. [f] is a formula; [v]
   % is a kernel; [theo] is a theory; [ans] is Boolean; [bvl] is a
   % list of kernels. Returns a IGRV.
   <<
      if cl_atfp f then
	 rl_qefsolset(f,v,theo,ans,bvl)
      else if rl_op f eq 'and then
	 cl_gaussand(rl_argn f,v,theo,ans,bvl)
      else if rl_op f eq 'or then
	 cl_gaussor(rl_argn f,v,theo,ans,bvl)
      else % TODO: Gauss elimination for formulas with extended Boolean op's
	 '(failed . nil)
   >>;

switch rlgausstheo;
on1 'rlgausstheo;

procedure cl_gaussand(fl,v,theo,ans,bvl);
   begin scalar w, curr;
      if !*rlgausstheo then
      	 for each subf in fl do
	    if cl_atfp subf and not memq(v,rl_varlat subf) then
	       theo := lto_insert(subf, theo);
      curr := cl_trygaussvar(car fl,v,theo,ans,bvl);
      fl := cdr fl;
      while fl and not(rl_bestgaussp curr) do <<
      	 w := cl_trygaussvar(car fl,v,theo,ans,bvl);
	 curr := cl_gaussintersection(w,curr);
	 fl := cdr fl
      >>;
      return curr
   end;

procedure cl_gaussor(fl,v,theo,ans,bvl);
   begin scalar w,curr;
      if !*rlgausstheo then
      	 for each subf in fl do
	    if cl_atfp subf and not memq(v,rl_varlat subf) then
	       theo := lto_insert(rl_negateat subf, theo);
      curr := cl_trygaussvar(car fl,v,theo,ans,bvl);
      fl := cdr fl;
      while fl and (car curr neq 'failed) do <<
	 w := cl_trygaussvar(car fl,v,theo,ans,bvl);
	 fl := cdr fl;
	 curr := cl_gaussunion(curr,w)
      >>;
      return curr
   end;

procedure cl_gaussunion(grv1,grv2);
   begin scalar tag,eset,theo;
      if car grv1 eq 'failed or car grv2 eq 'failed then
	 return '(failed . nil);
      tag := if car grv1 eq 'gignore then
	 car grv2
      else if car grv2 eq 'gignore then
	 car grv1
      else if rl_bettergaussp(grv1,grv2) then
	 car grv2
      else
	 car grv1;
      eset := rl_esetunion(cadr grv1,cadr grv2);
      theo := union(cddr grv1,cddr grv2);
      return tag . ( eset . theo )
   end;

procedure cl_gaussintersection(grv1,grv2);
   if car grv1 eq 'gignore and car grv2 eq 'gignore then
      if length cddr grv1 < length cddr grv2 then grv1 else grv2
   else if car grv1 eq 'gignore then grv2
   else if car grv2 eq 'gignore then grv1
   else if rl_bettergaussp(grv1,grv2) then grv1 else grv2;

procedure cl_specelim(f,vl,theo,ans,bvl);
   % Special elimination. [f] is a quantifier-free formula; [vl] is a
   % list of variables existentially quantified in the current block;
   % [theo] a THEORY; [ans] is bool; [bvl] is a list of variables.
   % Returns a GRV.
   'failed;

procedure cl_fbqe(f);
   % Fallback quantifier elimination. [f] is a formula. returns a
   % formula equivalent to [f].
   <<
      if !*rlverbose then
	 ioto_tprin2t "+++ no fallback QE specified";
      f
   >>;

endmodule;  % [clqe]

end;  % of file
