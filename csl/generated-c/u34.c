
/* $destdir\u34.c        Machine generated C code */

/* Signature: 00000000 27-Aug-2011 */

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
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
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
#ifdef OLD_VERSION
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
#else 
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(bits, font, code)                                \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF ((Lisp_Object)(int32_t)0xff000402)
#endif  
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
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
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
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
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
extern char *C_stack_limit;
extern CSLbool restartp;
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
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack(__FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
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
extern int csl_argc;
extern char **csl_argv;
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
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count;
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
#define validate_string(a) 
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


/* Code for mk!+scal!+mult!+mat */

static Lisp_Object CC_mkLscalLmultLmat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mk+scal+mult+mat");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v1;
    stack[-8] = v0;
/* end of prologue */
    v31 = stack[0];
    fn = elt(env, 6); /* matrix!+p */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    if (!(v31 == nil)) goto v34;
    v31 = qvalue(elt(env, 1)); /* !*protfg */
    if (!(v31 == nil)) goto v35;
    v31 = elt(env, 2); /* "no matrix in add" */
    fn = elt(env, 7); /* lprie */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    goto v35;

v35:
    v31 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    goto v34;

v34:
    v31 = stack[0];
    stack[-9] = v31;
    v31 = stack[-9];
    if (v31 == nil) goto v36;
    v31 = stack[-9];
    v31 = qcar(v31);
    stack[-4] = v31;
    v31 = stack[-4];
    if (v31 == nil) goto v37;
    v31 = stack[-4];
    v31 = qcar(v31);
    v32 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v32 = v31;
    v31 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v31; /* !*sub2 */
    v31 = v32;
    fn = elt(env, 9); /* subs2 */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v38;
    env = stack[-10];
    v32 = v31;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v31 = v32;
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    stack[-2] = v31;
    stack[-3] = v31;
    goto v39;

v39:
    v31 = stack[-4];
    v31 = qcdr(v31);
    stack[-4] = v31;
    v31 = stack[-4];
    if (v31 == nil) goto v40;
    stack[-1] = stack[-2];
    v31 = stack[-4];
    v31 = qcar(v31);
    v32 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v32 = v31;
    v31 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v31; /* !*sub2 */
    v31 = v32;
    fn = elt(env, 9); /* subs2 */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-10];
    v32 = v31;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v31 = v32;
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v31 = Lrplacd(nil, stack[-1], v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v31 = stack[-2];
    v31 = qcdr(v31);
    stack[-2] = v31;
    goto v39;

v40:
    v31 = stack[-3];
    goto v42;

v42:
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    stack[-6] = v31;
    stack[-7] = v31;
    goto v43;

v43:
    v31 = stack[-9];
    v31 = qcdr(v31);
    stack[-9] = v31;
    v31 = stack[-9];
    if (v31 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    stack[-5] = stack[-6];
    v31 = stack[-9];
    v31 = qcar(v31);
    stack[-4] = v31;
    v31 = stack[-4];
    if (v31 == nil) goto v44;
    v31 = stack[-4];
    v31 = qcar(v31);
    v32 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v32 = v31;
    v31 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v31; /* !*sub2 */
    v31 = v32;
    fn = elt(env, 9); /* subs2 */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v45;
    env = stack[-10];
    v32 = v31;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v31 = v32;
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    stack[-2] = v31;
    stack[-3] = v31;
    goto v46;

v46:
    v31 = stack[-4];
    v31 = qcdr(v31);
    stack[-4] = v31;
    v31 = stack[-4];
    if (v31 == nil) goto v47;
    stack[-1] = stack[-2];
    v31 = stack[-4];
    v31 = qcar(v31);
    v32 = stack[-8];
    fn = elt(env, 8); /* multsq */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v32 = v31;
    v31 = qvalue(elt(env, 4)); /* t */
    stack[0] = qvalue(elt(env, 5)); /* !*sub2 */
    qvalue(elt(env, 5)) = v31; /* !*sub2 */
    v31 = v32;
    fn = elt(env, 9); /* subs2 */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v48;
    env = stack[-10];
    v32 = v31;
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    v31 = v32;
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v31 = Lrplacd(nil, stack[-1], v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v31 = stack[-2];
    v31 = qcdr(v31);
    stack[-2] = v31;
    goto v46;

v47:
    v31 = stack[-3];
    goto v49;

v49:
    v31 = ncons(v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v31 = Lrplacd(nil, stack[-5], v31);
    nil = C_nil;
    if (exception_pending()) goto v33;
    env = stack[-10];
    v31 = stack[-6];
    v31 = qcdr(v31);
    stack[-6] = v31;
    goto v43;

v44:
    v31 = qvalue(elt(env, 3)); /* nil */
    goto v49;

v37:
    v31 = qvalue(elt(env, 3)); /* nil */
    goto v42;

v36:
    v31 = qvalue(elt(env, 3)); /* nil */
    { popv(11); return onevalue(v31); }
/* error exit handlers */
v48:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v45:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v41:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v38:
    env = stack[-10];
    qvalue(elt(env, 5)) = stack[0]; /* !*sub2 */
    popv(11);
    return nil;
v33:
    popv(11);
    return nil;
}



/* Code for rl_multsurep */

static Lisp_Object CC_rl_multsurep(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v53;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_multsurep");
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
    v35 = v1;
    v53 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_multsurep!* */
    v35 = list2(v53, v35);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-1];
    {
        Lisp_Object v55 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v55, v35);
    }
/* error exit handlers */
v54:
    popv(2);
    return nil;
}



/* Code for symbolsom */

static Lisp_Object CC_symbolsom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v71, v72, v73;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbolsom");
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
    stack[-1] = nil;
    v71 = stack[-4];
    v72 = qcar(v71);
    v71 = qvalue(elt(env, 1)); /* valid_om!* */
    v71 = Lassoc(nil, v72, v71);
    stack[-5] = v71;
    v71 = stack[-5];
    if (v71 == nil) goto v53;
    v71 = stack[-5];
    v71 = qcdr(v71);
    v71 = qcar(v71);
    stack[-5] = v71;
    goto v53;

v53:
    v71 = stack[-4];
    v71 = qcar(v71);
    stack[0] = v71;
    v71 = stack[-4];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcar(v71);
    stack[-3] = v71;
    v71 = stack[-4];
    v71 = Lreverse(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = qcar(v71);
    stack[-2] = v71;
    v72 = stack[0];
    v71 = elt(env, 2); /* diff */
    if (v72 == v71) goto v75;
    v71 = stack[-4];
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcdr(v71);
    v71 = qcar(v71);
    stack[-1] = v71;
    goto v75;

v75:
    v71 = stack[-1];
    if (v71 == nil) goto v76;
    v71 = stack[-1];
    v72 = qcar(v71);
    v71 = elt(env, 3); /* condition */
    if (!(v72 == v71)) goto v76;
    v72 = elt(env, 4); /* "<condition> tag not supported in MathML" */
    v71 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 15); /* errorml */
    v71 = (*qfn2(fn))(qenv(fn), v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    goto v76;

v76:
    v71 = elt(env, 5); /* "<OMA>" */
    fn = elt(env, 16); /* printout */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = qvalue(elt(env, 6)); /* t */
    fn = elt(env, 17); /* indent!* */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = stack[-1];
    if (v71 == nil) goto v22;
    v72 = stack[0];
    v71 = elt(env, 7); /* int */
    v71 = (v72 == v71 ? lisp_true : nil);
    goto v77;

v77:
    if (v71 == nil) goto v78;
    v71 = elt(env, 9); /* defint */
    stack[0] = v71;
    goto v78;

v78:
    v71 = elt(env, 10); /* "<OMS cd=""" */
    fn = elt(env, 16); /* printout */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = stack[-5];
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = elt(env, 11); /* """ name=""" */
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = stack[0];
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = elt(env, 12); /* """/>" */
    v71 = Lprinc(nil, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = stack[-1];
    if (v71 == nil) goto v2;
    v71 = stack[-1];
    fn = elt(env, 18); /* objectom */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    goto v2;

v2:
    stack[-1] = elt(env, 13); /* lambda */
    stack[0] = qvalue(elt(env, 8)); /* nil */
    v73 = stack[-3];
    v72 = stack[-2];
    v71 = qvalue(elt(env, 8)); /* nil */
    v71 = list2star(v73, v72, v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = list2star(stack[-1], stack[0], v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    fn = elt(env, 19); /* lambdaom */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = qvalue(elt(env, 8)); /* nil */
    fn = elt(env, 17); /* indent!* */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    env = stack[-6];
    v71 = elt(env, 14); /* "</OMA>" */
    fn = elt(env, 16); /* printout */
    v71 = (*qfn1(fn))(qenv(fn), v71);
    nil = C_nil;
    if (exception_pending()) goto v74;
    v71 = nil;
    { popv(7); return onevalue(v71); }

v22:
    v71 = qvalue(elt(env, 8)); /* nil */
    goto v77;
/* error exit handlers */
v74:
    popv(7);
    return nil;
}



/* Code for f4 */

static Lisp_Object CC_f4(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v88, v89;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for f4");
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
    v89 = stack[0];
    v88 = elt(env, 1); /* pi */
    if (v89 == v88) goto v62;
    v89 = stack[0];
    v88 = elt(env, 3); /* euler_gamma */
    if (v89 == v88) goto v52;
    v89 = stack[0];
    v88 = elt(env, 5); /* true */
    if (v89 == v88) goto v90;
    v89 = stack[0];
    v88 = elt(env, 7); /* false */
    if (v89 == v88) goto v91;
    v89 = stack[0];
    v88 = elt(env, 9); /* !Na!N */
    if (v89 == v88) goto v92;
    v89 = stack[0];
    v88 = elt(env, 11); /* infinity */
    if (v89 == v88) goto v93;
    v89 = stack[0];
    v88 = elt(env, 17); /* e */
    if (v89 == v88) goto v94;
    v89 = stack[0];
    v88 = elt(env, 19); /* i */
    if (v89 == v88) goto v95;
    v88 = stack[0];
    if (!(is_number(v88))) goto v71;
    v88 = elt(env, 21); /* "<cn" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = stack[0];
    v88 = Lfloatp(nil, v88);
    env = stack[-1];
    if (v88 == nil) goto v74;
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v97;
    v88 = elt(env, 23); /* " type=&quot;real&quot;>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v98;

v98:
    v88 = stack[0];
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = elt(env, 16); /* "</cn>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v71;

v71:
    v88 = stack[0];
    if (!(symbolp(v88))) goto v61;
    v88 = elt(env, 27); /* "<ci" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = stack[0];
    fn = elt(env, 35); /* listp */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    if (v88 == nil) goto v99;
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v38;
    v88 = elt(env, 29); /* " type=&quot;list&quot;>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v100;

v100:
    v88 = stack[0];
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = elt(env, 32); /* "</ci>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v61:
    v88 = nil;
    { popv(2); return onevalue(v88); }

v38:
    v88 = elt(env, 28); /* " type=""list"">" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v100;

v99:
    v88 = stack[0];
    v88 = Lsimple_vectorp(nil, v88);
    env = stack[-1];
    if (v88 == nil) goto v101;
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v102;
    v88 = elt(env, 31); /* " type=&quot;vector&quot;>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v100;

v102:
    v88 = elt(env, 30); /* " type=""vector"">" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v100;

v101:
    v88 = elt(env, 26); /* ">" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v100;

v97:
    v88 = elt(env, 22); /* " type=""real"">" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v98;

v74:
    v88 = stack[0];
    v88 = integerp(v88);
    if (v88 == nil) goto v103;
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v9;
    v88 = elt(env, 25); /* " type=&quot;integer&quot;>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v98;

v9:
    v88 = elt(env, 24); /* " type=""integer"">" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v98;

v103:
    v88 = elt(env, 26); /* ">" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v98;

v95:
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v4;
    v88 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v11;

v11:
    v88 = elt(env, 20); /* "&ImaginaryI;" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = elt(env, 16); /* "</cn>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v4:
    v88 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v11;

v94:
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v104;
    v88 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v105;

v105:
    v88 = elt(env, 18); /* "&ExponentialE;" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = elt(env, 16); /* "</cn>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v104:
    v88 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v105;

v93:
    v88 = qvalue(elt(env, 12)); /* !*web */
    if (v88 == nil) goto v106;
    v88 = elt(env, 14); /* "<cn type=&quot;constant&quot;>" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v107;

v107:
    v88 = elt(env, 15); /* "&infin;" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    v88 = elt(env, 16); /* "</cn>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v106:
    v88 = elt(env, 13); /* "<cn type=""constant"">" */
    fn = elt(env, 34); /* printout */
    v88 = (*qfn1(fn))(qenv(fn), v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    env = stack[-1];
    goto v107;

v92:
    v88 = elt(env, 10); /* "<notanumber/>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v91:
    v88 = elt(env, 8); /* "<false/>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v90:
    v88 = elt(env, 6); /* "<true/>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v52:
    v88 = elt(env, 4); /* "<eulergamma/>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;

v62:
    v88 = elt(env, 2); /* "<pi/>" */
    v88 = Lprinc(nil, v88);
    nil = C_nil;
    if (exception_pending()) goto v96;
    goto v61;
/* error exit handlers */
v96:
    popv(2);
    return nil;
}



/* Code for intrdsortin */

static Lisp_Object CC_intrdsortin(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v82;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intrdsortin");
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
    goto v62;

v62:
    v69 = stack[0];
    if (v69 == nil) goto v87;
    v69 = stack[-1];
    v82 = qcar(v69);
    v69 = stack[0];
    v69 = qcar(v69);
    v69 = qcar(v69);
    fn = elt(env, 1); /* !:difference */
    v69 = (*qfn2(fn))(qenv(fn), v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    fn = elt(env, 2); /* !:minusp */
    v69 = (*qfn1(fn))(qenv(fn), v69);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    if (v69 == nil) goto v112;
    v69 = stack[0];
    v82 = qcar(v69);
    v69 = stack[-2];
    v69 = cons(v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    stack[-2] = v69;
    v69 = stack[0];
    v69 = qcdr(v69);
    stack[0] = v69;
    goto v62;

v112:
    v82 = stack[-1];
    v69 = stack[0];
    v69 = cons(v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    {
        Lisp_Object v113 = stack[-2];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v113, v69);
    }

v87:
    stack[0] = stack[-2];
    v69 = stack[-1];
    v69 = ncons(v69);
    nil = C_nil;
    if (exception_pending()) goto v106;
    env = stack[-3];
    {
        Lisp_Object v67 = stack[0];
        popv(4);
        fn = elt(env, 3); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v67, v69);
    }
/* error exit handlers */
v106:
    popv(4);
    return nil;
}



/* Code for new_prove */

static Lisp_Object CC_new_prove(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v91, v114;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for new_prove");
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

v115:
    v91 = stack[0];
    if (v91 == nil) goto v61;
    v114 = stack[-1];
    v91 = stack[0];
    v91 = qcar(v91);
    fn = elt(env, 2); /* new_provev */
    v91 = (*qfn2(fn))(qenv(fn), v114, v91);
    nil = C_nil;
    if (exception_pending()) goto v27;
    env = stack[-2];
    v114 = v91;
    v91 = v114;
    if (v91 == nil) goto v116;
    v91 = v114;
    popv(3);
    return ncons(v91);

v116:
    v114 = stack[-1];
    v91 = stack[0];
    v91 = qcdr(v91);
    stack[-1] = v114;
    stack[0] = v91;
    goto v115;

v61:
    v91 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v91); }
/* error exit handlers */
v27:
    popv(3);
    return nil;
}



/* Code for verify_tens_ids */

static Lisp_Object CC_verify_tens_ids(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v118, v83;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for verify_tens_ids");
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
    v118 = stack[0];
    v118 = qcar(v118);
    v83 = v118;
    v118 = stack[0];
    v118 = qcdr(v118);
    v118 = qcar(v118);
    stack[-1] = v118;
    v118 = v83;
    fn = elt(env, 5); /* extract_dummy_ids */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    fn = elt(env, 6); /* repeats */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    if (!(v118 == nil)) goto v43;
    v118 = stack[-1];
    fn = elt(env, 5); /* extract_dummy_ids */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    fn = elt(env, 6); /* repeats */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    if (!(v118 == nil)) goto v43;
    v118 = qvalue(elt(env, 4)); /* t */
    { popv(3); return onevalue(v118); }

v43:
    v118 = stack[0];
    v83 = qcar(v118);
    v118 = stack[0];
    v118 = qcdr(v118);
    v118 = qcar(v118);
    v83 = list2(v83, v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    v118 = elt(env, 1); /* "are inconsistent lists of indices" */
    v118 = list2(v83, v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    v83 = v118;
    v118 = v83;
    qvalue(elt(env, 2)) = v118; /* errmsg!* */
    v118 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v118 == nil)) goto v42;
    v118 = v83;
    fn = elt(env, 7); /* lprie */
    v118 = (*qfn1(fn))(qenv(fn), v118);
    nil = C_nil;
    if (exception_pending()) goto v112;
    env = stack[-2];
    goto v42;

v42:
    v118 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v112;
    v118 = nil;
    { popv(3); return onevalue(v118); }
/* error exit handlers */
v112:
    popv(3);
    return nil;
}



/* Code for list2vect!* */

static Lisp_Object CC_list2vectH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v40, v120;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for list2vect*");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */
    v40 = stack[-4];
    v40 = Llength(nil, v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v40 = sub1(v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v40 = Lmkvect(nil, v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    stack[-5] = v40;
    v40 = (Lisp_Object)17; /* 1 */
    stack[-2] = v40;
    goto v54;

v54:
    v40 = stack[-5];
    v40 = Lupbv(nil, v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v120 = add1(v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v40 = stack[-2];
    v40 = difference2(v120, v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v40 = Lminusp(nil, v40);
    env = stack[-6];
    if (!(v40 == nil)) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    stack[-1] = stack[-5];
    v40 = stack[-2];
    stack[0] = sub1(v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v120 = stack[-3];
    v40 = elt(env, 2); /* algebraic */
    if (v120 == v40) goto v121;
    v120 = stack[-4];
    v40 = stack[-2];
    fn = elt(env, 3); /* pnth */
    v40 = (*qfn2(fn))(qenv(fn), v120, v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v40 = qcar(v40);
    goto v75;

v75:
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v40;
    v40 = stack[-2];
    v40 = add1(v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    stack[-2] = v40;
    goto v54;

v121:
    v120 = stack[-4];
    v40 = stack[-2];
    fn = elt(env, 3); /* pnth */
    v40 = (*qfn2(fn))(qenv(fn), v120, v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    v40 = qcar(v40);
    fn = elt(env, 4); /* symb_to_alg */
    v40 = (*qfn1(fn))(qenv(fn), v40);
    nil = C_nil;
    if (exception_pending()) goto v64;
    env = stack[-6];
    goto v75;
/* error exit handlers */
v64:
    popv(7);
    return nil;
}



/* Code for get!-current!-representation */

static Lisp_Object CC_getKcurrentKrepresentation(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v34, v123;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for get-current-representation");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v34 = v0;
/* end of prologue */
    v123 = elt(env, 1); /* currep */
    return get(v34, v123);
}



/* Code for make!-image */

static Lisp_Object CC_makeKimage(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v128, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for make-image");
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
    v128 = stack[-2];
    if (!consp(v128)) goto v50;
    v128 = stack[-2];
    v128 = qcar(v128);
    v128 = (consp(v128) ? nil : lisp_true);
    goto v122;

v122:
    if (!(v128 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v128 = stack[-2];
    v128 = qcar(v128);
    v128 = qcar(v128);
    v65 = qcar(v128);
    v128 = qvalue(elt(env, 2)); /* m!-image!-variable */
    if (equal(v65, v128)) goto v129;
    v65 = stack[-2];
    v128 = stack[-1];
    fn = elt(env, 4); /* evaluate!-in!-order */
    v128 = (*qfn2(fn))(qenv(fn), v65, v128);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v65 = v128;
    v128 = v65;
    v128 = (Lisp_Object)zerop(v128);
    v128 = v128 ? lisp_true : nil;
    env = stack[-4];
    if (v128 == nil) { popv(5); return onevalue(v65); }
    v128 = qvalue(elt(env, 3)); /* nil */
    { popv(5); return onevalue(v128); }

v129:
    v128 = stack[-2];
    v128 = qcar(v128);
    stack[-3] = qcar(v128);
    v128 = stack[-2];
    v128 = qcar(v128);
    v65 = qcdr(v128);
    v128 = stack[-1];
    fn = elt(env, 4); /* evaluate!-in!-order */
    v128 = (*qfn2(fn))(qenv(fn), v65, v128);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v65 = v128;
    v128 = v65;
    v128 = (Lisp_Object)zerop(v128);
    v128 = v128 ? lisp_true : nil;
    env = stack[-4];
    if (v128 == nil) goto v112;
    v128 = qvalue(elt(env, 3)); /* nil */
    stack[0] = v128;
    goto v130;

v130:
    v128 = stack[-2];
    v65 = qcdr(v128);
    v128 = stack[-1];
    v128 = CC_makeKimage(env, v65, v128);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    {
        Lisp_Object v104 = stack[-3];
        Lisp_Object v131 = stack[0];
        popv(5);
        fn = elt(env, 5); /* adjoin!-term */
        return (*qfnn(fn))(qenv(fn), 3, v104, v131, v128);
    }

v112:
    v128 = v65;
    stack[0] = v128;
    goto v130;

v50:
    v128 = qvalue(elt(env, 1)); /* t */
    goto v122;
/* error exit handlers */
v105:
    popv(5);
    return nil;
}



/* Code for simprd */

static Lisp_Object CC_simprd(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v86, v70;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for simprd");
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
    v70 = v0;
/* end of prologue */
    v86 = v70;
    if (!consp(v86)) goto v59;
    v86 = elt(env, 2); /* !:rd!: */
    stack[0] = qvalue(elt(env, 3)); /* dmode!* */
    qvalue(elt(env, 3)) = v86; /* dmode!* */
    v86 = v70;
    fn = elt(env, 4); /* simplist */
    v86 = (*qfn1(fn))(qenv(fn), v86);
    nil = C_nil;
    if (exception_pending()) goto v52;
    env = stack[-1];
    qvalue(elt(env, 3)) = stack[0]; /* dmode!* */
    { popv(2); return onevalue(v86); }

v59:
    v86 = qvalue(elt(env, 1)); /* nil */
    { popv(2); return onevalue(v86); }
/* error exit handlers */
v52:
    env = stack[-1];
    qvalue(elt(env, 3)) = stack[0]; /* dmode!* */
    popv(2);
    return nil;
}



/* Code for evalgreaterp */

static Lisp_Object CC_evalgreaterp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v139, v140;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for evalgreaterp");
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
    v139 = v1;
    v138 = v0;
/* end of prologue */
    v140 = elt(env, 1); /* difference */
    v138 = list3(v140, v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    fn = elt(env, 6); /* simp!* */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    stack[0] = v138;
    v138 = stack[0];
    v138 = qcdr(v138);
    if (!consp(v138)) goto v17;
    v138 = qvalue(elt(env, 2)); /* t */
    goto v54;

v54:
    if (v138 == nil) goto v106;
    v138 = stack[0];
    v138 = qcar(v138);
    fn = elt(env, 7); /* minusf */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    if (v138 == nil) goto v82;
    v138 = stack[0];
    v138 = qcar(v138);
    fn = elt(env, 8); /* negf */
    v139 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = cons(v139, v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    goto v37;

v37:
    fn = elt(env, 9); /* mk!*sq */
    v139 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v141;
    env = stack[-1];
    v138 = elt(env, 3); /* "number" */
    {
        popv(2);
        fn = elt(env, 10); /* typerr */
        return (*qfn2(fn))(qenv(fn), v139, v138);
    }

v82:
    v138 = stack[0];
    goto v37;

v106:
    v138 = stack[0];
    v138 = qcar(v138);
    if (v138 == nil) goto v40;
    v138 = stack[0];
    v138 = qcar(v138);
    if (!consp(v138)) goto v77;
    v138 = stack[0];
    v138 = qcar(v138);
    v139 = qcar(v138);
    v138 = elt(env, 5); /* minusp */
    v139 = get(v139, v138);
    v138 = stack[0];
    v138 = qcar(v138);
        popv(2);
        return Lapply1(nil, v139, v138);

v77:
    v138 = stack[0];
    v138 = qcar(v138);
        popv(2);
        return Lminusp(nil, v138);

v40:
    v138 = qvalue(elt(env, 4)); /* nil */
    { popv(2); return onevalue(v138); }

v17:
    v138 = stack[0];
    v138 = qcar(v138);
    if (!consp(v138)) goto v116;
    v138 = stack[0];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = (consp(v138) ? nil : lisp_true);
    goto v43;

v43:
    v138 = (v138 == nil ? lisp_true : nil);
    goto v54;

v116:
    v138 = qvalue(elt(env, 2)); /* t */
    goto v43;
/* error exit handlers */
v141:
    popv(2);
    return nil;
}



/* Code for mktag */

static Lisp_Object MS_CDECL CC_mktag(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v143, v94, v24;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "mktag");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mktag");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v63;
    stack[-2] = v1;
    v143 = v0;
/* end of prologue */
    v94 = v143;
    if (v94 == nil) goto v62;
    v94 = v143;
    if (!consp(v94)) goto v34;
    v94 = v143;
    v24 = qcar(v94);
    v94 = elt(env, 2); /* texprec */
    v94 = get(v24, v94);
    env = stack[-4];
    if (!(v94 == nil)) goto v55;
    v94 = (Lisp_Object)15985; /* 999 */
    goto v55;

v55:
    stack[-3] = v94;
    v94 = v143;
    v24 = qcar(v94);
    v94 = qcdr(v143);
    v143 = stack[-3];
    fn = elt(env, 5); /* makefunc */
    v143 = (*qfnn(fn))(qenv(fn), 3, v24, v94, v143);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    stack[0] = v143;
    v143 = stack[-1];
    if (v143 == nil) goto v130;
    v94 = stack[-2];
    v143 = stack[-3];
    if (!(equal(v94, v143))) goto v130;

v144:
    v94 = elt(env, 3); /* !\!( */
    v143 = stack[0];
    stack[0] = cons(v94, v143);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v143 = elt(env, 4); /* !\!) */
    v143 = ncons(v143);
    nil = C_nil;
    if (exception_pending()) goto v66;
    env = stack[-4];
    v143 = Lnconc(nil, stack[0], v143);
    nil = C_nil;
    if (exception_pending()) goto v66;
    stack[0] = v143;
    { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

v130:
    v94 = stack[-3];
    v143 = stack[-2];
    v143 = (Lisp_Object)lessp2(v94, v143);
    nil = C_nil;
    if (exception_pending()) goto v66;
    v143 = v143 ? lisp_true : nil;
    env = stack[-4];
    if (v143 == nil) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    else goto v144;

v34:
    {
        popv(5);
        fn = elt(env, 6); /* texexplode */
        return (*qfn1(fn))(qenv(fn), v143);
    }

v62:
    v143 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v143); }
/* error exit handlers */
v66:
    popv(5);
    return nil;
}



/* Code for fnom */

static Lisp_Object CC_fnom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnom");
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
    v27 = elt(env, 1); /* "<OMA>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 14); /* indent!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 3); /* "<OMATTR>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 14); /* indent!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 4); /* "<OMATP>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = qvalue(elt(env, 2)); /* t */
    fn = elt(env, 14); /* indent!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 5); /* "<OMS cd=""typmml"" name=""type""/>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 6); /* "<OMS cd=""typmml"" name=""" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 7); /* "fn_type" */
    v27 = Lprinc(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 8); /* """/>" */
    v27 = Lprinc(nil, v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* indent!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 10); /* "</OMATP>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = stack[0];
    v27 = qcar(v27);
    fn = elt(env, 15); /* objectom */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* indent!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 11); /* "</OMATTR>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = stack[0];
    v27 = qcdr(v27);
    v27 = qcdr(v27);
    fn = elt(env, 16); /* multiom */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = qvalue(elt(env, 9)); /* nil */
    fn = elt(env, 14); /* indent!* */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    env = stack[-1];
    v27 = elt(env, 12); /* "</OMA>" */
    fn = elt(env, 13); /* printout */
    v27 = (*qfn1(fn))(qenv(fn), v27);
    nil = C_nil;
    if (exception_pending()) goto v19;
    v27 = nil;
    { popv(2); return onevalue(v27); }
/* error exit handlers */
v19:
    popv(2);
    return nil;
}



/* Code for multup */

static Lisp_Object CC_multup(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v116, v129;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multup");
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
    v116 = v0;
/* end of prologue */
    v129 = (Lisp_Object)17; /* 1 */
    stack[0] = v116;
    goto v50;

v50:
    v116 = stack[0];
    if (v116 == nil) { popv(2); return onevalue(v129); }
    v116 = stack[0];
    v116 = qcar(v116);
    fn = elt(env, 2); /* multf */
    v116 = (*qfn2(fn))(qenv(fn), v129, v116);
    nil = C_nil;
    if (exception_pending()) goto v36;
    env = stack[-1];
    v129 = v116;
    v116 = stack[0];
    v116 = qcdr(v116);
    stack[0] = v116;
    goto v50;
/* error exit handlers */
v36:
    popv(2);
    return nil;
}



/* Code for diffp */

static Lisp_Object CC_diffp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v302, v303, v304, v305;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for diffp");
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
    stack[-1] = nil;
    v302 = stack[-5];
    v302 = qcdr(v302);
    stack[-6] = v302;
    v302 = stack[-5];
    v302 = qcar(v302);
    stack[-5] = v302;
    v303 = stack[-6];
    v302 = (Lisp_Object)17; /* 1 */
    v302 = (Lisp_Object)greaterp2(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    v302 = v302 ? lisp_true : nil;
    env = stack[-7];
    if (v302 == nil) goto v2;
    v302 = qvalue(elt(env, 1)); /* !*ncmp */
    if (v302 == nil) goto v2;
    v302 = stack[-5];
    fn = elt(env, 22); /* noncomp1 */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    if (v302 == nil) goto v2;
    v303 = stack[-5];
    v302 = stack[-4];
    v302 = list2(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 23); /* simpdf */
    stack[-1] = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[0] = stack[-5];
    v302 = stack[-6];
    v302 = sub1(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = list2(stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 24); /* simpexpt */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 25); /* multsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v304 = stack[-5];
    v303 = (Lisp_Object)17; /* 1 */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = acons(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v303 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = (Lisp_Object)17; /* 1 */
    stack[0] = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-2] = stack[-5];
    v302 = stack[-6];
    v302 = sub1(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v303 = cons(stack[-2], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-4];
    v302 = CC_diffp(env, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 25); /* multsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    {
        Lisp_Object v307 = stack[-1];
        popv(8);
        fn = elt(env, 26); /* addsq */
        return (*qfn2(fn))(qenv(fn), v307, v302);
    }

v2:
    v303 = stack[-5];
    v302 = stack[-4];
    if (v303 == v302) goto v4;
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v95;

v95:
    if (!(v302 == nil)) goto v308;
    v302 = stack[-5];
    if (!consp(v302)) goto v309;
    v302 = stack[-5];
    v302 = qcar(v302);
    if (!consp(v302)) goto v97;
    v303 = stack[-5];
    v302 = stack[-4];
    fn = elt(env, 27); /* difff */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v72;

v72:
    if (!(v302 == nil)) goto v308;
    v302 = stack[-5];
    v303 = qcar(v302);
    v302 = elt(env, 3); /* !*sq */
    if (v303 == v302) goto v310;
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v311;

v311:
    if (!(v302 == nil)) goto v308;
    v302 = stack[-5];
    v303 = qcar(v302);
    v302 = elt(env, 4); /* dfform */
    v302 = get(v303, v302);
    env = stack[-7];
    stack[-3] = v302;
    if (v302 == nil) goto v312;
    v305 = stack[-3];
    v304 = stack[-5];
    v303 = stack[-4];
    v302 = stack[-6];
        popv(8);
        return Lapply3(nil, 4, v305, v304, v303, v302);

v312:
    v302 = stack[-5];
    stack[0] = qcar(v302);
    v302 = stack[-5];
    fn = elt(env, 28); /* dfn_prop */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = get(stack[0], v302);
    env = stack[-7];
    stack[-3] = v302;
    if (v302 == nil) goto v313;
    v302 = stack[-3];
    stack[-2] = v302;
    v302 = stack[-5];
    v302 = qcdr(v302);
    stack[0] = v302;
    goto v314;

v314:
    v302 = stack[0];
    v302 = qcar(v302);
    fn = elt(env, 29); /* simp */
    v303 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-4];
    fn = elt(env, 30); /* diffsq */
    v303 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-1];
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    v302 = stack[-1];
    v302 = qcar(v302);
    v302 = qcar(v302);
    if (v302 == nil) goto v315;
    v302 = stack[-2];
    v302 = qcar(v302);
    if (!(v302 == nil)) goto v315;

v316:
    v302 = stack[-5];
    v303 = qcar(v302);
    v302 = elt(env, 16); /* df */
    if (v303 == v302) goto v317;
    v304 = elt(env, 16); /* df */
    v303 = stack[-5];
    v302 = stack[-4];
    v302 = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v52;

v52:
    v302 = stack[-1];
    fn = elt(env, 31); /* opmtch */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-3] = v302;
    if (v302 == nil) goto v318;
    v302 = stack[-3];
    fn = elt(env, 29); /* simp */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v308;

v308:
    v303 = stack[-5];
    v302 = qvalue(elt(env, 6)); /* wtl!* */
    v302 = Latsoc(nil, v303, v302);
    stack[-3] = v302;
    if (v302 == nil) goto v319;
    stack[0] = elt(env, 7); /* k!* */
    v302 = stack[-3];
    v302 = qcdr(v302);
    v303 = negate(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = (Lisp_Object)17; /* 1 */
    v302 = acons(stack[0], v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v303 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = (Lisp_Object)17; /* 1 */
    v303 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-1];
    fn = elt(env, 25); /* multsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v319;

v319:
    v302 = stack[-6];
    v302 = sub1(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[0] = v302;
    v303 = stack[-6];
    v302 = (Lisp_Object)17; /* 1 */
    if (v303 == v302) goto v320;
    v303 = qvalue(elt(env, 8)); /* dmode!* */
    v302 = elt(env, 9); /* convert */
    v302 = Lflagp(nil, v303, v302);
    env = stack[-7];
    if (v302 == nil) goto v321;
    v303 = qvalue(elt(env, 8)); /* dmode!* */
    v302 = elt(env, 10); /* i2d */
    v303 = get(v303, v302);
    env = stack[-7];
    v302 = stack[-6];
    v302 = Lapply1(nil, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 32); /* int!-equiv!-chk */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-6] = v302;
    v302 = (v302 == nil ? lisp_true : nil);
    goto v322;

v322:
    if (v302 == nil) goto v323;
    v303 = qvalue(elt(env, 2)); /* nil */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    goto v324;

v324:
    {
        popv(8);
        fn = elt(env, 33); /* rationalizesq */
        return (*qfn1(fn))(qenv(fn), v302);
    }

v323:
    v304 = stack[-5];
    v303 = stack[0];
    v302 = stack[-6];
    v302 = acons(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v303 = ncons(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = (Lisp_Object)17; /* 1 */
    v303 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-1];
    fn = elt(env, 25); /* multsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    goto v324;

v321:
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v322;

v320:
    v302 = stack[-1];
    goto v324;

v318:
    v303 = stack[-5];
    v302 = stack[-4];
    fn = elt(env, 34); /* depends */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    if (v302 == nil) goto v325;
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v326;

v326:
    if (v302 == nil) goto v327;
    v303 = qvalue(elt(env, 2)); /* nil */
    v302 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v303, v302);

v327:
    v303 = stack[-1];
    v302 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 35); /* mksq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v308;

v325:
    v302 = qvalue(elt(env, 13)); /* !*depend */
    v302 = (v302 == nil ? lisp_true : nil);
    goto v326;

v317:
    v302 = stack[-5];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = stack[-4];
    if (!(v303 == v302)) goto v328;
    v302 = qvalue(elt(env, 17)); /* !*commutedf */
    if (v302 == nil) goto v329;
    v302 = qvalue(elt(env, 13)); /* !*depend */
    if (!(v302 == nil)) goto v329;
    v303 = qvalue(elt(env, 2)); /* nil */
    v302 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v303, v302);

v329:
    v302 = qvalue(elt(env, 18)); /* !*simpnoncomdf */
    if (v302 == nil) goto v330;
    v303 = stack[-4];
    v302 = qvalue(elt(env, 15)); /* depl!* */
    v302 = Latsoc(nil, v303, v302);
    stack[-1] = v302;
    if (v302 == nil) goto v330;
    v302 = stack[-1];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    if (!(v302 == nil)) goto v330;
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    stack[-3] = v302;
    v304 = elt(env, 16); /* df */
    v303 = stack[-5];
    v302 = stack[-3];
    v302 = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v304 = elt(env, 16); /* df */
    v303 = stack[-4];
    v302 = stack[-3];
    v302 = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 36); /* invsq */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 25); /* multsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v308;

v330:
    v302 = stack[-5];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = elt(env, 19); /* int */
    if (!consp(v303)) goto v328;
    v303 = qcar(v303);
    if (!(v303 == v302)) goto v328;
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = stack[-4];
    if (v303 == v302) goto v331;
    v302 = qvalue(elt(env, 20)); /* !*allowdfint */
    if (v302 == nil) goto v328;
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    fn = elt(env, 37); /* simp!* */
    v303 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-4];
    fn = elt(env, 30); /* diffsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    fn = elt(env, 38); /* not_df_p */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    if (v302 == nil) goto v328;
    stack[-2] = elt(env, 16); /* df */
    stack[0] = elt(env, 19); /* int */
    v302 = stack[-1];
    fn = elt(env, 39); /* mk!*sq */
    v303 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = list3(stack[0], v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 40); /* reval */
    v303 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = list2star(stack[-2], v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v52;

v328:
    v302 = stack[-5];
    v302 = qcdr(v302);
    stack[0] = qcar(v302);
    v303 = stack[-5];
    v302 = stack[-4];
    fn = elt(env, 41); /* merge!-ind!-vars */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v304 = cons(stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v304;
    v303 = elt(env, 16); /* df */
    v302 = elt(env, 21); /* kvalue */
    v302 = get(v303, v302);
    env = stack[-7];
    fn = elt(env, 42); /* find_sub_df */
    v302 = (*qfn2(fn))(qenv(fn), v304, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-3] = v302;
    if (v302 == nil) goto v332;
    v302 = stack[-3];
    v302 = qcar(v302);
    fn = elt(env, 29); /* simp */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v333;

v333:
    v302 = stack[-3];
    if (v302 == nil) goto v308;
    v302 = stack[-3];
    v302 = qcar(v302);
    stack[-2] = v302;
    v302 = (Lisp_Object)17; /* 1 */
    stack[0] = v302;
    goto v334;

v334:
    v302 = stack[-2];
    v303 = qcdr(v302);
    v302 = stack[0];
    v302 = difference2(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = Lminusp(nil, v302);
    env = stack[-7];
    if (v302 == nil) goto v335;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v333;

v335:
    v303 = stack[-1];
    v302 = stack[-2];
    v302 = qcar(v302);
    fn = elt(env, 30); /* diffsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    v302 = stack[0];
    v302 = add1(v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[0] = v302;
    goto v334;

v332:
    v303 = elt(env, 16); /* df */
    v302 = stack[-1];
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v52;

v331:
    v304 = elt(env, 16); /* df */
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcar(v302);
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = stack[-5];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = list2star(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v52;

v315:
    v302 = stack[-2];
    v302 = qcdr(v302);
    stack[-2] = v302;
    v302 = stack[0];
    v302 = qcdr(v302);
    stack[0] = v302;
    v302 = stack[0];
    if (v302 == nil) goto v336;
    v302 = stack[-2];
    if (!(v302 == nil)) goto v314;

v336:
    v302 = stack[0];
    if (!(v302 == nil)) goto v316;
    v302 = stack[-2];
    if (!(v302 == nil)) goto v316;
    v302 = stack[-1];
    v302 = Lreverse(nil, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-2] = v302;
    v302 = stack[-5];
    v302 = qcdr(v302);
    stack[0] = v302;
    v303 = qvalue(elt(env, 2)); /* nil */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v137;

v137:
    v302 = stack[-2];
    v302 = qcar(v302);
    v302 = qcar(v302);
    if (v302 == nil) goto v337;
    v302 = stack[-2];
    stack[-4] = qcar(v302);
    v302 = stack[-3];
    v302 = qcar(v302);
    v303 = qcar(v302);
    v302 = stack[0];
    fn = elt(env, 43); /* pair */
    v303 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-3];
    v302 = qcar(v302);
    v302 = qcdr(v302);
    v302 = Lsubla(nil, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 25); /* multsq */
    v303 = (*qfn2(fn))(qenv(fn), stack[-4], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-1];
    fn = elt(env, 26); /* addsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v337;

v337:
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = stack[-2];
    v302 = qcdr(v302);
    stack[-2] = v302;
    v302 = stack[-2];
    if (v302 == nil) goto v308;
    else goto v137;

v313:
    v302 = stack[-5];
    v303 = qcar(v302);
    v302 = elt(env, 5); /* plus */
    if (v303 == v302) goto v338;
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v339;

v339:
    if (v302 == nil) goto v316;
    else goto v308;

v338:
    v302 = stack[-5];
    fn = elt(env, 29); /* simp */
    v303 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = stack[-4];
    fn = elt(env, 30); /* diffsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v339;

v310:
    v302 = stack[-5];
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = stack[-4];
    fn = elt(env, 30); /* diffsq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v311;

v97:
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v72;

v309:
    v303 = stack[-5];
    v302 = stack[-4];
    fn = elt(env, 34); /* depends */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    if (v302 == nil) goto v340;
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v341;

v341:
    if (v302 == nil) goto v342;
    v303 = qvalue(elt(env, 2)); /* nil */
    v302 = (Lisp_Object)17; /* 1 */
    popv(8);
    return cons(v303, v302);

v342:
    v302 = qvalue(elt(env, 14)); /* !*expanddf */
    if (v302 == nil) goto v343;
    v304 = stack[-4];
    v303 = stack[-5];
    v302 = qvalue(elt(env, 15)); /* depl!* */
    v302 = Latsoc(nil, v303, v302);
    v302 = qcdr(v302);
    stack[-3] = v302;
    v302 = Lmemq(nil, v304, v302);
    if (!(v302 == nil)) goto v343;
    v303 = qvalue(elt(env, 2)); /* nil */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    v302 = stack[-3];
    stack[-3] = v302;
    goto v344;

v344:
    v302 = stack[-3];
    if (v302 == nil) goto v308;
    v302 = stack[-3];
    v302 = qcar(v302);
    stack[-2] = v302;
    v304 = elt(env, 16); /* df */
    v303 = stack[-5];
    v302 = stack[-2];
    v302 = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v304 = elt(env, 16); /* df */
    v303 = stack[-2];
    v302 = stack[-4];
    v302 = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 29); /* simp */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 25); /* multsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[0], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    fn = elt(env, 26); /* addsq */
    v302 = (*qfn2(fn))(qenv(fn), stack[-1], v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    v302 = stack[-3];
    v302 = qcdr(v302);
    stack[-3] = v302;
    goto v344;

v343:
    v304 = elt(env, 16); /* df */
    v303 = stack[-5];
    v302 = stack[-4];
    v302 = list3(v304, v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    v302 = stack[-1];
    fn = elt(env, 31); /* opmtch */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-3] = v302;
    if (v302 == nil) goto v345;
    v302 = stack[-3];
    fn = elt(env, 29); /* simp */
    v302 = (*qfn1(fn))(qenv(fn), v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    goto v346;

v346:
    stack[-1] = v302;
    goto v308;

v345:
    v303 = stack[-1];
    v302 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 35); /* mksq */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    goto v346;

v340:
    v303 = stack[-5];
    v302 = qvalue(elt(env, 11)); /* powlis!* */
    v302 = Latsoc(nil, v303, v302);
    stack[-3] = v302;
    if (v302 == nil) goto v347;
    v302 = stack[-3];
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v302 = qcdr(v302);
    v303 = qcar(v302);
    v302 = stack[-4];
    fn = elt(env, 34); /* depends */
    v302 = (*qfn2(fn))(qenv(fn), v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    v302 = (v302 == nil ? lisp_true : nil);
    goto v348;

v348:
    if (v302 == nil) goto v349;
    v302 = qvalue(elt(env, 13)); /* !*depend */
    v302 = (v302 == nil ? lisp_true : nil);
    goto v341;

v349:
    v302 = qvalue(elt(env, 2)); /* nil */
    goto v341;

v347:
    v302 = qvalue(elt(env, 12)); /* t */
    goto v348;

v4:
    v303 = (Lisp_Object)17; /* 1 */
    v302 = (Lisp_Object)17; /* 1 */
    v302 = cons(v303, v302);
    nil = C_nil;
    if (exception_pending()) goto v306;
    env = stack[-7];
    stack[-1] = v302;
    goto v95;
/* error exit handlers */
v306:
    popv(8);
    return nil;
}



/* Code for ofsf_ir2atl */

static Lisp_Object MS_CDECL CC_ofsf_ir2atl(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v132, v138, v139;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "ofsf_ir2atl");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_ir2atl");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = v63;
    stack[0] = v1;
    stack[-5] = v0;
/* end of prologue */
    v132 = stack[0];
    v138 = qcar(v132);
    v132 = (Lisp_Object)17; /* 1 */
    v132 = cons(v138, v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    stack[-6] = v132;
    v132 = stack[0];
    v132 = qcdr(v132);
    stack[-3] = v132;
    goto v53;

v53:
    v132 = stack[-3];
    if (v132 == nil) goto v16;
    v132 = stack[-3];
    v132 = qcar(v132);
    v138 = v132;
    v132 = v138;
    v139 = qcar(v132);
    v132 = stack[-4];
    if (equal(v139, v132)) goto v42;
    v132 = nil;
    goto v356;

v356:
    stack[-2] = v132;
    v132 = stack[-2];
    fn = elt(env, 2); /* lastpair */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    stack[-1] = v132;
    v132 = stack[-3];
    v132 = qcdr(v132);
    stack[-3] = v132;
    v132 = stack[-1];
    if (!consp(v132)) goto v53;
    else goto v136;

v136:
    v132 = stack[-3];
    if (v132 == nil) { Lisp_Object res = stack[-2]; popv(8); return onevalue(res); }
    stack[0] = stack[-1];
    v132 = stack[-3];
    v132 = qcar(v132);
    v138 = v132;
    v132 = v138;
    v139 = qcar(v132);
    v132 = stack[-4];
    if (equal(v139, v132)) goto v80;
    v132 = nil;
    goto v40;

v40:
    v132 = Lrplacd(nil, stack[0], v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    v132 = stack[-1];
    fn = elt(env, 2); /* lastpair */
    v132 = (*qfn1(fn))(qenv(fn), v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    stack[-1] = v132;
    v132 = stack[-3];
    v132 = qcdr(v132);
    stack[-3] = v132;
    goto v136;

v80:
    v139 = stack[-5];
    v132 = v138;
    v138 = qcdr(v132);
    v132 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v132 = (*qfnn(fn))(qenv(fn), 3, v139, v138, v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    v132 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    goto v40;

v42:
    v139 = stack[-5];
    v132 = v138;
    v138 = qcdr(v132);
    v132 = stack[-6];
    fn = elt(env, 3); /* ofsf_entry2at */
    v132 = (*qfnn(fn))(qenv(fn), 3, v139, v138, v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    v132 = ncons(v132);
    nil = C_nil;
    if (exception_pending()) goto v3;
    env = stack[-7];
    goto v356;

v16:
    v132 = qvalue(elt(env, 1)); /* nil */
    { popv(8); return onevalue(v132); }
/* error exit handlers */
v3:
    popv(8);
    return nil;
}



/* Code for createtriple */

static Lisp_Object CC_createtriple(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v37, v76, v125;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for createtriple");
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
    v37 = (Lisp_Object)49; /* 3 */
    v37 = Lmkvect(nil, v37);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    stack[-2] = v37;
    v125 = stack[-2];
    v76 = (Lisp_Object)1; /* 0 */
    v37 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    *(Lisp_Object *)((char *)v125 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL))) = v37;
    v125 = stack[-2];
    v76 = (Lisp_Object)17; /* 1 */
    v37 = stack[0];
    *(Lisp_Object *)((char *)v125 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL))) = v37;
    v125 = stack[-2];
    v76 = (Lisp_Object)33; /* 2 */
    v37 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    *(Lisp_Object *)((char *)v125 + (CELL-TAG_VECTOR) + ((int32_t)v76/(16/CELL))) = v37;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)49; /* 3 */
    v37 = qvalue(elt(env, 2)); /* nil */
    v37 = ncons(v37);
    nil = C_nil;
    if (exception_pending()) goto v83;
    env = stack[-3];
    *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v37;
    v37 = qvalue(elt(env, 1)); /* fluidbibasistripleid */
    v37 = (Lisp_Object)((int32_t)(v37) + 0x10);
    qvalue(elt(env, 1)) = v37; /* fluidbibasistripleid */
    { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
v83:
    popv(4);
    return nil;
}



/* Code for rl_fvarl */

static Lisp_Object CC_rl_fvarl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v123;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rl_fvarl");
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
    v123 = v0;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_fvarl!* */
    v123 = ncons(v123);
    nil = C_nil;
    if (exception_pending()) goto v87;
    env = stack[-1];
    {
        Lisp_Object v86 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v86, v123);
    }
/* error exit handlers */
v87:
    popv(2);
    return nil;
}



/* Code for subtractinds */

static Lisp_Object MS_CDECL CC_subtractinds(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v126, v130;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subtractinds");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for subtractinds");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v63;
    stack[-2] = v1;
    stack[-3] = v0;
/* end of prologue */

v122:
    v126 = stack[-2];
    if (v126 == nil) goto v123;
    v126 = stack[-3];
    v130 = qcar(v126);
    v126 = stack[-2];
    v126 = qcar(v126);
    v126 = qcar(v126);
    v130 = difference2(v130, v126);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v126 = (Lisp_Object)1; /* 0 */
    v126 = (Lisp_Object)lessp2(v130, v126);
    nil = C_nil;
    if (exception_pending()) goto v119;
    v126 = v126 ? lisp_true : nil;
    env = stack[-5];
    if (v126 == nil) goto v109;
    v126 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v126); }

v109:
    v126 = stack[-3];
    v126 = qcdr(v126);
    stack[-4] = v126;
    v126 = stack[-2];
    v126 = qcdr(v126);
    stack[0] = v126;
    v126 = stack[-3];
    v130 = qcar(v126);
    v126 = stack[-2];
    v126 = qcar(v126);
    v126 = qcar(v126);
    v130 = difference2(v130, v126);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    v126 = stack[-1];
    v126 = cons(v130, v126);
    nil = C_nil;
    if (exception_pending()) goto v119;
    env = stack[-5];
    stack[-1] = v126;
    v126 = stack[0];
    stack[-2] = v126;
    v126 = stack[-4];
    stack[-3] = v126;
    goto v122;

v123:
    v126 = stack[-1];
        popv(6);
        return Lnreverse(nil, v126);
/* error exit handlers */
v119:
    popv(6);
    return nil;
}



/* Code for pasf_exprng1 */

static Lisp_Object CC_pasf_exprng1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v383, v384, v385, v269, v386, v387, v388;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for pasf_exprng1");
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
    v383 = v0;
/* end of prologue */
    v385 = v383;
    v384 = elt(env, 1); /* true */
    if (v385 == v384) goto v123;
    v385 = v383;
    v384 = elt(env, 3); /* false */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v34;

v34:
    if (!(v384 == nil)) { popv(6); return onevalue(v383); }
    v384 = v383;
    if (!consp(v384)) goto v36;
    v384 = v383;
    v384 = qcar(v384);
    goto v356;

v356:
    stack[-4] = v384;
    v385 = stack[-4];
    v384 = elt(env, 4); /* or */
    if (v385 == v384) goto v118;
    v385 = stack[-4];
    v384 = elt(env, 5); /* and */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v355;

v355:
    if (v384 == nil) goto v297;
    v384 = qvalue(elt(env, 2)); /* t */
    goto v37;

v37:
    if (v384 == nil) goto v65;
    v384 = qvalue(elt(env, 2)); /* t */
    goto v39;

v39:
    if (v384 == nil) goto v389;
    v383 = qcdr(v383);
    stack[-3] = v383;
    v383 = stack[-3];
    if (v383 == nil) goto v390;
    v383 = stack[-3];
    v383 = qcar(v383);
    v383 = CC_pasf_exprng1(env, v383);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-5];
    v383 = ncons(v383);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-5];
    stack[-1] = v383;
    stack[-2] = v383;
    goto v391;

