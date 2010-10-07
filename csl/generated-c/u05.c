
/* $destdir\u05.c        Machine generated C code */

/* Signature: 00000000 07-Oct-2010 */

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
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
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
extern int force_reclaim_method;
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
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
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


/* Code for layout!-formula */

static Lisp_Object MS_CDECL CC_layoutKformula(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v25;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "layout-formula");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for layout-formula");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = v2;
    stack[-7] = v1;
    stack[-8] = v0;
/* end of prologue */
    stack[-9] = qvalue(elt(env, 1)); /* ycoord!* */
    qvalue(elt(env, 1)) = nil; /* ycoord!* */
    stack[-5] = qvalue(elt(env, 2)); /* ymin!* */
    qvalue(elt(env, 2)) = nil; /* ymin!* */
    stack[-4] = qvalue(elt(env, 3)); /* ymax!* */
    qvalue(elt(env, 3)) = nil; /* ymax!* */
    stack[-3] = qvalue(elt(env, 4)); /* posn!* */
    qvalue(elt(env, 4)) = nil; /* posn!* */
    stack[-2] = qvalue(elt(env, 5)); /* pline!* */
    qvalue(elt(env, 5)) = nil; /* pline!* */
    stack[-1] = qvalue(elt(env, 6)); /* testing!-width!* */
    qvalue(elt(env, 6)) = nil; /* testing!-width!* */
    stack[0] = qvalue(elt(env, 7)); /* overflowed!* */
    qvalue(elt(env, 7)) = nil; /* overflowed!* */
    v24 = qvalue(elt(env, 8)); /* nil */
    qvalue(elt(env, 7)) = v24; /* overflowed!* */
    qvalue(elt(env, 5)) = v24; /* pline!* */
    v24 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 3)) = v24; /* ymax!* */
    qvalue(elt(env, 2)) = v24; /* ymin!* */
    qvalue(elt(env, 1)) = v24; /* ycoord!* */
    v24 = qvalue(elt(env, 9)); /* orig!* */
    qvalue(elt(env, 4)) = v24; /* posn!* */
    v24 = qvalue(elt(env, 10)); /* t */
    qvalue(elt(env, 6)) = v24; /* testing!-width!* */
    v24 = stack[-6];
    if (v24 == nil) goto v26;
    v25 = stack[-6];
    v24 = elt(env, 11); /* inbrackets */
    if (v25 == v24) goto v27;
    v24 = stack[-6];
    fn = elt(env, 14); /* oprin */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    goto v26;

