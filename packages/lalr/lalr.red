% Parser generator using LALR techniques as used by yacc etc

module lalr;

% Author: Arthur Norman

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
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

% $Id$

% The module genparser contains code that can create LALR parsing
% tables, while yyparse has a hand-written lexer suitable for use with
% Rlisp syntax together with the skeleton of an LR parser which can use
% the tables that are generated by genparser.

create!-package('(lalr genparser yylex yyparse), nil);

global '(lex_char yylval last64 last64p which_line if_depth);
global '(next_lex_code);
global '(dot_char rpar_char rsquare_char);

global '(!*lalr_verbose);

global '(goto_index goto_old_state goto_new_state);
global '(action_index, action_terminal action_result);
global '(action_first_error action_error_messages);
global '(action_fn action_A action_n);

global '(terminals non_terminals symbols goto_cache action_map);
fluid '(renamings);

!*lalr_verbose := t;      % How much will the parser-generator print?
                          % While I am debugging I want it noisy!

!#if (memq 'psl lispsystem!*)

% CSL has special vectors that hold just 8-bit integers (it also has ones
% for 16-bit integers) and use of those will decrease the amount of
% memory consumed by the parser tables. However if PSL does not have these
% it does not matter much since I can just use ordinary Lisp vectors...

inline procedure mkvect8 n; mkvect n;
inline procedure putv8(v, n, x); putv(v, n, x);
inline procedure getv8(v, n); getv(v, n);

inline procedure mkvect16 n; mkvect n;
inline procedure putv16(v, n, x); putv(v, n, x);
inline procedure getv16(v, n); getv(v, n);


% Other CSL-isms that need simulation in PSL.

global '(uc!-charassoc!*);

uc!-charassoc!* :=
         '((!a   !A) (!b . !B) (!c . !C) (!d . !D) (!e . !E) (!f . !F)
           (!g . !G) (!h . !H) (!i . !I) (!j . !J) (!k . !K) (!l . !L)
           (!m . !M) (!n . !N) (!o . !O) (!p . !P) (!q . !Q) (!r . !R)
           (!s . !S) (!t . !T) (!u . !U) (!v . !V) (!w . !W) (!x . !X)
           (!y . !Y) (!z . !Z));

symbolic procedure explode2uc u;
  for each c in explode2 u collect
    ((if x then cdr x else c) where x = atsoc(c, uc!-charassoc!*));

% If PSL does not have built-in hash tables I will model the
% effect that they provide using association lists. To arrange that
% a "table" can be updated in place I will have a list of length 1
% whose sole element is the association list. This code just uses
% EQUAL tests for hash table membership.

symbolic procedure mkhash(size, equality_mode, expandion_factor);
   list nil;

symbolic procedure puthash(key, table, value);
  begin
    scalar w;
    w := assoc(key, car table);
    if w then rplacd(w, value)
    else rplaca(table, (key . value) . car table);
    return value
  end;

symbolic procedure gethash(key, table);
  begin
    scalar w;
    w := assoc(key, car table);
    if w then return cdr w
    else return nil
  end;

symbolic procedure hashcontents table;
  car table;

symbolic procedure ttab n;
  tab n;

load gsort; % Not loaded by default and not autoloaded on demand.

symbolic procedure sort(ll, ff);
  gsort(ll, ff);


% In PSL the "orderp" function seems only to be willing to
% accept symbols...

symbolic procedure gorderp(a, b);
  if idp a and idp b then orderp(a, b)
  else if idp a then t
  else if idp b then nil
  else if stringp a and stringp b then gorderp(explode a, explode b)
  else if stringp a then t
  else if stringp b then nil
  else if numberp a and numberp b then gorderp(explode a, explode b)
  else if numberp a then t
  else if numberp b then nil
  else if atom a and atom b then gorderp(explode a, explode b)
  else if atom a then t
  else if atom b then nil
  else if car a = car b then gorderp(cdr a, cdr b)
  else gorderp(car a, car b);

!#else

symbolic procedure gorderp(a, b);
  orderp(a, b);

!#endif


endmodule;

end;

