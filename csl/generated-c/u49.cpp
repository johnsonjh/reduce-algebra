
// $destdir/u49.c        Machine generated C code

// $Id$

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#include <setjmp.h>
#include <exception>
#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
extern "C"
{
#include "softfloat.h"
}
#if !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#ifdef HAVE_STDINT_H
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
typedef intptr_t LispObject;
#define CELL ((size_t)sizeof(LispObject))
#define TAG_BITS 7
#define XTAG_BITS 15
#define TAG_CONS 0 
#define TAG_VECTOR 1 
#define TAG_HDR_IMMED 2 
#define TAG_FORWARD 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_BOXFLOAT 6 
#define TAG_FIXNUM 7 
#define TAG_XBIT 8 
#define XTAG_SFLOAT 15 
#define XTAG_FLOAT32 16
#define is_forward(p) ((((int)(p)) & TAG_BITS) == TAG_FORWARD)
#define is_number(p) ((((int)(p)) & TAG_BITS) >= TAG_NUMBERS)
#define is_float(p) (((0xc040 >> (((int)(p)) & XTAG_BITS)) & 1) != 0)
#define is_immed_or_cons(p) (((0x85 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define is_immed_cons_sym(p) (((0x95 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define need_more_than_eq(p) (((0x63 >> (((int)(p)) & TAG_BITS)) & 1) != 0)
#define fixnum_of_int(x) ((LispObject)((((uintptr_t)(x))<<4)+TAG_FIXNUM))
#define int_of_fixnum(x) (((intptr_t)(x) & ~(intptr_t)15)/16)
#define valid_as_fixnum(x) (int_of_fixnum(fixnum_of_int(x)) == (x))
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED) 
#define is_sfloat(p) ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#define car_legal(p) is_cons(p)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
} Cons_Cell;
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject no_args(LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef LispObject four_args(LispObject, size_t, LispObject, LispObject,
 LispObject, LispObject);
typedef uintptr_t Header;
#define Tw (3)
#define header_mask (0x7f<<Tw)
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) ((((size_t)(h)) >> (Tw+7)) << 2)
#define length_of_bitheader(h) ((((size_t)(h)) >> (Tw+2)) - 31)
#define length_of_byteheader(h) ((((size_t)(h)) >> (Tw+5)) - 3)
#define length_of_hwordheader(h) ((((size_t)(h)) >> (Tw+6)) - 1)
#define bitvechdr_(n) (TYPE_BITVEC_1 + ((((n)+31)&31)<<(Tw+2)))
#define TYPE_SYMBOL 0x00000000 
#define SYM_SPECIAL_VAR 0x00000080 
#define SYM_FLUID_VAR 0x00000080 
#define SYM_GLOBAL_VAR 0x00000100 
#define SYM_KEYWORD_VAR 0x00000180 
#define SYM_SPECIAL_FORM 0x00000200 
#define SYM_MACRO 0x00000400 
#define SYM_C_DEF 0x00000800 
#define SYM_CODEPTR 0x00001000 
#define SYM_ANY_GENSYM 0x00002000 
#define SYM_TRACED 0x00004000 
#define SYM_TRACESET 0x00008000 
#define SYM_TAGGED 0x00010000 
#define SYM_FASTGET_MASK 0x007e0000 
#define SYM_FASTGET_SHIFT 17
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00800000 
#define SYM_IN_PACKAGE 0xff000000U 
#define SYM_IN_PKG_SHIFT 24
#define SYM_IN_PKG_COUNT 8
#else 
#define SYM_UNPRINTED_GENSYM 0x00800000 
#endif 
#define symhdr_length (doubleword_align_up(sizeof(Symbol_Head)))
#define is_symbol_header(h) (((int)h & (0xf<<Tw)) == TYPE_SYMBOL)
#define is_symbol_header_full_test(h) \
 (((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED))
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define is_number_header_full_test(h) \
 (((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED))
#define is_vector_header_full_test(h) \
 (is_odds(h) && (((int)h & (0x3<<Tw)) != 0))
#define is_array_header(h) (type_of_header(h) == TYPE_ARRAY)
#define vector_i8(h) (((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i16(h) (((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i32(h) (((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i64(h) (((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_i128(h) (((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f32(h) (((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f64(h) (((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define vector_f128(h) (((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x1d <<Tw)
#define TYPE_COMPLEX_NUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define is_string_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1)
#define is_string(n) is_string_header(vechdr(n))
#define is_vec8_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1)
#define is_vec8(n) is_vec8_header(vechdr(n))
#define is_bps_header(h) ((type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1)
#define is_bps(n) is_bps_header(vechdr(n))
#define is_vec16_header(h) ((type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1)
#define is_vec16(n) is_vec16_header(vechdr(n))
#define is_bitvec_header(h) ((type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1)
#define is_bitvec(n) is_bitvec_header(vechdr(n))
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
 (CELL-TAG_VECTOR) + \
 (((intptr_t)(n))*sizeof(LispObject))))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define data_of_bps(v) ((unsigned char *)(v) + (CELL-TAG_VECTOR))
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
#define vselt(v, n) (*(LispObject *)(((intptr_t)(v) & ~((intptr_t)TAG_BITS)) + \
 ((1 + (intptr_t)(n))*sizeof(LispObject))))
#define helt(v, n) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)))
#define sethelt(v, n, x) (*(int16_t *)((char *)(v) + \
 (CELL-TAG_VECTOR) + ((intptr_t)(n))*sizeof(int16_t)) = (x))
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(intptr_t))))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(int32_t))))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(float))))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))*sizeof(double))))
#define TYPE_BITVEC_1 ( 0x02 <<Tw) 
#define TYPE_BITVEC_2 ( 0x06 <<Tw) 
#define TYPE_BITVEC_3 ( 0x0a <<Tw) 
#define TYPE_BITVEC_4 ( 0x0c <<Tw) 
#define TYPE_BITVEC_5 ( 0x12 <<Tw) 
#define TYPE_BITVEC_6 ( 0x16 <<Tw) 
#define TYPE_BITVEC_7 ( 0x1a <<Tw) 
#define TYPE_BITVEC_8 ( 0x1c <<Tw) 
#define TYPE_BITVEC_9 ( 0x22 <<Tw) 
#define TYPE_BITVEC_10 ( 0x26 <<Tw) 
#define TYPE_BITVEC_11 ( 0x2a <<Tw) 
#define TYPE_BITVEC_12 ( 0x2c <<Tw) 
#define TYPE_BITVEC_13 ( 0x32 <<Tw) 
#define TYPE_BITVEC_14 ( 0x36 <<Tw) 
#define TYPE_BITVEC_15 ( 0x3a <<Tw) 
#define TYPE_BITVEC_16 ( 0x3c <<Tw) 
#define TYPE_BITVEC_17 ( 0x42 <<Tw) 
#define TYPE_BITVEC_18 ( 0x46 <<Tw) 
#define TYPE_BITVEC_19 ( 0x4a <<Tw) 
#define TYPE_BITVEC_20 ( 0x4c <<Tw) 
#define TYPE_BITVEC_21 ( 0x52 <<Tw) 
#define TYPE_BITVEC_22 ( 0x56 <<Tw) 
#define TYPE_BITVEC_23 ( 0x5a <<Tw) 
#define TYPE_BITVEC_24 ( 0x5c <<Tw) 
#define TYPE_BITVEC_25 ( 0x62 <<Tw) 
#define TYPE_BITVEC_26 ( 0x66 <<Tw) 
#define TYPE_BITVEC_27 ( 0x6a <<Tw) 
#define TYPE_BITVEC_28 ( 0x6c <<Tw) 
#define TYPE_BITVEC_29 ( 0x72 <<Tw) 
#define TYPE_BITVEC_30 ( 0x76 <<Tw) 
#define TYPE_BITVEC_31 ( 0x7a <<Tw) 
#define TYPE_BITVEC_32 ( 0x7c <<Tw) 
#define TYPE_STRING_1 ( 0x07 <<Tw) 
#define TYPE_STRING_2 ( 0x27 <<Tw) 
#define TYPE_STRING_3 ( 0x47 <<Tw) 
#define TYPE_STRING_4 ( 0x67 <<Tw) 
#define TYPE_VEC8_1 ( 0x03 <<Tw) 
#define TYPE_VEC8_2 ( 0x23 <<Tw) 
#define TYPE_VEC8_3 ( 0x43 <<Tw) 
#define TYPE_VEC8_4 ( 0x63 <<Tw) 
#define TYPE_BPS_1 ( 0x0b <<Tw) 
#define TYPE_BPS_2 ( 0x2b <<Tw) 
#define TYPE_BPS_3 ( 0x4b <<Tw) 
#define TYPE_BPS_4 ( 0x6b <<Tw) 
#define TYPE_VEC16_1 ( 0x0f <<Tw) 
#define TYPE_VEC16_2 ( 0x4f <<Tw) 
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#define TYPE_FOREIGN ( 0x33 <<Tw) 
#define TYPE_SP ( 0x37 <<Tw) 
#define TYPE_ENCAPSULATE ( 0x3b <<Tw) 
#define vector_holds_binary(h) (((h) & (0x2<<Tw)) != 0)
#define TYPE_SIMPLE_VEC ( 0x01 <<Tw) 
#define TYPE_INDEXVEC ( 0x11 <<Tw) 
#define TYPE_NEWHASH ( 0x15 <<Tw) 
#define TYPE_NEWHASHX ( 0x19 <<Tw) 
#define TYPE_HASH ( 0x21 <<Tw) 
#define TYPE_ARRAY ( 0x05 <<Tw) 
#define TYPE_STRUCTURE ( 0x09 <<Tw) 
#define TYPE_OBJECT ( 0x0d <<Tw) 
#define TYPE_VEC32 ( 0x13 <<Tw) 
#define TYPE_VEC64 ( 0x17 <<Tw) 
#define TYPE_VEC128 ( 0x1b <<Tw) 
#define TYPE_VECFLOAT32 ( 0x53 <<Tw) 
#define TYPE_VECFLOAT64 ( 0x57 <<Tw) 
#define TYPE_VECFLOAT128 ( 0x5b <<Tw) 
#define is_mixed_header(h) (((h) & (0x73<<Tw)) == TYPE_MIXED1)
#define TYPE_MIXED1 ( 0x41 <<Tw) 
#define TYPE_MIXED2 ( 0x45 <<Tw) 
#define TYPE_MIXED3 ( 0x49 <<Tw) 
#define TYPE_STREAM ( 0x4d <<Tw) 
#define VIRTUAL_TYPE_CONS ( 0x7d <<Tw) 
#define HDR_IMMED_MASK (( 0xf <<Tw) | TAG_BITS)
#define TAG_CHAR (( 0x4 <<Tw) | TAG_HDR_IMMED) 
#define TAG_SPID (( 0xc <<Tw) | TAG_HDR_IMMED) 
#define SPID_NIL (TAG_SPID+(0x00<<(Tw+4))) 
#define SPID_FBIND (TAG_SPID+(0x01<<(Tw+4))) 
#define SPID_CATCH (TAG_SPID+(0x02<<(Tw+4))) 
#define SPID_PROTECT (TAG_SPID+(0x03<<(Tw+4))) 
#define SPID_HASHEMPTY (TAG_SPID+(0x04<<(Tw+4))) 
#define SPID_HASHTOMB (TAG_SPID+(0x05<<(Tw+4))) 
#define SPID_GCMARK (TAG_SPID+(0x06<<(Tw+4))) 
#define SPID_NOINPUT (TAG_SPID+(0x07<<(Tw+4))) 
#define SPID_ERROR (TAG_SPID+(0x08<<(Tw+4))) 
#define SPID_PVBIND (TAG_SPID+(0x09<<(Tw+4))) 
#define SPID_NOARG (TAG_SPID+(0x0a<<(Tw+4))) 
#define SPID_NOPROP (TAG_SPID+(0x0b<<(Tw+4))) 
#define SPID_LIBRARY (TAG_SPID+(0x0c<<(Tw+4))) 
#define is_header(x) (((int)(x) & (0x3<<Tw)) != 0) 
#define is_char(x) (((int)(x) & HDR_IMMED_MASK) == TAG_CHAR)
#define is_spid(x) (((int)(x) & HDR_IMMED_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xfffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> (21+4+Tw)) & 0xf)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> (4+Tw)) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << (21+4+Tw)) | \
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject package; 
 LispObject pname; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 union {
 intptr_t functionn; 
 intptr_t function4; 
 intptr_t function5up;
 };
 uint64_t count; 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#define qheader(p) (*(Header *)((char *)(p) + (0*CELL-TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)((char *)(p) + (1*CELL-TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)((char *)(p) + (2*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define qpackage(p) (*(LispObject *)((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define ifn0(p) (*(intptr_t *)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define ifn1(p) (*(intptr_t *)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define ifn3(p) (*(intptr_t *)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define ifn4(p) (*(intptr_t *)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn0(p) (*(no_args **)((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfn1(p) (*(one_args **)((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qfn2(p) (*(two_args **)((char *)(p) + (9*CELL-TAG_SYMBOL)))
#define qfn3(p) (*(three_args **)((char *)(p) + (10*CELL-TAG_SYMBOL)))
#define qfnn(p) (*(n_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qfn4(p) (*(four_args **)((char *)(p) + (11*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uint64_t *)((char *)(p) + (12*CELL-TAG_SYMBOL)))
typedef union Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
#define low32(a) ((LispObject)(uint32_t)(a))
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#define bignum_digits(b) \
 ((uint32_t *)((char *)(b) + (CELL-TAG_NUMBERS)))
#define bignum_digits64(b, n) \
 ((int64_t)((int32_t *)((char *)(b)+(CELL-TAG_NUMBERS)))[n])
#define make_bighdr(n) (TAG_HDR_IMMED+TYPE_BIGNUM+(((intptr_t)(n))<<(Tw+7)))
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
#define make_padder(n) (pack_hdrlength((n)/4) + TYPE_VEC8_1 + TAG_HDR_IMMED)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define float32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f32)
#define intfloat32_t_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.i)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float64_t_val(v) (*(float64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat64_t_val(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 24
#define long_float_addr(v) ((float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_pad(v) (*(int32_t *)((char *)(v) + \
 (4-TAG_BOXFLOAT)))
#define long_float_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define float128_t_val(v) (*(float128_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val0(v) (*(int64_t *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define intfloat128_t_val1(v) (*(int64_t *)((char *)(v) + \
 (16-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((uintptr_t)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((uintptr_t)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((uintptr_t)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_SIGNAL 0x6 
#define UNWIND_SIGINT 0x7 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#define MAXSHIFT(n, a) ((n) >= (int)(8*sizeof(a)) || (n) < 0 ? 0 : (n))
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
#define ASR(a, n) ((a) >> MAXSHIFT((n), a))
#else 
#include <type_traits>
template <typename T>
static inline T ASR(T a, int n)
{ typedef typename std::make_signed<T>::type ST;
 return ((ST)(a&~(((T)1<<MAXSHIFT(n,T))-1)))/((ST)1<<MAXSHIFT(n,T));
}
#endif 
#define ASL32(a,n) ((int32_t)((uint32_t)(a)<<MAXSHIFT((n),uint32_t)))
#define ASLptr(a,n) ((intptr_t)((uintptr_t)(a)<<MAXSHIFT((n),uintptr_t)))
#define ASL64(a,n) ((int64_t)((uint64_t)(a)<<MAXSHIFT((n),uint64_t)))
#define ASL128(a,n) ((int128_t)((uint128_t)(a)<<MAXSHIFT((n),uint128_t)))
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" NORETURN void error(int nargs, int code, ...);
extern "C" NORETURN void cerror(int nargs, int code1, int code2, ...);
extern "C" NORETURN void too_few_2(LispObject env, LispObject a1);
extern "C" NORETURN void too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_0a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_3a(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_na(LispObject env, LispObject a1);
extern "C" NORETURN void wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" NORETURN void wrong_no_1(LispObject env, int nargs, ...);
extern "C" NORETURN void wrong_no_2(LispObject env, int nargs, ...);
extern "C" NORETURN void bad_specialn(LispObject env, int nargs, ...);
#define TOO_FEW_2 ((one_args *)too_few_2)
#define TOO_MANY_1 ((two_args *)too_many_1)
#define WRONG_NO_0A ((one_args *)wrong_no_0a)
#define WRONG_NO_0B ((two_args *)wrong_no_0b)
#define WRONG_NO_3A ((one_args *)wrong_no_3a)
#define WRONG_NO_3B ((two_args *)wrong_no_3b)
#define WRONG_NO_NA ((one_args *)wrong_no_na)
#define WRONG_NO_NB ((two_args *)wrong_no_nb)
#define WRONG_NO_1 ((n_args *)wrong_no_1)
#define WRONG_NO_2 ((n_args *)wrong_no_2)
#define BAD_SPECIALN ((n_args *)bad_specialn)
extern "C" NORETURN void aerror(const char *s); 
extern "C" NORETURN void aerror0(const char *s);
extern "C" NORETURN void aerror1(const char *s, LispObject a);
extern "C" NORETURN void aerror2(const char *s, LispObject a, LispObject b);
extern "C" NORETURN void fatal_error(int code, ...);
extern "C" LispObject carerror(LispObject a);
extern "C" LispObject cdrerror(LispObject a);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_0 3 
#define err_undefined_function_1 4 
#define err_undefined_function_2 5 
#define err_undefined_function_3 6 
#define err_undefined_function_4 7 
#define err_undefined_function_n 7 
#define err_wrong_no_args 8 
#define err_unbound_lexical 9 
#define err_bad_rplac 10 
#define err_bad_arith 11 
#define err_redef_special 12 
#define err_bad_arg 13 
#define err_bad_declare 14 
#define err_bad_fn 15 
#define err_unset_var 16 
#define err_too_many_args0 17 
#define err_too_many_args1 18 
#define err_too_many_args2 19 
#define err_too_many_args3 20 
#define err_bad_apply 21 
#define err_macroex_hook 22 
#define err_block_tag 23 
#define err_go_tag 24 
#define err_excess_args 25
#define err_insufficient_args 26
#define err_bad_bvl 27 
#define err_bad_keyargs 28
#define err_write_err 29
#define err_bad_endp 30 
#define err_no_fasldir 31
#define err_no_fasl 32 
#define err_open_failed 33 
#define err_pipe_failed 34 
#define err_stack_overflow 35
#define err_top_bit 36
#define err_mem_spans_zero 37
#define err_no_longer_used 38 
#define err_no_tempdir 39
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
 "attempt to take cdr of an atom",
 "insufficient freestore to run this package",
 "undefined function (0 arg)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 arg)",
 "undefined function", 
 "wrong number of arguments",
 "unbound lexical variable",
 "bad rplaca/rplacd",
 "bad argument for an arithmetic function",
 "attempt to redefine a special form",
 "not a variable",
 "bad use of declare",
 "attempt to apply non-function",
 "unset variable",
 "too many arguments for 0-arg function",
 "too many arguments for 1-arg function",
 "too many arguments for 2-arg function",
 "too many arguments for 3-arg function",
 "object not valid as a function (apply,",
 "macroexpand-hook failure",
 "block tag not found",
 "go tag not found",
 "too many arguments provided",
 "not enough arguments provided",
 "bad item in bound variable list",
 "bad keyword arguments",
 "write-error on file",
 "endp used on badly terminated list",
 "environment parameter 'fasldir' not set",
 "loadable module not found for loading",
 "file could not be opened",
 "unable to establish pipe",
 "stack overflow",
 "top bit of address has unexpected value",
 "memory block spans the zero address",
 "this error code available for re-use",
 "unable to find a directory for temporary files",
 "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
 fflush(stderr); \
 } while (0)
#define DS(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
 fflush(stderr); \
 } while (0)
#define DX(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
 (long long unsigned)(s)); \
 fflush(stderr); \
 } while (0)
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
typedef struct page_map_t
{ void *start;
 void *end;
 int type;
} page_map_t;
#endif
extern int32_t pages_count, heap_pages_count, vheap_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *stack;
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern bool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *_p_ = (char *)&_p_; \
 if (_p_ < C_stack_limit) aerror("stack overflow"); \
 }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
 if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 }