v26:
    v25 = stack[-8];
    v24 = stack[-7];
    fn = elt(env, 15); /* maprint */
    v24 = (*qfn2(fn))(qenv(fn), v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    v25 = stack[-6];
    v24 = elt(env, 11); /* inbrackets */
    if (!(v25 == v24)) goto v29;
    v24 = elt(env, 13); /* ")" */
    fn = elt(env, 16); /* prin2!* */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    goto v29;

v29:
    v24 = qvalue(elt(env, 7)); /* overflowed!* */
    if (v24 == nil) goto v30;
    v24 = qvalue(elt(env, 8)); /* nil */
    goto v31;

v31:
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    { popv(11); return onevalue(v24); }

v30:
    stack[-7] = qvalue(elt(env, 5)); /* pline!* */
    v25 = qvalue(elt(env, 4)); /* posn!* */
    v24 = qvalue(elt(env, 9)); /* orig!* */
    stack[-6] = difference2(v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    v25 = qvalue(elt(env, 2)); /* ymin!* */
    v24 = qvalue(elt(env, 3)); /* ymax!* */
    v24 = cons(v25, v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    v24 = acons(stack[-7], stack[-6], v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    goto v31;

v27:
    v24 = elt(env, 12); /* "(" */
    fn = elt(env, 16); /* prin2!* */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v28;
    env = stack[-10];
    goto v26;
/* error exit handlers */
v28:
    env = stack[-10];
    qvalue(elt(env, 7)) = stack[0]; /* overflowed!* */
    qvalue(elt(env, 6)) = stack[-1]; /* testing!-width!* */
    qvalue(elt(env, 5)) = stack[-2]; /* pline!* */
    qvalue(elt(env, 4)) = stack[-3]; /* posn!* */
    qvalue(elt(env, 3)) = stack[-4]; /* ymax!* */
    qvalue(elt(env, 2)) = stack[-5]; /* ymin!* */
    qvalue(elt(env, 1)) = stack[-9]; /* ycoord!* */
    popv(11);
    return nil;
}



/* Code for repeatsp */

static Lisp_Object CC_repeatsp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for repeatsp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v35 = v0;
/* end of prologue */

v37:
    v34 = v35;
    if (v34 == nil) goto v10;
    v34 = v35;
    v36 = qcar(v34);
    v34 = v35;
    v34 = qcdr(v34);
    v34 = Lmember(nil, v36, v34);
    if (!(v34 == nil)) return onevalue(v34);
    v34 = v35;
    v34 = qcdr(v34);
    v35 = v34;
    goto v37;

v10:
    v34 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v34);
}



/* Code for assert_analyze */

static Lisp_Object MS_CDECL CC_assert_analyze(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v76, v77;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_analyze");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_analyze");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    v76 = (Lisp_Object)1; /* 0 */
    stack[0] = v76;
    v76 = (Lisp_Object)1; /* 0 */
    stack[-4] = v76;
    v76 = (Lisp_Object)1; /* 0 */
    stack[-2] = v76;
    v77 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v76 = elt(env, 2); /* lambda_l9xqtq_1 */
    fn = elt(env, 8); /* sort */
    v76 = (*qfn2(fn))(qenv(fn), v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    qvalue(elt(env, 1)) = v76; /* assertstatistics!* */
    v76 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-3] = v76;
    goto v79;

v79:
    v76 = stack[-3];
    if (v76 == nil) goto v32;
    v76 = stack[-3];
    v76 = qcar(v76);
    stack[-1] = v76;
    v77 = stack[0];
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = plus2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    v77 = stack[-4];
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = plus2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[-4] = v76;
    v77 = stack[-2];
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = plus2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[-2] = v76;
    v76 = stack[-3];
    v76 = qcdr(v76);
    stack[-3] = v76;
    goto v79;

v32:
    v76 = elt(env, 4); /* (function !#calls !#bad! calls !#assertion! violations) 
*/
    stack[-3] = v76;
    stack[-1] = elt(env, 5); /* sum */
    v77 = stack[-4];
    v76 = stack[-2];
    v76 = list2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = list2star(stack[-1], stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[-4] = qvalue(elt(env, 3)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* nil */
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    stack[0] = v76;
    v77 = qvalue(elt(env, 3)); /* nil */
    v76 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v76 = cons(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = list2star(stack[-1], stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Lnreverse(nil, v76);
    env = stack[-5];
    v76 = cons(stack[-2], v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = list2star(stack[-4], stack[-3], v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    qvalue(elt(env, 1)) = v76; /* assertstatistics!* */
    v76 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-2] = v76;
    goto v80;

v80:
    v76 = stack[-2];
    if (v76 == nil) goto v81;
    v76 = stack[-2];
    v76 = qcar(v76);
    stack[-1] = v76;
    v76 = stack[-1];
    if (v76 == nil) goto v82;
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[-1];
    v76 = qcar(v76);
    v76 = Lexplodec(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = Llength(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lexplodec(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Llength(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = plus2(stack[0], v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v83;

v83:
    v77 = (Lisp_Object)369; /* 23 */
    v76 = stack[0];
    v76 = difference2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Lminusp(nil, v76);
    env = stack[-5];
    if (v76 == nil) goto v84;
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lexplodec(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Llength(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v85;

v85:
    v77 = (Lisp_Object)369; /* 23 */
    v76 = stack[0];
    v76 = difference2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Lminusp(nil, v76);
    env = stack[-5];
    if (v76 == nil) goto v86;
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lexplodec(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Llength(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v87;

v87:
    v77 = (Lisp_Object)369; /* 23 */
    v76 = stack[0];
    v76 = difference2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Lminusp(nil, v76);
    env = stack[-5];
    if (v76 == nil) goto v88;
    v76 = stack[-1];
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcdr(v76);
    v76 = qcar(v76);
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    goto v89;

v89:
    v76 = stack[-2];
    v76 = qcdr(v76);
    stack[-2] = v76;
    goto v80;

v88:
    v76 = elt(env, 6); /* " " */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[0];
    v76 = add1(v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v87;

v86:
    v76 = elt(env, 6); /* " " */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[0];
    v76 = add1(v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v85;

v84:
    v76 = elt(env, 6); /* " " */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[0];
    v76 = add1(v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v83;

v82:
    v76 = (Lisp_Object)17; /* 1 */
    stack[0] = v76;
    goto v90;

v90:
    v77 = (Lisp_Object)1153; /* 72 */
    v76 = stack[0];
    v76 = difference2(v77, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = Lminusp(nil, v76);
    env = stack[-5];
    if (v76 == nil) goto v91;
    v76 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    goto v89;

v91:
    v76 = elt(env, 7); /* "-" */
    v76 = Lprinc(nil, v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    v76 = stack[0];
    v76 = add1(v76);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-5];
    stack[0] = v76;
    goto v90;

v81:
    v76 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v76; /* assertstatistics!* */
    v76 = nil;
    { popv(6); return onevalue(v76); }
/* error exit handlers */
v78:
    popv(6);
    return nil;
}



/* Code for lambda_l9xqtq_1 */

static Lisp_Object CC_lambda_l9xqtq_1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v92, v93;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqtq_1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v93 = v1;
    v92 = v0;
/* end of prologue */
    v93 = qcar(v93);
    v92 = qcar(v92);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v93, v92);
    }
}



/* Code for simpplus */

static Lisp_Object CC_simpplus(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpplus");
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
    v21 = stack[0];
    v96 = Llength(nil, v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v21 = (Lisp_Object)33; /* 2 */
    if (!(v96 == v21)) goto v32;
    v21 = stack[0];
    fn = elt(env, 2); /* ckpreci!# */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    goto v32;

v32:
    v96 = qvalue(elt(env, 1)); /* nil */
    v21 = (Lisp_Object)17; /* 1 */
    v21 = cons(v96, v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    stack[-1] = v21;
    goto v7;

v7:
    v21 = stack[0];
    if (v21 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v21 = stack[0];
    v21 = qcar(v21);
    fn = elt(env, 3); /* simp */
    v96 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v21 = stack[-1];
    fn = elt(env, 4); /* addsq */
    v21 = (*qfn2(fn))(qenv(fn), v96, v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    stack[-1] = v21;
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[0] = v21;
    goto v7;
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for mo_compare */

static Lisp_Object CC_mo_compare(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v102, v103, v104;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo_compare");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v102 = stack[-1];
    v103 = qcdr(v102);
    v102 = stack[0];
    v102 = qcdr(v102);
    fn = elt(env, 3); /* mo!=degcomp */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v104 = v102;
    v103 = v104;
    v102 = (Lisp_Object)1; /* 0 */
    if (!(v103 == v102)) { popv(3); return onevalue(v104); }
    v102 = qvalue(elt(env, 1)); /* cali!=basering */
    fn = elt(env, 4); /* ring_tag */
    v103 = (*qfn1(fn))(qenv(fn), v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-2];
    v102 = elt(env, 2); /* revlex */
    if (v103 == v102) goto v26;
    v102 = stack[-1];
    v103 = qcar(v102);
    v102 = stack[0];
    v102 = qcar(v102);
    fn = elt(env, 5); /* mo!=lexcomp */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    goto v36;

v36:
    v104 = v102;
    { popv(3); return onevalue(v104); }

v26:
    v102 = stack[-1];
    v103 = qcar(v102);
    v102 = stack[0];
    v102 = qcar(v102);
    fn = elt(env, 6); /* mo!=revlexcomp */
    v102 = (*qfn2(fn))(qenv(fn), v103, v102);
    nil = C_nil;
    if (exception_pending()) goto v105;
    goto v36;
/* error exit handlers */
v105:
    popv(3);
    return nil;
}



/* Code for pv_sort */

static Lisp_Object CC_pv_sort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v79;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort");
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
    v79 = v0;
/* end of prologue */
    v32 = v79;
    if (v32 == nil) goto v10;
    v32 = v79;
    stack[0] = qcdr(v32);
    v32 = v79;
    v32 = qcar(v32);
    v32 = ncons(v32);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-1];
    {
        Lisp_Object v101 = stack[0];
        popv(2);
        fn = elt(env, 2); /* pv_sort1 */
        return (*qfn2(fn))(qenv(fn), v101, v32);
    }

v10:
    v32 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v32); }
/* error exit handlers */
v27:
    popv(2);
    return nil;
}



/* Code for sc_kern */

static Lisp_Object CC_sc_kern(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sc_kern");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v93 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* g_sc_ve */
    v93 = sub1(v93);
    nil = C_nil;
    if (exception_pending()) goto v106;
    v93 = *(Lisp_Object *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v93/(16/CELL)));
    v93 = qcdr(v93);
    v93 = qcdr(v93);
    v93 = qcar(v93);
    { popv(1); return onevalue(v93); }
/* error exit handlers */
v106:
    popv(1);
    return nil;
}



/* Code for rntimes!: */

static Lisp_Object CC_rntimesT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rntimes:");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v109 = stack[-1];
    v109 = qcdr(v109);
    v110 = qcar(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcar(v109);
    stack[-2] = times2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    v109 = stack[-1];
    v109 = qcdr(v109);
    v110 = qcdr(v109);
    v109 = stack[0];
    v109 = qcdr(v109);
    v109 = qcdr(v109);
    v109 = times2(v110, v109);
    nil = C_nil;
    if (exception_pending()) goto v100;
    env = stack[-3];
    {
        Lisp_Object v72 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v72, v109);
    }
/* error exit handlers */
v100:
    popv(4);
    return nil;
}



/* Code for mod!# */

static Lisp_Object CC_modC(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v110, v112;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mod#");
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
    v110 = v0;
/* end of prologue */
    v112 = v110;
    v110 = qvalue(elt(env, 1)); /* current!-modulus */
    v110 = Cremainder(v112, v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    env = stack[-1];
    stack[0] = v110;
    v112 = stack[0];
    v110 = (Lisp_Object)1; /* 0 */
    v110 = (Lisp_Object)lessp2(v112, v110);
    nil = C_nil;
    if (exception_pending()) goto v113;
    v110 = v110 ? lisp_true : nil;
    env = stack[-1];
    if (v110 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v110 = stack[0];
    v112 = qvalue(elt(env, 1)); /* current!-modulus */
    popv(2);
    return plus2(v110, v112);
/* error exit handlers */
v113:
    popv(2);
    return nil;
}



/* Code for times!-mod!-p */

static Lisp_Object CC_timesKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v131;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for times-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v50 = stack[-2];
    if (v50 == nil) goto v7;
    v50 = stack[-1];
    if (v50 == nil) goto v7;
    v50 = stack[-2];
    if (!consp(v50)) goto v108;
    v50 = stack[-2];
    v50 = qcar(v50);
    if (!consp(v50)) goto v108;
    v50 = stack[-1];
    if (!consp(v50)) goto v112;
    v50 = stack[-1];
    v50 = qcar(v50);
    if (!consp(v50)) goto v112;
    v50 = stack[-2];
    v50 = qcar(v50);
    v50 = qcar(v50);
    v131 = qcar(v50);
    v50 = stack[-1];
    v50 = qcar(v50);
    v50 = qcar(v50);
    v50 = qcar(v50);
    if (equal(v131, v50)) goto v132;
    v50 = stack[-2];
    v50 = qcar(v50);
    v50 = qcar(v50);
    v131 = qcar(v50);
    v50 = stack[-1];
    v50 = qcar(v50);
    v50 = qcar(v50);
    v50 = qcar(v50);
    fn = elt(env, 2); /* ordop */
    v50 = (*qfn2(fn))(qenv(fn), v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    if (v50 == nil) goto v134;
    v50 = stack[-2];
    v50 = qcar(v50);
    stack[-3] = qcar(v50);
    v50 = stack[-2];
    v50 = qcar(v50);
    v131 = qcdr(v50);
    v50 = stack[-1];
    stack[0] = CC_timesKmodKp(env, v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v50 = stack[-2];
    v131 = qcdr(v50);
    v50 = stack[-1];
    v50 = CC_timesKmodKp(env, v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    {
        Lisp_Object v135 = stack[-3];
        Lisp_Object v136 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v135, v136, v50);
    }

v134:
    v50 = stack[-1];
    v50 = qcar(v50);
    stack[-3] = qcar(v50);
    v131 = stack[-2];
    v50 = stack[-1];
    v50 = qcar(v50);
    v50 = qcdr(v50);
    stack[0] = CC_timesKmodKp(env, v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v131 = stack[-2];
    v50 = stack[-1];
    v50 = qcdr(v50);
    v50 = CC_timesKmodKp(env, v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    {
        Lisp_Object v137 = stack[-3];
        Lisp_Object v45 = stack[0];
        popv(5);
        fn = elt(env, 3); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v137, v45, v50);
    }

v132:
    v50 = stack[-2];
    v131 = qcar(v50);
    v50 = stack[-1];
    fn = elt(env, 4); /* times!-term!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v50 = stack[-1];
    v131 = qcar(v50);
    v50 = stack[-2];
    v50 = qcdr(v50);
    fn = elt(env, 4); /* times!-term!-mod!-p */
    v50 = (*qfn2(fn))(qenv(fn), v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    fn = elt(env, 5); /* plus!-mod!-p */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    v50 = stack[-2];
    v131 = qcdr(v50);
    v50 = stack[-1];
    v50 = qcdr(v50);
    v50 = CC_timesKmodKp(env, v131, v50);
    nil = C_nil;
    if (exception_pending()) goto v133;
    env = stack[-4];
    {
        Lisp_Object v138 = stack[0];
        popv(5);
        fn = elt(env, 5); /* plus!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v138, v50);
    }

v112:
    v131 = stack[-2];
    v50 = stack[-1];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v131, v50);
    }

v108:
    v131 = stack[-1];
    v50 = stack[-2];
    {
        popv(5);
        fn = elt(env, 6); /* multiply!-by!-constant!-mod!-p */
        return (*qfn2(fn))(qenv(fn), v131, v50);
    }

v7:
    v50 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v50); }
/* error exit handlers */
v133:
    popv(5);
    return nil;
}



/* Code for rl_smmkatl */

static Lisp_Object MS_CDECL CC_rl_smmkatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v67, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "rl_smmkatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_smmkatl");
#endif
    if (stack >= stacklimit)
    {
        push4(v67,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v67);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v34 = v67;
    v35 = v2;
    v36 = v1;
    v107 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_smmkatl!* */
    v34 = list4(v107, v36, v35, v34);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-1];
    {
        Lisp_Object v22 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v22, v34);
    }
/* error exit handlers */
v23:
    popv(2);
    return nil;
}



/* Code for tayexp!-min2 */

static Lisp_Object CC_tayexpKmin2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-min2");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v108 = stack[-1];
    v33 = stack[0];
    fn = elt(env, 1); /* tayexp!-lessp */
    v33 = (*qfn2(fn))(qenv(fn), v108, v33);
    nil = C_nil;
    if (exception_pending()) goto v139;
    if (v33 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(2); return onevalue(res); }
/* error exit handlers */
v139:
    popv(2);
    return nil;
}



/* Code for subs2 */

static Lisp_Object CC_subs2(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v142, v143;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs2");
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
    stack[-2] = nil;
    stack[-1] = nil;
    v142 = qvalue(elt(env, 1)); /* subfg!* */
    if (v142 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v142 = qvalue(elt(env, 2)); /* !*sub2 */
    if (!(v142 == nil)) goto v93;
    v142 = qvalue(elt(env, 3)); /* powlis1!* */
    if (!(v142 == nil)) goto v93;

v3:
    v142 = qvalue(elt(env, 4)); /* !*combineexpt */
    if (v142 == nil) goto v27;
    v142 = stack[-3];
    v142 = qcar(v142);
    fn = elt(env, 11); /* exptchk */
    stack[0] = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    v142 = stack[-3];
    v142 = qcdr(v142);
    fn = elt(env, 11); /* exptchk */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    fn = elt(env, 12); /* invsq */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    fn = elt(env, 13); /* multsq */
    v142 = (*qfn2(fn))(qenv(fn), stack[0], v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    goto v139;

v139:
    stack[-3] = v142;
    v143 = elt(env, 5); /* slash */
    v142 = elt(env, 6); /* opmtch */
    v142 = get(v143, v142);
    env = stack[-5];
    stack[0] = v142;
    v142 = qvalue(elt(env, 7)); /* !*match */
    if (!(v142 == nil)) goto v145;
    v142 = stack[0];
    if (v142 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    else goto v145;

v145:
    v142 = stack[-3];
    v142 = qcar(v142);
    if (v142 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v142 = qvalue(elt(env, 8)); /* !*exp */
    if (!(v142 == nil)) goto v129;
    v142 = qvalue(elt(env, 9)); /* t */
    stack[-4] = v142;
    v142 = qvalue(elt(env, 9)); /* t */
    qvalue(elt(env, 8)) = v142; /* !*exp */
    v142 = stack[-3];
    stack[-2] = v142;
    v142 = stack[-3];
    fn = elt(env, 14); /* resimp */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-3] = v142;
    stack[-1] = v142;
    goto v129;

v129:
    v142 = stack[-3];
    fn = elt(env, 15); /* subs3q */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-3] = v142;
    v142 = stack[-4];
    if (v142 == nil) goto v146;
    v142 = qvalue(elt(env, 10)); /* nil */
    qvalue(elt(env, 8)) = v142; /* !*exp */
    v143 = stack[-3];
    v142 = stack[-1];
    if (!(equal(v143, v142))) goto v146;
    v142 = stack[-2];
    stack[-3] = v142;
    goto v146;

v146:
    v142 = stack[0];
    if (v142 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v142 = stack[-3];
    fn = elt(env, 16); /* subs4q */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    stack[-3] = v142;
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

v27:
    v142 = stack[-3];
    goto v139;

v93:
    v142 = stack[-3];
    fn = elt(env, 17); /* subs2q */
    v142 = (*qfn1(fn))(qenv(fn), v142);
    nil = C_nil;
    if (exception_pending()) goto v144;
    env = stack[-5];
    stack[-3] = v142;
    goto v3;
/* error exit handlers */
v144:
    popv(6);
    return nil;
}



/* Code for sqchk */

static Lisp_Object CC_sqchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v68, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqchk");
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
    v68 = v0;
/* end of prologue */
    v147 = v68;
    if (!consp(v147)) { popv(1); return onevalue(v68); }
    v147 = v68;
    v148 = qcar(v147);
    v147 = elt(env, 1); /* prepfn2 */
    v147 = get(v148, v147);
    env = stack[0];
    v148 = v147;
    v147 = v148;
    if (v147 == nil) goto v139;
    v147 = v148;
        popv(1);
        return Lapply1(nil, v147, v68);

v139:
    v147 = v68;
    v147 = qcar(v147);
    if (!consp(v147)) { popv(1); return onevalue(v68); }
    v147 = qvalue(elt(env, 2)); /* nil */
    fn = elt(env, 3); /* prepf1 */
    v147 = (*qfn2(fn))(qenv(fn), v68, v147);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    v68 = v147;
    v147 = v68;
    if (v147 == nil) goto v149;
    v147 = v68;
    {
        popv(1);
        fn = elt(env, 4); /* replus */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v149:
    v147 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(v147); }
/* error exit handlers */
v102:
    popv(1);
    return nil;
}



/* Code for cl_simplat */

static Lisp_Object CC_cl_simplat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v109, v110, v112;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_simplat");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v110 = v1;
    v112 = v0;
/* end of prologue */
    v109 = qvalue(elt(env, 1)); /* !*rlidentify */
    if (v109 == nil) goto v3;
    v109 = v112;
    fn = elt(env, 3); /* rl_simplat1 */
    v110 = (*qfn2(fn))(qenv(fn), v109, v110);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[0];
    v109 = elt(env, 2); /* cl_identifyat */
    {
        popv(1);
        fn = elt(env, 4); /* cl_apply2ats */
        return (*qfn2(fn))(qenv(fn), v110, v109);
    }

v3:
    v109 = v112;
    {
        popv(1);
        fn = elt(env, 3); /* rl_simplat1 */
        return (*qfn2(fn))(qenv(fn), v109, v110);
    }
/* error exit handlers */
v99:
    popv(1);
    return nil;
}



/* Code for ibalp_cequal */

static Lisp_Object CC_ibalp_cequal(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v162, v163;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_cequal");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v1;
    stack[-5] = v0;
/* end of prologue */
    v162 = stack[-5];
    v162 = qcar(v162);
    stack[-3] = v162;
    v162 = stack[-3];
    if (v162 == nil) goto v33;
    v162 = stack[-3];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-1] = v162;
    stack[-2] = v162;
    goto v93;

v93:
    v162 = stack[-3];
    v162 = qcdr(v162);
    stack[-3] = v162;
    v162 = stack[-3];
    if (v162 == nil) goto v109;
    stack[0] = stack[-1];
    v162 = stack[-3];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = Lrplacd(nil, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = stack[-1];
    v162 = qcdr(v162);
    stack[-1] = v162;
    goto v93;

v109:
    v162 = stack[-2];
    goto v92;

v92:
    stack[-6] = v162;
    v162 = stack[-4];
    v162 = qcar(v162);
    stack[-3] = v162;
    v162 = stack[-3];
    if (v162 == nil) goto v102;
    v162 = stack[-3];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-1] = v162;
    stack[-2] = v162;
    goto v19;

v19:
    v162 = stack[-3];
    v162 = qcdr(v162);
    stack[-3] = v162;
    v162 = stack[-3];
    if (v162 == nil) goto v13;
    stack[0] = stack[-1];
    v162 = stack[-3];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = Lrplacd(nil, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = stack[-1];
    v162 = qcdr(v162);
    stack[-1] = v162;
    goto v19;

v13:
    v162 = stack[-2];
    goto v142;

v142:
    v163 = stack[-6];
    fn = elt(env, 2); /* lto_setequalq */
    v162 = (*qfn2(fn))(qenv(fn), v163, v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    if (v162 == nil) goto v55;
    v162 = stack[-5];
    v162 = qcdr(v162);
    v162 = qcar(v162);
    stack[-3] = v162;
    v162 = stack[-3];
    if (v162 == nil) goto v165;
    v162 = stack[-3];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-1] = v162;
    stack[-2] = v162;
    goto v61;

v61:
    v162 = stack[-3];
    v162 = qcdr(v162);
    stack[-3] = v162;
    v162 = stack[-3];
    if (v162 == nil) goto v124;
    stack[0] = stack[-1];
    v162 = stack[-3];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = Lrplacd(nil, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = stack[-1];
    v162 = qcdr(v162);
    stack[-1] = v162;
    goto v61;

v124:
    v162 = stack[-2];
    goto v166;

v166:
    stack[-3] = v162;
    v162 = stack[-4];
    v162 = qcdr(v162);
    v162 = qcar(v162);
    stack[-4] = v162;
    v162 = stack[-4];
    if (v162 == nil) goto v118;
    v162 = stack[-4];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    stack[-1] = v162;
    stack[-2] = v162;
    goto v115;

v115:
    v162 = stack[-4];
    v162 = qcdr(v162);
    stack[-4] = v162;
    v162 = stack[-4];
    if (v162 == nil) goto v131;
    stack[0] = stack[-1];
    v162 = stack[-4];
    v162 = qcar(v162);
    v162 = qcar(v162);
    v162 = ncons(v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = Lrplacd(nil, stack[0], v162);
    nil = C_nil;
    if (exception_pending()) goto v164;
    env = stack[-7];
    v162 = stack[-1];
    v162 = qcdr(v162);
    stack[-1] = v162;
    goto v115;

v131:
    v162 = stack[-2];
    goto v86;

v86:
    v163 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); /* lto_setequalq */
        return (*qfn2(fn))(qenv(fn), v163, v162);
    }

v118:
    v162 = qvalue(elt(env, 1)); /* nil */
    goto v86;

v165:
    v162 = qvalue(elt(env, 1)); /* nil */
    goto v166;

v55:
    v162 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v162); }

v102:
    v162 = qvalue(elt(env, 1)); /* nil */
    goto v142;

v33:
    v162 = qvalue(elt(env, 1)); /* nil */
    goto v92;
/* error exit handlers */
v164:
    popv(8);
    return nil;
}



/* Code for ratpoly_idl */

static Lisp_Object CC_ratpoly_idl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_idl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v7 = qcar(v7);
    {
        fn = elt(env, 1); /* sf_idl */
        return (*qfn1(fn))(qenv(fn), v7);
    }
}



/* Code for list2string */

static Lisp_Object CC_list2string(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list2string");
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
    v95 = stack[0];
    if (v95 == nil) goto v7;
    v95 = stack[0];
    v95 = qcar(v95);
    v95 = Lprinc(nil, v95);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-1];
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = CC_list2string(env, v95);
    nil = C_nil;
    if (exception_pending()) goto v74;
    goto v7;

v7:
    v95 = nil;
    { popv(2); return onevalue(v95); }
/* error exit handlers */
v74:
    popv(2);
    return nil;
}



/* Code for isarb_int */

static Lisp_Object CC_isarb_int(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v111, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for isarb_int");
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
    v111 = v0;
/* end of prologue */
    v107 = v111;
    v107 = Lconsp(nil, v107);
    env = stack[0];
    if (v107 == nil) goto v7;
    v107 = v111;
    v23 = qcar(v107);
    v107 = elt(env, 1); /* arbint */
    if (v23 == v107) goto v31;
    v107 = v111;
    v107 = qcdr(v107);
    fn = elt(env, 4); /* multi_isarb_int */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v22;
    goto v7;

v7:
    v107 = nil;
    { popv(1); return onevalue(v107); }

v31:
    v107 = (Lisp_Object)17; /* 1 */
    qvalue(elt(env, 2)) = v107; /* found_int */
    goto v7;
/* error exit handlers */
v22:
    popv(1);
    return nil;
}



/* Code for evlexcomp */

static Lisp_Object CC_evlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evlexcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v7:
    v96 = stack[-1];
    if (v96 == nil) goto v6;
    v96 = stack[0];
    if (v96 == nil) goto v31;
    v96 = stack[-1];
    v29 = qcar(v96);
    v96 = stack[0];
    v96 = qcar(v96);
    v96 = Leqn(nil, v29, v96);
    nil = C_nil;
    if (exception_pending()) goto v149;
    env = stack[-2];
    if (v96 == nil) goto v110;
    v96 = stack[-1];
    v96 = qcdr(v96);
    stack[-1] = v96;
    v96 = stack[0];
    v96 = qcdr(v96);
    stack[0] = v96;
    goto v7;

v110:
    v96 = stack[-1];
    v29 = qcar(v96);
    v96 = stack[0];
    v96 = qcar(v96);
    if (((int32_t)(v29)) > ((int32_t)(v96))) goto v22;
    v96 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v96); }

v22:
    v96 = (Lisp_Object)17; /* 1 */
    { popv(3); return onevalue(v96); }

v31:
    v96 = elt(env, 1); /* (0) */
    stack[0] = v96;
    goto v7;

v6:
    v96 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v96); }
/* error exit handlers */
v149:
    popv(3);
    return nil;
}



/* Code for make!-set */

static Lisp_Object CC_makeKset(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v74, v75;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-set");
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
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v74 = v0;
/* end of prologue */
    stack[0] = elt(env, 1); /* list */
    v75 = v74;
    v74 = elt(env, 2); /* set!-ordp */
    fn = elt(env, 3); /* sort */
    v74 = (*qfn2(fn))(qenv(fn), v75, v74);
    nil = C_nil;
    if (exception_pending()) goto v108;
    {
        Lisp_Object v32 = stack[0];
        popv(1);
        return cons(v32, v74);
    }
/* error exit handlers */
v108:
    popv(1);
    return nil;
}



/* Code for convchk */

static Lisp_Object CC_convchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v68, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convchk");
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
    v147 = v0;
/* end of prologue */
    v68 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v68 == nil) goto v7;
    v68 = v147;
    if (!(!consp(v68))) { popv(1); return onevalue(v147); }
    v68 = v147;
    v68 = Lfloatp(nil, v68);
    env = stack[0];
    if (v68 == nil) goto v108;
    {
        popv(1);
        fn = elt(env, 3); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v108:
    v68 = v147;
    if (!(!consp(v68))) goto v27;
    v68 = v147;
    v68 = integerp(v68);
    if (v68 == nil) goto v161;
    v148 = elt(env, 2); /* !:rd!: */
    v68 = v147;
    v147 = (Lisp_Object)1; /* 0 */
    v147 = list2star(v148, v68, v147);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    goto v27;

v27:
    {
        popv(1);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v147);
    }

v161:
    fn = elt(env, 5); /* read!:num */
    v147 = (*qfn1(fn))(qenv(fn), v147);
    nil = C_nil;
    if (exception_pending()) goto v102;
    env = stack[0];
    goto v27;

v7:
    v68 = v147;
    if (!consp(v68)) { popv(1); return onevalue(v147); }
    {
        popv(1);
        fn = elt(env, 6); /* bf2flck */
        return (*qfn1(fn))(qenv(fn), v147);
    }
/* error exit handlers */
v102:
    popv(1);
    return nil;
}



/* Code for maxdeg */

static Lisp_Object CC_maxdeg(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v112, v99;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maxdeg");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v8:
    v112 = stack[-1];
    if (v112 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v112 = stack[-1];
    v112 = qcar(v112);
    v99 = qcdr(v112);
    v112 = stack[0];
    v112 = qcdr(v112);
    v112 = (Lisp_Object)greaterp2(v99, v112);
    nil = C_nil;
    if (exception_pending()) goto v72;
    v112 = v112 ? lisp_true : nil;
    env = stack[-2];
    if (v112 == nil) goto v23;
    v112 = stack[-1];
    v112 = qcdr(v112);
    v99 = v112;
    v112 = stack[-1];
    v112 = qcar(v112);
    stack[0] = v112;
    v112 = v99;
    stack[-1] = v112;
    goto v8;

v23:
    v112 = stack[-1];
    v112 = qcdr(v112);
    stack[-1] = v112;
    goto v8;
/* error exit handlers */
v72:
    popv(3);
    return nil;
}



/* Code for idlistp */

static Lisp_Object CC_idlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v139, v27;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for idlistp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v139 = v0;
/* end of prologue */

v37:
    v27 = v139;
    v27 = (v27 == nil ? lisp_true : nil);
    if (!(v27 == nil)) return onevalue(v27);
    v27 = v139;
    if (!consp(v27)) goto v3;
    v27 = v139;
    v27 = qcar(v27);
    if (symbolp(v27)) goto v75;
    v139 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v139);

v75:
    v139 = qcdr(v139);
    goto v37;

v3:
    v139 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v139);
}



/* Code for eolcheck */

static Lisp_Object MS_CDECL CC_eolcheck(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v100, v72;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "eolcheck");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for eolcheck");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v100 = qvalue(elt(env, 1)); /* !*eoldelimp */
    if (!(v100 == nil)) goto v106;
    v100 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v100); }

