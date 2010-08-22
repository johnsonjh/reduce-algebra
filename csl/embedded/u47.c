
/* $destdir/generated-c\u47.c Machine generated C code */

/* Signature: 00000000 21-Aug-2010 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
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
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? 153600 : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define PAGE_MASK               ((((uint32_t)1) << (32-PAGE_BITS)) - 1)
#define OFFSET_MASK             ((((uint32_t)1) << PAGE_BITS) - 1)
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32_t)(n) >> 24) & 0xff)
#define bits_of_char(n)  (((int32_t)(n) >> 16) & 0xff)
#ifdef Kanji
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0xffff)
#else
#define code_of_char(n)  ((char)(((int32_t)(n) >>  8) & 0xff))
#endif
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 24) |                  \
    (((uint32_t)(bits)) << 16) | (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0xff, 4)
 
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_ERROR      0x100       
#define UNWIND_UNWIND     0x200       
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object bad_special2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define HEADLINE_FLAG 0x08
#define MESSAGES_FLAG 0x10
#define ALWAYS_NOISY  0x20
#define verbos_flag (miscflags & GC_MSG_BITS)
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
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
    "too many arguments",
    "too many arguments",
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
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) return aerror("stack overflow");
#else
#define if_check_stack
#endif
extern int32_t software_ticks, countdown;
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int fasl_output_file, output_directory;
extern FILE *binary_read_file;
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern CSLbool always_noisy;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 0
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
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
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int time_base,  space_base,  io_base,  errors_base;
extern int time_now,   space_now,   io_now,   errors_now;
extern int time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       3.14159265358979323846
#define _half_pi  1.57079632679489661923
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for mk_simpl_map_ */

static Lisp_Object CC_mk_simpl_map_(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v3, v4;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk_simpl_map_");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v3 = v0;
/* end of prologue */
    v4 = v3;
    v3 = qvalue(elt(env, 1)); /* nil */
    {
        fn = elt(env, 2); /* mk_simpl_map_1 */
        return (*qfn2(fn))(qenv(fn), v4, v3);
    }
}



/* Code for pst_equitable */