extern LispObject nil;
#define first_nil_offset 50 
#define work_0_offset 250
#define last_nil_offset 301
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
extern intptr_t byteflip;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern unsigned int exit_count;
extern uint64_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table, progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject big_divisor, big_dividend, big_quotient;
extern LispObject big_fake1, big_fake2, active_stream, current_module;
extern LispObject mv_call_symbol, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject startup_symbol, mv_call_symbol, traceprint_symbol;
extern LispObject load_source_symbol, load_selected_source_symbol;
extern LispObject bytecoded_symbol, funcall_symbol, autoload_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, current_function, keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol, expand_def_symbol, allow_key_key;
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
extern LispObject nicknames_symbol, use_symbol, and_symbol, or_symbol;
extern LispObject not_symbol, reader_workspace, named_character;
extern LispObject read_float_format, short_float, single_float, double_float;
extern LispObject long_float, bit_symbol, pathname_symbol, print_array_sym;
extern LispObject read_base, initial_element;
extern LispObject builtin0_symbol, builtin1_symbol, builtin2_symbol;
extern LispObject builtin3_symbol, builtin4_symbol; 
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, int nargs, ...);
extern LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject env, LispObject ldev);
extern LispObject om_putEndApp(LispObject env, LispObject ldev);
extern LispObject om_putAtp(LispObject env, LispObject ldev);
extern LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern LispObject om_putAttr(LispObject env, LispObject ldev);
extern LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern LispObject om_putBind(LispObject env, LispObject ldev);
extern LispObject om_putEndBind(LispObject env, LispObject ldev);
extern LispObject om_putBVar(LispObject env, LispObject ldev);
extern LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern LispObject om_putError(LispObject env, LispObject ldev);
extern LispObject om_putEndError(LispObject env, LispObject ldev);
extern LispObject om_putObject(LispObject env, LispObject ldev);
extern LispObject om_putEndObject(LispObject env, LispObject ldev);
extern LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern LispObject om_getApp(LispObject env, LispObject ldev);
extern LispObject om_getEndApp(LispObject env, LispObject ldev);
extern LispObject om_getAtp(LispObject env, LispObject ldev);
extern LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern LispObject om_getAttr(LispObject env, LispObject ldev);
extern LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern LispObject om_getBind(LispObject env, LispObject ldev);
extern LispObject om_getEndBind(LispObject env, LispObject ldev);
extern LispObject om_getBVar(LispObject env, LispObject ldev);
extern LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern LispObject om_getError(LispObject env, LispObject ldev);
extern LispObject om_getEndError(LispObject env, LispObject ldev);
extern LispObject om_getObject(LispObject env, LispObject ldev);
extern LispObject om_getEndObject(LispObject env, LispObject ldev);
extern LispObject om_getInt(LispObject env, LispObject ldev);
extern LispObject om_getFloat(LispObject env, LispObject ldev);
extern LispObject om_getByteArray(LispObject env, LispObject ldev);
extern LispObject om_getVar(LispObject env, LispObject ldev);
extern LispObject om_getString(LispObject env, LispObject ldev);
extern LispObject om_getSymbol(LispObject env, LispObject ldev);
extern LispObject om_getType(LispObject env, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern LispObject om_read(LispObject env, LispObject dev);
extern LispObject om_supportsCD(LispObject env, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject env, int nargs, ...);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define work_50 workbase[50]
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
#define LOG2_VECTOR_CHUNK_WORDS 17
#define VECTOR_CHUNK_WORDS ((size_t)(1<<LOG2_VECTOR_CHUNK_WORDS)) 
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_WORDS+1];
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern LispObject eq_hash_tables, equal_hash_tables;
extern uint32_t hash_equal(LispObject key);
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
extern bool garbage_collection_permitted;
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern size_t output_directory;
extern LispObject *repeat_heap;
extern size_t repeat_count;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern FILE *binary_write_file;
extern size_t boffop;
extern void packcharacter(int c);
extern void packbyte(int c);
#define boffo_char(i) ucelt(boffo, i)
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#ifdef SOCKETS
extern bool sockets_ready;
extern void flush_socket();
#endif
extern void report_file(const char *s);
extern bool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern size_t number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths;
extern int init_flags;
extern const char *standard_directory;
extern int gc_number;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
#define CODESIZE 0x1000
typedef struct _entry_point0
{ no_args *p;
 const char *s;
} entry_point0;
typedef struct _entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct _entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct _entry_point3
{ three_args *p;
 const char *s;
} entry_point3;
typedef struct _entry_point4
{ four_args *p;
 const char *s;
} entry_point4;
typedef struct _entry_pointn
{ n_args *p;
 const char *s;
} entry_pointn;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4 entries_table4[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_tableio[];
extern void set_up_entry_lookup();
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit();
extern void IreInit();
extern void Ilist();
extern bool open_output(const char *s, size_t len);
#define IMAGE_CODE ((size_t)(-1000))
#define HELP_CODE ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))
#define IOPEN_OUT 0
#define IOPEN_IN 1
extern bool Iopen(const char *name, size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep(const char *name, size_t len, char *datestamp,
 size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, size_t *lenp);
extern bool Icopy(const char *name, size_t len);
extern bool Idelete(const char *name, size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int Igetc();
extern bool Iread(void *buff, size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int Zgetc();
extern bool Zread(void *buff, size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen();
extern int window_heading;
extern void my_abort();
extern "C" NORETURN void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock();
extern double pop_clock();
extern double consolidated_time[10], gc_time;
extern bool volatile already_in_gc, tick_on_gc_exit;
extern bool volatile interrupt_pending, tick_pending;
extern int deal_with_tick();
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
extern "C" void low_level_signal_handler(int code);
extern "C" void sigint_handler(int code);
extern "C" int async_interrupt(int a);
extern "C" void record_get(LispObject tag, bool found);
extern int primep(int32_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" bool eql_fn(LispObject a, LispObject b);
extern "C" bool cl_equal_fn(LispObject a, LispObject b);
extern "C" bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern "C" LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" bool geq2(LispObject a, LispObject b);
extern "C" bool greaterp2(LispObject a, LispObject b);
extern "C" bool lesseq2(LispObject a, LispObject b);
extern "C" bool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, size_t len);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t &len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prinhex_to_trace(const char *msg, LispObject value);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, bool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject quotrem2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
extern int64_t sixty_four_bits(LispObject a);
extern uint64_t crc64(uint64_t crc, const void *buf, size_t size);
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
static inline LispObject onevalue(LispObject r)
{ exit_count = 1;
 return r;
}
static inline LispObject nvalues(LispObject r, int n)
{ exit_count = n;
 return r;
}
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 need_more_than_eq(a) && \
 eql_fn(a, b)))
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
 uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#define argcheck(var, n, msg) if ((var)!=(n)) aerror(msg);
extern n_args *no_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern four_args *four_arg_functions[];
extern n_args *three_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool four_arg_traceflags[];
extern bool three_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *four_arg_names[];
extern const char *three_arg_names[];
typedef struct setup_type
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
 arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 lisphash_setup[], newhash_setup[], print_setup[], read_setup[],
 restart_setup[], mpi_setup[];
extern setup_type const
 u01_setup[], u02_setup[], u03_setup[], u04_setup[],
 u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
 u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
 u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
 u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
 u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
 u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
 u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
 u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
 u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
 u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
 u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
 u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
NORETURN extern void resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern bool symbol_protect_flag, warn_about_protected_symbols;
#ifdef HASH_STATISTICS
extern uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#if defined HAVE___INT128 && !defined __HAVE_INT128_T
typedef __int128 int128_t;
#define HAVE_INT128_T
#endif
#if defined HAVE_UNSIGNED___INT128 && !defined __HAVE_UINT128_T
typedef unsigned __int128 uint128_t;
#define HAVE_UINT128_T
#endif
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) ((int32_t)(((uint32_t)(n)) >> 31))
#define set_top_bit(n) ((int32_t)((uint32_t)(n) | (uint32_t)0x80000000U))
#define clear_top_bit(n) ((int32_t)(n) & 0x7fffffff)
#define signed_overflow(n) \
 top_bit_set((uint32_t)(n) ^ ((uint32_t)(n) << 1))
#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))
#define signed29_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x1fffffffU) << 35) / ((int64_t)1 << 35)) == \
 (int64_t)(n))
#define signed31_in_64(n) \
 (((int64_t)(((uint64_t)(n) & 0x7fffffffU) << 33) / ((int64_t)1 << 33)) == \
 (int64_t)(n))
#define signed31_in_ptr(n) \
 (((intptr_t)(((uintptr_t)(n)&0x7fffffffU) << (8*sizeof(intptr_t) - 31)) / \
 ((intptr_t)1 << (8*sizeof(intptr_t) - 31))) == (intptr_t)(n))
#define floating_edge_case(r) (1.0/(r) == 0.0 || (r) != (r))
#define floating_clear_flags() ((void)0)
#define floating_edge_case128(r) \
 (f128M_infinite(r) || f128M_nan(r))
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern "C" LispObject negateb(LispObject);
extern "C" LispObject copyb(LispObject);
extern "C" LispObject negate(LispObject);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern "C" LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject CLquot2(LispObject a, LispObject b);
extern "C" LispObject quotbn(LispObject a, int32_t n);
extern "C" LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern "C" LispObject quotbb(LispObject a, LispObject b, int needs);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern "C" LispObject rembi(LispObject a, LispObject b);
extern "C" LispObject rembb(LispObject a, LispObject b);
extern "C" LispObject shrink_bignum(LispObject a, size_t lena);
extern "C" LispObject modulus(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern "C" LispObject rationalize(LispObject a);
extern "C" LispObject lcm(LispObject a, LispObject b);
extern "C" LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern "C" bool numeq2(LispObject a, LispObject b);
extern "C" bool zerop(LispObject a);
extern "C" bool onep(LispObject a);
extern "C" bool minusp(LispObject a);
extern "C" bool plusp(LispObject a);
extern "C" bool lesspbd(LispObject a, double b);
extern "C" bool lessprd(LispObject a, double b);
extern "C" bool lesspdb(double a, LispObject b);
extern "C" bool lesspdr(double a, LispObject b);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, size_t n);
extern LispObject make_lisp_integer32_fn(int32_t n);
static inline LispObject make_lisp_integer32(int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(int64_t n);
static inline LispObject make_lisp_integer64(int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(uint64_t n);
static inline LispObject make_lisp_unsigned64(uint64_t n)
{ if (n < ((uint64_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(intptr_t n);
static inline LispObject make_lisp_integerptr(intptr_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
#ifdef HAVE_INT128_T
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer128_fn(n);
}
#endif
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_boxfloat128(float128_t a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern int _reduced_exp(double, double *);
extern bool lesspbi(LispObject a, LispObject b);
extern bool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
 *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
 kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern size_t karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
extern "C" int f128M_exponent(const float128_t *p);
extern "C" void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" bool f128M_infinite(const float128_t *p);
extern "C" bool f128M_nan(const float128_t *x);
extern "C" bool f128M_subnorm(const float128_t *x);
extern "C" bool f128M_negative(const float128_t *x);
extern "C" void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
extern "C" float128_t f128_0, f128_1, f128_10, f128_10_17,
 f128_10_18, f128_r10, f128_N1;
typedef struct _float256_t
{
#ifdef LITTLEENDIAN
 float128_t lo;
 float128_t hi;
#else
 float128_t hi;
 float128_t lo;
#endif
} float256_t;
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject env, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject env, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror(LispObject env, int nargs, ...);
extern "C" NORETURN void Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lall_symbols0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject env, int nargs, ...);
extern "C" LispObject Lgc0(LispObject env, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_selected_source0(LispObject env, int nargs, ...);
extern "C" LispObject Lload_spid(LispObject, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject env, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject env, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject Lunserialize(LispObject env, int nargs, ...);
extern "C" LispObject undefined0(LispObject env);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lall_symbols(LispObject env, LispObject a1);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject env, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject env, LispObject v);
extern "C" LispObject Lcaaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaadar(LispObject env, LispObject a);
extern "C" LispObject Lcaaddr(LispObject env, LispObject a);
extern "C" LispObject Lcaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcadaar(LispObject env, LispObject a);
extern "C" LispObject Lcadadr(LispObject env, LispObject a);
extern "C" LispObject Lcadar(LispObject env, LispObject a);
extern "C" LispObject Lcaddar(LispObject env, LispObject a);
extern "C" LispObject Lcadddr(LispObject env, LispObject a);
extern "C" LispObject Lcaddr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcdaaar(LispObject env, LispObject a);
extern "C" LispObject Lcdaadr(LispObject env, LispObject a);
extern "C" LispObject Lcdaar(LispObject env, LispObject a);
extern "C" LispObject Lcdadar(LispObject env, LispObject a);
extern "C" LispObject Lcdaddr(LispObject env, LispObject a);
extern "C" LispObject Lcdadr(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcddaar(LispObject env, LispObject a);
extern "C" LispObject Lcddadr(LispObject env, LispObject a);
extern "C" LispObject Lcddar(LispObject env, LispObject a);
extern "C" LispObject Lcdddar(LispObject env, LispObject a);
extern "C" LispObject Lcddddr(LispObject env, LispObject a);
extern "C" LispObject Lcdddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lchar_code(LispObject env, LispObject a);
extern "C" LispObject Lclose(LispObject env, LispObject a);
extern "C" LispObject Lcodep(LispObject env, LispObject a);
extern "C" LispObject Lcompress(LispObject env, LispObject a);
extern "C" LispObject Lconsp(LispObject env, LispObject a);
extern "C" LispObject Lconstantp(LispObject env, LispObject a);
extern "C" LispObject Lcopy_module(LispObject env, LispObject a);
extern "C" LispObject Ldefine_in_module(LispObject env, LispObject a);
extern "C" LispObject Ldelete_module(LispObject env, LispObject a);
extern "C" LispObject Ldigitp(LispObject env, LispObject a);
extern "C" LispObject Lendp(LispObject env, LispObject a);
extern "C" NORETURN void Lerror1(LispObject env, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject env, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject env, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject env, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject env, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject env, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject env, LispObject a);
extern "C" LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject env, LispObject a);
extern "C" LispObject Lis_spid(LispObject env, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject env, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject env, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Lload_selected_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject env, LispObject a);
extern "C" LispObject Llsd(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern "C" LispObject Lmacro_function(LispObject env, LispObject a);
extern "C" LispObject Lmake_global(LispObject env, LispObject a);
extern "C" LispObject Lmake_special(LispObject env, LispObject a);
extern "C" LispObject Lmapstore(LispObject env, LispObject a);
extern "C" LispObject Lmd5(LispObject env, LispObject a1);
extern "C" LispObject Lmd60(LispObject env, LispObject a1);
extern "C" LispObject Lminus(LispObject env, LispObject a);
extern "C" LispObject Lminusp(LispObject env, LispObject a);
extern "C" LispObject Lmkevect(LispObject env, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject env, LispObject a);
extern "C" LispObject Lncons(LispObject env, LispObject a);
extern "C" LispObject Lnreverse(LispObject env, LispObject a);
extern "C" LispObject Lnull(LispObject env, LispObject a);
extern "C" LispObject Lnumberp(LispObject env, LispObject a);
extern "C" LispObject Loddp(LispObject env, LispObject a);
extern "C" LispObject Lonep(LispObject env, LispObject a);
extern "C" LispObject Lpagelength(LispObject env, LispObject a);
extern "C" LispObject Lplist(LispObject env, LispObject a);
extern "C" LispObject Lplusp(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin2a(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lrepresentation1(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lserialize(LispObject env, LispObject a);
extern "C" LispObject Lserialize1(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspid_to_nil(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" NORETURN void Lstop(LispObject env, LispObject a);
extern "C" LispObject Lstringp(LispObject env, LispObject a);
extern "C" LispObject Lsub1(LispObject env, LispObject a);
extern "C" LispObject Lsymbolp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_env(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_function(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_name(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_value(LispObject env, LispObject a);
extern "C" LispObject Lsystem(LispObject env, LispObject a);
extern "C" LispObject Lthreevectorp(LispObject env, LispObject a);
extern "C" LispObject Lthrow_nil(LispObject env, LispObject a);
extern "C" LispObject Ltrace(LispObject env, LispObject a);
extern "C" LispObject Ltruncate(LispObject env, LispObject a);
extern "C" LispObject Lttab(LispObject env, LispObject a);
extern "C" LispObject Ltyo(LispObject env, LispObject a);
extern "C" LispObject Lunintern(LispObject env, LispObject a);
extern "C" LispObject Lunmake_global(LispObject env, LispObject a);
extern "C" LispObject Lunmake_special(LispObject env, LispObject a);
extern "C" LispObject Luntrace(LispObject env, LispObject a);
extern "C" LispObject Lupbv(LispObject env, LispObject a);
extern "C" LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern "C" LispObject Lvectorp(LispObject env, LispObject a);
extern "C" LispObject Lverbos(LispObject env, LispObject a);
extern "C" LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern "C" LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
extern "C" LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldifference2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldivide(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leql(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqn(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequal(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lerror2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject env, LispObject form, LispObject ffg1);
extern "C" LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lgcd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern "C" LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liremainder(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Litimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llcm(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llist2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmax2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmin2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmod(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lneq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject env, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" NORETURN void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject undefined3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject env, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
extern "C" LispObject Lappend_n(LispObject env, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject env, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject env, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject env, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject env, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject env, int nargs, ...);
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject env, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject env, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_putBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_putError(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_putObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_putInt(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject env, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject env, int nargs, ...);
extern "C" LispObject om_getApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject env, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject env, LispObject ldev);
extern "C" LispObject om_getBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject env, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getError(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject env, LispObject ldev);
extern "C" LispObject om_getObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject env, LispObject ldev);
extern "C" LispObject om_getInt(LispObject env, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject env, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject env, LispObject ldev);
extern "C" LispObject om_getVar(LispObject env, LispObject ldev);
extern "C" LispObject om_getString(LispObject env, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject env, LispObject ldev);
extern "C" LispObject om_getType(LispObject env, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject env, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject env, LispObject lpstr);
extern "C" LispObject om_read(LispObject env, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject env, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject env, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject env, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject env, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern "C" LispObject undefined4(LispObject env, size_t n, LispObject a1,
 LispObject a2, LispObject a3, LispObject a4);
#endif 
#ifndef __lispthrow_h
#define __lispthrow_h 1
class stack_popper
{ int n;
public:
 stack_popper(int nn)
 { n = nn;
 }
 ~stack_popper()
 { popv(n);
 }
};
class stack_restorer
{ LispObject *stackSave;
public:
 stack_restorer()
 { stackSave = stack;
 }
 ~stack_restorer()
 { stack = stackSave;
 }
};
class save_current_function
{ LispObject *savestack;
public:
 save_current_function(LispObject newfn)
 { push(current_function);
 savestack = stack;
 current_function = newfn;
 }
 ~save_current_function()
 { stack = savestack;
 pop(current_function);
 }
};
class bind_fluid_stack
{ LispObject *savestack;
 int env_loc;
 int name_loc;
 int val_loc;
public:
 bind_fluid_stack(int e, int name, int val)
 { savestack = stack;
 env_loc = e;
 name_loc = name;
 val_loc = val;
#ifdef TRACE_FLUID
 debug_printf("bind_fluid_stack(%d, %d, %d) @ %p\n", e, name, val, stack);
 debug_printf("name="); prin_to_debug(elt(savestack[e], name));
 debug_printf(" old-val="); prin_to_debug(qvalue(elt(savestack[e], name)));
 debug_printf("\n");
#endif
 savestack[val] = qvalue(elt(savestack[e], name));
 }
 ~bind_fluid_stack()
 {
#ifdef TRACE_FLUID
 debug_printf("restore(%d, %d, %d) @ %p\n", env_loc, name_loc, val_loc, savestack);
 debug_printf("name="); prin_to_debug(elt(savestack[env_loc], name_loc));
 debug_printf(" local-val="); prin_to_debug(qvalue(elt(savestack[env_loc], name_loc)));
 debug_printf(" restored-val="); prin_to_debug(savestack[val_loc]);
 debug_printf("\n");
#endif
 qvalue(elt(savestack[env_loc], name_loc)) = savestack[val_loc];
 }
};
struct LispException : public std::exception
{ virtual const char *what() const throw()
 { return "Generic Lisp Exception";
 }
};
 struct LispError : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Error";
 }
 };
 struct LispSignal : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Signal";
 }
 };
 struct LispResource : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Resouce Limiter";
 }
 };
 struct LispSigint : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Sigint";
 }
 };
 struct LispGo : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Go";
 }
 };
 struct LispReturnFrom : public LispException
 { virtual const char *what() const throw()
 { return "Lisp ReturnFrom";
 }
 };
 struct LispThrow : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Throw";
 }
 };
 struct LispRestart : public LispException
 { virtual const char *what() const throw()
 { return "Lisp Restart";
 }
 };
class RAIIstack_sanity
{ LispObject *saveStack;
 const char *fname;
 const char *file;
 int line;
 LispObject w;
public:
 RAIIstack_sanity(const char *fn, const char *fi, int li)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = nil;
 }
 RAIIstack_sanity(const char *fn, const char *fi, int li, LispObject ww)
 { saveStack = stack;
 fname = fn;
 file = fi;
 line = li;
 w = ww;
 }
 ~RAIIstack_sanity()
 { if (saveStack != stack && !std::uncaught_exception())
 { printf("???SP %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 if (w != nil)
 { err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 }
 }
 }
};
static inline const char *tidy_filename(const char *a)
{ const char *b = strrchr(a, '/');
 return (b == NULL ? a : b+1);
}
#ifdef DEBUG
#define STACK_SANITY \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__);
#define STACK_SANITY1(w) \
 RAIIstack_sanity stack_sanity_object(__func__, \
 tidy_filename(__FILE__), __LINE__, w);
#else
#define STACK_SANITY ;
#define STACK_SANITY1(w) ;
#endif
class RAIIsave_codevec
{ LispObject *saveStack;
public:
 RAIIsave_codevec()
 { push2(litvec, codevec);
 saveStack = stack;
 }
 ~RAIIsave_codevec()
 { stack = saveStack;
 pop2(codevec, litvec);
 }
};
#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;
extern LispObject *stack;
extern jmp_buf *global_jb;
class RAIIsave_stack_and_jb
{ LispObject *saveStack;
 jmp_buf *jbsave;
public:
 RAIIsave_stack_and_jb()
 { jbsave = global_jb; 
 saveStack = stack; 
 }
 ~RAIIsave_stack_and_jb()
 { global_jb = jbsave; 
 stack = saveStack; 
 }
};
class RAIIsave_stack
{ LispObject *saveStack;
public:
 RAIIsave_stack()
 { saveStack = stack; 
 }
 ~RAIIsave_stack()
 { stack = saveStack; 
 }
};
#define START_SETJMP_BLOCK \
 jmp_buf jb; \
 RAIIsave_stack_and_jb save_stack_Object; \
 switch (setjmp(jb)) \
 { default: \
 case 1: exit_reason = UNWIND_SIGNAL; \
 throw LispSignal(); \
 case 2: exit_reason = UNWIND_SIGINT; \
 throw LispSigint(); \
 case 0: break; \
 } \
 global_jb = &jb;
#define START_TRY_BLOCK \
 RAIIsave_stack save_stack_Object;
#define on_backtrace(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { int _reason = exit_reason; \
 b; \
 exit_reason = _reason; \
 throw; \
 }
#define if_error(a, b) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { b; \
 }
#define ignore_error(a) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#define ignore_exception(a) \
 try \
 { START_SETJMP_BLOCK; \
 a; \
 } \
 catch (LispError e) \
 { \
 }
#endif 



// Code for janettreeinsert

static LispObject CC_janettreeinsert(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29569, v_29570, v_29571;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_29285;
// end of prologue
    goto v_29300;
v_29296:
    v_29570 = stack[-7];
    goto v_29297;
v_29298:
    v_29569 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29299;
v_29300:
    goto v_29296;
v_29297:
    goto v_29298;
v_29299:
    v_29569 = *(LispObject *)((char *)v_29570 + (CELL-TAG_VECTOR) + (((intptr_t)v_29569-TAG_FIXNUM)/(16/CELL)));
    v_29569 = qcar(v_29569);
    stack[-3] = v_29569;
    goto v_29309;
v_29305:
    v_29570 = stack[-3];
    goto v_29306;
v_29307:
    v_29569 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29308;
v_29309:
    goto v_29305;
v_29306:
    goto v_29307;
v_29308:
    v_29569 = *(LispObject *)((char *)v_29570 + (CELL-TAG_VECTOR) + (((intptr_t)v_29569-TAG_FIXNUM)/(16/CELL)));
    stack[-6] = v_29569;
    v_29569 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_29569;
    v_29569 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    if (v_29569 == nil) goto v_29316;
    else goto v_29317;
v_29316:
    goto v_29326;
v_29320:
    v_29571 = stack[-6];
    goto v_29321;
v_29322:
    v_29570 = stack[-8];
    goto v_29323;
v_29324:
    v_29569 = stack[-7];
    goto v_29325;
v_29326:
    goto v_29320;
v_29321:
    goto v_29322;
v_29323:
    goto v_29324;
v_29325:
    fn = elt(env, 2); // janettreenodebuild
    v_29569 = (*qfnn(fn))(fn, 3, v_29571, v_29570, v_29569);
    env = stack[-9];
    qvalue(elt(env, 1)) = v_29569; // fluidbibasisjanettreerootnode
    goto v_29315;
v_29317:
    v_29569 = qvalue(elt(env, 1)); // fluidbibasisjanettreerootnode
    stack[-5] = v_29569;
v_29336:
    goto v_29346;
v_29342:
    v_29570 = stack[-6];
    goto v_29343;
v_29344:
    v_29569 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29345;
v_29346:
    goto v_29342;
v_29343:
    goto v_29344;
v_29345:
    v_29569 = (LispObject)greaterp2(v_29570, v_29569);
    v_29569 = v_29569 ? lisp_true : nil;
    env = stack[-9];
    if (v_29569 == nil) goto v_29339;
    else goto v_29340;
v_29339:
    goto v_29335;
v_29340:
v_29352:
    v_29569 = stack[-5];
    if (v_29569 == nil) goto v_29355;
    goto v_29366;
v_29362:
    v_29569 = stack[-5];
    v_29569 = qcar(v_29569);
    stack[0] = qcar(v_29569);
    goto v_29363;
v_29364:
    goto v_29375;
v_29371:
    v_29570 = stack[-3];
    goto v_29372;
v_29373:
    v_29569 = stack[-8];
    goto v_29374;
v_29375:
    goto v_29371;
v_29372:
    goto v_29373;
v_29374:
    fn = elt(env, 3); // monomgetvariabledegree
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29365;
v_29366:
    goto v_29362;
v_29363:
    goto v_29364;
v_29365:
    v_29569 = (LispObject)lessp2(stack[0], v_29569);
    v_29569 = v_29569 ? lisp_true : nil;
    env = stack[-9];
    if (v_29569 == nil) goto v_29355;
    v_29569 = stack[-5];
    v_29569 = qcdr(v_29569);
    v_29569 = qcar(v_29569);
    if (v_29569 == nil) goto v_29355;
    goto v_29356;
v_29355:
    goto v_29351;
v_29356:
    v_29569 = stack[-5];
    v_29569 = qcdr(v_29569);
    v_29569 = qcar(v_29569);
    stack[-5] = v_29569;
    goto v_29352;
v_29351:
    v_29569 = stack[-5];
    if (v_29569 == nil) goto v_29390;
    goto v_29399;
v_29395:
    v_29569 = stack[-5];
    v_29569 = qcar(v_29569);
    stack[0] = qcar(v_29569);
    goto v_29396;
v_29397:
    goto v_29408;
v_29404:
    v_29570 = stack[-3];
    goto v_29405;
v_29406:
    v_29569 = stack[-8];
    goto v_29407;
v_29408:
    goto v_29404;
v_29405:
    goto v_29406;
v_29407:
    fn = elt(env, 3); // monomgetvariabledegree
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29398;
v_29399:
    goto v_29395;
v_29396:
    goto v_29397;
v_29398:
    v_29569 = (LispObject)greaterp2(stack[0], v_29569);
    v_29569 = v_29569 ? lisp_true : nil;
    env = stack[-9];
    if (v_29569 == nil) goto v_29390;
    goto v_29418;
v_29412:
    v_29571 = stack[-6];
    goto v_29413;
v_29414:
    v_29570 = stack[-8];
    goto v_29415;
v_29416:
    v_29569 = stack[-7];
    goto v_29417;
v_29418:
    goto v_29412;
v_29413:
    goto v_29414;
v_29415:
    goto v_29416;
v_29417:
    fn = elt(env, 2); // janettreenodebuild
    v_29569 = (*qfnn(fn))(fn, 3, v_29571, v_29570, v_29569);
    env = stack[-9];
    stack[-4] = v_29569;
    v_29569 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_29569;
    goto v_29428;
v_29424:
    v_29569 = stack[-5];
    stack[-2] = qcdr(v_29569);
    goto v_29425;
v_29426:
    goto v_29438;
v_29432:
    v_29569 = stack[-5];
    v_29569 = qcar(v_29569);
    stack[-1] = qcar(v_29569);
    goto v_29433;
v_29434:
    v_29569 = stack[-5];
    v_29569 = qcar(v_29569);
    stack[0] = qcdr(v_29569);
    goto v_29435;
v_29436:
    goto v_29450;
v_29446:
    v_29569 = stack[-5];
    v_29569 = qcdr(v_29569);
    v_29570 = qcar(v_29569);
    goto v_29447;
v_29448:
    v_29569 = stack[-5];
    v_29569 = qcdr(v_29569);
    v_29569 = qcdr(v_29569);
    goto v_29449;
v_29450:
    goto v_29446;
v_29447:
    goto v_29448;
v_29449:
    v_29569 = cons(v_29570, v_29569);
    env = stack[-9];
    goto v_29437;
v_29438:
    goto v_29432;
v_29433:
    goto v_29434;
v_29435:
    goto v_29436;
v_29437:
    v_29569 = acons(stack[-1], stack[0], v_29569);
    env = stack[-9];
    goto v_29427;
v_29428:
    goto v_29424;
v_29425:
    goto v_29426;
v_29427:
    fn = elt(env, 4); // setcar
    v_29569 = (*qfn2(fn))(fn, stack[-2], v_29569);
    env = stack[-9];
    goto v_29462;
v_29458:
    v_29569 = stack[-5];
    v_29570 = qcdr(v_29569);
    goto v_29459;
v_29460:
    v_29569 = stack[-4];
    v_29569 = qcdr(v_29569);
    v_29569 = qcdr(v_29569);
    goto v_29461;
v_29462:
    goto v_29458;
v_29459:
    goto v_29460;
v_29461:
    fn = elt(env, 5); // setcdr
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29473;
v_29469:
    v_29569 = stack[-5];
    v_29570 = qcar(v_29569);
    goto v_29470;
v_29471:
    v_29569 = stack[-4];
    v_29569 = qcar(v_29569);
    v_29569 = qcar(v_29569);
    goto v_29472;
v_29473:
    goto v_29469;
v_29470:
    goto v_29471;
v_29472:
    fn = elt(env, 4); // setcar
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29484;
v_29480:
    v_29569 = stack[-5];
    v_29570 = qcar(v_29569);
    goto v_29481;
v_29482:
    v_29569 = stack[-4];
    v_29569 = qcar(v_29569);
    v_29569 = qcdr(v_29569);
    goto v_29483;
v_29484:
    goto v_29480;
v_29481:
    goto v_29482;
v_29483:
    fn = elt(env, 5); // setcdr
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29388;
v_29390:
    v_29569 = stack[-5];
    if (v_29569 == nil) goto v_29492;
    goto v_29504;
v_29500:
    v_29569 = stack[-5];
    v_29569 = qcar(v_29569);
    stack[0] = qcar(v_29569);
    goto v_29501;
v_29502:
    goto v_29513;
v_29509:
    v_29570 = stack[-3];
    goto v_29510;
v_29511:
    v_29569 = stack[-8];
    goto v_29512;
v_29513:
    goto v_29509;
v_29510:
    goto v_29511;
v_29512:
    fn = elt(env, 3); // monomgetvariabledegree
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29503;
v_29504:
    goto v_29500;
v_29501:
    goto v_29502;
v_29503:
    if (equal(stack[0], v_29569)) goto v_29498;
    else goto v_29499;
v_29498:
    v_29569 = stack[-5];
    v_29569 = qcdr(v_29569);
    v_29569 = qcdr(v_29569);
    goto v_29497;
v_29499:
    v_29569 = nil;
    goto v_29497;
    v_29569 = nil;
v_29497:
    if (v_29569 == nil) goto v_29492;
    goto v_29527;
v_29523:
    stack[0] = stack[-6];
    goto v_29524;
v_29525:
    goto v_29534;
v_29530:
    v_29570 = stack[-3];
    goto v_29531;
v_29532:
    v_29569 = stack[-8];
    goto v_29533;
v_29534:
    goto v_29530;
v_29531:
    goto v_29532;
v_29533:
    fn = elt(env, 3); // monomgetvariabledegree
    v_29569 = (*qfn2(fn))(fn, v_29570, v_29569);
    env = stack[-9];
    goto v_29526;
v_29527:
    goto v_29523;
v_29524:
    goto v_29525;
v_29526:
    v_29569 = difference2(stack[0], v_29569);
    env = stack[-9];
    stack[-6] = v_29569;
    v_29569 = stack[-8];
    v_29569 = add1(v_29569);
    env = stack[-9];
    stack[-8] = v_29569;
    v_29569 = stack[-5];
    v_29569 = qcdr(v_29569);
    v_29569 = qcdr(v_29569);
    stack[-5] = v_29569;
    goto v_29388;
v_29492:
    v_29569 = stack[-5];
    if (v_29569 == nil) goto v_29544;
    goto v_29551;
v_29547:
    v_29569 = stack[-5];
    stack[0] = qcdr(v_29569);
    goto v_29548;
v_29549:
    goto v_29561;
v_29555:
    v_29571 = stack[-6];
    goto v_29556;
v_29557:
    v_29570 = stack[-8];
    goto v_29558;
v_29559:
    v_29569 = stack[-7];
    goto v_29560;
v_29561:
    goto v_29555;
v_29556:
    goto v_29557;
v_29558:
    goto v_29559;
v_29560:
    fn = elt(env, 2); // janettreenodebuild
    v_29569 = (*qfnn(fn))(fn, 3, v_29571, v_29570, v_29569);
    env = stack[-9];
    goto v_29550;
v_29551:
    goto v_29547;
v_29548:
    goto v_29549;
v_29550:
    fn = elt(env, 4); // setcar
    v_29569 = (*qfn2(fn))(fn, stack[0], v_29569);
    env = stack[-9];
    v_29569 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-6] = v_29569;
    goto v_29388;
v_29544:
v_29388:
    goto v_29336;
v_29335:
    goto v_29315;
v_29315:
    v_29569 = nil;
    return onevalue(v_29569);
}



// Code for mri_simplat1

static LispObject CC_mri_simplat1(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29381, v_29382;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29286;
    stack[-2] = v_29285;
// end of prologue
    v_29381 = qvalue(elt(env, 1)); // !*rlsimplfloor
    if (v_29381 == nil) goto v_29295;
    goto v_29304;
v_29298:
    v_29381 = stack[-2];
    fn = elt(env, 4); // mri_op
    stack[-3] = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29299;
v_29300:
    v_29381 = stack[-2];
    fn = elt(env, 5); // mri_arg2l
    v_29381 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    fn = elt(env, 6); // mri_simplfloor
    stack[0] = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29301;
v_29302:
    v_29381 = stack[-2];
    fn = elt(env, 7); // mri_type
    v_29381 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29303;
v_29304:
    goto v_29298;
v_29299:
    goto v_29300;
v_29301:
    goto v_29302;
v_29303:
    fn = elt(env, 8); // mri_0mk2
    v_29381 = (*qfnn(fn))(fn, 3, stack[-3], stack[0], v_29381);
    env = stack[-4];
    stack[-2] = v_29381;
    goto v_29293;
v_29295:
v_29293:
    v_29381 = stack[-2];
    fn = elt(env, 7); // mri_type
    v_29381 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    if (v_29381 == nil) goto v_29314;
    else goto v_29313;
v_29314:
    v_29381 = stack[-2];
    fn = elt(env, 9); // mri_dettype
    v_29381 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
v_29313:
    stack[0] = v_29381;
    goto v_29327;
v_29323:
    v_29382 = stack[0];
    goto v_29324;
v_29325:
    v_29381 = elt(env, 2); // int
    goto v_29326;
v_29327:
    goto v_29323;
v_29324:
    goto v_29325;
v_29326:
    if (v_29382 == v_29381) goto v_29321;
    else goto v_29322;
v_29321:
    goto v_29335;
v_29331:
    goto v_29341;
v_29337:
    v_29381 = stack[-2];
    fn = elt(env, 10); // mri_2pasfat
    v_29382 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29338;
v_29339:
    v_29381 = stack[-1];
    goto v_29340;
v_29341:
    goto v_29337;
v_29338:
    goto v_29339;
v_29340:
    fn = elt(env, 11); // pasf_simplat1
    v_29382 = (*qfn2(fn))(fn, v_29382, v_29381);
    env = stack[-4];
    goto v_29332;
v_29333:
    v_29381 = elt(env, 2); // int
    goto v_29334;
v_29335:
    goto v_29331;
v_29332:
    goto v_29333;
v_29334:
    {
        fn = elt(env, 12); // mri_pasf2mri
        return (*qfn2(fn))(fn, v_29382, v_29381);
    }
v_29322:
    v_29381 = stack[-2];
    fn = elt(env, 13); // mri_congp
    v_29381 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    if (v_29381 == nil) goto v_29348;
    else goto v_29349;
v_29348:
    goto v_29357;
v_29353:
    goto v_29363;
v_29359:
    v_29381 = stack[-2];
    fn = elt(env, 14); // mri_2ofsfat
    v_29382 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29360;
v_29361:
    v_29381 = stack[-1];
    goto v_29362;
v_29363:
    goto v_29359;
v_29360:
    goto v_29361;
v_29362:
    fn = elt(env, 15); // ofsf_simplat1
    v_29382 = (*qfn2(fn))(fn, v_29382, v_29381);
    env = stack[-4];
    goto v_29354;
v_29355:
    v_29381 = elt(env, 3); // real
    goto v_29356;
v_29357:
    goto v_29353;
v_29354:
    goto v_29355;
v_29356:
    {
        fn = elt(env, 16); // mri_ofsf2mri
        return (*qfn2(fn))(fn, v_29382, v_29381);
    }
v_29349:
    goto v_29375;
v_29369:
    v_29381 = stack[-2];
    fn = elt(env, 4); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29370;
v_29371:
    v_29381 = stack[-2];
    fn = elt(env, 5); // mri_arg2l
    v_29382 = (*qfn1(fn))(fn, v_29381);
    env = stack[-4];
    goto v_29372;
v_29373:
    v_29381 = stack[0];
    goto v_29374;
v_29375:
    goto v_29369;
v_29370:
    goto v_29371;
v_29372:
    goto v_29373;
v_29374:
    {
        LispObject v_29387 = stack[-1];
        fn = elt(env, 8); // mri_0mk2
        return (*qfnn(fn))(fn, 3, v_29387, v_29382, v_29381);
    }
    return onevalue(v_29381);
}



// Code for ofsf_updsignpow

static LispObject CC_ofsf_updsignpow(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29324, v_29325, v_29326, v_29327;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29326 = v_29286;
    v_29327 = v_29285;
// end of prologue
    goto v_29296;
v_29292:
    v_29325 = v_29327;
    goto v_29293;
v_29294:
    v_29324 = elt(env, 1); // (equal greaterp geq neq)
    goto v_29295;
v_29296:
    goto v_29292;
v_29293:
    goto v_29294;
v_29295:
    v_29324 = Lmemq(nil, v_29325, v_29324);
    if (v_29324 == nil) goto v_29291;
    v_29324 = v_29327;
    goto v_29289;
v_29291:
    goto v_29307;
v_29303:
    v_29325 = v_29327;
    goto v_29304;
v_29305:
    v_29324 = elt(env, 2); // (lessp leq)
    goto v_29306;
v_29307:
    goto v_29303;
v_29304:
    goto v_29305;
v_29306:
    v_29324 = Lmemq(nil, v_29325, v_29324);
    if (v_29324 == nil) goto v_29302;
    goto v_29316;
v_29312:
    v_29324 = v_29327;
    goto v_29313;
v_29314:
    v_29325 = v_29326;
    v_29325 = Levenp(nil, v_29325);
    env = stack[0];
    v_29325 = (v_29325 == nil ? lisp_true : nil);
    goto v_29315;
v_29316:
    goto v_29312;
v_29313:
    goto v_29314;
v_29315:
    {
        fn = elt(env, 4); // ofsf_canegrel
        return (*qfn2(fn))(fn, v_29324, v_29325);
    }
v_29302:
    v_29324 = elt(env, 3); // unknown
    goto v_29289;
    v_29324 = nil;
v_29289:
    return onevalue(v_29324);
}



// Code for cr!:prep

static LispObject CC_crTprep(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29316, v_29317;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    goto v_29293;
v_29289:
    goto v_29300;
v_29296:
    v_29317 = elt(env, 1); // !:rd!:
    goto v_29297;
v_29298:
    v_29316 = stack[0];
    v_29316 = qcdr(v_29316);
    v_29316 = qcar(v_29316);
    goto v_29299;
v_29300:
    goto v_29296;
v_29297:
    goto v_29298;
v_29299:
    v_29316 = cons(v_29317, v_29316);
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    stack[-1] = (*qfn1(fn))(fn, v_29316);
    env = stack[-2];
    goto v_29290;
v_29291:
    goto v_29311;
v_29307:
    v_29317 = elt(env, 1); // !:rd!:
    goto v_29308;
v_29309:
    v_29316 = stack[0];
    v_29316 = qcdr(v_29316);
    v_29316 = qcdr(v_29316);
    goto v_29310;
v_29311:
    goto v_29307;
v_29308:
    goto v_29309;
v_29310:
    v_29316 = cons(v_29317, v_29316);
    env = stack[-2];
    fn = elt(env, 2); // rd!:prep
    v_29316 = (*qfn1(fn))(fn, v_29316);
    env = stack[-2];
    goto v_29292;
v_29293:
    goto v_29289;
v_29290:
    goto v_29291;
v_29292:
    v_29316 = cons(stack[-1], v_29316);
    env = stack[-2];
    {
        fn = elt(env, 3); // crprep1
        return (*qfn1(fn))(fn, v_29316);
    }
}



// Code for spinnerprod

static LispObject CC_spinnerprod(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29421, v_29422, v_29423, v_29424;
    LispObject v_29290, v_29289, v_29288, v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 6, "spinnerprod");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    v_29288 = va_arg(aa, LispObject);
    v_29289 = va_arg(aa, LispObject);
    v_29290 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push6(v_29290,v_29289,v_29288,v_29287,v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop6(v_29285,v_29286,v_29287,v_29288,v_29289,v_29290);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_29290;
    v_29421 = v_29289;
    v_29422 = v_29288;
    stack[-5] = v_29287;
    v_29423 = v_29286;
    v_29424 = v_29285;
// end of prologue
    stack[-6] = v_29422;
    v_29422 = stack[-6];
    stack[-3] = v_29422;
    v_29421 = qcdr(v_29421);
    stack[-1] = v_29421;
v_29304:
    v_29421 = stack[-1];
    if (v_29421 == nil) goto v_29309;
    else goto v_29310;
v_29309:
    goto v_29303;
v_29310:
    v_29421 = stack[-1];
    v_29421 = qcar(v_29421);
    v_29422 = v_29421;
    v_29421 = v_29422;
    v_29421 = qcar(v_29421);
    stack[-7] = v_29421;
    v_29421 = stack[-7];
    if (v_29421 == nil) goto v_29320;
    else goto v_29321;
v_29320:
    v_29421 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_29421;
    goto v_29319;
v_29321:
v_29319:
    v_29421 = v_29422;
    v_29421 = qcdr(v_29421);
    stack[-2] = v_29421;
    v_29421 = stack[-2];
    if (v_29421 == nil) goto v_29332;
    else goto v_29333;
v_29332:
    v_29421 = lisp_true;
    goto v_29331;
v_29333:
    goto v_29342;
v_29338:
    stack[0] = stack[-2];
    goto v_29339;
v_29340:
    v_29421 = nil;
    v_29421 = ncons(v_29421);
    env = stack[-8];
    goto v_29341;
v_29342:
    goto v_29338;
v_29339:
    goto v_29340;
v_29341:
    v_29421 = (equal(stack[0], v_29421) ? lisp_true : nil);
    goto v_29331;
    v_29421 = nil;
v_29331:
    if (v_29421 == nil) goto v_29329;
    v_29421 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_29421;
    goto v_29327;
v_29329:
v_29327:
    goto v_29357;
v_29353:
    v_29422 = stack[-7];
    goto v_29354;
v_29355:
    v_29421 = stack[-5];
    goto v_29356;
v_29357:
    goto v_29353;
v_29354:
    goto v_29355;
v_29356:
    v_29421 = (LispObject)lesseq2(v_29422, v_29421);
    v_29421 = v_29421 ? lisp_true : nil;
    env = stack[-8];
    if (v_29421 == nil) goto v_29351;
    goto v_29364;
v_29360:
    v_29422 = stack[-7];
    goto v_29361;
v_29362:
    v_29421 = stack[-4];
    goto v_29363;
v_29364:
    goto v_29360;
v_29361:
    goto v_29362;
v_29363:
    v_29421 = Latsoc(nil, v_29422, v_29421);
    stack[-7] = v_29421;
    v_29421 = stack[-7];
    if (v_29421 == nil) goto v_29374;
    else goto v_29375;
v_29374:
    v_29421 = lisp_true;
    goto v_29373;
v_29375:
    goto v_29384;
v_29380:
    stack[0] = stack[-7];
    goto v_29381;
v_29382:
    v_29421 = nil;
    v_29421 = ncons(v_29421);
    env = stack[-8];
    goto v_29383;
v_29384:
    goto v_29380;
v_29381:
    goto v_29382;
v_29383:
    v_29421 = (equal(stack[0], v_29421) ? lisp_true : nil);
    goto v_29373;
    v_29421 = nil;
v_29373:
    if (v_29421 == nil) goto v_29371;
    goto v_29369;
v_29371:
    goto v_29399;
v_29393:
    stack[0] = elt(env, 1); // plus
    goto v_29394;
v_29395:
    stack[-3] = stack[-6];
    goto v_29396;
v_29397:
    goto v_29409;
v_29403:
    v_29423 = elt(env, 2); // times
    goto v_29404;
v_29405:
    v_29422 = stack[-2];
    goto v_29406;
v_29407:
    v_29421 = stack[-7];
    v_29421 = qcdr(v_29421);
    goto v_29408;
v_29409:
    goto v_29403;
v_29404:
    goto v_29405;
v_29406:
    goto v_29407;
v_29408:
    v_29421 = list3(v_29423, v_29422, v_29421);
    env = stack[-8];
    goto v_29398;
v_29399:
    goto v_29393;
v_29394:
    goto v_29395;
v_29396:
    goto v_29397;
v_29398:
    v_29421 = list3(stack[0], stack[-3], v_29421);
    env = stack[-8];
    stack[-6] = v_29421;
    v_29421 = stack[-6];
    stack[-3] = v_29421;
    goto v_29369;
v_29369:
    goto v_29349;
v_29351:
v_29349:
    v_29421 = stack[-1];
    v_29421 = qcdr(v_29421);
    stack[-1] = v_29421;
    goto v_29304;
v_29303:
    v_29421 = stack[-3];
    return onevalue(v_29421);
}



// Code for safe!-fp!-quot

static LispObject CC_safeKfpKquot(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29376, v_29377, v_29378;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29378 = v_29286;
    stack[0] = v_29285;
// end of prologue
    goto v_29299;
v_29295:
    v_29377 = v_29378;
    goto v_29296;
v_29297:
    v_29376 = elt(env, 1); // 0.0
    goto v_29298;
v_29299:
    goto v_29295;
v_29296:
    goto v_29297;
v_29298:
    if (equal(v_29377, v_29376)) goto v_29293;
    else goto v_29294;
v_29293:
    v_29376 = nil;
    goto v_29290;
v_29294:
    v_29376 = qvalue(elt(env, 2)); // !*nonegzerotimes
    if (v_29376 == nil) goto v_29304;
    goto v_29312;
v_29308:
    v_29377 = stack[0];
    goto v_29309;
v_29310:
    v_29376 = elt(env, 1); // 0.0
    goto v_29311;
v_29312:
    goto v_29308;
v_29309:
    goto v_29310;
v_29311:
    if (equal(v_29377, v_29376)) goto v_29307;
    else goto v_29304;
v_29307:
    v_29376 = elt(env, 1); // 0.0
    goto v_29290;
v_29304:
    goto v_29321;
v_29317:
    v_29376 = stack[0];
    goto v_29318;
v_29319:
    v_29377 = v_29378;
    goto v_29320;
v_29321:
    goto v_29317;
v_29318:
    goto v_29319;
v_29320:
    v_29376 = quot2(v_29376, v_29377);
    env = stack[-2];
    stack[-1] = v_29376;
    goto v_29334;
v_29330:
    v_29377 = stack[-1];
    goto v_29331;
v_29332:
    v_29376 = qvalue(elt(env, 3)); // !!minnorm
    goto v_29333;
v_29334:
    goto v_29330;
v_29331:
    goto v_29332;
v_29333:
    v_29376 = (LispObject)lessp2(v_29377, v_29376);
    v_29376 = v_29376 ? lisp_true : nil;
    env = stack[-2];
    if (v_29376 == nil) goto v_29327;
    goto v_29344;
v_29340:
    v_29377 = stack[-1];
    goto v_29341;
v_29342:
    v_29376 = qvalue(elt(env, 4)); // !!minnegnorm
    goto v_29343;
v_29344:
    goto v_29340;
v_29341:
    goto v_29342;
v_29343:
    v_29376 = (LispObject)greaterp2(v_29377, v_29376);
    v_29376 = v_29376 ? lisp_true : nil;
    env = stack[-2];
    if (v_29376 == nil) goto v_29327;
    goto v_29352;
v_29348:
    v_29377 = stack[0];
    goto v_29349;
v_29350:
    v_29376 = elt(env, 1); // 0.0
    goto v_29351;
v_29352:
    goto v_29348;
v_29349:
    goto v_29350;
v_29351:
    if (equal(v_29377, v_29376)) goto v_29327;
    v_29376 = nil;
    goto v_29290;
v_29327:
    goto v_29362;
v_29358:
    goto v_29368;
v_29364:
    v_29377 = stack[-1];
    goto v_29365;
v_29366:
    v_29376 = stack[-1];
    goto v_29367;
v_29368:
    goto v_29364;
v_29365:
    goto v_29366;
v_29367:
    v_29376 = difference2(v_29377, v_29376);
    env = stack[-2];
    goto v_29359;
v_29360:
    v_29377 = elt(env, 1); // 0.0
    goto v_29361;
v_29362:
    goto v_29358;
v_29359:
    goto v_29360;
v_29361:
    if (equal(v_29376, v_29377)) goto v_29356;
    else goto v_29357;
v_29356:
    v_29376 = stack[-1];
    goto v_29290;
v_29357:
    v_29376 = nil;
    goto v_29290;
    v_29376 = nil;
v_29290:
    return onevalue(v_29376);
}



// Code for f2dip

static LispObject CC_f2dip(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29299 = v_29285;
// end of prologue
    goto v_29294;
v_29288:
    stack[-1] = v_29299;
    goto v_29289;
v_29290:
    fn = elt(env, 1); // evzero
    stack[0] = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    goto v_29291;
v_29292:
    v_29299 = (LispObject)16+TAG_FIXNUM; // 1
    fn = elt(env, 2); // bcfd
    v_29299 = (*qfn1(fn))(fn, v_29299);
    env = stack[-2];
    goto v_29293;
v_29294:
    goto v_29288;
v_29289:
    goto v_29290;
v_29291:
    goto v_29292;
v_29293:
    {
        LispObject v_29302 = stack[-1];
        LispObject v_29303 = stack[0];
        fn = elt(env, 3); // f2dip1
        return (*qfnn(fn))(fn, 3, v_29302, v_29303, v_29299);
    }
}



// Code for delete_edge

static LispObject CC_delete_edge(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29333, v_29334, v_29335;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    v_29335 = nil;
v_29291:
    v_29333 = stack[0];
    if (v_29333 == nil) goto v_29294;
    else goto v_29295;
v_29294:
    v_29333 = v_29335;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_29333);
    }
v_29295:
    goto v_29305;
v_29301:
    v_29333 = stack[-1];
    v_29334 = qcar(v_29333);
    goto v_29302;
v_29303:
    v_29333 = stack[0];
    v_29333 = qcar(v_29333);
    v_29333 = qcar(v_29333);
    goto v_29304;
v_29305:
    goto v_29301;
v_29302:
    goto v_29303;
v_29304:
    if (v_29334 == v_29333) goto v_29299;
    else goto v_29300;
v_29299:
    goto v_29316;
v_29312:
    v_29334 = v_29335;
    goto v_29313;
v_29314:
    v_29333 = stack[0];
    v_29333 = qcdr(v_29333);
    goto v_29315;
v_29316:
    goto v_29312;
v_29313:
    goto v_29314;
v_29315:
    {
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_29334, v_29333);
    }
v_29300:
    goto v_29327;
v_29323:
    v_29333 = stack[0];
    v_29333 = qcar(v_29333);
    goto v_29324;
v_29325:
    v_29334 = v_29335;
    goto v_29326;
v_29327:
    goto v_29323;
v_29324:
    goto v_29325;
v_29326:
    v_29333 = cons(v_29333, v_29334);
    env = stack[-2];
    v_29335 = v_29333;
    v_29333 = stack[0];
    v_29333 = qcdr(v_29333);
    stack[0] = v_29333;
    goto v_29291;
    v_29333 = nil;
    return onevalue(v_29333);
}



// Code for reduce!-ratios

static LispObject CC_reduceKratios(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29353, v_29354;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29286;
    stack[-2] = v_29285;
// end of prologue
v_29284:
    goto v_29300;
v_29296:
    v_29354 = stack[-2];
    goto v_29297;
v_29298:
    v_29353 = stack[-1];
    goto v_29299;
v_29300:
    goto v_29296;
v_29297:
    goto v_29298;
v_29299:
    fn = elt(env, 1); // red!-ratios1
    v_29353 = (*qfn2(fn))(fn, v_29354, v_29353);
    env = stack[-4];
    stack[-3] = v_29353;
    if (v_29353 == nil) goto v_29293;
    else goto v_29294;
v_29293:
    v_29353 = stack[-2];
    goto v_29290;
v_29294:
    goto v_29309;
v_29305:
    goto v_29315;
v_29311:
    v_29353 = stack[-3];
    v_29354 = qcar(v_29353);
    goto v_29312;
v_29313:
    v_29353 = stack[-2];
    goto v_29314;
v_29315:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    fn = elt(env, 2); // mv!-domainlist!-!*
    stack[0] = (*qfn2(fn))(fn, v_29354, v_29353);
    env = stack[-4];
    goto v_29306;
v_29307:
    goto v_29324;
v_29320:
    v_29353 = stack[-3];
    v_29354 = qcdr(v_29353);
    goto v_29321;
v_29322:
    v_29353 = stack[-1];
    goto v_29323;
v_29324:
    goto v_29320;
v_29321:
    goto v_29322;
v_29323:
    fn = elt(env, 2); // mv!-domainlist!-!*
    v_29353 = (*qfn2(fn))(fn, v_29354, v_29353);
    env = stack[-4];
    goto v_29308;
v_29309:
    goto v_29305;
v_29306:
    goto v_29307;
v_29308:
    fn = elt(env, 3); // mv!-domainlist!-!-
    v_29353 = (*qfn2(fn))(fn, stack[0], v_29353);
    env = stack[-4];
    stack[-3] = v_29353;
    goto v_29337;
v_29333:
    v_29353 = stack[-2];
    fn = elt(env, 4); // reddom_zeros
    stack[0] = (*qfn1(fn))(fn, v_29353);
    env = stack[-4];
    goto v_29334;
v_29335:
    v_29353 = stack[-3];
    fn = elt(env, 4); // reddom_zeros
    v_29353 = (*qfn1(fn))(fn, v_29353);
    env = stack[-4];
    goto v_29336;
v_29337:
    goto v_29333;
v_29334:
    goto v_29335;
v_29336:
    v_29353 = (LispObject)geq2(stack[0], v_29353);
    v_29353 = v_29353 ? lisp_true : nil;
    env = stack[-4];
    if (v_29353 == nil) goto v_29331;
    v_29353 = stack[-2];
    goto v_29329;
v_29331:
    goto v_29350;
v_29346:
    v_29354 = stack[-3];
    goto v_29347;
v_29348:
    v_29353 = stack[-1];
    goto v_29349;
v_29350:
    goto v_29346;
v_29347:
    goto v_29348;
v_29349:
    stack[-2] = v_29354;
    stack[-1] = v_29353;
    goto v_29284;
    v_29353 = nil;
v_29329:
v_29290:
    return onevalue(v_29353);
}



// Code for fs!:subang

static LispObject CC_fsTsubang(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29470, v_29471, v_29472, v_29473;
    LispObject fn;
    LispObject v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "fs:subang");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29287,v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29285,v_29286,v_29287);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-5] = v_29287;
    stack[-6] = v_29286;
    stack[-7] = v_29285;
// end of prologue
    v_29470 = stack[-7];
    if (v_29470 == nil) goto v_29291;
    else goto v_29292;
v_29291:
    v_29470 = nil;
    goto v_29290;
v_29292:
    v_29470 = (LispObject)112+TAG_FIXNUM; // 7
    v_29470 = Lmkvect(nil, v_29470);
    env = stack[-9];
    stack[-8] = v_29470;
    goto v_29307;
v_29303:
    goto v_29312;
v_29308:
    v_29471 = stack[-7];
    goto v_29309;
v_29310:
    v_29470 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_29311;
v_29312:
    goto v_29308;
v_29309:
    goto v_29310;
v_29311:
    v_29471 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29304;
v_29305:
    v_29470 = stack[-6];
    goto v_29306;
v_29307:
    goto v_29303;
v_29304:
    goto v_29305;
v_29306:
    v_29470 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    stack[-4] = v_29470;
    v_29470 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_29470;
v_29321:
    goto v_29333;
v_29329:
    v_29471 = (LispObject)112+TAG_FIXNUM; // 7
    goto v_29330;
v_29331:
    v_29470 = stack[-3];
    goto v_29332;
v_29333:
    goto v_29329;
v_29330:
    goto v_29331;
v_29332:
    v_29470 = difference2(v_29471, v_29470);
    env = stack[-9];
    v_29470 = Lminusp(nil, v_29470);
    env = stack[-9];
    if (v_29470 == nil) goto v_29326;
    goto v_29320;
v_29326:
    goto v_29345;
v_29341:
    v_29471 = stack[-3];
    goto v_29342;
v_29343:
    v_29470 = stack[-6];
    goto v_29344;
v_29345:
    goto v_29341;
v_29342:
    goto v_29343;
v_29344:
    if (equal(v_29471, v_29470)) goto v_29339;
    else goto v_29340;
v_29339:
    goto v_29354;
v_29348:
    stack[-1] = stack[-8];
    goto v_29349;
v_29350:
    stack[0] = stack[-3];
    goto v_29351;
v_29352:
    goto v_29362;
v_29358:
    v_29472 = stack[-4];
    goto v_29359;
v_29360:
    goto v_29368;
v_29364:
    v_29471 = stack[-5];
    goto v_29365;
v_29366:
    v_29470 = stack[-3];
    goto v_29367;
v_29368:
    goto v_29364;
v_29365:
    goto v_29366;
v_29367:
    v_29470 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29361;
v_29362:
    goto v_29358;
v_29359:
    goto v_29360;
v_29361:
    v_29470 = times2(v_29472, v_29470);
    env = stack[-9];
    goto v_29353;
v_29354:
    goto v_29348;
v_29349:
    goto v_29350;
v_29351:
    goto v_29352;
v_29353:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + (((intptr_t)stack[0]-TAG_FIXNUM)/(16/CELL))) = v_29470;
    goto v_29338;
v_29340:
    goto v_29380;
v_29374:
    stack[-2] = stack[-8];
    goto v_29375;
v_29376:
    stack[-1] = stack[-3];
    goto v_29377;
v_29378:
    goto v_29388;
v_29384:
    goto v_29393;
v_29389:
    goto v_29398;
v_29394:
    v_29471 = stack[-7];
    goto v_29395;
v_29396:
    v_29470 = (LispObject)32+TAG_FIXNUM; // 2
    goto v_29397;
v_29398:
    goto v_29394;
v_29395:
    goto v_29396;
v_29397:
    v_29471 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29390;
v_29391:
    v_29470 = stack[-3];
    goto v_29392;
v_29393:
    goto v_29389;
v_29390:
    goto v_29391;
v_29392:
    stack[0] = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29385;
v_29386:
    goto v_29409;
v_29405:
    v_29472 = stack[-4];
    goto v_29406;
v_29407:
    goto v_29415;
v_29411:
    v_29471 = stack[-5];
    goto v_29412;
v_29413:
    v_29470 = stack[-3];
    goto v_29414;
v_29415:
    goto v_29411;
v_29412:
    goto v_29413;
v_29414:
    v_29470 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29408;
v_29409:
    goto v_29405;
v_29406:
    goto v_29407;
v_29408:
    v_29470 = times2(v_29472, v_29470);
    env = stack[-9];
    goto v_29387;
v_29388:
    goto v_29384;
v_29385:
    goto v_29386;
v_29387:
    v_29470 = plus2(stack[0], v_29470);
    env = stack[-9];
    goto v_29379;
v_29380:
    goto v_29374;
v_29375:
    goto v_29376;
v_29377:
    goto v_29378;
v_29379:
    *(LispObject *)((char *)stack[-2] + (CELL-TAG_VECTOR) + (((intptr_t)stack[-1]-TAG_FIXNUM)/(16/CELL))) = v_29470;
    goto v_29338;
v_29338:
    v_29470 = stack[-3];
    v_29470 = add1(v_29470);
    env = stack[-9];
    stack[-3] = v_29470;
    goto v_29321;
v_29320:
    goto v_29426;
v_29422:
    goto v_29434;
v_29428:
    goto v_29439;
v_29435:
    v_29471 = stack[-7];
    goto v_29436;
v_29437:
    v_29470 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_29438;
v_29439:
    goto v_29435;
v_29436:
    goto v_29437;
v_29438:
    v_29472 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29429;
v_29430:
    v_29471 = stack[-6];
    goto v_29431;
v_29432:
    v_29470 = stack[-5];
    goto v_29433;
v_29434:
    goto v_29428;
v_29429:
    goto v_29430;
v_29431:
    goto v_29432;
v_29433:
    stack[0] = CC_fsTsubang(elt(env, 0), 3, v_29472, v_29471, v_29470);
    env = stack[-9];
    goto v_29423;
v_29424:
    goto v_29452;
v_29446:
    goto v_29457;
v_29453:
    v_29471 = stack[-7];
    goto v_29454;
v_29455:
    v_29470 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29456;
v_29457:
    goto v_29453;
v_29454:
    goto v_29455;
v_29456:
    v_29473 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29447;
v_29448:
    v_29472 = stack[-8];
    goto v_29449;
v_29450:
    goto v_29466;
v_29462:
    v_29471 = stack[-7];
    goto v_29463;
v_29464:
    v_29470 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29465;
v_29466:
    goto v_29462;
v_29463:
    goto v_29464;
v_29465:
    v_29470 = *(LispObject *)((char *)v_29471 + (CELL-TAG_VECTOR) + (((intptr_t)v_29470-TAG_FIXNUM)/(16/CELL)));
    goto v_29451;
v_29452:
    goto v_29446;
v_29447:
    goto v_29448;
v_29449:
    goto v_29450;
v_29451:
    fn = elt(env, 1); // make!-term
    v_29470 = (*qfnn(fn))(fn, 3, v_29473, v_29472, v_29470);
    env = stack[-9];
    goto v_29425;
v_29426:
    goto v_29422;
v_29423:
    goto v_29424;
v_29425:
    {
        LispObject v_29483 = stack[0];
        fn = elt(env, 2); // fs!:plus
        return (*qfn2(fn))(fn, v_29483, v_29470);
    }
    goto v_29290;
    v_29470 = nil;
v_29290:
    return onevalue(v_29470);
}



// Code for addnew

static LispObject CC_addnew(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29333, v_29334, v_29335, v_29336, v_29337;
    LispObject fn;
    LispObject v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "addnew");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29287,v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29285,v_29286,v_29287);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29287;
    v_29336 = v_29286;
    v_29337 = v_29285;