v106:
    v72 = qvalue(elt(env, 3)); /* nxtsym!* */
    v100 = qvalue(elt(env, 4)); /* !$eol!$ */
    if (v72 == v100) goto v35;
    v100 = nil;
    { popv(1); return onevalue(v100); }

v35:
    v72 = qvalue(elt(env, 5)); /* cursym!* */
    v100 = elt(env, 6); /* end */
    if (v72 == v100) goto v101;
    fn = elt(env, 8); /* token1 */
    v100 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[0];
    goto v27;

v27:
    qvalue(elt(env, 3)) = v100; /* nxtsym!* */
    goto v106;

v101:
    v100 = elt(env, 7); /* !; */
    goto v27;
/* error exit handlers */
v26:
    popv(1);
    return nil;
}



/* Code for reval2 */

static Lisp_Object CC_reval2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval2");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v21 = v0;
/* end of prologue */
    v20 = stack[0];
    if (!(v20 == nil)) goto v7;
    v20 = qvalue(elt(env, 1)); /* !*combineexpt */
    if (v20 == nil) goto v7;
    v20 = qvalue(elt(env, 2)); /* dmode!* */
    if (!(v20 == nil)) goto v7;
    v20 = qvalue(elt(env, 3)); /* nil */
    stack[-1] = qvalue(elt(env, 4)); /* !*mcd */
    qvalue(elt(env, 4)) = v20; /* !*mcd */
    v20 = v21;
    fn = elt(env, 5); /* simp!* */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v70;
    env = stack[-2];
    qvalue(elt(env, 4)) = stack[-1]; /* !*mcd */
    v21 = v20;
    v20 = stack[0];
    if (v20 == nil) goto v99;
    v20 = v21;
    {
        popv(3);
        fn = elt(env, 6); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v20);
    }

