
/* $destdir\u21.c        Machine generated C code */

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


/* Code for cl_qb */

static Lisp_Object CC_cl_qb(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v13, v14, v15, v16, v17;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_qb");
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
    v17 = nil;
    v13 = (Lisp_Object)1; /* 0 */
    v16 = v13;
    goto v18;

v18:
    v13 = stack[0];
    if (!consp(v13)) goto v19;
    v13 = stack[0];
    v13 = qcar(v13);
    goto v20;

v20:
    stack[-1] = v13;
    v15 = v13;
    v14 = v15;
    v13 = elt(env, 1); /* ex */
    v13 = (v14 == v13 ? lisp_true : nil);
    if (!(v13 == nil)) goto v21;
    v14 = v15;
    v13 = elt(env, 2); /* all */
    v13 = (v14 == v13 ? lisp_true : nil);
    goto v21;

v21:
    if (v13 == nil) { popv(3); return onevalue(v16); }
    v14 = stack[-1];
    v13 = v17;
    if (equal(v14, v13)) goto v22;
    v13 = v16;
    v13 = add1(v13);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v16 = v13;
    v13 = stack[-1];
    v17 = v13;
    goto v22;

v22:
    v13 = stack[0];
    v13 = qcdr(v13);
    v13 = qcdr(v13);
    v13 = qcar(v13);
    stack[0] = v13;
    goto v18;

v19:
    v13 = stack[0];
    goto v20;
/* error exit handlers */
v23:
    popv(3);
    return nil;
}



/* Code for ofsf_ordatp */

static Lisp_Object CC_ofsf_ordatp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v7, v8, v31, v32, v33, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ordatp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v33 = v24;
    v22 = v0;
/* end of prologue */
    v7 = v22;
    v7 = qcdr(v7);
    v7 = qcar(v7);
    v32 = v7;
    v7 = v33;
    v7 = qcdr(v7);
    v7 = qcar(v7);
    v31 = v7;
    v8 = v32;
    v7 = v31;
    if (equal(v8, v7)) goto v34;
    v7 = v32;
    v8 = v31;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v7, v8);
    }

v34:
    v7 = v22;
    v7 = qcar(v7);
    v8 = v33;
    v8 = qcar(v8);
    {
        fn = elt(env, 2); /* ofsf_ordrelp */
        return (*qfn2(fn))(qenv(fn), v7, v8);
    }
}



/* Code for naryom */

static Lisp_Object CC_naryom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v39, v40;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for naryom");
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
    v39 = stack[-1];
    v39 = qcar(v39);
    stack[0] = v39;
    v40 = stack[0];
    v39 = elt(env, 1); /* var */
    if (!(v40 == v39)) goto v41;
    v39 = elt(env, 2); /* variance */
    stack[0] = v39;
    goto v41;

v41:
    v40 = stack[0];
    v39 = qvalue(elt(env, 3)); /* valid_om!* */
    v39 = Lassoc(nil, v40, v39);
    stack[-2] = v39;
    v39 = stack[-2];
    if (v39 == nil) goto v42;
    v39 = stack[-2];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    stack[-2] = v39;
    goto v42;

v42:
    v39 = stack[-1];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    if (v39 == nil) goto v43;
    v39 = stack[-1];
    v39 = qcdr(v39);
    v40 = qcar(v39);
    v39 = elt(env, 4); /* multiset */
    if (!(v40 == v39)) goto v43;
    v39 = stack[-1];
    v39 = qcdr(v39);
    v39 = qcar(v39);
    stack[-2] = v39;
    goto v43;

v43:
    v39 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v40 = qvalue(elt(env, 7)); /* indent */
    v39 = (Lisp_Object)33; /* 2 */
    v39 = plus2(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    qvalue(elt(env, 7)) = v39; /* indent */
    v39 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v39 = stack[-2];
    v39 = Lprinc(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v39 = elt(env, 9); /* """ name=""" */
    v39 = Lprinc(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v39 = stack[0];
    v39 = Lprinc(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v39 = elt(env, 10); /* """>" */
    v39 = Lprinc(nil, v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v39 = stack[-1];
    v39 = qcdr(v39);
    v39 = qcdr(v39);
    fn = elt(env, 13); /* multiom */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    v40 = qvalue(elt(env, 7)); /* indent */
    v39 = (Lisp_Object)33; /* 2 */
    v39 = difference2(v40, v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    env = stack[-3];
    qvalue(elt(env, 7)) = v39; /* indent */
    v39 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v39 = (*qfn1(fn))(qenv(fn), v39);
    nil = C_nil;
    if (exception_pending()) goto v44;
    v39 = nil;
    { popv(4); return onevalue(v39); }
/* error exit handlers */
v44:
    popv(4);
    return nil;
}



/* Code for ft!:zerop */

static Lisp_Object CC_ftTzerop(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ft:zerop");
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
    v8 = v0;
/* end of prologue */
    stack[0] = v8;
    v31 = (Lisp_Object)161; /* 10 */
    v8 = qvalue(elt(env, 1)); /* !:prec!: */
    v8 = Lexpt(nil, v31, v8);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    v8 = times2(stack[0], v8);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    stack[0] = v8;
    v31 = stack[0];
    v8 = (Lisp_Object)-799; /* -50 */
    v8 = (Lisp_Object)greaterp2(v31, v8);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v8 = v8 ? lisp_true : nil;
    env = stack[-1];
    if (v8 == nil) goto v29;
    v31 = stack[0];
    v8 = (Lisp_Object)801; /* 50 */
        popv(2);
        return Llessp(nil, v31, v8);

v29:
    v8 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v8); }
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for gvarlis1 */

static Lisp_Object CC_gvarlis1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v52;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gvarlis1");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v24;
    stack[-1] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v53;

v53:
    v51 = stack[-1];
    if (v51 == nil) goto v54;
    v51 = stack[-1];
    v52 = qcar(v51);
    v51 = stack[0];
    fn = elt(env, 1); /* gvar1 */
    v52 = (*qfn2(fn))(qenv(fn), v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    v51 = stack[-2];
    v51 = cons(v52, v51);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    stack[-2] = v51;
    v51 = stack[-1];
    v51 = qcdr(v51);
    stack[-1] = v51;
    goto v53;

v54:
    v51 = stack[0];
    v52 = v51;
    goto v55;

v55:
    v51 = stack[-2];
    if (v51 == nil) { popv(4); return onevalue(v52); }
    v51 = stack[-2];
    v51 = qcar(v51);
    fn = elt(env, 2); /* union */
    v51 = (*qfn2(fn))(qenv(fn), v51, v52);
    nil = C_nil;
    if (exception_pending()) goto v2;
    env = stack[-3];
    v52 = v51;
    v51 = stack[-2];
    v51 = qcdr(v51);
    stack[-2] = v51;
    goto v55;
/* error exit handlers */
v2:
    popv(4);
    return nil;
}



/* Code for assert_typedefstat */

static Lisp_Object MS_CDECL CC_assert_typedefstat(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "assert_typedefstat");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for assert_typedefstat");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* end of prologue */
    fn = elt(env, 17); /* scan */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[0] = v69;
    fn = elt(env, 17); /* scan */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v70 = qvalue(elt(env, 1)); /* cursym!* */
    v69 = elt(env, 2); /* delim */
    v69 = Lflagp(nil, v70, v69);
    env = stack[-4];
    if (v69 == nil) goto v73;
    v69 = qvalue(elt(env, 3)); /* !*assert */
    if (v69 == nil) goto v49;
    v69 = qvalue(elt(env, 5)); /* !*msg */
    if (v69 == nil) goto v6;
    v69 = qvalue(elt(env, 5)); /* !*msg */
    if (v69 == nil) goto v6;
    stack[-1] = elt(env, 6); /* "***" */
    v71 = elt(env, 7); /* "type" */
    v70 = stack[0];
    v69 = elt(env, 8); /* "is not checked" */
    v69 = list3(v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    fn = elt(env, 18); /* lpriw */
    v69 = (*qfn2(fn))(qenv(fn), stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v6;

v6:
    v69 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v69); }

v49:
    v69 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v69); }

v73:
    v70 = qvalue(elt(env, 1)); /* cursym!* */
    v69 = elt(env, 9); /* checked */
    if (v70 == v69) goto v74;
    v69 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v69 == nil)) goto v75;
    v70 = elt(env, 11); /* "expecting 'checked by' in typedef but found" 
*/
    v69 = qvalue(elt(env, 1)); /* cursym!* */
    v69 = list2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v75;

v75:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v74;

v74:
    fn = elt(env, 17); /* scan */
    v70 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v69 = elt(env, 12); /* by */
    if (v70 == v69) goto v76;
    v69 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v69 == nil)) goto v44;
    v70 = elt(env, 13); /* "expecting 'by' in typedef but found" */
    v69 = qvalue(elt(env, 1)); /* cursym!* */
    v69 = list2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v44;

v44:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v76;

v76:
    fn = elt(env, 17); /* scan */
    v69 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[-3] = v69;
    fn = elt(env, 17); /* scan */
    v70 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    v69 = elt(env, 2); /* delim */
    v69 = Lflagp(nil, v70, v69);
    env = stack[-4];
    if (!(v69 == nil)) goto v77;
    v69 = qvalue(elt(env, 10)); /* !*protfg */
    if (!(v69 == nil)) goto v78;
    v70 = elt(env, 14); /* "expecting end of typedef but found" */
    v69 = qvalue(elt(env, 1)); /* cursym!* */
    v69 = list2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    fn = elt(env, 19); /* lprie */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v78;

v78:
    v69 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    goto v77;

v77:
    v69 = qvalue(elt(env, 3)); /* !*assert */
    if (v69 == nil) goto v79;
    stack[-2] = elt(env, 15); /* put */
    v69 = stack[0];
    stack[-1] = Lmkquote(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    env = stack[-4];
    stack[0] = elt(env, 16); /* (quote assert_checkfn) */
    v69 = stack[-3];
    v69 = Lmkquote(nil, v69);
    nil = C_nil;
    if (exception_pending()) goto v72;
    {
        Lisp_Object v80 = stack[-2];
        Lisp_Object v81 = stack[-1];
        Lisp_Object v82 = stack[0];
        popv(5);
        return list4(v80, v81, v82, v69);
    }

v79:
    v69 = qvalue(elt(env, 4)); /* nil */
    { popv(5); return onevalue(v69); }
/* error exit handlers */
v72:
    popv(5);
    return nil;
}



/* Code for fs!:prin1 */

static Lisp_Object CC_fsTprin1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v96, v97;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:prin1");
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
    stack[0] = v0;
/* end of prologue */
    v96 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v96;
    v97 = stack[0];
    v96 = (Lisp_Object)1; /* 0 */
    v97 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    v96 = elt(env, 2); /* (1 . 1) */
    if (equal(v97, v96)) goto v55;
    v96 = elt(env, 3); /* "(" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v97 = stack[0];
    v96 = (Lisp_Object)1; /* 0 */
    v96 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    fn = elt(env, 13); /* sqprint */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v96 = elt(env, 4); /* ")" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v55;

v55:
    v96 = stack[0];
    fn = elt(env, 14); /* fs!:null!-angle */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    if (v96 == nil) goto v33;
    v97 = stack[0];
    v96 = (Lisp_Object)1; /* 0 */
    v97 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    v96 = elt(env, 2); /* (1 . 1) */
    if (!(equal(v97, v96))) goto v99;
    v96 = elt(env, 11); /* "1" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    goto v99;

v99:
    v96 = nil;
    { popv(5); return onevalue(v96); }

v33:
    v97 = stack[0];
    v96 = (Lisp_Object)17; /* 1 */
    v96 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v96 = elt(env, 5); /* "[" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v97 = stack[0];
    v96 = (Lisp_Object)33; /* 2 */
    v96 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    stack[-2] = v96;
    v96 = (Lisp_Object)1; /* 0 */
    stack[0] = v96;
    goto v100;