// end of prologue
    goto v_29295;
v_29289:
    v_29335 = qvalue(elt(env, 1)); // gv!*
    goto v_29290;
v_29291:
    v_29334 = v_29336;
    goto v_29292;
v_29293:
    v_29333 = v_29337;
    goto v_29294;
v_29295:
    goto v_29289;
v_29290:
    goto v_29291;
v_29292:
    goto v_29293;
v_29294:
    *(LispObject *)((char *)v_29335 + (CELL-TAG_VECTOR) + (((intptr_t)v_29334-TAG_FIXNUM)/(16/CELL))) = v_29333;
    goto v_29305;
v_29299:
    v_29335 = qvalue(elt(env, 2)); // bv!*
    goto v_29300;
v_29301:
    v_29334 = v_29336;
    goto v_29302;
v_29303:
    v_29333 = lisp_true;
    goto v_29304;
v_29305:
    goto v_29299;
v_29300:
    goto v_29301;
v_29302:
    goto v_29303;
v_29304:
    *(LispObject *)((char *)v_29335 + (CELL-TAG_VECTOR) + (((intptr_t)v_29334-TAG_FIXNUM)/(16/CELL))) = v_29333;
    v_29333 = v_29337;
    if (v_29333 == nil) goto v_29311;
    else goto v_29312;