v99:
    v20 = v21;
    {
        popv(3);
        fn = elt(env, 7); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v20);
    }

v7:
    v20 = v21;
    fn = elt(env, 5); /* simp!* */
    v20 = (*qfn1(fn))(qenv(fn), v20);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    v21 = v20;
    v20 = stack[0];
    if (v20 == nil) goto v75;
    v20 = v21;
    {
        popv(3);
        fn = elt(env, 6); /* prepsqxx */
        return (*qfn1(fn))(qenv(fn), v20);
    }

v75:
    v20 = v21;
    {
        popv(3);
        fn = elt(env, 7); /* mk!*sq */
        return (*qfn1(fn))(qenv(fn), v20);
    }
/* error exit handlers */
v97:
    popv(3);
    return nil;
v70:
    env = stack[-2];
    qvalue(elt(env, 4)) = stack[-1]; /* !*mcd */
    popv(3);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v161, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp=ecart");
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
    goto v8;

v8:
    v161 = stack[0];
    if (v161 == nil) goto v5;
    v161 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v161 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v20 = (*qfn1(fn))(qenv(fn), v161);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    v161 = stack[-1];
    v161 = cons(v20, v161);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    stack[-1] = v161;
    v161 = stack[0];
    v161 = qcdr(v161);
    stack[0] = v161;
    goto v8;

v5:
    v161 = (Lisp_Object)1; /* 0 */
    v20 = v161;
    goto v6;

v6:
    v161 = stack[-1];
    if (v161 == nil) { popv(3); return onevalue(v20); }
    v161 = stack[-1];
    v161 = qcar(v161);
    v161 = Lmax2(nil, v161, v20);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-2];
    v20 = v161;
    v161 = stack[-1];
    v161 = qcdr(v161);
    stack[-1] = v161;
    goto v6;
/* error exit handlers */
v29:
    popv(3);
    return nil;
}



/* Code for pv_add */

static Lisp_Object CC_pv_add(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123, v156, v48;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_add");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    v123 = stack[-1];
    if (v123 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v123 = stack[0];
    if (v123 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    stack[-2] = nil;
    goto v32;

v32:
    v123 = stack[-1];
    if (!(v123 == nil)) goto v139;
    v123 = stack[0];
    if (!(v123 == nil)) goto v139;
    v123 = stack[-2];
        popv(4);
        return Lnreverse(nil, v123);

v139:
    v123 = stack[-1];
    if (v123 == nil) goto v110;
    v123 = stack[0];
    if (v123 == nil) goto v110;
    v123 = stack[-1];
    v123 = qcar(v123);
    v156 = qcdr(v123);
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = qcdr(v123);
    if (!(equal(v156, v123))) goto v110;
    v123 = stack[-1];
    v123 = qcar(v123);
    v156 = qcar(v123);
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = qcar(v123);
    v123 = plus2(v156, v123);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    v48 = v123;
    v156 = v48;
    v123 = (Lisp_Object)1; /* 0 */
    if (v156 == v123) goto v104;
    v123 = stack[-1];
    v123 = qcar(v123);
    v156 = qcdr(v123);
    v123 = stack[-2];
    v123 = acons(v48, v156, v123);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    stack[-2] = v123;
    goto v104;

v104:
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v32;

v110:
    v123 = stack[-1];
    if (v123 == nil) goto v25;
    v123 = stack[0];
    if (!(v123 == nil)) goto v25;

v173:
    v123 = stack[-1];
    v156 = qcar(v123);
    v123 = stack[-2];
    v123 = cons(v156, v123);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    stack[-2] = v123;
    v123 = stack[-1];
    v123 = qcdr(v123);
    stack[-1] = v123;
    goto v32;

v25:
    v123 = stack[-1];
    if (v123 == nil) goto v174;
    v123 = stack[0];
    if (v123 == nil) goto v174;
    v123 = stack[-1];
    v123 = qcar(v123);
    v156 = qcdr(v123);
    v123 = stack[0];
    v123 = qcar(v123);
    v123 = qcdr(v123);
    v123 = (Lisp_Object)greaterp2(v156, v123);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v123 = v123 ? lisp_true : nil;
    env = stack[-3];
    if (!(v123 == nil)) goto v173;

v174:
    v123 = stack[0];
    v156 = qcar(v123);
    v123 = stack[-2];
    v123 = cons(v156, v123);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-3];
    stack[-2] = v123;
    v123 = stack[0];
    v123 = qcdr(v123);
    stack[0] = v123;
    goto v32;
/* error exit handlers */
v172:
    popv(4);
    return nil;
}



/* Code for modplus!: */

static Lisp_Object CC_modplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for modplus:");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v93 = v1;
    v95 = v0;
/* end of prologue */
    v95 = qcdr(v95);
    v93 = qcdr(v93);
    fn = elt(env, 1); /* general!-modular!-plus */
    v93 = (*qfn2(fn))(qenv(fn), v95, v93);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* !*modular2f */
        return (*qfn1(fn))(qenv(fn), v93);
    }
/* error exit handlers */
v106:
    popv(1);
    return nil;
}



/* Code for gen!-mult!-by!-const!-mod!-p */

static Lisp_Object CC_genKmultKbyKconstKmodKp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v11, v64;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gen-mult-by-const-mod-p");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v11 = stack[-2];
    if (v11 == nil) goto v7;
    v64 = stack[-1];
    v11 = (Lisp_Object)17; /* 1 */
    if (v64 == v11) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v11 = stack[-2];
    if (!consp(v11)) goto v35;
    v11 = stack[-2];
    v11 = qcar(v11);
    if (!consp(v11)) goto v35;
    v11 = stack[-2];
    v11 = qcar(v11);
    stack[-3] = qcar(v11);
    v11 = stack[-2];
    v11 = qcar(v11);
    v64 = qcdr(v11);
    v11 = stack[-1];
    stack[0] = CC_genKmultKbyKconstKmodKp(env, v64, v11);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    v11 = stack[-2];
    v64 = qcdr(v11);
    v11 = stack[-1];
    v11 = CC_genKmultKbyKconstKmodKp(env, v64, v11);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    {
        Lisp_Object v17 = stack[-3];
        Lisp_Object v12 = stack[0];
        popv(5);
        fn = elt(env, 2); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v17, v12, v11);
    }

v35:
    v64 = stack[-2];
    v11 = stack[-1];
    fn = elt(env, 3); /* general!-modular!-times */
    v11 = (*qfn2(fn))(qenv(fn), v64, v11);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-4];
    v64 = v11;
    v11 = v64;
    v11 = (Lisp_Object)zerop(v11);
    v11 = v11 ? lisp_true : nil;
    env = stack[-4];
    if (v11 == nil) { popv(5); return onevalue(v64); }
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v11); }

v7:
    v11 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v11); }
/* error exit handlers */
v16:
    popv(5);
    return nil;
}



/* Code for subs3q */

static Lisp_Object CC_subs3q(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v130, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3q");
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
    stack[-1] = v0;
/* end of prologue */
    v26 = qvalue(elt(env, 1)); /* mchfg!* */
    stack[-2] = v26;
    v26 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 1)) = v26; /* mchfg!* */
    v26 = stack[-1];
    v73 = qcar(v26);
    v130 = qvalue(elt(env, 3)); /* !*match */
    v26 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 5); /* subs3f1 */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v73, v130, v26);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    v26 = stack[-1];
    v73 = qcdr(v26);
    v130 = qvalue(elt(env, 3)); /* !*match */
    v26 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 5); /* subs3f1 */
    v26 = (*qfnn(fn))(qenv(fn), 3, v73, v130, v26);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    fn = elt(env, 6); /* invsq */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    fn = elt(env, 7); /* multsq */
    v26 = (*qfn2(fn))(qenv(fn), stack[0], v26);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-3];
    stack[-1] = v26;
    v26 = stack[-2];
    qvalue(elt(env, 1)) = v26; /* mchfg!* */
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
v21:
    popv(4);
    return nil;
}



/* Code for tayexp!-difference */

static Lisp_Object CC_tayexpKdifference(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v54, v55;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-difference");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v56 = v0;
/* end of prologue */
    v54 = v56;
    if (!(!consp(v54))) goto v33;
    v54 = stack[0];
    if (!(!consp(v54))) goto v33;
    v54 = v56;
    v56 = stack[0];
    popv(3);
    return difference2(v54, v56);

v33:
    v54 = v56;
    if (!consp(v54)) goto v109;
    v54 = stack[0];
    if (!consp(v54)) goto v29;
    v54 = v56;
    v56 = stack[0];
    fn = elt(env, 2); /* rndifference!: */
    v56 = (*qfn2(fn))(qenv(fn), v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v142;
    goto v79;

v79:
    v55 = v56;
    v56 = v55;
    v56 = qcdr(v56);
    v54 = qcdr(v56);
    v56 = (Lisp_Object)17; /* 1 */
    if (!(v54 == v56)) { popv(3); return onevalue(v55); }
    v56 = v55;
    v56 = qcdr(v56);
    v56 = qcar(v56);
    { popv(3); return onevalue(v56); }

v29:
    stack[-1] = v56;
    v55 = elt(env, 1); /* !:rn!: */
    v54 = stack[0];
    v56 = (Lisp_Object)17; /* 1 */
    v56 = list2star(v55, v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-2];
    fn = elt(env, 2); /* rndifference!: */
    v56 = (*qfn2(fn))(qenv(fn), stack[-1], v56);
    nil = C_nil;
    if (exception_pending()) goto v142;
    goto v79;

v109:
    v55 = elt(env, 1); /* !:rn!: */
    v54 = v56;
    v56 = (Lisp_Object)17; /* 1 */
    v54 = list2star(v55, v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v142;
    env = stack[-2];
    v56 = stack[0];
    fn = elt(env, 2); /* rndifference!: */
    v56 = (*qfn2(fn))(qenv(fn), v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v142;
    goto v79;
/* error exit handlers */
v142:
    popv(3);
    return nil;
}



/* Code for get!+col!+nr */

static Lisp_Object CC_getLcolLnr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v5;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get+col+nr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v5 = v0;
/* end of prologue */
    v5 = qcar(v5);
        return Llength(nil, v5);
}



/* Code for rl_varlat */

static Lisp_Object CC_rl_varlat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_varlat");
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
    v9 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_varlat!* */
    v9 = ncons(v9);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-1];
    {
        Lisp_Object v93 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v93, v9);
    }
/* error exit handlers */
v92:
    popv(2);
    return nil;
}



/* Code for find */

static Lisp_Object CC_find(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v20, v21, v96, v29;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v1;
    v96 = v0;
/* end of prologue */

v3:
    v29 = v21;
    v20 = nil;
    if (v29 == v20) goto v5;
    v20 = v21;
    v20 = qcar(v20);
    v96 = Lmember(nil, v20, v96);
    v20 = v21;
    v20 = qcdr(v20);
    v21 = v20;
    goto v3;

v5:
    v20 = v96;
    if (v20 == nil) goto v139;
    v20 = v96;
    v20 = qcdr(v20);
    return onevalue(v20);

v139:
    v20 = elt(env, 1); /* (stop) */
    return onevalue(v20);
}



/* Code for ps!:get!-term */