v391:
    v383 = stack[-3];
    v383 = qcdr(v383);
    stack[-3] = v383;
    v383 = stack[-3];
    if (v383 == nil) goto v392;
    stack[0] = stack[-1];
    v383 = stack[-3];
    v383 = qcar(v383);
    v383 = CC_pasf_exprng1(env, v383);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-5];
    v383 = ncons(v383);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-5];
    v383 = Lrplacd(nil, stack[0], v383);
    nil = C_nil;
    if (exception_pending()) goto v272;
    env = stack[-5];
    v383 = stack[-1];
    v383 = qcdr(v383);
    stack[-1] = v383;
    goto v391;

v392:
    v383 = stack[-2];
    goto v46;

v46:
    v384 = v383;
    v383 = v384;
    if (v383 == nil) goto v9;
    v383 = v384;
    v383 = qcdr(v383);
    if (v383 == nil) goto v9;
    v383 = stack[-4];
    popv(6);
    return cons(v383, v384);

v9:
    v383 = v384;
    if (v383 == nil) goto v393;
    v383 = v384;
    v383 = qcar(v383);
    { popv(6); return onevalue(v383); }

v393:
    v384 = stack[-4];
    v383 = elt(env, 5); /* and */
    if (v384 == v383) goto v31;
    v383 = elt(env, 3); /* false */
    { popv(6); return onevalue(v383); }