v_29311:
    v_29333 = stack[0];
    goto v_29310;
v_29312:
    goto v_29322;
v_29318:
    goto v_29328;
v_29324:
    stack[-1] = v_29336;
    goto v_29325;
v_29326:
    v_29333 = v_29337;
    fn = elt(env, 3); // ljet
    v_29333 = (*qfn1(fn))(fn, v_29333);
    env = stack[-2];
    goto v_29327;
v_29328:
    goto v_29324;
v_29325:
    goto v_29326;
v_29327:
    v_29334 = cons(stack[-1], v_29333);
    env = stack[-2];
    goto v_29319;
v_29320:
    v_29333 = stack[0];
    goto v_29321;
v_29322:
    goto v_29318;
v_29319:
    goto v_29320;
v_29321:
    fn = elt(env, 4); // insert
    v_29333 = (*qfn2(fn))(fn, v_29334, v_29333);
    goto v_29310;
    v_29333 = nil;
v_29310:
    return onevalue(v_29333);
}



// Code for flattens1

static LispObject CC_flattens1(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29317;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
v_29289:
    v_29317 = stack[0];
    if (!consp(v_29317)) goto v_29292;
    else goto v_29293;
v_29292:
    v_29317 = stack[0];
    return ncons(v_29317);
v_29293:
    v_29317 = stack[0];
    v_29317 = qcdr(v_29317);
    if (v_29317 == nil) goto v_29298;
    goto v_29306;
v_29302:
    v_29317 = stack[0];
    v_29317 = qcar(v_29317);
    stack[-1] = CC_flattens1(elt(env, 0), v_29317);
    env = stack[-2];
    goto v_29303;
v_29304:
    v_29317 = stack[0];
    v_29317 = qcdr(v_29317);
    v_29317 = CC_flattens1(elt(env, 0), v_29317);
    goto v_29305;
v_29306:
    goto v_29302;
v_29303:
    goto v_29304;
v_29305:
    {
        LispObject v_29320 = stack[-1];
        return Lappend(nil, v_29320, v_29317);
    }
v_29298:
    v_29317 = stack[0];
    v_29317 = qcar(v_29317);
    stack[0] = v_29317;
    goto v_29289;
    v_29317 = nil;
    return onevalue(v_29317);
}



// Code for pst_mkpst

static LispObject CC_pst_mkpst(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29297;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29297 = v_29285;
// end of prologue
    goto v_29293;
v_29289:
    stack[0] = nil;
    goto v_29290;
v_29291:
    fn = elt(env, 1); // pst_mkpst1
    v_29297 = (*qfn1(fn))(fn, v_29297);
    env = stack[-1];
    goto v_29292;
v_29293:
    goto v_29289;
v_29290:
    goto v_29291;
v_29292:
    v_29297 = cons(stack[0], v_29297);
    env = stack[-1];
    {
        fn = elt(env, 2); // pst_equitable
        return (*qfn1(fn))(fn, v_29297);
    }
}



// Code for taylorp

static LispObject CC_taylorp(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29295, v_29296;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29295 = v_29285;
// end of prologue
    goto v_29292;
v_29288:
    goto v_29289;
v_29290:
    v_29296 = elt(env, 1); // taylor
    goto v_29291;
v_29292:
    goto v_29288;
v_29289:
    goto v_29290;
v_29291:
        return Leqcar(nil, v_29295, v_29296);
}



// Code for get!-new!-prime

static LispObject CC_getKnewKprime(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29377, v_29378;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_29285;
// end of prologue
    v_29377 = qvalue(elt(env, 1)); // !*force!-prime
    if (v_29377 == nil) goto v_29290;
    v_29377 = qvalue(elt(env, 1)); // !*force!-prime
    goto v_29288;
v_29290:
    stack[-3] = nil;
    v_29377 = stack[-2];
    stack[-1] = v_29377;
v_29303:
    v_29377 = stack[-1];
    if (v_29377 == nil) goto v_29307;
    else goto v_29308;
v_29307:
    goto v_29302;
v_29308:
    v_29377 = stack[-1];
    v_29377 = qcar(v_29377);
    stack[0] = v_29377;
    goto v_29323;
v_29319:
    v_29378 = stack[0];
    goto v_29320;
v_29321:
    v_29377 = (LispObject)512+TAG_FIXNUM; // 32
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    v_29377 = (LispObject)lessp2(v_29378, v_29377);
    v_29377 = v_29377 ? lisp_true : nil;
    env = stack[-4];
    if (v_29377 == nil) goto v_29317;
    goto v_29331;
v_29327:
    v_29378 = stack[0];
    goto v_29328;
v_29329:
    v_29377 = stack[-3];
    goto v_29330;
v_29331:
    goto v_29327;
v_29328:
    goto v_29329;
v_29330:
    v_29377 = cons(v_29378, v_29377);
    env = stack[-4];
    stack[-3] = v_29377;
    goto v_29315;
v_29317:
v_29315:
    v_29377 = stack[-1];
    v_29377 = qcdr(v_29377);
    stack[-1] = v_29377;
    goto v_29303;
v_29302:
v_29299:
    v_29377 = stack[-3];
    fn = elt(env, 4); // random!-teeny!-prime
    v_29377 = (*qfn1(fn))(fn, v_29377);
    env = stack[-4];
    stack[0] = v_29377;
    if (v_29377 == nil) goto v_29338;
    else goto v_29339;
v_29338:
    fn = elt(env, 5); // random!-small!-prime
    v_29377 = (*qfnn(fn))(fn, 0);
    env = stack[-4];
    stack[0] = v_29377;
    v_29377 = elt(env, 2); // all
    stack[-3] = v_29377;
    goto v_29337;
v_29339:
    goto v_29351;
v_29347:
    v_29378 = stack[0];
    goto v_29348;
v_29349:
    v_29377 = stack[-3];
    goto v_29350;
v_29351:
    goto v_29347;
v_29348:
    goto v_29349;
v_29350:
    v_29377 = cons(v_29378, v_29377);
    env = stack[-4];
    stack[-3] = v_29377;
    goto v_29337;
v_29337:
    goto v_29363;
v_29359:
    v_29378 = stack[0];
    goto v_29360;
v_29361:
    v_29377 = stack[-2];
    goto v_29362;
v_29363:
    goto v_29359;
v_29360:
    goto v_29361;
v_29362:
    v_29377 = Lmember(nil, v_29378, v_29377);
    if (v_29377 == nil) goto v_29358;
    else goto v_29356;
v_29358:
    goto v_29373;
v_29369:
    v_29378 = stack[0];
    goto v_29370;
v_29371:
    v_29377 = qvalue(elt(env, 3)); // smallest!-prime
    goto v_29372;
v_29373:
    goto v_29369;
v_29370:
    goto v_29371;
v_29372:
    v_29377 = (LispObject)lesseq2(v_29378, v_29377);
    v_29377 = v_29377 ? lisp_true : nil;
    env = stack[-4];
    if (v_29377 == nil) goto v_29367;
    else goto v_29356;
v_29367:
    goto v_29357;
v_29356:
    goto v_29299;
v_29357:
    v_29377 = stack[0];
    goto v_29288;
    v_29377 = nil;
v_29288:
    return onevalue(v_29377);
}



// Code for min2!-order

static LispObject CC_min2Korder(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29369, v_29370;
    LispObject fn;
    LispObject v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "min2-order");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29287,v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29285,v_29286,v_29287);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_29287;
    stack[-2] = v_29286;
    stack[-3] = v_29285;
// end of prologue
    stack[-4] = nil;
v_29292:
    v_29369 = stack[-3];
    if (v_29369 == nil) goto v_29295;
    else goto v_29296;
v_29295:
    v_29369 = stack[-4];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_29369);
    }
v_29296:
    goto v_29307;
v_29303:
    v_29369 = stack[-1];
    v_29369 = qcar(v_29369);
    stack[0] = v_29369;
    v_29369 = (LispObject)0+TAG_FIXNUM; // 0
    v_29370 = v_29369;
v_29312:
    v_29369 = stack[0];
    if (v_29369 == nil) goto v_29318;
    else goto v_29319;
v_29318:
    v_29369 = v_29370;
    goto v_29311;
v_29319:
    goto v_29327;
v_29323:
    v_29369 = stack[0];
    v_29369 = qcar(v_29369);
    goto v_29324;
v_29325:
    goto v_29326;
v_29327:
    goto v_29323;
v_29324:
    goto v_29325;
v_29326:
    fn = elt(env, 2); // tayexp!-plus2
    v_29369 = (*qfn2(fn))(fn, v_29369, v_29370);
    env = stack[-5];
    v_29370 = v_29369;
    v_29369 = stack[0];
    v_29369 = qcdr(v_29369);
    stack[0] = v_29369;
    goto v_29312;
v_29311:
    stack[0] = v_29369;
    goto v_29345;
v_29341:
    v_29370 = stack[0];
    goto v_29342;
v_29343:
    v_29369 = stack[-2];
    v_29369 = qcar(v_29369);
    goto v_29344;
v_29345:
    goto v_29341;
v_29342:
    goto v_29343;
v_29344:
    fn = elt(env, 3); // tayexp!-greaterp
    v_29369 = (*qfn2(fn))(fn, v_29370, v_29369);
    env = stack[-5];
    if (v_29369 == nil) goto v_29339;
    goto v_29354;
v_29350:
    v_29370 = stack[0];
    goto v_29351;
v_29352:
    v_29369 = stack[-3];
    v_29369 = qcar(v_29369);
    goto v_29353;
v_29354:
    goto v_29350;
v_29351:
    goto v_29352;
v_29353:
    fn = elt(env, 4); // tayexp!-min2
    v_29369 = (*qfn2(fn))(fn, v_29370, v_29369);
    env = stack[-5];
    v_29370 = v_29369;
    goto v_29337;
v_29339:
    v_29369 = stack[-3];
    v_29369 = qcar(v_29369);
    v_29370 = v_29369;
    goto v_29337;
    v_29370 = nil;
v_29337:
    goto v_29304;
v_29305:
    v_29369 = stack[-4];
    goto v_29306;
v_29307:
    goto v_29303;
v_29304:
    goto v_29305;
v_29306:
    v_29369 = cons(v_29370, v_29369);
    env = stack[-5];
    stack[-4] = v_29369;
    v_29369 = stack[-3];
    v_29369 = qcdr(v_29369);
    stack[-3] = v_29369;
    v_29369 = stack[-2];
    v_29369 = qcdr(v_29369);
    stack[-2] = v_29369;
    v_29369 = stack[-1];
    v_29369 = qcdr(v_29369);
    stack[-1] = v_29369;
    goto v_29292;
    v_29369 = nil;
    return onevalue(v_29369);
}



// Code for bc_dcont

static LispObject CC_bc_dcont(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29290;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29290 = v_29285;
// end of prologue
    v_29290 = qcar(v_29290);
    {
        fn = elt(env, 1); // sfto_dcontentf
        return (*qfn1(fn))(fn, v_29290);
    }
}



// Code for evalgeq

static LispObject CC_evalgeq(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29297, v_29298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
// copy arguments values to proper place
    v_29297 = v_29286;
    v_29298 = v_29285;
// end of prologue
    goto v_29293;
v_29289:
    goto v_29290;
v_29291:
    goto v_29292;
v_29293:
    goto v_29289;
v_29290:
    goto v_29291;
v_29292:
    fn = elt(env, 1); // evallessp
    v_29297 = (*qfn2(fn))(fn, v_29298, v_29297);
    v_29297 = (v_29297 == nil ? lisp_true : nil);
    return onevalue(v_29297);
}



// Code for exp!*

static LispObject CC_expH(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29295, v_29296;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29295 = v_29285;
// end of prologue
    goto v_29292;
v_29288:
    v_29296 = v_29295;
    goto v_29289;
v_29290:
    v_29295 = qvalue(elt(env, 1)); // !:bprec!:
    goto v_29291;
v_29292:
    goto v_29288;
v_29289:
    goto v_29290;
v_29291:
    {
        fn = elt(env, 2); // exp!:
        return (*qfn2(fn))(fn, v_29296, v_29295);
    }
}



// Code for mk_names_map_2

static LispObject CC_mk_names_map_2(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29338, v_29339;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_29338 = v_29285;
// end of prologue
    goto v_29298;
v_29294:
    v_29339 = v_29338;
    v_29339 = qcar(v_29339);
    goto v_29295;
v_29296:
    v_29338 = qcdr(v_29338);
    goto v_29297;
v_29298:
    goto v_29294;
v_29295:
    goto v_29296;
v_29297:
    v_29338 = Lappend(nil, v_29339, v_29338);
    env = stack[-4];
    stack[-3] = v_29338;
    v_29338 = stack[-3];
    if (v_29338 == nil) goto v_29305;
    else goto v_29306;
v_29305:
    v_29338 = nil;
    goto v_29291;
v_29306:
    v_29338 = stack[-3];
    v_29338 = qcar(v_29338);
    v_29338 = qcar(v_29338);
    v_29338 = ncons(v_29338);
    env = stack[-4];
    stack[-1] = v_29338;
    stack[-2] = v_29338;
v_29292:
    v_29338 = stack[-3];
    v_29338 = qcdr(v_29338);
    stack[-3] = v_29338;
    v_29338 = stack[-3];
    if (v_29338 == nil) goto v_29319;
    else goto v_29320;
v_29319:
    v_29338 = stack[-2];
    goto v_29291;
v_29320:
    goto v_29328;
v_29324:
    stack[0] = stack[-1];
    goto v_29325;
v_29326:
    v_29338 = stack[-3];
    v_29338 = qcar(v_29338);
    v_29338 = qcar(v_29338);
    v_29338 = ncons(v_29338);
    env = stack[-4];
    goto v_29327;
v_29328:
    goto v_29324;
v_29325:
    goto v_29326;
v_29327:
    v_29338 = Lrplacd(nil, stack[0], v_29338);
    env = stack[-4];
    v_29338 = stack[-1];
    v_29338 = qcdr(v_29338);
    stack[-1] = v_29338;
    goto v_29292;
v_29291:
    return onevalue(v_29338);
}