static Lisp_Object CC_psTgetKterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v120, v81, v80;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:get-term");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */
    v120 = stack[-2];
    fn = elt(env, 4); /* ps!:order */
    stack[0] = (*qfn1(fn))(qenv(fn), v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v120 = stack[-2];
    fn = elt(env, 5); /* ps!:last!-term */
    v120 = (*qfn1(fn))(qenv(fn), v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v120;
    v81 = stack[-1];
    v120 = stack[-3];
    v120 = (Lisp_Object)lessp2(v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    v120 = v120 ? lisp_true : nil;
    env = stack[-4];
    if (v120 == nil) goto v22;
    v81 = qvalue(elt(env, 1)); /* nil */
    v120 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v81, v120);

v22:
    v81 = stack[-1];
    v120 = stack[0];
    v120 = (Lisp_Object)greaterp2(v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    v120 = v120 ? lisp_true : nil;
    env = stack[-4];
    if (v120 == nil) goto v149;
    v120 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v120); }

v149:
    v81 = stack[-1];
    v120 = stack[-3];
    stack[0] = difference2(v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v120 = stack[-2];
    if (!consp(v120)) goto v66;
    v120 = stack[-2];
    v81 = qcar(v120);
    v120 = elt(env, 2); /* !:ps!: */
    if (v81 == v120) goto v178;
    v120 = stack[-2];
    v81 = qcar(v120);
    v120 = elt(env, 3); /* dname */
    v120 = get(v81, v120);
    env = stack[-4];
    if (!(v120 == nil)) goto v66;

v178:
    v81 = stack[-2];
    v120 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 6); /* ps!:getv */
    v120 = (*qfn2(fn))(qenv(fn), v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    goto v29;

v29:
    v120 = Lassoc(nil, stack[0], v120);
    v81 = v120;
    v120 = v81;
    if (v120 == nil) goto v179;
    v120 = v81;
    v120 = qcdr(v120);
    { popv(5); return onevalue(v120); }

v179:
    v81 = qvalue(elt(env, 1)); /* nil */
    v120 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v81, v120);

v66:
    v80 = (Lisp_Object)1; /* 0 */
    v81 = stack[-2];
    v120 = (Lisp_Object)17; /* 1 */
    v120 = list2star(v80, v81, v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    v120 = ncons(v120);
    nil = C_nil;
    if (exception_pending()) goto v174;
    env = stack[-4];
    goto v29;
/* error exit handlers */
v174:
    popv(5);
    return nil;
}



/* Code for sortcolelem */

static Lisp_Object MS_CDECL CC_sortcolelem(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v54;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sortcolelem");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sortcolelem");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */
    stack[0] = nil;
    v56 = stack[-2];
    v56 = qcdr(v56);
    stack[-4] = v56;
    goto v31;

v31:
    v56 = stack[0];
    if (v56 == nil) goto v93;
    v56 = nil;
    { popv(6); return onevalue(v56); }

v93:
    v56 = stack[-4];
    if (v56 == nil) goto v101;
    v54 = stack[-3];
    v56 = stack[-4];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = (Lisp_Object)lessp2(v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v56 = v56 ? lisp_true : nil;
    env = stack[-5];
    if (v56 == nil) goto v181;
    stack[0] = stack[-2];
    v54 = stack[-3];
    v56 = stack[-1];
    v56 = cons(v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v54 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v56 = stack[-4];
    v56 = Lrplacd(nil, v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v56 = Lrplacd(nil, stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v56 = qvalue(elt(env, 2)); /* t */
    stack[0] = v56;
    goto v31;

v181:
    v54 = stack[-3];
    v56 = stack[-4];
    v56 = qcar(v56);
    v56 = qcar(v56);
    v56 = (Lisp_Object)greaterp2(v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    v56 = v56 ? lisp_true : nil;
    env = stack[-5];
    if (v56 == nil) goto v31;
    v56 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v56;
    v56 = stack[-2];
    v56 = qcdr(v56);
    stack[-2] = v56;
    v56 = stack[-2];
    v56 = qcdr(v56);
    stack[-4] = v56;
    goto v31;

v101:
    stack[0] = stack[-2];
    v54 = stack[-3];
    v56 = stack[-1];
    v56 = cons(v54, v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v56 = ncons(v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v56 = Lrplacd(nil, stack[0], v56);
    nil = C_nil;
    if (exception_pending()) goto v180;
    env = stack[-5];
    v56 = qvalue(elt(env, 2)); /* t */
    stack[0] = v56;
    goto v31;
/* error exit handlers */
v180:
    popv(6);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v23, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groebsearchinlist");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v7:
    v23 = stack[0];
    if (v23 == nil) goto v6;
    v23 = stack[0];
    v23 = qcar(v23);
    v23 = qcdr(v23);
    v22 = qcar(v23);
    v23 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v23 = (*qfn2(fn))(qenv(fn), v22, v23);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    if (v23 == nil) goto v35;
    v23 = stack[0];
    v23 = qcar(v23);
    { popv(3); return onevalue(v23); }

v35:
    v23 = stack[0];
    v23 = qcdr(v23);
    stack[0] = v23;
    goto v7;

v6:
    v23 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v23); }
/* error exit handlers */
v112:
    popv(3);
    return nil;
}



/* Code for find_item */

static Lisp_Object CC_find_item(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v70, v97;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for find_item");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v37:
    v70 = stack[0];
    v70 = qcdr(v70);
    if (v70 == nil) goto v7;
    v97 = stack[-1];
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = qcar(v70);
    v70 = CC_find_item(env, v97, v70);
    nil = C_nil;
    if (exception_pending()) goto v71;
    env = stack[-2];
    if (!(v70 == nil)) { popv(3); return onevalue(v70); }
    v70 = stack[0];
    v97 = qcar(v70);
    v70 = stack[-1];
    if (equal(v97, v70)) goto v36;
    v70 = nil;
    goto v35;

v35:
    if (!(v70 == nil)) { popv(3); return onevalue(v70); }
    v97 = stack[-1];
    v70 = stack[0];
    v70 = qcdr(v70);
    v70 = qcdr(v70);
    stack[-1] = v97;
    stack[0] = v70;
    goto v37;

v36:
    v70 = stack[0];
    goto v35;

v7:
    v70 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v70); }
/* error exit handlers */
v71:
    popv(3);
    return nil;
}



/* Code for noncommuting */

static Lisp_Object CC_noncommuting(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommuting");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    v98 = stack[-1];
    if (!consp(v98)) goto v3;
    v98 = stack[-1];
    v98 = qcar(v98);
    goto v6;

v6:
    stack[-1] = v98;
    v98 = stack[0];
    if (!consp(v98)) goto v33;
    v98 = stack[0];
    v98 = qcar(v98);
    goto v75;

v75:
    stack[0] = v98;
    v98 = stack[-1];
    fn = elt(env, 3); /* noncomp2 */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    if (v98 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v98 = stack[0];
    fn = elt(env, 3); /* noncomp2 */
    v98 = (*qfn1(fn))(qenv(fn), v98);
    nil = C_nil;
    if (exception_pending()) goto v103;
    env = stack[-3];
    if (v98 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v147 = stack[-1];
    v98 = elt(env, 2); /* noncommutes */
    v98 = get(v147, v98);
    v147 = stack[0];
    v98 = Lmember(nil, v147, v98);
    stack[-2] = v98;
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }

v33:
    v98 = stack[0];
    goto v75;

v3:
    v98 = stack[-1];
    goto v6;
/* error exit handlers */
v103:
    popv(4);
    return nil;
}



/* Code for form1 */

static Lisp_Object MS_CDECL CC_form1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v266, v267, v268, v269;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "form1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v2;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v37:
    v266 = stack[-3];
    if (!consp(v266)) goto v4;
    v266 = stack[-3];
    v266 = qcar(v266);
    if (!consp(v266)) goto v105;
    v268 = stack[-3];
    v267 = stack[-2];
    v266 = stack[-1];
    {
        popv(6);
        fn = elt(env, 31); /* form2 */
        return (*qfnn(fn))(qenv(fn), 3, v268, v267, v266);
    }

v105:
    v266 = stack[-3];
    v266 = qcar(v266);
    if (symbolp(v266)) goto v54;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 4); /* "operator" */
    fn = elt(env, 32); /* typerr */
    v266 = (*qfn2(fn))(qenv(fn), v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v271;

v271:
    v267 = stack[-1];
    v266 = elt(env, 9); /* symbolic */
    if (v267 == v266) goto v272;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 22); /* opfn */
    v266 = Lflagp(nil, v267, v266);
    env = stack[-5];
    if (!(v266 == nil)) goto v272;

v273:
    v266 = stack[-3];
    v268 = qcdr(v266);
    v267 = stack[-2];
    v266 = stack[-1];
    fn = elt(env, 33); /* formlis */
    v266 = (*qfnn(fn))(qenv(fn), 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    stack[-4] = v266;
    v267 = stack[-4];
    v266 = stack[-3];
    v266 = qcdr(v266);
    if (equal(v267, v266)) goto v274;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = stack[-4];
    v266 = cons(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v275;

v275:
    stack[0] = v266;
    v267 = stack[-1];
    v266 = elt(env, 9); /* symbolic */
    if (v267 == v266) goto v276;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 14); /* stat */
    v266 = get(v267, v266);
    env = stack[-5];
    if (!(v266 == nil)) goto v276;
    v266 = stack[-3];
    v266 = qcdr(v266);
    if (v266 == nil) goto v277;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v267 = qcar(v266);
    v266 = elt(env, 23); /* quote */
    if (!consp(v267)) goto v277;
    v267 = qcar(v267);
    if (!(v267 == v266)) goto v277;
    v266 = qvalue(elt(env, 24)); /* !*micro!-version */
    if (v266 == nil) goto v276;
    v266 = qvalue(elt(env, 25)); /* !*defn */
    if (!(v266 == nil)) goto v276;

v277:
    v267 = stack[0];
    v266 = stack[-2];
    fn = elt(env, 34); /* intexprnp */
    v266 = (*qfn2(fn))(qenv(fn), v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    if (v266 == nil) goto v278;
    v266 = qvalue(elt(env, 26)); /* !*composites */
    if (!(v266 == nil)) goto v278;
    v267 = qvalue(elt(env, 27)); /* current!-modulus */
    v266 = (Lisp_Object)17; /* 1 */
    if (!(v267 == v266)) goto v278;

v276:
    v267 = stack[0];
    v266 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v267, v266);
    }

v278:
    v267 = stack[-1];
    v266 = elt(env, 28); /* algebraic */
    if (v267 == v266) goto v279;
    v268 = stack[0];
    v267 = stack[-2];
    v266 = elt(env, 28); /* algebraic */
    v269 = CC_form1(env, 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v268 = stack[-2];
    v267 = stack[-1];
    v266 = elt(env, 28); /* algebraic */
    {
        popv(6);
        fn = elt(env, 36); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v269, v268, v267, v266);
    }

v279:
    stack[0] = elt(env, 29); /* list */
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = stack[-2];
    v266 = Latsoc(nil, v267, v266);
    if (!(v266 == nil)) goto v280;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 30); /* share */
    v266 = Lflagp(nil, v267, v266);
    env = stack[-5];
    if (!(v266 == nil)) goto v280;
    v266 = stack[-3];
    v266 = qcar(v266);
    v266 = Lmkquote(nil, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    v267 = v266;
    goto v281;

v281:
    v266 = stack[-4];
    {
        Lisp_Object v282 = stack[0];
        popv(6);
        return list2star(v282, v267, v266);
    }

v280:
    v266 = stack[-3];
    v266 = qcar(v266);
    v267 = v266;
    goto v281;

v274:
    v266 = stack[-3];
    goto v275;

v272:
    v266 = stack[-3];
    fn = elt(env, 37); /* argnochk */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v273;

v54:
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 5); /* comment */
    if (v267 == v266) goto v28;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 6); /* noform */
    v266 = Lflagp(nil, v267, v266);
    env = stack[-5];
    if (!(v266 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 7); /* rtype */
    v267 = get(v267, v266);
    env = stack[-5];
    v266 = elt(env, 8); /* array */
    if (!(v267 == v266)) goto v283;
    v267 = stack[-1];
    v266 = elt(env, 9); /* symbolic */
    if (!(v267 == v266)) goto v283;
    stack[0] = elt(env, 10); /* getel */
    v268 = stack[-3];
    v267 = stack[-2];
    v266 = stack[-1];
    fn = elt(env, 38); /* intargfn */
    v266 = (*qfnn(fn))(qenv(fn), 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    {
        Lisp_Object v284 = stack[0];
        popv(6);
        return list2(v284, v266);
    }

v283:
    v266 = stack[-3];
    v266 = qcdr(v266);
    if (v266 == nil) goto v285;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 7); /* rtype */
    v267 = get(v267, v266);
    env = stack[-5];
    v266 = elt(env, 11); /* vector */
    if (v267 == v266) goto v286;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    v266 = Lsimple_vectorp(nil, v266);
    env = stack[-5];
    if (!(v266 == nil)) goto v286;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v267 = qcar(v266);
    v266 = elt(env, 12); /* vecfn */
    v266 = Lflagpcar(nil, v267, v266);
    env = stack[-5];
    if (!(v266 == nil)) goto v286;

v285:
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 2); /* modefn */
    v266 = Lflagp(nil, v267, v266);
    env = stack[-5];
    if (v266 == nil) goto v287;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v268 = qcar(v266);
    v267 = stack[-2];
    v266 = stack[-3];
    v266 = qcar(v266);
    v269 = CC_form1(env, 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v268 = stack[-2];
    v267 = stack[-1];
    v266 = stack[-3];
    v266 = qcar(v266);
    {
        popv(6);
        fn = elt(env, 36); /* convertmode1 */
        return (*qfnn(fn))(qenv(fn), 4, v269, v268, v267, v266);
    }

v287:
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 13); /* formfn */
    v266 = get(v267, v266);
    env = stack[-5];
    stack[-4] = v266;
    if (v266 == nil) goto v288;
    v269 = stack[-4];
    v268 = stack[-3];
    v267 = stack[-2];
    v266 = stack[-1];
    v267 = Lapply3(nil, 4, v269, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v266 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v267, v266);
    }