v31:
    v383 = elt(env, 1); /* true */
    { popv(6); return onevalue(v383); }

v390:
    v383 = qvalue(elt(env, 10)); /* nil */
    goto v46;

v389:
    v385 = stack[-4];
    v384 = elt(env, 11); /* ex */
    if (v385 == v384) goto v312;
    v385 = stack[-4];
    v384 = elt(env, 12); /* all */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v394;

v394:
    if (v384 == nil) goto v395;
    stack[-1] = stack[-4];
    v384 = v383;
    v384 = qcdr(v384);
    stack[0] = qcar(v384);
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v383 = qcar(v383);
    v383 = CC_pasf_exprng1(env, v383);
    nil = C_nil;
    if (exception_pending()) goto v272;
    {
        Lisp_Object v396 = stack[-1];
        Lisp_Object v397 = stack[0];
        popv(6);
        return list3(v396, v397, v383);
    }

v395:
    v385 = stack[-4];
    v384 = elt(env, 13); /* ball */
    if (v385 == v384) goto v398;
    v385 = stack[-4];
    v384 = elt(env, 14); /* bex */
    if (!(v385 == v384)) { popv(6); return onevalue(v383); }
    v388 = stack[-4];
    v384 = v383;
    v384 = qcdr(v384);
    v387 = qcar(v384);
    v384 = v383;
    v384 = qcdr(v384);
    v384 = qcdr(v384);
    v384 = qcdr(v384);
    v386 = qcar(v384);
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v269 = qcar(v383);
    v385 = elt(env, 4); /* or */
    v384 = elt(env, 3); /* false */
    v383 = elt(env, 1); /* true */
    {
        popv(6);
        fn = elt(env, 15); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v388, v387, v386, v269, v385, v384, v383);
    }