// Code for general!-modular!-difference

static LispObject CC_generalKmodularKdifference(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29320, v_29321;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29320 = v_29286;
    v_29321 = v_29285;
// end of prologue
    goto v_29296;
v_29292:
    goto v_29293;
v_29294:
    goto v_29295;
v_29296:
    goto v_29292;
v_29293:
    goto v_29294;
v_29295:
    v_29320 = difference2(v_29321, v_29320);
    env = stack[-1];
    stack[0] = v_29320;
    goto v_29308;
v_29304:
    v_29321 = stack[0];
    goto v_29305;
v_29306:
    v_29320 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29307;
v_29308:
    goto v_29304;
v_29305:
    goto v_29306;
v_29307:
    v_29320 = (LispObject)lessp2(v_29321, v_29320);
    v_29320 = v_29320 ? lisp_true : nil;
    env = stack[-1];
    if (v_29320 == nil) goto v_29302;
    goto v_29316;
v_29312:
    v_29321 = stack[0];
    goto v_29313;
v_29314:
    v_29320 = qvalue(elt(env, 1)); // current!-modulus
    goto v_29315;
v_29316:
    goto v_29312;
v_29313:
    goto v_29314;
v_29315:
    v_29320 = plus2(v_29321, v_29320);
    stack[0] = v_29320;
    goto v_29300;
v_29302:
v_29300:
    v_29320 = stack[0];
    return onevalue(v_29320);
}



// Code for ofsf_smmkatl!-and1

static LispObject CC_ofsf_smmkatlKand1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29465, v_29466, v_29467;
    LispObject fn;
    LispObject v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "ofsf_smmkatl-and1");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29287,v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29285,v_29286,v_29287);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_29287;
    stack[0] = v_29286;
    stack[-6] = v_29285;
// end of prologue
    goto v_29298;
v_29294:
    v_29465 = stack[0];
    v_29466 = qcar(v_29465);
    goto v_29295;
v_29296:
    v_29465 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29297;
v_29298:
    goto v_29294;
v_29295:
    goto v_29296;
v_29297:
    v_29465 = cons(v_29466, v_29465);
    env = stack[-8];
    stack[-7] = v_29465;
    v_29465 = stack[0];
    v_29465 = qcdr(v_29465);
    stack[-4] = v_29465;
v_29307:
    v_29465 = stack[-4];
    if (v_29465 == nil) goto v_29313;
    else goto v_29314;
v_29313:
    v_29465 = nil;
    goto v_29306;
v_29314:
    v_29465 = stack[-4];
    v_29465 = qcar(v_29465);
    stack[0] = v_29465;
    goto v_29328;
v_29324:
    v_29465 = stack[0];
    v_29466 = qcar(v_29465);
    goto v_29325;
v_29326:
    v_29465 = stack[-5];
    goto v_29327;
v_29328:
    goto v_29324;
v_29325:
    goto v_29326;
v_29327:
    if (equal(v_29466, v_29465)) goto v_29322;
    else goto v_29323;
v_29322:
    goto v_29341;
v_29337:
    v_29465 = stack[0];
    v_29465 = qcdr(v_29465);
    v_29466 = qcar(v_29465);
    goto v_29338;
v_29339:
    v_29465 = elt(env, 1); // (lessp greaterp)
    goto v_29340;
v_29341:
    goto v_29337;
v_29338:
    goto v_29339;
v_29340:
    v_29465 = Lmemq(nil, v_29466, v_29465);
    if (v_29465 == nil) goto v_29335;
    goto v_29355;
v_29349:
    v_29465 = stack[-6];
    v_29467 = qcdr(v_29465);
    goto v_29350;
v_29351:
    v_29465 = stack[0];
    v_29466 = qcdr(v_29465);
    goto v_29352;
v_29353:
    v_29465 = stack[-7];
    goto v_29354;
v_29355:
    goto v_29349;
v_29350:
    goto v_29351;
v_29352:
    goto v_29353;
v_29354:
    fn = elt(env, 3); // ofsf_smmkat!-and2
    v_29465 = (*qfnn(fn))(fn, 3, v_29467, v_29466, v_29465);
    env = stack[-8];
    v_29466 = v_29465;
    if (v_29465 == nil) goto v_29335;
    v_29465 = v_29466;
    v_29465 = ncons(v_29465);
    env = stack[-8];
    goto v_29333;
v_29335:
    goto v_29373;
v_29367:
    v_29467 = elt(env, 2); // and
    goto v_29368;
v_29369:
    v_29465 = stack[0];
    v_29466 = qcdr(v_29465);
    goto v_29370;
v_29371:
    v_29465 = stack[-7];
    goto v_29372;
v_29373:
    goto v_29367;
v_29368:
    goto v_29369;
v_29370:
    goto v_29371;
v_29372:
    fn = elt(env, 4); // ofsf_entry2at
    v_29465 = (*qfnn(fn))(fn, 3, v_29467, v_29466, v_29465);
    env = stack[-8];
    v_29465 = ncons(v_29465);
    env = stack[-8];
    goto v_29333;
    v_29465 = nil;
v_29333:
    goto v_29321;
v_29323:
    v_29465 = nil;
v_29321:
    stack[-3] = v_29465;
    v_29465 = stack[-3];
    fn = elt(env, 5); // lastpair
    v_29465 = (*qfn1(fn))(fn, v_29465);
    env = stack[-8];
    stack[-2] = v_29465;
    v_29465 = stack[-4];
    v_29465 = qcdr(v_29465);
    stack[-4] = v_29465;
    v_29465 = stack[-2];
    if (!consp(v_29465)) goto v_29384;
    else goto v_29385;
v_29384:
    goto v_29307;
v_29385:
v_29308:
    v_29465 = stack[-4];
    if (v_29465 == nil) goto v_29389;
    else goto v_29390;
v_29389:
    v_29465 = stack[-3];
    goto v_29306;
v_29390:
    goto v_29398;
v_29394:
    stack[-1] = stack[-2];
    goto v_29395;
v_29396:
    v_29465 = stack[-4];
    v_29465 = qcar(v_29465);
    stack[0] = v_29465;
    goto v_29411;
v_29407:
    v_29465 = stack[0];
    v_29466 = qcar(v_29465);
    goto v_29408;
v_29409:
    v_29465 = stack[-5];
    goto v_29410;
v_29411:
    goto v_29407;
v_29408:
    goto v_29409;
v_29410:
    if (equal(v_29466, v_29465)) goto v_29405;
    else goto v_29406;
v_29405:
    goto v_29424;
v_29420:
    v_29465 = stack[0];
    v_29465 = qcdr(v_29465);
    v_29466 = qcar(v_29465);
    goto v_29421;
v_29422:
    v_29465 = elt(env, 1); // (lessp greaterp)
    goto v_29423;
v_29424:
    goto v_29420;
v_29421:
    goto v_29422;
v_29423:
    v_29465 = Lmemq(nil, v_29466, v_29465);
    if (v_29465 == nil) goto v_29418;
    goto v_29438;
v_29432:
    v_29465 = stack[-6];
    v_29467 = qcdr(v_29465);
    goto v_29433;
v_29434:
    v_29465 = stack[0];
    v_29466 = qcdr(v_29465);
    goto v_29435;
v_29436:
    v_29465 = stack[-7];
    goto v_29437;
v_29438:
    goto v_29432;
v_29433:
    goto v_29434;
v_29435:
    goto v_29436;
v_29437:
    fn = elt(env, 3); // ofsf_smmkat!-and2
    v_29465 = (*qfnn(fn))(fn, 3, v_29467, v_29466, v_29465);
    env = stack[-8];
    v_29466 = v_29465;
    if (v_29465 == nil) goto v_29418;
    v_29465 = v_29466;
    v_29465 = ncons(v_29465);
    env = stack[-8];
    goto v_29416;
v_29418:
    goto v_29456;
v_29450:
    v_29467 = elt(env, 2); // and
    goto v_29451;
v_29452:
    v_29465 = stack[0];
    v_29466 = qcdr(v_29465);
    goto v_29453;
v_29454:
    v_29465 = stack[-7];
    goto v_29455;
v_29456:
    goto v_29450;
v_29451:
    goto v_29452;
v_29453:
    goto v_29454;
v_29455:
    fn = elt(env, 4); // ofsf_entry2at
    v_29465 = (*qfnn(fn))(fn, 3, v_29467, v_29466, v_29465);
    env = stack[-8];
    v_29465 = ncons(v_29465);
    env = stack[-8];
    goto v_29416;
    v_29465 = nil;
v_29416:
    goto v_29404;
v_29406:
    v_29465 = nil;
v_29404:
    goto v_29397;
v_29398:
    goto v_29394;
v_29395:
    goto v_29396;
v_29397:
    v_29465 = Lrplacd(nil, stack[-1], v_29465);
    env = stack[-8];
    v_29465 = stack[-2];
    fn = elt(env, 5); // lastpair
    v_29465 = (*qfn1(fn))(fn, v_29465);
    env = stack[-8];
    stack[-2] = v_29465;
    v_29465 = stack[-4];
    v_29465 = qcdr(v_29465);
    stack[-4] = v_29465;
    goto v_29308;
v_29306:
    return onevalue(v_29465);
}



// Code for sfchk

static LispObject CC_sfchk(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29298;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    v_29298 = stack[0];
    fn = elt(env, 1); // sfp
    v_29298 = (*qfn1(fn))(fn, v_29298);
    env = stack[-1];
    if (v_29298 == nil) goto v_29290;
    v_29298 = stack[0];
    {
        fn = elt(env, 2); // prepf
        return (*qfn1(fn))(fn, v_29298);
    }
v_29290:
    v_29298 = stack[0];
    goto v_29288;
    v_29298 = nil;
v_29288:
    return onevalue(v_29298);
}



// Code for depend!-sq

static LispObject CC_dependKsq(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29309, v_29310;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    goto v_29296;
v_29292:
    v_29309 = stack[-1];
    v_29310 = qcar(v_29309);
    goto v_29293;
v_29294:
    v_29309 = stack[0];
    goto v_29295;
v_29296:
    goto v_29292;
v_29293:
    goto v_29294;
v_29295:
    fn = elt(env, 1); // depend!-f
    v_29309 = (*qfn2(fn))(fn, v_29310, v_29309);
    env = stack[-2];
    if (v_29309 == nil) goto v_29290;
    else goto v_29289;
v_29290:
    goto v_29305;
v_29301:
    v_29309 = stack[-1];
    v_29310 = qcdr(v_29309);
    goto v_29302;
v_29303:
    v_29309 = stack[0];
    goto v_29304;
v_29305:
    goto v_29301;
v_29302:
    goto v_29303;
v_29304:
    {
        fn = elt(env, 1); // depend!-f
        return (*qfn2(fn))(fn, v_29310, v_29309);
    }
v_29289:
    return onevalue(v_29309);
}



// Code for talp_mkinvop

static LispObject CC_talp_mkinvop(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29310;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    goto v_29295;
v_29291:
    goto v_29303;
v_29299:
    v_29310 = elt(env, 1); // inv_
    stack[-2] = Lexplode(nil, v_29310);
    env = stack[-3];
    goto v_29300;
v_29301:
    v_29310 = stack[-1];
    v_29310 = ncons(v_29310);
    env = stack[-3];
    goto v_29302;
v_29303:
    goto v_29299;
v_29300:
    goto v_29301;
v_29302:
    v_29310 = Lnconc(nil, stack[-2], v_29310);
    env = stack[-3];
    v_29310 = Lcompress(nil, v_29310);
    env = stack[-3];
    stack[-1] = Lexplode(nil, v_29310);
    env = stack[-3];
    goto v_29292;
v_29293:
    v_29310 = stack[0];
    v_29310 = Lexplode(nil, v_29310);
    env = stack[-3];
    goto v_29294;
v_29295:
    goto v_29291;
v_29292:
    goto v_29293;
v_29294:
    v_29310 = Lnconc(nil, stack[-1], v_29310);
    env = stack[-3];
    v_29310 = Lcompress(nil, v_29310);
        return Lintern(nil, v_29310);
}



// Code for mri_simplfloor1

static LispObject CC_mri_simplfloor1(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29354, v_29355;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_29285;
// end of prologue
    v_29354 = stack[-1];
    if (!consp(v_29354)) goto v_29298;
    else goto v_29299;
v_29298:
    v_29354 = lisp_true;
    goto v_29297;
v_29299:
    v_29354 = stack[-1];
    v_29354 = qcar(v_29354);
    v_29354 = (consp(v_29354) ? nil : lisp_true);
    goto v_29297;
    v_29354 = nil;
v_29297:
    if (v_29354 == nil) goto v_29295;
    v_29354 = stack[-1];
    goto v_29291;
v_29295:
    v_29354 = stack[-1];
    v_29354 = qcar(v_29354);
    v_29354 = qcdr(v_29354);
    fn = elt(env, 1); // mri_simplfloor
    v_29354 = (*qfn1(fn))(fn, v_29354);
    env = stack[-3];
    stack[0] = v_29354;
    v_29354 = stack[-1];
    v_29354 = qcdr(v_29354);
    fn = elt(env, 1); // mri_simplfloor
    v_29354 = (*qfn1(fn))(fn, v_29354);
    env = stack[-3];
    stack[-2] = v_29354;
    v_29354 = stack[-1];
    v_29354 = qcar(v_29354);
    v_29354 = qcar(v_29354);
    v_29354 = qcar(v_29354);
    fn = elt(env, 2); // mri_irsplit
    v_29354 = (*qfn1(fn))(fn, v_29354);
    env = stack[-3];
    goto v_29325;
v_29321:
    goto v_29331;
v_29327:
    goto v_29328;
v_29329:
    goto v_29338;
v_29334:
    goto v_29344;
v_29340:
    v_29355 = v_29354;
    v_29355 = qcar(v_29355);
    goto v_29341;
v_29342:
    v_29354 = qcdr(v_29354);
    goto v_29343;
v_29344:
    goto v_29340;
v_29341:
    goto v_29342;
v_29343:
    fn = elt(env, 3); // addf
    v_29355 = (*qfn2(fn))(fn, v_29355, v_29354);
    env = stack[-3];
    goto v_29335;
v_29336:
    v_29354 = stack[-1];
    v_29354 = qcar(v_29354);
    v_29354 = qcar(v_29354);
    v_29354 = qcdr(v_29354);
    goto v_29337;
v_29338:
    goto v_29334;
v_29335:
    goto v_29336;
v_29337:
    fn = elt(env, 4); // exptf
    v_29354 = (*qfn2(fn))(fn, v_29355, v_29354);
    env = stack[-3];
    goto v_29330;
v_29331:
    goto v_29327;
v_29328:
    goto v_29329;
v_29330:
    fn = elt(env, 5); // multf
    v_29355 = (*qfn2(fn))(fn, stack[0], v_29354);
    env = stack[-3];
    goto v_29322;
v_29323:
    v_29354 = stack[-2];
    goto v_29324;
v_29325:
    goto v_29321;
v_29322:
    goto v_29323;
v_29324:
    {
        fn = elt(env, 3); // addf
        return (*qfn2(fn))(fn, v_29355, v_29354);
    }
v_29291:
    return onevalue(v_29354);
}



// Code for countof

static LispObject CC_countof(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29330, v_29331;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    goto v_29296;
v_29292:
    v_29331 = stack[-1];
    goto v_29293;
v_29294:
    v_29330 = stack[0];
    goto v_29295;
v_29296:
    goto v_29292;
v_29293:
    goto v_29294;
v_29295:
    if (equal(v_29331, v_29330)) goto v_29290;
    else goto v_29291;
v_29290:
    v_29330 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29289;
v_29291:
    v_29330 = stack[0];
    if (!consp(v_29330)) goto v_29300;
    else goto v_29301;
v_29300:
    v_29330 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29289;
v_29301:
    goto v_29311;
v_29307:
    goto v_29317;
v_29313:
    v_29331 = stack[-1];
    goto v_29314;
v_29315:
    v_29330 = stack[0];
    v_29330 = qcar(v_29330);
    goto v_29316;
v_29317:
    goto v_29313;
v_29314:
    goto v_29315;
v_29316:
    stack[-2] = CC_countof(elt(env, 0), v_29331, v_29330);
    env = stack[-3];
    goto v_29308;
v_29309:
    goto v_29326;
v_29322:
    v_29331 = stack[-1];
    goto v_29323;
v_29324:
    v_29330 = stack[0];
    v_29330 = qcdr(v_29330);
    goto v_29325;
v_29326:
    goto v_29322;
v_29323:
    goto v_29324;
v_29325:
    v_29330 = CC_countof(elt(env, 0), v_29331, v_29330);
    goto v_29310;
v_29311:
    goto v_29307;
v_29308:
    goto v_29309;
v_29310:
    {
        LispObject v_29335 = stack[-2];
        return plus2(v_29335, v_29330);
    }
    v_29330 = nil;
v_29289:
    return onevalue(v_29330);
}



// Code for den

static LispObject CC_den(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29298, v_29299;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29298 = v_29285;
// end of prologue
    goto v_29293;
v_29289:
    fn = elt(env, 1); // simp!*
    v_29298 = (*qfn1(fn))(fn, v_29298);
    env = stack[0];
    v_29299 = qcdr(v_29298);
    goto v_29290;
v_29291:
    v_29298 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29292;
v_29293:
    goto v_29289;
v_29290:
    goto v_29291;
v_29292:
    v_29298 = cons(v_29299, v_29298);
    env = stack[0];
    {
        fn = elt(env, 2); // mk!*sq
        return (*qfn1(fn))(fn, v_29298);
    }
}



// Code for !:log2

static LispObject CC_Tlog2(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29327, v_29328;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    goto v_29295;
v_29291:
    v_29328 = elt(env, 0); // !:log2
    goto v_29292;
v_29293:
    v_29327 = stack[0];
    goto v_29294;
v_29295:
    goto v_29291;
v_29292:
    goto v_29293;
v_29294:
    fn = elt(env, 3); // get!:const
    v_29327 = (*qfn2(fn))(fn, v_29328, v_29327);
    env = stack[-2];
    stack[-1] = v_29327;
    goto v_29306;
v_29302:
    v_29328 = stack[-1];
    goto v_29303;
v_29304:
    v_29327 = elt(env, 1); // not_found
    goto v_29305;
v_29306:
    goto v_29302;
v_29303:
    goto v_29304;
v_29305:
    if (v_29328 == v_29327) goto v_29301;
    v_29327 = stack[-1];
    goto v_29289;
v_29301:
    goto v_29315;
v_29311:
    v_29328 = qvalue(elt(env, 2)); // bftwo!*
    goto v_29312;
v_29313:
    v_29327 = stack[0];
    goto v_29314;
v_29315:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    fn = elt(env, 4); // log!:
    v_29327 = (*qfn2(fn))(fn, v_29328, v_29327);
    env = stack[-2];
    stack[-1] = v_29327;
    goto v_29323;
v_29319:
    v_29328 = elt(env, 0); // !:log2
    goto v_29320;
v_29321:
    v_29327 = stack[-1];
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    fn = elt(env, 5); // save!:const
    v_29327 = (*qfn2(fn))(fn, v_29328, v_29327);
    v_29327 = stack[-1];
v_29289:
    return onevalue(v_29327);
}



// Code for exptbf

static LispObject CC_exptbf(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29334, v_29335;
    LispObject fn;
    LispObject v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "exptbf");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_29287,v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_29285,v_29286,v_29287);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29287;
    stack[-1] = v_29286;
    stack[-2] = v_29285;
// end of prologue
v_29291:
    v_29334 = stack[-1];
    v_29334 = Levenp(nil, v_29334);
    env = stack[-3];
    if (v_29334 == nil) goto v_29294;
    else goto v_29295;
v_29294:
    goto v_29303;
v_29299:
    v_29335 = stack[0];
    goto v_29300;
v_29301:
    v_29334 = stack[-2];
    goto v_29302;
v_29303:
    goto v_29299;
v_29300:
    goto v_29301;
v_29302:
    fn = elt(env, 1); // csl_timbf
    v_29334 = (*qfn2(fn))(fn, v_29335, v_29334);
    env = stack[-3];
    stack[0] = v_29334;
    goto v_29293;
v_29295:
v_29293:
    goto v_29311;
v_29307:
    v_29335 = stack[-1];
    goto v_29308;
v_29309:
    v_29334 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_29310;
v_29311:
    goto v_29307;
v_29308:
    goto v_29309;
v_29310:
    fn = elt(env, 2); // lshift
    v_29334 = (*qfn2(fn))(fn, v_29335, v_29334);
    env = stack[-3];
    stack[-1] = v_29334;
    goto v_29322;
v_29318:
    v_29335 = stack[-1];
    goto v_29319;
v_29320:
    v_29334 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29321;
v_29322:
    goto v_29318;
v_29319:
    goto v_29320;
v_29321:
    if (v_29335 == v_29334) goto v_29316;
    else goto v_29317;
v_29316:
    v_29334 = stack[0];
    goto v_29290;
v_29317:
    goto v_29331;
v_29327:
    v_29335 = stack[-2];
    goto v_29328;
v_29329:
    v_29334 = stack[-2];
    goto v_29330;
v_29331:
    goto v_29327;
v_29328:
    goto v_29329;
v_29330:
    fn = elt(env, 1); // csl_timbf
    v_29334 = (*qfn2(fn))(fn, v_29335, v_29334);
    env = stack[-3];
    stack[-2] = v_29334;
    goto v_29291;
v_29290:
    return onevalue(v_29334);
}



// Code for find_triangl_coeff

static LispObject CC_find_triangl_coeff(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29303, v_29304, v_29305, v_29306;
    LispObject fn;
    LispObject v_29287, v_29286, v_29285;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_triangl_coeff");
    va_start(aa, nargs);
    v_29285 = va_arg(aa, LispObject);
    v_29286 = va_arg(aa, LispObject);
    v_29287 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29303 = v_29287;
    v_29304 = v_29286;
    v_29305 = v_29285;
// end of prologue
    goto v_29298;
v_29290:
    v_29306 = v_29305;
    goto v_29291;
v_29292:
    v_29305 = nil;
    goto v_29293;
v_29294:
    goto v_29295;
v_29296:
    goto v_29297;
v_29298:
    goto v_29290;
v_29291:
    goto v_29292;
v_29293:
    goto v_29294;
v_29295:
    goto v_29296;
v_29297:
    {
        fn = elt(env, 1); // find_triangle_coeff
        return (*qfnn(fn))(fn, 4, v_29306, v_29305, v_29304, v_29303);
    }
}



// Code for mo_support

static LispObject CC_mo_support(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29330, v_29331;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_29285;
// end of prologue
    stack[-3] = nil;
    v_29330 = qvalue(elt(env, 1)); // cali!=basering
    fn = elt(env, 2); // ring_names
    v_29330 = (*qfn1(fn))(fn, v_29330);
    env = stack[-4];
    stack[-1] = v_29330;
v_29293:
    v_29330 = stack[-1];
    if (v_29330 == nil) goto v_29298;
    else goto v_29299;
v_29298:
    goto v_29292;
v_29299:
    v_29330 = stack[-1];
    v_29330 = qcar(v_29330);
    stack[0] = v_29330;
    goto v_29314;
v_29310:
    v_29330 = stack[0];
    fn = elt(env, 3); // mo_from_a
    v_29331 = (*qfn1(fn))(fn, v_29330);
    env = stack[-4];
    goto v_29311;
v_29312:
    v_29330 = stack[-2];
    goto v_29313;
v_29314:
    goto v_29310;
v_29311:
    goto v_29312;
v_29313:
    fn = elt(env, 4); // mo_divides!?
    v_29330 = (*qfn2(fn))(fn, v_29331, v_29330);
    env = stack[-4];
    if (v_29330 == nil) goto v_29308;
    goto v_29323;
v_29319:
    v_29331 = stack[0];
    goto v_29320;
v_29321:
    v_29330 = stack[-3];
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    v_29330 = cons(v_29331, v_29330);
    env = stack[-4];
    stack[-3] = v_29330;
    goto v_29306;
v_29308:
v_29306:
    v_29330 = stack[-1];
    v_29330 = qcdr(v_29330);
    stack[-1] = v_29330;
    goto v_29293;
v_29292:
    v_29330 = stack[-3];
        return Lnreverse(nil, v_29330);
    return onevalue(v_29330);
}



// Code for dv_skel2factor