v100:
    v97 = (Lisp_Object)113; /* 7 */
    v96 = stack[0];
    v96 = difference2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v96 = Lminusp(nil, v96);
    env = stack[-4];
    if (v96 == nil) goto v101;
    v96 = elt(env, 10); /* "]" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    goto v99;

v101:
    v97 = stack[-2];
    v96 = stack[0];
    v97 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    stack[-1] = v97;
    v96 = (Lisp_Object)1; /* 0 */
    if (v97 == v96) goto v102;
    v97 = stack[-1];
    v96 = (Lisp_Object)1; /* 0 */
    v96 = (Lisp_Object)lessp2(v97, v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    v96 = v96 ? lisp_true : nil;
    env = stack[-4];
    if (v96 == nil) goto v103;
    v96 = qvalue(elt(env, 1)); /* t */
    stack[-3] = v96;
    v96 = elt(env, 7); /* "-" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    v96 = stack[-1];
    v96 = negate(v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    stack[-1] = v96;
    goto v103;

v103:
    v96 = stack[-3];
    if (!(v96 == nil)) goto v78;
    v96 = elt(env, 8); /* "+" */
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v78;

v78:
    v97 = stack[-1];
    v96 = (Lisp_Object)17; /* 1 */
    if (v97 == v96) goto v104;
    v96 = stack[-1];
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v104;

v104:
    v96 = qvalue(elt(env, 6)); /* nil */
    stack[-3] = v96;
    v97 = qvalue(elt(env, 9)); /* fourier!-name!* */
    v96 = stack[0];
    v96 = *(Lisp_Object *)((char *)v97 + (CELL-TAG_VECTOR) + ((int32_t)v96/(16/CELL)));
    fn = elt(env, 12); /* prin2!* */
    v96 = (*qfn1(fn))(qenv(fn), v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    goto v102;

v102:
    v96 = stack[0];
    v96 = add1(v96);
    nil = C_nil;
    if (exception_pending()) goto v98;
    env = stack[-4];
    stack[0] = v96;
    goto v100;
/* error exit handlers */
v98:
    popv(5);
    return nil;
}



/* Code for dpmat_coldegs */

static Lisp_Object CC_dpmat_coldegs(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dpmat_coldegs");
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
    v45 = v0;
/* end of prologue */
    v46 = v45;
    v45 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 1); /* pnth */
    v45 = (*qfn2(fn))(qenv(fn), v46, v45);
    errexit();
    v45 = qcar(v45);
    return onevalue(v45);
}



/* Code for subs3t */

static Lisp_Object CC_subs3t(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v167, v168, v169, v170;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subs3t");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    v168 = v24;
    stack[-4] = v0;
/* end of prologue */
    stack[-5] = nil;
    v167 = stack[-4];
    stack[0] = qcar(v167);
    v167 = stack[-4];
    v167 = qcdr(v167);
    if (!consp(v167)) goto v171;
    v167 = stack[-4];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    if (!consp(v167)) goto v171;
    v167 = v168;
    goto v41;

v41:
    fn = elt(env, 14); /* mtchk */
    v167 = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-3] = v167;
    v167 = stack[-3];
    if (v167 == nil) goto v91;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    if (v167 == nil) goto v45;
    v167 = stack[-4];
    v169 = qcdr(v167);
    v168 = stack[-3];
    v167 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 15); /* subs3f1 */
    v167 = (*qfnn(fn))(qenv(fn), 3, v169, v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-2] = v167;
    v167 = qvalue(elt(env, 2)); /* mchfg!* */
    if (v167 == nil) goto v91;
    v167 = stack[-4];
    v168 = qcar(v167);
    v167 = (Lisp_Object)17; /* 1 */
    v167 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v168 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = (Lisp_Object)17; /* 1 */
    v168 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = stack[-2];
    {
        popv(7);
        fn = elt(env, 16); /* multsq */
        return (*qfn2(fn))(qenv(fn), v168, v167);
    }

v91:
    v167 = stack[-4];
    v168 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v167 = (Lisp_Object)17; /* 1 */
    popv(7);
    return cons(v168, v167);

v45:
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    v167 = qcdr(v167);
    stack[-3] = v167;
    v167 = stack[-3];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = qcar(v167);
    stack[-1] = v167;
    v167 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v167; /* mchfg!* */
    v167 = stack[-4];
    v169 = qcdr(v167);
    v168 = qvalue(elt(env, 3)); /* !*match */
    v167 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 15); /* subs3f1 */
    v167 = (*qfnn(fn))(qenv(fn), 3, v169, v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-2] = v167;
    v167 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 2)) = v167; /* mchfg!* */
    v167 = stack[-1];
    v168 = qcar(v167);
    v167 = stack[-4];
    v167 = qcar(v167);
    v167 = qcar(v167);
    if (equal(v168, v167)) goto v173;
    v167 = stack[-1];
    v167 = qcar(v167);
    fn = elt(env, 17); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = stack[-4];
    v167 = qcar(v167);
    v167 = qcar(v167);
    fn = elt(env, 17); /* simp */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    if (equal(stack[0], v167)) goto v174;
    v167 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 18); /* terpri!* */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = elt(env, 9); /* "CATASTROPHIC ERROR *****" */
    fn = elt(env, 19); /* lprie */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v170 = elt(env, 0); /* subs3t */
    v169 = stack[-4];
    v168 = stack[-3];
    v167 = stack[-1];
    v167 = list4(v170, v169, v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    fn = elt(env, 20); /* printty */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v168 = elt(env, 10); /* " " */
    v167 = qvalue(elt(env, 1)); /* nil */
    fn = elt(env, 21); /* lpriw */
    v167 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = elt(env, 11); /* "Please report output and input listing on the sourceforge bug tracker" 
*/
    v168 = v167;
    v167 = v168;
    qvalue(elt(env, 12)) = v167; /* errmsg!* */
    v167 = qvalue(elt(env, 13)); /* !*protfg */
    if (!(v167 == nil)) goto v175;
    v167 = v168;
    fn = elt(env, 19); /* lprie */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    goto v175;

v175:
    v167 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    goto v174;

v174:
    v167 = stack[-1];
    v168 = qcdr(v167);
    v167 = stack[-4];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    if (equal(v168, v167)) goto v176;
    v167 = stack[-4];
    v167 = qcar(v167);
    stack[0] = qcar(v167);
    v167 = stack[-4];
    v167 = qcar(v167);
    v168 = qcdr(v167);
    v167 = stack[-1];
    v167 = qcdr(v167);
    v168 = difference2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = (Lisp_Object)17; /* 1 */
    v167 = acons(stack[0], v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v168 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = (Lisp_Object)17; /* 1 */
    v168 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = stack[-2];
    fn = elt(env, 16); /* multsq */
    v167 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-2] = v167;
    goto v176;

v176:
    v167 = stack[-3];
    v167 = qcar(v167);
    fn = elt(env, 17); /* simp */
    v168 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = stack[-2];
    fn = elt(env, 16); /* multsq */
    v167 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-2] = v167;
    v167 = stack[-3];
    v167 = qcdr(v167);
    v167 = qcar(v167);
    v167 = qcdr(v167);
    stack[-3] = v167;
    v167 = stack[-3];
    if (v167 == nil) { Lisp_Object res = stack[-2]; popv(7); return onevalue(res); }
    v167 = (Lisp_Object)17; /* 1 */
    stack[-1] = v167;
    goto v177;

v177:
    v167 = stack[-3];
    if (v167 == nil) goto v178;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    if (!consp(v167)) goto v179;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    if (!consp(v167)) goto v180;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    v167 = qcar(v167);
    if (!(!consp(v167))) goto v179;

v180:
    v167 = qvalue(elt(env, 1)); /* nil */
    stack[-4] = qvalue(elt(env, 5)); /* subfg!* */
    qvalue(elt(env, 5)) = v167; /* subfg!* */
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    fn = elt(env, 17); /* simp */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    stack[0] = v167;
    v167 = stack[0];
    fn = elt(env, 22); /* kernp */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    if (v167 == nil) goto v182;
    v167 = stack[0];
    v167 = qcar(v167);
    v167 = qcar(v167);
    v167 = qcar(v167);
    v168 = qcar(v167);
    stack[0] = v168;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    v167 = qcar(v167);
    if (!consp(v168)) goto v182;
    v168 = qcar(v168);
    if (!(v168 == v167)) goto v182;
    v167 = stack[0];
    goto v183;

v183:
    qvalue(elt(env, 5)) = stack[-4]; /* subfg!* */
    goto v184;

v184:
    stack[0] = v167;
    v167 = qvalue(elt(env, 7)); /* !*ncmp */
    if (v167 == nil) goto v185;
    v167 = stack[0];
    fn = elt(env, 23); /* noncomp1 */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    if (!(v167 == nil)) goto v186;

v185:
    v167 = qvalue(elt(env, 8)); /* !*mcd */
    if (!(v167 == nil)) goto v187;

v186:
    v167 = qvalue(elt(env, 4)); /* t */
    stack[-5] = v167;
    goto v187;