v398:
    v388 = stack[-4];
    v384 = v383;
    v384 = qcdr(v384);
    v387 = qcar(v384);
    v384 = v383;
    v384 = qcdr(v384);
    v384 = qcdr(v384);
    v384 = qcdr(v384);
    v386 = qcar(v384);
    v383 = qcdr(v383);
    v383 = qcdr(v383);
    v269 = qcar(v383);
    v385 = elt(env, 5); /* and */
    v384 = elt(env, 1); /* true */
    v383 = elt(env, 3); /* false */
    {
        popv(6);
        fn = elt(env, 15); /* pasf_exprng1!-gand */
        return (*qfnn(fn))(qenv(fn), 7, v388, v387, v386, v269, v385, v384, v383);
    }

v312:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v394;

v65:
    v385 = stack[-4];
    v384 = elt(env, 7); /* impl */
    if (v385 == v384) goto v354;
    v385 = stack[-4];
    v384 = elt(env, 8); /* repl */
    if (v385 == v384) goto v352;
    v385 = stack[-4];
    v384 = elt(env, 9); /* equiv */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v39;

v352:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v39;

v354:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v39;

v297:
    v385 = stack[-4];
    v384 = elt(env, 6); /* not */
    v384 = (v385 == v384 ? lisp_true : nil);
    goto v37;

