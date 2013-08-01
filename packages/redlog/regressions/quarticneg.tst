% Testing rlcad
% Condition on quartic polynomial being positive semidefinite.

rlset reals;

quartic := all(x,x**4+p*x**2+q*x+r>=0)$
quarticneg := not quartic$

on rlcadfulldimonly;
rlcad quarticneg;
off rlcadfulldimonly;

end;