static LispObject CC_dv_skel2factor(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29372, v_29373;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    v_29373 = v_29286;
    stack[-4] = v_29285;
// end of prologue
    v_29372 = stack[-4];
    v_29372 = qcdr(v_29372);
    if (v_29372 == nil) goto v_29294;
    else goto v_29295;
v_29294:
    v_29372 = stack[-4];
    v_29372 = qcar(v_29372);
    goto v_29291;
v_29295:
    goto v_29305;
v_29301:
    goto v_29302;
v_29303:
    v_29372 = stack[-4];
    v_29372 = qcdr(v_29372);
    goto v_29304;
v_29305:
    goto v_29301;
v_29302:
    goto v_29303;
v_29304:
    v_29372 = Lsublis(nil, v_29373, v_29372);
    env = stack[-6];
    stack[-5] = v_29372;
    v_29372 = stack[-5];
    fn = elt(env, 1); // st_ad_numsorttree
    v_29372 = (*qfn1(fn))(fn, v_29372);
    env = stack[-6];
    stack[-5] = v_29372;
    v_29372 = stack[-5];
    v_29372 = qcdr(v_29372);
    fn = elt(env, 2); // st_flatten
    v_29372 = (*qfn1(fn))(fn, v_29372);
    env = stack[-6];
    stack[-3] = v_29372;
    v_29372 = stack[-3];
    if (v_29372 == nil) goto v_29322;
    else goto v_29323;
v_29322:
    v_29372 = nil;
    goto v_29315;
v_29323:
    v_29372 = stack[-3];
    v_29372 = qcar(v_29372);
    fn = elt(env, 3); // dv_ind2var
    v_29372 = (*qfn1(fn))(fn, v_29372);
    env = stack[-6];
    v_29372 = ncons(v_29372);
    env = stack[-6];
    stack[-1] = v_29372;
    stack[-2] = v_29372;
v_29316:
    v_29372 = stack[-3];
    v_29372 = qcdr(v_29372);
    stack[-3] = v_29372;
    v_29372 = stack[-3];
    if (v_29372 == nil) goto v_29336;
    else goto v_29337;
v_29336:
    v_29372 = stack[-2];
    goto v_29315;
v_29337:
    goto v_29345;
v_29341:
    stack[0] = stack[-1];
    goto v_29342;
v_29343:
    v_29372 = stack[-3];
    v_29372 = qcar(v_29372);
    fn = elt(env, 3); // dv_ind2var
    v_29372 = (*qfn1(fn))(fn, v_29372);
    env = stack[-6];
    v_29372 = ncons(v_29372);
    env = stack[-6];
    goto v_29344;
v_29345:
    goto v_29341;
v_29342:
    goto v_29343;
v_29344:
    v_29372 = Lrplacd(nil, stack[0], v_29372);
    env = stack[-6];
    v_29372 = stack[-1];
    v_29372 = qcdr(v_29372);
    stack[-1] = v_29372;
    goto v_29316;
v_29315:
    goto v_29360;
v_29356:
    v_29373 = stack[-5];
    stack[0] = qcar(v_29373);
    goto v_29357;
v_29358:
    goto v_29368;
v_29364:
    v_29373 = stack[-4];
    v_29373 = qcar(v_29373);
    goto v_29365;
v_29366:
    goto v_29367;
v_29368:
    goto v_29364;
v_29365:
    goto v_29366;
v_29367:
    fn = elt(env, 4); // dv_skel2factor1
    v_29372 = (*qfn2(fn))(fn, v_29373, v_29372);
    goto v_29359;
v_29360:
    goto v_29356;
v_29357:
    goto v_29358;
v_29359:
    {
        LispObject v_29380 = stack[0];
        return cons(v_29380, v_29372);
    }
v_29291:
    return onevalue(v_29372);
}



// Code for simpsqrt2

static LispObject CC_simpsqrt2(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29333, v_29334;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    v_29333 = stack[0];
    fn = elt(env, 2); // minusf
    v_29333 = (*qfn1(fn))(fn, v_29333);
    env = stack[-1];
    if (v_29333 == nil) goto v_29290;
    goto v_29302;
v_29298:
    v_29334 = stack[0];
    goto v_29299;
v_29300:
    v_29333 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_29301;
v_29302:
    goto v_29298;
v_29299:
    goto v_29300;
v_29301:
    fn = elt(env, 3); // iequal
    v_29333 = (*qfn2(fn))(fn, v_29334, v_29333);
    env = stack[-1];
    if (v_29333 == nil) goto v_29296;
    v_29333 = qvalue(elt(env, 1)); // gaussiani
    goto v_29294;
v_29296:
    v_29333 = stack[0];
    fn = elt(env, 4); // negf
    v_29333 = (*qfn1(fn))(fn, v_29333);
    env = stack[-1];
    v_29334 = v_29333;
    v_29333 = v_29334;
    if (is_number(v_29333)) goto v_29315;
    else goto v_29316;
v_29315:
    goto v_29323;
v_29319:
    stack[0] = qvalue(elt(env, 1)); // gaussiani
    goto v_29320;
v_29321:
    v_29333 = v_29334;
    fn = elt(env, 5); // simpsqrt3
    v_29333 = (*qfn1(fn))(fn, v_29333);
    env = stack[-1];
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    {
        LispObject v_29336 = stack[0];
        fn = elt(env, 6); // multf
        return (*qfn2(fn))(fn, v_29336, v_29333);
    }
v_29316:
    v_29333 = stack[0];
    {
        fn = elt(env, 5); // simpsqrt3
        return (*qfn1(fn))(fn, v_29333);
    }
    goto v_29294;
    v_29333 = nil;
v_29294:
    goto v_29288;
v_29290:
    v_29333 = stack[0];
    {
        fn = elt(env, 5); // simpsqrt3
        return (*qfn1(fn))(fn, v_29333);
    }
    v_29333 = nil;
v_29288:
    return onevalue(v_29333);
}



// Code for add!-factor

static LispObject CC_addKfactor(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29352, v_29353, v_29354;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    v_29352 = stack[0];
    v_29352 = Lconsp(nil, v_29352);
    env = stack[-2];
    if (v_29352 == nil) goto v_29291;
    goto v_29303;
v_29299:
    v_29353 = stack[-1];
    goto v_29300;
v_29301:
    v_29352 = stack[0];
    v_29352 = qcar(v_29352);
    v_29352 = qcar(v_29352);
    goto v_29302;
v_29303:
    goto v_29299;
v_29300:
    goto v_29301;
v_29302:
    v_29352 = (LispObject)greaterp2(v_29353, v_29352);
    v_29352 = v_29352 ? lisp_true : nil;
    env = stack[-2];
    if (v_29352 == nil) goto v_29297;
    v_29352 = nil;
    goto v_29295;
v_29297:
    goto v_29315;
v_29311:
    v_29353 = stack[-1];
    goto v_29312;
v_29313:
    v_29352 = stack[0];
    goto v_29314;
v_29315:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    v_29352 = Lassoc(nil, v_29353, v_29352);
    goto v_29295;
    v_29352 = nil;
v_29295:
    goto v_29289;
v_29291:
    v_29352 = nil;
    goto v_29289;
    v_29352 = nil;
v_29289:
    v_29353 = v_29352;
    v_29352 = v_29353;
    if (v_29352 == nil) goto v_29326;
    goto v_29333;
v_29329:
    stack[-1] = v_29353;
    goto v_29330;
v_29331:
    v_29352 = v_29353;
    v_29352 = qcdr(v_29352);
    v_29352 = add1(v_29352);
    env = stack[-2];
    goto v_29332;
v_29333:
    goto v_29329;
v_29330:
    goto v_29331;
v_29332:
    v_29352 = Lrplacd(nil, stack[-1], v_29352);
    v_29352 = stack[0];
    goto v_29324;
v_29326:
    goto v_29348;
v_29342:
    v_29354 = stack[-1];
    goto v_29343;
v_29344:
    v_29353 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29345;
v_29346:
    v_29352 = stack[0];
    goto v_29347;
v_29348:
    goto v_29342;
v_29343:
    goto v_29344;
v_29345:
    goto v_29346;
v_29347:
    return acons(v_29354, v_29353, v_29352);
    v_29352 = nil;
v_29324:
    return onevalue(v_29352);
}



// Code for df_min

static LispObject CC_df_min(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29344, v_29345;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    v_29344 = stack[-1];
    v_29344 = Lconsp(nil, v_29344);
    env = stack[-2];
    if (v_29344 == nil) goto v_29290;
    else goto v_29291;
v_29290:
    v_29344 = stack[-1];
    v_29344 = ncons(v_29344);
    env = stack[-2];
    stack[-1] = v_29344;
    goto v_29289;
v_29291:
v_29289:
    v_29344 = stack[0];
    v_29344 = Lconsp(nil, v_29344);
    env = stack[-2];
    if (v_29344 == nil) goto v_29298;
    else goto v_29299;
v_29298:
    v_29344 = stack[0];
    v_29344 = ncons(v_29344);
    env = stack[-2];
    stack[0] = v_29344;
    goto v_29297;
v_29299:
v_29297:
    goto v_29312;
v_29308:
    v_29344 = stack[-1];
    v_29345 = qcar(v_29344);
    goto v_29309;
v_29310:
    v_29344 = stack[0];
    v_29344 = qcar(v_29344);
    goto v_29311;
v_29312:
    goto v_29308;
v_29309:
    goto v_29310;
v_29311:
    if (equal(v_29345, v_29344)) goto v_29306;
    else goto v_29307;
v_29306:
    goto v_29326;
v_29322:
    v_29344 = stack[-1];
    v_29345 = qcdr(v_29344);
    goto v_29323;
v_29324:
    v_29344 = stack[0];
    v_29344 = qcdr(v_29344);
    goto v_29325;
v_29326:
    goto v_29322;
v_29323:
    goto v_29324;
v_29325:
    fn = elt(env, 1); // df_min1
    v_29344 = (*qfn2(fn))(fn, v_29345, v_29344);
    stack[-1] = v_29344;
    if (v_29344 == nil) goto v_29320;
    goto v_29336;
v_29332:
    v_29344 = stack[0];
    v_29345 = qcar(v_29344);
    goto v_29333;
v_29334:
    v_29344 = stack[-1];
    goto v_29335;
v_29336:
    goto v_29332;
v_29333:
    goto v_29334;
v_29335:
    return cons(v_29345, v_29344);
v_29320:
    v_29344 = stack[0];
    v_29344 = qcar(v_29344);
    goto v_29318;
    v_29344 = nil;
v_29318:
    goto v_29305;
v_29307:
    v_29344 = nil;
v_29305:
    return onevalue(v_29344);
}



// Code for merge_lists

static LispObject CC_merge_lists(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29471, v_29472;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_29286;
    stack[-5] = v_29285;
// end of prologue
    stack[-6] = nil;
    stack[-3] = nil;
    stack[-1] = nil;
    v_29471 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_29471;
    v_29471 = stack[-5];
    v_29471 = Lreverse(nil, v_29471);
    env = stack[-7];
    stack[-5] = v_29471;
    v_29471 = stack[-5];
    if (v_29471 == nil) goto v_29305;
    v_29471 = stack[-5];
    v_29471 = qcar(v_29471);
    stack[-6] = v_29471;
    goto v_29303;
v_29305:
    goto v_29297;
v_29303:
v_29296:
    v_29471 = stack[-4];
    if (v_29471 == nil) goto v_29314;
    v_29471 = stack[-4];
    v_29471 = qcar(v_29471);
    stack[-2] = v_29471;
    goto v_29312;
v_29314:
    goto v_29297;
v_29312:
    goto v_29329;
v_29325:
    v_29472 = stack[-6];
    goto v_29326;
v_29327:
    v_29471 = stack[-2];
    goto v_29328;
v_29329:
    goto v_29325;
v_29326:
    goto v_29327;
v_29328:
    v_29471 = (LispObject)lessp2(v_29472, v_29471);
    v_29471 = v_29471 ? lisp_true : nil;
    env = stack[-7];
    if (v_29471 == nil) goto v_29323;
    goto v_29297;
v_29323:
    goto v_29337;
v_29333:
    v_29472 = stack[-2];
    goto v_29334;
v_29335:
    v_29471 = stack[-3];
    goto v_29336;
v_29337:
    goto v_29333;
v_29334:
    goto v_29335;
v_29336:
    v_29471 = cons(v_29472, v_29471);
    env = stack[-7];
    stack[-3] = v_29471;
    v_29471 = stack[-1];
    v_29471 = (v_29471 == nil ? lisp_true : nil);
    stack[-1] = v_29471;
    v_29471 = stack[-4];
    v_29471 = qcdr(v_29471);
    stack[-4] = v_29471;
    goto v_29296;
v_29297:
    v_29471 = stack[-5];
    if (v_29471 == nil) goto v_29346;
    else goto v_29347;
v_29346:
    goto v_29354;
v_29350:
    goto v_29351;
v_29352:
    goto v_29361;
v_29357:
    v_29472 = stack[-3];
    goto v_29358;
v_29359:
    v_29471 = stack[-4];
    goto v_29360;
v_29361:
    goto v_29357;
v_29358:
    goto v_29359;
v_29360:
    fn = elt(env, 1); // reversip2
    v_29471 = (*qfn2(fn))(fn, v_29472, v_29471);
    goto v_29353;
v_29354:
    goto v_29350;
v_29351:
    goto v_29352;
v_29353:
    {
        LispObject v_29480 = stack[0];
        return cons(v_29480, v_29471);
    }
v_29347:
    v_29471 = stack[-3];
    if (v_29471 == nil) goto v_29366;
    else goto v_29367;
v_29366:
    goto v_29374;
v_29370:
    goto v_29371;
v_29372:
    goto v_29381;
v_29377:
    v_29472 = stack[-5];
    goto v_29378;
v_29379:
    v_29471 = stack[-4];
    goto v_29380;
v_29381:
    goto v_29377;
v_29378:
    goto v_29379;
v_29380:
    fn = elt(env, 1); // reversip2
    v_29471 = (*qfn2(fn))(fn, v_29472, v_29471);
    goto v_29373;
v_29374:
    goto v_29370;
v_29371:
    goto v_29372;
v_29373:
    {
        LispObject v_29481 = stack[0];
        return cons(v_29481, v_29471);
    }
v_29367:
    v_29471 = stack[-3];
    v_29471 = qcar(v_29471);
    stack[-2] = v_29471;
    goto v_29398;
v_29394:
    v_29472 = stack[-6];
    goto v_29395;
v_29396:
    v_29471 = stack[-2];
    goto v_29397;
v_29398:
    goto v_29394;
v_29395:
    goto v_29396;
v_29397:
    if (equal(v_29472, v_29471)) goto v_29392;
    else goto v_29393;
v_29392:
    goto v_29406;
v_29402:
    v_29472 = stack[-6];
    goto v_29403;
v_29404:
    v_29471 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29405;
v_29406:
    goto v_29402;
v_29403:
    goto v_29404;
v_29405:
    v_29471 = (LispObject)greaterp2(v_29472, v_29471);
    v_29471 = v_29471 ? lisp_true : nil;
    env = stack[-7];
    goto v_29391;
v_29393:
    v_29471 = nil;
    goto v_29391;
    v_29471 = nil;
v_29391:
    if (v_29471 == nil) goto v_29389;
    v_29471 = nil;
    goto v_29295;
v_29389:
    goto v_29422;
v_29418:
    v_29472 = stack[-6];
    goto v_29419;
v_29420:
    v_29471 = stack[-2];
    goto v_29421;
v_29422:
    goto v_29418;
v_29419:
    goto v_29420;
v_29421:
    v_29471 = (LispObject)greaterp2(v_29472, v_29471);
    v_29471 = v_29471 ? lisp_true : nil;
    env = stack[-7];
    if (v_29471 == nil) goto v_29416;
    goto v_29298;
v_29416:
    goto v_29430;
v_29426:
    v_29472 = stack[-2];
    goto v_29427;
v_29428:
    v_29471 = stack[-4];
    goto v_29429;
v_29430:
    goto v_29426;
v_29427:
    goto v_29428;
v_29429:
    v_29471 = cons(v_29472, v_29471);
    env = stack[-7];
    stack[-4] = v_29471;
    v_29471 = stack[-3];
    v_29471 = qcdr(v_29471);
    stack[-3] = v_29471;
    v_29471 = stack[-1];
    v_29471 = (v_29471 == nil ? lisp_true : nil);
    stack[-1] = v_29471;
    goto v_29297;
v_29298:
    goto v_29442;
v_29438:
    v_29472 = stack[-6];
    goto v_29439;
v_29440:
    v_29471 = stack[-4];
    goto v_29441;
v_29442:
    goto v_29438;
v_29439:
    goto v_29440;
v_29441:
    v_29471 = cons(v_29472, v_29471);
    env = stack[-7];
    stack[-4] = v_29471;
    v_29471 = stack[-5];
    v_29471 = qcdr(v_29471);
    stack[-5] = v_29471;
    v_29471 = stack[-1];
    if (v_29471 == nil) goto v_29450;
    goto v_29459;
v_29455:
    v_29472 = stack[-6];
    goto v_29456;
v_29457:
    v_29471 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29458;
v_29459:
    goto v_29455;
v_29456:
    goto v_29457;
v_29458:
    v_29471 = (LispObject)greaterp2(v_29472, v_29471);
    v_29471 = v_29471 ? lisp_true : nil;
    env = stack[-7];
    if (v_29471 == nil) goto v_29450;
    v_29471 = stack[0];
    v_29471 = negate(v_29471);
    env = stack[-7];
    stack[0] = v_29471;
    goto v_29448;
v_29450:
v_29448:
    v_29471 = stack[-5];
    if (v_29471 == nil) goto v_29467;
    v_29471 = stack[-5];
    v_29471 = qcar(v_29471);
    stack[-6] = v_29471;
    goto v_29465;
v_29467:
v_29465:
    goto v_29297;
v_29295:
    return onevalue(v_29471);
}



// Code for talp_lssimpl

static LispObject CC_talp_lssimpl(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29416, v_29417, v_29418;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    v_29416 = stack[0];
    fn = elt(env, 4); // talp_rnf
    v_29416 = (*qfn1(fn))(fn, v_29416);
    env = stack[-5];
    stack[0] = v_29416;
    v_29416 = stack[0];
    if (!consp(v_29416)) goto v_29298;
    else goto v_29299;
v_29298:
    v_29416 = lisp_true;
    goto v_29297;
v_29299:
    v_29416 = stack[0];
    fn = elt(env, 5); // talp_atfp
    v_29416 = (*qfn1(fn))(fn, v_29416);
    env = stack[-5];
    goto v_29297;
    v_29416 = nil;
v_29297:
    if (v_29416 == nil) goto v_29295;
    v_29416 = stack[0];
    goto v_29289;
v_29295:
    v_29416 = stack[0];
    fn = elt(env, 6); // talp_op
    v_29416 = (*qfn1(fn))(fn, v_29416);
    env = stack[-5];
    v_29418 = v_29416;
    goto v_29321;
v_29317:
    v_29417 = v_29418;
    goto v_29318;
v_29319:
    v_29416 = elt(env, 1); // or
    goto v_29320;
v_29321:
    goto v_29317;
v_29318:
    goto v_29319;
v_29320:
    if (v_29417 == v_29416) goto v_29315;
    else goto v_29316;
v_29315:
    v_29416 = lisp_true;
    goto v_29314;
v_29316:
    goto v_29331;
v_29327:
    v_29417 = v_29418;
    goto v_29328;
v_29329:
    v_29416 = elt(env, 2); // and
    goto v_29330;
v_29331:
    goto v_29327;
v_29328:
    goto v_29329;
v_29330:
    v_29416 = (v_29417 == v_29416 ? lisp_true : nil);
    goto v_29314;
    v_29416 = nil;
v_29314:
    if (v_29416 == nil) goto v_29312;
    goto v_29342;
v_29338:
    stack[-4] = v_29418;
    goto v_29339;
v_29340:
    v_29416 = stack[0];
    fn = elt(env, 7); // talp_argl
    v_29416 = (*qfn1(fn))(fn, v_29416);
    env = stack[-5];
    stack[-3] = v_29416;
    v_29416 = stack[-3];
    if (v_29416 == nil) goto v_29354;
    else goto v_29355;
v_29354:
    v_29416 = nil;
    goto v_29348;
v_29355:
    v_29416 = stack[-3];
    v_29416 = qcar(v_29416);
    v_29416 = CC_talp_lssimpl(elt(env, 0), v_29416);
    env = stack[-5];
    v_29416 = ncons(v_29416);
    env = stack[-5];
    stack[-1] = v_29416;
    stack[-2] = v_29416;
v_29349:
    v_29416 = stack[-3];
    v_29416 = qcdr(v_29416);
    stack[-3] = v_29416;
    v_29416 = stack[-3];
    if (v_29416 == nil) goto v_29368;
    else goto v_29369;
v_29368:
    v_29416 = stack[-2];
    goto v_29348;
v_29369:
    goto v_29377;
v_29373:
    stack[0] = stack[-1];
    goto v_29374;
v_29375:
    v_29416 = stack[-3];
    v_29416 = qcar(v_29416);
    v_29416 = CC_talp_lssimpl(elt(env, 0), v_29416);
    env = stack[-5];
    v_29416 = ncons(v_29416);
    env = stack[-5];
    goto v_29376;
v_29377:
    goto v_29373;
v_29374:
    goto v_29375;
v_29376:
    v_29416 = Lrplacd(nil, stack[0], v_29416);
    env = stack[-5];
    v_29416 = stack[-1];
    v_29416 = qcdr(v_29416);
    stack[-1] = v_29416;
    goto v_29349;
v_29348:
    goto v_29341;
v_29342:
    goto v_29338;
v_29339:
    goto v_29340;
v_29341:
    v_29416 = cons(stack[-4], v_29416);
    env = stack[-5];
    fn = elt(env, 8); // talp_lssimpl1
    v_29416 = (*qfn1(fn))(fn, v_29416);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_29416);
    }
v_29312:
    goto v_29393;
v_29389:
    v_29417 = v_29418;
    goto v_29390;
v_29391:
    v_29416 = elt(env, 3); // (ex all)
    goto v_29392;
v_29393:
    goto v_29389;
v_29390:
    goto v_29391;
v_29392:
    v_29416 = Lmemq(nil, v_29417, v_29416);
    if (v_29416 == nil) goto v_29388;
    goto v_29405;
v_29399:
    stack[-2] = v_29418;
    goto v_29400;
v_29401:
    v_29416 = stack[0];
    v_29416 = qcdr(v_29416);
    stack[-1] = qcar(v_29416);
    goto v_29402;
v_29403:
    v_29416 = stack[0];
    v_29416 = qcdr(v_29416);
    v_29416 = qcdr(v_29416);
    v_29416 = qcar(v_29416);
    v_29416 = CC_talp_lssimpl(elt(env, 0), v_29416);
    env = stack[-5];
    v_29416 = ncons(v_29416);
    env = stack[-5];
    goto v_29404;
v_29405:
    goto v_29399;
v_29400:
    goto v_29401;
v_29402:
    goto v_29403;
v_29404:
    v_29416 = list2star(stack[-2], stack[-1], v_29416);
    env = stack[-5];
    {
        fn = elt(env, 4); // talp_rnf
        return (*qfn1(fn))(fn, v_29416);
    }
v_29388:
    v_29416 = nil;
v_29289:
    return onevalue(v_29416);
}



// Code for pasf_lnegrel

static LispObject CC_pasf_lnegrel(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29380, v_29381, v_29382;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29382 = v_29285;
// end of prologue
    goto v_29295;
v_29291:
    v_29381 = v_29382;
    goto v_29292;
v_29293:
    v_29380 = elt(env, 1); // equal
    goto v_29294;
v_29295:
    goto v_29291;
v_29292:
    goto v_29293;
v_29294:
    if (v_29381 == v_29380) goto v_29289;
    else goto v_29290;
v_29289:
    v_29380 = elt(env, 2); // neq
    goto v_29288;
v_29290:
    goto v_29305;
v_29301:
    v_29381 = v_29382;
    goto v_29302;
v_29303:
    v_29380 = elt(env, 2); // neq
    goto v_29304;
v_29305:
    goto v_29301;
v_29302:
    goto v_29303;
v_29304:
    if (v_29381 == v_29380) goto v_29299;
    else goto v_29300;
v_29299:
    v_29380 = elt(env, 1); // equal
    goto v_29288;
v_29300:
    goto v_29315;
v_29311:
    v_29381 = v_29382;
    goto v_29312;
v_29313:
    v_29380 = elt(env, 3); // leq
    goto v_29314;
v_29315:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    if (v_29381 == v_29380) goto v_29309;
    else goto v_29310;
v_29309:
    v_29380 = elt(env, 4); // greaterp
    goto v_29288;
v_29310:
    goto v_29325;
v_29321:
    v_29381 = v_29382;
    goto v_29322;
v_29323:
    v_29380 = elt(env, 5); // lessp
    goto v_29324;
v_29325:
    goto v_29321;
v_29322:
    goto v_29323;
v_29324:
    if (v_29381 == v_29380) goto v_29319;
    else goto v_29320;
v_29319:
    v_29380 = elt(env, 6); // geq
    goto v_29288;
v_29320:
    goto v_29335;
v_29331:
    v_29381 = v_29382;
    goto v_29332;
v_29333:
    v_29380 = elt(env, 6); // geq
    goto v_29334;
v_29335:
    goto v_29331;
v_29332:
    goto v_29333;
v_29334:
    if (v_29381 == v_29380) goto v_29329;
    else goto v_29330;
v_29329:
    v_29380 = elt(env, 5); // lessp
    goto v_29288;
v_29330:
    goto v_29345;
v_29341:
    v_29381 = v_29382;
    goto v_29342;
v_29343:
    v_29380 = elt(env, 4); // greaterp
    goto v_29344;
v_29345:
    goto v_29341;
v_29342:
    goto v_29343;
v_29344:
    if (v_29381 == v_29380) goto v_29339;
    else goto v_29340;
v_29339:
    v_29380 = elt(env, 3); // leq
    goto v_29288;
v_29340:
    goto v_29355;
v_29351:
    v_29381 = v_29382;
    goto v_29352;
v_29353:
    v_29380 = elt(env, 7); // cong
    goto v_29354;
v_29355:
    goto v_29351;
v_29352:
    goto v_29353;
v_29354:
    if (v_29381 == v_29380) goto v_29349;
    else goto v_29350;
v_29349:
    v_29380 = elt(env, 8); // ncong
    goto v_29288;
v_29350:
    goto v_29365;
v_29361:
    v_29381 = v_29382;
    goto v_29362;
v_29363:
    v_29380 = elt(env, 8); // ncong
    goto v_29364;
v_29365:
    goto v_29361;
v_29362:
    goto v_29363;
v_29364:
    if (v_29381 == v_29380) goto v_29359;
    else goto v_29360;
v_29359:
    v_29380 = elt(env, 7); // cong
    goto v_29288;
v_29360:
    goto v_29377;
v_29373:
    v_29380 = elt(env, 9); // "pasf_lnegrel: unknown operator"
    goto v_29374;
v_29375:
    v_29381 = v_29382;
    goto v_29376;
v_29377:
    goto v_29373;
v_29374:
    goto v_29375;
v_29376:
    v_29380 = list2(v_29380, v_29381);
    env = stack[0];
    {
        fn = elt(env, 10); // rederr
        return (*qfn1(fn))(fn, v_29380);
    }
    v_29380 = nil;
v_29288:
    return onevalue(v_29380);
}