v187:
    v167 = stack[0];
    fn = elt(env, 24); /* fkern */
    stack[0] = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = stack[-5];
    if (v167 == nil) goto v188;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    v167 = negate(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    goto v189;

v189:
    fn = elt(env, 25); /* getpower */
    v168 = (*qfn2(fn))(qenv(fn), stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = (Lisp_Object)17; /* 1 */
    v167 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    fn = elt(env, 26); /* multf */
    v167 = (*qfn2(fn))(qenv(fn), stack[-1], v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-1] = v167;
    v167 = stack[-3];
    v167 = qcdr(v167);
    stack[-3] = v167;
    goto v177;

v188:
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcdr(v167);
    goto v189;

v182:
    v167 = qvalue(elt(env, 6)); /* !*val */
    if (v167 == nil) goto v190;
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    stack[0] = qcar(v167);
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    v167 = qcdr(v167);
    fn = elt(env, 27); /* revlis */
    v167 = (*qfn1(fn))(qenv(fn), v167);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    v167 = cons(stack[0], v167);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-6];
    goto v183;

v190:
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    goto v183;

v179:
    v167 = stack[-3];
    v167 = qcar(v167);
    v167 = qcar(v167);
    goto v184;

v178:
    v167 = stack[-5];
    if (v167 == nil) goto v191;
    v168 = stack[-1];
    v167 = stack[-2];
    v167 = qcar(v167);
    fn = elt(env, 26); /* multf */
    v168 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    v167 = stack[-2];
    v167 = qcdr(v167);
    popv(7);
    return cons(v168, v167);

v191:
    v167 = stack[-2];
    stack[0] = qcar(v167);
    v168 = stack[-1];
    v167 = stack[-2];
    v167 = qcdr(v167);
    fn = elt(env, 26); /* multf */
    v167 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    {
        Lisp_Object v192 = stack[0];
        popv(7);
        return cons(v192, v167);
    }

v173:
    v168 = stack[-1];
    v167 = stack[-4];
    v167 = qcar(v167);
    if (equal(v168, v167)) goto v176;
    v167 = stack[-4];
    v167 = qcar(v167);
    stack[0] = qcar(v167);
    v167 = stack[-4];
    v167 = qcar(v167);
    v168 = qcdr(v167);
    v167 = stack[-1];
    v167 = qcdr(v167);
    v168 = difference2(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = (Lisp_Object)17; /* 1 */
    v167 = acons(stack[0], v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v168 = ncons(v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = (Lisp_Object)17; /* 1 */
    v168 = cons(v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    v167 = stack[-2];
    fn = elt(env, 16); /* multsq */
    v167 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    stack[-2] = v167;
    goto v176;

v171:
    v167 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 28); /* sizchk */
    v167 = (*qfn2(fn))(qenv(fn), v168, v167);
    nil = C_nil;
    if (exception_pending()) goto v172;
    env = stack[-6];
    goto v41;
/* error exit handlers */
v181:
    env = stack[-6];
    qvalue(elt(env, 5)) = stack[-4]; /* subfg!* */
    popv(7);
    return nil;
v172:
    popv(7);
    return nil;
}



/* Code for tensorp */

static Lisp_Object CC_tensorp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v41;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tensorp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v0;
/* end of prologue */
    v47 = v41;
    if (!consp(v47)) goto v1;
    v47 = v41;
    v47 = qcar(v47);
    v41 = elt(env, 2); /* tensor */
        return Lflagp(nil, v47, v41);

v1:
    v47 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v47);
}



/* Code for simpcv */

static Lisp_Object CC_simpcv(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v195, v196, v100;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpcv");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v24;
    stack[-1] = v0;
/* end of prologue */
    v195 = stack[-1];
    v196 = Llength(nil, v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v195 = (Lisp_Object)49; /* 3 */
    if (v196 == v195) goto v27;
    v196 = elt(env, 1); /* "Invalid number of edges in vertex" */
    v195 = stack[-1];
    v195 = list2(v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* cerror */
        return (*qfn1(fn))(qenv(fn), v195);
    }

v27:
    v196 = elt(env, 2); /* simpcgraph */
    v195 = qvalue(elt(env, 3)); /* mul!* */
    v195 = Lmemq(nil, v196, v195);
    if (!(v195 == nil)) goto v197;
    stack[-2] = qvalue(elt(env, 3)); /* mul!* */
    v195 = elt(env, 2); /* simpcgraph */
    v195 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v195 = Lnconc(nil, stack[-2], v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    qvalue(elt(env, 3)) = v195; /* mul!* */
    goto v197;

v197:
    v196 = stack[0];
    v195 = stack[-1];
    v100 = cons(v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v196 = (Lisp_Object)17; /* 1 */
    v195 = (Lisp_Object)17; /* 1 */
    v195 = acons(v100, v196, v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    env = stack[-3];
    v196 = ncons(v195);
    nil = C_nil;
    if (exception_pending()) goto v163;
    v195 = (Lisp_Object)17; /* 1 */
    popv(4);
    return cons(v196, v195);
/* error exit handlers */
v163:
    popv(4);
    return nil;
}



/* Code for simpexpt */

static Lisp_Object CC_simpexpt(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v14, v15, v16;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simpexpt");
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
    v14 = qvalue(elt(env, 1)); /* nil */
    stack[-1] = qvalue(elt(env, 2)); /* kord!* */
    qvalue(elt(env, 2)) = v14; /* kord!* */
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = qcdr(v14);
    if (v14 == nil) goto v12;
    v15 = elt(env, 3); /* "Wrong number of arguments to" */
    v14 = elt(env, 4); /* expt */
    v14 = list2(v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v15 = v14;
    v14 = v15;
    qvalue(elt(env, 5)) = v14; /* errmsg!* */
    v14 = qvalue(elt(env, 6)); /* !*protfg */
    if (!(v14 == nil)) goto v171;
    v14 = v15;
    fn = elt(env, 9); /* lprie */
    v14 = (*qfn1(fn))(qenv(fn), v14);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    goto v171;

v171:
    v14 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v14 = nil;
    v15 = v14;
    goto v18;

v18:
    v14 = elt(env, 7); /* simp!* */
    fn = elt(env, 10); /* simpexpon1 */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    v15 = v14;
    v14 = elt(env, 8); /* resimp */
    fn = elt(env, 10); /* simpexpon1 */
    v14 = (*qfn2(fn))(qenv(fn), v15, v14);
    nil = C_nil;
    if (exception_pending()) goto v23;
    env = stack[-2];
    v15 = stack[0];
    v16 = qcar(v15);
    v15 = v14;
    v14 = qvalue(elt(env, 1)); /* nil */
    {
        popv(3);
        fn = elt(env, 11); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v16, v15, v14);
    }

v12:
    v14 = stack[0];
    v14 = qcdr(v14);
    v14 = qcar(v14);
    v15 = v14;
    goto v18;
/* error exit handlers */
v23:
    popv(3);
    return nil;
v75:
    env = stack[-2];
    qvalue(elt(env, 2)) = stack[-1]; /* kord!* */
    popv(3);
    return nil;
}



/* Code for pasf_anegrel */

static Lisp_Object CC_pasf_anegrel(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v28, v198, v34;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_anegrel");
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
    v34 = v0;
/* end of prologue */
    v198 = v34;
    v28 = elt(env, 1); /* ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong)) 
*/
    v28 = Latsoc(nil, v198, v28);
    v28 = qcdr(v28);
    if (!(v28 == nil)) { popv(1); return onevalue(v28); }
    v28 = qvalue(elt(env, 2)); /* !*protfg */
    if (!(v28 == nil)) goto v19;
    v28 = elt(env, 3); /* "pasf_anegrel: unknown operator " */
    v198 = v34;
    v28 = list2(v28, v198);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    fn = elt(env, 4); /* lprie */
    v28 = (*qfn1(fn))(qenv(fn), v28);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[0];
    goto v19;

v19:
    v28 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v10;
    v28 = nil;
    { popv(1); return onevalue(v28); }
/* error exit handlers */
v10:
    popv(1);
    return nil;
}



/* Code for ibalp_negateat */

static Lisp_Object CC_ibalp_negateat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_negateat");
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
    v19 = stack[-1];
    fn = elt(env, 1); /* ibalp_op */
    stack[-2] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v19 = stack[-1];
    fn = elt(env, 2); /* ibalp_arg2l */
    stack[0] = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    v19 = stack[-1];
    fn = elt(env, 3); /* ibalp_arg2r */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    fn = elt(env, 4); /* ibalp_negatet */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-3];
    {
        Lisp_Object v29 = stack[-2];
        Lisp_Object v30 = stack[0];
        popv(4);
        fn = elt(env, 5); /* ibalp_mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v29, v30, v19);
    }
/* error exit handlers */
v49:
    popv(4);
    return nil;
}



/* Code for rationalizesq */

static Lisp_Object CC_rationalizesq(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v103, v162;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rationalizesq");
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
    stack[-4] = qvalue(elt(env, 1)); /* !*structure */
    qvalue(elt(env, 1)) = nil; /* !*structure */
    stack[-2] = qvalue(elt(env, 2)); /* !*sub2 */
    qvalue(elt(env, 2)) = nil; /* !*sub2 */
    v162 = qvalue(elt(env, 3)); /* dmode!* */
    v103 = elt(env, 4); /* rationalizefn */
    v103 = get(v162, v103);
    env = stack[-5];
    stack[0] = v103;
    if (v103 == nil) goto v42;
    v162 = stack[0];
    v103 = stack[-3];
    v103 = Lapply1(nil, v162, v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[-3] = v103;
    goto v42;

v42:
    v162 = elt(env, 5); /* (i 2 (nil . t) -1 nil) */
    v103 = qvalue(elt(env, 6)); /* powlis!* */
    v103 = cons(v162, v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    qvalue(elt(env, 6)) = v103; /* powlis!* */
    v103 = stack[-3];
    fn = elt(env, 9); /* subs2q */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[-1] = v103;
    v103 = qvalue(elt(env, 6)); /* powlis!* */
    v103 = qcdr(v103);
    qvalue(elt(env, 6)) = v103; /* powlis!* */
    v103 = stack[-1];
    v103 = qcdr(v103);
    if (!consp(v103)) goto v7;
    v103 = stack[-1];
    v103 = qcdr(v103);
    v103 = qcar(v103);
    if (!consp(v103)) goto v7;
    v103 = stack[-1];
    v103 = qcdr(v103);
    fn = elt(env, 10); /* rationalizef */
    v162 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[0] = v162;
    v103 = (Lisp_Object)17; /* 1 */
    if (v162 == v103) goto v44;
    v103 = stack[-1];
    v162 = qcar(v103);
    v103 = stack[0];
    fn = elt(env, 11); /* multf */
    stack[-3] = (*qfn2(fn))(qenv(fn), v162, v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v103 = stack[-1];
    v162 = qcdr(v103);
    v103 = stack[0];
    fn = elt(env, 11); /* multf */
    v103 = (*qfn2(fn))(qenv(fn), v162, v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    v103 = cons(stack[-3], v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[-1] = v103;
    v103 = qvalue(elt(env, 7)); /* !*algint */
    if (!(v103 == nil)) goto v204;
    v103 = qvalue(elt(env, 8)); /* !*rationalize */
    if (!(v103 == nil)) goto v204;
    v103 = stack[-1];
    fn = elt(env, 12); /* gcdchk */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    stack[-1] = v103;
    goto v204;

v204:
    v103 = stack[-1];
    fn = elt(env, 9); /* subs2q */
    v103 = (*qfn1(fn))(qenv(fn), v103);
    nil = C_nil;
    if (exception_pending()) goto v203;
    env = stack[-5];
    goto v53;

v53:
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    { popv(6); return onevalue(v103); }

v44:
    v103 = stack[-3];
    goto v53;

v7:
    v103 = stack[-1];
    goto v53;
/* error exit handlers */
v203:
    env = stack[-5];
    qvalue(elt(env, 2)) = stack[-2]; /* !*sub2 */
    qvalue(elt(env, 1)) = stack[-4]; /* !*structure */
    popv(6);
    return nil;
}



/* Code for flatindl */

static Lisp_Object CC_flatindl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v31;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for flatindl");
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
    goto v107;

v107:
    v8 = stack[0];
    if (v8 == nil) goto v53;
    v8 = stack[0];
    v31 = qcar(v8);
    v8 = stack[-1];
    v8 = cons(v31, v8);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    stack[-1] = v8;
    v8 = stack[0];
    v8 = qcdr(v8);
    stack[0] = v8;
    goto v107;

v53:
    v8 = qvalue(elt(env, 1)); /* nil */
    v31 = v8;
    goto v54;

v54:
    v8 = stack[-1];
    if (v8 == nil) { popv(3); return onevalue(v31); }
    v8 = stack[-1];
    v8 = qcar(v8);
    v8 = Lappend(nil, v8, v31);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-2];
    v31 = v8;
    v8 = stack[-1];
    v8 = qcdr(v8);
    stack[-1] = v8;
    goto v54;
/* error exit handlers */
v22:
    popv(3);
    return nil;
}



/* Code for no!-side!-effect!-listp */

static Lisp_Object CC_noKsideKeffectKlistp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no-side-effect-listp");
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

v205:
    v41 = stack[0];
    v41 = (v41 == nil ? lisp_true : nil);
    if (!(v41 == nil)) { popv(2); return onevalue(v41); }
    v41 = stack[0];
    v41 = qcar(v41);
    fn = elt(env, 2); /* no!-side!-effectp */
    v41 = (*qfn1(fn))(qenv(fn), v41);
    nil = C_nil;
    if (exception_pending()) goto v29;
    env = stack[-1];
    if (v41 == nil) goto v55;
    v41 = stack[0];
    v41 = qcdr(v41);
    stack[0] = v41;
    goto v205;

v55:
    v41 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v41); }
/* error exit handlers */
v29:
    popv(2);
    return nil;
}



/* Code for groeb!=weight */

static Lisp_Object MS_CDECL CC_groebMweight(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v24,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "groeb=weight");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for groeb=weight");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v24,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v24;
    v29 = v0;
/* end of prologue */
    fn = elt(env, 1); /* mo_ecart */
    stack[-2] = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v29 = stack[-1];
    fn = elt(env, 2); /* bas_dpecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v29 = stack[0];
    fn = elt(env, 2); /* bas_dpecart */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-3];
    v29 = Lmin2(nil, stack[-1], v29);
    nil = C_nil;
    if (exception_pending()) goto v6;
    {
        Lisp_Object v21 = stack[-2];
        popv(4);
        return plus2(v21, v29);
    }
/* error exit handlers */
v6:
    popv(4);
    return nil;
}



/* Code for no_dum_varp */

static Lisp_Object CC_no_dum_varp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for no_dum_varp");
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
    v27 = stack[0];
    v27 = qcdr(v27);
    if (v27 == nil) goto v1;
    v27 = stack[0];
    v28 = qcdr(v27);
    v27 = elt(env, 1); /* list */
    fn = elt(env, 4); /* splitlist!: */
    v28 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-1];
    v27 = stack[0];
    v27 = qcdr(v27);
    if (equal(v28, v27)) goto v1;
    v27 = qvalue(elt(env, 3)); /* nil */
    { popv(2); return onevalue(v27); }

v1:
    v27 = qvalue(elt(env, 2)); /* t */
    { popv(2); return onevalue(v27); }
/* error exit handlers */
v34:
    popv(2);
    return nil;
}



/* Code for ad_numsort */

static Lisp_Object CC_ad_numsort(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ad_numsort");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v45 = v18;
    v18 = elt(env, 1); /* lambda_l9xqts_5 */
    {
        fn = elt(env, 2); /* sort */
        return (*qfn2(fn))(qenv(fn), v45, v18);
    }
}



/* Code for lambda_l9xqts_5 */

static Lisp_Object CC_lambda_l9xqts_5(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_l9xqts_5");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v45 = v24;
    v46 = v0;
/* end of prologue */
        return Lleq(nil, v46, v45);
}



/* Code for cl_identifyat */

static Lisp_Object CC_cl_identifyat(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v206, v207;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_identifyat");
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
    v207 = stack[0];
    v206 = elt(env, 1); /* true */
    if (v207 == v206) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v207 = stack[0];
    v206 = elt(env, 2); /* false */
    if (v207 == v206) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v207 = stack[0];
    v206 = qvalue(elt(env, 3)); /* cl_identify!-atl!* */
    v206 = Lmember(nil, v207, v206);
    v207 = v206;
    if (v206 == nil) goto v26;
    v206 = v207;
    v206 = qcar(v206);
    { popv(2); return onevalue(v206); }

v26:
    v207 = stack[0];
    v206 = qvalue(elt(env, 3)); /* cl_identify!-atl!* */
    v206 = cons(v207, v206);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    qvalue(elt(env, 3)) = v206; /* cl_identify!-atl!* */
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
/* error exit handlers */
v52:
    popv(2);
    return nil;
}



/* Code for ibalp_isinminclause */

