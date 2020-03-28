% Camassa-Holm equation: cosymmetries
% 2016-08-13
% Raffaele Vitolo

load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x}$
dep_var:={u}$
odd_var:={p}$
deg_indep_var:={-2,-1}$
deg_dep_var:={1}$
deg_odd_var:={1}$
total_order:=8$
principal_der:={u_3x}$
de:={(alpha*(u_t + 3*u*u_x) - u_t2x - 2*u_x*u_2x)/u}$

% names for output of the state of cde and results of computations
statename:="ch_csy1_state.red"$
resname:="ch_csy1_res.red"$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
  {principal_der,de,principal_odd,de_odd})$

% Solving the determining equations through dimensional analysis
cde_grading(deg_indep_var,deg_dep_var,deg_odd_var)$

% Saving cde state in a file
save_cde_state(statename)$

% Defining the superfunction corresponding with the adjoint
% linearization operator
mk_superfun(lch_star_sf,1,1);
lch_star_sf(1):= - alpha*p_t - 3*alpha*p_x*u + p_2x*u_x + p_3x*u
  + p_t2x + p_x*u_2x$
conv_superfun2cdiff(lch_star_sf,lch_star);

% Initialize a counter for the vector of arbitrary constants
% and vectors of equations and constants
ctel:=0;
operator c,equ;

% List of variables ordered by gradings
l_grad_mon:=der_deg_ordering(0,all_parametric_der)$
% List of graded monomials of scale degree <= 6
gradmon:=graded_mon(1,6,l_grad_mon)$
gradmon:=part(gradmon,2):=alpha . part(gradmon,2)$
gradmon:={1} . gradmon$
ansatz:=for each el in gradmon join el$

phi:=(for each el in ansatz sum (c(ctel:=ctel+1)*el))$

% This is the equation \tilde\ell_K(sym)=0, where K=0 is KdV equation,
% \tilde\ell stands for lnearization lifted on the cotangent covering
% and sym is the generating function. From now on all equations
% are arranged in a single vector whose name is `equ'.

equ 1:=num lch_star(1,1,phi)$

% This is the list of variables, to be passed to the equation solver.

vars:=append(indep_var,all_parametric_der);

% This is the number of initial equation(s)

tel:=1;

% We need to solve irrespectively of the values of alpha
off coefficient_check;

% This command initialize the equation solver.
% It passes the equation(s) togeher with their number `tel',
% the constants'vector `c', its length `ctel',
% an arbitrary constant `f' that may appear in computations.

initialize_equations(equ,tel,{},{c,ctel,0},{f,0,0});

% Run the procedures splitext and splitvars in order to obtain equations on
% coefficients of each monomial.

tel:=splitext_opequ(equ,1,1);

tel2:=splitvars_opequ(equ,2,tel,vars);

% Next command tells the solver the total number of equations obtained
% after running splitvars.

put_equations_used tel2;

% This command solves the equations for the coefficients.
% Note that we have to skip the initial equations!

for i:=tel+1:tel2 do integrate_equation i;

% Here we write results of the computation in a file.

off nat$
off echo$
out <<resname>>$
write phi:=phi;
write ";end;";
shut <<resname>>$
on echo$
on nat$

;end;