static Lisp_Object CC_pst_equitable(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pst_equitable");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v21 = v0;
/* end of prologue */
    v20 = v21;
    v20 = qcdr(v20);
    if (v20 == nil) { popv(4); return onevalue(v21); }
    v20 = v21;
    v20 = qcar(v20);
    stack[-1] = v20;
    v20 = v21;
    v20 = qcdr(v20);
    fn = elt(env, 1); /* pst_reduce */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = v20;
    stack[0] = stack[-2];
    v21 = stack[-1];
    v20 = stack[-2];
    v20 = qcar(v20);
    v20 = Lappend(nil, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v20 = Lrplaca(nil, stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    goto v23;

v23:
    v20 = stack[-2];
    v20 = qcar(v20);
    stack[-1] = v20;
    stack[0] = stack[-1];
    v21 = stack[-1];
    v20 = stack[-2];
    v20 = qcdr(v20);
    fn = elt(env, 2); /* pst_equitable1 */
    v20 = (*qfn2(fn))(qenv(fn), v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v20 = cons(stack[0], v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = v20;
    v20 = stack[-2];
    v20 = qcdr(v20);
    fn = elt(env, 1); /* pst_reduce */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[0] = v20;
    v20 = stack[0];
    v20 = qcar(v20);
    if (v20 == nil) goto v24;
    v21 = stack[-1];
    v20 = stack[0];
    v20 = qcar(v20);
    v21 = Lappend(nil, v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v20 = stack[0];
    v20 = qcdr(v20);
    v20 = cons(v21, v20);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = v20;
    goto v24;

v24:
    v20 = stack[0];
    v20 = qcar(v20);
    stack[0] = v20;
    v20 = stack[0];
    if (v20 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v23;
/* error exit handlers */
v22:
    popv(4);
    return nil;
}



/* Code for ofsf_smmkatl!-and */

static Lisp_Object MS_CDECL CC_ofsf_smmkatlKand(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_smmkatl-and");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smmkatl-and");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v6;
    v50 = v25;
    stack[-4] = v0;
/* end of prologue */
    v51 = qvalue(elt(env, 1)); /* !*rlsipw */
    if (!(v51 == nil)) goto v1;
    v51 = qvalue(elt(env, 2)); /* !*rlsipo */
    if (v51 == nil) goto v1;
    v52 = elt(env, 3); /* and */
    v51 = v50;
    v50 = stack[-3];
    {
        popv(7);
        fn = elt(env, 5); /* ofsf_irl2atl */
        return (*qfnn(fn))(qenv(fn), 3, v52, v51, v50);
    }

v1:
    stack[-5] = v50;
    goto v53;

v53:
    v50 = stack[-5];
    if (v50 == nil) goto v54;
    v50 = stack[-5];
    v50 = qcar(v50);
    v51 = v50;
    v52 = qcar(v51);
    v51 = stack[-4];
    v51 = Latsoc(nil, v52, v51);
    v52 = v51;
    v51 = v52;
    if (v51 == nil) goto v55;
    v51 = v50;
    v50 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v50 = (*qfnn(fn))(qenv(fn), 3, v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    goto v14;

v14:
    stack[-2] = v50;
    v50 = stack[-2];
    fn = elt(env, 7); /* lastpair */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-1] = v50;
    v50 = stack[-5];
    v50 = qcdr(v50);
    stack[-5] = v50;
    v50 = stack[-1];
    if (!consp(v50)) goto v53;
    else goto v18;

v18:
    v50 = stack[-5];
    if (v50 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    stack[0] = stack[-1];
    v50 = stack[-5];
    v50 = qcar(v50);
    v51 = v50;
    v52 = qcar(v51);
    v51 = stack[-4];
    v51 = Latsoc(nil, v52, v51);
    v52 = v51;
    v51 = v52;
    if (v51 == nil) goto v57;
    v51 = v50;
    v50 = stack[-3];
    fn = elt(env, 6); /* ofsf_smmkatl!-and1 */
    v50 = (*qfnn(fn))(qenv(fn), 3, v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    goto v58;

v58:
    v50 = Lrplacd(nil, stack[0], v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    v50 = stack[-1];
    fn = elt(env, 7); /* lastpair */
    v50 = (*qfn1(fn))(qenv(fn), v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    stack[-1] = v50;
    v50 = stack[-5];
    v50 = qcdr(v50);
    stack[-5] = v50;
    goto v18;

v57:
    v52 = elt(env, 3); /* and */
    v51 = v50;
    v50 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v50 = (*qfnn(fn))(qenv(fn), 3, v52, v51, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    goto v58;

v55:
    v51 = elt(env, 3); /* and */
    v52 = v50;
    v50 = stack[-3];
    fn = elt(env, 8); /* ofsf_ir2atl */
    v50 = (*qfnn(fn))(qenv(fn), 3, v51, v52, v50);
    nil = C_nil;
    if (exception_pending()) goto v56;
    env = stack[-6];
    goto v14;

v54:
    v50 = qvalue(elt(env, 4)); /* nil */
    { popv(7); return onevalue(v50); }
/* error exit handlers */
v56:
    popv(7);
    return nil;
}



/* Code for collectpolyvarsaux */

static Lisp_Object CC_collectpolyvarsaux(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v55, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for collectpolyvarsaux");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v65 = v25;
    stack[-1] = v0;
/* end of prologue */
    v55 = stack[-1];
    if (!consp(v55)) { popv(4); return onevalue(v65); }
    v55 = stack[-1];
    v55 = qcar(v55);
    if (!consp(v55)) { popv(4); return onevalue(v65); }
    stack[0] = v65;
    v55 = stack[-1];
    v55 = qcar(v55);
    v55 = qcar(v55);
    v55 = qcar(v55);
    v55 = ncons(v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    fn = elt(env, 2); /* union */
    stack[-2] = (*qfn2(fn))(qenv(fn), stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v55 = stack[-1];
    v55 = qcar(v55);
    v65 = qcdr(v55);
    v55 = qvalue(elt(env, 1)); /* nil */
    stack[0] = CC_collectpolyvarsaux(env, v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    v55 = stack[-1];
    v65 = qcdr(v55);
    v55 = qvalue(elt(env, 1)); /* nil */
    v55 = CC_collectpolyvarsaux(env, v65, v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    fn = elt(env, 2); /* union */
    v55 = (*qfn2(fn))(qenv(fn), stack[0], v55);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-3];
    {
        Lisp_Object v67 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* union */
        return (*qfn2(fn))(qenv(fn), v67, v55);
    }
/* error exit handlers */
v66:
    popv(4);
    return nil;
}



/* Code for dip_f2dip1 */

static Lisp_Object MS_CDECL CC_dip_f2dip1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v10, v40, v8, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dip_f2dip1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_f2dip1");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v25;
    stack[-2] = v0;
/* end of prologue */
    v41 = stack[-2];
    if (v41 == nil) goto v74;
    v41 = stack[-2];
    if (!consp(v41)) goto v17;
    v41 = stack[-2];
    v41 = qcar(v41);
    if (!consp(v41)) goto v17;
    v41 = stack[-2];
    v41 = qcar(v41);
    v41 = qcar(v41);
    v73 = qcar(v41);
    v41 = stack[-2];
    v41 = qcar(v41);
    v41 = qcar(v41);
    v8 = qcdr(v41);
    v41 = stack[-2];
    v41 = qcar(v41);
    v40 = qcdr(v41);
    v10 = stack[-1];
    v41 = stack[0];
    fn = elt(env, 2); /* dip_f2dip2 */
    stack[-3] = (*qfnn(fn))(qenv(fn), 5, v73, v8, v40, v10, v41);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v41 = stack[-2];
    v40 = qcdr(v41);
    v10 = stack[-1];
    v41 = stack[0];
    v41 = CC_dip_f2dip1(env, 3, v40, v10, v41);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    {
        Lisp_Object v76 = stack[-3];
        popv(5);
        fn = elt(env, 3); /* dip_sum */
        return (*qfn2(fn))(qenv(fn), v76, v41);
    }

v17:
    v41 = stack[-2];
    fn = elt(env, 4); /* bc_fd */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    fn = elt(env, 5); /* bc_prod */
    v10 = (*qfn2(fn))(qenv(fn), stack[0], v41);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-4];
    v41 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* dip_fmon */
        return (*qfn2(fn))(qenv(fn), v10, v41);
    }

v74:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v41); }
/* error exit handlers */
v75:
    popv(5);
    return nil;
}



/* Code for tryreduction */

static Lisp_Object MS_CDECL CC_tryreduction(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v85, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tryreduction");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tryreduction");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v25;
    stack[-2] = v0;
/* end of prologue */
    v85 = stack[-2];
    v85 = qcar(v85);
    stack[-3] = v85;
    v85 = stack[-3];
    if (!consp(v85)) goto v86;
    v85 = stack[-3];
    stack[-2] = v85;
    v85 = stack[-2];
    v85 = qcar(v85);
    stack[-3] = v85;
    goto v86;

v86:
    v32 = stack[-3];
    v85 = (Lisp_Object)1; /* 0 */
    if (v32 == v85) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v32 = stack[-3];
    v85 = (Lisp_Object)17; /* 1 */
    if (v32 == v85) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v32 = stack[-3];
    v85 = (Lisp_Object)33; /* 2 */
    v85 = Ldivide(nil, v32, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    stack[-3] = v85;
    v32 = stack[-2];
    v85 = stack[-3];
    v85 = qcdr(v85);
    v85 = Lrplaca(nil, v32, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v85 = stack[-3];
    v85 = qcar(v85);
    stack[-3] = v85;
    v85 = stack[-1];
    v85 = qcdr(v85);
    v85 = qcar(v85);
    fn = elt(env, 1); /* simp */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    stack[-1] = v85;
    v32 = stack[-1];
    v85 = stack[-3];
    fn = elt(env, 2); /* !*exptsq */
    v85 = (*qfn2(fn))(qenv(fn), v32, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    stack[-1] = v85;
    v32 = (Lisp_Object)17; /* 1 */
    v85 = stack[-1];
    v85 = qcdr(v85);
    stack[-2] = cons(v32, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    v85 = stack[-1];
    v85 = qcar(v85);
    fn = elt(env, 3); /* f2df */
    v85 = (*qfn1(fn))(qenv(fn), v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    fn = elt(env, 4); /* multdfconst */
    v85 = (*qfn2(fn))(qenv(fn), stack[-2], v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-4];
    stack[-3] = v85;
    v85 = stack[0];
    if (v85 == nil) goto v88;
    v32 = stack[0];
    v85 = stack[-3];
    fn = elt(env, 5); /* multdf */
    v85 = (*qfn2(fn))(qenv(fn), v32, v85);
    nil = C_nil;
    if (exception_pending()) goto v87;
    stack[0] = v85;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v88:
    v85 = stack[-3];
    stack[0] = v85;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
/* error exit handlers */
v87:
    popv(5);
    return nil;
}



/* Code for ldt!-dep */

static Lisp_Object CC_ldtKdep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ldt-dep");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v86 = v0;
/* end of prologue */
    fn = elt(env, 3); /* ldt!-tvar */
    v48 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[0];
    v86 = qvalue(elt(env, 1)); /* depl!* */
    v86 = Lassoc(nil, v48, v86);
    v48 = v86;
    v86 = v48;
    if (v86 == nil) goto v90;
    v86 = v48;
    v86 = qcdr(v86);
    { popv(1); return onevalue(v86); }

v90:
    v86 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v86); }
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for improvelayout */

static Lisp_Object MS_CDECL CC_improvelayout(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v37, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "improvelayout");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for improvelayout");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* end of prologue */
    stack[-2] = nil;
    v36 = (Lisp_Object)1; /* 0 */
    stack[-1] = v36;
    goto v98;

v98:
    v37 = qvalue(elt(env, 1)); /* rowmax */
    v36 = stack[-1];
    v36 = difference2(v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v36 = Lminusp(nil, v36);
    env = stack[-3];
    if (v36 == nil) goto v84;
    v36 = stack[-2];
    if (v36 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    fn = elt(env, 10); /* improvekvarlst */
    v36 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v99;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v84:
    stack[0] = qvalue(elt(env, 3)); /* codmat */
    v37 = qvalue(elt(env, 4)); /* maxvar */
    v36 = stack[-1];
    v36 = plus2(v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    v37 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v36/(16/CELL)));
    v36 = (Lisp_Object)49; /* 3 */
    v36 = *(Lisp_Object *)((char *)v37 + (CELL-TAG_VECTOR) + ((int32_t)v36/(16/CELL)));
    v97 = v36;
    if (is_number(v36)) goto v16;
    v36 = v97;
    v36 = Lconsp(nil, v36);
    env = stack[-3];
    if (!(v36 == nil)) goto v16;
    v37 = stack[-1];
    v36 = qvalue(elt(env, 5)); /* codbexl!* */
    v36 = Lmember(nil, v37, v36);
    if (v36 == nil) goto v22;
    v37 = v97;
    v36 = elt(env, 6); /* nex */
    v36 = get(v37, v36);
    env = stack[-3];
    if (!(v36 == nil)) goto v16;
    v37 = v97;
    v36 = elt(env, 7); /* newsym */
    v36 = Lflagp(nil, v37, v36);
    env = stack[-3];
    if (v36 == nil) goto v16;
    v37 = v97;
    v36 = elt(env, 8); /* alias */
    v36 = get(v37, v36);
    env = stack[-3];
    if (!(v36 == nil)) goto v16;

v22:
    v37 = v97;
    v36 = stack[-1];
    fn = elt(env, 11); /* testononeel */
    v36 = (*qfn2(fn))(qenv(fn), v37, v36);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    if (v36 == nil) goto v16;
    v36 = qvalue(elt(env, 9)); /* t */
    stack[-2] = v36;
    goto v16;

v16:
    v36 = stack[-1];
    v36 = add1(v36);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-3];
    stack[-1] = v36;
    goto v98;
/* error exit handlers */
v99:
    popv(4);
    return nil;
}



/* Code for updkorder */

static Lisp_Object CC_updkorder(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v61, v96;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for updkorder");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    v103 = qvalue(elt(env, 1)); /* kord!* */
    stack[-1] = v103;
    stack[0] = v61;
    v103 = stack[-1];
    v103 = Ldelete(nil, v61, v103);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    v103 = cons(stack[0], v103);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    v96 = v103;
    v61 = stack[-1];
    v103 = v96;
    if (equal(v61, v103)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v103 = v96;
    qvalue(elt(env, 1)) = v103; /* kord!* */
    v103 = qvalue(elt(env, 2)); /* nil */
    v103 = ncons(v103);
    nil = C_nil;
    if (exception_pending()) goto v104;
    env = stack[-2];
    qvalue(elt(env, 3)) = v103; /* alglist!* */
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v104:
    popv(3);
    return nil;
}



/* Code for dip2a1 */

static Lisp_Object CC_dip2a1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v105, v106;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip2a1");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    goto v91;

v91:
    v105 = stack[-3];
    if (v105 == nil) goto v1;
    v105 = stack[-3];
    v105 = qcdr(v105);
    stack[0] = qcar(v105);
    v105 = stack[-3];
    v105 = qcar(v105);
    fn = elt(env, 2); /* expvec2a */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    stack[-2] = stack[0];
    stack[-1] = v105;
    v105 = stack[-2];
    fn = elt(env, 3); /* bcminus!? */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    if (v105 == nil) goto v63;
    stack[0] = elt(env, 1); /* minus */
    v105 = stack[-2];
    fn = elt(env, 4); /* bcneg */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    fn = elt(env, 5); /* bc2a */
    v106 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v105 = stack[-1];
    v105 = cons(v106, v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    fn = elt(env, 6); /* dipretimes */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v105 = list2(stack[0], v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v106 = v105;
    goto v107;

v107:
    v105 = stack[-4];
    v105 = cons(v106, v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    stack[-4] = v105;
    v105 = stack[-3];
    v105 = qcdr(v105);
    v105 = qcdr(v105);
    stack[-3] = v105;
    goto v91;

v63:
    v105 = stack[-2];
    fn = elt(env, 5); /* bc2a */
    v106 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v105 = stack[-1];
    v105 = cons(v106, v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    fn = elt(env, 6); /* dipretimes */
    v105 = (*qfn1(fn))(qenv(fn), v105);
    nil = C_nil;
    if (exception_pending()) goto v69;
    env = stack[-5];
    v106 = v105;
    goto v107;

v1:
    v105 = stack[-4];
    {
        popv(6);
        fn = elt(env, 7); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v105);
    }
/* error exit handlers */
v69:
    popv(6);
    return nil;
}



/* Code for prepsqyy */

static Lisp_Object CC_prepsqyy(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v59, v86, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for prepsqyy");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v48 = v0;
/* end of prologue */
    v86 = v48;
    v59 = elt(env, 1); /* !*sq */
    if (!consp(v86)) return onevalue(v48);
    v86 = qcar(v86);
    if (!(v86 == v59)) return onevalue(v48);
    v59 = v48;
    v59 = qcdr(v59);
    v59 = qcar(v59);
    {
        fn = elt(env, 2); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v59);
    }
}



/* Code for generic!-sub */

static Lisp_Object CC_genericKsub(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v48;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for generic-sub");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v86 = v25;
    v48 = v0;
/* end of prologue */
    stack[-2] = v48;
    stack[-1] = elt(env, 1); /* dfp */
    stack[0] = v86;
    v86 = elt(env, 2); /* list */
    v86 = ncons(v86);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    v86 = list3(stack[-1], stack[0], v86);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-3];
    {
        Lisp_Object v28 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* dfp!-sub */
        return (*qfn2(fn))(qenv(fn), v28, v86);
    }
/* error exit handlers */
v38:
    popv(4);
    return nil;
}



/* Code for tensor_has_dummy_idx */

static Lisp_Object CC_tensor_has_dummy_idx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensor_has_dummy_idx");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v25;
    stack[-1] = v0;
/* end of prologue */

v91:
    v28 = stack[-1];
    if (v28 == nil) goto v1;
    v28 = stack[-1];
    v71 = qcar(v28);
    v28 = stack[0];
    fn = elt(env, 3); /* smember */
    v28 = (*qfn2(fn))(qenv(fn), v71, v28);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (v28 == nil) goto v49;
    v28 = qvalue(elt(env, 2)); /* t */
    { popv(3); return onevalue(v28); }

v49:
    v28 = stack[-1];
    v28 = qcdr(v28);
    stack[-1] = v28;
    goto v91;

v1:
    v28 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v28); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for xprint */

static Lisp_Object CC_xprint(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v111, v112, v113;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v25;
    stack[-2] = v0;
/* end of prologue */
    v111 = stack[-2];
    v111 = qcdr(v111);
    stack[-3] = v111;
    v111 = stack[-2];
    v111 = qcar(v111);
    stack[-2] = v111;
    v111 = stack[-3];
    fn = elt(env, 5); /* kernlp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[0] = v111;
    if (v111 == nil) goto v108;
    v112 = stack[0];
    v111 = (Lisp_Object)17; /* 1 */
    if (v112 == v111) goto v108;
    v112 = stack[-3];
    v111 = stack[0];
    fn = elt(env, 6); /* quotf */
    v111 = (*qfn2(fn))(qenv(fn), v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[-3] = v111;
    v111 = stack[0];
    fn = elt(env, 7); /* minusf */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    if (v111 == nil) goto v108;
    v111 = elt(env, 1); /* minus */
    fn = elt(env, 8); /* oprin */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v111 = stack[0];
    fn = elt(env, 9); /* !:minus */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    stack[0] = v111;
    v111 = qvalue(elt(env, 2)); /* nil */
    stack[-1] = v111;
    goto v108;

v108:
    v111 = stack[-1];
    if (v111 == nil) goto v12;
    v111 = elt(env, 3); /* plus */
    fn = elt(env, 8); /* oprin */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    goto v12;

v12:
    v111 = stack[0];
    if (v111 == nil) goto v14;
    v112 = stack[0];
    v111 = (Lisp_Object)17; /* 1 */
    if (v112 == v111) goto v14;
    v111 = stack[0];
    fn = elt(env, 10); /* prin2!* */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v111 = elt(env, 4); /* times */
    fn = elt(env, 8); /* oprin */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    goto v14;

v14:
    v111 = stack[-2];
    fn = elt(env, 11); /* xprinp */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v112 = stack[-3];
    v111 = (Lisp_Object)17; /* 1 */
    if (v112 == v111) goto v93;
    v111 = elt(env, 4); /* times */
    fn = elt(env, 8); /* oprin */
    v111 = (*qfn1(fn))(qenv(fn), v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    env = stack[-4];
    v113 = stack[-3];
    v111 = stack[-3];
    v112 = qcdr(v111);
    v111 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 12); /* xprinf */
    v111 = (*qfnn(fn))(qenv(fn), 3, v113, v112, v111);
    nil = C_nil;
    if (exception_pending()) goto v85;
    goto v93;

v93:
    v111 = nil;
    { popv(5); return onevalue(v111); }
/* error exit handlers */
v85:
    popv(5);
    return nil;
}



/* Code for movebds */

static Lisp_Object MS_CDECL CC_movebds(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v68;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "movebds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for movebds");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v6;
    stack[-1] = v25;
    stack[-2] = v0;
/* end of prologue */
    v68 = qvalue(elt(env, 1)); /* !*intp */
    v96 = stack[-1];
    fn = elt(env, 2); /* sgn1 */
    v68 = (*qfn2(fn))(qenv(fn), v68, v96);
    nil = C_nil;
    if (exception_pending()) goto v83;
    v96 = stack[0];
    if (equal(v68, v96)) goto v48;
    v68 = stack[-2];
    v96 = stack[-1];
        popv(3);
        return Lrplaca(nil, v68, v96);

v48:
    v68 = stack[-2];
    v96 = stack[-1];
        popv(3);
        return Lrplacd(nil, v68, v96);
/* error exit handlers */
v83:
    popv(3);
    return nil;
}



/* Code for cl_pop */

static Lisp_Object CC_cl_pop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v5;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_pop");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    return onevalue(v5);
}



/* Code for !*addsq */

static Lisp_Object CC_Haddsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v133;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *addsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v25;
    stack[-3] = v0;
/* end of prologue */
    v132 = stack[-3];
    v132 = qcar(v132);
    if (v132 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v132 = stack[-2];
    v132 = qcar(v132);
    if (v132 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v132 = stack[-3];
    v133 = qcdr(v132);
    v132 = (Lisp_Object)17; /* 1 */
    if (!(v133 == v132)) goto v95;
    v132 = stack[-2];
    v133 = qcdr(v132);
    v132 = (Lisp_Object)17; /* 1 */
    if (!(v133 == v132)) goto v95;
    v132 = stack[-3];
    v133 = qcar(v132);
    v132 = stack[-2];
    v132 = qcar(v132);
    fn = elt(env, 2); /* addf */
    v133 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    v132 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v133, v132);

v95:
    v132 = stack[-3];
    v133 = qcdr(v132);
    stack[-4] = v133;
    v132 = stack[-2];
    v132 = qcdr(v132);
    stack[-1] = v132;
    fn = elt(env, 3); /* gcdf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[0] = v132;
    v133 = stack[-4];
    v132 = stack[0];
    fn = elt(env, 4); /* quotf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-4] = v132;
    v133 = stack[-1];
    v132 = stack[0];
    fn = elt(env, 4); /* quotf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-1] = v132;
    v133 = stack[-1];
    v132 = stack[-3];
    v132 = qcar(v132);
    fn = elt(env, 5); /* !*multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = stack[-4];
    v132 = stack[-2];
    v132 = qcar(v132);
    fn = elt(env, 5); /* !*multf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    fn = elt(env, 2); /* addf */
    v132 = (*qfn2(fn))(qenv(fn), stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-2] = v132;
    v132 = stack[-2];
    if (v132 == nil) goto v135;
    v132 = stack[-3];
    v133 = qcdr(v132);
    v132 = stack[-1];
    fn = elt(env, 5); /* !*multf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-1] = v132;
    v132 = stack[-1];
    fn = elt(env, 6); /* minusf */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    if (v132 == nil) goto v136;
    v132 = stack[-2];
    fn = elt(env, 7); /* negf */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-2] = v132;
    v132 = stack[-1];
    fn = elt(env, 7); /* negf */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[-1] = v132;
    goto v136;

v136:
    v133 = stack[-2];
    v132 = stack[-1];
    fn = elt(env, 3); /* gcdf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    stack[0] = v132;
    v133 = stack[0];
    v132 = (Lisp_Object)17; /* 1 */
    if (v133 == v132) goto v137;
    v133 = stack[-2];
    v132 = stack[0];
    fn = elt(env, 4); /* quotf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    env = stack[-5];
    v133 = stack[-1];
    v132 = stack[0];
    fn = elt(env, 4); /* quotf */
    v132 = (*qfn2(fn))(qenv(fn), v133, v132);
    nil = C_nil;
    if (exception_pending()) goto v134;
    {
        Lisp_Object v138 = stack[-2];
        popv(6);
        return cons(v138, v132);
    }

v137:
    v133 = stack[-2];
    v132 = stack[-1];
    popv(6);
    return cons(v133, v132);

v135:
    v133 = qvalue(elt(env, 1)); /* nil */
    v132 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v133, v132);
/* error exit handlers */
v134:
    popv(6);
    return nil;
}



/* Code for matpri1 */

static Lisp_Object CC_matpri1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v337, v338, v339;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matpri1");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-14] = v25;
    stack[-9] = v0;
/* end of prologue */
    stack[-8] = nil;
    stack[-4] = nil;
    stack[0] = nil;
    v337 = qvalue(elt(env, 1)); /* !*fort */
    if (v337 == nil) goto v86;
    v337 = (Lisp_Object)17; /* 1 */
    stack[0] = v337;
    v337 = stack[-14];
    if (!(v337 == nil)) goto v28;
    v337 = elt(env, 2); /* "MAT" */
    stack[-14] = v337;
    goto v28;

v28:
    v337 = stack[-9];
    stack[-3] = v337;
    goto v54;

v54:
    v337 = stack[-3];
    if (v337 == nil) goto v84;
    v337 = stack[-3];
    v337 = qcar(v337);
    v338 = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-10] = v337;
    v337 = v338;
    stack[-2] = v337;
    goto v131;

v131:
    v337 = stack[-2];
    if (v337 == nil) goto v47;
    v337 = stack[-2];
    v337 = qcar(v337);
    stack[-1] = v337;
    v339 = stack[-14];
    v338 = stack[0];
    v337 = stack[-10];
    v337 = list3(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = ncons(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = elt(env, 4); /* only */
    fn = elt(env, 21); /* assgnpri */
    v337 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-10];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-10] = v337;
    v337 = stack[-2];
    v337 = qcdr(v337);
    stack[-2] = v337;
    goto v131;

v47:
    v337 = stack[0];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[0] = v337;
    v337 = stack[-3];
    v337 = qcdr(v337);
    stack[-3] = v337;
    goto v54;

v84:
    v337 = qvalue(elt(env, 3)); /* nil */
    { popv(19); return onevalue(v337); }

v86:
    v337 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 22); /* terpri!* */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-14];
    if (v337 == nil) goto v34;
    v337 = qvalue(elt(env, 6)); /* !*nat */
    if (v337 == nil) goto v34;
    v339 = stack[-14];
    v338 = (Lisp_Object)1; /* 0 */
    v337 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 23); /* layout!-formula */
    v337 = (*qfnn(fn))(qenv(fn), 3, v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = v337;
    v337 = v338;
    if (v337 == nil) goto v341;
    v337 = v338;
    v337 = qcar(v337);
    v338 = qcdr(v337);
    v337 = (Lisp_Object)65; /* 4 */
    v337 = plus2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[0] = v337;
    v337 = qvalue(elt(env, 6)); /* !*nat */
    stack[-4] = v337;
    goto v341;

v341:
    v337 = qvalue(elt(env, 3)); /* nil */
    v338 = Llinelength(nil, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = qvalue(elt(env, 7)); /* spare!* */
    v338 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = qvalue(elt(env, 8)); /* orig!* */
    v338 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[0];
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-5] = v337;
    v337 = stack[-9];
    v337 = qcar(v337);
    v337 = Llength(nil, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[0] = v337;
    v337 = stack[0];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = Lmkvect(nil, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-15] = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-1] = v337;
    goto v342;

v342:
    v338 = stack[0];
    v337 = stack[-1];
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = Lminusp(nil, v337);
    env = stack[-18];
    if (v337 == nil) goto v343;
    v337 = qvalue(elt(env, 8)); /* orig!* */
    stack[-11] = v337;
    v337 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 8)) = v337; /* orig!* */
    v337 = stack[-4];
    if (v337 == nil) goto v344;
    v337 = stack[-9];
    stack[-3] = v337;
    goto v345;

v345:
    v337 = stack[-3];
    if (v337 == nil) goto v344;
    v337 = stack[-3];
    v337 = qcar(v337);
    v338 = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-10] = v337;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-7] = v337;
    v337 = (Lisp_Object)1; /* 0 */
    stack[0] = v337;
    v337 = stack[-4];
    if (v337 == nil) goto v346;
    v337 = v338;
    stack[-2] = v337;
    goto v347;