v118:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v355;

v36:
    v384 = v383;
    goto v356;

v123:
    v384 = qvalue(elt(env, 2)); /* t */
    goto v34;
/* error exit handlers */
v272:
    popv(6);
    return nil;
}



/* Code for intervalom */

static Lisp_Object CC_intervalom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v354, v128, v65;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for intervalom");
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
    v354 = stack[-2];
    v354 = qcdr(v354);
    v354 = qcar(v354);
    stack[-3] = v354;
    v354 = stack[-2];
    v354 = qcar(v354);
    stack[-1] = v354;
    v128 = stack[-1];
    v354 = elt(env, 1); /* lowupperlimit */
    if (!(v128 == v354)) goto v91;
    v354 = elt(env, 2); /* integer_interval */
    stack[-1] = v354;
    v354 = qvalue(elt(env, 3)); /* nil */
    stack[-3] = v354;
    v354 = stack[-2];
    v65 = qcar(v354);
    v128 = qvalue(elt(env, 3)); /* nil */
    v354 = stack[-2];
    v354 = qcdr(v354);
    v354 = list2star(v65, v128, v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    stack[-2] = v354;
    goto v91;

v91:
    v128 = stack[-1];
    v354 = qvalue(elt(env, 4)); /* valid_om!* */
    v354 = Lassoc(nil, v128, v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    stack[0] = v354;
    v354 = stack[-3];
    if (v354 == nil) goto v92;
    v354 = stack[-3];
    v354 = qcar(v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    v128 = Lintern(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = qvalue(elt(env, 5)); /* interval!* */
    v354 = Lassoc(nil, v128, v354);
    v354 = qcdr(v354);
    v354 = qcar(v354);
    stack[-1] = v354;
    goto v92;

v92:
    v354 = elt(env, 6); /* "<OMA>" */
    fn = elt(env, 12); /* printout */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = qvalue(elt(env, 7)); /* t */
    fn = elt(env, 13); /* indent!* */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = elt(env, 8); /* "<OMS cd=""" */
    fn = elt(env, 12); /* printout */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = stack[0];
    v354 = Lprinc(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = elt(env, 9); /* """ name=""" */
    v354 = Lprinc(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = stack[-1];
    v354 = Lprinc(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = elt(env, 10); /* """/>" */
    v354 = Lprinc(nil, v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = stack[-2];
    v354 = qcdr(v354);
    v354 = qcdr(v354);
    fn = elt(env, 14); /* multiom */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = qvalue(elt(env, 3)); /* nil */
    fn = elt(env, 13); /* indent!* */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    env = stack[-4];
    v354 = elt(env, 11); /* "</OMA>" */
    fn = elt(env, 12); /* printout */
    v354 = (*qfn1(fn))(qenv(fn), v354);
    nil = C_nil;
    if (exception_pending()) goto v105;
    v354 = nil;
    { popv(5); return onevalue(v354); }
/* error exit handlers */
v105:
    popv(5);
    return nil;
}



/* Code for reduceroots */

static Lisp_Object CC_reduceroots(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v19, v42, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reduceroots");
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
    v19 = nil;
    goto v122;

v122:
    v42 = stack[-1];
    if (v42 == nil) { popv(3); return onevalue(v19); }
    v42 = stack[0];
    v39 = qcar(v42);
    v42 = elt(env, 2); /* sqrt */
    if (!consp(v39)) goto v51;
    v39 = qcar(v39);
    if (!(v39 == v42)) goto v51;
    v39 = stack[-1];
    v42 = stack[0];
    v42 = qcar(v42);
    fn = elt(env, 3); /* tryreduction */
    v19 = (*qfnn(fn))(qenv(fn), 3, v39, v42, v19);
    nil = C_nil;
    if (exception_pending()) goto v92;
    env = stack[-2];
    goto v51;

v51:
    v42 = stack[-1];
    v42 = qcdr(v42);
    stack[-1] = v42;
    v42 = stack[0];
    v42 = qcdr(v42);
    stack[0] = v42;
    goto v122;
/* error exit handlers */
v92:
    popv(3);
    return nil;
}



/* Code for reprod */

static Lisp_Object CC_reprod(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v129, v356;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reprod");
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

v61:
    v129 = stack[-1];
    if (v129 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v129 = stack[-1];
    v356 = qcar(v129);
    v129 = (Lisp_Object)17; /* 1 */
    v129 = cons(v356, v129);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v356 = ncons(v129);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    v129 = stack[0];
    fn = elt(env, 2); /* multf */
    v129 = (*qfn2(fn))(qenv(fn), v356, v129);
    nil = C_nil;
    if (exception_pending()) goto v75;
    env = stack[-2];
    stack[0] = v129;
    v129 = stack[-1];
    v129 = qcdr(v129);
    stack[-1] = v129;
    goto v61;
/* error exit handlers */
v75:
    popv(3);
    return nil;
}



/* Code for fnreval */

static Lisp_Object MS_CDECL CC_fnreval(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v4, v49;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "fnreval");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for fnreval");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = v63;
    stack[-1] = v1;
    stack[0] = v0;
/* end of prologue */
    stack[-2] = nil;
    goto v127;

v127:
    v4 = stack[0];
    if (v4 == nil) goto v34;
    v49 = stack[-1];
    v4 = qvalue(elt(env, 1)); /* t */
    if (v49 == v4) goto v16;
    v4 = stack[-1];
    if (v4 == nil) goto v75;
    v4 = stack[-1];
    v4 = qcar(v4);
    if (v4 == nil) goto v401;
    v4 = stack[0];
    v4 = qcar(v4);
    v49 = v4;
    goto v131;

v131:
    v4 = stack[-2];
    v4 = cons(v49, v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    stack[-2] = v4;
    v4 = stack[0];
    v4 = qcdr(v4);
    stack[0] = v4;
    v4 = stack[-1];
    v4 = qcdr(v4);
    stack[-1] = v4;
    goto v127;

v401:
    v4 = stack[0];
    v49 = qcar(v4);
    v4 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v4 = (*qfn2(fn))(qenv(fn), v49, v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    v49 = v4;
    goto v131;

v75:
    stack[-5] = stack[-2];
    v4 = stack[0];
    stack[-3] = v4;
    v4 = stack[-3];
    if (v4 == nil) goto v37;
    v4 = stack[-3];
    v4 = qcar(v4);
    v49 = v4;
    v4 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v4 = (*qfn2(fn))(qenv(fn), v49, v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    v4 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    stack[-1] = v4;
    stack[-2] = v4;
    goto v39;

v39:
    v4 = stack[-3];
    v4 = qcdr(v4);
    stack[-3] = v4;
    v4 = stack[-3];
    if (v4 == nil) goto v107;
    stack[0] = stack[-1];
    v4 = stack[-3];
    v4 = qcar(v4);
    v49 = v4;
    v4 = stack[-4];
    fn = elt(env, 3); /* reval1 */
    v4 = (*qfn2(fn))(qenv(fn), v49, v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    v4 = ncons(v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    v4 = Lrplacd(nil, stack[0], v4);
    nil = C_nil;
    if (exception_pending()) goto v390;
    env = stack[-6];
    v4 = stack[-1];
    v4 = qcdr(v4);
    stack[-1] = v4;
    goto v39;

v107:
    v4 = stack[-2];
    goto v91;

v91:
    {
        Lisp_Object v58 = stack[-5];
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v58, v4);
    }

v37:
    v4 = qvalue(elt(env, 2)); /* nil */
    goto v91;

v16:
    v49 = stack[-2];
    v4 = stack[0];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v49, v4);
    }

v34:
    v4 = stack[-2];
    {
        popv(7);
        fn = elt(env, 4); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v4);
    }
/* error exit handlers */
v390:
    popv(7);
    return nil;
}



/* Code for sqprla */

static Lisp_Object CC_sqprla(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v87, v86;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sqprla");
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
    v87 = v0;
/* end of prologue */
    v87 = qcar(v87);
    fn = elt(env, 1); /* prepsq!* */
    v86 = (*qfn1(fn))(qenv(fn), v87);
    nil = C_nil;
    if (exception_pending()) goto v51;
    env = stack[-1];
    v87 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* maprintla */
        return (*qfn2(fn))(qenv(fn), v86, v87);
    }
/* error exit handlers */
v51:
    popv(2);
    return nil;
}



/* Code for gfftimes */

static Lisp_Object CC_gfftimes(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v69, v82, v81;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gfftimes");
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
/* copy arguments values to proper place */
    v82 = v1;
    v81 = v0;
/* end of prologue */
    v69 = v81;
    v69 = qcar(v69);
    stack[-4] = v69;
    v69 = v81;
    v69 = qcdr(v69);
    stack[-3] = v69;
    v69 = v82;
    v69 = qcar(v69);
    stack[-2] = v69;
    v69 = v82;
    v69 = qcdr(v69);
    stack[-1] = v69;
    v82 = stack[-4];
    v69 = stack[-2];
    stack[0] = times2(v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v82 = stack[-3];
    v69 = stack[-1];
    v69 = times2(v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    stack[0] = difference2(stack[0], v69);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v82 = stack[-4];
    v69 = stack[-1];
    stack[-1] = times2(v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v82 = stack[-3];
    v69 = stack[-2];
    v69 = times2(v82, v69);
    nil = C_nil;
    if (exception_pending()) goto v68;
    env = stack[-5];
    v69 = plus2(stack[-1], v69);
    nil = C_nil;
    if (exception_pending()) goto v68;
    {
        Lisp_Object v40 = stack[0];
        popv(6);
        return cons(v40, v69);
    }
/* error exit handlers */
v68:
    popv(6);
    return nil;
}



/* Code for lispcodeexp */

static Lisp_Object CC_lispcodeexp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v227, v226, v467;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lispcodeexp");
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
/* copy arguments values to proper place */
    stack[-3] = v1;
    stack[-2] = v0;
/* end of prologue */

v115:
    v227 = stack[-2];
    if (is_number(v227)) goto v127;
    v226 = stack[-2];
    v227 = elt(env, 1); /* e */
    if (v226 == v227) goto v75;
    v227 = stack[-2];
    if (!consp(v227)) goto v296;
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = elt(env, 5); /* (!:rd!: !:cr!: !:crn!: !:gi!:) */
    v227 = Lmemq(nil, v226, v227);
    goto v39;

v39:
    if (v227 == nil) goto v124;
    v227 = qvalue(elt(env, 6)); /* irena!-constants */
    if (v227 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v227 = stack[-2];
    if (v227 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v227 = stack[-2];
    v227 = Lstringp(nil, v227);
    env = stack[-5];
    if (!(v227 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v227 = stack[-2];
    fn = elt(env, 21); /* check!-for!-irena!-constants */
    v227 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }

v124:
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = elt(env, 7); /* expt */
    if (v226 == v227) goto v354;
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = elt(env, 12); /* quotient */
    if (v226 == v227) goto v469;
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = elt(env, 14); /* recip */
    if (v226 == v227) goto v470;
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = elt(env, 16); /* difference */
    if (v226 == v227) goto v471;
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = qvalue(elt(env, 19)); /* !*lisparithexpops!* */
    v227 = Lmemq(nil, v226, v227);
    if (v227 == nil) goto v472;
    v227 = qvalue(elt(env, 13)); /* nil */
    goto v255;

v255:
    if (v227 == nil) goto v473;
    v227 = stack[-2];
    stack[-3] = v227;
    v227 = stack[-3];
    if (v227 == nil) goto v321;
    v227 = stack[-3];
    v227 = qcar(v227);
    v226 = v227;
    v227 = qvalue(elt(env, 13)); /* nil */
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-1] = v227;
    stack[-2] = v227;
    goto v250;

v250:
    v227 = stack[-3];
    v227 = qcdr(v227);
    stack[-3] = v227;
    v227 = stack[-3];
    if (v227 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v227 = stack[-3];
    v227 = qcar(v227);
    v226 = v227;
    v227 = qvalue(elt(env, 13)); /* nil */
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = Lrplacd(nil, stack[0], v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-1];
    v227 = qcdr(v227);
    stack[-1] = v227;
    goto v250;

v321:
    v227 = qvalue(elt(env, 13)); /* nil */
    { popv(6); return onevalue(v227); }

v473:
    v227 = stack[-2];
    stack[-4] = v227;
    v227 = stack[-4];
    if (v227 == nil) goto v474;
    v227 = stack[-4];
    v227 = qcar(v227);
    v226 = v227;
    v227 = stack[-3];
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-1] = v227;
    stack[-2] = v227;
    goto v475;

v475:
    v227 = stack[-4];
    v227 = qcdr(v227);
    stack[-4] = v227;
    v227 = stack[-4];
    if (v227 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v227 = stack[-4];
    v227 = qcar(v227);
    v226 = v227;
    v227 = stack[-3];
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = ncons(v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = Lrplacd(nil, stack[0], v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-1];
    v227 = qcdr(v227);
    stack[-1] = v227;
    goto v475;

v474:
    v227 = qvalue(elt(env, 13)); /* nil */
    { popv(6); return onevalue(v227); }

v472:
    v227 = stack[-2];
    v226 = qcar(v227);
    v227 = qvalue(elt(env, 20)); /* !*lisplogexpops!* */
    v227 = Lmemq(nil, v226, v227);
    v227 = (v227 == nil ? lisp_true : nil);
    goto v255;

v471:
    stack[-4] = elt(env, 17); /* plus */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[0] = elt(env, 18); /* minus */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = list2(stack[0], v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v476 = stack[-4];
        Lisp_Object v477 = stack[-1];
        popv(6);
        return list3(v476, v477, v227);
    }

v470:
    v227 = qvalue(elt(env, 15)); /* !*period */
    if (v227 == nil) goto v478;
    stack[-1] = elt(env, 12); /* quotient */
    stack[0] = elt(env, 3); /* 1.0 */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v479 = stack[-1];
        Lisp_Object v480 = stack[0];
        popv(6);
        return list3(v479, v480, v227);
    }

v478:
    stack[-1] = elt(env, 12); /* quotient */
    stack[0] = (Lisp_Object)17; /* 1 */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v481 = stack[-1];
        Lisp_Object v222 = stack[0];
        popv(6);
        return list3(v481, v222, v227);
    }

v469:
    stack[-1] = elt(env, 12); /* quotient */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = qvalue(elt(env, 4)); /* t */
    stack[0] = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = qvalue(elt(env, 4)); /* t */
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v482 = stack[-1];
        Lisp_Object v483 = stack[0];
        popv(6);
        return list3(v482, v483, v227);
    }

v354:
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = elt(env, 1); /* e */
    if (v226 == v227) goto v133;
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = elt(env, 8); /* (quotient 1 2) */
    if (equal(v226, v227)) goto v56;
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = elt(env, 10); /* !:rd!: */
    if (!consp(v226)) goto v96;
    v226 = qcar(v226);
    if (!(v226 == v227)) goto v96;
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v227 = qcar(v227);
    fn = elt(env, 22); /* realrat */
    v227 = (*qfn1(fn))(qenv(fn), v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    stack[-1] = v227;
    v226 = stack[-1];
    v227 = elt(env, 11); /* (1 . 2) */
    if (equal(v226, v227)) goto v8;
    stack[0] = elt(env, 7); /* expt */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    stack[-2] = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v467 = elt(env, 12); /* quotient */
    v227 = stack[-1];
    v226 = qcar(v227);
    v227 = stack[-1];
    v227 = qcdr(v227);
    v226 = list3(v467, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = qvalue(elt(env, 13)); /* nil */
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v484 = stack[0];
        Lisp_Object v485 = stack[-2];
        popv(6);
        return list3(v484, v485, v227);
    }

v8:
    stack[0] = elt(env, 9); /* sqrt */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v486 = stack[0];
        popv(6);
        return list2(v486, v227);
    }

v96:
    stack[0] = elt(env, 7); /* expt */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = stack[-3];
    stack[-1] = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v226 = qcar(v227);
    v227 = qvalue(elt(env, 13)); /* nil */
    v227 = CC_lispcodeexp(env, v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    {
        Lisp_Object v224 = stack[0];
        Lisp_Object v225 = stack[-1];
        popv(6);
        return list3(v224, v225, v227);
    }

v56:
    v226 = elt(env, 9); /* sqrt */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcar(v227);
    v226 = list2(v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-3];
    stack[-2] = v226;
    stack[-3] = v227;
    goto v115;

v133:
    v226 = elt(env, 2); /* exp */
    v227 = stack[-2];
    v227 = qcdr(v227);
    v227 = qcdr(v227);
    v227 = qcar(v227);
    v226 = list2(v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-3];
    stack[-2] = v226;
    stack[-3] = v227;
    goto v115;

v296:
    v227 = qvalue(elt(env, 4)); /* t */
    goto v39;

v75:
    v226 = elt(env, 2); /* exp */
    v227 = elt(env, 3); /* 1.0 */
    v226 = list2(v226, v227);
    nil = C_nil;
    if (exception_pending()) goto v468;
    env = stack[-5];
    v227 = stack[-3];
    stack[-2] = v226;
    stack[-3] = v227;
    goto v115;

v127:
    v227 = stack[-3];
    if (v227 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v227 = stack[-2];
        popv(6);
        return Lfloat(nil, v227);
/* error exit handlers */
v468:
    popv(6);
    return nil;
}



/* Code for incident1 */

static Lisp_Object MS_CDECL CC_incident1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v63, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v2, v3, v400, v382, v79;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "incident1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for incident1");
#endif
    if (stack >= stacklimit)
    {
        push3(v63,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0,v1,v63);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v400 = v63;
    v382 = v1;
    v79 = v0;
/* end of prologue */
    v3 = v79;
    v2 = v382;
    v2 = qcar(v2);
    v2 = qcar(v2);
    if (v3 == v2) goto v35;
    v3 = v79;
    v2 = v382;
    v2 = qcdr(v2);
    v2 = qcar(v2);
    v2 = qcar(v2);
    if (v3 == v2) goto v118;
    v3 = v79;
    v2 = v382;
    v2 = qcdr(v2);
    v2 = qcdr(v2);
    v2 = qcar(v2);
    v2 = qcar(v2);
    if (v3 == v2) goto v65;
    v2 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v2); }

v65:
    v2 = v382;
    v2 = qcar(v2);
    stack[-1] = qcar(v2);
    stack[0] = v400;
    v2 = v382;
    v2 = qcdr(v2);
    v2 = qcar(v2);
    v2 = qcar(v2);
    v3 = v400;
    v2 = cons(v2, v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v11;
    {
        Lisp_Object v4 = stack[-1];
        Lisp_Object v49 = stack[0];
        popv(3);
        return acons(v4, v49, v2);
    }

v118:
    v2 = v382;
    v2 = qcdr(v2);
    v2 = qcdr(v2);
    v2 = qcar(v2);
    stack[-1] = qcar(v2);
    stack[0] = v400;
    v2 = v382;
    v2 = qcar(v2);
    v2 = qcar(v2);
    v3 = v400;
    v2 = cons(v2, v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v11;
    {
        Lisp_Object v46 = stack[-1];
        Lisp_Object v391 = stack[0];
        popv(3);
        return acons(v46, v391, v2);
    }

v35:
    v2 = v382;
    v2 = qcdr(v2);
    v2 = qcar(v2);
    stack[-1] = qcar(v2);
    stack[0] = v400;
    v2 = v382;
    v2 = qcdr(v2);
    v2 = qcdr(v2);
    v2 = qcar(v2);
    v2 = qcar(v2);
    v3 = v400;
    v2 = cons(v2, v3);
    nil = C_nil;
    if (exception_pending()) goto v11;
    env = stack[-2];
    v2 = ncons(v2);
    nil = C_nil;
    if (exception_pending()) goto v11;
    {
        Lisp_Object v487 = stack[-1];
        Lisp_Object v295 = stack[0];
        popv(3);
        return acons(v487, v295, v2);
    }
/* error exit handlers */
v11:
    popv(3);
    return nil;
}



/* Code for negex */

static Lisp_Object CC_negex(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v356, v36;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for negex");
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
    goto v61;

v61:
    v356 = stack[-1];
    if (v356 == nil) goto v122;
    v356 = stack[-1];
    v356 = qcar(v356);
    stack[0] = qcar(v356);
    v356 = stack[-1];
    v356 = qcar(v356);
    v356 = qcdr(v356);
    fn = elt(env, 1); /* negf */
    v36 = (*qfn1(fn))(qenv(fn), v356);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-3];
    v356 = stack[-2];
    v356 = acons(stack[0], v36, v356);
    nil = C_nil;
    if (exception_pending()) goto v110;
    env = stack[-3];
    stack[-2] = v356;
    v356 = stack[-1];
    v356 = qcdr(v356);
    stack[-1] = v356;
    goto v61;

v122:
    v356 = stack[-2];
    {
        popv(4);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v356);
    }
/* error exit handlers */
v110:
    popv(4);
    return nil;
}



/* Code for msolve!-psys1 */

static Lisp_Object CC_msolveKpsys1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v79, v10;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for msolve-psys1");
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
    stack[-5] = v1;
    stack[0] = v0;
/* end of prologue */
    v79 = qvalue(elt(env, 1)); /* nil */
    v79 = ncons(v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    v10 = v79;
    v79 = stack[0];
    stack[-4] = v79;
    goto v86;

v86:
    v79 = stack[-4];
    if (v79 == nil) { popv(8); return onevalue(v10); }
    v79 = stack[-4];
    v79 = qcar(v79);
    stack[-3] = v79;
    v79 = qvalue(elt(env, 1)); /* nil */
    stack[-6] = v79;
    v79 = v10;
    stack[-2] = v79;
    goto v111;

v111:
    v79 = stack[-2];
    if (v79 == nil) goto v90;
    v79 = stack[-2];
    v79 = qcar(v79);
    stack[-1] = v79;
    v10 = stack[-3];
    v79 = stack[-1];
    fn = elt(env, 3); /* subf */
    v79 = (*qfn2(fn))(qenv(fn), v10, v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    v79 = qcar(v79);
    fn = elt(env, 4); /* moduntag */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    fn = elt(env, 5); /* general!-reduce!-mod!-p */
    v79 = (*qfn1(fn))(qenv(fn), v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    v10 = v79;
    v79 = v10;
    if (v79 == nil) goto v83;
    v79 = v10;
    if (!consp(v79)) goto v82;
    v79 = v10;
    v79 = qcar(v79);
    v79 = (consp(v79) ? nil : lisp_true);
    goto v69;

v69:
    if (!(v79 == nil)) goto v76;
    v79 = stack[-5];
    fn = elt(env, 6); /* msolve!-poly */
    v79 = (*qfn2(fn))(qenv(fn), v10, v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    stack[0] = v79;
    goto v142;

v142:
    v79 = stack[0];
    if (v79 == nil) goto v76;
    v79 = stack[0];
    v79 = qcar(v79);
    v10 = stack[-1];
    v10 = Lappend(nil, v10, v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    v79 = stack[-6];
    v79 = cons(v10, v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    stack[-6] = v79;
    v79 = stack[0];
    v79 = qcdr(v79);
    stack[0] = v79;
    goto v142;

v76:
    v79 = stack[-2];
    v79 = qcdr(v79);
    stack[-2] = v79;
    goto v111;

v82:
    v79 = qvalue(elt(env, 2)); /* t */
    goto v69;

v83:
    v10 = stack[-1];
    v79 = stack[-6];
    v79 = cons(v10, v79);
    nil = C_nil;
    if (exception_pending()) goto v295;
    env = stack[-7];
    stack[-6] = v79;
    goto v76;

v90:
    v79 = stack[-6];
    v10 = v79;
    v79 = stack[-4];
    v79 = qcdr(v79);
    stack[-4] = v79;
    goto v86;
/* error exit handlers */
v295:
    popv(8);
    return nil;
}



/* Code for settreset */

static Lisp_Object MS_CDECL CC_settreset(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v62;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "settreset");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for settreset");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* end of prologue */
    v62 = qvalue(elt(env, 1)); /* nil */
    qvalue(elt(env, 2)) = v62; /* fluidbibasisjanettreerootnode */
    v62 = qvalue(elt(env, 1)); /* nil */
    v62 = ncons(v62);
    nil = C_nil;
    if (exception_pending()) goto v127;
    env = stack[0];
    qvalue(elt(env, 3)) = v62; /* fluidbibasissett */
    v62 = nil;
    { popv(1); return onevalue(v62); }
/* error exit handlers */
v127:
    popv(1);
    return nil;
}



setup_type const u34_setup[] =
{
    {"mk+scal+mult+mat",        too_few_2,      CC_mkLscalLmultLmat,wrong_no_2},
    {"rl_multsurep",            too_few_2,      CC_rl_multsurep,wrong_no_2},
    {"symbolsom",               CC_symbolsom,   too_many_1,    wrong_no_1},
    {"f4",                      CC_f4,          too_many_1,    wrong_no_1},
    {"intrdsortin",             too_few_2,      CC_intrdsortin,wrong_no_2},
    {"new_prove",               too_few_2,      CC_new_prove,  wrong_no_2},
    {"verify_tens_ids",         CC_verify_tens_ids,too_many_1, wrong_no_1},
    {"list2vect*",              too_few_2,      CC_list2vectH, wrong_no_2},
    {"get-current-representation",CC_getKcurrentKrepresentation,too_many_1,wrong_no_1},
    {"make-image",              too_few_2,      CC_makeKimage, wrong_no_2},
    {"simprd",                  CC_simprd,      too_many_1,    wrong_no_1},
    {"evalgreaterp",            too_few_2,      CC_evalgreaterp,wrong_no_2},
    {"mktag",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_mktag},
    {"fnom",                    CC_fnom,        too_many_1,    wrong_no_1},
    {"multup",                  CC_multup,      too_many_1,    wrong_no_1},
    {"diffp",                   too_few_2,      CC_diffp,      wrong_no_2},
    {"ofsf_ir2atl",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_ofsf_ir2atl},
    {"createtriple",            CC_createtriple,too_many_1,    wrong_no_1},
    {"rl_fvarl",                CC_rl_fvarl,    too_many_1,    wrong_no_1},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"pasf_exprng1",            CC_pasf_exprng1,too_many_1,    wrong_no_1},
    {"intervalom",              CC_intervalom,  too_many_1,    wrong_no_1},
    {"reduceroots",             too_few_2,      CC_reduceroots,wrong_no_2},
    {"reprod",                  too_few_2,      CC_reprod,     wrong_no_2},
    {"fnreval",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_fnreval},
    {"sqprla",                  too_few_2,      CC_sqprla,     wrong_no_2},
    {"gfftimes",                too_few_2,      CC_gfftimes,   wrong_no_2},
    {"lispcodeexp",             too_few_2,      CC_lispcodeexp,wrong_no_2},
    {"incident1",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_incident1},
    {"negex",                   CC_negex,       too_many_1,    wrong_no_1},
    {"msolve-psys1",            too_few_2,      CC_msolveKpsys1,wrong_no_2},
    {"settreset",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_settreset},
    {NULL, (one_args *)"u34", (two_args *)"2134 269352 9044758", 0}
};

/* end of generated code */
