// fns1.cpp                           Copyright (C) 1989-2015 Codemist Ltd

//
// Basic functions part 1.
//

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
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
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

// $Id$


#include "headers.h"

#ifdef WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

/*!!! csl
*/

/*****************************************************************************/
//      Some basic functions
/*****************************************************************************/

LispObject integerp(LispObject p)
{   LispObject nil = C_nil;
    int tag = ((int)p) & TAG_BITS;
    if (tag == TAG_FIXNUM) return lisp_true;
    else if (tag == TAG_NUMBERS)
    {   Header h = *(Header *)((char *)p - TAG_NUMBERS);
        if (type_of_header(h) == TYPE_BIGNUM) return lisp_true;
        else return nil;
    }
    else return nil;
}

/*****************************************************************************/
//      Storage allocation.
/*****************************************************************************/


LispObject cons(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal cons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject cons_no_gc(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

//
// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.
//

LispObject cons_gc_test(LispObject p)
{   if ((char *)fringe <= (char *)heaplimit)
        return reclaim(p, "cons gc test", GC_CONS, 0);
    else return p;
}

LispObject ncons(LispObject a)
{   LispObject nil = C_nil;
    LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal ncons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2(LispObject a, LispObject b)
{
// Note that building two cons cells at once saves some overhead here
    LispObject nil = C_nil;
    LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = d;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject nil = C_nil;
    LispObject r = (LispObject)((char *)fringe - 4*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 3*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r +3*sizeof(Cons_Cell)) = d;
    qcdr((char *)r + 3*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list4", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}



LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal acons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject nil = C_nil;
    LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

/*****************************************************************************/
/*****************************************************************************/
//**              Lisp-callable versions of all the above                  **
/*****************************************************************************/
/*****************************************************************************/

//
// The set of car/cdr combinations here seem pretty dull, but they
// are fairly important for performance...
//

/*! fns [car] \item [{\ttfamily car} {\itshape expr}] \index{{\ttfamily car} {\itshape expr}} ~\newline
 * For a non-empty list the function {\ttfamily car} will return the
 * first element. For a dotted pair (created using {\ttfamily cons})
 * it extracts the first component. This is the fundamental low-level
 * data structure access function in Lisp. See {\ttfamily cdr} for the
 * function that returns the tail or a list or the second component of
 * a dotted pair. In CSL any attempt to take {\ttfamily car} of an atom
 * should be detected and will be treated as an error. If CSL had been
 * compiled in Common Lisp mode (which is now not probable) a special
 * exemption would apply and {\ttfamily car} and {\ttfamily cdr} of the
 * empty lisp {\ttfamily nil} would be {\ttfamily nil}.
 */

LispObject Lcar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

//
// (car* a) = (car a) if a is non-atomic, but just a otherwise.
//

/*! fns [car*] \item[{\ttfamily car!*} {\itshape expr}] \index{{\ttfamily car"!*} {\itshape expr}} ~\newline
 * This function behaves like {\ttfamily car} except that if its argument
 * is atomic then the argument is returned unaltered rather than that case
 * being treated as an error.
 */

LispObject Lcar_star(LispObject, LispObject a)
{   if (!car_legal(a)) return onevalue(a);
    else return onevalue(qcar(a));
}

/*! fns [cdr] \item [{\ttfamily cdr} {\itshape expr}] \index{{\ttfamily cdr} {\itshape expr}} ~\newline
 * See {\ttfamily car}.
 */

LispObject Lcdr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [caar] \item [{\ttfamily caar \ldots cddddr} {\itshape expr}] \index{{\ttfamily caar \ldots cddddr} {\itshape expr}} ~\newline
 * Names that start with {\ttfamily c}, then have a sequence of
 * {\ttfamily a} or {\ttfamily d}s and finally {\ttfamily r} provide
 * shorthand functions for chains of uses of {\ttfamily car} and
 * {\ttfamily cdr}. Thus for instance
 * {\ttfamily (cadar x)} has the same meaning as
 * {\ttfamily (car (cdr (car x)))}.
 */

LispObject Lcaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cadr] \item [{\ttfamily  cadr} {\itshape expr}] \index{{\ttfamily  cadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar} and {\ttfamily second}.
 */

LispObject Lcadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cdar] \item[{\ttfamily cdar} {\itshape expr}] \index{{\ttfamily cdar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cddr] \item[{\ttfamily cddr} {\itshape expr}] \index{{\ttfamily cddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [caaar] \item[{\ttfamily caaar} {\itshape expr}] \index{{\ttfamily caaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [caadr] \item[{\ttfamily caadr} {\itshape expr}] \index{{\ttfamily caadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cadar] \item[{\ttfamily cadar} {\itshape expr}] \index{{\ttfamily cadar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcadar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [caddr] \item[{\ttfamily caddr} {\itshape expr}] \index{{\ttfamily caddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar} and {\ttfamily third}.
 */

LispObject Lcaddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cdaar] \item[{\ttfamily cdaar} {\itshape expr}] \index{{\ttfamily cdaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cdadr] \item[{\ttfamily cdadr} {\itshape expr}] \index{{\ttfamily cdadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cddar] \item[{\ttfamily cddar} {\itshape expr}] \index{{\ttfamily cddar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cdddr] \item[{\ttfamily cdddr} {\itshape expr}] \index{{\ttfamily cdddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [caaaar] \item[{\ttfamily caaaar} {\itshape expr}] \index{{\ttfamily caaaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [caaadr] \item[{\ttfamily caaadr} {\itshape expr}] \index{{\ttfamily caaadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [caadar] \item[{\ttfamily caadar} {\itshape expr}] \index{{\ttfamily caadar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaadar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [caaddr] \item[{\ttfamily caaddr} {\itshape expr}] \index{{\ttfamily caaddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaaddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cadaar] \item[{\ttfamily cadaar} {\itshape expr}] \index{{\ttfamily cadaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcadaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cadadr] \item[{\ttfamily cadadr} {\itshape expr}] \index{{\ttfamily cadadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcadadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [caddar] \item[{\ttfamily caddar} {\itshape expr}] \index{{\ttfamily caddar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcaddar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cadddr] \item[{\ttfamily cadddr} {\itshape expr}] \index{{\ttfamily cadddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar} and {\ttfamily fourth}.
 */

LispObject Lcadddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else return onevalue(qcar(a));
}

/*! fns [cdaaar] \item[{\ttfamily cdaaar} {\itshape expr}] \index{{\ttfamily cdaaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cdaadr] \item[{\ttfamily cdaadr} {\itshape expr}] \index{{\ttfamily cdaadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cdadar] \item[{\ttfamily cdadar} {\itshape expr}] \index{{\ttfamily cdadar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdadar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cdaddr] \item[{\ttfamily cdaddr} {\itshape expr}] \index{{\ttfamily cdaddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdaddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cddaar] \item[{\ttfamily cddaar} {\itshape expr}] \index{{\ttfamily cddaar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddaar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cddadr] \item[{\ttfamily cddadr} {\itshape expr}] \index{{\ttfamily cddadr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddadr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cdddar] \item[{\ttfamily cdddar} {\itshape expr}] \index{{\ttfamily cdddar} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcdddar(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_car, a);
    else a = qcar(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [cddddr] \item[{\ttfamily cddddr} {\itshape expr}] \index{{\ttfamily cddddr} {\itshape expr}} ~\newline
 * see {\ttfamily caar}.
 */

LispObject Lcddddr(LispObject, LispObject a)
{   if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else a = qcdr(a);
    if (!car_legal(a)) return error(1, err_bad_cdr, a);
    else return onevalue(qcdr(a));
}

/*! fns [rplaca] \item[{\ttfamily rplaca} {\itshape expr}] \index{{\ttfamily rplaca} {\itshape expr}} ~\newline
 * This is a destructive function in that it alters the data structure
 * that it is given as its first argument by updating its {\ttfamily car}
 * component. The result is the updated object. See {\ttfamily rplacd}
 * for the corresponding function for updating the {\ttfamily cdr} component.
 */

LispObject Lrplaca(LispObject,
                   LispObject a, LispObject b)
{   if (!consp(a)) return error(1, err_bad_rplac, a);
    qcar(a) = b;
    return onevalue(a);
}

/*! fns [rplacd] \item [{\ttfamily rplacd} {\itshape expr}] \index{{\ttfamily rplacd} {\itshape expr}} ~\newline
 * See {\ttfamily rplaca}
 */

LispObject Lrplacd(LispObject,
                   LispObject a, LispObject b)
{   if (!consp(a)) return error(1, err_bad_rplac, a);
    qcdr(a) = b;
    return onevalue(a);
}

LispObject Lsymbolp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(symbolp(a)));
}

LispObject Latom(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(!consp(a)));
}

LispObject Lconsp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(consp(a)));
}

LispObject Lconstantp(LispObject nil, LispObject a)
//
// This version is as required for Standard Lisp - it is inadequate
// for Common Lisp.
//
{
//
// Standard Lisp requires that I report that "Function Pointers" are
// "constant" here. It is not at all clear that I have a way of
// doing that. I will go some way by ensuring that code-vectors are
// reported as constant.
//
#ifdef COMMON
    return onevalue(Lispify_predicate(
                        a == nil || a == lisp_true ||
                        is_char(a) ||
                        is_number(a) ||
                        is_vector(a) ||
                        is_bps(a)));
#else
    return onevalue(Lispify_predicate(
                        is_number(a) ||
                        is_vector(a) ||  // Vectors include strings here
                        is_bps(a)));
#endif
}

LispObject Lidentity(LispObject, LispObject a)
{   return onevalue(a);
}

#ifdef COMMON

LispObject Llistp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(is_cons(a)));
}

#endif

LispObject Lnumberp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(is_number(a)));
}

LispObject Lintegerp(LispObject, LispObject a)
{   return onevalue(integerp(a));
}

LispObject Leq_safe(LispObject nil, LispObject a)
{
//
// True if you can safely use EQ tests to check equality. Thus true for
// things that are represented in "immediate" form... and ALSO of nil
// and all other symbols.
//
    return onevalue(symbolp(a) ||
                    is_fixnum(a) ||
                    is_sfloat(a) ||
                    is_odds(a) ? lisp_true : nil);
}

LispObject Lfixp(LispObject nil, LispObject a)
{
#ifdef COMMON
    return onevalue(is_fixnum(a) ? lisp_true : nil);
#else
//
// Standard Lisp defines fixp to say yes to bignums as well as
// fixnums. The code here is as in intergerp.
//
    int tag = ((int)a) & TAG_BITS;
    if (tag == TAG_FIXNUM) return onevalue(lisp_true);
    else if (tag == TAG_NUMBERS)
    {   Header h = *(Header *)((char *)a - TAG_NUMBERS);
        if (type_of_header(h) == TYPE_BIGNUM) return onevalue(lisp_true);
        else return onevalue(nil);
    }
    else return onevalue(nil);
#endif
}

LispObject Lfloatp(LispObject nil, LispObject p)
{   int tag = TAG_BITS & (int)p;
#ifndef EXPERIMENT
    if (tag == TAG_SFLOAT) return onevalue(lisp_true);
#endif
// Beware the next line if I move boxed floats to within TAG_NUMBERS
    if (tag == TAG_BOXFLOAT) return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lshort_floatp(LispObject nil, LispObject p)
{
#ifndef EXPERIMENT
    int tag = TAG_BITS & (int)p;
    if (tag == TAG_SFLOAT) return onevalue(lisp_true);
    else return onevalue(nil);
#else
    return onevalue(nil);
#endif
}

static LispObject Lsingle_floatp(LispObject nil, LispObject p)
{   int tag = TAG_BITS & (int)p;
    if (tag == TAG_BOXFLOAT &&
        type_of_header(flthdr(p)) == TYPE_SINGLE_FLOAT)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Ldouble_floatp(LispObject nil, LispObject p)
{   int tag = TAG_BITS & (int)p;
    if (tag == TAG_BOXFLOAT &&
        type_of_header(flthdr(p)) == TYPE_DOUBLE_FLOAT)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Llong_floatp(LispObject nil, LispObject p)
{   int tag = TAG_BITS & (int)p;
    if (tag == TAG_BOXFLOAT &&
        type_of_header(flthdr(p)) == TYPE_LONG_FLOAT)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lrationalp(LispObject nil, LispObject a)
{   return onevalue(
               Lispify_predicate(
                   is_fixnum(a) ||
                   (is_numbers(a) &&
                    (is_bignum(a) || is_ratio(a)))));
}

LispObject Lcomplexp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(is_numbers(a) && is_complex(a)));
}

#ifdef COMMON

CSLbool complex_stringp(LispObject a)
//
// true if the arg is a string, but NOT a simple string.  In general
// when this is true simplify_string() will then be called to do
// an adjustment.
//
{   Header h;
    LispObject w, nil = C_nil;
    if (!is_vector(a)) return NO;
    h = vechdr(a);
    if (type_of_header(h) != TYPE_ARRAY) return NO;
//
// Note that the cheery Common Lisp Committee decided the abolish the
// separate type 'string-char, so the test here is maybe dubious...
//
    else if (elt(a, 0) != string_char_sym) return NO;
    w = elt(a, 1);
    if (!consp(w) || consp(qcdr(w))) return NO;
    else return YES;
}

#endif

LispObject Lwarn_about_protected_symbols(LispObject nil, LispObject a)
{   LispObject retval = Lispify_predicate(warn_about_protected_symbols);
    warn_about_protected_symbols = (a != nil);
    return onevalue(retval);
}

LispObject Lprotect_symbols(LispObject nil, LispObject a)
{   LispObject retval = Lispify_predicate(symbol_protect_flag);
    symbol_protect_flag = (a != nil);
    return onevalue(retval);
}

CSLbool stringp(LispObject a)
//
// True if arg is a simple OR a general string
//
{   Header h;
#ifdef COMMON
    LispObject w, nil = C_nil;
#endif
    if (!is_vector(a)) return NO;
    h = vechdr(a);
    if (is_string_header(h)) return YES;
#ifdef COMMON
    else if (type_of_header(h) != TYPE_ARRAY) return NO;
//
// Beware abolition of 'string-char
//
    else if (elt(a, 0) != string_char_sym) return NO;
    w = elt(a, 1);
    if (!consp(w) || consp(qcdr(w))) return NO;
    else return YES;
#else
    else return NO;
#endif
}

LispObject Lstringp(LispObject nil, LispObject a)
//
// simple-string-p
//
{   if (!(is_vector(a)) || !is_string(a)) return onevalue(nil);
    else return onevalue(lisp_true);
}

#ifdef COMMON

static LispObject Lc_stringp(LispObject nil, LispObject a)
{   return onevalue(Lispify_predicate(stringp(a)));
}

#endif

LispObject Lhash_table_p(LispObject nil, LispObject a)
//
// hash-table-p
//
{   if (!(is_vector(a)) || type_of_header(vechdr(a)) != TYPE_HASH)
        return onevalue(nil);
    else return onevalue(lisp_true);
}

static LispObject Lsimple_bit_vector_p(LispObject nil,
                                       LispObject a)
//
// simple-bit-vector-p
//
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(is_bitvec_header(vechdr(a))));
}

LispObject Lsimple_vectorp(LispObject nil, LispObject a)
//
// simple-vector-p
//
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_SIMPLE_VEC));
}

LispObject Lbpsp(LispObject nil, LispObject a)
{   if (!(is_bps(a))) return onevalue(nil);
    else return onevalue(lisp_true);
}

LispObject Lthreevectorp(LispObject nil, LispObject a)
//
// This is useful for REDUCE - it checks if something is a vector
// of size 3!
//
{   if (!(is_vector(a))) return onevalue(nil);
    return onevalue(Lispify_predicate(
                        vechdr(a) == (TAG_HDR_IMMED + TYPE_SIMPLE_VEC + ((4*CELL)<<10))));
}

#ifdef COMMON

static LispObject Larrayp(LispObject nil, LispObject a)
{   Header h;
    if (!(is_vector(a))) return onevalue(nil);
    h = vechdr(a);
//
// I could consider accepting TYPE_VEC16 and TYPE_VEC32 etc here...
//
// Note that the suggestion that a string is an array is a real problem
// in a world that believes in Unicode...
    if (type_of_header(h)==TYPE_ARRAY ||
        is_string_header(h) ||
        type_of_header(h)==TYPE_SIMPLE_VEC ||
        is_bitvec_header(h)) return onevalue(lisp_true);
    else return onevalue(nil);
}

static LispObject Lcomplex_arrayp(LispObject nil, LispObject a)
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_ARRAY));
}

static LispObject Lconvert_to_array(LispObject nil, LispObject a)
{   if (!(is_vector(a))) return onevalue(nil);
    vechdr(a) = TYPE_ARRAY + (vechdr(a) & ~header_mask);
    return onevalue(a);
}

#endif

static LispObject Lstructp(LispObject nil, LispObject a)
//
// structp
//
{   if (!(is_vector(a))) return onevalue(nil);
    else return onevalue(Lispify_predicate(
                                 type_of_header(vechdr(a))==TYPE_STRUCTURE));
}

static LispObject Lconvert_to_struct(LispObject nil, LispObject a)
{   if (!(is_vector(a))) return onevalue(nil);
    vechdr(a) = TYPE_STRUCTURE + (vechdr(a) & ~header_mask);
    return onevalue(a);
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "cons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = b;
    qcdr(r) = a;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "xcons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lncons(LispObject nil, LispObject a)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if ((char *)r <= (char *)heaplimit)
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "ncons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Llist2(LispObject nil, LispObject a, LispObject b)
{   a = list2(a, b);
    errexit();
    return onevalue(a);
}

LispObject Lmkquote(LispObject nil, LispObject a)
{   a = list2(quote_symbol, a);
    errexit();
    return onevalue(a);
}

LispObject Llist2star(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "list2*");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = list2star(a,b,c);
    errexit();
    return onevalue(a);
}

LispObject Lacons(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "acons");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = acons(a,b,c);
    errexit();
    return onevalue(a);
}

LispObject Llist3(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, b, c;
    argcheck(nargs, 3, "list3");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    va_end(aa);
    a = list3(a,b,c);
    errexit();
    return onevalue(a);
}

LispObject Llist3star(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, b, c, d;
    argcheck(nargs, 4, "list3*");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    d = va_arg(aa, LispObject);
    va_end(aa);
    a = list3star(a,b,c,d);
    errexit();
    return onevalue(a);
}

LispObject Llist4(LispObject nil, int nargs, ...)
{   va_list aa;
    LispObject a, b, c, d;
    argcheck(nargs, 4, "list4");
    va_start(aa, nargs);
    a = va_arg(aa, LispObject);
    b = va_arg(aa, LispObject);
    c = va_arg(aa, LispObject);
    d = va_arg(aa, LispObject);
    va_end(aa);
    a = list4(a,b,c,d);
    errexit();
    return onevalue(a);
}



#ifdef COMMON
//
// In non-COMMON mode I implement list and list* as special forms
// rather than as functions, guessing that that will be more efficient.
//

LispObject Llist(LispObject nil, int nargs, ...)
{   LispObject r = nil, w, w1;
    va_list a;
    va_start(a, nargs);
    push_args(a, nargs);
    while (nargs > 1)
    {   pop2(w, w1);
        nargs-=2;
        r = list2star(w1, w, r);
        errexitn(nargs);
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        r = cons(w, r);
        errexitn(nargs);
    }
    return onevalue(r);
}

static LispObject Lliststar(LispObject nil, int nargs, ...)
{   LispObject r, w, w1;
    va_list a;
    if (nargs == 0) return onevalue(nil);
    va_start(a, nargs);
    push_args(a, nargs);
    pop(r);
    nargs--;
    while (nargs > 1)
    {   pop2(w, w1);
        nargs-=2;
        r = list2star(w1, w, r);
        errexitn(nargs);
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        r = cons(w, r);
        errexitn(nargs);
    }
    return onevalue(r);
}

//
// fill-vector is used for open-compilation of (vector ...) to avoid
// passing grossly unreasonable numbers of arguments. The expansion of
// (vector e1 ... en) should be
//    (let ((v (mkvect <n-1>)) (i 0))
//       (setq i (fill-vector v i e1 e2 ... e10))
//       (setq i (fill-vector v i e11 e12 ... ))
//       ...
//       v)
//
static LispObject Lfill_vector(LispObject, int nargs, ...)
{   va_list a;
    LispObject v, il;
    int32_t i;
    if (nargs < 3) return aerror("fill-vector");
    va_start(a, nargs);
    v = va_arg(a, LispObject);
    il = va_arg(a, LispObject);
    if (!is_vector(v) || !is_fixnum(il)) return aerror("fill-vector");
    i = int_of_fixnum(il);
    nargs -= 2;
    while (nargs != 0)
    {   elt(v, i++) = va_arg(a, LispObject);
        nargs--;
    }
    return onevalue(fixnum_of_int(i));
}

#endif

LispObject Lpair(LispObject nil, LispObject a, LispObject b)
{   LispObject r = nil;
    while (consp(a) && consp(b))
    {   push2(a, b);
        r = acons(qcar(a), qcar(b), r);
        pop2(b, a);
        errexit();
        a = qcdr(a);
        b = qcdr(b);
    }
    a = nil;
    while (r != nil)
    {   b = qcdr(r);
        qcdr(r) = a;
        a = r;
        r = b;
    }
    return onevalue(a);
}


static int32_t membercount(LispObject a, LispObject b)
//
// Counts how many times a is a member of the list b
//
{   int32_t r = 0;
#ifdef COMMON
    LispObject nil = C_nil;
#endif
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == qcar(b)) r++;
            b = qcdr(b);
        }
        return r;
    }
    while (consp(b))
    {   LispObject cb = qcar(b);
        if (equal(a, cb)) r++;
        b = qcdr(b);
    }
    return r;
}

//
// INTERSECTION(A,B)
// The result will have its items in the order that they occur in A.
// If lists A and B contain duplicate items these will appear in the
// output if and only if the items involved are duplicated in both
// input lists.
//
LispObject Lintersect(LispObject nil, LispObject a, LispObject b)
{   LispObject r = nil, w;
    push(b);
    while (consp(a))
    {   push2(a, r);
        w = Lmember(nil, qcar(a), stack[-2]);
        errexitn(3);
// Here I ignore any item in a that is not also in b
        if (w != nil)
        {   int32_t n1 = membercount(qcar(stack[-1]), stack[0]);
            errexitn(3);
//
// Here I want to arrange that items only appear in the result list multiple
// times if they occur multipl times in BOTH the input lists.
//
            if (n1 != 0)
            {   int32_t n2 = membercount(qcar(stack[-1]), stack[-2]);
                errexitn(3);
                if (n2 > n1) n1 = 0;
            }
            if (n1 == 0)
            {   pop(r);
                a = stack[0];
                r = cons(qcar(a), r);
                errexitn(2);
                pop(a);
            }
            else pop2(r, a);
        }
        else pop2(r, a);
        a = qcdr(a);
    }
    popv(1);
    a = nil;
    while (consp(r))
    {   b = r;
        r = qcdr(r);
        qcdr(b) = a;
        a = b;
    }
    return onevalue(a);
}

//
// UNION(A, B)
// This works by consing onto the front of B each element of A that
// is not already in B.  Thus items in A (but not already in B) get
// added in reversed order.  Duplicates in B remain there, and but
// duplicates in A are dropped.
//
LispObject Lunion(LispObject nil, LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject c;
        push2(a, b);
        c = Lmember(nil, qcar(a), b);
        errexitn(2);
        pop(b);
        if (c == nil)
        {   b = cons(qcar(stack[0]), b);
            errexitn(1);
        }
        pop(a);
        a = qcdr(a);
    }
    return onevalue(b);
}


LispObject Lenable_errorset(LispObject nil, LispObject a, LispObject b)
{   LispObject r = cons(fixnum_of_int(errorset_min),
                        fixnum_of_int(errorset_max));
    errexit();
    if (a == nil || a == fixnum_of_int(0))            errorset_min = 0;
    else if (a == fixnum_of_int(1))                   errorset_min = 1;
    else if (a == fixnum_of_int(2))                   errorset_min = 2;
    else if (a == fixnum_of_int(3) || a == lisp_true) errorset_min = 3;
    if (b == nil || b == fixnum_of_int(0))            errorset_max = 0;
    else if (b == fixnum_of_int(1))                   errorset_max = 1;
    else if (b == fixnum_of_int(2))                   errorset_max = 2;
    else if (b == fixnum_of_int(3) || b == lisp_true) errorset_max = 3;
// I increase the max to be at least as high as the indicated min
    if (errorset_min > errorset_max) errorset_max = errorset_min;
// I also arrange that the current state is within the specified range
    switch (errorset_min)
    {   case 0: break;
        case 1: miscflags |= HEADLINE_FLAG;
            break;
        case 2: miscflags |= HEADLINE_FLAG | FNAME_FLAG;
            break;
        default: // case 3:
            miscflags |= BACKTRACE_MSG_BITS;
            break;
    }
    switch (errorset_max)
    {   case 0: miscflags &= ~BACKTRACE_MSG_BITS;
            break;
        case 1: miscflags &= ~(FNAME_FLAG | ARGS_FLAG);
            break;
        case 2: miscflags &= ~ARGS_FLAG;
            break;
        default: // case 3:
            break;
    }
    return r;
}

LispObject Lenable_backtrace(LispObject nil, LispObject a)
{
//
//    (enable-backtrace nil)    errors silent unless ALWAYS_NOISY set
//    (enable-backtrace 0)      ditto
//    (enable-backtrace 1)      show 1-line messaqe on error
//    (enable-backtrace 2)      show function names but not args in B/T
//    (enable-backtrace 3)      show functions and args
//    (enable-backtrace t)      ditto
//    otherwise                 just return previous setting
//
    int32_t n = miscflags;
    miscflags &= ~BACKTRACE_MSG_BITS;
    if (a == nil || a == fixnum_of_int(0)) /* nothing */;
    else if (a == fixnum_of_int(1))
        miscflags |=  HEADLINE_FLAG;
    else if (a == fixnum_of_int(2))
        miscflags |=  HEADLINE_FLAG | FNAME_FLAG;
    else if (a == lisp_true || a == fixnum_of_int(3))
        miscflags |= BACKTRACE_MSG_BITS;
    else miscflags = n; // Otherwise have no effect
    return onevalue(fixnum_of_int(miscflags & ARGS_FLAG ? 3 :
                                  miscflags & FNAME_FLAG ? 2 :
                                  miscflags & HEADLINE_FLAG ? 1 :
                                  0));
}

#ifdef NAG

LispObject Lunwind(LispObject nil, int nargs, ...)
{   argcheck(nargs, 0, "unwind");
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_count = 0;
    exit_tag = nil;
    flip_exception();
    return nil;
}

#endif

//
// If the variable *break-function* has as its value a symbol, and that
// symbol names a function, then the function concerned will be called
// with one argument after the headline for the diagnostic. When it returns
// the system will unwind in the usual manner.
//

LispObject Lerror(LispObject nil, int nargs, ...)
{   va_list a;
    LispObject w;
#ifdef COMMON
    LispObject r = nil, w1;
#else
    int i;
#endif
    if (nargs == 0) return aerror("error");
    errors_now++;
    if (errors_limit >= 0 && errors_now > errors_limit)
        return resource_exceeded();
    va_start(a, nargs);
    push_args(a, nargs);
#ifdef COMMON
    while (nargs > 1)
    {   pop2(w, w1);
        nargs -= 2;
        w = list2star(w1, w, r);
        nil = C_nil;
        if (exception_pending()) flip_exception();
        else r = w;
    }
    while (nargs > 0)
    {   pop(w);
        nargs--;
        w = cons(w, r);
        nil = C_nil;
        if (exception_pending()) flip_exception();
        else r = w;
    }
    if (miscflags & (HEADLINE_FLAG|ALWAYS_NOISY))
    {   push(r);
        err_printf("\n+++ error: ");
//
// I will use FORMAT to handle error messages provided the first arg
// to error had been a string and also provided (for bootstrapping) that
// the function FORMAT seems to be defined.
//
        if (qfn1(format_symbol) == undefined1 ||
            !consp(r) ||
            !stringp(qcar(r))) loop_print_error(r);
        else Lapply_n(nil, 3, format_symbol, qvalue(error_output), r);
        ignore_exception();
        err_printf("\n");
        pop(r);
        ignore_exception();
    }
    qvalue(emsg_star) = r;               // "Error message" in CL world
    exit_value = fixnum_of_int(0);       // "Error number"  in CL world
#else
    if (miscflags & HEADLINE_FLAG)
    {   err_printf("\n+++ error: ");
        loop_print_error(stack[1-nargs]);
        for (i=1; i<nargs; i++)
        {   err_printf(" ");
            loop_print_error(stack[1+i-nargs]);
        }
        err_printf("\n");
    }
    if (nargs == 1)
    {   push(nil);
        nargs++;
    }
    qvalue(emsg_star) = stack[2-nargs];  // "Error message" in SL world
    exit_value = stack[1-nargs];         // "Error number"  in SL world
    popv(nargs);
#endif
    if ((w = qvalue(break_function)) != nil &&
        symbolp(w) &&
        qfn1(w) != undefined1)
    {   (*qfn1(w))(qenv(w), qvalue(emsg_star));
        ignore_exception();
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_count = 0;
    exit_tag = nil;
    flip_exception();
    return nil;
}

LispObject Lerror1(LispObject nil, LispObject a1)
{   return Lerror(nil, 1, a1);
}

LispObject Lerror2(LispObject nil, LispObject a1, LispObject a2)
{   return Lerror(nil, 2, a1, a2);
}

LispObject Lerror0(LispObject nil, int nargs, ...)
{
//
// Silently provoked error - unwind to surrounding errorset level. Note that
// this will NEVER enter a user-provided break loop...
// Also note that (enable-errorset) can set a lower limit to noise levels
// that can result in the error here NOT being silent!
//
    argcheck(nargs, 0, "error0");
    errors_now++;
    if (errors_limit >= 0 && errors_now > errors_limit)
        return resource_exceeded();
    switch (errorset_min)
    {   case 0: miscflags &= ~BACKTRACE_MSG_BITS;
            break;
        case 1: miscflags &= ~(FNAME_FLAG | ARGS_FLAG);
            break;
        case 2: miscflags &= ~ARGS_FLAG;
        default:break;
    }
    exit_reason = (miscflags & ARGS_FLAG) ? UNWIND_ERROR :
                  (miscflags & FNAME_FLAG) ? UNWIND_FNAME :
                  UNWIND_UNWIND;
    exit_value = exit_tag = nil;
    exit_count = 0;
    flip_exception();
    return nil;
}

LispObject Lmake_special(LispObject, LispObject a)
{   if (!symbolp(a)) return aerror1("make-special", a);
    qheader(a) |= SYM_SPECIAL_VAR;
    return onevalue(a);
}

LispObject Lmake_global(LispObject, LispObject a)
{   if (!symbolp(a)) return aerror("make-global");
    qheader(a) |= (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    return onevalue(a);
}

LispObject Lunmake_special(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    qheader(a) &= ~(SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    return onevalue(a);
}

LispObject Lunmake_global(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    qheader(a) &= ~(SYM_SPECIAL_VAR | SYM_GLOBAL_VAR);
    return onevalue(a);
}

LispObject Lsymbol_specialp(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & (SYM_SPECIAL_VAR | SYM_GLOBAL_VAR)) ==
             SYM_SPECIAL_VAR) return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lsymbol_globalp(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & SYM_GLOBAL_VAR) != 0) return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lboundp(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
#if !defined COMMON && 0
//
// In COMMON Lisp it seems that this is intended to just check if the
// value cell in a shallow-bound implementation contains some marker value
// that stands for "junk".  In Standard Lisp mode I deem that variables
// that have not been declared fluid are unbound.  Seems to me like a
// classical mix-up between the concept of binding and of having some
// particular value...  Oh well.
//
// (September 2010) I just changed that so that a name that is not fluid
// but that has been given a value (using SET or SETQ I expect) is counted
// as "bound". This probably matches what PSL does and this function is
// also probably used by few enough people that this will not lead to
// too many bugs even though it is an incompatible change in behavior.
//
    else if ((qheader(a) & SYM_SPECIAL_VAR) == 0) return onevalue(nil);
#endif
    else if (qvalue(a) == unset_var) return onevalue(nil); // no value yet
    else return onevalue(lisp_true);
}

LispObject Lsymbol_value(LispObject, LispObject a)
{   if (!symbolp(a)) return onevalue(a);
    else return onevalue(qvalue(a));
}

LispObject Lset(LispObject nil, LispObject a, LispObject b)
{   if (!symbolp(a) || a == nil || a == lisp_true) return aerror("set");
    qvalue(a) = b;
    return onevalue(b);
}

LispObject Lmakeunbound(LispObject nil, LispObject a)
{   if (!symbolp(a) || a == nil || a == lisp_true) return aerror("makeunbound");
    qvalue(a) = unset_var;
    return onevalue(a);
}

LispObject Lsymbol_function(LispObject nil, LispObject a)
{   one_args *f1;
    two_args *f2;
    n_args *fn;
    if (!symbolp(a)) return onevalue(nil);
    f1 = qfn1(a); f2 = qfn2(a); fn = qfnn(a);
    if ((qheader(a) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0 ||
        (f1 == undefined1 && f2 == undefined2 &&
         fn == undefinedn)) return onevalue(nil);
    else if (f1 == interpreted1 ||
             f2 == interpreted2 ||
             fn == interpretedn)
// I wonder if onevalue(cons(...)) is really valid here. It is OK in SL mode
        return onevalue(cons(lambda, qenv(a)));
    else if (f1 == funarged1 ||
             f2 == funarged2 ||
             fn == funargedn)
        return onevalue(cons(funarg, qenv(a)));
    else if (f1 == traceinterpreted1 ||
             f2 == traceinterpreted2 ||
             fn == traceinterpretedn)
        return onevalue(cons(lambda, qcdr(qenv(a))));
    else if (f1 == tracefunarged1 ||
             f2 == tracefunarged2 ||
             fn == tracefunargedn)
        return onevalue(cons(funarg, qcdr(qenv(a))));
    else
    {
#ifdef COMMON
        LispObject b = get(a, work_symbol, nil);
#else
        LispObject b = get(a, work_symbol);
#endif
//
// If I have already manufactured a code pointer for this function I
// can find it on the property list - in that case I will re-use it.
//
        while (b != nil)
        {   LispObject c = qcar(b);
            if ((qheader(c) & (SYM_C_DEF | SYM_CODEPTR)) ==
                (SYM_CODEPTR | (qheader(a) & SYM_C_DEF)))
                return onevalue(c);
            b = qcdr(b);
        }
        push(a);
//
// To carry a code-pointer I manufacture a sort of gensym, flagging
// it in its header as a "code pointer object" and sticking the required
// definition in with it.  I need to link this to the originating
// definition in some cases to allow for preserve/restart problems wrt
// the initialisation of function addresses that refer to C code.
// I make the carrier using GENSYM1, but need to clear the gensym flag bit
// to show I have a regular name for the object, and that I will not need
// to append a serial number later on. In Common Lisp mode I let the name
// of the gensym be just the name of the function, while in Standard Lisp
// mode I will append a numeric suffix. I do this because in Common Lisp
// mode the thing will print as (say) #:apply which is visibly different
// from the name 'apply of the base function, while in Standard Lisp a name
// like apply775 is needed to make the distinction (easily) visible.
//
#ifdef COMMON
        b = Lgensym2(nil, a);
#else
        b = Lgensym1(nil, a);
#endif
        pop(a);
        errexit();
        set_fns(b, f1, f2, fn);
        qenv(b) = qenv(a);
#ifdef COMMON
// in Common Lisp mode gensyms that are "unprinted" are not special
        qheader(b) ^= (SYM_ANY_GENSYM | SYM_CODEPTR);
#else
        qheader(b) ^= (SYM_UNPRINTED_GENSYM | SYM_ANY_GENSYM | SYM_CODEPTR);
#endif
        if ((qheader(a) & SYM_C_DEF) != 0)
        {   LispObject c, w;
#ifdef COMMON
            c = get(a, unset_var, nil);
#else
            c = get(a, unset_var);
#endif
            if (c == nil) c = a;
            push3(a, b, c);
            qheader(b) |= SYM_C_DEF;
            putprop(b, unset_var, c);
            errexitn(3);
            c = stack[0]; b = stack[-1];
#ifdef COMMON
            w = get(c, work_symbol, nil);
#else
            w = get(c, work_symbol);
#endif
            w = cons(b, w);
            pop(c);
            errexitn(2);
            putprop(c, work_symbol, w);
            pop2(b, a);
            errexit();
        }
        return onevalue(b);
    }
}

LispObject Lspecial_form_p(LispObject nil, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & SYM_SPECIAL_FORM) != 0) return onevalue(lisp_true);
    else return onevalue(nil);
}

LispObject Lcodep(LispObject nil, LispObject a)
//
// This responds TRUE for the special pseudo-symbols that are used to
// carry compiled code objects.  It returns NIL on the symbols that
// are normally used by the user.
//
{   if (!symbolp(a)) return onevalue(nil);
    if ((qheader(a) & (SYM_CODEPTR | SYM_C_DEF)) == SYM_CODEPTR)
        return onevalue(lisp_true);
    else return onevalue(nil);
}

#ifdef DEBUG_VALIDATE
static int validate_count = 0;
#endif

LispObject getvector(int tag, int type, size_t size)
{
//
// tag is the value (e.g. TAG_SYMBOL) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_SYMBOL) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
//
// When I allocate most things the size as passed MUST be a multiple of 4.
// If I am allocating an array of halfwords I need to have added 1 to it, for
// strings and byte-arrays 3 (in the experimental scheme). For bit-vectors the
// easiest scheme may be to put most of what I need in the type argument and
// leave size passed as zero!
    LispObject nil = C_nil;
#ifdef DEBUG_VALIDATE
//
// If I do a full validation every time I allocate a vector that REALLY
// hits performance, so I will do it occasionally. The 1 in 500 indicated
// at present is a pretty random choice of frequency!
//
    if ((++validate_count) % 500 == 0)
    {   copy_into_nilseg(NO);
        validate_all("getvector", __LINE__, __FILE__);
    }
#endif
    for (;;)
    {   char *r = (char *)vfringe;
        uint32_t free = (size_t)((char *)vheaplimit - r);
//
// On a 64-bit system the allocation size will be a multiple of 8 anyway, so
// the doubleword_align here will have no effect! The result is that I never
// need or use a padding word at the end of a vector in that case. Note that
// well. On 32-bit systems vectors may have a dummy padder word at the end
// but on 64-bit systems they do not.
//
        size_t alloc_size = (size_t)doubleword_align_up(size);
//
// There is a real NASTY here - it is quite possible that I ought to implement
// a scheme whereby large vectors can be allocated as a series of chunks so as
// to avoid the current absolute limit on size.  At one stage I used a page
// size of just 64K on small machines, and for embedded applications that
// may still be sensible. But MOSTLY I now have 4Mb pages. But as discussed
// in restart.c I need to limit the size of a vector to HALF the page
// size of I am later on going to reload on a 64-bit machine, so here I
// have a rather odd test that tries to enforce this on "standard" machines
// but not on truly tiny ones. The specific judgement applied here is
// that if the page size is at least 2M and I am on a 32-bit machine I will
// use at most half the page. To be specific about the consequences, it means
// that I can have an array of length up to about 512K cells not 1M in
// that case. If I ask for someting too bif I will report the request size
// as if it has been for a vector of lisp items.
//
        if (alloc_size >
            ((CSL_PAGE_SIZE>2000000 &&
              !SIXTY_FOUR_BIT) ? CSL_PAGE_SIZE/2 - 32 :
             CSL_PAGE_SIZE - 32))
            return aerror1("vector request too big",
                           fixnum_of_int(alloc_size/CELL-1));
        if (alloc_size > free)
        {   char msg[40];
//
// I go to a whole load of trouble here to tell the user what sort of
// vector request provoked this garbage collection.  I wonder if the user
// really cares - but I do very much when I am chasing after GC bugs!
//
            switch (tag)
            {   case TAG_SYMBOL:
                    sprintf(msg, "symbol header");
                    break;
                case TAG_NUMBERS:
                    switch (type)
                    {   case TYPE_BIGNUM:
                            sprintf(msg, "bignum(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "numbers(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_VECTOR:
                    switch (type)
                    {
#ifdef EXPERIMENT
                        case TYPE_STRING_1:
                        case TYPE_STRING_2:
                        case TYPE_STRING_3:
                        case TYPE_STRING_4:
#else
                        case TYPE_STRING:
#endif
                            sprintf(msg, "string(%ld)", (long)size);
                            break;
#ifdef EXPERIMENT
                        case TYPE_BPS_1:
                        case TYPE_BPS_2:
                        case TYPE_BPS_3:
                        case TYPE_BPS_4:
#else
                        case TYPE_BPS:
#endif
                            sprintf(msg, "BPS(%ld)", (long)size);
                            break;
                        case TYPE_SIMPLE_VEC:
                            sprintf(msg, "simple vector(%ld)", (long)size);
                            break;
                        case TYPE_HASH:
                            sprintf(msg, "hash table(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "vector(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_BOXFLOAT:
                    sprintf(msg, "float(%ld)", (long)size);
                    break;
                default:
                    sprintf(msg, "getvector(%lx,%ld)", (long)tag, (long)size);
                    break;
            }
            reclaim(nil, msg, GC_VEC, alloc_size);
            errexit();
            continue;
        }
        vfringe = (LispObject)(r + alloc_size);
#ifdef EXPERIMENT
        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
#else
        *((Header *)r) = type + (size << 10) + TAG_HDR_IMMED;
#endif
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
        return (LispObject)(r + tag);
    }
}

LispObject getvector_init(size_t n, LispObject k)
{   LispObject p, nil;
    push(k);
    p = getvector(TAG_VECTOR, TYPE_SIMPLE_VEC, n);
    pop(k);
    errexit();
    if (!SIXTY_FOUR_BIT && ((n & 4) != 0))
        n += 4;   // Ensure last doubleword is tidy
    while (n > CELL)
    {   n -= CELL;
        *(LispObject *)((char *)p - TAG_VECTOR + n) = k;
    }
    return p;
}

LispObject Lstop(LispObject, LispObject code)
{
//
// I ignore "env" and set up nil for myself here to make it easier to call
// this function from random places in my interface code...
//
    LispObject nil = C_nil;
    if (!is_fixnum(code)) return aerror("stop");
    exit_value = code;
    exit_tag = fixnum_of_int(0);    // Flag to say "stop"
    exit_reason = UNWIND_RESTART;
    exit_count = 1;
    flip_exception();
    return nil;
}

LispObject Lstop2(LispObject env, LispObject code, LispObject)
{   return Lstop(env, code);
}

LispObject Lstop0(LispObject env, int nargs, ...)
{   va_list aa;
    LispObject code = fixnum_of_int(0);
    if (nargs != 0)
    {   va_start(aa, nargs);
        code = va_arg(aa, LispObject);
        va_end(aa);
    }
    return Lstop(env, code);
}

clock_t base_time;
double *clock_stack, consolidated_time[10], gc_time;

void push_clock(void)
{   clock_t t0 = read_clock();
//
// Provided that I do this often enough I will not suffer clock
// wrap-around or overflow.
//
    double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
    base_time = t0;
    *clock_stack += delta;
    *++clock_stack = 0.0;
}

double pop_clock(void)
{   clock_t t0 = read_clock();
    double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
    base_time = t0;
    return delta + *clock_stack--;
}

LispObject Ltime(LispObject nil, int nargs, ...)
{   uint32_t tt, tthigh;
    double td;
    LispObject r;
    if (clock_stack == &consolidated_time[0])
    {   clock_t t0 = read_clock();
        double delta = (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
        base_time = t0;
        consolidated_time[0] += delta;
    }
    argcheck(nargs, 0, "time");
//
// If I just converted to an uint32_t value here I would get overflow
// after 2^32 milliseconds, which is 49.7 days. This is, I fear, just within
// the range that could come and bite me! So I will arrange the
// conversion so I get a greater range supported!
//
    td = 1000.0 * consolidated_time[0];
//
// By dividing by 2^16 I get a value tthigh that only only approaches overflow
// after almost 9000 years. That seems good enough to me!
//
    tthigh = (uint32_t)(td/(double)0x10000);
//
// On the next line the conversion of thigh back to a double and the
// multiplication ought not to introduce any error at all, and so td should
// and up an accurate remainder.
//
    td -= (double)0x10000 * (double)tthigh;
    if (td < 0.0)
    {   tthigh--;
        td += (double)0x10000;
    }
    tt = (uint32_t)td;
//
// Now I shuffle bits in tt and tthigh to get a proper CSL-ish representation
// of a 2-word integer, with the low 31 bits in tt.
//
    tt += (tthigh & 0x7fff) << 16;
    tthigh >>= 15;
    if ((tt & 0x80000000) != 0)
    {   tt &= 0x7fffffff;
        tthigh++;
    }
    if (tthigh != 0) r = make_two_word_bignum(tthigh, tt);
    else if ((tt & fix_mask) != 0) r = make_one_word_bignum(tt);
    else return onevalue(fixnum_of_int(tt));
    errexit();
    return onevalue(r);
}

LispObject Lgctime(LispObject, int nargs, ...)
{   argcheck(nargs, 0, "gctime");
    return onevalue(fixnum_of_int((int32_t)(1000.0 * gc_time)));
}

LispObject Ldecoded_time(LispObject nil, int nargs, ...)
{   time_t t0 = time(NULL);
//
//        tm_sec      -- seconds 0..59
//        tm_min      -- minutes 0..59
//        tm_hour     -- hour of day 0..23
//        tm_mday     -- day of month 1..31
//        tm_mon      -- month 0..11
//        tm_year     -- years since 1900
//        tm_wday     -- day of week, 0..6 (Sunday..Saturday)
//        tm_yday     -- day of year, 0..365
//        tm_isdst    -- >0 if daylight savings time
//                    -- ==0 if not DST
//                    -- <0 if don't know
//
    struct tm *tbuf = localtime(&t0);
    LispObject r, *p = &mv_2;
    int w;
    argcheck(nargs, 0, "get-decoded-time");
    r = fixnum_of_int(tbuf->tm_sec);
    *p++ = fixnum_of_int(tbuf->tm_min);
    *p++ = fixnum_of_int(tbuf->tm_hour);
    *p++ = fixnum_of_int(tbuf->tm_mday);
    *p++ = fixnum_of_int(tbuf->tm_mon+1);
    *p++ = fixnum_of_int(tbuf->tm_year+1900);
    w = tbuf->tm_wday;
    *p++ = fixnum_of_int(w == 0 ? 6 : w-1);
    *p++ = tbuf->tm_isdst > 0 ? lisp_true : nil;
    *p++ = fixnum_of_int(0);  // Time zone info not available?
//
// Until and unless I implement multiple values in Standard Lisp mode this
// function will count as a bit silly in that most of its results will
// be just lost!
//
    return nvalues(r, 9);
}

//
// (date)             "14-May-13"
// (date!-and!-time)  "Tue May 14 09:52:45 2013"
//
// Then (date t) and (date!-and!-time t) flip formats (well actually any
// argument will suffice).
//

LispObject Ldate(LispObject nil, int nargs, ...)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    char today1[32];
    argcheck(nargs, 0, "date");
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    //       012345678901234567890123
    today[24] = 0;             // loses final '\n'
    today1[0] = today[8]==' ' ? '0' : today[8];
    today1[1] = today[9];
    today1[2] = '-';
    today1[3] = today[4];
    today1[4] = today[5];
    today1[5] = today[6];
    today1[6] = '-';
    today1[7] = today[22];
    today1[8] = today[23];
    today1[9] = 0;             // Now as in 03-Apr-09
    w = make_string(today1);
    errexit();
    return onevalue(w);
}

LispObject Ldate1(LispObject nil, LispObject a1)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    today[24] = 0;             // loses final '\n'
    w = make_string(today);
    errexit();
    return onevalue(w);
}

LispObject Ldate_and_time(LispObject nil, int nargs, ...)
{   LispObject w;
    time_t t = time(NULL);
    char today[32];
    argcheck(nargs, 0, "date");
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    today[24] = 0;             // loses final '\n'
    w = make_string(today);
    errexit();
    return onevalue(w);
}

LispObject Ldate_and_time1(LispObject nil, LispObject a1)
{   LispObject w;
    time_t t = time(NULL);
    char today[32], today1[32];
    strcpy(today, ctime(&t));  // e.g. "Sun Sep 16 01:03:52 1973\n"
    //       012345678901234567890123
    today[24] = 0;             // loses final '\n'
    today1[0] = today[8]==' ' ? '0' : today[8];
    today1[1] = today[9];
    today1[2] = '-';
    today1[3] = today[4];
    today1[4] = today[5];
    today1[5] = today[6];
    today1[6] = '-';
    today1[7] = today[22];
    today1[8] = today[23];
    today1[9] = 0;             // Now as in 03-Apr-09
    w = make_string(today1);
    errexit();
    return onevalue(w);
}

LispObject Ldatestamp(LispObject nil, int nargs, ...)
//
// Returns date-stamp integer, which on many systems will be the
// number of seconds between 1970.0.0 and now, but which could be
// pretty-well other things, as per the C "time_t" type.
//
{   LispObject w;
    time_t t = time(NULL);
//
// Hmmm - I need to check time_t on a 64-bit machine!
//
    uint32_t n = (uint32_t)t;   // NON-PORTABLE assumption about time_t
    argcheck(nargs, 0, "datestamp");
    if ((n & fix_mask) == 0) w = fixnum_of_int(n);
    else if ((n & 0xc0000000U) == 0) w = make_one_word_bignum(n);
    else w = make_two_word_bignum((n >> 31) & 1, n & 0x7fffffff);
    errexit();
    return onevalue(w);
}

LispObject Ltimeofday(LispObject nil, int nargs, ...)
//
// This is like datestamp, in that it returns information about the
// current real time. However it returns a pair of two values, the
// first being in seconds and the second (when available) being in
// microseconds.
//
{   LispObject w;
    time_t t = time(NULL);
//
// Note that the 32-bit time used here will wrap in 2038.
//
    uint32_t n = (uint32_t)t, un = 0;
#ifdef HAVE_SYS_TIME_H
#ifdef HAVE_GETTIMEOFDAY
// If more precise informatuon is available then use it
    struct timeval tv;
    gettimeofday(&tv, NULL);
    n = (uint32_t)tv.tv_sec;
    un = (uint32_t)tv.tv_usec;
#endif
#endif
    argcheck(nargs, 0, "datestamp");
    if ((n & fix_mask) == 0) w = fixnum_of_int(n);
    else if ((n & 0xc0000000U) == 0) w = make_one_word_bignum(n);
    else w = make_two_word_bignum((n >> 31) & 1, n & 0x7fffffff);
    errexit();
    w = cons(w, fixnum_of_int(un));
    errexit();
    return onevalue(w);
}

// This will be the header for a string of length exactly 24. It is
// used because a valid date will be a string of just that length.

#ifdef EXPERIMENT
#define STR24HDR (TAG_HDR_IMMED+TYPE_STRING_1+((24+CELL+3)<<(Tw+5)))
#else
#define STR24HDR (TAG_HDR_IMMED+TYPE_STRING+((24+CELL)<<10))
#endif

static int getint(char *p, int len)
{   int r = 0;
    while (len-- != 0)
    {   int c = *p++;
        if (c == ' ') c = '0';
        r = 10*r + (c - '0');
    }
    return r;
}

static int getmon(char *s)
{   int c1 = s[0], c2 = s[1], c3 = s[2], r = -1, w;
    const char *m = "janfebmaraprmayjunjulaugsepoctnovdec";
    if (isupper(c1)) c1 = tolower(c1);
    if (isupper(c2)) c2 = tolower(c2);
    if (isupper(c3)) c3 = tolower(c3);
    for (w=0; w<12; w++)
    {   if (c1==m[0] && c2==m[1] && c3==m[2])
        {   r = w;
            break;
        }
        m += 3;
    }
    return r;
}

static LispObject Ldatelessp(LispObject nil, LispObject a, LispObject b)
//
// This is maybe a bit of an abomination!  The functions (date) and
// (filedate "filename") [and also (modulep 'modulename)] return times
// as strings of 24 characters.  This function decodes these and
// sorts out which time is earlier.  The alternative would be to provide
// a collection of functions that returned coded times (as in C "time_t"),
// but I have greater doubts about making those utterly portable, while the
// textual arrangement used here seems fairly robust (until you start
// worrying about carrying a portable machine across time zones or switching
// to daylight savings time).
//
{   char *aa, *bb;
    CSLbool res;
    int wa, wb;
    if (!is_vector(a) || !is_vector(b) ||
        vechdr(a) != STR24HDR ||
        vechdr(b) != STR24HDR) return aerror2("datelessp", a, b);
    aa = (char *)a + (CELL - TAG_VECTOR);
    bb = (char *)b + (CELL - TAG_VECTOR);
//
// Layout is eg. "Wed May 12 15:50:23 1993"
//                012345678901234567890123
// Note that the year is 4 digits so that the year 2000 should hold
// no special terrors JUST here.
//
    if ((wa = getint(aa+20, 4)) != (wb = getint(bb+20, 4))) res = wa < wb;
    else if ((wa = getmon(aa+4)) != (wb = getmon(bb+4))) res = wa < wb;
    else if ((wa = getint(aa+8, 2)) != (wb = getint(bb+8, 2))) res = wa < wb;
    else if ((wa = getint(aa+11, 2)) != (wb = getint(bb+11, 2))) res = wa < wb;
    else if ((wa = getint(aa+14, 2)) != (wb = getint(bb+14, 2))) res = wa < wb;
    else if ((wa = getint(aa+17, 2)) != (wb = getint(bb+17, 2))) res = wa < wb;
    else res = NO;
    return onevalue(Lispify_predicate(res));
}

static LispObject Lrepresentation1(LispObject nil, LispObject a)
//
// Intended for debugging, and use with indirect (q.v.)
//
{   if (SIXTY_FOUR_BIT)
    {   a = make_lisp_integer64((int64_t)a);
        errexit();
        return onevalue(a);
    }
    else
    {   a = make_lisp_integer32((int32_t)a);
        errexit();
        return onevalue(a);
    }
}

static LispObject Lrepresentation2(LispObject nil,
                                   LispObject a, LispObject b)
//
// Intended for debugging, and use with indirect (q.v.).  arg2, if
// present and non-nil makes this more verbose.
//
{   if (SIXTY_FOUR_BIT)
    {   if (b != nil) trace_printf(" %.16" PRIx64 " ", (uint64_t)a);
        a = make_lisp_integer64((int64_t)a);
        errexit();
        return onevalue(a);
    }
    else
    {   if (b != nil) trace_printf(" %.8lx ", (long)(uint32_t)a);
        a = make_lisp_integer32((int32_t)a);
        errexit();
        return onevalue(a);
    }
}

LispObject Lindirect(LispObject, LispObject a)
{   if (SIXTY_FOUR_BIT)
        return onevalue(*(LispObject *)(intptr_t)sixty_four_bits(a));
    else return onevalue(*(LispObject *)(intptr_t)thirty_two_bits(a));
}

//
// A basic foreign function interface...
//


//
//   (setq libobject (open!-foreign!-library "libraryname"))
// On windows ".dll" is appended, on other systems ".so", unless there is
// already a suffix. Returns nil if the library can not be accessed.
//
// I will not (for now) provide a call to close the library - it should be
// closed when the system exits.
//

LispObject Lopen_foreign_library(LispObject nil, LispObject name)
{
#ifdef WIN32
    HANDLE a;
#else
    void *a;
#endif
    LispObject r;
    char libname[LONGEST_LEGAL_FILENAME];
    size_t len;
    const char *w;
    char *w2, *w1 = NULL;
    memset(libname, 0, sizeof(libname));
    w = get_string_data(name, "find-foreign-library", &len);
    errexit();
    if (len > sizeof(libname)-5) len = sizeof(libname)-5;
    sprintf(libname, "%.*s", (int)len, w);
    for (w2=libname; *w2!=0; w2++)
        if (w1==NULL && *w2 == '.') w1 = w2;
        else if (*w2 == '/' || *w2 == '\\') w1 = NULL;
//
// Now of w1 is not NULL it identifies a suffix ".xxx" where there is no
// "/" or "\\" in the string xxx. A suffix such as ".so.1.3.2" is reported as
// a whole despite the embedded dots.
// On Windows if no suffix is provided a ".dll" will be appended, while
// on other systems ".so" is used.
//
#ifdef WIN32
    if (w1 == NULL) strcat(libname, ".dll");
    for (w1=libname; *w1!=0; w1++)
        if (*w1 == '/') *w1 = '\\';
//
// For now I will leave the trace print of the library name here, since
// it should only appear once per run so ought not to cause over-much grief.
// eventually I will remove it!
//
#ifdef DEBUG
    printf("open-library Windows %s\n", libname);
#endif
    a = LoadLibrary(libname);
    if (a == 0)
    {
#ifdef DEBUG
        DWORD err = GetLastError();
        char errbuf[80];
//
// The printf calls here to report errors will not be useful in some
// windowed contexts, so I will need to rework them in due course.
//
        printf("Error code %ld = %lx\n", (long)err, (long)err);
        err = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
                            FORMAT_MESSAGE_IGNORE_INSERTS,
                            NULL, err, 0, errbuf, 80, NULL);
        if (err != 0) printf("%s", errbuf);
#endif
        return onevalue(nil);
    }
#else
    if (w1 == NULL) strcat(libname, ".so");
#ifdef DEBUG
//
// For now I will leave the trace print of the library name here, since
// it should only appear once per run so ought not to cause over-much grief.
// eventually I will remove it!
//
    printf("open-library Linux/Mac/BSD/Unix etc %s\n", libname);
#endif
    a = dlopen(libname, RTLD_NOW | RTLD_GLOBAL);
    if (a == NULL)
    {
#ifdef DEBUG
        printf("Err = <%s>\n", dlerror()); fflush(stdout);
#endif
        return onevalue(nil);
    }
#endif
    r = encapsulate_pointer((void *)a);
    errexit();
    return onevalue(r);
}

//
// (setq entrypoint (find!-foreign!-function "fname" libobject))
// Using a library opened by open!-foreign!-library look up an entrypoint
// for a function called "fname". If one can not be found return nil.
//

LispObject Lfind_foreign_function(LispObject nil, LispObject name,
                                  LispObject lib)
{   LispObject r;
    void *b;
    const char *w;
    char sname[100];
    size_t len;
#ifdef WIN32
    HMODULE a;
#else
    void *a;
#endif
    if (Lencapsulatedp(nil, lib) == nil)
        return aerror("find-foreign-function");
#ifdef WIN32
    a = (HMODULE)extract_pointer(lib);
#else
    a = extract_pointer(lib);
#endif
    w = get_string_data(name, "find-foreign-function", &len);
    errexit();
    if (len > sizeof(sname)-2) len = sizeof(sname)-2;
    sprintf(sname, "%.*s", (int)len, w);
//
// Again I will leave the print statement in on a temporary basis...
//
#ifdef __CYGWIN__
    printf("name to look up = %s\r\n", sname);
#else
    printf("name to look up = %s\n", sname);
#endif
#ifdef WIN32
    b = (void *)GetProcAddress(a, sname);
#else
    b = dlsym(a, sname);
#endif
    if (b == NULL) return onevalue(nil);
    r = encapsulate_pointer(b);
    errexit();
    return onevalue(r);
}

//
// (call!-foreign!-function fnptr)
// call the function as found by find!-foreign!-function not passing it
// any arguments and not expecting any result.
//

LispObject Lcallf1(LispObject nil, LispObject entry)
{   void *f;
    if (Lencapsulatedp(nil, entry) == nil)
        return aerror("call-foreign-function");
    f = extract_pointer(entry);
    (*(void(*)())f)();
    return onevalue(nil);
}

//
// For calling foreign functions I need to know something of their type
// signature. The view I will take here is NOT guaranteed portable but
// is liable to work on many practical systems. I classify arguments that
// are actually passed as Int32, Int64 or Double. These are expected to
// be sufficiant for:
// Int32     int when sizeof(int)==4
//           char *, void * when sizeof(void *)==4, and hence "abcdef"
//           'x'
// Int64     int, long or long long when sizeof(.)==8
//           size_t if it has size 8
//           char *, void *, strings etc when size 8
// Double    double
//
// So the code that arranges to pass arguments will need to map from one of
// the intended types to one of the above three options. It could be that for
// some system that pointers and integers (of the relevant with) are passed in
// different locations or with different alignment constraints, but I believe
// that will not be the case on any system I am at present concerned with.
// Result types can be any of the above together with Void.
// As one further mess, a function signature can end with "..." and I use
// the pseudo-type VarArg to denote that.
//

#define Int32  0
#define Int64  1
#define Double 2
#define VarArg 3
//
// The ones that follow are only given as return types.
//
#define Void   4
#define String 5

#define A1(a1)             (a1)
#define A2(a1, a2)         ((a2)<<2 | (a1))
#define A3(a1, a2, a3)     ((a3)<<4 | (a2)<<2 | (a1))
#define A4(a1, a2, a3, a4) ((a4)<<6 | (a3)<<4 | (a2)<<2 | (a1))

#define MAX_ARGCOUNT 10
#define MAX_STRINGLEN 256

int32_t i32a[MAX_ARGCOUNT];
int64_t i64a[MAX_ARGCOUNT];
double da[MAX_ARGCOUNT];
char sa[MAX_ARGCOUNT][MAX_STRINGLEN];

int32_t i32r;
int64_t i64r;
double dr;

//
// This seems HORRID to me, and as it is it only supports passing up to three
// arguments. The alternatives that I can think of seem even worse!
// Well ACTUALLY I should change all of this to use "libffi" (which is subject
// to a generously liberal license and so will not cause problems in the
// BSD context I am working in). But it would be nice if somebody else did
// that conversion for me... since it should be a useful and self-contained
// task that would generalise and clean up the code but doing it would take
// me away from other things that I also want to do.
//

//
// Given a symbol (or in fact a string) this checks if its name is the
// same as the value given as arg2.
//
int name_matches(LispObject a, const char *s)
{   size_t len;
    const char *w = get_string_data(a, "call-foreign", &len);
    if (len == strlen(s) &&
        strncmp(w, s, len) == 0) return 1;
    else return 0;
}


LispObject callforeign(void *f, int returntype, int nargs, int signature)
{   LispObject nil = C_nil;
    int rt = (returntype == String) ?
             (sizeof(char *)==4 ? Int32 : Int64) :
             returntype;
    switch (rt)
    {   case Void:
            switch (nargs)
            {   case 0:
                    (*(void(*)())f)();
                    return onevalue(nil);
                case 1:
                    switch (signature)
                    {   case A1(Int32):
                            (*(void(*)(int32_t))f)(i32a[0]);
                            return onevalue(nil);
                        case A1(Int64):
                            (*(void(*)(int64_t))f)(i64a[0]);
                            return onevalue(nil);
                        case A1(Double):
                            (*(void(*)(double))f)(da[0]);
                            return onevalue(nil);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(Int32,Int32):
                            (*(void(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return onevalue(nil);
                        case A2(Int32,Int64):
                            (*(void(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return onevalue(nil);
                        case A2(Int32,Double):
                            (*(void(*)(int32_t,double))f)(i32a[0],da[1]);
                            return onevalue(nil);
                        case A2(Int64,Int32):
                            (*(void(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return onevalue(nil);
                        case A2(Int64,Int64):
                            (*(void(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return onevalue(nil);
                        case A2(Int64,Double):
                            (*(void(*)(int64_t,double))f)(i64a[0],da[1]);
                            return onevalue(nil);
                        case A2(Double,Int32):
                            (*(void(*)(double,int32_t))f)(da[0],i32a[1]);
                            return onevalue(nil);
                        case A2(Double,Int64):
                            (*(void(*)(double,int64_t))f)(da[0],i64a[1]);
                            return onevalue(nil);
                        case A2(Double,Double):
                            (*(void(*)(double,double))f)(da[0],da[1]);
                            return onevalue(nil);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(Int32,Int32,Int32):
                            (*(void(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int32,Int32,Int64):
                            (*(void(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Int32,Int32,Double):
                            (*(void(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return onevalue(nil);
                        case A3(Int32,Int64,Int32):
                            (*(void(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int32,Int64,Int64):
                            (*(void(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int32,Int64,Double):
                            (*(void(*)(int32_t,int64_t,double))f)(i32a[0],i64a[1],da[2]);
                            return onevalue(nil);
                        case A3(Int32,Double,Int32):
                            (*(void(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int32,Double,Int64):
                            (*(void(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int32,Double,Double):
                            (*(void(*)(int32_t,double,double))f)(i32a[0],da[1],da[2]);
                            return onevalue(nil);

                        case A3(Int64,Int32,Int32):
                            (*(void(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int64,Int32,Int64):
                            (*(void(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Int64,Int32,Double):
                            (*(void(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return onevalue(nil);
                        case A3(Int64,Int64,Int32):
                            (*(void(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int64,Int64,Int64):
                            (*(void(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Int64,Int64,Double):
                            (*(void(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return onevalue(nil);
                        case A3(Int64,Double,Int32):
                            (*(void(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Int64,Double,Int64):
                            (*(void(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Int64,Double,Double):
                            (*(void(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return onevalue(nil);

                        case A3(Double,Int32,Int32):
                            (*(void(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Double,Int32,Int64):
                            (*(void(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Double,Int32,Double):
                            (*(void(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return onevalue(nil);
                        case A3(Double,Int64,Int32):
                            (*(void(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Double,Int64,Int64):
                            (*(void(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Double,Int64,Double):
                            (*(void(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return onevalue(nil);
                        case A3(Double,Double,Int32):
                            (*(void(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return onevalue(nil);
                        case A3(Double,Double,Int64):
                            (*(void(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return onevalue(nil);
                        case A3(Double,Double,Double):
                            (*(void(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return onevalue(nil);
                        default:
                            break;
                    }
                    break;
            }
            break;
        case Int32:
            switch (nargs)
            {   case 0:
                    i32r = (*(int32_t(*)())f)();
                    return make_lisp_integer32(i32r);
                case 1:
                    switch (signature)
                    {   case A1(Int32):
                            i32r = (*(int32_t(*)(int32_t))f)(i32a[0]);
                            return make_lisp_integer32(i32r);
                        case A1(Int64):
                            i32r = (*(int32_t(*)(int64_t))f)(i64a[0]);
                            return make_lisp_integer32(i32r);
                        case A1(Double):
                            i32r = (*(int32_t(*)(double))f)(da[0]);
                            return make_lisp_integer32(i32r);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(Int32,Int32):
                            i32r = (*(int32_t(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Int32,Int64):
                            i32r = (*(int32_t(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Int32,Double):
                            i32r = (*(int32_t(*)(int32_t,double))f)(i32a[0],da[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Int64,Int32):
                            i32r = (*(int32_t(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Int64,Int64):
                            i32r = (*(int32_t(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Int64,Double):
                            i32r = (*(int32_t(*)(int64_t,double))f)(i64a[0],da[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Double,Int32):
                            i32r = (*(int32_t(*)(double,int32_t))f)(da[0],i32a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Double,Int64):
                            i32r = (*(int32_t(*)(double,int64_t))f)(da[0],i64a[1]);
                            return make_lisp_integer32(i32r);
                        case A2(Double,Double):
                            i32r = (*(int32_t(*)(double,double))f)(da[0],da[1]);
                            return make_lisp_integer32(i32r);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(Int32,Int32,Int32):
                            i32r = (*(int32_t(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Int32,Int64):
                            i32r = (*(int32_t(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Int32,Double):
                            i32r = (*(int32_t(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Int64,Int32):
                            i32r = (*(int32_t(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Int64,Int64):
                            i32r = (*(int32_t(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Int64,Double):
                            i32r = (*(int32_t(*)(int32_t,int64_t,double))f)(i32a[0],i64a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Double,Int32):
                            i32r = (*(int32_t(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Double,Int64):
                            i32r = (*(int32_t(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int32,Double,Double):
                            i32r = (*(int32_t(*)(int32_t,double,double))f)(i32a[0],da[1],da[2]);
                            return make_lisp_integer32(i32r);

                        case A3(Int64,Int32,Int32):
                            i32r = (*(int32_t(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Int32,Int64):
                            i32r = (*(int32_t(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Int32,Double):
                            i32r = (*(int32_t(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Int64,Int32):
                            i32r = (*(int32_t(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Int64,Int64):
                            i32r = (*(int32_t(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Int64,Double):
                            i32r = (*(int32_t(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Double,Int32):
                            i32r = (*(int32_t(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Double,Int64):
                            i32r = (*(int32_t(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Int64,Double,Double):
                            i32r = (*(int32_t(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return make_lisp_integer32(i32r);

                        case A3(Double,Int32,Int32):
                            i32r = (*(int32_t(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Int32,Int64):
                            i32r = (*(int32_t(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Int32,Double):
                            i32r = (*(int32_t(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Int64,Int32):
                            i32r = (*(int32_t(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Int64,Int64):
                            i32r = (*(int32_t(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Int64,Double):
                            i32r = (*(int32_t(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Double,Int32):
                            i32r = (*(int32_t(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Double,Int64):
                            i32r = (*(int32_t(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return make_lisp_integer32(i32r);
                        case A3(Double,Double,Double):
                            i32r = (*(int32_t(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return make_lisp_integer32(i32r);
                        default:
                            break;
                    }
                    break;
            }
            break;
        case Int64:
            switch (nargs)
            {   case 0:
                    i64r = (*(int64_t(*)())f)();
                    return make_lisp_integer64(i64r);
                case 1:
                    switch (signature)
                    {   case A1(Int32):
                            i64r = (*(int64_t(*)(int32_t))f)(i32a[0]);
                            return make_lisp_integer64(i64r);
                        case A1(Int64):
                            i64r = (*(int64_t(*)(int64_t))f)(i64a[0]);
                            return make_lisp_integer64(i64r);
                        case A1(Double):
                            i64r = (*(int64_t(*)(double))f)(da[0]);
                            return make_lisp_integer64(i64r);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(Int32,Int32):
                            i64r = (*(int64_t(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Int32,Int64):
                            i64r = (*(int64_t(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Int32,Double):
                            i64r = (*(int64_t(*)(int32_t,double))f)(i32a[0],da[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Int64,Int32):
                            i64r = (*(int64_t(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Int64,Int64):
                            i64r = (*(int64_t(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Int64,Double):
                            i64r = (*(int64_t(*)(int64_t,double))f)(i64a[0],da[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Double,Int32):
                            i64r = (*(int64_t(*)(double,int32_t))f)(da[0],i32a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Double,Int64):
                            i64r = (*(int64_t(*)(double,int64_t))f)(da[0],i64a[1]);
                            return make_lisp_integer64(i64r);
                        case A2(Double,Double):
                            i64r = (*(int64_t(*)(double,double))f)(da[0],da[1]);
                            return make_lisp_integer64(i64r);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(Int32,Int32,Int32):
                            i64r = (*(int64_t(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Int32,Int64):
                            i64r = (*(int64_t(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Int32,Double):
                            i64r = (*(int64_t(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Int64,Int32):
                            i64r = (*(int64_t(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Int64,Int64):
                            i64r = (*(int64_t(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Int64,Double):
                            i64r = (*(int64_t(*)(int32_t,int64_t,double))f)(i32a[0],i64a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Double,Int32):
                            i64r = (*(int64_t(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Double,Int64):
                            i64r = (*(int64_t(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int32,Double,Double):
                            i64r = (*(int64_t(*)(int32_t,double,double))f)(i32a[0],da[1],da[2]);
                            return make_lisp_integer64(i64r);

                        case A3(Int64,Int32,Int32):
                            i64r = (*(int64_t(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Int32,Int64):
                            i64r = (*(int64_t(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Int32,Double):
                            i64r = (*(int64_t(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Int64,Int32):
                            i64r = (*(int64_t(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Int64,Int64):
                            i64r = (*(int64_t(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Int64,Double):
                            i64r = (*(int64_t(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Double,Int32):
                            i64r = (*(int64_t(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Double,Int64):
                            i64r = (*(int64_t(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Int64,Double,Double):
                            i64r = (*(int64_t(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return make_lisp_integer64(i64r);

                        case A3(Double,Int32,Int32):
                            i64r = (*(int64_t(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Int32,Int64):
                            i64r = (*(int64_t(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Int32,Double):
                            i64r = (*(int64_t(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Int64,Int32):
                            i64r = (*(int64_t(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Int64,Int64):
                            i64r = (*(int64_t(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Int64,Double):
                            i64r = (*(int64_t(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Double,Int32):
                            i64r = (*(int64_t(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Double,Int64):
                            i64r = (*(int64_t(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return make_lisp_integer64(i64r);
                        case A3(Double,Double,Double):
                            i64r = (*(int64_t(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return make_lisp_integer64(i64r);
                        default:
                            break;
                    }
                    break;
            }
            break;
        case Double:
            switch (nargs)
            {   case 0:
                    dr = (*(double(*)())f)();
                    return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                case 1:
                    switch (signature)
                    {   case A1(Int32):
                            dr = (*(double(*)(int32_t))f)(i32a[0]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A1(Int64):
                            dr = (*(double(*)(int64_t))f)(i64a[0]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A1(Double):
                            dr = (*(double(*)(double))f)(da[0]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        default:
                            break;
                    }
                case 2:
                    switch (signature)
                    {   case A2(Int32,Int32):
                            dr = (*(double(*)(int32_t,int32_t))f)(i32a[0],i32a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Int32,Int64):
                            dr = (*(double(*)(int32_t,int64_t))f)(i32a[0],i64a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Int32,Double):
                            dr = (*(double(*)(int32_t,double))f)(i32a[0],da[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Int64,Int32):
                            dr = (*(double(*)(int64_t,int32_t))f)(i64a[0],i32a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Int64,Int64):
                            dr = (*(double(*)(int64_t,int64_t))f)(i64a[0],i64a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Int64,Double):
                            dr = (*(double(*)(int64_t,double))f)(i64a[0],da[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Double,Int32):
                            dr = (*(double(*)(double,int32_t))f)(da[0],i32a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Double,Int64):
                            dr = (*(double(*)(double,int64_t))f)(da[0],i64a[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A2(Double,Double):
                            dr = (*(double(*)(double,double))f)(da[0],da[1]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        default:
                            break;
                    }
                case 3:
                    switch (signature)
                    {   case A3(Int32,Int32,Int32):
                            dr = (*(double(*)(int32_t,int32_t,int32_t))f)(i32a[0],i32a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Int32,Int64):
                            dr = (*(double(*)(int32_t,int32_t,int64_t))f)(i32a[0],i32a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Int32,Double):
                            dr = (*(double(*)(int32_t,int32_t,double))f)(i32a[0],i32a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Int64,Int32):
                            dr = (*(double(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Int64,Int64):
                            dr = (*(double(*)(int32_t,int64_t,int64_t))f)(i32a[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Int64,Double):
                            dr = (*(double(*)(int32_t,int64_t,int32_t))f)(i32a[0],i64a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Double,Int32):
                            dr = (*(double(*)(int32_t,double,int32_t))f)(i32a[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Double,Int64):
                            dr = (*(double(*)(int32_t,double,int64_t))f)(i32a[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int32,Double,Double):
                            dr = (*(double(*)(int32_t,double,int32_t))f)(i32a[0],da[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);

                        case A3(Int64,Int32,Int32):
                            dr = (*(double(*)(int64_t,int32_t,int32_t))f)(i64a[0],i32a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Int32,Int64):
                            dr = (*(double(*)(int64_t,int32_t,int64_t))f)(i64a[0],i32a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Int32,Double):
                            dr = (*(double(*)(int64_t,int32_t,double))f)(i64a[0],i32a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Int64,Int32):
                            dr = (*(double(*)(int64_t,int64_t,int32_t))f)(i64a[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Int64,Int64):
                            dr = (*(double(*)(int64_t,int64_t,int64_t))f)(i64a[0],i64a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Int64,Double):
                            dr = (*(double(*)(int64_t,int64_t,double))f)(i64a[0],i64a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Double,Int32):
                            dr = (*(double(*)(int64_t,double,int32_t))f)(i64a[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Double,Int64):
                            dr = (*(double(*)(int64_t,double,int64_t))f)(i64a[0],da[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Int64,Double,Double):
                            dr = (*(double(*)(int64_t,double,double))f)(i64a[0],da[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);

                        case A3(Double,Int32,Int32):
                            dr = (*(double(*)(double,int32_t,int32_t))f)(da[0],i32a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Int32,Int64):
                            dr = (*(double(*)(double,int32_t,int64_t))f)(da[0],i32a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Int32,Double):
                            dr = (*(double(*)(double,int32_t,double))f)(da[0],i32a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Int64,Int32):
                            dr = (*(double(*)(double,int64_t,int32_t))f)(da[0],i64a[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Int64,Int64):
                            dr = (*(double(*)(double,int64_t,int64_t))f)(da[0],i64a[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Int64,Double):
                            dr = (*(double(*)(double,int64_t,double))f)(da[0],i64a[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Double,Int32):
                            dr = (*(double(*)(double,double,int32_t))f)(da[0],da[1],i32a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Double,Int64):
                            dr = (*(double(*)(double,double,int64_t))f)(da[0],da[1],i64a[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        case A3(Double,Double,Double):
                            dr = (*(double(*)(double,double,double))f)(da[0],da[1],da[2]);
                            return make_boxfloat(dr, TYPE_DOUBLE_FLOAT);
                        default:
                            break;
                    }
                    break;
            }
            break;
        default:
            break;
    }
    return aerror("Too many arguments for foreign function");
}

//
// For things with type-signatures involving "..." the only case I will
// support at present is "int f(const char *s,...)" which is of course the
// signature of printf. I will permit three arguments beyond the "char *" one.
//

LispObject callforeignvarargs(void *f, int returntype, int nargs, int signature)
{   const char *s;
    if (sizeof(const char *)==4) s = (const char *)(intptr_t)i32a[0];
    else s = (const char *)(intptr_t)i64a[0];
    switch (nargs)
    {   case 0:
            i32r = (*(int32_t(*)(const char *s,...))f)(s);
            return make_lisp_integer32(i32r);
        case 1:
            switch (signature)
            {   case A1(Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1]);
                    return make_lisp_integer32(i32r);
                case A1(Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1]);
                    return make_lisp_integer32(i32r);
                case A1(Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1]);
                    return make_lisp_integer32(i32r);
                default:
                    break;
            }
        case 2:
            switch (signature)
            {   case A2(Int32,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2]);
                    return make_lisp_integer32(i32r);
                case A2(Int32,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2]);
                    return make_lisp_integer32(i32r);
                case A2(Int32,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2]);
                    return make_lisp_integer32(i32r);
                case A2(Int64,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2]);
                    return make_lisp_integer32(i32r);
                case A2(Int64,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2]);
                    return make_lisp_integer32(i32r);
                case A2(Int64,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2]);
                    return make_lisp_integer32(i32r);
                case A2(Double,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2]);
                    return make_lisp_integer32(i32r);
                case A2(Double,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2]);
                    return make_lisp_integer32(i32r);
                case A2(Double,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2]);
                    return make_lisp_integer32(i32r);
                default:
                    break;
            }
        case 3:
            switch (signature)
            {   case A3(Int32,Int32,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Int32,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Int32,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i32a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Int64,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Int64,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Int64,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],i64a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Double,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Double,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int32,Double,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i32a[1],da[2],da[3]);
                    return make_lisp_integer32(i32r);

                case A3(Int64,Int32,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Int32,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Int32,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i32a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Int64,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Int64,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Int64,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],i64a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Double,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Double,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Int64,Double,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,i64a[1],da[2],da[3]);
                    return make_lisp_integer32(i32r);

                case A3(Double,Int32,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Int32,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Int32,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i32a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Int64,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Int64,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Int64,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],i64a[2],da[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Double,Int32):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2],i32a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Double,Int64):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2],i64a[3]);
                    return make_lisp_integer32(i32r);
                case A3(Double,Double,Double):
                    i32r = (*(int32_t(*)(const char *s,...))f)(s,da[1],da[2],da[3]);
                    return make_lisp_integer32(i32r);
                default:
                    break;
            }
            break;
    }
    return aerror("Too many arguments for foreign varargs function");
}

//
// The general scheme for call-foreign-function is as follows, where the
// key issue is that of the types of data passed and returned...
//
//    (call-foreign-function f)    call f with no args, ignoring any result
//    (call-foreign-function f a1)
//    (call-foreign-function f a1 a2)
//    (call-foreign-function f a1 a2 a3)
//    etc
// Each argument can be one of the following:
//    A symbol, where int32, int64, int, long, longlong, intptr and size
//    are the useful values. This specifies the way in which the next
//    argument (which should be an integer) will be passed. If there is no
//    further argument then the name can also possibly be void, string
//    or double and it indicates a return type.
//
//    An integer. This is passed as the next argument to the function
//    as a 32-bit integer unless a type was specified by the previous symbol.
//    A double-precision float. Passed to the function as the next argument.
//
//    A string. A C string is passed to the function. There will be a
//    limit on the length of string that can be passed this way.
//
//    A pair (sym . val) where sym can be one of
//        int int32 long int64 longlong intptr size string double
//    and val is something that can be mapped onto the matching type. The
//    purpose of this is so that whether an integer passed this way will be
//    32 or 64-bit can depend on the nature of the host system.
//
// The foreign function may only be provided with 0, 1, 2 or 3 arguments.
// At some stage I may need to find a way to be able to call functions that
// use va_arg style argument passing. But that is not worked out or
// implemented yet.
//

int dumparg(int i, LispObject type, LispObject value)
{   int typecode;
    size_t len;
    const char *w = get_string_data(type, "call-foreign-function", &len);
    if (len==5 && strncmp(w, "int32", 5)==0)
    {   i32a[i] = thirty_two_bits(value);
        typecode = Int32;
    }
    else if (len==3 && strncmp(w, "int", 3)==0)
    {   i32a[i] = thirty_two_bits(value);
        typecode = Int32;
    }
    else if (len==5 && strncmp(w, "int64", 5)==0)
    {   i64a[i] = sixty_four_bits(value);
        typecode = Int64;
    }
    else if (len==4 && strncmp(w, "long", 4)==0)
    {   if (sizeof(long)==4)
        {   i32a[i] = thirty_two_bits(value);
            typecode = Int32;
        }
        else
        {   i64a[i] = sixty_four_bits(value);
            typecode = Int64;
        }
    }
    else if (len==8 && strncmp(w, "longlong", 8)==0)
    {   i64a[i] = sixty_four_bits(value);
        typecode = Int64;
    }
    else if (len==4 && strncmp(w, "size", 4)==0)
    {   if (sizeof(size_t)==4)
        {   i32a[i] = thirty_two_bits(value);
            typecode = Int32;
        }
        else
        {   i64a[i] = sixty_four_bits(value);
            typecode = Int64;
        }
    }
    else if (len==6 && strncmp(w, "intptr", 6)==0)
    {   if (sizeof(intptr_t)==4)
        {   i32a[i] = thirty_two_bits(value);
            typecode = Int32;
        }
        else
        {   i64a[i] = sixty_four_bits(value);
            typecode = Int64;
        }
    }
    else if (len==6 && strncmp(w, "double", 6)==0)
    {   da[i] = float_of_number(value);
        typecode = Double;
    }
    else if (len==6 && strncmp(w, "string", 6)==0)
    {   w = get_string_data(value, "call-foreign-function", &len);
        memcpy(&sa[i][0], w, len);
        sa[i][len] = 0;
        if (sizeof(char *)==4)
        {   i32a[i] = (int32_t)(intptr_t)&sa[i][0];
            typecode = Int32;
        }
        else
        {   i64a[i] = (int64_t)(intptr_t)&sa[i][0];
            typecode = Int64;
        }
    }
    else
    {   i32a[i] = 0;
        typecode = Int32;
    }
    return typecode << (2*i);
}

LispObject Lcallfn(LispObject nil, int nargs, ...)
{   int i;
    LispObject w;
    void *f;
    int resulttype = Void, rtype, typemap = 0;
    LispObject currenttype = nil;
    va_list aa;
    for (i=0; i<MAX_ARGCOUNT; i++)
    {   i32a[i] = 0;
        i64a[i] = 0;
        da[i] = 0.0;
    }
    i = 0;  // Where to put next argument
    va_start(aa, nargs);
    w = va_arg(aa, LispObject);
    nargs--;
    if (Lencapsulatedp(nil, w) == nil)
        return aerror("call-foreign-function");
    f = extract_pointer(w);
    while (nargs > 0)
    {   nargs--;
        w = va_arg(aa, LispObject);
        if (is_cons(w))
        {   typemap |= dumparg(i, qcar(w), qcdr(w));
            i++;
            currenttype = nil;
        }
        else if (is_symbol(w))
        {   currenttype = w;
        }
        else if (is_fixnum(w) || is_numbers(w) ||
                 is_bfloat(w) || stringp(w))
        {   typemap |= dumparg(i, currenttype, w);
            i++;
            currenttype = nil;
        }
        else return aerror1("call-foreign-function", w);
    }
    va_end(aa);
//
// Now I need to call (*f)
//
    resulttype = Void;
    if (currenttype != nil)
    {   if (name_matches(currenttype, "int32")) resulttype = Int32;
        else if (name_matches(currenttype, "int64")) resulttype = Int64;
        else if (name_matches(currenttype, "int")) resulttype = Int32;
        else if (name_matches(currenttype, "long")) resulttype = sizeof(long)==4 ? Int32 : Int64;
        else if (name_matches(currenttype, "longlong")) resulttype = Int64;
        else if (name_matches(currenttype, "size")) resulttype = sizeof(size_t)==4 ? Int32 : Int64;
        else if (name_matches(currenttype, "intptr")) resulttype = sizeof(void *)==4 ? Int32 : Int64;
        else if (name_matches(currenttype, "double")) resulttype = Double;
        else if (name_matches(currenttype, "string")) resulttype = String;
        else if (name_matches(currenttype, "void")) resulttype = Void;
        else return aerror1("call-foreign-function", currenttype);
    }
    rtype = (resulttype == String) ? (sizeof(void *)==4 ? Int32 : Int64) :
            resulttype;
    w = callforeign(f, rtype, i, typemap);
    errexit();
    if (resulttype == String)
    {   char *s = (char *)(intptr_t)sixty_four_bits(w);
        w = make_string(s);
    }
    return onevalue(w);
}

LispObject Lcallf2(LispObject nil, LispObject entry, LispObject arg)
{   return Lcallfn(nil, 2, entry, arg);;
}

//
// It may be useful to pass callbacks into CSL to a foreign function so that
// they can be stored and used...
//

static LispObject Lget_callback(LispObject nil, LispObject a)
{   void *r = NULL;
    if (!is_fixnum(a)) return aerror("get_callback needs an integer arg");
    switch (int_of_fixnum(a))
    {   case  0:  r = (void *)execute_lisp_function;
            break;
        case  1:  r = (void *)PROC_set_callbacks;
            break;
        case  2:  r = (void *)PROC_load_package;
            break;
        case  3:  r = (void *)PROC_set_switch;
            break;
        case  4:  r = (void *)PROC_gc_messages;
            break;
        case  5:  r = (void *)PROC_clear_stack;
            break;
        case  6:  r = (void *)PROC_push_symbol;
            break;
        case  7:  r = (void *)PROC_push_string;
            break;
        case  8:  r = (void *)PROC_push_small_integer;
            break;
        case  9:  r = (void *)PROC_push_big_integer;
            break;
        case 10:  r = (void *)PROC_push_floating;
            break;
        case 11:  r = (void *)PROC_make_function_call;
            break;
        case 12:  r = (void *)PROC_save;
            break;
        case 13:  r = (void *)PROC_load;
            break;
        case 14:  r = (void *)PROC_dup;
            break;
        case 15:  r = (void *)PROC_pop;
            break;
        case 16:  r = (void *)PROC_simplify;
            break;
        case 17:  r = (void *)PROC_make_printable;
            break;
        case 18:  r = (void *)PROC_get_value;
            break;
        case 19:  r = (void *)PROC_atom;
            break;
        case 20:  r = (void *)PROC_null;
            break;
        case 21:  r = (void *)PROC_fixnum;
            break;
        case 22:  r = (void *)PROC_floatnum;
            break;
        case 23:  r = (void *)PROC_string;
            break;
        case 24:  r = (void *)PROC_symbol;
            break;
        case 25:  r = (void *)PROC_first;
            break;
        case 26:  r = (void *)PROC_rest;
            break;
        case 27:  r = (void *)PROC_integer_value;
            break;
        case 28:  r = (void *)PROC_floating_value;
            break;
        case 29:  r = (void *)PROC_symbol_name;
            break;
        case 30:  r = (void *)PROC_string_data;
            break;
        case 31:  r = (void *)PROC_lisp_eval;
            break;
        case 32:  r = (void *)PROC_get_raw_value;
            break;
    }
    return onevalue(make_lisp_integer64((LispObject)r));
}

setup_type const funcs1_setup[] =
{   {"acons",                   wrong_no_na, wrong_no_nb, Lacons},
    {"atom",                    Latom, too_many_1, wrong_no_1},
    {"boundp",                  Lboundp, too_many_1, wrong_no_1},

    {"car",                     Lcar, too_many_1, wrong_no_1},
    {"car*",                    Lcar_star, too_many_1, wrong_no_1},
    {"cdr",                     Lcdr, too_many_1, wrong_no_1},
    {"caar",                    Lcaar, too_many_1, wrong_no_1},
    {"cadr",                    Lcadr, too_many_1, wrong_no_1},
    {"cdar",                    Lcdar, too_many_1, wrong_no_1},
    {"cddr",                    Lcddr, too_many_1, wrong_no_1},
    {"caaar",                   Lcaaar, too_many_1, wrong_no_1},
    {"caadr",                   Lcaadr, too_many_1, wrong_no_1},
    {"cadar",                   Lcadar, too_many_1, wrong_no_1},
    {"caddr",                   Lcaddr, too_many_1, wrong_no_1},
    {"cdaar",                   Lcdaar, too_many_1, wrong_no_1},
    {"cdadr",                   Lcdadr, too_many_1, wrong_no_1},
    {"cddar",                   Lcddar, too_many_1, wrong_no_1},
    {"cdddr",                   Lcdddr, too_many_1, wrong_no_1},
    {"caaaar",                  Lcaaaar, too_many_1, wrong_no_1},
    {"caaadr",                  Lcaaadr, too_many_1, wrong_no_1},
    {"caadar",                  Lcaadar, too_many_1, wrong_no_1},
    {"caaddr",                  Lcaaddr, too_many_1, wrong_no_1},
    {"cadaar",                  Lcadaar, too_many_1, wrong_no_1},
    {"cadadr",                  Lcadadr, too_many_1, wrong_no_1},
    {"caddar",                  Lcaddar, too_many_1, wrong_no_1},
    {"cadddr",                  Lcadddr, too_many_1, wrong_no_1},
    {"cdaaar",                  Lcdaaar, too_many_1, wrong_no_1},
    {"cdaadr",                  Lcdaadr, too_many_1, wrong_no_1},
    {"cdadar",                  Lcdadar, too_many_1, wrong_no_1},
    {"cdaddr",                  Lcdaddr, too_many_1, wrong_no_1},
    {"cddaar",                  Lcddaar, too_many_1, wrong_no_1},
    {"cddadr",                  Lcddadr, too_many_1, wrong_no_1},
    {"cdddar",                  Lcdddar, too_many_1, wrong_no_1},
    {"cddddr",                  Lcddddr, too_many_1, wrong_no_1},

    {"qcar",                    Lcar, too_many_1, wrong_no_1},
    {"qcdr",                    Lcdr, too_many_1, wrong_no_1},
    {"qcaar",                   Lcaar, too_many_1, wrong_no_1},
    {"qcadr",                   Lcadr, too_many_1, wrong_no_1},
    {"qcdar",                   Lcdar, too_many_1, wrong_no_1},
    {"qcddr",                   Lcddr, too_many_1, wrong_no_1},

    {"bpsp",                    Lbpsp, too_many_1, wrong_no_1},
    {"codep",                   Lcodep, too_many_1, wrong_no_1},
    {"constantp",               Lconstantp, too_many_1, wrong_no_1},
    {"date",                    Ldate1, wrong_no_nb, Ldate},
    {"date-and-time",           Ldate_and_time1, wrong_no_nb, Ldate_and_time},
    {"datestamp",               wrong_no_na, wrong_no_nb, Ldatestamp},
    {"timeofday",               wrong_no_na, wrong_no_nb, Ltimeofday},
    {"enable-errorset",         too_few_2, Lenable_errorset, wrong_no_2},
    {"enable-backtrace",        Lenable_backtrace, too_many_1, wrong_no_1},
    {"error",                   Lerror1, Lerror2, Lerror},
    {"error1",                  wrong_no_na, wrong_no_nb, Lerror0},
#ifdef NAG
    {"unwind",                  wrong_no_na, wrong_no_nb, Lunwind},
#endif
    {"eq-safe",                 Leq_safe, too_many_1, wrong_no_1},
    {"fixp",                    Lfixp, too_many_1, wrong_no_1},
    {"floatp",                  Lfloatp, too_many_1, wrong_no_1},
    {"fluidp",                  Lsymbol_specialp, too_many_1, wrong_no_1},
    {"gctime",                  wrong_no_na, wrong_no_nb, Lgctime},
    {"globalp",                 Lsymbol_globalp, too_many_1, wrong_no_1},
    {"hash-table-p",            Lhash_table_p, too_many_1, wrong_no_1},
    {"indirect",                Lindirect, too_many_1, wrong_no_1},
    {"integerp",                Lintegerp, too_many_1, wrong_no_1},
    {"intersection",            too_few_2, Lintersect, wrong_no_2},
    {"list2",                   too_few_2, Llist2, wrong_no_2},
    {"list2*",                  wrong_no_na, wrong_no_nb, Llist2star},
    {"list3",                   wrong_no_na, wrong_no_nb, Llist3},
    {"list3*",                  wrong_no_na, wrong_no_nb, Llist3star},
    {"list4",                   wrong_no_na, wrong_no_nb, Llist4},
    {"make-global",             Lmake_global, too_many_1, wrong_no_1},
    {"make-special",            Lmake_special, too_many_1, wrong_no_1},
    {"mkquote",                 Lmkquote, too_many_1, wrong_no_1},
    {"ncons",                   Lncons, too_many_1, wrong_no_1},
    {"numberp",                 Lnumberp, too_many_1, wrong_no_1},
    {"pair",                    too_few_2, Lpair, wrong_no_2},
    {"protect-symbols",     Lprotect_symbols, too_many_1, wrong_no_1},
    {"protected-symbol-warn",   Lwarn_about_protected_symbols, too_many_1, wrong_no_1},
    {"put",                     wrong_no_na, wrong_no_nb, Lputprop},
    {"remprop",                 too_few_2, Lremprop, wrong_no_2},
    {"representation",          Lrepresentation1, Lrepresentation2, wrong_no_2},
    {"rplaca",                  too_few_2, Lrplaca, wrong_no_2},
    {"rplacd",                  too_few_2, Lrplacd, wrong_no_2},
    {"set",                     too_few_2, Lset, wrong_no_2},
    {"makeunbound",             Lmakeunbound, too_many_1, wrong_no_1},
    {"special-form-p",          Lspecial_form_p, too_many_1, wrong_no_1},
    {"stop",                    Lstop, Lstop2, Lstop0},
    {"symbol-function",         Lsymbol_function, too_many_1, wrong_no_1},
    {"symbol-value",            Lsymbol_value, too_many_1, wrong_no_1},
    {"time",                    wrong_no_na, wrong_no_nb, Ltime},
    {"datelessp",               too_few_2, Ldatelessp, wrong_no_2},
    {"union",                   too_few_2, Lunion, wrong_no_2},
    {"unmake-global",           Lunmake_global, too_many_1, wrong_no_1},
    {"unmake-special",          Lunmake_special, too_many_1, wrong_no_1},
    {"xcons",                   too_few_2, Lxcons, wrong_no_2},
// I provide both IDP and SYMBOLP in both modes...
    {"symbolp",                 Lsymbolp, too_many_1, wrong_no_1},
    {"idp",                     Lsymbolp, too_many_1, wrong_no_1},
// I support the Common Lisp names here in both modes
    {"simple-string-p",         Lstringp, too_many_1, wrong_no_1},
    {"simple-vector-p",         Lsimple_vectorp, too_many_1, wrong_no_1},
    {"get-decoded-time",        wrong_no_0a, wrong_no_0b, Ldecoded_time},
    {"short-floatp",            Lshort_floatp, too_many_1, wrong_no_1},
    {"single-floatp",           Lsingle_floatp, too_many_1, wrong_no_1},
    {"double-floatp",           Ldouble_floatp, too_many_1, wrong_no_1},
    {"long-floatp",             Llong_floatp, too_many_1, wrong_no_1},
    {"rationalp",               Lrationalp, too_many_1, wrong_no_1},
    {"complexp",                Lcomplexp, too_many_1, wrong_no_1},
    {"bit-vector-p",            Lsimple_bit_vector_p, too_many_1, wrong_no_1},
    {"simple-bit-vector-p",     Lsimple_bit_vector_p, too_many_1, wrong_no_1},
#ifdef COMMON
    {"fill-vector",             wrong_no_na, wrong_no_nb, Lfill_vector},
    {"get",                     too_few_2, Lget, Lget_3},
    {"arrayp",                  Larrayp, too_many_1, wrong_no_1},
    {"complex-arrayp",          Lcomplex_arrayp, too_many_1, wrong_no_1},
    {"consp",                   Lconsp, too_many_1, wrong_no_1},
    {"convert-to-array",        Lconvert_to_array, too_many_1, wrong_no_1},
    {"convert-to-struct",       Lconvert_to_struct, too_many_1, wrong_no_1},
    {"identity",                Lidentity, too_many_1, wrong_no_1},
    {"list",                    Lncons, Llist2, Llist},
    {"list*",                   Lidentity, Lcons, Lliststar},
    {"listp",                   Llistp, too_many_1, wrong_no_1},
    {"stringp",                 Lc_stringp, too_many_1, wrong_no_1},
    {"structp",                 Lstructp, too_many_1, wrong_no_1},
    {"flag",                    too_few_2, Lflag, wrong_no_2},
    {"flagp",                   too_few_2, Lflagp, wrong_no_2},
    {"flagpcar",                too_few_2, Lflagpcar, wrong_no_2},
    {"remflag",                 too_few_2, Lremflag, wrong_no_2},
    {"time*",                   wrong_no_na, wrong_no_nb, Ltime},
#else
    {"get",                     too_few_2, Lget, wrong_no_2},
    {"convert-to-evector",      Lconvert_to_struct, too_many_1, wrong_no_1},
    {"evectorp",                Lstructp, too_many_1, wrong_no_1},
    {"get*",                    too_few_2, Lget, wrong_no_2},
    {"pairp",                   Lconsp, too_many_1, wrong_no_1},
// I provide CONSP as well as PAIRP since otherwise I get muddled
    {"consp",                   Lconsp, too_many_1, wrong_no_1},
    {"flag",                    too_few_2, Lflag, wrong_no_2},
    {"flagp",                   too_few_2, Lflagp, wrong_no_2},
    {"flagpcar",                too_few_2, Lflagpcar, wrong_no_2},
    {"flagp**",                 too_few_2, Lflagp, wrong_no_2},
    {"remflag",                 too_few_2, Lremflag, wrong_no_2},
    {"stringp",                 Lstringp, too_many_1, wrong_no_1},
    {"threevectorp",            Lthreevectorp, too_many_1, wrong_no_1},
    {"throw",                   Lthrow_nil, Lthrow_one_value, wrong_no_2},
    {"vectorp",                 Lsimple_vectorp, too_many_1, wrong_no_1},
#endif
    {"open-foreign-library",    Lopen_foreign_library, too_many_1, wrong_no_1},
    {"find-foreign-function",   too_few_2, Lfind_foreign_function, wrong_no_2},
    {"call-foreign-function",   Lcallf1, Lcallf2, Lcallfn},
    {"get-callback",            Lget_callback, too_many_1, wrong_no_1},
    {NULL,                      0, 0, 0}
};

// end of fns1.cpp