v347:
    v337 = stack[-2];
    if (v337 == nil) goto v346;
    v337 = stack[-2];
    v337 = qcar(v337);
    v338 = v337;
    v337 = stack[-4];
    if (v337 == nil) goto v348;
    v339 = v338;
    v338 = (Lisp_Object)1; /* 0 */
    v337 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 23); /* layout!-formula */
    v337 = (*qfnn(fn))(qenv(fn), 3, v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-6] = v337;
    v337 = stack[-6];
    if (v337 == nil) goto v349;
    v338 = stack[-15];
    v337 = stack[-10];
    v338 = *(Lisp_Object *)((char *)v338 + (CELL-TAG_VECTOR) + ((int32_t)v337/(16/CELL)));
    v337 = stack[-6];
    v337 = qcar(v337);
    v337 = qcdr(v337);
    fn = elt(env, 24); /* max */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-1] = v337;
    v338 = stack[-1];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = plus2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = plus2(stack[0], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[0] = v338;
    v337 = stack[-5];
    v337 = (Lisp_Object)greaterp2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    v337 = v337 ? lisp_true : nil;
    env = stack[-18];
    if (v337 == nil) goto v350;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v337;
    goto v351;

v351:
    v337 = stack[-10];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-10] = v337;
    goto v348;

v348:
    v337 = stack[-2];
    v337 = qcdr(v337);
    stack[-2] = v337;
    goto v347;