static Lisp_Object CC_ibalp_isinminclause(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v211, v62;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_isinminclause");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v24;
    stack[-2] = v0;
/* end of prologue */
    stack[0] = nil;
    v211 = stack[-2];
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    stack[-3] = v211;
    goto v177;

v177:
    v211 = stack[-3];
    if (v211 == nil) goto v46;
    v211 = stack[0];
    if (!(v211 == nil)) goto v46;
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    if (!(v211 == nil)) goto v95;
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v62 = qcar(v211);
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    v62 = plus2(v62, v211);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v211 = stack[-1];
    v211 = Leqn(nil, v62, v211);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    if (v211 == nil) goto v95;
    v211 = qvalue(elt(env, 2)); /* t */
    stack[0] = v211;
    goto v95;

v95:
    v211 = stack[-3];
    v211 = qcdr(v211);
    stack[-3] = v211;
    goto v177;

v46:
    v211 = stack[-2];
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    stack[-3] = v211;
    goto v75;

v75:
    v211 = stack[-3];
    if (v211 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v211 = stack[0];
    if (!(v211 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    if (!(v211 == nil)) goto v66;
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v62 = qcar(v211);
    v211 = stack[-3];
    v211 = qcar(v211);
    v211 = qcdr(v211);
    v211 = qcdr(v211);
    v211 = qcar(v211);
    v62 = plus2(v62, v211);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    v211 = stack[-1];
    v211 = Leqn(nil, v62, v211);
    nil = C_nil;
    if (exception_pending()) goto v78;
    env = stack[-4];
    if (v211 == nil) goto v66;
    v211 = qvalue(elt(env, 2)); /* t */
    stack[0] = v211;
    goto v66;

v66:
    v211 = stack[-3];
    v211 = qcdr(v211);
    stack[-3] = v211;
    goto v75;
/* error exit handlers */
v78:
    popv(5);
    return nil;
}



/* Code for cgb_buch!-ev_divides!? */

static Lisp_Object CC_cgb_buchKev_dividesW(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v45, v46;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cgb_buch-ev_divides?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v24;
    v45 = v0;
/* end of prologue */
    {
        fn = elt(env, 1); /* ev_mtest!? */
        return (*qfn2(fn))(qenv(fn), v46, v45);
    }
}



/* Code for dipev2f */

static Lisp_Object CC_dipev2f(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v210, v202, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipev2f");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v24;
    stack[-1] = v0;
/* end of prologue */

v124:
    v210 = stack[-1];
    if (v210 == nil) goto v54;
    v210 = stack[-1];
    v202 = qcar(v210);
    v210 = (Lisp_Object)1; /* 0 */
    if (v202 == v210) goto v46;
    v210 = stack[0];
    v213 = qcar(v210);
    v210 = stack[-1];
    v202 = qcar(v210);
    v210 = (Lisp_Object)17; /* 1 */
    v210 = acons(v213, v202, v210);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    stack[-2] = ncons(v210);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    v210 = stack[-1];
    v202 = qcdr(v210);
    v210 = stack[0];
    v210 = qcdr(v210);
    v210 = CC_dipev2f(env, v202, v210);
    nil = C_nil;
    if (exception_pending()) goto v84;
    env = stack[-3];
    {
        Lisp_Object v13 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* multf */
        return (*qfn2(fn))(qenv(fn), v13, v210);
    }

v46:
    v210 = stack[-1];
    v210 = qcdr(v210);
    stack[-1] = v210;
    v210 = stack[0];
    v210 = qcdr(v210);
    stack[0] = v210;
    goto v124;

v54:
    v210 = (Lisp_Object)17; /* 1 */
    { popv(4); return onevalue(v210); }
/* error exit handlers */
v84:
    popv(4);
    return nil;
}



/* Code for bcneg */

static Lisp_Object CC_bcneg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v8, v31;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcneg");
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
    v8 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v8 == nil) goto v34;
    v31 = stack[0];
    v8 = (Lisp_Object)1; /* 0 */
    v8 = Leqn(nil, v31, v8);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-1];
    if (!(v8 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v31 = qvalue(elt(env, 2)); /* current!-modulus */
    v8 = stack[0];
    v8 = (Lisp_Object)(int32_t)((int32_t)v31 - (int32_t)v8 + TAG_FIXNUM);
    { popv(2); return onevalue(v8); }

v34:
    v8 = stack[0];
    v8 = qcar(v8);
    fn = elt(env, 3); /* negf */
    v31 = (*qfn1(fn))(qenv(fn), v8);
    nil = C_nil;
    if (exception_pending()) goto v33;
    v8 = stack[0];
    v8 = qcdr(v8);
    popv(2);
    return cons(v31, v8);
/* error exit handlers */
v33:
    popv(2);
    return nil;
}



/* Code for edge_new_parent */

static Lisp_Object CC_edge_new_parent(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v26, v7;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edge_new_parent");
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
    v26 = v0;
/* end of prologue */

v205:
    v99 = v26;
    if (v99 == nil) goto v1;
    v99 = v26;
    v7 = qcar(v99);
    v99 = qvalue(elt(env, 2)); /* new_edge_list */
    v99 = Lassoc(nil, v7, v99);
    v7 = v99;
    v99 = v7;
    if (v99 == nil) goto v11;
    stack[0] = v7;
    v99 = v26;
    v99 = qcdr(v99);
    v99 = CC_edge_new_parent(env, v99);
    nil = C_nil;
    if (exception_pending()) goto v31;
    {
        Lisp_Object v32 = stack[0];
        popv(1);
        return cons(v32, v99);
    }

v11:
    v99 = v26;
    v99 = qcdr(v99);
    v26 = v99;
    goto v205;

v1:
    v99 = qvalue(elt(env, 1)); /* nil */
    { popv(1); return onevalue(v99); }
/* error exit handlers */
v31:
    popv(1);
    return nil;
}



/* Code for !*di2q0 */

static Lisp_Object CC_Hdi2q0(Lisp_Object env,
                         Lisp_Object v24, Lisp_Object v4)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v160, v218, v60, v61;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *di2q0");
#endif
    if (stack >= stacklimit)
    {
        push2(v4,v24);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v24,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v160 = v4;
    stack[-3] = v24;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* varlist */
    qvalue(elt(env, 1)) = nil; /* varlist */
    qvalue(elt(env, 1)) = v160; /* varlist */
    stack[-2] = nil;
    goto v46;

v46:
    v160 = stack[-3];
    if (v160 == nil) goto v219;
    v160 = stack[-3];
    v160 = qcar(v160);
    stack[-1] = qcdr(v160);
    stack[0] = qvalue(elt(env, 1)); /* varlist */
    v218 = qvalue(elt(env, 2)); /* ordering */
    v160 = elt(env, 3); /* lex */
    if (v218 == v160) goto v171;
    v160 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    v160 = qcdr(v160);
    goto v34;

v34:
    fn = elt(env, 6); /* pair */
    v160 = (*qfn2(fn))(qenv(fn), stack[0], v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    v61 = stack[-1];
    stack[-1] = v160;
    goto v202;

v202:
    v160 = stack[-1];
    if (v160 == nil) goto v210;
    v160 = stack[-1];
    v160 = qcar(v160);
    v60 = v160;
    v160 = v60;
    v218 = qcdr(v160);
    v160 = (Lisp_Object)1; /* 0 */
    if (v218 == v160) goto v75;
    stack[0] = v61;
    v218 = v60;
    v160 = (Lisp_Object)17; /* 1 */
    v60 = cons(v218, v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    v218 = qvalue(elt(env, 4)); /* nil */
    v160 = (Lisp_Object)17; /* 1 */
    v160 = acons(v60, v218, v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    fn = elt(env, 7); /* multsq */
    v160 = (*qfn2(fn))(qenv(fn), stack[0], v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    v61 = v160;
    goto v75;

v75:
    v160 = stack[-1];
    v160 = qcdr(v160);
    stack[-1] = v160;
    goto v202;

v210:
    v218 = v61;
    v160 = stack[-2];
    v160 = cons(v218, v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    stack[-2] = v160;
    v160 = stack[-3];
    v160 = qcdr(v160);
    stack[-3] = v160;
    goto v46;

v171:
    v160 = stack[-3];
    fn = elt(env, 5); /* ljet */
    v160 = (*qfn1(fn))(qenv(fn), v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    goto v34;

v219:
    v218 = qvalue(elt(env, 4)); /* nil */
    v160 = (Lisp_Object)17; /* 1 */
    v160 = cons(v218, v160);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    v218 = v160;
    goto v178;

v178:
    v160 = stack[-2];
    if (v160 == nil) goto v211;
    v160 = stack[-2];
    v160 = qcar(v160);
    fn = elt(env, 8); /* addsq */
    v160 = (*qfn2(fn))(qenv(fn), v160, v218);
    nil = C_nil;
    if (exception_pending()) goto v220;
    env = stack[-5];
    v218 = v160;
    v160 = stack[-2];
    v160 = qcdr(v160);
    stack[-2] = v160;
    goto v178;

v211:
    v160 = v218;
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    { popv(6); return onevalue(v160); }
/* error exit handlers */
v220:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* varlist */
    popv(6);
    return nil;
}



/* Code for arglist_member */

static Lisp_Object CC_arglist_member(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v3;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for arglist_member");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v24;
    stack[-1] = v0;
/* end of prologue */

v205:
    v37 = stack[0];
    if (!consp(v37)) goto v124;
    v3 = stack[-1];
    v37 = stack[0];
    v37 = qcar(v37);
    v37 = (equal(v3, v37) ? lisp_true : nil);
    if (!(v37 == nil)) goto v12;
    v37 = stack[0];
    v37 = qcar(v37);
    if (!consp(v37)) goto v50;
    v3 = stack[-1];
    v37 = stack[0];
    v37 = qcar(v37);
    v37 = qcdr(v37);
    v37 = CC_arglist_member(env, v3, v37);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-2];
    goto v12;

v12:
    if (!(v37 == nil)) { popv(3); return onevalue(v37); }
    v3 = stack[-1];
    v37 = stack[0];
    v37 = qcdr(v37);
    stack[-1] = v3;
    stack[0] = v37;
    goto v205;

v50:
    v37 = qvalue(elt(env, 1)); /* nil */
    goto v12;

v124:
    v37 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v37); }
/* error exit handlers */
v210:
    popv(3);
    return nil;
}



/* Code for wupseudodivide */

static Lisp_Object MS_CDECL CC_wupseudodivide(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v24,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v234, v235;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "wupseudodivide");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wupseudodivide");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v24,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v4;
    stack[-3] = v24;
    stack[-4] = v0;
/* end of prologue */
    v234 = stack[-4];
    stack[0] = v234;
    v234 = stack[-1];
    v234 = ncons(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    fn = elt(env, 2); /* setkorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-5] = v234;
    v234 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-4] = v234;
    v234 = stack[-4];
    fn = elt(env, 4); /* wuconstantp */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    if (!(v234 == nil)) goto v49;
    v234 = stack[-4];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v235 = qcar(v234);
    v234 = stack[-1];
    if (!(equal(v235, v234))) goto v49;
    v234 = stack[-3];
    fn = elt(env, 3); /* reorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-3] = v234;
    v234 = stack[-3];
    fn = elt(env, 4); /* wuconstantp */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    if (!(v234 == nil)) goto v16;
    v234 = stack[-3];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v235 = qcar(v234);
    v234 = stack[-1];
    if (!(equal(v235, v234))) goto v16;
    v234 = stack[-4];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v234 = qcdr(v234);
    stack[-2] = v234;
    v234 = stack[-3];
    v234 = qcar(v234);
    v234 = qcar(v234);
    v234 = qcdr(v234);
    stack[-1] = v234;
    v235 = stack[-2];
    v234 = stack[-1];
    v234 = difference2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v235 = add1(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = (Lisp_Object)1; /* 0 */
    v234 = (Lisp_Object)lessp2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    v234 = v234 ? lisp_true : nil;
    env = stack[-6];
    if (v234 == nil) goto v161;
    v234 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v235 = qvalue(elt(env, 1)); /* nil */
    v234 = stack[0];
    popv(7);
    return cons(v235, v234);

v161:
    v234 = stack[-3];
    v234 = qcar(v234);
    v234 = qcdr(v234);
    stack[0] = v234;
    v235 = stack[-2];
    v234 = stack[-1];
    v234 = difference2(v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = add1(v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    fn = elt(env, 5); /* exptf */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[0] = v234;
    v235 = stack[0];
    v234 = stack[-4];
    fn = elt(env, 6); /* multf */
    v235 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = stack[-3];
    fn = elt(env, 7); /* qremf */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-1] = v234;
    v235 = stack[0];
    v234 = stack[-1];
    v234 = qcdr(v234);
    fn = elt(env, 8); /* gcdf!* */
    v235 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = stack[-1];
    v234 = qcar(v234);
    fn = elt(env, 8); /* gcdf!* */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-2] = v234;
    v234 = stack[-1];
    v235 = qcar(v234);
    v234 = stack[-2];
    fn = elt(env, 9); /* quotf */
    stack[0] = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = stack[-1];
    v235 = qcdr(v234);
    v234 = stack[-2];
    fn = elt(env, 9); /* quotf */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = cons(stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-1] = v234;
    v234 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = stack[-1];
    v234 = qcar(v234);
    fn = elt(env, 3); /* reorder */
    stack[0] = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = stack[-1];
    v234 = qcdr(v234);
    fn = elt(env, 3); /* reorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    {
        Lisp_Object v237 = stack[0];
        popv(7);
        return cons(v237, v234);
    }

v16:
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v234 = stack[-4];
    v234 = qcar(v234);
    v235 = qcdr(v234);
    v234 = stack[-3];
    fn = elt(env, 8); /* gcdf!* */
    v234 = (*qfn2(fn))(qenv(fn), v235, v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    fn = elt(env, 9); /* quotf */
    v234 = (*qfn2(fn))(qenv(fn), stack[0], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    fn = elt(env, 6); /* multf */
    v234 = (*qfn2(fn))(qenv(fn), stack[-1], v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    stack[-4] = v234;
    v234 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v234 = stack[-4];
    fn = elt(env, 3); /* reorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    popv(7);
    return ncons(v234);

v49:
    v234 = stack[-5];
    fn = elt(env, 2); /* setkorder */
    v234 = (*qfn1(fn))(qenv(fn), v234);
    nil = C_nil;
    if (exception_pending()) goto v236;
    env = stack[-6];
    v235 = qvalue(elt(env, 1)); /* nil */
    v234 = stack[0];
    popv(7);
    return cons(v235, v234);
/* error exit handlers */
v236:
    popv(7);
    return nil;
}



/* Code for taydegree!< */

static Lisp_Object CC_taydegreeR(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v202, v213;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for taydegree<");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v24;
    stack[-2] = v0;
/* end of prologue */

v53:
    v202 = stack[-2];
    v202 = qcar(v202);
    stack[-3] = v202;
    v202 = stack[-1];
    v202 = qcar(v202);
    stack[0] = v202;
    goto v38;

v38:
    v202 = stack[-3];
    v213 = qcar(v202);
    v202 = stack[0];
    v202 = qcar(v202);
    fn = elt(env, 3); /* tayexp!-greaterp */
    v202 = (*qfn2(fn))(qenv(fn), v213, v202);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    if (v202 == nil) goto v28;
    v202 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v202); }

v28:
    v202 = stack[-3];
    v213 = qcar(v202);
    v202 = stack[0];
    v202 = qcar(v202);
    fn = elt(env, 4); /* tayexp!-lessp */
    v202 = (*qfn2(fn))(qenv(fn), v213, v202);
    nil = C_nil;
    if (exception_pending()) goto v13;
    env = stack[-4];
    if (v202 == nil) goto v178;
    v202 = qvalue(elt(env, 2)); /* t */
    { popv(5); return onevalue(v202); }

v178:
    v202 = stack[-3];
    v202 = qcdr(v202);
    stack[-3] = v202;
    v202 = stack[0];
    v202 = qcdr(v202);
    stack[0] = v202;
    v202 = stack[-3];
    if (!(v202 == nil)) goto v38;
    v202 = stack[-2];
    v202 = qcdr(v202);
    stack[-2] = v202;
    v202 = stack[-1];
    v202 = qcdr(v202);
    stack[-1] = v202;
    v202 = stack[-2];
    if (!(v202 == nil)) goto v53;
    v202 = nil;
    { popv(5); return onevalue(v202); }
/* error exit handlers */
v13:
    popv(5);
    return nil;
}



/* Code for ibalp_var!-set */

static Lisp_Object MS_CDECL CC_ibalp_varKset(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v24,
                         Lisp_Object v4, Lisp_Object v5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "ibalp_var-set");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_var-set");
#endif
    if (stack >= stacklimit)
    {
        push4(v5,v4,v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v24,v4,v5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v5;
    stack[-1] = v4;
    stack[-2] = v24;
    stack[-3] = v0;
/* end of prologue */
    v87 = stack[-3];
    v239 = qcdr(v87);
    v87 = stack[-2];
    fn = elt(env, 1); /* setcar */
    v87 = (*qfn2(fn))(qenv(fn), v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v239 = qcdr(v87);
    v87 = stack[-1];
    fn = elt(env, 1); /* setcar */
    v87 = (*qfn2(fn))(qenv(fn), v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v239 = qcdr(v87);
    v87 = stack[0];
    fn = elt(env, 1); /* setcar */
    v87 = (*qfn2(fn))(qenv(fn), v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v87 = stack[-3];
    v87 = qcar(v87);
    stack[0] = v87;
    v239 = stack[-2];
    v87 = (Lisp_Object)1; /* 0 */
    v87 = Leqn(nil, v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    if (v87 == nil) goto v15;
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcar(v87);
    goto v196;

v196:
    v239 = v87;
    v87 = stack[0];
    fn = elt(env, 2); /* ibalp_var!-satlist */
    v87 = (*qfn2(fn))(qenv(fn), v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v239 = stack[-2];
    v87 = (Lisp_Object)17; /* 1 */
    v87 = Leqn(nil, v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    if (v87 == nil) goto v91;
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcar(v87);
    goto v161;

v161:
    v239 = v87;
    v87 = stack[-2];
    fn = elt(env, 3); /* ibalp_var!-unsatlist */
    v87 = (*qfn2(fn))(qenv(fn), v239, v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    v87 = stack[-3];
    fn = elt(env, 4); /* ibalp_var!-wclist */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    stack[-1] = v87;
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    stack[0] = qcdr(v87);
    v87 = stack[-3];
    fn = elt(env, 5); /* ibalp_calcmom */
    v87 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    env = stack[-4];
    fn = elt(env, 1); /* setcar */
    v87 = (*qfn2(fn))(qenv(fn), stack[0], v87);
    nil = C_nil;
    if (exception_pending()) goto v61;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v91:
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcar(v87);
    goto v161;

v15:
    v87 = stack[-3];
    v87 = qcdr(v87);
    v87 = qcdr(v87);
    v87 = qcar(v87);
    goto v196;
/* error exit handlers */
v61:
    popv(5);
    return nil;
}



/* Code for unaryrd */

static Lisp_Object MS_CDECL CC_unaryrd(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "unaryrd");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for unaryrd");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    fn = elt(env, 1); /* mathml */
    v54 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v18;
    env = stack[-1];
    stack[0] = v54;
    fn = elt(env, 2); /* lex */
    v54 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v18;
    v54 = stack[0];
    popv(2);
    return ncons(v54);
/* error exit handlers */
v18:
    popv(2);
    return nil;
}



/* Code for freeindexchk */

static Lisp_Object CC_freeindexchk(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for freeindexchk");
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
    v38 = v0;
/* end of prologue */
    v19 = v38;
    if (v19 == nil) goto v178;
    v19 = qvalue(elt(env, 1)); /* indxl!* */
    if (v19 == nil) goto v178;
    v19 = v38;
    fn = elt(env, 4); /* indxchk */
    v19 = (*qfn1(fn))(qenv(fn), v19);
    nil = C_nil;
    if (exception_pending()) goto v47;
    env = stack[0];
    if (v19 == nil) goto v178;
    v19 = elt(env, 2); /* form!-with!-free!-indices */
    { popv(1); return onevalue(v19); }

v178:
    v19 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v19); }
/* error exit handlers */
v47:
    popv(1);
    return nil;
}



/* Code for pfordp */

static Lisp_Object CC_pfordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v212, v210, v202;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pfordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v212 = v24;
    v210 = v0;
/* end of prologue */

v124:
    v2 = v210;
    if (v2 == nil) goto v54;
    v2 = v212;
    if (v2 == nil) goto v20;
    v2 = v210;
    v2 = qcar(v2);
    v202 = qcar(v2);
    v2 = v212;
    v2 = qcar(v2);
    v2 = qcar(v2);
    if (v202 == v2) goto v207;
    v2 = v210;
    v2 = qcar(v2);
    v2 = qcar(v2);
    v212 = qcar(v212);
    v212 = qcar(v212);
    {
        fn = elt(env, 2); /* termordp */
        return (*qfn2(fn))(qenv(fn), v2, v212);
    }

v207:
    v2 = v210;
    v2 = qcdr(v2);
    v210 = v2;
    v2 = v212;
    v2 = qcdr(v2);
    v212 = v2;
    goto v124;

v20:
    v2 = v210;
    v2 = qcar(v2);
    v212 = qcar(v2);
    v2 = (Lisp_Object)17; /* 1 */
        return Lneq(nil, v212, v2);

v54:
    v2 = qvalue(elt(env, 1)); /* nil */
    return onevalue(v2);
}



/* Code for fl2bf */

static Lisp_Object CC_fl2bf(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v33, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fl2bf");
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
    v33 = v0;
/* end of prologue */
    fn = elt(env, 3); /* frexp */
    v33 = (*qfn1(fn))(qenv(fn), v33);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-2] = v33;
    v33 = stack[-2];
    v33 = qcdr(v33);
    v22 = stack[-2];
    v22 = qcar(v22);
    stack[-2] = v22;
    stack[0] = v33;
    v22 = (Lisp_Object)33; /* 2 */
    v33 = qvalue(elt(env, 1)); /* !!nbfpd */
    v33 = Lexpt(nil, v22, v33);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v33 = times2(stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v33 = Ltruncate(nil, v33);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    stack[-1] = elt(env, 2); /* !:rd!: */
    stack[0] = v33;
    v22 = stack[-2];
    v33 = qvalue(elt(env, 1)); /* !!nbfpd */
    v33 = difference2(v22, v33);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    v33 = list2star(stack[-1], stack[0], v33);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-3];
    {
        popv(4);
        fn = elt(env, 4); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v33);
    }
/* error exit handlers */
v51:
    popv(4);
    return nil;
}



/* Code for chkint!* */

static Lisp_Object CC_chkintH(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v241, v242, v203;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for chkint*");
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
    v241 = qvalue(elt(env, 1)); /* !*!*roundbf */
    if (v241 == nil) goto v8;
    v241 = stack[0];
    v241 = Lfloatp(nil, v241);
    env = stack[-1];
    if (v241 == nil) goto v12;
    v241 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v12:
    v241 = stack[0];
    if (!consp(v241)) goto v49;
    v241 = stack[0];
    goto v47;

v47:
    {
        popv(2);
        fn = elt(env, 5); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v49:
    v241 = stack[0];
    v241 = integerp(v241);
    if (v241 == nil) goto v25;
    v203 = elt(env, 2); /* !:rd!: */
    v242 = stack[0];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = list2star(v203, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    goto v47;

v25:
    v241 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    goto v47;

v8:
    v241 = stack[0];
    v241 = Labsval(nil, v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v242 = v241;
    v241 = stack[0];
    v241 = Lfloatp(nil, v241);
    env = stack[-1];
    if (!(v241 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    v241 = v242;
    fn = elt(env, 7); /* msd */
    v242 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v241 = qvalue(elt(env, 3)); /* !!maxbflexp */
    v241 = (Lisp_Object)lesseq2(v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    v241 = v241 ? lisp_true : nil;
    env = stack[-1];
    if (v241 == nil) goto v16;
    v241 = stack[0];
        popv(2);
        return Lfloat(nil, v241);

v16:
    fn = elt(env, 8); /* rndbfon */
    v241 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    v241 = stack[0];
    v241 = Lfloatp(nil, v241);
    env = stack[-1];
    if (v241 == nil) goto v163;
    v241 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); /* fl2bf */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v163:
    v241 = stack[0];
    if (!consp(v241)) goto v165;
    v241 = stack[0];
    goto v67;

v67:
    {
        popv(2);
        fn = elt(env, 5); /* csl_normbf */
        return (*qfn1(fn))(qenv(fn), v241);
    }

v165:
    v241 = stack[0];
    v241 = integerp(v241);
    if (v241 == nil) goto v162;
    v203 = elt(env, 2); /* !:rd!: */
    v242 = stack[0];
    v241 = (Lisp_Object)1; /* 0 */
    v241 = list2star(v203, v242, v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    goto v67;

v162:
    v241 = stack[0];
    fn = elt(env, 6); /* read!:num */
    v241 = (*qfn1(fn))(qenv(fn), v241);
    nil = C_nil;
    if (exception_pending()) goto v65;
    env = stack[-1];
    goto v67;
/* error exit handlers */
v65:
    popv(2);
    return nil;
}



/* Code for coposp */

static Lisp_Object CC_coposp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29, v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for coposp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v30 = v0;
/* end of prologue */
    v29 = v30;
    v29 = qcdr(v29);
    v29 = (v29 == nil ? lisp_true : nil);
    if (!(v29 == nil)) return onevalue(v29);
    v29 = v30;
    v29 = qcar(v29);
    if (!consp(v29)) goto v18;
    v29 = v30;
    v29 = qcdr(v29);
    {
        fn = elt(env, 1); /* covposp */
        return (*qfn1(fn))(qenv(fn), v29);
    }

v18:
    v29 = v30;
    v29 = qcdr(v29);
    {
        fn = elt(env, 2); /* contposp */
        return (*qfn1(fn))(qenv(fn), v29);
    }
}



/* Code for comblog */

static Lisp_Object CC_comblog(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v209, v208;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for comblog");
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
    stack[0] = v0;
/* end of prologue */
    stack[-1] = nil;
    goto v124;

v124:
    v209 = stack[0];
    if (!consp(v209)) goto v30;
    v209 = stack[0];
    v208 = qcar(v209);
    v209 = qvalue(elt(env, 1)); /* domainlist!* */
    v209 = Lmemq(nil, v208, v209);
    if (!(v209 == nil)) goto v30;
    v209 = stack[0];
    v208 = qcar(v209);
    v209 = elt(env, 2); /* plus */
    if (v208 == v209) goto v92;
    v209 = stack[0];
    v208 = qcar(v209);
    v209 = elt(env, 3); /* times */
    if (!(v208 == v209)) goto v161;
    v209 = stack[0];
    fn = elt(env, 6); /* simp!* */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    v209 = qcar(v209);
    v208 = v209;
    v209 = v208;
    if (!consp(v209)) goto v210;
    v209 = v208;
    v209 = qcar(v209);
    if (!consp(v209)) goto v210;
    v209 = v208;
    v209 = qcar(v209);
    v209 = qcar(v209);
    v208 = qcar(v209);
    v209 = elt(env, 5); /* log */
    v209 = Leqcar(nil, v208, v209);
    env = stack[-3];
    goto v212;

v212:
    if (!(v209 == nil)) goto v92;

v161:
    v209 = stack[0];
    v209 = qcar(v209);
    v208 = CC_comblog(env, v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    v209 = stack[-1];
    v209 = cons(v208, v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    stack[-1] = v209;
    v209 = stack[0];
    v209 = qcdr(v209);
    stack[0] = v209;
    goto v124;

v92:
    stack[-2] = stack[-1];
    v209 = stack[0];
    fn = elt(env, 6); /* simp!* */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    stack[-1] = v209;
    v209 = stack[-1];
    v209 = qcar(v209);
    fn = elt(env, 7); /* clogf */
    stack[0] = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    v209 = stack[-1];
    v209 = qcdr(v209);
    fn = elt(env, 7); /* clogf */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    v209 = cons(stack[0], v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    fn = elt(env, 8); /* prepsq!* */
    v209 = (*qfn1(fn))(qenv(fn), v209);
    nil = C_nil;
    if (exception_pending()) goto v232;
    env = stack[-3];
    {
        Lisp_Object v233 = stack[-2];
        popv(4);
        fn = elt(env, 9); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v233, v209);
    }

v210:
    v209 = qvalue(elt(env, 4)); /* nil */
    goto v212;

v30:
    v208 = stack[-1];
    v209 = stack[0];
    {
        popv(4);
        fn = elt(env, 9); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v208, v209);
    }
/* error exit handlers */
v232:
    popv(4);
    return nil;
}



/* Code for mkprogn */

static Lisp_Object CC_mkprogn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v99, v26, v7, v8;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mkprogn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v7 = v24;
    v8 = v0;
/* end of prologue */
    v26 = v7;
    v99 = elt(env, 1); /* progn */
    if (!consp(v26)) goto v27;
    v26 = qcar(v26);
    if (!(v26 == v99)) goto v27;
    v99 = elt(env, 1); /* progn */
    v26 = v8;
    v7 = qcdr(v7);
    return list2star(v99, v26, v7);

v27:
    v99 = elt(env, 1); /* progn */
    v26 = v8;
    return list3(v99, v26, v7);
}



/* Code for lengthcdr */

static Lisp_Object CC_lengthcdr(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v124;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lengthcdr");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v124 = v0;
/* end of prologue */
    v124 = qcdr(v124);
        return Llength(nil, v124);
}



/* Code for changearg */

static Lisp_Object MS_CDECL CC_changearg(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v24,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v23, v195;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "changearg");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for changearg");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v24,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v24;
    stack[-2] = v0;
/* end of prologue */
    stack[-3] = nil;
    goto v53;

v53:
    v75 = stack[0];
    if (!consp(v75)) goto v178;
    v75 = stack[0];
    v23 = qcar(v75);
    v75 = stack[-2];
    v75 = Lmemq(nil, v23, v75);
    if (v75 == nil) goto v212;
    stack[-2] = stack[-3];
    v75 = stack[0];
    v23 = qcar(v75);
    v75 = stack[-1];
    v75 = cons(v23, v75);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    {
        Lisp_Object v163 = stack[-2];
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v163, v75);
    }

v212:
    v195 = stack[-2];
    v23 = stack[-1];
    v75 = stack[0];
    v75 = qcar(v75);
    v23 = CC_changearg(env, 3, v195, v23, v75);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    v75 = stack[-3];
    v75 = cons(v23, v75);
    nil = C_nil;
    if (exception_pending()) goto v199;
    env = stack[-4];
    stack[-3] = v75;
    v75 = stack[0];
    v75 = qcdr(v75);
    stack[0] = v75;
    goto v53;

v178:
    v23 = stack[-3];
    v75 = stack[0];
    {
        popv(5);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v23, v75);
    }
/* error exit handlers */
v199:
    popv(5);
    return nil;
}



/* Code for copy!-tree */

static Lisp_Object CC_copyKtree(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v165, v76, v244, v204;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for copy-tree");
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
    v165 = stack[-2];
    if (v165 == nil) goto v1;
    v165 = (Lisp_Object)49; /* 3 */
    v165 = Lmkvect(nil, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    env = stack[-4];
    stack[-3] = v165;
    v204 = stack[-3];
    v244 = (Lisp_Object)1; /* 0 */
    v76 = stack[-2];
    v165 = (Lisp_Object)1; /* 0 */
    v165 = *(Lisp_Object *)((char *)v76 + (CELL-TAG_VECTOR) + ((int32_t)v165/(16/CELL)));
    *(Lisp_Object *)((char *)v204 + (CELL-TAG_VECTOR) + ((int32_t)v244/(16/CELL))) = v165;
    v204 = stack[-3];
    v244 = (Lisp_Object)17; /* 1 */
    v76 = stack[-2];
    v165 = (Lisp_Object)17; /* 1 */
    v165 = *(Lisp_Object *)((char *)v76 + (CELL-TAG_VECTOR) + ((int32_t)v165/(16/CELL)));
    *(Lisp_Object *)((char *)v204 + (CELL-TAG_VECTOR) + ((int32_t)v244/(16/CELL))) = v165;
    v204 = stack[-3];
    v244 = (Lisp_Object)33; /* 2 */
    v76 = stack[-2];
    v165 = (Lisp_Object)33; /* 2 */
    v165 = *(Lisp_Object *)((char *)v76 + (CELL-TAG_VECTOR) + ((int32_t)v165/(16/CELL)));
    *(Lisp_Object *)((char *)v204 + (CELL-TAG_VECTOR) + ((int32_t)v244/(16/CELL))) = v165;
    stack[-1] = stack[-3];
    stack[0] = (Lisp_Object)49; /* 3 */
    v76 = stack[-2];
    v165 = (Lisp_Object)49; /* 3 */
    v165 = *(Lisp_Object *)((char *)v76 + (CELL-TAG_VECTOR) + ((int32_t)v165/(16/CELL)));
    v165 = CC_copyKtree(env, v165);
    nil = C_nil;
    if (exception_pending()) goto v166;
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v165;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

v1:
    v165 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v165); }
/* error exit handlers */
v166:
    popv(5);
    return nil;
}



/* Code for red!=cancelsimp */

static Lisp_Object CC_redMcancelsimp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27, v28;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red=cancelsimp");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v24;
    stack[-1] = v0;
/* end of prologue */
    v28 = stack[-1];
    v27 = stack[0];
    fn = elt(env, 2); /* red_better */
    v27 = (*qfn2(fn))(qenv(fn), v28, v27);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    if (v27 == nil) goto v124;
    v27 = stack[-1];
    fn = elt(env, 3); /* bas_dpoly */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    fn = elt(env, 4); /* dp_lmon */
    stack[-1] = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    v27 = stack[0];
    fn = elt(env, 3); /* bas_dpoly */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    fn = elt(env, 4); /* dp_lmon */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v10;
    env = stack[-2];
    {
        Lisp_Object v11 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* mo_vdivides!? */
        return (*qfn2(fn))(qenv(fn), v11, v27);
    }

v124:
    v27 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v27); }
/* error exit handlers */
v10:
    popv(3);
    return nil;
}



/* Code for get!-free!-form */

static Lisp_Object CC_getKfreeKform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v201, v199, v163;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-free-form");
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
    stack[-2] = nil;
    v199 = stack[-1];
    v201 = qvalue(elt(env, 1)); /* frasc!* */
    v201 = Latsoc(nil, v199, v201);
    stack[0] = v201;
    if (v201 == nil) goto v9;
    v201 = stack[0];
    v201 = qcdr(v201);
    { popv(4); return onevalue(v201); }

v9:
    v199 = stack[-1];
    v201 = elt(env, 2); /* !~ */
    if (!consp(v199)) goto v43;
    v199 = qcar(v199);
    if (!(v199 == v201)) goto v43;
    v201 = stack[-1];
    v201 = qcdr(v201);
    v201 = qcar(v201);
    stack[-1] = v201;
    v201 = elt(env, 3); /* (!! !~ !! !~) */
    stack[0] = v201;
    v201 = qvalue(elt(env, 4)); /* t */
    stack[-2] = v201;
    goto v32;

v32:
    v201 = stack[-1];
    v201 = Lexplode(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v201 = Lappend(nil, stack[0], v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v201 = Lcompress(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v201 = Lintern(nil, v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    stack[0] = v201;
    v163 = stack[-1];
    v199 = stack[0];
    v201 = qvalue(elt(env, 1)); /* frasc!* */
    v201 = acons(v163, v199, v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    qvalue(elt(env, 1)) = v201; /* frasc!* */
    v201 = stack[-2];
    if (v201 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v201 = stack[0];
    v199 = ncons(v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    env = stack[-3];
    v201 = elt(env, 6); /* optional */
    v201 = Lflag(nil, v199, v201);
    nil = C_nil;
    if (exception_pending()) goto v67;
    { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }

v43:
    v201 = elt(env, 5); /* (!! !~) */
    stack[0] = v201;
    goto v32;
/* error exit handlers */
v67:
    popv(4);
    return nil;
}



/* Code for tayexp!-times2 */

static Lisp_Object CC_tayexpKtimes2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v70, v71;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tayexp-times2");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v24;
    stack[-1] = v0;
/* end of prologue */
    v69 = stack[-1];
    if (!(!consp(v69))) goto v47;
    v69 = stack[0];
    if (!(!consp(v69))) goto v47;
    v70 = stack[-1];
    v69 = stack[0];
    popv(4);
    return times2(v70, v69);

v47:
    v69 = stack[-1];
    if (!consp(v69)) goto v21;
    v69 = stack[0];
    if (!consp(v69)) goto v23;
    v69 = stack[-1];
    v69 = qcdr(v69);
    v70 = qcar(v69);
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcar(v69);
    stack[-2] = times2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v69 = stack[-1];
    v69 = qcdr(v69);
    v70 = qcdr(v69);
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = times2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    fn = elt(env, 2); /* mkrn */
    v69 = (*qfn2(fn))(qenv(fn), stack[-2], v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    goto v29;

v29:
    v71 = v69;
    v69 = v71;
    v69 = qcdr(v69);
    v70 = qcdr(v69);
    v69 = (Lisp_Object)17; /* 1 */
    if (!(v70 == v69)) { popv(4); return onevalue(v71); }
    v69 = v71;
    v69 = qcdr(v69);
    v69 = qcar(v69);
    { popv(4); return onevalue(v69); }

v23:
    v71 = elt(env, 1); /* !:rn!: */
    v70 = stack[0];
    v69 = (Lisp_Object)17; /* 1 */
    v69 = list2star(v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    stack[-2] = v69;
    v69 = stack[-1];
    v69 = qcdr(v69);
    v70 = qcar(v69);
    v69 = stack[-2];
    v69 = qcdr(v69);
    v69 = qcar(v69);
    stack[0] = times2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v69 = stack[-1];
    v69 = qcdr(v69);
    v70 = qcdr(v69);
    v69 = stack[-2];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = times2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    fn = elt(env, 2); /* mkrn */
    v69 = (*qfn2(fn))(qenv(fn), stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    goto v29;

v21:
    v71 = elt(env, 1); /* !:rn!: */
    v70 = stack[-1];
    v69 = (Lisp_Object)17; /* 1 */
    v69 = list2star(v71, v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    stack[-2] = v69;
    v69 = stack[-2];
    v69 = qcdr(v69);
    v70 = qcar(v69);
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcar(v69);
    stack[-1] = times2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    v69 = stack[-2];
    v69 = qcdr(v69);
    v70 = qcdr(v69);
    v69 = stack[0];
    v69 = qcdr(v69);
    v69 = qcdr(v69);
    v69 = times2(v70, v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    env = stack[-3];
    fn = elt(env, 2); /* mkrn */
    v69 = (*qfn2(fn))(qenv(fn), stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v97;
    goto v29;
/* error exit handlers */
v97:
    popv(4);
    return nil;
}



/* Code for get_char_value */

static Lisp_Object CC_get_char_value(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v75, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get_char_value");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v24;
    v23 = v0;
/* end of prologue */
    stack[-1] = nil;
    v75 = qvalue(elt(env, 1)); /* nil */
    stack[-3] = v75;
    v75 = v23;
    v75 = qcdr(v75);
    stack[0] = v75;
    goto v177;

v177:
    v75 = stack[-3];
    if (!(v75 == nil)) goto v46;
    v75 = stack[0];
    v23 = Llength(nil, v75);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    v75 = (Lisp_Object)1; /* 0 */
    v75 = (Lisp_Object)greaterp2(v23, v75);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v75 = v75 ? lisp_true : nil;
    env = stack[-4];
    if (v75 == nil) goto v46;
    v75 = stack[0];
    v75 = qcar(v75);
    v23 = qcar(v75);
    v75 = stack[-2];
    if (!(equal(v23, v75))) goto v198;
    v75 = stack[0];
    v75 = qcar(v75);
    v75 = qcdr(v75);
    v75 = qcar(v75);
    stack[-1] = v75;
    v75 = qvalue(elt(env, 2)); /* t */
    stack[-3] = v75;
    goto v198;

v198:
    v75 = stack[0];
    v75 = qcdr(v75);
    stack[0] = v75;
    goto v177;

v46:
    v75 = stack[-3];
    if (!(v75 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v75 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v75 == nil)) goto v84;
    v75 = elt(env, 4); /* "error in get character element" */
    fn = elt(env, 5); /* lprie */
    v75 = (*qfn1(fn))(qenv(fn), v75);
    nil = C_nil;
    if (exception_pending()) goto v201;
    env = stack[-4];
    goto v84;

v84:
    v75 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v201;
    v75 = nil;
    { popv(5); return onevalue(v75); }
/* error exit handlers */
v201:
    popv(5);
    return nil;
}



/* Code for cl_sacatl */

static Lisp_Object MS_CDECL CC_cl_sacatl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v24,
                         Lisp_Object v4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v243, v219;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "cl_sacatl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cl_sacatl");
#endif
    if (stack >= stacklimit)
    {
        push3(v4,v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v24,v4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v4;
    stack[-1] = v24;
    stack[-2] = v0;
/* end of prologue */

v205:
    v88 = stack[-1];
    if (v88 == nil) goto v55;
    v243 = stack[-2];
    v88 = stack[-1];
    fn = elt(env, 6); /* rl_sacatlp */
    v88 = (*qfn2(fn))(qenv(fn), v243, v88);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    if (v88 == nil) goto v6;
    v219 = stack[-2];
    v88 = stack[-1];
    v243 = qcar(v88);
    v88 = stack[0];
    fn = elt(env, 7); /* rl_sacat */
    v88 = (*qfnn(fn))(qenv(fn), 3, v219, v243, v88);
    nil = C_nil;
    if (exception_pending()) goto v246;
    env = stack[-3];
    v219 = v88;
    v88 = v219;
    if (v88 == nil) goto v51;
    v243 = v219;
    v88 = elt(env, 3); /* (keep1 keep) */
    v88 = Lmemq(nil, v243, v88);
    if (v88 == nil) goto v244;
    v243 = elt(env, 4); /* keep1 */
    v88 = stack[-1];
    v88 = qcdr(v88);
    popv(4);
    return cons(v243, v88);

v244:
    v243 = v219;
    v88 = elt(env, 5); /* keep2 */
    if (v243 == v88) goto v40;
    v243 = v219;
    v88 = stack[-1];
    v88 = qcdr(v88);
    popv(4);
    return cons(v243, v88);

v40:
    v243 = qvalue(elt(env, 2)); /* nil */
    v88 = stack[-1];
    v88 = qcdr(v88);
    popv(4);
    return cons(v243, v88);

v51:
    v219 = stack[-2];
    v88 = stack[-1];
    v243 = qcdr(v88);
    v88 = stack[0];
    stack[-2] = v219;
    stack[-1] = v243;
    stack[0] = v88;
    goto v205;

v6:
    v243 = qvalue(elt(env, 2)); /* nil */
    v88 = stack[-1];
    popv(4);
    return cons(v243, v88);

v55:
    v88 = elt(env, 1); /* (nil) */
    { popv(4); return onevalue(v88); }
/* error exit handlers */
v246:
    popv(4);
    return nil;
}



/* Code for om2ir */

static Lisp_Object MS_CDECL CC_om2ir(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v16, v17;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "om2ir");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for om2ir");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* end of prologue */
    v16 = qvalue(elt(env, 1)); /* nil */
    stack[0] = v16;
    v16 = elt(env, 2); /* (safe_atts char ch atts count temp space temp2) 
*/
    fn = elt(env, 13); /* fluid */
    v16 = (*qfn1(fn))(qenv(fn), v16);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v17 = elt(env, 3); /* !! */
    v16 = (Lisp_Object)513; /* 32 */
    v16 = list2(v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v16 = Lcompress(nil, v16);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    qvalue(elt(env, 4)) = v16; /* space */
    v16 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 5)) = v16; /* count */
    v16 = Lreadch(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    qvalue(elt(env, 6)) = v16; /* ch */
    v16 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 7)) = v16; /* temp2 */
    fn = elt(env, 14); /* lex */
    v16 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v17 = qvalue(elt(env, 8)); /* char */
    v16 = elt(env, 9); /* (o m o b j) */
    if (equal(v17, v16)) goto v29;
    v17 = elt(env, 10); /* "<omobj>" */
    v16 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 15); /* errorml */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    goto v49;

v49:
    fn = elt(env, 14); /* lex */
    v16 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    v17 = qvalue(elt(env, 8)); /* char */
    v16 = elt(env, 11); /* (!/ o m o b j) */
    if (equal(v17, v16)) goto v22;
    v17 = elt(env, 12); /* "</omobj>" */
    v16 = (Lisp_Object)305; /* 19 */
    fn = elt(env, 15); /* errorml */
    v16 = (*qfn2(fn))(qenv(fn), v17, v16);
    nil = C_nil;
    if (exception_pending()) goto v75;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v22:
    v16 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }

v29:
    fn = elt(env, 14); /* lex */
    v16 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    fn = elt(env, 16); /* omobj */
    v16 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-1];
    stack[0] = v16;
    goto v49;
/* error exit handlers */
v75:
    popv(2);
    return nil;
}



/* Code for initarg */

static Lisp_Object CC_initarg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v255, v221;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for initarg");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v0;
/* end of prologue */
    v221 = qvalue(elt(env, 1)); /* op */
    v255 = elt(env, 2); /* symmetric */
    v255 = Lflagp(nil, v221, v255);
    env = stack[-6];
    qvalue(elt(env, 3)) = v255; /* symm */
    v255 = qvalue(elt(env, 4)); /* p */
    stack[0] = Llength(nil, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v255 = qvalue(elt(env, 5)); /* r */
    v255 = Llength(nil, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v255 = difference2(stack[0], v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v255 = add1(v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    stack[-1] = v255;
    v255 = qvalue(elt(env, 1)); /* op */
    fn = elt(env, 16); /* ident */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    qvalue(elt(env, 6)) = v255; /* identity */
    v255 = qvalue(elt(env, 5)); /* r */
    v255 = qcar(v255);
    fn = elt(env, 17); /* mgenp */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    stack[-3] = v255;
    v255 = qvalue(elt(env, 5)); /* r */
    v255 = qcdr(v255);
    fn = elt(env, 18); /* list!-mgen */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    stack[0] = v255;
    v221 = qvalue(elt(env, 1)); /* op */
    v255 = elt(env, 7); /* assoc */
    v255 = Lflagp(nil, v221, v255);
    env = stack[-6];
    if (v255 == nil) goto v26;
    v255 = qvalue(elt(env, 3)); /* symm */
    if (v255 == nil) goto v2;
    v221 = stack[0];
    v255 = (Lisp_Object)1; /* 0 */
    v255 = (Lisp_Object)greaterp2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v255 = v255 ? lisp_true : nil;
    env = stack[-6];
    if (v255 == nil) goto v213;
    v255 = qvalue(elt(env, 9)); /* !*sym!-assoc */
    v255 = (v255 == nil ? lisp_true : nil);
    goto v3;

v3:
    v255 = (v255 == nil ? lisp_true : nil);
    goto v99;

v99:
    stack[-5] = v255;
    v255 = qvalue(elt(env, 5)); /* r */
    v221 = Llength(nil, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v255 = (Lisp_Object)17; /* 1 */
    v255 = (Lisp_Object)greaterp2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v255 = v255 ? lisp_true : nil;
    env = stack[-6];
    if (v255 == nil) goto v199;
    v255 = stack[-5];
    if (!(v255 == nil)) goto v201;
    v255 = stack[0];
    goto v201;

v201:
    stack[-2] = v255;
    v221 = stack[-1];
    v255 = (Lisp_Object)17; /* 1 */
    v255 = (Lisp_Object)greaterp2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v255 = v255 ? lisp_true : nil;
    env = stack[-6];
    if (!(v255 == nil)) goto v91;
    v255 = qvalue(elt(env, 6)); /* identity */
    if (v255 == nil) goto v64;
    v255 = qvalue(elt(env, 4)); /* p */
    v221 = Llength(nil, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    v255 = (Lisp_Object)1; /* 0 */
    v255 = (Lisp_Object)greaterp2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v255 = v255 ? lisp_true : nil;
    env = stack[-6];
    goto v91;

v91:
    v221 = v255;
    v255 = stack[-3];
    if (v255 == nil) goto v257;
    v255 = v221;
    goto v104;

v104:
    qvalue(elt(env, 10)) = v255; /* mcontract */
    v255 = stack[-5];
    if (v255 == nil) goto v239;
    v255 = v221;
    if (v255 == nil) goto v60;
    v255 = stack[-3];
    v255 = (v255 == nil ? lisp_true : nil);
    goto v87;

v87:
    qvalue(elt(env, 11)) = v255; /* acontract */
    v255 = qvalue(elt(env, 6)); /* identity */
    if (v255 == nil) goto v258;
    v221 = stack[-1];
    v255 = (Lisp_Object)17; /* 1 */
    v255 = (Lisp_Object)lessp2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v255 = v255 ? lisp_true : nil;
    env = stack[-6];
    if (!(v255 == nil)) goto v159;
    v255 = stack[-2];
    goto v159;

v159:
    qvalue(elt(env, 12)) = v255; /* expand */
    v255 = stack[-2];
    if (!(v255 == nil)) goto v96;
    v221 = stack[-1];
    v255 = (Lisp_Object)17; /* 1 */
    v255 = (Lisp_Object)lessp2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    v255 = v255 ? lisp_true : nil;
    env = stack[-6];
    if (!(v255 == nil)) goto v96;
    v255 = stack[-1];
    goto v259;

v259:
    qvalue(elt(env, 13)) = v255; /* i */
    v255 = qvalue(elt(env, 6)); /* identity */
    if (v255 == nil) goto v260;
    v255 = qvalue(elt(env, 4)); /* p */
    v255 = Llength(nil, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    goto v150;

v150:
    qvalue(elt(env, 14)) = v255; /* upb */
    v255 = qvalue(elt(env, 3)); /* symm */
    if (v255 == nil) goto v261;
    v255 = stack[-4];
    fn = elt(env, 19); /* initcomb */
    v255 = (*qfn1(fn))(qenv(fn), v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    qvalue(elt(env, 15)) = v255; /* comb */
    goto v261;

v261:
    v255 = nil;
    { popv(7); return onevalue(v255); }

v260:
    v221 = stack[-1];
    v255 = stack[0];
    v255 = plus2(v221, v255);
    nil = C_nil;
    if (exception_pending()) goto v256;
    env = stack[-6];
    goto v150;

v96:
    v255 = stack[-3];
    if (v255 == nil) goto v153;
    v255 = (Lisp_Object)1; /* 0 */
    goto v259;

v153:
    v255 = (Lisp_Object)17; /* 1 */
    goto v259;

v258:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v159;

v60:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v87;

v239:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v87;

v257:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v104;

v64:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v91;

v199:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v201;

v213:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v3;

v2:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v3;

v26:
    v255 = qvalue(elt(env, 8)); /* nil */
    goto v99;
/* error exit handlers */
v256:
    popv(7);
    return nil;
}



/* Code for matsm!* */

static Lisp_Object CC_matsmH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v107, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for matsm*");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v107 = v24;
    v53 = v0;
/* end of prologue */
    v107 = v53;
    fn = elt(env, 1); /* matsm */
    v107 = (*qfn1(fn))(qenv(fn), v107);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* matsm!*1 */
        return (*qfn1(fn))(qenv(fn), v107);
    }
/* error exit handlers */
v54:
    popv(1);
    return nil;
}



/* Code for dipevlcomp */

static Lisp_Object CC_dipevlcomp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v12;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dipevlcomp");
#endif
    if (stack >= stacklimit)
    {
        push2(v24,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0,v24);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v178 = v24;
    v12 = v0;
/* end of prologue */
    v12 = qcar(v12);
    v178 = qcar(v178);
    fn = elt(env, 1); /* evcompless!? */
    v178 = (*qfn2(fn))(qenv(fn), v12, v178);
    errexit();
    v178 = (v178 == nil ? lisp_true : nil);
    return onevalue(v178);
}



/* Code for xdegreecheck */

static Lisp_Object CC_xdegreecheck(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v47, v41;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for xdegreecheck");
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
    v41 = v0;
/* end of prologue */
    v47 = qvalue(elt(env, 1)); /* xtruncate!* */
    if (v47 == nil) goto v1;
    v47 = v41;
    fn = elt(env, 3); /* xdegree */
    v47 = (*qfn1(fn))(qenv(fn), v47);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[0];
    v41 = qvalue(elt(env, 1)); /* xtruncate!* */
        popv(1);
        return Lgreaterp(nil, v47, v41);

v1:
    v47 = qvalue(elt(env, 2)); /* nil */
    { popv(1); return onevalue(v47); }
/* error exit handlers */
v49:
    popv(1);
    return nil;
}



/* Code for bfplusn */

static Lisp_Object CC_bfplusn(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v6, v21, v50;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bfplusn");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v21 = v24;
    v50 = v0;
/* end of prologue */
    v6 = v50;
    if (!consp(v6)) goto v55;
    v6 = v50;
    {
        fn = elt(env, 1); /* plus!: */
        return (*qfn2(fn))(qenv(fn), v6, v21);
    }

v55:
    v6 = v50;
    return plus2(v6, v21);
}



/* Code for r2findindex */

static Lisp_Object CC_r2findindex(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v24)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v178, v12, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for r2findindex");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v178 = v24;
    v12 = v0;
/* end of prologue */
    v20 = v12;
    v12 = v178;
    v178 = (Lisp_Object)17; /* 1 */
    {
        fn = elt(env, 1); /* r2findindex1 */
        return (*qfnn(fn))(qenv(fn), 3, v20, v12, v178);
    }
}



/* Code for fortexp */

static Lisp_Object CC_fortexp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fortexp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v18 = v0;
/* end of prologue */
    v45 = v18;
    v18 = (Lisp_Object)1; /* 0 */
    {
        fn = elt(env, 1); /* fortexp1 */
        return (*qfn2(fn))(qenv(fn), v45, v18);
    }
}



/* Code for edges_parents */

static Lisp_Object CC_edges_parents(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v95;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for edges_parents");
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
    v95 = stack[0];
    if (v95 == nil) goto v1;
    v95 = stack[0];
    v95 = qcar(v95);
    fn = elt(env, 2); /* edge_new_parents */
    v95 = (*qfn1(fn))(qenv(fn), v95);
    nil = C_nil;
    if (exception_pending()) goto v21;
    env = stack[-2];
    stack[-1] = v95;
    v95 = stack[0];
    v95 = qcdr(v95);
    v95 = CC_edges_parents(env, v95);
    nil = C_nil;
    if (exception_pending()) goto v21;
    {
        Lisp_Object v50 = stack[-1];
        popv(3);
        return Lappend(nil, v50, v95);
    }

v1:
    v95 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v95); }
/* error exit handlers */
v21:
    popv(3);
    return nil;
}



/* Code for rread1 */

static Lisp_Object MS_CDECL CC_rread1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v258, v158, v229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "rread1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rread1");
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
    fn = elt(env, 14); /* ptoken */
    v258 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-2];
    stack[-1] = v258;
    v158 = qvalue(elt(env, 1)); /* ttype!* */
    v258 = (Lisp_Object)49; /* 3 */
    if (v158 == v258) goto v15;
    v258 = stack[-1];
    if (symbolp(v258)) goto v47;
    v158 = stack[-1];
    v258 = elt(env, 4); /* !:dn!: */
    if (!consp(v158)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v158 = qcar(v158);
    if (!(v158 == v258)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v229 = stack[-1];
    v158 = qvalue(elt(env, 5)); /* nil */
    v258 = elt(env, 6); /* symbolic */
    {
        popv(3);
        fn = elt(env, 15); /* dnform */
        return (*qfnn(fn))(qenv(fn), 3, v229, v158, v258);
    }

v47:
    v258 = qvalue(elt(env, 2)); /* !*quotenewnam */
    if (v258 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v158 = stack[-1];
    v258 = elt(env, 3); /* quotenewnam */
    v258 = get(v158, v258);
    stack[0] = v258;
    if (v258 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    else { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v15:
    v158 = stack[-1];
    v258 = elt(env, 7); /* !( */
    if (v158 == v258) goto v13;
    v158 = stack[-1];
    v258 = elt(env, 8); /* !+ */
    if (v158 == v258) goto v53;
    v158 = stack[-1];
    v258 = elt(env, 9); /* !- */
    if (!(v158 == v258)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v53:
    fn = elt(env, 14); /* ptoken */
    v258 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-2];
    stack[0] = v258;
    v158 = stack[0];
    v258 = elt(env, 4); /* !:dn!: */
    if (!consp(v158)) goto v164;
    v158 = qcar(v158);
    if (!(v158 == v258)) goto v164;
    v229 = stack[0];
    v158 = qvalue(elt(env, 5)); /* nil */
    v258 = elt(env, 6); /* symbolic */
    fn = elt(env, 15); /* dnform */
    v258 = (*qfnn(fn))(qenv(fn), 3, v229, v158, v258);
    nil = C_nil;
    if (exception_pending()) goto v263;
    env = stack[-2];
    stack[0] = v258;
    goto v164;

v164:
    v258 = stack[0];
    if (is_number(v258)) goto v86;
    v258 = elt(env, 10); /* " " */
    qvalue(elt(env, 11)) = v258; /* nxtsym!* */
    v158 = elt(env, 12); /* "Syntax error: improper number" */
    v258 = qvalue(elt(env, 5)); /* nil */
    fn = elt(env, 16); /* symerr */
    v258 = (*qfn2(fn))(qenv(fn), v158, v258);
    nil = C_nil;
    if (exception_pending()) goto v263;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v86:
    v158 = stack[-1];
    v258 = elt(env, 9); /* !- */
    if (!(v158 == v258)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v158 = elt(env, 13); /* minus */
    v258 = stack[0];
    v258 = Lapply1(nil, v158, v258);
    nil = C_nil;
    if (exception_pending()) goto v263;
    stack[0] = v258;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v13:
    {
        popv(3);
        fn = elt(env, 17); /* rrdls */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
v263:
    popv(3);
    return nil;
}



/* Code for fs!:null!-angle */

static Lisp_Object CC_fsTnullKangle(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v52, v68;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fs:null-angle");
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
    v52 = v0;
/* end of prologue */
    v68 = v52;
    v52 = (Lisp_Object)33; /* 2 */
    v52 = *(Lisp_Object *)((char *)v68 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL)));
    stack[0] = v52;
    v52 = qvalue(elt(env, 1)); /* t */
    stack[-2] = v52;
    v52 = (Lisp_Object)1; /* 0 */
    stack[-1] = v52;
    goto v21;

v21:
    v68 = stack[0];
    v52 = stack[-1];
    v68 = *(Lisp_Object *)((char *)v68 + (CELL-TAG_VECTOR) + ((int32_t)v52/(16/CELL)));
    v52 = (Lisp_Object)1; /* 0 */
    if (v68 == v52) goto v47;
    v52 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v52); }

v47:
    v52 = stack[-1];
    v52 = add1(v52);
    nil = C_nil;
    if (exception_pending()) goto v212;
    env = stack[-3];
    stack[-1] = v52;
    v68 = stack[-1];
    v52 = (Lisp_Object)129; /* 8 */
    v52 = (Lisp_Object)lessp2(v68, v52);
    nil = C_nil;
    if (exception_pending()) goto v212;
    v52 = v52 ? lisp_true : nil;
    env = stack[-3];
    if (v52 == nil) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    else goto v21;
/* error exit handlers */
v212:
    popv(4);
    return nil;
}



setup_type const u21_setup[] =
{
    {"cl_qb",                   CC_cl_qb,       too_many_1,    wrong_no_1},
    {"ofsf_ordatp",             too_few_2,      CC_ofsf_ordatp,wrong_no_2},
    {"naryom",                  CC_naryom,      too_many_1,    wrong_no_1},
    {"ft:zerop",                CC_ftTzerop,    too_many_1,    wrong_no_1},
    {"gvarlis1",                too_few_2,      CC_gvarlis1,   wrong_no_2},
    {"assert_typedefstat",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_typedefstat},
    {"fs:prin1",                CC_fsTprin1,    too_many_1,    wrong_no_1},
    {"dpmat_coldegs",           CC_dpmat_coldegs,too_many_1,   wrong_no_1},
    {"subs3t",                  too_few_2,      CC_subs3t,     wrong_no_2},
    {"tensorp",                 CC_tensorp,     too_many_1,    wrong_no_1},
    {"simpcv",                  too_few_2,      CC_simpcv,     wrong_no_2},
    {"simpexpt",                CC_simpexpt,    too_many_1,    wrong_no_1},
    {"pasf_anegrel",            CC_pasf_anegrel,too_many_1,    wrong_no_1},
    {"ibalp_negateat",          CC_ibalp_negateat,too_many_1,  wrong_no_1},
    {"rationalizesq",           CC_rationalizesq,too_many_1,   wrong_no_1},
    {"flatindl",                CC_flatindl,    too_many_1,    wrong_no_1},
    {"no-side-effect-listp",    CC_noKsideKeffectKlistp,too_many_1,wrong_no_1},
    {"groeb=weight",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_groebMweight},
    {"no_dum_varp",             CC_no_dum_varp, too_many_1,    wrong_no_1},
    {"ad_numsort",              CC_ad_numsort,  too_many_1,    wrong_no_1},
    {"lambda_l9xqts_5",         too_few_2,      CC_lambda_l9xqts_5,wrong_no_2},
    {"cl_identifyat",           CC_cl_identifyat,too_many_1,   wrong_no_1},
    {"ibalp_isinminclause",     too_few_2,      CC_ibalp_isinminclause,wrong_no_2},
    {"cgb_buch-ev_divides?",    too_few_2,      CC_cgb_buchKev_dividesW,wrong_no_2},
    {"dipev2f",                 too_few_2,      CC_dipev2f,    wrong_no_2},
    {"bcneg",                   CC_bcneg,       too_many_1,    wrong_no_1},
    {"edge_new_parent",         CC_edge_new_parent,too_many_1, wrong_no_1},
    {"*di2q0",                  too_few_2,      CC_Hdi2q0,     wrong_no_2},
    {"arglist_member",          too_few_2,      CC_arglist_member,wrong_no_2},
    {"wupseudodivide",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_wupseudodivide},
    {"taydegree<",              too_few_2,      CC_taydegreeR, wrong_no_2},
    {"ibalp_var-set",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_ibalp_varKset},
    {"unaryrd",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_unaryrd},
    {"freeindexchk",            CC_freeindexchk,too_many_1,    wrong_no_1},
    {"pfordp",                  too_few_2,      CC_pfordp,     wrong_no_2},
    {"fl2bf",                   CC_fl2bf,       too_many_1,    wrong_no_1},
    {"chkint*",                 CC_chkintH,     too_many_1,    wrong_no_1},
    {"coposp",                  CC_coposp,      too_many_1,    wrong_no_1},
    {"comblog",                 CC_comblog,     too_many_1,    wrong_no_1},
    {"mkprogn",                 too_few_2,      CC_mkprogn,    wrong_no_2},
    {"lengthcdr",               CC_lengthcdr,   too_many_1,    wrong_no_1},
    {"changearg",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_changearg},
    {"copy-tree",               CC_copyKtree,   too_many_1,    wrong_no_1},
    {"red=cancelsimp",          too_few_2,      CC_redMcancelsimp,wrong_no_2},
    {"get-free-form",           CC_getKfreeKform,too_many_1,   wrong_no_1},
    {"tayexp-times2",           too_few_2,      CC_tayexpKtimes2,wrong_no_2},
    {"get_char_value",          too_few_2,      CC_get_char_value,wrong_no_2},
    {"cl_sacatl",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_cl_sacatl},
    {"om2ir",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_om2ir},
    {"initarg",                 CC_initarg,     too_many_1,    wrong_no_1},
    {"matsm*",                  too_few_2,      CC_matsmH,     wrong_no_2},
    {"dipevlcomp",              too_few_2,      CC_dipevlcomp, wrong_no_2},
    {"xdegreecheck",            CC_xdegreecheck,too_many_1,    wrong_no_1},
    {"bfplusn",                 too_few_2,      CC_bfplusn,    wrong_no_2},
    {"r2findindex",             too_few_2,      CC_r2findindex,wrong_no_2},
    {"fortexp",                 CC_fortexp,     too_many_1,    wrong_no_1},
    {"edges_parents",           CC_edges_parents,too_many_1,   wrong_no_1},
    {"rread1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_rread1},
    {"fs:null-angle",           CC_fsTnullKangle,too_many_1,   wrong_no_1},
    {NULL, (one_args *)"u21", (two_args *)"20783 1526207 1815847", 0}
};

/* end of generated code */