// Code for addexptsdf

static LispObject CC_addexptsdf(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29350, v_29351;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    stack[-2] = nil;
v_29291:
    v_29350 = stack[-1];
    if (v_29350 == nil) goto v_29294;
    else goto v_29295;
v_29294:
    v_29350 = stack[0];
    if (v_29350 == nil) goto v_29299;
    else goto v_29300;
v_29299:
    v_29350 = stack[-2];
    {
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(fn, v_29350);
    }
v_29300:
    goto v_29311;
v_29307:
    stack[0] = stack[-2];
    goto v_29308;
v_29309:
    v_29350 = elt(env, 1); // "X too long"
    fn = elt(env, 4); // interr
    v_29350 = (*qfn1(fn))(fn, v_29350);
    env = stack[-3];
    goto v_29310;
v_29311:
    goto v_29307;
v_29308:
    goto v_29309;
v_29310:
    {
        LispObject v_29355 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_29355, v_29350);
    }
    goto v_29293;
v_29295:
    v_29350 = stack[0];
    if (v_29350 == nil) goto v_29315;
    else goto v_29316;
v_29315:
    goto v_29323;
v_29319:
    stack[0] = stack[-2];
    goto v_29320;
v_29321:
    v_29350 = elt(env, 2); // "Y too long"
    fn = elt(env, 4); // interr
    v_29350 = (*qfn1(fn))(fn, v_29350);
    env = stack[-3];
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    {
        LispObject v_29356 = stack[0];
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(fn, v_29356, v_29350);
    }
v_29316:
    goto v_29334;
v_29330:
    goto v_29340;
v_29336:
    v_29350 = stack[-1];
    v_29351 = qcar(v_29350);
    goto v_29337;
v_29338:
    v_29350 = stack[0];
    v_29350 = qcar(v_29350);
    goto v_29339;
v_29340:
    goto v_29336;
v_29337:
    goto v_29338;
v_29339:
    fn = elt(env, 5); // exptplus
    v_29351 = (*qfn2(fn))(fn, v_29351, v_29350);
    env = stack[-3];
    goto v_29331;
v_29332:
    v_29350 = stack[-2];
    goto v_29333;
v_29334:
    goto v_29330;
v_29331:
    goto v_29332;
v_29333:
    v_29350 = cons(v_29351, v_29350);
    env = stack[-3];
    stack[-2] = v_29350;
    v_29350 = stack[-1];
    v_29350 = qcdr(v_29350);
    stack[-1] = v_29350;
    v_29350 = stack[0];
    v_29350 = qcdr(v_29350);
    stack[0] = v_29350;
    goto v_29291;
v_29293:
    v_29350 = nil;
    return onevalue(v_29350);
}



// Code for lengthn

static LispObject CC_lengthn(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29315;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    v_29315 = stack[0];
    if (v_29315 == nil) goto v_29289;
    else goto v_29290;
v_29289:
    v_29315 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29288;
v_29290:
    v_29315 = stack[0];
    v_29315 = qcar(v_29315);
    if (is_number(v_29315)) goto v_29293;
    else goto v_29294;
v_29293:
    goto v_29302;
v_29298:
    v_29315 = stack[0];
    v_29315 = qcar(v_29315);
    stack[-1] = sub1(v_29315);
    env = stack[-2];
    goto v_29299;
v_29300:
    v_29315 = stack[0];
    v_29315 = qcdr(v_29315);
    v_29315 = CC_lengthn(elt(env, 0), v_29315);
    goto v_29301;
v_29302:
    goto v_29298;
v_29299:
    goto v_29300;
v_29301:
    {
        LispObject v_29318 = stack[-1];
        return plus2(v_29318, v_29315);
    }
v_29294:
    v_29315 = stack[0];
    v_29315 = qcdr(v_29315);
    v_29315 = CC_lengthn(elt(env, 0), v_29315);
    return add1(v_29315);
    v_29315 = nil;
v_29288:
    return onevalue(v_29315);
}



// Code for spmatlength

static LispObject CC_spmatlength(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29358, v_29359, v_29360, v_29361;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_29360 = v_29285;
// end of prologue
    v_29358 = v_29360;
    v_29358 = Lconsp(nil, v_29358);
    env = stack[-2];
    if (v_29358 == nil) goto v_29294;
    v_29358 = v_29360;
    goto v_29292;
v_29294:
    v_29358 = v_29360;
    if (!symbolp(v_29358)) v_29358 = nil;
    else { v_29358 = qfastgets(v_29358);
           if (v_29358 != nil) { v_29358 = elt(v_29358, 4); // avalue
#ifdef RECORD_GET
             if (v_29358 != SPID_NOPROP)
                record_get(elt(fastget_names, 4), 1);
             else record_get(elt(fastget_names, 4), 0),
                v_29358 = nil; }
           else record_get(elt(fastget_names, 4), 0); }
#else
             if (v_29358 == SPID_NOPROP) v_29358 = nil; }}
#endif
    v_29358 = qcdr(v_29358);
    v_29358 = qcar(v_29358);
    goto v_29292;
v_29292:
    v_29359 = v_29358;
    v_29359 = qcdr(v_29359);
    v_29359 = qcdr(v_29359);
    v_29359 = qcar(v_29359);
    v_29359 = qcdr(v_29359);
    v_29361 = v_29359;
    goto v_29318;
v_29314:
    v_29359 = v_29358;
    goto v_29315;
v_29316:
    v_29358 = elt(env, 1); // sparsemat
    goto v_29317;
v_29318:
    goto v_29314;
v_29315:
    goto v_29316;
v_29317:
    if (!consp(v_29359)) goto v_29311;
    v_29359 = qcar(v_29359);
    if (v_29359 == v_29358) goto v_29312;
v_29311:
    goto v_29328;
v_29322:
    stack[-1] = elt(env, 2); // matrix
    goto v_29323;
v_29324:
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    goto v_29325;
v_29326:
    goto v_29338;
v_29332:
    v_29359 = elt(env, 3); // "Matrix"
    goto v_29333;
v_29334:
    goto v_29335;
v_29336:
    v_29358 = elt(env, 4); // "not set"
    goto v_29337;
v_29338:
    goto v_29332;
v_29333:
    goto v_29334;
v_29335:
    goto v_29336;
v_29337:
    v_29358 = list3(v_29359, v_29360, v_29358);
    env = stack[-2];
    goto v_29327;
v_29328:
    goto v_29322;
v_29323:
    goto v_29324;
v_29325:
    goto v_29326;
v_29327:
    fn = elt(env, 6); // rerror
    v_29358 = (*qfnn(fn))(fn, 3, stack[-1], stack[0], v_29358);
    goto v_29310;
v_29312:
    goto v_29351;
v_29345:
    v_29359 = elt(env, 5); // list
    goto v_29346;
v_29347:
    v_29358 = v_29361;
    v_29358 = qcar(v_29358);
    goto v_29348;
v_29349:
    v_29360 = v_29361;
    v_29360 = qcdr(v_29360);
    v_29360 = qcar(v_29360);
    goto v_29350;
v_29351:
    goto v_29345;
v_29346:
    goto v_29347;
v_29348:
    goto v_29349;
v_29350:
    return list3(v_29359, v_29358, v_29360);
v_29310:
    v_29358 = nil;
    return onevalue(v_29358);
}



// Code for groebcplistsort

static LispObject CC_groebcplistsort(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29314, v_29315;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29314 = v_29285;
// end of prologue
    v_29315 = nil;
    stack[0] = v_29314;
v_29292:
    v_29314 = stack[0];
    if (v_29314 == nil) goto v_29296;
    else goto v_29297;
v_29296:
    goto v_29291;
v_29297:
    v_29314 = stack[0];
    v_29314 = qcar(v_29314);
    goto v_29308;
v_29304:
    goto v_29305;
v_29306:
    goto v_29307;
v_29308:
    goto v_29304;
v_29305:
    goto v_29306;
v_29307:
    fn = elt(env, 1); // groebcplistsortin
    v_29314 = (*qfn2(fn))(fn, v_29314, v_29315);
    env = stack[-1];
    v_29315 = v_29314;
    v_29314 = stack[0];
    v_29314 = qcdr(v_29314);
    stack[0] = v_29314;
    goto v_29292;
v_29291:
    v_29314 = v_29315;
    return onevalue(v_29314);
}



// Code for maprintla

static LispObject CC_maprintla(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29650, v_29651, v_29652;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-1] = v_29286;
    stack[-2] = v_29285;
// end of prologue
v_29284:
    v_29650 = stack[-2];
    if (v_29650 == nil) goto v_29296;
    else goto v_29297;
v_29296:
    v_29650 = nil;
    goto v_29290;
v_29297:
    v_29650 = stack[-2];
    if (is_number(v_29650)) goto v_29300;
    else goto v_29301;
v_29300:
    goto v_29293;
v_29301:
    v_29650 = stack[-2];
    if (!consp(v_29650)) goto v_29303;
    else goto v_29304;
v_29303:
    v_29650 = stack[-2];
    {
        fn = elt(env, 15); // prinlatom
        return (*qfn1(fn))(fn, v_29650);
    }
v_29304:
    v_29650 = stack[-2];
    v_29650 = Lstringp(nil, v_29650);
    env = stack[-4];
    if (v_29650 == nil) goto v_29309;
    v_29650 = stack[-2];
    {
        fn = elt(env, 16); // prin2la
        return (*qfn1(fn))(fn, v_29650);
    }
v_29309:
    v_29650 = stack[-2];
    v_29650 = qcar(v_29650);
    if (!consp(v_29650)) goto v_29315;
    goto v_29323;
v_29319:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29320;
v_29321:
    v_29650 = stack[-1];
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    stack[-2] = v_29651;
    stack[-1] = v_29650;
    goto v_29284;
v_29315:
    goto v_29335;
v_29331:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29332;
v_29333:
    v_29650 = elt(env, 1); // laprifn
    goto v_29334;
v_29335:
    goto v_29331;
v_29332:
    goto v_29333;
v_29334:
    v_29650 = get(v_29651, v_29650);
    env = stack[-4];
    stack[-3] = v_29650;
    if (v_29650 == nil) goto v_29328;
    goto v_29353;
v_29349:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29350;
v_29351:
    v_29650 = elt(env, 2); // fulla
    goto v_29352;
v_29353:
    goto v_29349;
v_29350:
    goto v_29351;
v_29352:
    v_29650 = Lflagp(nil, v_29651, v_29650);
    env = stack[-4];
    if (v_29650 == nil) goto v_29346;
    else goto v_29347;
v_29346:
    goto v_29361;
v_29357:
    goto v_29367;
v_29363:
    stack[0] = stack[-3];
    goto v_29364;
v_29365:
    goto v_29374;
v_29370:
    v_29650 = stack[-2];
    v_29651 = qcdr(v_29650);
    goto v_29371;
v_29372:
    v_29650 = stack[-1];
    goto v_29373;
v_29374:
    goto v_29370;
v_29371:
    goto v_29372;
v_29373:
    v_29650 = list2(v_29651, v_29650);
    env = stack[-4];
    goto v_29366;
v_29367:
    goto v_29363;
v_29364:
    goto v_29365;
v_29366:
    fn = elt(env, 17); // apply
    v_29651 = (*qfn2(fn))(fn, stack[0], v_29650);
    env = stack[-4];
    goto v_29358;
v_29359:
    v_29650 = elt(env, 3); // failed
    goto v_29360;
v_29361:
    goto v_29357;
v_29358:
    goto v_29359;
v_29360:
    v_29650 = (v_29651 == v_29650 ? lisp_true : nil);
    v_29650 = (v_29650 == nil ? lisp_true : nil);
    goto v_29345;
v_29347:
    v_29650 = nil;
    goto v_29345;
    v_29650 = nil;
v_29345:
    if (v_29650 == nil) goto v_29343;
    v_29650 = lisp_true;
    goto v_29341;
v_29343:
    goto v_29396;
v_29392:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29393;
v_29394:
    v_29650 = elt(env, 2); // fulla
    goto v_29395;
v_29396:
    goto v_29392;
v_29393:
    goto v_29394;
v_29395:
    v_29650 = Lflagp(nil, v_29651, v_29650);
    env = stack[-4];
    if (v_29650 == nil) goto v_29390;
    goto v_29404;
v_29400:
    goto v_29410;
v_29406:
    stack[0] = stack[-3];
    goto v_29407;
v_29408:
    goto v_29417;
v_29413:
    v_29651 = stack[-2];
    goto v_29414;
v_29415:
    v_29650 = stack[-1];
    goto v_29416;
v_29417:
    goto v_29413;
v_29414:
    goto v_29415;
v_29416:
    v_29650 = list2(v_29651, v_29650);
    env = stack[-4];
    goto v_29409;
v_29410:
    goto v_29406;
v_29407:
    goto v_29408;
v_29409:
    fn = elt(env, 17); // apply
    v_29651 = (*qfn2(fn))(fn, stack[0], v_29650);
    env = stack[-4];
    goto v_29401;
v_29402:
    v_29650 = elt(env, 3); // failed
    goto v_29403;
v_29404:
    goto v_29400;
v_29401:
    goto v_29402;
v_29403:
    v_29650 = (v_29651 == v_29650 ? lisp_true : nil);
    v_29650 = (v_29650 == nil ? lisp_true : nil);
    goto v_29388;
v_29390:
    v_29650 = nil;
    goto v_29388;
    v_29650 = nil;
v_29388:
    goto v_29341;
    v_29650 = nil;
v_29341:
    if (v_29650 == nil) goto v_29328;
    v_29650 = stack[-2];
    goto v_29290;
v_29328:
    goto v_29434;
v_29430:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29431;
v_29432:
    v_29650 = elt(env, 4); // indexed
    goto v_29433;
v_29434:
    goto v_29430;
v_29431:
    goto v_29432;
v_29433:
    v_29650 = get(v_29651, v_29650);
    env = stack[-4];
    stack[-3] = v_29650;
    if (v_29650 == nil) goto v_29428;
    goto v_29445;
v_29439:
    v_29650 = stack[-2];
    v_29652 = qcar(v_29650);
    goto v_29440;
v_29441:
    v_29650 = stack[-2];
    v_29651 = qcdr(v_29650);
    goto v_29442;
v_29443:
    v_29650 = stack[-3];
    goto v_29444;
v_29445:
    goto v_29439;
v_29440:
    goto v_29441;
v_29442:
    goto v_29443;
v_29444:
    {
        fn = elt(env, 18); // prinidop
        return (*qfnn(fn))(fn, 3, v_29652, v_29651, v_29650);
    }
v_29428:
    v_29650 = stack[-2];
    v_29650 = qcar(v_29650);
    if (!symbolp(v_29650)) v_29650 = nil;
    else { v_29650 = qfastgets(v_29650);
           if (v_29650 != nil) { v_29650 = elt(v_29650, 23); // infix
#ifdef RECORD_GET
             if (v_29650 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_29650 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_29650 == SPID_NOPROP) v_29650 = nil; }}
#endif
    stack[-3] = v_29650;
    if (v_29650 == nil) goto v_29452;
    goto v_29291;
v_29452:
    goto v_29462;
v_29458:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29459;
v_29460:
    v_29650 = elt(env, 5); // !:rd!:
    goto v_29461;
v_29462:
    goto v_29458;
v_29459:
    goto v_29460;
v_29461:
    if (v_29651 == v_29650) goto v_29456;
    else goto v_29457;
v_29456:
// Binding !*nat
// FLUIDBIND: reloadenv=4 litvec-offset=6 saveloc=1
{   bind_fluid_stack bind_fluid_var(-4, 6, -1);
    qvalue(elt(env, 6)) = nil; // !*nat
    v_29650 = stack[-2];
    v_29650 = qcdr(v_29650);
    v_29650 = Lfloatp(nil, v_29650);
    env = stack[-4];
    if (v_29650 == nil) goto v_29473;
    v_29650 = stack[-2];
    v_29650 = qcdr(v_29650);
    v_29650 = Llengthc(nil, v_29650);
    env = stack[-4];
    goto v_29471;
v_29473:
    goto v_29487;
v_29483:
    v_29650 = stack[-2];
    v_29650 = qcdr(v_29650);
    v_29650 = qcar(v_29650);
    stack[0] = Llengthc(nil, v_29650);
    env = stack[-4];
    goto v_29484;
v_29485:
    goto v_29497;
v_29493:
    v_29650 = stack[-2];
    v_29650 = qcdr(v_29650);
    v_29650 = qcdr(v_29650);
    v_29651 = Llengthc(nil, v_29650);
    env = stack[-4];
    goto v_29494;
v_29495:
    v_29650 = (LispObject)80+TAG_FIXNUM; // 5
    goto v_29496;
v_29497:
    goto v_29493;
v_29494:
    goto v_29495;
v_29496:
    v_29650 = plus2(v_29651, v_29650);
    env = stack[-4];
    goto v_29486;
v_29487:
    goto v_29483;
v_29484:
    goto v_29485;
v_29486:
    v_29650 = plus2(stack[0], v_29650);
    env = stack[-4];
    goto v_29471;
    v_29650 = nil;
v_29471:
    stack[0] = v_29650;
    goto v_29512;
v_29508:
    goto v_29518;
v_29514:
    v_29651 = qvalue(elt(env, 7)); // ncharspr!*
    goto v_29515;
v_29516:
    v_29650 = stack[0];
    goto v_29517;
v_29518:
    goto v_29514;
v_29515:
    goto v_29516;
v_29517:
    v_29651 = plus2(v_29651, v_29650);
    env = stack[-4];
    goto v_29509;
v_29510:
    v_29650 = qvalue(elt(env, 8)); // laline!*
    goto v_29511;
v_29512:
    goto v_29508;
v_29509:
    goto v_29510;
v_29511:
    v_29650 = (LispObject)greaterp2(v_29651, v_29650);
    v_29650 = v_29650 ? lisp_true : nil;
    env = stack[-4];
    if (v_29650 == nil) goto v_29506;
    v_29650 = Lterpri(nil, 0);
    env = stack[-4];
    v_29650 = stack[0];
    qvalue(elt(env, 7)) = v_29650; // ncharspr!*
    goto v_29504;
v_29506:
    goto v_29531;
v_29527:
    v_29651 = qvalue(elt(env, 7)); // ncharspr!*
    goto v_29528;
v_29529:
    v_29650 = stack[0];
    goto v_29530;
v_29531:
    goto v_29527;
v_29528:
    goto v_29529;
v_29530:
    v_29650 = plus2(v_29651, v_29650);
    env = stack[-4];
    qvalue(elt(env, 7)) = v_29650; // ncharspr!*
    goto v_29504;
v_29504:
    v_29650 = qvalue(elt(env, 9)); // orig!*
    qvalue(elt(env, 10)) = v_29650; // posn!*
    v_29650 = stack[-2];
    fn = elt(env, 19); // rd!:prin
    v_29650 = (*qfn1(fn))(fn, v_29650);
    v_29650 = nil;
    ;}  // end of a binding scope
    goto v_29290;
v_29457:
    v_29650 = stack[-2];
    v_29650 = qcar(v_29650);
    fn = elt(env, 20); // oprinla
    v_29650 = (*qfn1(fn))(fn, v_29650);
    env = stack[-4];
    goto v_29547;
v_29541:
    v_29650 = stack[-2];
    v_29652 = qcar(v_29650);
    goto v_29542;
v_29543:
    v_29650 = stack[-2];
    v_29651 = qcdr(v_29650);
    goto v_29544;
v_29545:
    v_29650 = stack[-1];
    goto v_29546;
v_29547:
    goto v_29541;
v_29542:
    goto v_29543;
v_29544:
    goto v_29545;
v_29546:
    fn = elt(env, 21); // prinpopargs
    v_29650 = (*qfnn(fn))(fn, 3, v_29652, v_29651, v_29650);
    v_29650 = stack[-2];
    goto v_29290;
v_29291:
    goto v_29559;
v_29555:
    v_29651 = stack[-3];
    goto v_29556;
v_29557:
    v_29650 = stack[-1];
    goto v_29558;
v_29559:
    goto v_29555;
v_29556:
    goto v_29557;
v_29558:
    v_29650 = (LispObject)greaterp2(v_29651, v_29650);
    v_29650 = v_29650 ? lisp_true : nil;
    env = stack[-4];
    stack[-1] = v_29650;
    v_29650 = stack[-1];
    if (v_29650 == nil) goto v_29568;
    else goto v_29569;
v_29568:
    goto v_29575;
v_29571:
    v_29650 = stack[-2];
    v_29651 = qcar(v_29650);
    goto v_29572;
v_29573:
    v_29650 = elt(env, 11); // equal
    goto v_29574;
v_29575:
    goto v_29571;
v_29572:
    goto v_29573;
v_29574:
    v_29650 = (v_29651 == v_29650 ? lisp_true : nil);
    goto v_29567;
v_29569:
    v_29650 = nil;
    goto v_29567;
    v_29650 = nil;
v_29567:
    if (v_29650 == nil) goto v_29565;
    v_29650 = lisp_true;
    stack[-1] = v_29650;
    goto v_29563;
v_29565:
v_29563:
    v_29650 = stack[-1];
    if (v_29650 == nil) goto v_29587;
    goto v_29292;
v_29587:
    v_29650 = elt(env, 12); // !(
    fn = elt(env, 15); // prinlatom
    v_29650 = (*qfn1(fn))(fn, v_29650);
    env = stack[-4];
v_29292:
    goto v_29598;
v_29592:
    v_29650 = stack[-2];
    v_29652 = qcar(v_29650);
    goto v_29593;
v_29594:
    v_29651 = stack[-3];
    goto v_29595;
v_29596:
    v_29650 = stack[-2];
    v_29650 = qcdr(v_29650);
    goto v_29597;
v_29598:
    goto v_29592;
v_29593:
    goto v_29594;
v_29595:
    goto v_29596;
v_29597:
    fn = elt(env, 22); // inprinla
    v_29650 = (*qfnn(fn))(fn, 3, v_29652, v_29651, v_29650);
    env = stack[-4];
    v_29650 = stack[-1];
    if (v_29650 == nil) goto v_29607;
    v_29650 = stack[-2];
    goto v_29290;
v_29607:
    v_29650 = elt(env, 13); // !)
    fn = elt(env, 15); // prinlatom
    v_29650 = (*qfn1(fn))(fn, v_29650);
    v_29650 = stack[-2];
    goto v_29290;
v_29293:
    goto v_29626;
v_29622:
    v_29651 = stack[-2];
    goto v_29623;
v_29624:
    v_29650 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29625;
v_29626:
    goto v_29622;
v_29623:
    goto v_29624;
v_29625:
    v_29650 = (LispObject)lessp2(v_29651, v_29650);
    v_29650 = v_29650 ? lisp_true : nil;
    env = stack[-4];
    if (v_29650 == nil) goto v_29619;
    else goto v_29620;
v_29619:
    v_29650 = lisp_true;
    goto v_29618;
v_29620:
    goto v_29637;
v_29633:
    v_29651 = stack[-1];
    goto v_29634;
v_29635:
    v_29650 = elt(env, 14); // minus
    if (!symbolp(v_29650)) v_29650 = nil;
    else { v_29650 = qfastgets(v_29650);
           if (v_29650 != nil) { v_29650 = elt(v_29650, 23); // infix
#ifdef RECORD_GET
             if (v_29650 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_29650 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_29650 == SPID_NOPROP) v_29650 = nil; }}
#endif
    goto v_29636;
v_29637:
    goto v_29633;
v_29634:
    goto v_29635;
v_29636:
    v_29650 = (LispObject)lessp2(v_29651, v_29650);
    v_29650 = v_29650 ? lisp_true : nil;
    env = stack[-4];
    goto v_29618;
    v_29650 = nil;