v350:
    v338 = stack[-6];
    v337 = stack[-7];
    v337 = cons(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-7] = v337;
    v339 = stack[-15];
    v338 = stack[-10];
    v337 = stack[-1];
    *(Lisp_Object *)((char *)v339 + (CELL-TAG_VECTOR) + ((int32_t)v338/(16/CELL))) = v337;
    goto v351;

v349:
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-4] = v337;
    goto v351;

v346:
    v337 = stack[-7];
    v338 = Lreverse(nil, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-8];
    v337 = cons(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-8] = v337;
    v337 = stack[-3];
    v337 = qcdr(v337);
    stack[-3] = v337;
    goto v345;

v344:
    v337 = stack[-4];
    if (v337 == nil) goto v352;
    v337 = qvalue(elt(env, 5)); /* t */
    stack[-12] = v337;
    stack[-13] = v337;
    v337 = stack[-8];
    v337 = Lreverse(nil, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-10] = v337;
    v337 = stack[-10];
    if (v337 == nil) goto v353;
    v337 = (Lisp_Object)1; /* 0 */
    stack[-5] = v337;
    stack[-6] = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-4] = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-2] = v337;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v337;
    v337 = stack[-10];
    v337 = qcar(v337);
    stack[-7] = v337;
    goto v354;

v354:
    v337 = stack[-7];
    if (v337 == nil) goto v355;
    v337 = stack[-7];
    v337 = qcar(v337);
    stack[-1] = v337;
    v338 = stack[-15];
    v337 = stack[-2];
    v337 = *(Lisp_Object *)((char *)v338 + (CELL-TAG_VECTOR) + ((int32_t)v337/(16/CELL)));
    stack[-8] = v337;
    stack[0] = stack[-4];
    v338 = stack[-8];
    v337 = stack[-1];
    v337 = qcar(v337);
    v337 = qcdr(v337);
    v338 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = quot2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v339 = plus2(stack[0], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = (Lisp_Object)1; /* 0 */
    v337 = stack[-1];
    v337 = qcar(v337);
    v337 = qcar(v337);
    fn = elt(env, 25); /* update!-pline */
    v338 = (*qfnn(fn))(qenv(fn), 3, v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-3];
    v337 = Lappend(nil, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-3] = v337;
    stack[0] = stack[-4];
    v338 = stack[-8];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = plus2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = plus2(stack[0], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-4] = v337;
    v337 = stack[-2];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-2] = v337;
    v338 = stack[-6];
    v337 = stack[-1];
    v337 = qcdr(v337);
    v337 = qcar(v337);
    fn = elt(env, 26); /* min */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-6] = v337;
    v338 = stack[-5];
    v337 = stack[-1];
    v337 = qcdr(v337);
    v337 = qcdr(v337);
    fn = elt(env, 24); /* max */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-5] = v337;
    v337 = stack[-7];
    v337 = qcdr(v337);
    stack[-7] = v337;
    goto v354;

v355:
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v337;
    v337 = stack[-13];
    if (v337 == nil) goto v356;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-13] = v337;
    goto v357;

v357:
    v337 = stack[-5];
    stack[-1] = v337;
    goto v358;

v358:
    v338 = stack[-1];
    v337 = stack[-6];
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = Lminusp(nil, v337);
    env = stack[-18];
    if (v337 == nil) goto v359;
    v338 = stack[-3];
    v337 = stack[-2];
    stack[0] = Lappend(nil, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-1] = stack[-4];
    v338 = stack[-6];
    v337 = stack[-5];
    v337 = cons(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = acons(stack[0], stack[-1], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = ncons(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-8] = v337;
    stack[-9] = v337;
    goto v360;

v360:
    v337 = stack[-10];
    v337 = qcdr(v337);
    stack[-10] = v337;
    v337 = stack[-10];
    if (v337 == nil) goto v361;
    stack[-7] = stack[-8];
    v337 = (Lisp_Object)1; /* 0 */
    stack[-5] = v337;
    stack[-6] = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-4] = v337;
    v337 = (Lisp_Object)17; /* 1 */
    stack[-2] = v337;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v337;
    v337 = stack[-10];
    v337 = qcar(v337);
    stack[-16] = v337;
    goto v362;

v362:
    v337 = stack[-16];
    if (v337 == nil) goto v363;
    v337 = stack[-16];
    v337 = qcar(v337);
    stack[-1] = v337;
    v338 = stack[-15];
    v337 = stack[-2];
    v337 = *(Lisp_Object *)((char *)v338 + (CELL-TAG_VECTOR) + ((int32_t)v337/(16/CELL)));
    stack[-17] = v337;
    stack[0] = stack[-4];
    v338 = stack[-17];
    v337 = stack[-1];
    v337 = qcar(v337);
    v337 = qcdr(v337);
    v338 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = quot2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v339 = plus2(stack[0], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = (Lisp_Object)1; /* 0 */
    v337 = stack[-1];
    v337 = qcar(v337);
    v337 = qcar(v337);
    fn = elt(env, 25); /* update!-pline */
    v338 = (*qfnn(fn))(qenv(fn), 3, v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-3];
    v337 = Lappend(nil, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-3] = v337;
    stack[0] = stack[-4];
    v338 = stack[-17];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = plus2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = plus2(stack[0], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-4] = v337;
    v337 = stack[-2];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-2] = v337;
    v338 = stack[-6];
    v337 = stack[-1];
    v337 = qcdr(v337);
    v337 = qcar(v337);
    fn = elt(env, 26); /* min */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-6] = v337;
    v338 = stack[-5];
    v337 = stack[-1];
    v337 = qcdr(v337);
    v337 = qcdr(v337);
    fn = elt(env, 24); /* max */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-5] = v337;
    v337 = stack[-16];
    v337 = qcdr(v337);
    stack[-16] = v337;
    goto v362;

v363:
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-2] = v337;
    v337 = stack[-13];
    if (v337 == nil) goto v364;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-13] = v337;
    goto v365;

v365:
    v337 = stack[-5];
    stack[-1] = v337;
    goto v366;

v366:
    v338 = stack[-1];
    v337 = stack[-6];
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = Lminusp(nil, v337);
    env = stack[-18];
    if (v337 == nil) goto v367;
    v338 = stack[-3];
    v337 = stack[-2];
    stack[0] = Lappend(nil, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-1] = stack[-4];
    v338 = stack[-6];
    v337 = stack[-5];
    v337 = cons(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = acons(stack[0], stack[-1], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = ncons(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = Lrplacd(nil, stack[-7], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-8];
    v337 = qcdr(v337);
    stack[-8] = v337;
    goto v360;

v367:
    v337 = stack[-12];
    if (v337 == nil) goto v368;
    v337 = elt(env, 9); /* mat!-top!-l */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-17] = v337;
    v337 = elt(env, 10); /* mat!-top!-r */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-16] = v337;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-12] = v337;
    goto v369;

v369:
    v338 = stack[-4];
    v337 = (Lisp_Object)33; /* 2 */
    stack[0] = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-4];
    v338 = sub1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-1];
    v339 = acons(stack[0], v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = stack[-16];
    v337 = stack[-3];
    v337 = acons(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-3] = v337;
    v339 = (Lisp_Object)1; /* 0 */
    v338 = (Lisp_Object)17; /* 1 */
    v337 = stack[-1];
    v339 = acons(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = stack[-17];
    v337 = stack[-2];
    v337 = acons(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-2] = v337;
    v337 = stack[-1];
    v337 = sub1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-1] = v337;
    goto v366;

v368:
    v338 = stack[-1];
    v337 = stack[-6];
    if (!(equal(v338, v337))) goto v370;
    v337 = stack[-10];
    v337 = qcdr(v337);
    if (!(v337 == nil)) goto v370;
    v337 = elt(env, 11); /* mat!-low!-l */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-17] = v337;
    v337 = elt(env, 12); /* mat!-low!-r */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-16] = v337;
    goto v369;

v370:
    v337 = elt(env, 13); /* mat!-mid!-l */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-17] = v337;
    v337 = elt(env, 14); /* mat!-mid!-r */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-16] = v337;
    goto v369;

v364:
    v337 = stack[-5];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-5] = v337;
    goto v365;

v361:
    v337 = stack[-9];
    goto v371;

v371:
    stack[-8] = v337;
    v337 = stack[-11];
    qvalue(elt(env, 8)) = v337; /* orig!* */
    v337 = (Lisp_Object)1; /* 0 */
    stack[0] = v337;
    v337 = stack[-8];
    stack[-1] = v337;
    goto v372;

v372:
    v337 = stack[-1];
    if (v337 == nil) goto v373;
    v337 = stack[-1];
    v337 = qcar(v337);
    v338 = v337;
    v338 = qcdr(v338);
    v338 = qcdr(v338);
    v337 = qcdr(v337);
    v337 = qcar(v337);
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = plus2(stack[0], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[0] = v337;
    v337 = stack[-1];
    v337 = qcdr(v337);
    stack[-1] = v337;
    goto v372;

v373:
    v338 = stack[0];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = quot2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-10] = v337;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-9] = v337;
    v337 = stack[-8];
    stack[-3] = v337;
    goto v374;

v374:
    v337 = stack[-3];
    if (v337 == nil) goto v375;
    v337 = stack[-3];
    v337 = qcar(v337);
    stack[-2] = v337;
    stack[-1] = (Lisp_Object)1; /* 0 */
    v338 = stack[-10];
    v337 = stack[-2];
    v337 = qcdr(v337);
    v337 = qcdr(v337);
    v338 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-2];
    v337 = qcar(v337);
    v337 = qcar(v337);
    fn = elt(env, 25); /* update!-pline */
    v338 = (*qfnn(fn))(qenv(fn), 3, stack[-1], v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-9];
    v337 = Lappend(nil, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-9] = v337;
    stack[-1] = stack[-10];
    v337 = stack[-2];
    v337 = qcdr(v337);
    v338 = qcdr(v337);
    v337 = stack[-2];
    v337 = qcdr(v337);
    v337 = qcar(v337);
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = difference2(stack[-1], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-10] = v337;
    v337 = stack[-3];
    v337 = qcdr(v337);
    stack[-3] = v337;
    goto v374;

v375:
    v337 = stack[-14];
    if (v337 == nil) goto v376;
    v337 = stack[-14];
    fn = elt(env, 28); /* maprin */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = elt(env, 15); /* setq */
    fn = elt(env, 29); /* oprin */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    goto v376;