v288:
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 14); /* stat */
    v267 = get(v267, v266);
    env = stack[-5];
    v266 = elt(env, 15); /* rlis */
    if (v267 == v266) goto v289;
    v266 = stack[-3];
    v267 = qcar(v266);
    v266 = elt(env, 16); /* !*comma!* */
    if (!(v267 == v266)) goto v271;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    if (!consp(v266)) goto v290;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = qcdr(v266);
    v266 = qcar(v266);
    if (!(!consp(v266))) goto v290;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    v267 = qcar(v266);
    v266 = elt(env, 17); /* type */
    v266 = Lflagp(nil, v267, v266);
    env = stack[-5];
    if (v266 == nil) goto v290;
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    v267 = qcar(v266);
    v266 = elt(env, 18); /* "invalid except at head of block" */
    v266 = list2(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v267 = v266;
    v266 = v267;
    qvalue(elt(env, 19)) = v266; /* errmsg!* */
    v266 = qvalue(elt(env, 20)); /* !*protfg */
    if (!(v266 == nil)) goto v291;
    v266 = v267;
    fn = elt(env, 39); /* lprie */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v291;

v291:
    v266 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v271;

v290:
    v267 = elt(env, 21); /* "Syntax error: , invalid after" */
    v266 = stack[-3];
    v266 = qcdr(v266);
    v266 = qcar(v266);
    v266 = list2(v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v267 = v266;
    v266 = v267;
    qvalue(elt(env, 19)) = v266; /* errmsg!* */
    v266 = qvalue(elt(env, 20)); /* !*protfg */
    if (!(v266 == nil)) goto v292;
    v266 = v267;
    fn = elt(env, 39); /* lprie */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v292;

v292:
    v266 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    goto v271;

v289:
    v268 = stack[-3];
    v267 = stack[-2];
    v266 = stack[-1];
    fn = elt(env, 40); /* formrlis */
    v267 = (*qfnn(fn))(qenv(fn), 3, v268, v267, v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v266 = stack[-1];
    {
        popv(6);
        fn = elt(env, 35); /* macrochk */
        return (*qfn2(fn))(qenv(fn), v267, v266);
    }

v286:
    v268 = stack[-3];
    v267 = stack[-2];
    v266 = stack[-1];
    {
        popv(6);
        fn = elt(env, 41); /* getvect */
        return (*qfnn(fn))(qenv(fn), 3, v268, v267, v266);
    }

v28:
    v266 = stack[-3];
    fn = elt(env, 42); /* lastpair */
    v266 = (*qfn1(fn))(qenv(fn), v266);
    nil = C_nil;
    if (exception_pending()) goto v270;
    env = stack[-5];
    v268 = qcar(v266);
    v267 = stack[-2];
    v266 = stack[-1];
    stack[-3] = v268;
    stack[-2] = v267;
    stack[-1] = v266;
    goto v37;

v4:
    v266 = stack[-3];
    if (!(symbolp(v266))) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v267 = stack[-3];
    v266 = elt(env, 1); /* ed */
    if (v267 == v266) goto v33;
    v267 = stack[-3];
    v266 = elt(env, 2); /* modefn */
    v266 = Lflagp(nil, v267, v266);
    env = stack[-5];
    if (v266 == nil) goto v20;
    v266 = stack[-3];
    {
        popv(6);
        fn = elt(env, 43); /* set!-global!-mode */
        return (*qfn1(fn))(qenv(fn), v266);
    }

v20:
    v267 = stack[-1];
    v266 = elt(env, 3); /* idfn */
    v266 = get(v267, v266);
    stack[-4] = v266;
    if (v266 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v268 = stack[-4];
    v267 = stack[-3];
    v266 = stack[-2];
        popv(6);
        return Lapply2(nil, 3, v268, v267, v266);

v33:
    v266 = stack[-3];
    popv(6);
    return ncons(v266);
/* error exit handlers */
v270:
    popv(6);
    return nil;
}



/* Code for mo!=lexcomp */

static Lisp_Object CC_moMlexcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v145, v18, v19;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mo=lexcomp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v145 = v1;
    v18 = v0;
/* end of prologue */

v7:
    v160 = v18;
    if (v160 == nil) goto v6;
    v160 = v145;
    if (v160 == nil) goto v108;
    v160 = v18;
    v19 = qcar(v160);
    v160 = v145;
    v160 = qcar(v160);
    if (equal(v19, v160)) goto v27;
    v160 = v18;
    v160 = qcar(v160);
    v145 = qcar(v145);
    if (((int32_t)(v160)) > ((int32_t)(v145))) goto v72;
    v160 = (Lisp_Object)-15; /* -1 */
    return onevalue(v160);

v72:
    v160 = (Lisp_Object)17; /* 1 */
    return onevalue(v160);

v27:
    v160 = v18;
    v160 = qcdr(v160);
    v18 = v160;
    v160 = v145;
    v160 = qcdr(v160);
    v145 = v160;
    goto v7;

v108:
    v160 = elt(env, 1); /* (0) */
    v145 = v160;
    goto v7;

v6:
    v160 = v145;
    if (v160 == nil) goto v92;
    v160 = elt(env, 1); /* (0) */
    v18 = v160;
    goto v7;

v92:
    v160 = (Lisp_Object)1; /* 0 */
    return onevalue(v160);
}



/* Code for insert_pv */

static Lisp_Object CC_insert_pv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v22, v109, v110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for insert_pv");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v22 = v0;
/* end of prologue */
    v109 = v22;
    v22 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v22 = (*qfn2(fn))(qenv(fn), v109, v22);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    v109 = v22;
    v22 = v109;
    if (v22 == nil) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v22 = v109;
    fn = elt(env, 3); /* pv_renorm */
    v110 = (*qfn1(fn))(qenv(fn), v22);
    nil = C_nil;
    if (exception_pending()) goto v99;
    env = stack[-1];
    v109 = stack[0];
    v22 = qvalue(elt(env, 1)); /* nil */
    {
        popv(2);
        fn = elt(env, 4); /* insert_pv1 */
        return (*qfnn(fn))(qenv(fn), 3, v110, v109, v22);
    }
/* error exit handlers */
v99:
    popv(2);
    return nil;
}



/* Code for gionep!: */

static Lisp_Object CC_gionepT(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v107, v111;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gionep:");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v111 = v0;
/* end of prologue */
    v36 = v111;
    v36 = qcdr(v36);
    v107 = qcar(v36);
    v36 = (Lisp_Object)17; /* 1 */
    if (v107 == v36) goto v75;
    v36 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v36);

v75:
    v36 = v111;
    v36 = qcdr(v36);
    v107 = qcdr(v36);
    v36 = (Lisp_Object)1; /* 0 */
    v36 = (v107 == v36 ? lisp_true : nil);
    return onevalue(v36);
}



/* Code for ibalp_calcmom */

static Lisp_Object CC_ibalp_calcmom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v160;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_calcmom");
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
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v160 = qcar(v71);
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcar(v71);
    v160 = plus2(v160, v71);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v71 = (Lisp_Object)513; /* 32 */
    stack[-1] = times2(v160, v71);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-2];
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v160 = qcar(v71);
    v71 = stack[0];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcar(v71);
    v71 = times2(v160, v71);
    nil = C_nil;
    if (exception_pending()) goto v19;
    {
        Lisp_Object v98 = stack[-1];
        popv(3);
        return plus2(v98, v71);
    }
/* error exit handlers */
v19:
    popv(3);
    return nil;
}



/* Code for quotfd */

static Lisp_Object CC_quotfd(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v98, v147, v68, v148;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for quotfd");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v147 = v1;
    v68 = v0;
/* end of prologue */
    v148 = v68;
    v98 = v147;
    if (equal(v148, v98)) goto v7;
    v148 = qvalue(elt(env, 1)); /* dmode!* */
    v98 = elt(env, 2); /* field */
    v98 = Lflagp(nil, v148, v98);
    env = stack[0];
    if (v98 == nil) goto v106;
    v98 = v68;
    {
        popv(1);
        fn = elt(env, 3); /* divd */
        return (*qfn2(fn))(qenv(fn), v98, v147);
    }

v106:
    v98 = v68;
    if (!consp(v98)) goto v130;
    v98 = v68;
    v98 = qcar(v98);
    if (!consp(v98)) goto v130;
    v98 = v68;
    {
        popv(1);
        fn = elt(env, 4); /* quotk */
        return (*qfn2(fn))(qenv(fn), v98, v147);
    }

v130:
    v98 = v68;
    {
        popv(1);
        fn = elt(env, 5); /* quotdd */
        return (*qfn2(fn))(qenv(fn), v98, v147);
    }

v7:
    v98 = (Lisp_Object)17; /* 1 */
    { popv(1); return onevalue(v98); }
}



/* Code for mkwedge */

static Lisp_Object CC_mkwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v93, v95, v106;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkwedge");
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
    v93 = v0;
/* end of prologue */
    v106 = v93;
    v95 = (Lisp_Object)17; /* 1 */
    v93 = (Lisp_Object)17; /* 1 */
    v93 = list2star(v106, v95, v93);
    errexit();
    return ncons(v93);
}



/* Code for evaluate0 */

static Lisp_Object CC_evaluate0(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v92;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evaluate0");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    v31 = v0;
/* end of prologue */
    fn = elt(env, 1); /* evaluate!-horner */
    v92 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v95;
    env = stack[-1];
    v31 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* evaluate1 */
        return (*qfn2(fn))(qenv(fn), v92, v31);
    }
/* error exit handlers */
v95:
    popv(2);
    return nil;
}



/* Code for optype */

static Lisp_Object CC_optype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v9;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for optype");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v4 = v0;
/* end of prologue */
    v9 = elt(env, 1); /* !*optype!* */
    return get(v4, v9);
}



/* Code for noncommutingf */

static Lisp_Object CC_noncommutingf(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v21, v96;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncommutingf");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v37:
    v21 = stack[0];
    fn = elt(env, 2); /* domain!*p */
    v21 = (*qfn1(fn))(qenv(fn), v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    if (v21 == nil) goto v106;
    v21 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v21); }

v106:
    v96 = stack[-1];
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcar(v21);
    v21 = qcar(v21);
    fn = elt(env, 3); /* noncommuting */
    v21 = (*qfn2(fn))(qenv(fn), v96, v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    if (!(v21 == nil)) { popv(3); return onevalue(v21); }
    v96 = stack[-1];
    v21 = stack[0];
    v21 = qcar(v21);
    v21 = qcdr(v21);
    v21 = CC_noncommutingf(env, v96, v21);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-2];
    if (!(v21 == nil)) { popv(3); return onevalue(v21); }
    v96 = stack[-1];
    v21 = stack[0];
    v21 = qcdr(v21);
    stack[-1] = v96;
    stack[0] = v21;
    goto v37;
/* error exit handlers */
v97:
    popv(3);
    return nil;
}



/* Code for convertmode1 */