v_29618:
    if (v_29650 == nil) goto v_29616;
    v_29650 = stack[-2];
    {
        fn = elt(env, 16); // prin2la
        return (*qfn1(fn))(fn, v_29650);
    }
v_29616:
    v_29650 = elt(env, 12); // !(
    fn = elt(env, 16); // prin2la
    v_29650 = (*qfn1(fn))(fn, v_29650);
    env = stack[-4];
    v_29650 = stack[-2];
    fn = elt(env, 16); // prin2la
    v_29650 = (*qfn1(fn))(fn, v_29650);
    env = stack[-4];
    v_29650 = elt(env, 13); // !)
    fn = elt(env, 16); // prin2la
    v_29650 = (*qfn1(fn))(fn, v_29650);
    v_29650 = stack[-2];
v_29290:
    return onevalue(v_29650);
}



// Code for !:log10

static LispObject CC_Tlog10(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29327, v_29328;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    goto v_29295;
v_29291:
    v_29328 = elt(env, 0); // !:log10
    goto v_29292;
v_29293:
    v_29327 = stack[0];
    goto v_29294;
v_29295:
    goto v_29291;
v_29292:
    goto v_29293;
v_29294:
    fn = elt(env, 3); // get!:const
    v_29327 = (*qfn2(fn))(fn, v_29328, v_29327);
    env = stack[-2];
    stack[-1] = v_29327;
    goto v_29306;
v_29302:
    v_29328 = stack[-1];
    goto v_29303;
v_29304:
    v_29327 = elt(env, 1); // not_found
    goto v_29305;
v_29306:
    goto v_29302;
v_29303:
    goto v_29304;
v_29305:
    if (v_29328 == v_29327) goto v_29301;
    v_29327 = stack[-1];
    goto v_29289;
v_29301:
    goto v_29315;
v_29311:
    v_29328 = qvalue(elt(env, 2)); // bften!*
    goto v_29312;
v_29313:
    v_29327 = stack[0];
    goto v_29314;
v_29315:
    goto v_29311;
v_29312:
    goto v_29313;
v_29314:
    fn = elt(env, 4); // log!:
    v_29327 = (*qfn2(fn))(fn, v_29328, v_29327);
    env = stack[-2];
    stack[-1] = v_29327;
    goto v_29323;
v_29319:
    v_29328 = elt(env, 0); // !:log10
    goto v_29320;
v_29321:
    v_29327 = stack[-1];
    goto v_29322;
v_29323:
    goto v_29319;
v_29320:
    goto v_29321;
v_29322:
    fn = elt(env, 5); // save!:const
    v_29327 = (*qfn2(fn))(fn, v_29328, v_29327);
    v_29327 = stack[-1];
v_29289:
    return onevalue(v_29327);
}



// Code for pnth!*

static LispObject CC_pnthH(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29313, v_29314, v_29315;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29314 = v_29286;
    stack[0] = v_29285;
// end of prologue
v_29290:
    v_29313 = stack[0];
    if (v_29313 == nil) goto v_29293;
    else goto v_29294;
v_29293:
    v_29313 = nil;
    goto v_29289;
v_29294:
    goto v_29303;
v_29299:
    v_29315 = v_29314;
    goto v_29300;
v_29301:
    v_29313 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29302;
v_29303:
    goto v_29299;
v_29300:
    goto v_29301;
v_29302:
    if (v_29315 == v_29313) goto v_29297;
    else goto v_29298;
v_29297:
    v_29313 = stack[0];
    goto v_29289;
v_29298:
    v_29313 = stack[0];
    v_29313 = qcdr(v_29313);
    stack[0] = v_29313;
    v_29313 = v_29314;
    v_29313 = sub1(v_29313);
    env = stack[-1];
    v_29314 = v_29313;
    goto v_29290;
    v_29313 = nil;
v_29289:
    return onevalue(v_29313);
}



// Code for sub01

static LispObject CC_sub01(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29326, v_29327, v_29328;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    v_29328 = nil;
v_29291:
    v_29326 = stack[0];
    if (v_29326 == nil) goto v_29295;
    goto v_29302;
v_29298:
    goto v_29311;
v_29307:
    v_29326 = stack[0];
    v_29327 = qcar(v_29326);
    goto v_29308;
v_29309:
    v_29326 = stack[-1];
    goto v_29310;
v_29311:
    goto v_29307;
v_29308:
    goto v_29309;
v_29310:
    if (equal(v_29327, v_29326)) goto v_29305;
    else goto v_29306;
v_29305:
    v_29326 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29304;
v_29306:
    v_29326 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29304;
    v_29326 = nil;
v_29304:
    goto v_29299;
v_29300:
    v_29327 = v_29328;
    goto v_29301;
v_29302:
    goto v_29298;
v_29299:
    goto v_29300;
v_29301:
    v_29326 = cons(v_29326, v_29327);
    env = stack[-2];
    v_29328 = v_29326;
    v_29326 = stack[0];
    v_29326 = qcdr(v_29326);
    stack[0] = v_29326;
    goto v_29291;
v_29295:
    v_29326 = v_29328;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_29326);
    }
    v_29326 = nil;
    return onevalue(v_29326);
}



// Code for replace!-next

static LispObject CC_replaceKnext(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29336, v_29337, v_29338, v_29339;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_29286;
    stack[-1] = v_29285;
// end of prologue
    stack[-2] = nil;
v_29291:
    v_29336 = stack[-1];
    if (v_29336 == nil) goto v_29294;
    else goto v_29295;
v_29294:
    v_29336 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_29336);
    }
v_29295:
    goto v_29306;
v_29302:
    goto v_29316;
v_29308:
    v_29336 = stack[-1];
    v_29336 = qcar(v_29336);
    v_29339 = qcar(v_29336);
    goto v_29309;
v_29310:
    v_29336 = stack[-1];
    v_29336 = qcar(v_29336);
    v_29336 = qcdr(v_29336);
    v_29338 = qcar(v_29336);
    goto v_29311;
v_29312:
    v_29336 = stack[-1];
    v_29336 = qcar(v_29336);
    v_29336 = qcdr(v_29336);
    v_29336 = qcdr(v_29336);
    v_29337 = qcar(v_29336);
    goto v_29313;
v_29314:
    v_29336 = stack[0];
    v_29336 = qcar(v_29336);
    goto v_29315;
v_29316:
    goto v_29308;
v_29309:
    goto v_29310;
v_29311:
    goto v_29312;
v_29313:
    goto v_29314;
v_29315:
    v_29337 = list4(v_29339, v_29338, v_29337, v_29336);
    env = stack[-3];
    goto v_29303;
v_29304:
    v_29336 = stack[-2];
    goto v_29305;
v_29306:
    goto v_29302;
v_29303:
    goto v_29304;
v_29305:
    v_29336 = cons(v_29337, v_29336);
    env = stack[-3];
    stack[-2] = v_29336;
    v_29336 = stack[-1];
    v_29336 = qcdr(v_29336);
    stack[-1] = v_29336;
    v_29336 = stack[0];
    v_29336 = qcdr(v_29336);
    stack[0] = v_29336;
    goto v_29291;
    v_29336 = nil;
    return onevalue(v_29336);
}



// Code for mk!+inner!+product

static LispObject CC_mkLinnerLproduct(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29382, v_29383;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-1] = v_29286;
    stack[-3] = v_29285;
// end of prologue
    goto v_29301;
v_29297:
    v_29382 = stack[-3];
    fn = elt(env, 4); // get!+vec!+dim
    stack[0] = (*qfn1(fn))(fn, v_29382);
    env = stack[-5];
    goto v_29298;
v_29299:
    v_29382 = stack[-1];
    fn = elt(env, 4); // get!+vec!+dim
    v_29382 = (*qfn1(fn))(fn, v_29382);
    env = stack[-5];
    goto v_29300;
v_29301:
    goto v_29297;
v_29298:
    goto v_29299;
v_29300:
    if (equal(stack[0], v_29382)) goto v_29296;
    v_29382 = elt(env, 1); // "wrong dimensions in innerproduct"
    fn = elt(env, 5); // rederr
    v_29382 = (*qfn1(fn))(fn, v_29382);
    env = stack[-5];
    goto v_29294;
v_29296:
v_29294:
    goto v_29313;
v_29309:
    v_29383 = nil;
    goto v_29310;
v_29311:
    v_29382 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_29312;
v_29313:
    goto v_29309;
v_29310:
    goto v_29311;
v_29312:
    v_29382 = cons(v_29383, v_29382);
    env = stack[-5];
    stack[0] = v_29382;
    v_29382 = qvalue(elt(env, 2)); // !*complex
    if (v_29382 == nil) goto v_29319;
    v_29382 = stack[-1];
    fn = elt(env, 6); // mk!+conjugate!+vec
    v_29382 = (*qfn1(fn))(fn, v_29382);
    env = stack[-5];
    stack[-4] = v_29382;
    goto v_29317;
v_29319:
    v_29382 = stack[-1];
    stack[-4] = v_29382;
    goto v_29317;
v_29317:
    v_29382 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = v_29382;
v_29329:
    goto v_29341;
v_29337:
    v_29382 = stack[-3];
    fn = elt(env, 4); // get!+vec!+dim
    v_29383 = (*qfn1(fn))(fn, v_29382);
    env = stack[-5];
    goto v_29338;
v_29339:
    v_29382 = stack[-2];
    goto v_29340;
v_29341:
    goto v_29337;
v_29338:
    goto v_29339;
v_29340:
    v_29382 = difference2(v_29383, v_29382);
    env = stack[-5];
    v_29382 = Lminusp(nil, v_29382);
    env = stack[-5];
    if (v_29382 == nil) goto v_29334;
    goto v_29328;
v_29334:
    goto v_29351;
v_29347:
    stack[-1] = stack[0];
    goto v_29348;
v_29349:
    goto v_29358;
v_29354:
    goto v_29364;
v_29360:
    v_29383 = stack[-3];
    goto v_29361;
v_29362:
    v_29382 = stack[-2];
    goto v_29363;
v_29364:
    goto v_29360;
v_29361:
    goto v_29362;
v_29363:
    fn = elt(env, 7); // get!+vec!+entry
    stack[0] = (*qfn2(fn))(fn, v_29383, v_29382);
    env = stack[-5];
    goto v_29355;
v_29356:
    goto v_29372;
v_29368:
    v_29383 = stack[-4];
    goto v_29369;
v_29370:
    v_29382 = stack[-2];
    goto v_29371;
v_29372:
    goto v_29368;
v_29369:
    goto v_29370;
v_29371:
    fn = elt(env, 7); // get!+vec!+entry
    v_29382 = (*qfn2(fn))(fn, v_29383, v_29382);
    env = stack[-5];
    goto v_29357;
v_29358:
    goto v_29354;
v_29355:
    goto v_29356;
v_29357:
    fn = elt(env, 8); // multsq
    v_29382 = (*qfn2(fn))(fn, stack[0], v_29382);
    env = stack[-5];
    goto v_29350;
v_29351:
    goto v_29347;
v_29348:
    goto v_29349;
v_29350:
    fn = elt(env, 9); // addsq
    v_29382 = (*qfn2(fn))(fn, stack[-1], v_29382);
    env = stack[-5];
    stack[0] = v_29382;
    v_29382 = stack[-2];
    v_29382 = add1(v_29382);
    env = stack[-5];
    stack[-2] = v_29382;
    goto v_29329;
v_29328:
    v_29382 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=5 litvec-offset=3 saveloc=1
{   bind_fluid_stack bind_fluid_var(-5, 3, -1);
    qvalue(elt(env, 3)) = v_29382; // !*sub2
    v_29382 = stack[0];
    fn = elt(env, 10); // subs2
    v_29382 = (*qfn1(fn))(fn, v_29382);
    stack[0] = v_29382;
    ;}  // end of a binding scope
    v_29382 = stack[0];
    return onevalue(v_29382);
}



// Code for dim!<!=deg

static LispObject CC_dimRMdeg(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29323, v_29324;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29323 = v_29285;
// end of prologue
    goto v_29292;
v_29288:
    stack[0] = qvalue(elt(env, 1)); // dimex!*
    goto v_29289;
v_29290:
    fn = elt(env, 2); // deg!*form
    v_29323 = (*qfn1(fn))(fn, v_29323);
    env = stack[-1];
    fn = elt(env, 3); // negf
    v_29323 = (*qfn1(fn))(fn, v_29323);
    env = stack[-1];
    goto v_29291;
v_29292:
    goto v_29288;
v_29289:
    goto v_29290;
v_29291:
    fn = elt(env, 4); // addf
    v_29323 = (*qfn2(fn))(fn, stack[0], v_29323);
    v_29324 = v_29323;
    v_29323 = v_29324;
    if (v_29323 == nil) goto v_29300;
    else goto v_29301;
v_29300:
    v_29323 = lisp_true;
    goto v_29299;
v_29301:
    v_29323 = v_29324;
    v_29323 = integerp(v_29323);
    if (v_29323 == nil) goto v_29308;
    else goto v_29309;
v_29308:
    v_29323 = nil;
    goto v_29307;
v_29309:
    goto v_29320;
v_29316:
    goto v_29317;
v_29318:
    v_29323 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29319;
v_29320:
    goto v_29316;
v_29317:
    goto v_29318;
v_29319:
        return Lleq(nil, v_29324, v_29323);
    v_29323 = nil;
v_29307:
    goto v_29299;
    v_29323 = nil;
v_29299:
    return onevalue(v_29323);
}



// Code for endofstmtp

static LispObject CC_endofstmtp(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_29299, v_29300;
    argcheck(nargs, 0, "endofstmtp");
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    goto v_29294;
v_29290:
    v_29299 = qvalue(elt(env, 1)); // cursym!*
    goto v_29291;
v_29292:
    v_29300 = elt(env, 2); // (!*semicol!* !*rsqbkt!* end)
    goto v_29293;
v_29294:
    goto v_29290;
v_29291:
    goto v_29292;
v_29293:
    v_29299 = Lmember(nil, v_29299, v_29300);
    if (v_29299 == nil) goto v_29289;
    v_29299 = lisp_true;
    goto v_29287;
v_29289:
    v_29299 = nil;
v_29287:
    return onevalue(v_29299);
}



// Code for mk_parents_prim

static LispObject CC_mk_parents_prim(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29323, v_29324;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_29285);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_29285;
// end of prologue
    goto v_29295;
v_29291:
    v_29323 = stack[0];
    v_29324 = Llength(nil, v_29323);
    env = stack[-1];
    goto v_29292;
v_29293:
    v_29323 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_29294;
v_29295:
    goto v_29291;
v_29292:
    goto v_29293;
v_29294:
    if (v_29324 == v_29323) goto v_29290;
    v_29323 = stack[0];
    goto v_29288;
v_29290:
    v_29323 = stack[0];
    fn = elt(env, 1); // s_noparents
    v_29323 = (*qfn1(fn))(fn, v_29323);
    env = stack[-1];
    v_29324 = v_29323;
    if (v_29324 == nil) goto v_29307;
    else goto v_29308;
v_29307:
    v_29323 = stack[0];
    goto v_29306;
v_29308:
    goto v_29318;
v_29314:
    v_29324 = stack[0];
    goto v_29315;
v_29316:
    v_29323 = qcar(v_29323);
    goto v_29317;
v_29318:
    goto v_29314;
v_29315:
    goto v_29316;
v_29317:
    fn = elt(env, 2); // mk_edge_parents
    v_29323 = (*qfn2(fn))(fn, v_29324, v_29323);
    v_29323 = stack[0];
    goto v_29306;
    v_29323 = nil;
v_29306:
    goto v_29288;
    v_29323 = nil;
v_29288:
    return onevalue(v_29323);
}



// Code for fs!:zerop!:

static LispObject CC_fsTzeropT(LispObject env,
                         LispObject v_29285)
{
    env = qenv(env);
    LispObject v_29349, v_29350, v_29351;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_29350 = v_29285;
// end of prologue
    v_29349 = v_29350;
    if (v_29349 == nil) goto v_29289;
    else goto v_29290;
v_29289:
    v_29349 = lisp_true;
    goto v_29288;
v_29290:
    v_29349 = v_29350;
    if (is_number(v_29349)) goto v_29302;
    v_29349 = v_29350;
    v_29349 = qcdr(v_29349);
    v_29349 = (v_29349 == nil ? lisp_true : nil);
    goto v_29300;
v_29302:
    v_29349 = nil;
    goto v_29300;
    v_29349 = nil;
v_29300:
    if (v_29349 == nil) goto v_29298;
    v_29349 = lisp_true;
    goto v_29296;
v_29298:
    goto v_29321;
v_29317:
    v_29349 = v_29350;
    v_29351 = qcdr(v_29349);
    goto v_29318;
v_29319:
    v_29349 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_29320;
v_29321:
    goto v_29317;
v_29318:
    goto v_29319;
v_29320:
    v_29349 = *(LispObject *)((char *)v_29351 + (CELL-TAG_VECTOR) + (((intptr_t)v_29349-TAG_FIXNUM)/(16/CELL)));
    if (v_29349 == nil) goto v_29315;
    else goto v_29316;
v_29315:
    goto v_29330;
v_29326:
    v_29349 = v_29350;
    v_29350 = qcdr(v_29349);
    goto v_29327;
v_29328:
    v_29349 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_29329;
v_29330:
    goto v_29326;
v_29327:
    goto v_29328;
v_29329:
    v_29349 = *(LispObject *)((char *)v_29350 + (CELL-TAG_VECTOR) + (((intptr_t)v_29349-TAG_FIXNUM)/(16/CELL)));
    v_29350 = v_29349;
    v_29349 = v_29350;
    if (is_number(v_29349)) goto v_29339;
    v_29349 = nil;
    goto v_29337;
v_29339:
    v_29349 = v_29350;
        return Lzerop(nil, v_29349);
    v_29349 = nil;
v_29337:
    goto v_29314;
v_29316:
    v_29349 = nil;
    goto v_29314;
    v_29349 = nil;
v_29314:
    goto v_29296;
    v_29349 = nil;
v_29296:
    goto v_29288;
    v_29349 = nil;
v_29288:
    return onevalue(v_29349);
}



// Code for monic

static LispObject CC_monic(LispObject env,
                         LispObject v_29285, LispObject v_29286)
{
    env = qenv(env);
    LispObject v_29318, v_29319, v_29320;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_29286,v_29285);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_29285,v_29286);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_29318 = v_29286;
    stack[0] = v_29285;
// end of prologue
    goto v_29300;
v_29294:
    v_29320 = elt(env, 1); // lcof
    goto v_29295;
v_29296:
    v_29319 = stack[0];
    goto v_29297;
v_29298:
    goto v_29299;
v_29300:
    goto v_29294;
v_29295:
    goto v_29296;
v_29297:
    goto v_29298;
v_29299:
    v_29318 = list3(v_29320, v_29319, v_29318);
    env = stack[-1];
    fn = elt(env, 3); // aeval
    v_29318 = (*qfn1(fn))(fn, v_29318);
    env = stack[-1];
    goto v_29312;
v_29306:
    v_29320 = elt(env, 2); // quotient
    goto v_29307;
v_29308:
    v_29319 = stack[0];
    goto v_29309;
v_29310:
    goto v_29311;
v_29312:
    goto v_29306;
v_29307:
    goto v_29308;
v_29309:
    goto v_29310;
v_29311:
    v_29318 = list3(v_29320, v_29319, v_29318);
    env = stack[-1];
    fn = elt(env, 3); // aeval
    v_29318 = (*qfn1(fn))(fn, v_29318);
    env = stack[-1];
    stack[0] = v_29318;
    v_29318 = stack[0];
    {
        fn = elt(env, 3); // aeval
        return (*qfn1(fn))(fn, v_29318);
    }
    return onevalue(v_29318);
}



setup_type const u49_setup[] =
{
    {"janettreeinsert",         CC_janettreeinsert,TOO_MANY_1, WRONG_NO_1},
    {"mri_simplat1",            TOO_FEW_2,      CC_mri_simplat1,WRONG_NO_2},
    {"ofsf_updsignpow",         TOO_FEW_2,      CC_ofsf_updsignpow,WRONG_NO_2},
    {"cr:prep",                 CC_crTprep,     TOO_MANY_1,    WRONG_NO_1},
    {"spinnerprod",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_spinnerprod},
    {"safe-fp-quot",            TOO_FEW_2,      CC_safeKfpKquot,WRONG_NO_2},
    {"f2dip",                   CC_f2dip,       TOO_MANY_1,    WRONG_NO_1},
    {"delete_edge",             TOO_FEW_2,      CC_delete_edge,WRONG_NO_2},
    {"reduce-ratios",           TOO_FEW_2,      CC_reduceKratios,WRONG_NO_2},
    {"fs:subang",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_fsTsubang},
    {"addnew",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_addnew},
    {"flattens1",               CC_flattens1,   TOO_MANY_1,    WRONG_NO_1},
    {"pst_mkpst",               CC_pst_mkpst,   TOO_MANY_1,    WRONG_NO_1},
    {"taylorp",                 CC_taylorp,     TOO_MANY_1,    WRONG_NO_1},
    {"get-new-prime",           CC_getKnewKprime,TOO_MANY_1,   WRONG_NO_1},
    {"min2-order",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_min2Korder},
    {"bc_dcont",                CC_bc_dcont,    TOO_MANY_1,    WRONG_NO_1},
    {"evalgeq",                 TOO_FEW_2,      CC_evalgeq,    WRONG_NO_2},
    {"exp*",                    CC_expH,        TOO_MANY_1,    WRONG_NO_1},
    {"mk_names_map_2",          CC_mk_names_map_2,TOO_MANY_1,  WRONG_NO_1},
    {"general-modular-difference",TOO_FEW_2,    CC_generalKmodularKdifference,WRONG_NO_2},
    {"ofsf_smmkatl-and1",       WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_ofsf_smmkatlKand1},
    {"sfchk",                   CC_sfchk,       TOO_MANY_1,    WRONG_NO_1},
    {"depend-sq",               TOO_FEW_2,      CC_dependKsq,  WRONG_NO_2},
    {"talp_mkinvop",            TOO_FEW_2,      CC_talp_mkinvop,WRONG_NO_2},
    {"mri_simplfloor1",         CC_mri_simplfloor1,TOO_MANY_1, WRONG_NO_1},
    {"countof",                 TOO_FEW_2,      CC_countof,    WRONG_NO_2},
    {"den",                     CC_den,         TOO_MANY_1,    WRONG_NO_1},
    {":log2",                   CC_Tlog2,       TOO_MANY_1,    WRONG_NO_1},
    {"exptbf",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_exptbf},
    {"find_triangl_coeff",      WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_find_triangl_coeff},
    {"mo_support",              CC_mo_support,  TOO_MANY_1,    WRONG_NO_1},
    {"dv_skel2factor",          TOO_FEW_2,      CC_dv_skel2factor,WRONG_NO_2},
    {"simpsqrt2",               CC_simpsqrt2,   TOO_MANY_1,    WRONG_NO_1},
    {"add-factor",              TOO_FEW_2,      CC_addKfactor, WRONG_NO_2},
    {"df_min",                  TOO_FEW_2,      CC_df_min,     WRONG_NO_2},
    {"merge_lists",             TOO_FEW_2,      CC_merge_lists,WRONG_NO_2},
    {"talp_lssimpl",            CC_talp_lssimpl,TOO_MANY_1,    WRONG_NO_1},
    {"pasf_lnegrel",            CC_pasf_lnegrel,TOO_MANY_1,    WRONG_NO_1},
    {"addexptsdf",              TOO_FEW_2,      CC_addexptsdf, WRONG_NO_2},
    {"lengthn",                 CC_lengthn,     TOO_MANY_1,    WRONG_NO_1},
    {"spmatlength",             CC_spmatlength, TOO_MANY_1,    WRONG_NO_1},
    {"groebcplistsort",         CC_groebcplistsort,TOO_MANY_1, WRONG_NO_1},
    {"maprintla",               TOO_FEW_2,      CC_maprintla,  WRONG_NO_2},
    {":log10",                  CC_Tlog10,      TOO_MANY_1,    WRONG_NO_1},
    {"pnth*",                   TOO_FEW_2,      CC_pnthH,      WRONG_NO_2},
    {"sub01",                   TOO_FEW_2,      CC_sub01,      WRONG_NO_2},
    {"replace-next",            TOO_FEW_2,      CC_replaceKnext,WRONG_NO_2},
    {"mk+inner+product",        TOO_FEW_2,      CC_mkLinnerLproduct,WRONG_NO_2},
    {"dim<=deg",                CC_dimRMdeg,    TOO_MANY_1,    WRONG_NO_1},
    {"endofstmtp",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_endofstmtp},
    {"mk_parents_prim",         CC_mk_parents_prim,TOO_MANY_1, WRONG_NO_1},
    {"fs:zerop:",               CC_fsTzeropT,   TOO_MANY_1,    WRONG_NO_1},
    {"monic",                   TOO_FEW_2,      CC_monic,      WRONG_NO_2},
    {NULL, (one_args *)"u49", (two_args *)"138446 1811382 4439670", 0}
};

// end of generated code