v376:
    v339 = qvalue(elt(env, 16)); /* posn!* */
    v338 = qvalue(elt(env, 17)); /* ycoord!* */
    v337 = stack[-9];
    fn = elt(env, 25); /* update!-pline */
    v338 = (*qfnn(fn))(qenv(fn), 3, v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = qvalue(elt(env, 18)); /* pline!* */
    v337 = Lappend(nil, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    qvalue(elt(env, 18)) = v337; /* pline!* */
    stack[-1] = qvalue(elt(env, 17)); /* ycoord!* */
    v338 = stack[0];
    v337 = (Lisp_Object)33; /* 2 */
    v337 = quot2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = plus2(stack[-1], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = qvalue(elt(env, 19)); /* ymax!* */
    fn = elt(env, 24); /* max */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    qvalue(elt(env, 19)) = v337; /* ymax!* */
    stack[-1] = qvalue(elt(env, 17)); /* ycoord!* */
    v338 = stack[0];
    v337 = (Lisp_Object)33; /* 2 */
    v338 = quot2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[0];
    v337 = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = plus2(stack[-1], v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = qvalue(elt(env, 20)); /* ymin!* */
    fn = elt(env, 26); /* min */
    v337 = (*qfn2(fn))(qenv(fn), v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    qvalue(elt(env, 20)) = v337; /* ymin!* */
    v337 = qvalue(elt(env, 6)); /* !*nat */
    v337 = (v337 == nil ? lisp_true : nil);
    fn = elt(env, 22); /* terpri!* */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    goto v377;

v377:
    v337 = nil;
    { popv(19); return onevalue(v337); }

v359:
    v337 = stack[-12];
    if (v337 == nil) goto v378;
    v337 = elt(env, 9); /* mat!-top!-l */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-17] = v337;
    v337 = elt(env, 10); /* mat!-top!-r */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-16] = v337;
    v337 = qvalue(elt(env, 3)); /* nil */
    stack[-12] = v337;
    goto v379;

v379:
    v338 = stack[-4];
    v337 = (Lisp_Object)33; /* 2 */
    stack[0] = difference2(v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-4];
    v338 = sub1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = stack[-1];
    v339 = acons(stack[0], v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = stack[-16];
    v337 = stack[-3];
    v337 = acons(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-3] = v337;
    v339 = (Lisp_Object)1; /* 0 */
    v338 = (Lisp_Object)17; /* 1 */
    v337 = stack[-1];
    v339 = acons(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v338 = stack[-17];
    v337 = stack[-2];
    v337 = acons(v339, v338, v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-2] = v337;
    v337 = stack[-1];
    v337 = sub1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-1] = v337;
    goto v358;

v378:
    v338 = stack[-1];
    v337 = stack[-6];
    if (!(equal(v338, v337))) goto v380;
    v337 = stack[-10];
    v337 = qcdr(v337);
    if (!(v337 == nil)) goto v380;
    v337 = elt(env, 11); /* mat!-low!-l */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-17] = v337;
    v337 = elt(env, 12); /* mat!-low!-r */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-16] = v337;
    goto v379;

v380:
    v337 = elt(env, 13); /* mat!-mid!-l */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-17] = v337;
    v337 = elt(env, 14); /* mat!-mid!-r */
    fn = elt(env, 27); /* symbol */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-16] = v337;
    goto v379;

v356:
    v337 = stack[-5];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-5] = v337;
    goto v357;

v353:
    v337 = qvalue(elt(env, 3)); /* nil */
    goto v371;

v352:
    v337 = stack[-14];
    if (v337 == nil) goto v381;
    v337 = stack[-14];
    fn = elt(env, 28); /* maprin */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    v337 = elt(env, 15); /* setq */
    fn = elt(env, 29); /* oprin */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    goto v381;

v381:
    v337 = stack[-9];
    fn = elt(env, 30); /* matpri2 */
    v337 = (*qfn1(fn))(qenv(fn), v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    goto v377;

v343:
    v339 = stack[-15];
    v338 = stack[-1];
    v337 = (Lisp_Object)17; /* 1 */
    *(Lisp_Object *)((char *)v339 + (CELL-TAG_VECTOR) + ((int32_t)v338/(16/CELL))) = v337;
    v337 = stack[-1];
    v337 = add1(v337);
    nil = C_nil;
    if (exception_pending()) goto v340;
    env = stack[-18];
    stack[-1] = v337;
    goto v342;

v34:
    v337 = (Lisp_Object)1; /* 0 */
    stack[0] = v337;
    v337 = qvalue(elt(env, 6)); /* !*nat */
    stack[-4] = v337;
    goto v341;
/* error exit handlers */
v340:
    popv(19);
    return nil;
}



/* Code for reval!-without */

static Lisp_Object CC_revalKwithout(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v336, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval-without");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v25;
    stack[-2] = v0;
/* end of prologue */
    v336 = stack[-1];
    v24 = elt(env, 1); /* opmtch */
    v24 = get(v336, v24);
    env = stack[-4];
    stack[-3] = v24;
    v336 = stack[-1];
    v24 = elt(env, 1); /* opmtch */
    v24 = Lremprop(nil, v336, v24);
    env = stack[-4];
    stack[0] = elt(env, 2); /* reval */
    v24 = stack[-2];
    v24 = Lmkquote(nil, v24);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v336 = list2(stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v24 = qvalue(elt(env, 3)); /* t */
    fn = elt(env, 4); /* errorset!* */
    v24 = (*qfn2(fn))(qenv(fn), v336, v24);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    stack[-2] = v24;
    v95 = stack[-1];
    v336 = elt(env, 1); /* opmtch */
    v24 = stack[-3];
    v24 = Lputprop(nil, 3, v95, v336, v24);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    v24 = stack[-2];
    fn = elt(env, 5); /* errorp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-4];
    if (v24 == nil) goto v62;
    v24 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v24 = nil;
    { popv(5); return onevalue(v24); }

v62:
    v24 = stack[-2];
    v24 = qcar(v24);
    { popv(5); return onevalue(v24); }
/* error exit handlers */
v44:
    popv(5);
    return nil;
}



/* Code for aex_ids */

static Lisp_Object CC_aex_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for aex_ids");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v91 = v0;
/* end of prologue */
    fn = elt(env, 1); /* aex_ex */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* ratpoly_idl */
        return (*qfn1(fn))(qenv(fn), v91);
    }
/* error exit handlers */
v74:
    popv(1);
    return nil;
}



/* Code for !:dm2fix */

static Lisp_Object CC_Tdm2fix(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v15;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for :dm2fix");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0;
/* end of prologue */
    v15 = stack[-2];
    v15 = integerp(v15);
    if (!(v15 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v15 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = qvalue(elt(env, 2)); /* !*noequiv */
    qvalue(elt(env, 2)) = v15; /* !*noequiv */
    v15 = stack[-2];
    fn = elt(env, 4); /* int!-equiv!-chk */
    v15 = (*qfn1(fn))(qenv(fn), v15);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    stack[-2] = v15;
    v15 = integerp(v15);
    if (v15 == nil) goto v98;
    v15 = stack[-2];
    goto v101;

v101:
    qvalue(elt(env, 2)) = stack[-3]; /* !*noequiv */
    { popv(5); return onevalue(v15); }

v98:
    v15 = stack[-2];
    if (v15 == nil) goto v59;
    v15 = stack[-2];
    v15 = qcdr(v15);
    v15 = Lfloatp(nil, v15);
    env = stack[-4];
    if (v15 == nil) goto v39;
    stack[-1] = elt(env, 3); /* 0.0 */
    v15 = stack[-2];
    stack[0] = qcdr(v15);
    v15 = stack[-2];
    v15 = qcdr(v15);
    v15 = Ltruncate(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    v15 = difference2(stack[0], v15);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    if (!(equal(stack[-1], v15))) goto v39;
    v15 = stack[-2];
    v15 = qcdr(v15);
    v15 = Ltruncate(nil, v15);
    nil = C_nil;
    if (exception_pending()) goto v24;
    env = stack[-4];
    goto v101;

v39:
    v15 = stack[-2];
    goto v101;

v59:
    v15 = (Lisp_Object)1; /* 0 */
    goto v101;
/* error exit handlers */
v24:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* !*noequiv */
    popv(5);
    return nil;
}



/* Code for makeanewindex */

static Lisp_Object MS_CDECL CC_makeanewindex(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "makeanewindex");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for makeanewindex");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* end of prologue */
    v28 = (Lisp_Object)1; /* 0 */
    stack[0] = v28;
    goto v91;

v91:
    v28 = stack[0];
    v28 = add1(v28);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    stack[0] = v28;
    v71 = elt(env, 1); /* idx */
    v28 = stack[0];
    fn = elt(env, 2); /* mkid */
    v28 = (*qfn2(fn))(qenv(fn), v71, v28);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    stack[-1] = v28;
    v28 = stack[-1];
    fn = elt(env, 3); /* isanindex */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (!(v28 == nil)) goto v91;
    v28 = stack[-1];
    fn = elt(env, 4); /* putanewindex */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v18;
    { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for dp_comp */

static Lisp_Object CC_dp_comp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_comp");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v106 = v25;
    v7 = v0;
/* end of prologue */
    fn = elt(env, 2); /* dp!=comp */
    v106 = (*qfn2(fn))(qenv(fn), v7, v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    stack[-4] = v106;
    v106 = stack[-4];
    if (v106 == nil) goto v90;
    v106 = stack[-4];
    v106 = qcar(v106);
    stack[0] = v106;
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 3); /* mo_deletecomp */
    v7 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = cons(v7, v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    stack[-2] = v106;
    stack[-3] = v106;
    goto v1;

v1:
    v106 = stack[-4];
    v106 = qcdr(v106);
    stack[-4] = v106;
    v106 = stack[-4];
    if (v106 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    stack[-1] = stack[-2];
    v106 = stack[-4];
    v106 = qcar(v106);
    stack[0] = v106;
    v106 = stack[0];
    v106 = qcar(v106);
    fn = elt(env, 3); /* mo_deletecomp */
    v7 = (*qfn1(fn))(qenv(fn), v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = stack[0];
    v106 = qcdr(v106);
    v106 = cons(v7, v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = ncons(v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = Lrplacd(nil, stack[-1], v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = stack[-2];
    v106 = qcdr(v106);
    stack[-2] = v106;
    goto v1;

v90:
    v106 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v106); }
/* error exit handlers */
v9:
    popv(6);
    return nil;
}



/* Code for partsym_zerop */

static Lisp_Object CC_partsym_zerop(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v104, v82, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partsym_zerop");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v25;
    stack[-1] = v0;
/* end of prologue */

v382:
    v104 = stack[-1];
    if (v104 == nil) goto v91;
    v104 = stack[-1];
    v104 = qcar(v104);
    fn = elt(env, 3); /* repeats */
    v104 = (*qfn1(fn))(qenv(fn), v104);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-2];
    v83 = v104;
    v104 = stack[0];
    v82 = qcar(v104);
    v104 = elt(env, 2); /* !- */
    if (!(v82 == v104)) goto v19;
    v104 = v83;
    if (!(v104 == nil)) { popv(3); return onevalue(v83); }

v19:
    v104 = stack[-1];
    v82 = qcdr(v104);
    v104 = stack[0];
    v104 = qcdr(v104);
    stack[-1] = v82;
    stack[0] = v104;
    goto v382;

v91:
    v104 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v104); }
/* error exit handlers */
v64:
    popv(3);
    return nil;
}



/* Code for division!-test */

static Lisp_Object CC_divisionKtest(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for division-test");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v25;
    stack[-1] = v0;
/* end of prologue */

v91:
    v28 = stack[0];
    if (v28 == nil) goto v1;
    v28 = stack[0];
    v71 = qcar(v28);
    v28 = stack[-1];
    fn = elt(env, 3); /* quotf */
    v28 = (*qfn2(fn))(qenv(fn), v71, v28);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-2];
    if (v28 == nil) goto v108;
    v28 = stack[0];
    v28 = qcdr(v28);
    stack[0] = v28;
    goto v91;

v108:
    v28 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v28); }

v1:
    v28 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v28); }