static Lisp_Object MS_CDECL CC_convertmode1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v67, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124, v125, v121, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "convertmode1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for convertmode1");
#endif
    if (stack >= stacklimit)
    {
        push4(v67,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v67);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v125 = v67;
    stack[0] = v2;
    stack[-1] = v1;
    v121 = v0;
/* end of prologue */

v31:
    v41 = v125;
    v124 = elt(env, 1); /* real */
    if (!(v41 == v124)) goto v27;
    v124 = elt(env, 2); /* algebraic */
    v125 = v124;
    goto v27;

v27:
    v41 = stack[0];
    v124 = elt(env, 1); /* real */
    if (!(v41 == v124)) goto v99;
    v124 = elt(env, 2); /* algebraic */
    stack[0] = v124;
    goto v99;

v99:
    v41 = stack[0];
    v124 = v125;
    if (v41 == v124) { popv(4); return onevalue(v121); }
    v124 = v121;
    if (!(symbolp(v124))) goto v28;
    v41 = v121;
    v124 = stack[-1];
    v124 = Latsoc(nil, v41, v124);
    stack[-2] = v124;
    if (v124 == nil) goto v28;
    v124 = stack[-2];
    v41 = qcdr(v124);
    v124 = elt(env, 3); /* (integer scalar real) */
    v124 = Lmemq(nil, v41, v124);
    if (!(v124 == nil)) goto v28;
    v124 = stack[-2];
    v41 = qcdr(v124);
    v124 = v125;
    if (v41 == v124) goto v28;
    v125 = stack[-1];
    v124 = stack[-2];
    v124 = qcdr(v124);
    fn = elt(env, 4); /* form1 */
    v121 = (*qfnn(fn))(qenv(fn), 3, v121, v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-3];
    v41 = stack[-1];
    v125 = stack[0];
    v124 = stack[-2];
    v124 = qcdr(v124);
    stack[-1] = v41;
    stack[0] = v125;
    v125 = v124;
    goto v31;

v28:
    v41 = v125;
    v124 = stack[0];
    v124 = get(v41, v124);
    env = stack[-3];
    stack[-2] = v124;
    if (v124 == nil) goto v60;
    v125 = stack[-2];
    v124 = stack[-1];
        popv(4);
        return Lapply2(nil, 3, v125, v121, v124);

v60:
    v124 = stack[0];
    fn = elt(env, 5); /* typerr */
    v124 = (*qfn2(fn))(qenv(fn), v125, v124);
    nil = C_nil;
    if (exception_pending()) goto v295;
    v124 = nil;
    { popv(4); return onevalue(v124); }
/* error exit handlers */
v295:
    popv(4);
    return nil;
}



/* Code for getel1 */

static Lisp_Object MS_CDECL CC_getel1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v64, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "getel1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getel1");
#endif
    if (stack >= stacklimit)
    {
        push3(v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v2;
    stack[-1] = v1;
    stack[-2] = v0;
/* end of prologue */

v8:
    v64 = stack[-1];
    if (v64 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = integerp(v64);
    if (v64 == nil) goto v33;
    v64 = stack[-1];
    v65 = qcar(v64);
    v64 = stack[0];
    v64 = qcar(v64);
    v64 = (Lisp_Object)geq2(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v64 = v64 ? lisp_true : nil;
    env = stack[-3];
    if (!(v64 == nil)) goto v35;
    v64 = stack[-1];
    v65 = qcar(v64);
    v64 = (Lisp_Object)1; /* 0 */
    v64 = (Lisp_Object)lessp2(v65, v64);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v64 = v64 ? lisp_true : nil;
    env = stack[-3];
    if (!(v64 == nil)) goto v35;
    v65 = stack[-2];
    v64 = stack[-1];
    v64 = qcar(v64);
    v64 = *(Lisp_Object *)((char *)v65 + (CELL-TAG_VECTOR) + ((int32_t)v64/(16/CELL)));
    stack[-2] = v64;
    v64 = stack[-1];
    v64 = qcdr(v64);
    stack[-1] = v64;
    v64 = stack[0];
    v64 = qcdr(v64);
    stack[0] = v64;
    goto v8;

v35:
    v64 = elt(env, 2); /* "Array out of bounds" */
    v65 = v64;
    v64 = v65;
    qvalue(elt(env, 3)) = v64; /* errmsg!* */
    v64 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v64 == nil)) goto v18;
    v64 = v65;
    fn = elt(env, 5); /* lprie */
    v64 = (*qfn1(fn))(qenv(fn), v64);
    nil = C_nil;
    if (exception_pending()) goto v16;
    env = stack[-3];
    goto v18;

v18:
    v64 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v16;
    v64 = nil;
    { popv(4); return onevalue(v64); }

v33:
    v64 = stack[-1];
    v65 = qcar(v64);
    v64 = elt(env, 1); /* "array index" */
    {
        popv(4);
        fn = elt(env, 6); /* typerr */
        return (*qfn2(fn))(qenv(fn), v65, v64);
    }
/* error exit handlers */
v16:
    popv(4);
    return nil;
}



/* Code for bc!=simp */

static Lisp_Object CC_bcMsimp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v60, v168;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bc=simp");
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
    v168 = elt(env, 1); /* cali */
    v60 = elt(env, 2); /* rules */
    v60 = get(v168, v60);
    env = stack[-5];
    stack[-4] = v60;
    v60 = stack[-4];
    if (v60 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v60 = (Lisp_Object)1; /* 0 */
    stack[0] = v60;
    v60 = stack[-4];
    stack[-2] = v60;
    goto v34;

v34:
    v60 = stack[-2];
    if (v60 == nil) goto v15;
    v168 = stack[0];
    v60 = (Lisp_Object)16001; /* 1000 */
    v60 = (Lisp_Object)lessp2(v168, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v60 = v60 ? lisp_true : nil;
    env = stack[-5];
    if (v60 == nil) goto v15;
    v168 = stack[-3];
    v60 = stack[-2];
    v60 = qcar(v60);
    v60 = qcar(v60);
    fn = elt(env, 6); /* qremf */
    v60 = (*qfn2(fn))(qenv(fn), v168, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-1] = v60;
    v60 = stack[-1];
    v60 = qcar(v60);
    if (v60 == nil) goto v145;
    v60 = stack[-1];
    v168 = qcar(v60);
    v60 = stack[-2];
    v60 = qcar(v60);
    v60 = qcdr(v60);
    fn = elt(env, 7); /* multf */
    v168 = (*qfn2(fn))(qenv(fn), v168, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    v60 = stack[-1];
    v60 = qcdr(v60);
    fn = elt(env, 8); /* addf */
    v60 = (*qfn2(fn))(qenv(fn), v168, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[-3] = v60;
    v60 = stack[0];
    v60 = add1(v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    stack[0] = v60;
    v60 = stack[-4];
    stack[-2] = v60;
    goto v34;

v145:
    v60 = stack[-2];
    v60 = qcdr(v60);
    stack[-2] = v60;
    goto v34;

v15:
    v168 = stack[0];
    v60 = (Lisp_Object)16001; /* 1000 */
    v60 = (Lisp_Object)lessp2(v168, v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v60 = v60 ? lisp_true : nil;
    env = stack[-5];
    if (!(v60 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v60 = qvalue(elt(env, 4)); /* !*protfg */
    if (!(v60 == nil)) goto v28;
    v60 = elt(env, 5); /* "recursion depth of bc!=simp too high" */
    fn = elt(env, 9); /* lprie */
    v60 = (*qfn1(fn))(qenv(fn), v60);
    nil = C_nil;
    if (exception_pending()) goto v63;
    env = stack[-5];
    goto v28;

v28:
    v60 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v63;
    v60 = nil;
    { popv(6); return onevalue(v60); }
/* error exit handlers */
v63:
    popv(6);
    return nil;
}



/* Code for pv_sort1 */

static Lisp_Object CC_pv_sort1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v145;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pv_sort1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v8:
    v160 = stack[-1];
    if (v160 == nil) goto v3;
    v160 = stack[-1];
    v160 = qcar(v160);
    v145 = qcdr(v160);
    v160 = stack[0];
    v160 = qcar(v160);
    v160 = qcdr(v160);
    v160 = (Lisp_Object)lessp2(v145, v160);
    nil = C_nil;
    if (exception_pending()) goto v147;
    v160 = v160 ? lisp_true : nil;
    env = stack[-3];
    if (v160 == nil) goto v26;
    v160 = stack[-1];
    v160 = qcdr(v160);
    stack[-2] = v160;
    v160 = stack[-1];
    v145 = qcar(v160);
    v160 = stack[0];
    v160 = cons(v145, v160);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    stack[0] = v160;
    v160 = stack[-2];
    stack[-1] = v160;
    goto v8;

v26:
    v160 = stack[-1];
    v160 = qcdr(v160);
    stack[-2] = v160;
    v160 = stack[-1];
    v145 = qcar(v160);
    v160 = stack[0];
    fn = elt(env, 1); /* pv_sort2 */
    v160 = (*qfn2(fn))(qenv(fn), v145, v160);
    nil = C_nil;
    if (exception_pending()) goto v147;
    env = stack[-3];
    stack[0] = v160;
    v160 = stack[-2];
    stack[-1] = v160;
    goto v8;

v3:
    v160 = stack[0];
        popv(4);
        return Lnreverse(nil, v160);
/* error exit handlers */
v147:
    popv(4);
    return nil;
}



/* Code for treesizep1 */

static Lisp_Object CC_treesizep1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v113;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for treesizep1");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v7:
    v99 = stack[-1];
    if (!consp(v99)) goto v6;
    v99 = stack[-1];
    v113 = qcar(v99);
    v99 = stack[0];
    v113 = CC_treesizep1(env, v113, v99);
    nil = C_nil;
    if (exception_pending()) goto v26;
    env = stack[-2];
    stack[0] = v113;
    v99 = (Lisp_Object)1; /* 0 */
    v99 = (Lisp_Object)greaterp2(v113, v99);
    nil = C_nil;
    if (exception_pending()) goto v26;
    v99 = v99 ? lisp_true : nil;
    env = stack[-2];
    if (v99 == nil) goto v109;
    v99 = stack[-1];
    v99 = qcdr(v99);
    stack[-1] = v99;
    goto v7;

v109:
    v99 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v99); }

v6:
    v99 = stack[0];
    popv(3);
    return sub1(v99);
/* error exit handlers */
v26:
    popv(3);
    return nil;
}



/* Code for removev */

static Lisp_Object CC_removev(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v70, v97, v149;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for removev");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v149 = v1;
    v97 = v0;
/* end of prologue */

v7:
    v29 = v97;
    if (v29 == nil) goto v92;
    v29 = v97;
    v29 = qcdr(v29);
    v70 = qcar(v29);
    v29 = v149;
    if (v70 == v29) goto v112;
    v29 = v97;
    v29 = qcdr(v29);
    v97 = v29;
    goto v7;

v112:
    v29 = v97;
    v70 = v97;
    v70 = qcdr(v70);
    v70 = qcdr(v70);
        popv(1);
        return Lrplacd(nil, v29, v70);

v92:
    v70 = elt(env, 1); /* "Vertex" */
    v97 = v149;
    v29 = elt(env, 2); /* "is absent." */
    v29 = list3(v70, v97, v29);
    nil = C_nil;
    if (exception_pending()) goto v129;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); /* cerror */
        return (*qfn1(fn))(qenv(fn), v29);
    }
/* error exit handlers */
v129:
    popv(1);
    return nil;
}



/* Code for pasf_deci */

static Lisp_Object CC_pasf_deci(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v35, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_deci");
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
    v34 = v0;
/* end of prologue */
    fn = elt(env, 1); /* pasf_dec */
    v34 = (*qfn1(fn))(qenv(fn), v34);
    errexit();
    v36 = v34;
    v34 = v36;
    v35 = qcar(v34);
    v34 = v36;
    v34 = qcdr(v34);
    if (v34 == nil) goto v74;
    v34 = v36;
    v34 = qcdr(v34);
    goto v9;

v9:
    return cons(v35, v34);

v74:
    v34 = (Lisp_Object)1; /* 0 */
    goto v9;
}



/* Code for ibalp_emptyclausep */

static Lisp_Object CC_ibalp_emptyclausep(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v130, v73;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_emptyclausep");
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
    v130 = stack[0];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcar(v130);
    if (v130 == nil) goto v106;
    v130 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v130); }

v106:
    v130 = stack[0];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v73 = qcar(v130);
    v130 = (Lisp_Object)1; /* 0 */
    v130 = Leqn(nil, v73, v130);
    nil = C_nil;
    if (exception_pending()) goto v161;
    env = stack[-1];
    if (v130 == nil) goto v92;
    v130 = stack[0];
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v130 = qcdr(v130);
    v73 = qcar(v130);
    v130 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Leqn(nil, v73, v130);

v92:
    v130 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v130); }
/* error exit handlers */
v161:
    popv(2);
    return nil;
}



/* Code for ratpoly_ldeg */

static Lisp_Object CC_ratpoly_ldeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ratpoly_ldeg");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v0;
/* end of prologue */
    v7 = qcar(v7);
    {
        fn = elt(env, 1); /* numpoly_ldeg */
        return (*qfn1(fn))(qenv(fn), v7);
    }
}



/* Code for omobj */