/* error exit handlers */
v18:
    popv(3);
    return nil;
}



/* Code for giprim */

static Lisp_Object CC_giprim(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v38, v28, v71;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for giprim");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v71 = v0;
/* end of prologue */
    v28 = v71;
    v38 = (Lisp_Object)17; /* 1 */
    if (v28 == v38) goto v11;
    v38 = elt(env, 2); /* times */
    v28 = v71;
    v71 = elt(env, 1); /* i */
    return list3(v38, v28, v71);

v11:
    v38 = elt(env, 1); /* i */
    return onevalue(v38);
}



/* Code for dip_condense */

static Lisp_Object CC_dip_condense(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object v5;
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dip_condense");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    return onevalue(v5);
}



/* Code for revise2 */

static Lisp_Object CC_revise2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v403, v404, v405;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for revise2");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v25;
    stack[0] = v0;
/* end of prologue */
    v403 = stack[0];
    if (!consp(v403)) goto v1;
    v403 = stack[0];
    fn = elt(env, 7); /* constp */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    if (!(v403 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v403 = stack[0];
    v403 = qcar(v403);
    fn = elt(env, 8); /* subscriptedvarp */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    if (v403 == nil) goto v407;
    v403 = stack[0];
    v404 = qcar(v403);
    v403 = elt(env, 1); /* aliaslist */
    v403 = get(v404, v403);
    env = stack[-6];
    if (v403 == nil) goto v94;
    v403 = stack[0];
    stack[-5] = qcar(v403);
    v403 = stack[0];
    fn = elt(env, 9); /* ireval */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = qcdr(v403);
    stack[-3] = v403;
    v403 = stack[-3];
    if (v403 == nil) goto v408;
    v403 = stack[-3];
    v403 = qcar(v403);
    v404 = v403;
    v403 = stack[-4];
    v403 = CC_revise2(env, v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = ncons(v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    stack[-1] = v403;
    stack[-2] = v403;
    goto v111;

v111:
    v403 = stack[-3];
    v403 = qcdr(v403);
    stack[-3] = v403;
    v403 = stack[-3];
    if (v403 == nil) goto v126;
    stack[0] = stack[-1];
    v403 = stack[-3];
    v403 = qcar(v403);
    v404 = v403;
    v403 = stack[-4];
    v403 = CC_revise2(env, v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = ncons(v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = Lrplacd(nil, stack[0], v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = stack[-1];
    v403 = qcdr(v403);
    stack[-1] = v403;
    goto v111;

v126:
    v403 = stack[-2];
    goto v76;

v76:
    v403 = cons(stack[-5], v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    stack[0] = v403;
    v405 = stack[0];
    v403 = stack[0];
    v404 = qcar(v403);
    v403 = elt(env, 2); /* finalalias */
    v403 = get(v404, v403);
    env = stack[-6];
    v403 = Lassoc(nil, v405, v403);
    v404 = v403;
    if (v403 == nil) goto v409;
    v403 = v404;
    v403 = qcdr(v403);
    v403 = qcar(v403);
    { popv(7); return onevalue(v403); }

v409:
    v403 = qvalue(elt(env, 5)); /* !*vectorc */
    if (v403 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v403 = stack[0];
    fn = elt(env, 10); /* introduce!-alias */
    v405 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v404 = stack[0];
    v403 = qvalue(elt(env, 6)); /* rhsaliases */
    v403 = acons(v405, v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    qvalue(elt(env, 6)) = v403; /* rhsaliases */
    v403 = qvalue(elt(env, 6)); /* rhsaliases */
    v403 = qcar(v403);
    v403 = qcar(v403);
    { popv(7); return onevalue(v403); }

v408:
    v403 = qvalue(elt(env, 4)); /* nil */
    goto v76;

v94:
    v403 = qvalue(elt(env, 5)); /* !*vectorc */
    if (v403 == nil) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v403 = stack[0];
    fn = elt(env, 10); /* introduce!-alias */
    v405 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v404 = stack[0];
    v403 = qvalue(elt(env, 6)); /* rhsaliases */
    v403 = acons(v405, v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    qvalue(elt(env, 6)) = v403; /* rhsaliases */
    v403 = qvalue(elt(env, 6)); /* rhsaliases */
    v403 = qcar(v403);
    v403 = qcar(v403);
    { popv(7); return onevalue(v403); }

v407:
    v404 = stack[0];
    v403 = stack[-4];
    v403 = Lassoc(nil, v404, v403);
    v404 = v403;
    if (v403 == nil) goto v410;
    v403 = v404;
    v403 = qcdr(v403);
    v403 = qcar(v403);
    { popv(7); return onevalue(v403); }

v410:
    v403 = stack[0];
    stack[-5] = qcar(v403);
    v403 = stack[0];
    v403 = qcdr(v403);
    stack[-3] = v403;
    v403 = stack[-3];
    if (v403 == nil) goto v411;
    v403 = stack[-3];
    v403 = qcar(v403);
    v404 = v403;
    v403 = stack[-4];
    v403 = CC_revise2(env, v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = ncons(v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    stack[-1] = v403;
    stack[-2] = v403;
    goto v412;

v412:
    v403 = stack[-3];
    v403 = qcdr(v403);
    stack[-3] = v403;
    v403 = stack[-3];
    if (v403 == nil) goto v413;
    stack[0] = stack[-1];
    v403 = stack[-3];
    v403 = qcar(v403);
    v404 = v403;
    v403 = stack[-4];
    v403 = CC_revise2(env, v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = ncons(v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = Lrplacd(nil, stack[0], v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    v403 = stack[-1];
    v403 = qcdr(v403);
    stack[-1] = v403;
    goto v412;

v413:
    v403 = stack[-2];
    goto v414;

v414:
    {
        Lisp_Object v311 = stack[-5];
        popv(7);
        return cons(v311, v403);
    }

v411:
    v403 = qvalue(elt(env, 4)); /* nil */
    goto v414;

v1:
    v403 = stack[0];
    fn = elt(env, 7); /* constp */
    v403 = (*qfn1(fn))(qenv(fn), v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    if (!(v403 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v404 = stack[0];
    v403 = elt(env, 1); /* aliaslist */
    v403 = get(v404, v403);
    env = stack[-6];
    if (v403 == nil) goto v42;
    v403 = stack[0];
    v404 = elt(env, 2); /* finalalias */
    popv(7);
    return get(v403, v404);

v42:
    v404 = stack[0];
    v403 = qvalue(elt(env, 3)); /* known */
    v403 = Lmember(nil, v404, v403);
    if (!(v403 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    v404 = stack[0];
    v403 = qvalue(elt(env, 3)); /* known */
    v403 = cons(v404, v403);
    nil = C_nil;
    if (exception_pending()) goto v406;
    env = stack[-6];
    qvalue(elt(env, 3)) = v403; /* known */
    { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
/* error exit handlers */
v406:
    popv(7);
    return nil;
}



/* Code for bccheckz */

static Lisp_Object CC_bccheckz(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62, v63, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bccheckz");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v62 = v0;
/* end of prologue */
    v63 = v62;
    v63 = qcar(v63);
    if (v63 == nil) { popv(3); return onevalue(v62); }
    v63 = qvalue(elt(env, 1)); /* !*bcsubs2 */
    if (v63 == nil) goto v101;
    {
        popv(3);
        fn = elt(env, 4); /* subs2 */
        return (*qfn1(fn))(qenv(fn), v62);
    }

v101:
    v55 = qvalue(elt(env, 2)); /* bczerodivl!* */
    v63 = v62;
    v63 = qcar(v63);
    v62 = qcdr(v62);
    stack[-1] = v55;
    stack[0] = v62;
    goto v17;

v17:
    v62 = stack[-1];
    if (v62 == nil) goto v131;
    v62 = v63;
    if (v62 == nil) goto v131;
    v62 = stack[-1];
    v62 = qcar(v62);
    fn = elt(env, 5); /* qremf */
    v62 = (*qfn2(fn))(qenv(fn), v63, v62);
    nil = C_nil;
    if (exception_pending()) goto v336;
    env = stack[-2];
    v62 = qcdr(v62);
    v63 = v62;
    v62 = stack[-1];
    v62 = qcdr(v62);
    stack[-1] = v62;
    goto v17;

v131:
    v62 = stack[0];
    popv(3);
    return cons(v63, v62);
/* error exit handlers */
v336:
    popv(3);
    return nil;
}



/* Code for vdptdeg */

static Lisp_Object CC_vdptdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v14;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vdptdeg");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v74;

v74:
    v39 = stack[0];
    if (v39 == nil) goto v89;
    v39 = stack[0];
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    v39 = qcar(v39);
    if (v39 == nil) goto v89;
    v39 = stack[0];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    fn = elt(env, 1); /* vevtdeg */
    v14 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v39 = stack[-1];
    v39 = cons(v14, v39);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    stack[-1] = v39;
    v39 = stack[0];
    fn = elt(env, 2); /* vdpred */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    stack[0] = v39;
    goto v74;

v89:
    v39 = (Lisp_Object)1; /* 0 */
    v14 = v39;
    goto v1;

v1:
    v39 = stack[-1];
    if (v39 == nil) { popv(3); return onevalue(v14); }
    v39 = stack[-1];
    v39 = qcar(v39);
    fn = elt(env, 3); /* max */
    v39 = (*qfn2(fn))(qenv(fn), v39, v14);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-2];
    v14 = v39;
    v39 = stack[-1];
    v39 = qcdr(v39);
    stack[-1] = v39;
    goto v1;
/* error exit handlers */
v62:
    popv(3);
    return nil;
}



/* Code for rembras */

static Lisp_Object CC_rembras(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rembras");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v60 = qvalue(elt(env, 1)); /* !*nat */
    if (v60 == nil) goto v16;
    v60 = stack[0];
    if (!consp(v60)) goto v11;
    v60 = stack[0];
    v19 = qcar(v60);
    v60 = elt(env, 2); /* infix */
    v60 = get(v19, v60);
    env = stack[-1];
    if (!(v60 == nil)) goto v16;

v11:
    v60 = elt(env, 3); /* " " */
    fn = elt(env, 6); /* prin2!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v60 = stack[0];
    {
        popv(2);
        fn = elt(env, 7); /* maprin */
        return (*qfn1(fn))(qenv(fn), v60);
    }

v16:
    v60 = elt(env, 4); /* "(" */
    fn = elt(env, 6); /* prin2!* */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v60 = stack[0];
    fn = elt(env, 7); /* maprin */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    v60 = elt(env, 5); /* ")" */
    {
        popv(2);
        fn = elt(env, 6); /* prin2!* */
        return (*qfn1(fn))(qenv(fn), v60);
    }
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for mkprogn */

static Lisp_Object CC_mkprogn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v68, v42, v104;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprogn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v42 = v25;
    v104 = v0;
/* end of prologue */
    v68 = v42;
    v96 = elt(env, 1); /* progn */
    if (!consp(v68)) goto v72;
    v68 = qcar(v68);
    if (!(v68 == v96)) goto v72;
    v96 = elt(env, 1); /* progn */
    v68 = v104;
    v42 = qcdr(v42);
    return list2star(v96, v68, v42);

v72:
    v96 = elt(env, 1); /* progn */
    v68 = v104;
    return list3(v96, v68, v42);
}



/* Code for listnoeval */

static Lisp_Object CC_listnoeval(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v49, v16;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for listnoeval");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v16 = v25;
    v49 = v0;
/* end of prologue */

v91:
    v16 = v49;
    if (!(!consp(v16))) { popv(1); return onevalue(v49); }
    v16 = v49;
    v49 = elt(env, 1); /* avalue */
    v49 = get(v16, v49);
    env = stack[0];
    v49 = qcdr(v49);
    v49 = qcar(v49);
    goto v91;
}



/* Code for partdfsq */

static Lisp_Object CC_partdfsq(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for partdfsq");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v25;
    stack[-2] = v0;
/* end of prologue */
    v47 = stack[-2];
    v131 = qcar(v47);
    v47 = stack[-1];
    fn = elt(env, 1); /* partdff */
    stack[-3] = (*qfn2(fn))(qenv(fn), v131, v47);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    stack[0] = stack[-2];
    v47 = stack[-2];
    v47 = qcdr(v47);
    fn = elt(env, 2); /* negf */
    v131 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v47 = stack[-1];
    fn = elt(env, 1); /* partdff */
    v47 = (*qfn2(fn))(qenv(fn), v131, v47);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 3); /* multsq */
    v47 = (*qfn2(fn))(qenv(fn), stack[0], v47);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    fn = elt(env, 4); /* addsq */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-3], v47);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    v131 = (Lisp_Object)17; /* 1 */
    v47 = stack[-2];
    v47 = qcdr(v47);
    v47 = cons(v131, v47);
    nil = C_nil;
    if (exception_pending()) goto v62;
    env = stack[-4];
    {
        Lisp_Object v63 = stack[0];
        popv(5);
        fn = elt(env, 3); /* multsq */
        return (*qfn2(fn))(qenv(fn), v63, v47);
    }
/* error exit handlers */
v62:
    popv(5);
    return nil;
}



/* Code for find_bubles1_coeff */

static Lisp_Object MS_CDECL CC_find_bubles1_coeff(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v106, v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "find_bubles1_coeff");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_bubles1_coeff");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v25,v6,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v5;
    stack[0] = v6;
    stack[-1] = v25;
    stack[-4] = v0;
/* end of prologue */

v382:
    v106 = stack[-4];
    if (v106 == nil) goto v4;
    v106 = stack[-4];
    v7 = qcar(v106);
    v106 = stack[0];
    fn = elt(env, 1); /* find_bubles1 */
    v106 = (*qfn2(fn))(qenv(fn), v7, v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    stack[-2] = v106;
    v106 = stack[-4];
    stack[-4] = qcdr(v106);
    v106 = stack[-2];
    v7 = qcdr(v106);
    v106 = stack[-1];
    stack[-1] = cons(v7, v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    v106 = stack[-2];
    v106 = qcar(v106);
    if (v106 == nil) goto v81;
    v106 = stack[-2];
    v7 = qcar(v106);
    v106 = stack[-3];
    v106 = cons(v7, v106);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-5];
    goto v103;

v103:
    stack[-3] = v106;
    goto v382;

v81:
    v106 = stack[-3];
    goto v103;

v4:
    v7 = stack[-3];
    v106 = stack[-1];
    popv(6);
    return cons(v7, v106);
/* error exit handlers */
v9:
    popv(6);
    return nil;
}



/* Code for ratplusm */

static Lisp_Object MS_CDECL CC_ratplusm(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v419, v396, v397;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ratplusm");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratplusm");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v6;
    v396 = v25;
    v397 = v0;
/* end of prologue */
    v419 = v397;
    v419 = qcar(v419);
    stack[0] = v419;
    v419 = v397;
    v419 = qcdr(v419);
    stack[-5] = v419;
    v419 = v396;
    v419 = qcar(v419);
    stack[-3] = v419;
    v419 = v396;
    v419 = qcdr(v419);
    stack[-2] = v419;
    v396 = stack[-5];
    v419 = stack[-2];
    if (equal(v396, v419)) goto v60;
    v396 = stack[-5];
    v419 = stack[-2];
    v419 = Lgcd(nil, v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    stack[-1] = v419;
    v396 = stack[-2];
    v419 = stack[-1];
    v396 = quot2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    v419 = stack[0];
    stack[0] = times2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    v396 = stack[-5];
    v419 = stack[-1];
    v396 = quot2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    v419 = stack[-3];
    v419 = times2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    v419 = plus2(stack[0], v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    stack[0] = v419;
    v396 = stack[-5];
    v419 = stack[-1];
    v396 = quot2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    v419 = stack[-2];
    v419 = times2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    stack[-2] = v419;
    goto v86;

v86:
    v419 = stack[-4];
    if (v419 == nil) goto v421;
    v396 = stack[-2];
    v419 = stack[-2];
    v419 = plus2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    stack[-2] = v419;
    goto v421;

v421:
    v396 = stack[0];
    v419 = (Lisp_Object)1; /* 0 */
    if (v396 == v419) goto v334;
    v396 = stack[0];
    v419 = stack[-2];
    v419 = Lgcd(nil, v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    stack[-1] = v419;
    v396 = stack[0];
    v419 = stack[-1];
    stack[0] = quot2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    v396 = stack[-2];
    v419 = stack[-1];
    v419 = quot2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    {
        Lisp_Object v342 = stack[0];
        popv(7);
        return cons(v342, v419);
    }

v334:
    v396 = (Lisp_Object)1; /* 0 */
    v419 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v396, v419);

v60:
    v396 = stack[0];
    v419 = stack[-3];
    v419 = plus2(v396, v419);
    nil = C_nil;
    if (exception_pending()) goto v420;
    env = stack[-6];
    stack[0] = v419;
    v419 = stack[-5];
    stack[-2] = v419;
    goto v86;
/* error exit handlers */
v420:
    popv(7);
    return nil;
}



/* Code for gd_applyscheme */

static Lisp_Object CC_gd_applyscheme(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v25)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95, v66, v67;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gd_applyscheme");
#endif
    if (stack >= stacklimit)
    {
        push2(v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v25);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v25;
    stack[-3] = v0;
/* end of prologue */
    stack[-4] = nil;
    v95 = (Lisp_Object)1; /* 0 */
    stack[-1] = v95;
    v95 = stack[-2];
    stack[0] = v95;
    goto v4;

v4:
    v95 = stack[0];
    if (v95 == nil) goto v64;
    v95 = stack[-1];
    v95 = add1(v95);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-1] = v95;
    v66 = elt(env, 2); /* a */
    v95 = stack[-1];
    fn = elt(env, 3); /* mkid */
    v67 = (*qfn2(fn))(qenv(fn), v66, v95);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    v95 = stack[-2];
    v66 = qcar(v95);
    v95 = stack[-4];
    v95 = acons(v67, v66, v95);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-5];
    stack[-4] = v95;
    v95 = stack[-2];
    v95 = qcdr(v95);
    stack[-2] = v95;
    v95 = stack[0];
    v95 = qcdr(v95);
    stack[0] = v95;
    goto v4;

v64:
    stack[0] = stack[-4];
    v66 = stack[-3];
    v95 = stack[-1];
    fn = elt(env, 4); /* gd_getscheme */
    v95 = (*qfn2(fn))(qenv(fn), v66, v95);
    nil = C_nil;
    if (exception_pending()) goto v106;
    {
        Lisp_Object v7 = stack[0];
        popv(6);
        return Lsublis(nil, v7, v95);
    }
/* error exit handlers */
v106:
    popv(6);
    return nil;
}



/* Code for make!-var!-coefflist */

static Lisp_Object MS_CDECL CC_makeKvarKcoefflist(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, Lisp_Object v5,
                         Lisp_Object v11, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v19, v84, v54, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 5, "make-var-coefflist");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-var-coefflist");
#endif
    if (stack >= stacklimit)
    {
        push5(v11,v5,v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop5(v0,v25,v6,v5,v11);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v60 = v11;
    v19 = v5;
    v84 = v6;
    v54 = v25;
    v23 = v0;
/* end of prologue */
    fn = elt(env, 1); /* make!-var!-powerlist */
    v84 = (*qfnn(fn))(qenv(fn), 5, v23, v54, v84, v19, v60);
    errexit();
    v19 = (Lisp_Object)17; /* 1 */
    v60 = (Lisp_Object)17; /* 1 */
    return list2star(v84, v19, v60);
}



/* Code for nsubsq */

static Lisp_Object MS_CDECL CC_nsubsq(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v72, v53, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "nsubsq");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nsubsq");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v72 = v6;
    v53 = v25;
    v18 = v0;
/* end of prologue */
    stack[-2] = v18;
    stack[-1] = v53;
    stack[0] = elt(env, 1); /* plus */
    v72 = list2(v53, v72);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v72 = list2star(stack[-1], stack[0], v72);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    v72 = ncons(v72);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-3];
    {
        Lisp_Object v23 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* subsq */
        return (*qfn2(fn))(qenv(fn), v23, v72);
    }
/* error exit handlers */
v54:
    popv(4);
    return nil;
}



/* Code for ps!:onep!: */

static Lisp_Object CC_psTonepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:onep:");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v91 = v0;
/* end of prologue */
    fn = elt(env, 1); /* ps!:value */
    v91 = (*qfn1(fn))(qenv(fn), v91);
    errexit();
        return Lonep(nil, v91);
}



/* Code for smaddm2 */

static Lisp_Object MS_CDECL CC_smaddm2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v25,
                         Lisp_Object v6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v425, v426, v115, v326;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "smaddm2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smaddm2");
#endif
    if (stack >= stacklimit)
    {
        push3(v6,v25,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v25,v6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-8] = v6;
    v426 = v25;
    v425 = v0;
/* end of prologue */
    stack[-7] = v425;
    v425 = v426;
    stack[-6] = v425;
    v426 = stack[-6];
    v425 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 2); /* copy_vect */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    stack[-9] = v425;
    v425 = (Lisp_Object)17; /* 1 */
    stack[-2] = v425;
    goto v103;

v103:
    v425 = stack[-8];
    v425 = qcdr(v425);
    v426 = qcar(v425);
    v425 = stack[-2];
    v425 = difference2(v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    v425 = Lminusp(nil, v425);
    env = stack[-10];
    if (!(v425 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    v426 = stack[-7];
    v425 = stack[-2];
    fn = elt(env, 3); /* findrow */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    stack[0] = v425;
    v426 = stack[-6];
    v425 = stack[-2];
    fn = elt(env, 3); /* findrow */
    v425 = (*qfn2(fn))(qenv(fn), v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    stack[-5] = v425;
    v425 = stack[0];
    if (v425 == nil) goto v44;
    v425 = stack[0];
    v425 = qcdr(v425);
    stack[-1] = v425;
    goto v94;

v94:
    v425 = stack[-1];
    if (v425 == nil) goto v44;
    v425 = stack[-1];
    v425 = qcar(v425);
    v426 = v425;
    v425 = v426;
    v425 = qcar(v425);
    stack[-3] = v425;
    v425 = v426;
    v425 = qcdr(v425);
    stack[0] = v425;
    v426 = stack[-3];
    v425 = stack[-5];
    v425 = Latsoc(nil, v426, v425);
    stack[-4] = v425;
    v425 = stack[-4];
    if (v425 == nil) goto v97;
    v425 = stack[-4];
    v425 = qcdr(v425);
    stack[-4] = v425;
    v425 = stack[0];
    fn = elt(env, 4); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    v425 = stack[-4];
    fn = elt(env, 4); /* simp */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    fn = elt(env, 5); /* addsq */
    v425 = (*qfn2(fn))(qenv(fn), stack[0], v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    stack[0] = v425;
    v425 = stack[0];
    fn = elt(env, 6); /* mk!*sq */
    v425 = (*qfn1(fn))(qenv(fn), v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    stack[0] = v425;
    v115 = stack[-9];
    v426 = stack[-2];
    v425 = stack[-3];
    v326 = list3(v115, v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    v115 = stack[0];
    v426 = stack[-9];
    v425 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v425 = (*qfnn(fn))(qenv(fn), 4, v326, v115, v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    goto v113;

v113:
    v425 = stack[-1];
    v425 = qcdr(v425);
    stack[-1] = v425;
    goto v94;

v97:
    v115 = stack[-9];
    v426 = stack[-2];
    v425 = stack[-3];
    v326 = list3(v115, v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    v115 = stack[0];
    v426 = stack[-9];
    v425 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 7); /* letmtr3 */
    v425 = (*qfnn(fn))(qenv(fn), 4, v326, v115, v426, v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    goto v113;

v44:
    v425 = stack[-2];
    v425 = add1(v425);
    nil = C_nil;
    if (exception_pending()) goto v325;
    env = stack[-10];
    stack[-2] = v425;
    goto v103;
/* error exit handlers */
v325:
    popv(11);
    return nil;
}



/* Code for check_info */

static Lisp_Object CC_check_info(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v125, v398, v399;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for check_info");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0;
/* end of prologue */
    v125 = stack[0];
    v125 = Lconsp(nil, v125);
    env = stack[-1];
    if (v125 == nil) goto v1;
    v125 = stack[0];
    fn = elt(env, 8); /* constp */
    v125 = (*qfn1(fn))(qenv(fn), v125);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-1];
    if (!(v125 == nil)) goto v74;
    v125 = stack[0];
    stack[0] = v125;
    goto v48;

v48:
    v125 = stack[0];
    if (v125 == nil) goto v74;
    v125 = stack[0];
    v125 = qcar(v125);
    v125 = CC_check_info(env, v125);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-1];
    v125 = stack[0];
    v125 = qcdr(v125);
    stack[0] = v125;
    goto v48;

v74:
    v125 = nil;
    { popv(2); return onevalue(v125); }

v1:
    v125 = stack[0];
    if (!(symbolp(v125))) goto v74;
    v398 = stack[0];
    v125 = qvalue(elt(env, 2)); /* avarlst */
    v125 = Lmemq(nil, v398, v125);
    if (!(v125 == nil)) goto v74;
    v398 = stack[0];
    v125 = elt(env, 3); /* avalue */
    v398 = get(v398, v125);
    env = stack[-1];
    v125 = v398;
    if (v398 == nil) goto v74;
    v399 = stack[0];
    v398 = elt(env, 4); /* a2value */
    v125 = Lputprop(nil, 3, v399, v398, v125);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-1];
    v398 = stack[0];
    v125 = elt(env, 3); /* avalue */
    v125 = Lremprop(nil, v398, v125);
    env = stack[-1];
    v398 = stack[0];
    v125 = qvalue(elt(env, 2)); /* avarlst */
    v125 = cons(v398, v125);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-1];
    qvalue(elt(env, 2)) = v125; /* avarlst */
    v398 = stack[0];
    v125 = elt(env, 5); /* rtype */
    v398 = get(v398, v125);
    env = stack[-1];
    v125 = elt(env, 6); /* (array matrix) */
    v125 = Lmember(nil, v398, v125);
    if (v125 == nil) goto v74;
    v398 = stack[0];
    v399 = stack[0];
    v125 = elt(env, 5); /* rtype */
    v399 = get(v399, v125);
    env = stack[-1];
    v125 = qvalue(elt(env, 7)); /* malst */
    v125 = acons(v398, v399, v125);
    nil = C_nil;
    if (exception_pending()) goto v427;
    env = stack[-1];
    qvalue(elt(env, 7)) = v125; /* malst */
    v398 = stack[0];
    v125 = elt(env, 5); /* rtype */
    v125 = Lremprop(nil, v398, v125);
    goto v74;
/* error exit handlers */
v427:
    popv(2);
    return nil;
}



/* Code for nestprep!: */

static Lisp_Object CC_nestprepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for nestprep:");
#endif
    if (stack >= stacklimit)
    {
        push(v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v61 = v0;
/* end of prologue */
    stack[-1] = elt(env, 1); /* co */
    v103 = v61;
    v103 = integerp(v103);
    if (v103 == nil) goto v107;
    v103 = (Lisp_Object)1; /* 0 */
    stack[0] = v103;
    goto v89;

v89:
    v103 = v61;
    v103 = integerp(v103);
    if (v103 == nil) goto v18;
    v103 = v61;
    fn = elt(env, 2); /* simp */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v42;
    env = stack[-2];
    goto v16;

v16:
    fn = elt(env, 3); /* prepsq */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v42;
    {
        Lisp_Object v104 = stack[-1];
        Lisp_Object v82 = stack[0];
        popv(3);
        return list3(v104, v82, v103);
    }

v18:
    v103 = v61;
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    v103 = qcdr(v103);
    goto v16;

v107:
    v103 = v61;
    v103 = qcdr(v103);
    v103 = qcar(v103);
    stack[0] = v103;
    goto v89;
/* error exit handlers */
v42:
    popv(3);
    return nil;
}



setup_type const u47_setup[] =
{
    {"mk_simpl_map_",           CC_mk_simpl_map_,too_many_1,   wrong_no_1},
    {"pst_equitable",           CC_pst_equitable,too_many_1,   wrong_no_1},
    {"ofsf_smmkatl-and",        wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_smmkatlKand},
    {"collectpolyvarsaux",      too_few_2,      CC_collectpolyvarsaux,wrong_no_2},
    {"dip_f2dip1",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_dip_f2dip1},
    {"tryreduction",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_tryreduction},
    {"ldt-dep",                 CC_ldtKdep,     too_many_1,    wrong_no_1},
    {"improvelayout",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_improvelayout},
    {"updkorder",               CC_updkorder,   too_many_1,    wrong_no_1},
    {"dip2a1",                  CC_dip2a1,      too_many_1,    wrong_no_1},
    {"prepsqyy",                CC_prepsqyy,    too_many_1,    wrong_no_1},
    {"generic-sub",             too_few_2,      CC_genericKsub,wrong_no_2},
    {"tensor_has_dummy_idx",    too_few_2,      CC_tensor_has_dummy_idx,wrong_no_2},
    {"xprint",                  too_few_2,      CC_xprint,     wrong_no_2},
    {"movebds",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_movebds},
    {"cl_pop",                  CC_cl_pop,      too_many_1,    wrong_no_1},
    {"*addsq",                  too_few_2,      CC_Haddsq,     wrong_no_2},
    {"matpri1",                 too_few_2,      CC_matpri1,    wrong_no_2},
    {"reval-without",           too_few_2,      CC_revalKwithout,wrong_no_2},
    {"aex_ids",                 CC_aex_ids,     too_many_1,    wrong_no_1},
    {":dm2fix",                 CC_Tdm2fix,     too_many_1,    wrong_no_1},
    {"makeanewindex",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeanewindex},
    {"dp_comp",                 too_few_2,      CC_dp_comp,    wrong_no_2},
    {"partsym_zerop",           too_few_2,      CC_partsym_zerop,wrong_no_2},
    {"division-test",           too_few_2,      CC_divisionKtest,wrong_no_2},
    {"giprim",                  CC_giprim,      too_many_1,    wrong_no_1},
    {"dip_condense",            CC_dip_condense,too_many_1,    wrong_no_1},
    {"revise2",                 too_few_2,      CC_revise2,    wrong_no_2},
    {"bccheckz",                CC_bccheckz,    too_many_1,    wrong_no_1},
    {"vdptdeg",                 CC_vdptdeg,     too_many_1,    wrong_no_1},
    {"rembras",                 CC_rembras,     too_many_1,    wrong_no_1},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"listnoeval",              too_few_2,      CC_listnoeval, wrong_no_2},
    {"partdfsq",                too_few_2,      CC_partdfsq,   wrong_no_2},
    {"find_bubles1_coeff",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles1_coeff},
    {"ratplusm",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_ratplusm},
    {"gd_applyscheme",          too_few_2,      CC_gd_applyscheme,wrong_no_2},
    {"make-var-coefflist",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_makeKvarKcoefflist},
    {"nsubsq",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_nsubsq},
    {"ps:onep:",                CC_psTonepT,    too_many_1,    wrong_no_1},
    {"smaddm2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_smaddm2},
    {"check_info",              CC_check_info,  too_many_1,    wrong_no_1},
    {"nestprep:",               CC_nestprepT,   too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u47", (two_args *)"18585 1291857 6869434", 0}
};

/* end of generated code */