static Lisp_Object MS_CDECL CC_omobj(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v36, v107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "omobj");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for omobj");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v36 = qvalue(elt(env, 1)); /* char */
    fn = elt(env, 4); /* compress!* */
    v107 = (*qfn1(fn))(qenv(fn), v36);
    nil = C_nil;
    if (exception_pending()) goto v111;
    env = stack[0];
    v36 = qvalue(elt(env, 2)); /* omfuncs!* */
    v36 = Lassoc(nil, v107, v36);
    v107 = v36;
    if (v36 == nil) goto v8;
    v36 = v107;
    v36 = qcdr(v36);
    v107 = qcar(v36);
    v36 = qvalue(elt(env, 3)); /* nil */
    {
        popv(1);
        fn = elt(env, 5); /* apply */
        return (*qfn2(fn))(qenv(fn), v107, v36);
    }

v8:
    v36 = nil;
    { popv(1); return onevalue(v36); }
/* error exit handlers */
v111:
    popv(1);
    return nil;
}



/* Code for mk!*sq */

static Lisp_Object CC_mkHsq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v296, v169;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk*sq");
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
    v169 = v0;
/* end of prologue */
    v296 = qvalue(elt(env, 1)); /* !*exp */
    if (v296 == nil) goto v6;
    v296 = v169;
    goto v67;

v67:
    stack[0] = v296;
    v296 = stack[0];
    v296 = qcar(v296);
    if (v296 == nil) goto v95;
    v296 = stack[0];
    v296 = qcar(v296);
    if (!(!consp(v296))) goto v32;
    v296 = stack[0];
    v169 = qcdr(v296);
    v296 = (Lisp_Object)17; /* 1 */
    if (!(v169 == v296)) goto v32;
    v296 = stack[0];
    v296 = qcar(v296);
    { popv(3); return onevalue(v296); }

v32:
    v296 = stack[0];
    fn = elt(env, 7); /* kernp */
    v296 = (*qfn1(fn))(qenv(fn), v296);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-2];
    if (v296 == nil) goto v102;
    v296 = stack[0];
    v296 = qcar(v296);
    v296 = qcar(v296);
    v296 = qcar(v296);
    v169 = qcar(v296);
    v296 = elt(env, 2); /* list */
    if (!consp(v169)) goto v102;
    v169 = qcar(v169);
    if (!(v169 == v296)) goto v102;
    v296 = stack[0];
    v296 = qcar(v296);
    v296 = qcar(v296);
    v296 = qcar(v296);
    v296 = qcar(v296);
    { popv(3); return onevalue(v296); }

v102:
    stack[-1] = elt(env, 3); /* !*sq */
    v296 = qvalue(elt(env, 4)); /* !*resubs */
    if (v296 == nil) goto v11;
    v296 = qvalue(elt(env, 5)); /* !*sqvar!* */
    goto v105;

v105:
    {
        Lisp_Object v66 = stack[-1];
        Lisp_Object v128 = stack[0];
        popv(3);
        return list2star(v66, v128, v296);
    }

v11:
    v296 = qvalue(elt(env, 6)); /* nil */
    v296 = ncons(v296);
    nil = C_nil;
    if (exception_pending()) goto v12;
    goto v105;

v95:
    v296 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v296); }

v6:
    v296 = v169;
    fn = elt(env, 8); /* offexpchk */
    v296 = (*qfn1(fn))(qenv(fn), v296);
    nil = C_nil;
    if (exception_pending()) goto v12;
    env = stack[-2];
    goto v67;
/* error exit handlers */
v12:
    popv(3);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v167, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for testred");
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
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v167 = qvalue(elt(env, 2)); /* maxvar */
    v41 = stack[0];
    v41 = plus2(v167, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v167 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    v41 = (Lisp_Object)1; /* 0 */
    v41 = *(Lisp_Object *)((char *)v167 + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    if (v41 == nil) goto v7;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v167 = qvalue(elt(env, 2)); /* maxvar */
    v41 = stack[0];
    v41 = plus2(v167, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v167 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    v41 = (Lisp_Object)17; /* 1 */
    v41 = *(Lisp_Object *)((char *)v167 + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    v41 = qcar(v41);
    v167 = qcar(v41);
    v41 = (Lisp_Object)33; /* 2 */
    v41 = (Lisp_Object)lessp2(v167, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    v41 = v41 ? lisp_true : nil;
    env = stack[-2];
    if (v41 == nil) goto v7;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v167 = qvalue(elt(env, 2)); /* maxvar */
    v41 = stack[0];
    v41 = plus2(v167, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v89 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    v167 = (Lisp_Object)1; /* 0 */
    v41 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v89 + (CELL-TAG_VECTOR) + ((int32_t)v167/(16/CELL))) = v41;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v167 = qvalue(elt(env, 2)); /* maxvar */
    v41 = stack[0];
    v41 = plus2(v167, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v167 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    v41 = (Lisp_Object)65; /* 4 */
    v41 = *(Lisp_Object *)((char *)v167 + (CELL-TAG_VECTOR) + ((int32_t)v41/(16/CELL)));
    stack[-1] = v41;
    goto v127;

v127:
    v41 = stack[-1];
    if (v41 == nil) goto v61;
    v41 = stack[-1];
    v41 = qcar(v41);
    stack[0] = v41;
    v41 = stack[0];
    v167 = qcar(v41);
    v41 = stack[0];
    v41 = qcdr(v41);
    v41 = qcar(v41);
    fn = elt(env, 4); /* downwght1 */
    v41 = (*qfn2(fn))(qenv(fn), v167, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v41 = stack[0];
    v41 = qcar(v41);
    v41 = CC_testred(env, v41);
    nil = C_nil;
    if (exception_pending()) goto v298;
    env = stack[-2];
    v41 = stack[-1];
    v41 = qcdr(v41);
    stack[-1] = v41;
    goto v127;

v61:
    v41 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v41); }

v7:
    v41 = nil;
    { popv(3); return onevalue(v41); }
/* error exit handlers */
v298:
    popv(3);
    return nil;
}



/* Code for mknwedge */

static Lisp_Object CC_mknwedge(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v108, v32;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mknwedge");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v32 = v0;
/* end of prologue */
    v108 = v32;
    v108 = qcdr(v108);
    if (v108 == nil) goto v106;
    v108 = elt(env, 1); /* wedge */
    return cons(v108, v32);

v106:
    v108 = v32;
    v108 = qcar(v108);
    return onevalue(v108);
}



/* Code for smemqlp */

static Lisp_Object CC_smemqlp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v98;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for smemqlp");
#endif
    if (stack >= stacklimit)
    {
        push2(v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v1);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-1] = v0;
/* end of prologue */

v37:
    v19 = stack[0];
    if (v19 == nil) goto v7;
    v19 = stack[0];
    if (is_number(v19)) goto v7;
    v19 = stack[0];
    if (!consp(v19)) goto v95;
    v19 = stack[0];
    v98 = qcar(v19);
    v19 = elt(env, 2); /* quote */
    if (v98 == v19) goto v139;
    v98 = stack[-1];
    v19 = stack[0];
    v19 = qcar(v19);
    v19 = CC_smemqlp(env, v98, v19);
    nil = C_nil;
    if (exception_pending()) goto v148;
    env = stack[-2];
    if (!(v19 == nil)) { popv(3); return onevalue(v19); }
    v98 = stack[-1];
    v19 = stack[0];
    v19 = qcdr(v19);
    stack[-1] = v98;
    stack[0] = v19;
    goto v37;

v139:
    v19 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v19); }

v95:
    v98 = stack[0];
    v19 = stack[-1];
    v19 = Lmemq(nil, v98, v19);
    { popv(3); return onevalue(v19); }

v7:
    v19 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v19); }
/* error exit handlers */
v148:
    popv(3);
    return nil;
}



setup_type const u05_setup[] =
{
    {"layout-formula",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_layoutKformula},
    {"repeatsp",                CC_repeatsp,    too_many_1,    wrong_no_1},
    {"assert_analyze",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_analyze},
    {"lambda_l9xqtq_1",         too_few_2,      CC_lambda_l9xqtq_1,wrong_no_2},
    {"simpplus",                CC_simpplus,    too_many_1,    wrong_no_1},
    {"mo_compare",              too_few_2,      CC_mo_compare, wrong_no_2},
    {"pv_sort",                 CC_pv_sort,     too_many_1,    wrong_no_1},
    {"sc_kern",                 CC_sc_kern,     too_many_1,    wrong_no_1},
    {"rntimes:",                too_few_2,      CC_rntimesT,   wrong_no_2},
    {"mod#",                    CC_modC,        too_many_1,    wrong_no_1},
    {"times-mod-p",             too_few_2,      CC_timesKmodKp,wrong_no_2},
    {"rl_smmkatl",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_rl_smmkatl},
    {"tayexp-min2",             too_few_2,      CC_tayexpKmin2,wrong_no_2},
    {"subs2",                   CC_subs2,       too_many_1,    wrong_no_1},
    {"sqchk",                   CC_sqchk,       too_many_1,    wrong_no_1},
    {"cl_simplat",              too_few_2,      CC_cl_simplat, wrong_no_2},
    {"ibalp_cequal",            too_few_2,      CC_ibalp_cequal,wrong_no_2},
    {"ratpoly_idl",             CC_ratpoly_idl, too_many_1,    wrong_no_1},
    {"list2string",             CC_list2string, too_many_1,    wrong_no_1},
    {"isarb_int",               CC_isarb_int,   too_many_1,    wrong_no_1},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"make-set",                CC_makeKset,    too_many_1,    wrong_no_1},
    {"convchk",                 CC_convchk,     too_many_1,    wrong_no_1},
    {"maxdeg",                  too_few_2,      CC_maxdeg,     wrong_no_2},
    {"idlistp",                 CC_idlistp,     too_many_1,    wrong_no_1},
    {"eolcheck",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_eolcheck},
    {"reval2",                  too_few_2,      CC_reval2,     wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"pv_add",                  too_few_2,      CC_pv_add,     wrong_no_2},
    {"modplus:",                too_few_2,      CC_modplusT,   wrong_no_2},
    {"gen-mult-by-const-mod-p", too_few_2,      CC_genKmultKbyKconstKmodKp,wrong_no_2},
    {"subs3q",                  CC_subs3q,      too_many_1,    wrong_no_1},
    {"tayexp-difference",       too_few_2,      CC_tayexpKdifference,wrong_no_2},
    {"get+col+nr",              CC_getLcolLnr,  too_many_1,    wrong_no_1},
    {"rl_varlat",               CC_rl_varlat,   too_many_1,    wrong_no_1},
    {"find",                    too_few_2,      CC_find,       wrong_no_2},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"sortcolelem",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_sortcolelem},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"find_item",               too_few_2,      CC_find_item,  wrong_no_2},
    {"noncommuting",            too_few_2,      CC_noncommuting,wrong_no_2},
    {"form1",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_form1},
    {"mo=lexcomp",              too_few_2,      CC_moMlexcomp, wrong_no_2},
    {"insert_pv",               too_few_2,      CC_insert_pv,  wrong_no_2},
    {"gionep:",                 CC_gionepT,     too_many_1,    wrong_no_1},
    {"ibalp_calcmom",           CC_ibalp_calcmom,too_many_1,   wrong_no_1},
    {"quotfd",                  too_few_2,      CC_quotfd,     wrong_no_2},
    {"mkwedge",                 CC_mkwedge,     too_many_1,    wrong_no_1},
    {"evaluate0",               too_few_2,      CC_evaluate0,  wrong_no_2},
    {"optype",                  CC_optype,      too_many_1,    wrong_no_1},
    {"noncommutingf",           too_few_2,      CC_noncommutingf,wrong_no_2},
    {"convertmode1",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_convertmode1},
    {"getel1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_getel1},
    {"bc=simp",                 CC_bcMsimp,     too_many_1,    wrong_no_1},
    {"pv_sort1",                too_few_2,      CC_pv_sort1,   wrong_no_2},
    {"treesizep1",              too_few_2,      CC_treesizep1, wrong_no_2},
    {"removev",                 too_few_2,      CC_removev,    wrong_no_2},
    {"pasf_deci",               CC_pasf_deci,   too_many_1,    wrong_no_1},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,too_many_1,wrong_no_1},
    {"ratpoly_ldeg",            CC_ratpoly_ldeg,too_many_1,    wrong_no_1},
    {"omobj",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_omobj},
    {"mk*sq",                   CC_mkHsq,       too_many_1,    wrong_no_1},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"mknwedge",                CC_mknwedge,    too_many_1,    wrong_no_1},
    {"smemqlp",                 too_few_2,      CC_smemqlp,    wrong_no_2},
    {NULL, (one_args *)"u05", (two_args *)"4103 6859962 5130685", 0}
};

/* end of generated code */
