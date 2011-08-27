
/* $destdir\u07.c        Machine generated C code */

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


/* Code for mcharg2 */

static Lisp_Object MS_CDECL CC_mcharg2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v33;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "mcharg2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mcharg2");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-6] = v3;
    stack[-7] = v2;
    stack[-8] = v1;
    stack[-9] = v0;
/* end of prologue */
    v31 = stack[-9];
    if (v31 == nil) { Lisp_Object res = stack[-7]; popv(12); return onevalue(res); }
    v31 = stack[-9];
    v32 = qcar(v31);
    v31 = stack[-8];
    v31 = qcar(v31);
    fn = elt(env, 2); /* mchk */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v32 = v31;
    v31 = stack[-9];
    v31 = qcdr(v31);
    stack[-9] = v31;
    v31 = stack[-8];
    v31 = qcdr(v31);
    stack[-8] = v31;
    v31 = v32;
    stack[-10] = v31;
    goto v35;

v35:
    v31 = stack[-10];
    if (v31 == nil) goto v36;
    v31 = stack[-10];
    v31 = qcar(v31);
    stack[-2] = v31;
    stack[-1] = stack[-9];
    v33 = stack[-2];
    v32 = stack[-8];
    v31 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v33, v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v32 = stack[-7];
    v31 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v32 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v31 = stack[-6];
    v31 = CC_mcharg2(env, 4, stack[-1], stack[0], v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    stack[-5] = v31;
    v31 = stack[-5];
    fn = elt(env, 5); /* lastpair */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    stack[-4] = v31;
    v31 = stack[-10];
    v31 = qcdr(v31);
    stack[-10] = v31;
    v31 = stack[-4];
    if (!consp(v31)) goto v35;
    else goto v37;

v37:
    v31 = stack[-10];
    if (v31 == nil) { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }
    stack[-3] = stack[-4];
    v31 = stack[-10];
    v31 = qcar(v31);
    stack[-2] = v31;
    stack[-1] = stack[-9];
    v33 = stack[-2];
    v32 = stack[-8];
    v31 = stack[-6];
    fn = elt(env, 3); /* updtemplate */
    stack[0] = (*qfnn(fn))(qenv(fn), 3, v33, v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v32 = stack[-7];
    v31 = stack[-2];
    fn = elt(env, 4); /* msappend */
    v32 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v31 = stack[-6];
    v31 = CC_mcharg2(env, 4, stack[-1], stack[0], v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v31 = Lrplacd(nil, stack[-3], v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    v31 = stack[-4];
    fn = elt(env, 5); /* lastpair */
    v31 = (*qfn1(fn))(qenv(fn), v31);
    nil = C_nil;
    if (exception_pending()) goto v34;
    env = stack[-11];
    stack[-4] = v31;
    v31 = stack[-10];
    v31 = qcdr(v31);
    stack[-10] = v31;
    goto v37;

v36:
    v31 = qvalue(elt(env, 1)); /* nil */
    { popv(12); return onevalue(v31); }
/* error exit handlers */
v34:
    popv(12);
    return nil;
}



/* Code for mri_pasf2mriat */

static Lisp_Object CC_mri_pasf2mriat(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v41, v42, v43;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for mri_pasf2mriat");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v41 = v1;
    v42 = v0;
/* end of prologue */
    v43 = v42;
    v43 = qcar(v43);
    v42 = qcdr(v42);
    v42 = qcar(v42);
    {
        fn = elt(env, 1); /* mri_0mk2 */
        return (*qfnn(fn))(qenv(fn), 3, v43, v42, v41);
    }
}



/* Code for ibalp_varlt1 */

static Lisp_Object CC_ibalp_varlt1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v48, v49, v23;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_varlt1");
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
    v23 = v0;
/* end of prologue */
    v49 = v23;
    v48 = (Lisp_Object)1; /* 0 */
    if (v49 == v48) goto v50;
    v49 = v23;
    v48 = (Lisp_Object)17; /* 1 */
    v48 = (v49 == v48 ? lisp_true : nil);
    goto v51;

v51:
    if (v48 == nil) goto v52;
    v48 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v48); }

v52:
    v48 = v23;
    if (symbolp(v48)) goto v36;
    v48 = v23;
    fn = elt(env, 3); /* ibalp_argn */
    v48 = (*qfn1(fn))(qenv(fn), v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[-1] = v48;
    goto v54;

v54:
    v48 = stack[-1];
    if (v48 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    v48 = stack[-1];
    v48 = qcar(v48);
    v49 = v48;
    v48 = stack[0];
    v48 = CC_ibalp_varlt1(env, v49, v48);
    nil = C_nil;
    if (exception_pending()) goto v53;
    env = stack[-2];
    stack[0] = v48;
    v48 = stack[-1];
    v48 = qcdr(v48);
    stack[-1] = v48;
    goto v54;

v36:
    v49 = v23;
    v48 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* lto_insertq */
        return (*qfn2(fn))(qenv(fn), v49, v48);
    }

v50:
    v48 = qvalue(elt(env, 1)); /* t */
    goto v51;
/* error exit handlers */
v53:
    popv(3);
    return nil;
}



/* Code for checktag */

static Lisp_Object CC_checktag(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for checktag");
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
    v30 = v0;
/* end of prologue */
    v58 = qvalue(elt(env, 1)); /* char */
    if (equal(v58, v30)) goto v59;
    v58 = elt(env, 2); /* "Problem" */
    v30 = elt(env, 3); /* "problem" */
    fn = elt(env, 4); /* errorml */
    v30 = (*qfn2(fn))(qenv(fn), v58, v30);
    errexit();
    goto v59;

v59:
    v30 = nil;
    return onevalue(v30);
}



/* Code for reval1 */

static Lisp_Object CC_reval1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v149, v150, v151, v152, v153;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for reval1");
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
    v149 = qvalue(elt(env, 1)); /* !*revalp */
    if (v149 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v149 = qvalue(elt(env, 2)); /* varstack!* */
    stack[-3] = qvalue(elt(env, 2)); /* varstack!* */
    qvalue(elt(env, 2)) = v149; /* varstack!* */
    v149 = stack[-2];
    if (v149 == nil) goto v43;
    v149 = stack[-2];
    v149 = Lstringp(nil, v149);
    env = stack[-4];
    if (v149 == nil) goto v58;
    v149 = stack[-2];
    goto v40;

v40:
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    { popv(5); return onevalue(v149); }

v58:
    v149 = stack[-2];
    v149 = integerp(v149);
    if (v149 == nil) goto v18;
    v150 = qvalue(elt(env, 4)); /* dmode!* */
    v149 = elt(env, 5); /* convert */
    v149 = Lflagp(nil, v150, v149);
    env = stack[-4];
    if (v149 == nil) goto v154;
    v150 = stack[-2];
    v149 = stack[-1];
    fn = elt(env, 31); /* reval2 */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v154:
    v149 = stack[-2];
    goto v40;

v18:
    v149 = stack[-2];
    if (!consp(v149)) goto v21;
    v149 = stack[-2];
    v149 = qcar(v149);
    if (symbolp(v149)) goto v156;
    v153 = elt(env, 11); /* "Syntax error:" */
    v152 = stack[-2];
    v151 = elt(env, 12); /* "invalid" */
    v150 = qvalue(elt(env, 3)); /* nil */
    v149 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 32); /* msgpri */
    v149 = (*qfnn(fn))(qenv(fn), 5, v153, v152, v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v42;

v42:
    v149 = stack[-2];
    fn = elt(env, 33); /* getrtype */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[0] = v149;
    if (v149 == nil) goto v157;
    v150 = stack[0];
    v149 = elt(env, 10); /* evfn */
    v149 = get(v150, v149);
    env = stack[-4];
    v151 = v149;
    if (v149 == nil) goto v158;
    v150 = stack[-2];
    v149 = stack[-1];
    v149 = Lapply2(nil, 3, v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v158:
    v150 = elt(env, 21); /* "Missing evaluation for type" */
    v149 = stack[0];
    v149 = list2(v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v150 = v149;
    v149 = v150;
    qvalue(elt(env, 22)) = v149; /* errmsg!* */
    v149 = qvalue(elt(env, 23)); /* !*protfg */
    if (!(v149 == nil)) goto v159;
    v149 = v150;
    fn = elt(env, 34); /* lprie */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v159;

v159:
    v149 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v149 = nil;
    goto v40;

v157:
    v149 = stack[-2];
    if (!consp(v149)) goto v160;
    v149 = stack[-2];
    v149 = qcdr(v149);
    if (!consp(v149)) goto v161;
    v149 = stack[-2];
    v149 = qcdr(v149);
    v149 = qcar(v149);
    fn = elt(env, 33); /* getrtype */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v151 = v149;
    if (v149 == nil) goto v162;
    v150 = v151;
    v149 = elt(env, 24); /* list */
    if (v150 == v149) goto v163;
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v164;

v164:
    if (v149 == nil) goto v165;
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v166:
    if (v149 == nil) goto v167;
    v151 = stack[0];
    v150 = stack[-2];
    v149 = stack[-1];
    v149 = Lapply2(nil, 3, v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v167:
    v150 = stack[-2];
    v149 = stack[-1];
    fn = elt(env, 31); /* reval2 */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v165:
    v150 = v151;
    v149 = elt(env, 25); /* aggregatefn */
    v149 = get(v150, v149);
    env = stack[-4];
    stack[0] = v149;
    if (v149 == nil) goto v168;
    v150 = stack[0];
    v149 = elt(env, 26); /* matrixmap */
    if (v150 == v149) goto v169;
    v149 = qvalue(elt(env, 9)); /* t */
    goto v170;

v170:
    if (v149 == nil) goto v171;
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 28); /* boolean */
    v149 = Lflagp(nil, v150, v149);
    env = stack[-4];
    if (v149 == nil) goto v172;
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v172:
    v149 = qvalue(elt(env, 29)); /* !*listargs */
    if (v149 == nil) goto v173;
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v173:
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 30); /* listargp */
    v149 = Lflagp(nil, v150, v149);
    env = stack[-4];
    v149 = (v149 == nil ? lisp_true : nil);
    goto v166;

v171:
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v169:
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 27); /* matmapfn */
    v149 = Lflagp(nil, v150, v149);
    env = stack[-4];
    goto v170;

v168:
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v163:
    v149 = stack[-2];
    v149 = qcdr(v149);
    v149 = qcdr(v149);
    goto v164;

v162:
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v161:
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v160:
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v166;

v156:
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 13); /* !*sq */
    if (v150 == v149) goto v174;
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 15); /* remember */
    v149 = Lflagp(nil, v150, v149);
    env = stack[-4];
    if (v149 == nil) goto v175;
    v150 = stack[-2];
    v149 = stack[-1];
    fn = elt(env, 35); /* rmmbreval */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v175:
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 16); /* opfn */
    v149 = Lflagp(nil, v150, v149);
    env = stack[-4];
    if (v149 == nil) goto v176;
    v149 = stack[-2];
    fn = elt(env, 36); /* opfneval */
    v150 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v149 = stack[-1];
    v149 = CC_reval1(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v176:
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 17); /* psopfn */
    v149 = get(v150, v149);
    env = stack[-4];
    stack[0] = v149;
    if (v149 == nil) goto v177;
    v150 = stack[0];
    v149 = stack[-2];
    v149 = qcdr(v149);
    v149 = Lapply1(nil, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-2] = v149;
    v150 = stack[0];
    v149 = elt(env, 18); /* cleanupfn */
    v149 = get(v150, v149);
    env = stack[-4];
    stack[0] = v149;
    if (v149 == nil) goto v178;
    v151 = stack[0];
    v150 = stack[-2];
    v149 = stack[-1];
    v149 = Lapply2(nil, 3, v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    stack[-2] = v149;
    goto v178;

v178:
    v149 = stack[-2];
    goto v40;

v177:
    v149 = stack[-2];
    v150 = qcar(v149);
    v149 = elt(env, 19); /* rtype */
    v150 = get(v150, v149);
    env = stack[-4];
    v149 = elt(env, 20); /* array */
    if (!(v150 == v149)) goto v42;
    v149 = stack[-2];
    fn = elt(env, 37); /* getelv */
    v150 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    v149 = stack[-1];
    v149 = CC_reval1(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v174:
    v149 = stack[-2];
    v149 = qcdr(v149);
    v149 = qcdr(v149);
    v149 = qcar(v149);
    if (v149 == nil) goto v179;
    v149 = qvalue(elt(env, 14)); /* !*resimp */
    if (!(v149 == nil)) goto v179;
    v149 = stack[-1];
    if (v149 == nil) goto v180;
    v149 = stack[-2];
    v149 = qcdr(v149);
    v149 = qcar(v149);
    fn = elt(env, 38); /* prepsqxx */
    v149 = (*qfn1(fn))(qenv(fn), v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v180:
    v149 = stack[-2];
    goto v40;

v179:
    v150 = stack[-2];
    v149 = stack[-1];
    fn = elt(env, 31); /* reval2 */
    v149 = (*qfn2(fn))(qenv(fn), v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v21:
    v149 = qvalue(elt(env, 6)); /* subfg!* */
    if (v149 == nil) goto v181;
    v149 = stack[-2];
    if (!(symbolp(v149))) goto v42;
    v150 = stack[-2];
    v149 = elt(env, 7); /* avalue */
    v149 = get(v150, v149);
    env = stack[-4];
    stack[0] = v149;
    if (v149 == nil) goto v42;
    v150 = stack[-2];
    v149 = qvalue(elt(env, 2)); /* varstack!* */
    v149 = Lmemq(nil, v150, v149);
    if (v149 == nil) goto v182;
    v153 = qvalue(elt(env, 3)); /* nil */
    v152 = stack[-2];
    v151 = elt(env, 8); /* "improperly defined in terms of itself" */
    v150 = qvalue(elt(env, 3)); /* nil */
    v149 = qvalue(elt(env, 9)); /* t */
    fn = elt(env, 32); /* msgpri */
    v149 = (*qfnn(fn))(qenv(fn), 5, v153, v152, v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v42;

v182:
    v150 = stack[-2];
    v149 = qvalue(elt(env, 2)); /* varstack!* */
    v149 = cons(v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    qvalue(elt(env, 2)) = v149; /* varstack!* */
    v149 = stack[0];
    v150 = qcar(v149);
    v149 = elt(env, 10); /* evfn */
    v149 = get(v150, v149);
    env = stack[-4];
    v151 = v149;
    if (v149 == nil) goto v183;
    v150 = stack[-2];
    v149 = stack[-1];
    v149 = Lapply2(nil, 3, v151, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v183:
    v149 = stack[0];
    v149 = qcdr(v149);
    v150 = qcar(v149);
    v149 = stack[-1];
    v149 = CC_reval1(env, v150, v149);
    nil = C_nil;
    if (exception_pending()) goto v155;
    env = stack[-4];
    goto v40;

v181:
    v149 = stack[-2];
    goto v40;

v43:
    v149 = qvalue(elt(env, 3)); /* nil */
    goto v40;
/* error exit handlers */
v155:
    env = stack[-4];
    qvalue(elt(env, 2)) = stack[-3]; /* varstack!* */
    popv(5);
    return nil;
}



/* Code for exchk2 */

static Lisp_Object CC_exchk2(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v32, v33, v134;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for exchk2");
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

v52:
    v32 = stack[-1];
    if (v32 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v32 = stack[-1];
    v32 = qcdr(v32);
    stack[-2] = v32;
    v32 = qvalue(elt(env, 1)); /* !*intstr */
    if (v32 == nil) goto v197;
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcdr(v32);
    fn = elt(env, 8); /* prepsq!* */
    v32 = (*qfn1(fn))(qenv(fn), v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    goto v22;

v22:
    v134 = v32;
    v33 = (Lisp_Object)17; /* 1 */
    if (v134 == v33) goto v198;
    v33 = qvalue(elt(env, 3)); /* !*nosqrts */
    if (v33 == nil) goto v199;
    v134 = elt(env, 4); /* expt */
    v33 = stack[-1];
    v33 = qcar(v33);
    v33 = qcar(v33);
    v32 = list3(v134, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v33 = v32;
    goto v200;

v200:
    v32 = stack[0];
    v32 = cons(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    stack[0] = v32;
    v32 = stack[-2];
    stack[-1] = v32;
    goto v52;

v199:
    v134 = v32;
    v33 = elt(env, 5); /* (quotient 1 2) */
    if (equal(v134, v33)) goto v201;
    v134 = v32;
    v33 = elt(env, 7); /* 0.5 */
    if (equal(v134, v33)) goto v10;
    v134 = elt(env, 4); /* expt */
    v33 = stack[-1];
    v33 = qcar(v33);
    v33 = qcar(v33);
    v32 = list3(v134, v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v33 = v32;
    goto v200;

v10:
    v33 = elt(env, 6); /* sqrt */
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v32 = list2(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v33 = v32;
    goto v200;

v201:
    v33 = elt(env, 6); /* sqrt */
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v32 = list2(v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    v33 = v32;
    goto v200;

v198:
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcar(v32);
    v33 = v32;
    goto v200;

v197:
    v32 = stack[-1];
    v32 = qcar(v32);
    v32 = qcdr(v32);
    v32 = qcar(v32);
    if (v32 == nil) goto v145;
    v32 = stack[-1];
    v32 = qcar(v32);
    v33 = qcdr(v32);
    v32 = elt(env, 2); /* prepf */
    fn = elt(env, 9); /* sqform */
    v32 = (*qfn2(fn))(qenv(fn), v33, v32);
    nil = C_nil;
    if (exception_pending()) goto v183;
    env = stack[-3];
    goto v22;

v145:
    v32 = (Lisp_Object)1; /* 0 */
    goto v22;
/* error exit handlers */
v183:
    popv(4);
    return nil;
}



/* Code for vevtdeg */

static Lisp_Object CC_vevtdeg(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v46, v25, v45;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for vevtdeg");
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
    v25 = nil;
    goto v52;

v52:
    v46 = stack[0];
    if (v46 == nil) goto v203;
    v46 = stack[0];
    v46 = qcar(v46);
    v46 = cons(v46, v25);
    nil = C_nil;
    if (exception_pending()) goto v204;
    env = stack[-1];
    v25 = v46;
    v46 = stack[0];
    v46 = qcdr(v46);
    stack[0] = v46;
    goto v52;

v203:
    v46 = (Lisp_Object)1; /* 0 */
    goto v205;

v205:
    v45 = v25;
    if (v45 == nil) { popv(2); return onevalue(v46); }
    v45 = v25;
    v45 = qcar(v45);
    v46 = (Lisp_Object)(int32_t)((int32_t)v45 + (int32_t)v46 - TAG_FIXNUM);
    v25 = qcdr(v25);
    goto v205;
/* error exit handlers */
v204:
    popv(2);
    return nil;
}



/* Code for getphystype */

static Lisp_Object CC_getphystype(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v10, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for getphystype");
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
    v10 = stack[0];
    fn = elt(env, 9); /* physopp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    if (v10 == nil) goto v205;
    v10 = stack[0];
    fn = elt(env, 10); /* scalopp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    if (v10 == nil) goto v57;
    v10 = elt(env, 1); /* scalar */
    { popv(3); return onevalue(v10); }

v57:
    v10 = stack[0];
    fn = elt(env, 11); /* vecopp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    if (v10 == nil) goto v43;
    v10 = elt(env, 2); /* vector */
    { popv(3); return onevalue(v10); }

v43:
    v10 = stack[0];
    fn = elt(env, 12); /* tensopp */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    if (v10 == nil) goto v58;
    v10 = elt(env, 3); /* tensor */
    { popv(3); return onevalue(v10); }

v58:
    v10 = stack[0];
    fn = elt(env, 13); /* statep */
    v10 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    if (v10 == nil) goto v35;
    v10 = elt(env, 4); /* state */
    { popv(3); return onevalue(v10); }

v35:
    v10 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v10); }

v205:
    v10 = stack[0];
    if (!consp(v10)) goto v209;
    v10 = stack[0];
    v9 = qcar(v10);
    v10 = elt(env, 6); /* phystype */
    v9 = get(v9, v10);
    env = stack[-2];
    v10 = v9;
    if (!(v9 == nil)) { popv(3); return onevalue(v10); }
    v10 = stack[0];
    v9 = qcar(v10);
    v10 = elt(env, 7); /* phystypefn */
    v9 = get(v9, v10);
    env = stack[-2];
    v10 = v9;
    if (v9 == nil) goto v210;
    v9 = v10;
    v10 = stack[0];
    v10 = qcdr(v10);
        popv(3);
        return Lapply1(nil, v9, v10);

v210:
    v10 = stack[0];
    fn = elt(env, 14); /* collectphystype */
    v9 = (*qfn1(fn))(qenv(fn), v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    v10 = v9;
    if (v9 == nil) goto v49;
    v9 = v10;
    v9 = qcdr(v9);
    if (v9 == nil) goto v193;
    v9 = elt(env, 4); /* state */
    v10 = Lmember(nil, v9, v10);
    if (v10 == nil) goto v4;
    v10 = elt(env, 4); /* state */
    { popv(3); return onevalue(v10); }

v4:
    stack[-1] = elt(env, 0); /* getphystype */
    v9 = elt(env, 8); /* "PHYSOP type conflict in" */
    v10 = stack[0];
    v10 = list2(v9, v10);
    nil = C_nil;
    if (exception_pending()) goto v138;
    env = stack[-2];
    {
        Lisp_Object v132 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* rederr2 */
        return (*qfn2(fn))(qenv(fn), v132, v10);
    }

v193:
    v10 = qcar(v10);
    { popv(3); return onevalue(v10); }

v49:
    v10 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v10); }

v209:
    v10 = qvalue(elt(env, 5)); /* nil */
    { popv(3); return onevalue(v10); }
/* error exit handlers */
v138:
    popv(3);
    return nil;
}



/* Code for form */

static Lisp_Object CC_form(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v218, v185, v186;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for form");
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
    v185 = v0;
/* end of prologue */
    v218 = v185;
    if (!consp(v218)) goto v200;
    v218 = v185;
    v186 = qcar(v218);
    v218 = elt(env, 1); /* always_nform */
    v218 = Lflagp(nil, v186, v218);
    env = stack[0];
    goto v203;

v203:
    if (v218 == nil) goto v59;
    v218 = v185;
    {
        popv(1);
        fn = elt(env, 11); /* n_form */
        return (*qfn1(fn))(qenv(fn), v218);
    }

v59:
    v218 = qvalue(elt(env, 3)); /* !*rlisp88 */
    if (v218 == nil) goto v18;
    v186 = qvalue(elt(env, 5)); /* !*mode */
    v218 = elt(env, 6); /* symbolic */
    if (v186 == v218) goto v28;
    v218 = qvalue(elt(env, 7)); /* t */
    goto v148;

v148:
    if (v218 == nil) goto v15;
    v185 = elt(env, 9); /* "algebraic expression" */
    v218 = elt(env, 10); /* "Rlisp88 form" */
    {
        popv(1);
        fn = elt(env, 12); /* typerr */
        return (*qfn2(fn))(qenv(fn), v185, v218);
    }

v15:
    v186 = v185;
    v185 = qvalue(elt(env, 4)); /* !*vars!* */
    v218 = qvalue(elt(env, 5)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 13); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v186, v185, v218);
    }

v28:
    v186 = v185;
    v218 = elt(env, 8); /* modefn */
    v218 = Lflagp(nil, v186, v218);
    env = stack[0];
    if (v218 == nil) goto v191;
    v186 = v185;
    v218 = elt(env, 6); /* symbolic */
    v218 = (v186 == v218 ? lisp_true : nil);
    v218 = (v218 == nil ? lisp_true : nil);
    goto v181;

v181:
    if (v218 == nil) goto v207;
    v218 = qvalue(elt(env, 7)); /* t */
    goto v148;

v207:
    v186 = v185;
    v218 = elt(env, 8); /* modefn */
    v218 = Lflagpcar(nil, v186, v218);
    env = stack[0];
    if (v218 == nil) goto v219;
    v218 = v185;
    v186 = qcar(v218);
    v218 = elt(env, 6); /* symbolic */
    v218 = (v186 == v218 ? lisp_true : nil);
    v218 = (v218 == nil ? lisp_true : nil);
    goto v148;

v219:
    v218 = qvalue(elt(env, 2)); /* nil */
    goto v148;

v191:
    v218 = qvalue(elt(env, 2)); /* nil */
    goto v181;

v18:
    v186 = v185;
    v185 = qvalue(elt(env, 4)); /* !*vars!* */
    v218 = qvalue(elt(env, 5)); /* !*mode */
    {
        popv(1);
        fn = elt(env, 13); /* form1 */
        return (*qfnn(fn))(qenv(fn), 3, v186, v185, v218);
    }

v200:
    v218 = qvalue(elt(env, 2)); /* nil */
    goto v203;
}



/* Code for dp_ecart */

static Lisp_Object CC_dp_ecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v29;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for dp_ecart");
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
    v29 = stack[0];
    if (v29 == nil) goto v220;
    v29 = stack[0];
    fn = elt(env, 1); /* dp!=ecart */
    stack[-1] = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    v29 = stack[0];
    fn = elt(env, 2); /* dp_lmon */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v58;
    env = stack[-2];
    fn = elt(env, 3); /* mo_ecart */
    v29 = (*qfn1(fn))(qenv(fn), v29);
    nil = C_nil;
    if (exception_pending()) goto v58;
    {
        Lisp_Object v221 = stack[-1];
        popv(3);
        return difference2(v221, v29);
    }

v220:
    v29 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(v29); }
/* error exit handlers */
v58:
    popv(3);
    return nil;
}



/* Code for maprint */

static Lisp_Object CC_maprint(Lisp_Object env,
                         Lisp_Object v1, Lisp_Object v2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v107, v108;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for maprint");
#endif
    if (stack >= stacklimit)
    {
        push2(v2,v1);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v1,v2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    v250 = v2;
    stack[-3] = v1;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* p!*!* */
    qvalue(elt(env, 1)) = nil; /* p!*!* */
    qvalue(elt(env, 1)) = v250; /* p!*!* */
    stack[0] = nil;
    v250 = qvalue(elt(env, 1)); /* p!*!* */
    stack[-2] = v250;
    v250 = stack[-3];
    if (v250 == nil) goto v40;
    v250 = stack[-3];
    if (!consp(v250)) goto v200;
    v250 = stack[-3];
    v250 = qcar(v250);
    if (!consp(v250)) goto v251;
    v250 = stack[-3];
    v107 = qcar(v250);
    v250 = stack[-2];
    v250 = CC_maprint(env, v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v39;

v39:
    v250 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = qvalue(elt(env, 2)); /* nil */
    qvalue(elt(env, 13)) = v250; /* obrkp!* */
    v250 = qvalue(elt(env, 11)); /* orig!* */
    stack[0] = v250;
    v107 = qvalue(elt(env, 12)); /* posn!* */
    v250 = (Lisp_Object)289; /* 18 */
    v250 = (Lisp_Object)lessp2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v250 = v250 ? lisp_true : nil;
    env = stack[-5];
    if (v250 == nil) goto v114;
    v250 = qvalue(elt(env, 12)); /* posn!* */
    goto v253;

v253:
    qvalue(elt(env, 11)) = v250; /* orig!* */
    v250 = stack[-3];
    v250 = qcdr(v250);
    if (v250 == nil) goto v254;
    v108 = elt(env, 14); /* !*comma!* */
    v107 = (Lisp_Object)1; /* 0 */
    v250 = stack[-3];
    v250 = qcdr(v250);
    fn = elt(env, 16); /* inprint */
    v250 = (*qfnn(fn))(qenv(fn), 3, v108, v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v254;

v254:
    v250 = qvalue(elt(env, 3)); /* t */
    qvalue(elt(env, 13)) = v250; /* obrkp!* */
    v250 = stack[0];
    qvalue(elt(env, 11)) = v250; /* orig!* */
    v250 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = stack[-3];
    goto v52;

v52:
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    { popv(6); return onevalue(v250); }

v114:
    v107 = qvalue(elt(env, 11)); /* orig!* */
    v250 = (Lisp_Object)49; /* 3 */
    v250 = plus2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v253;

v251:
    v250 = stack[-3];
    v107 = qcar(v250);
    v250 = elt(env, 8); /* pprifn */
    v250 = get(v107, v250);
    env = stack[-5];
    stack[-1] = v250;
    if (v250 == nil) goto v184;
    v108 = stack[-1];
    v107 = stack[-3];
    v250 = stack[-2];
    v107 = Lapply2(nil, 3, v108, v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = elt(env, 9); /* failed */
    if (!(v107 == v250)) goto v5;

v184:
    v250 = stack[-3];
    v107 = qcar(v250);
    v250 = elt(env, 10); /* prifn */
    v250 = get(v107, v250);
    env = stack[-5];
    stack[-1] = v250;
    if (v250 == nil) goto v255;
    v107 = stack[-1];
    v250 = stack[-3];
    v107 = Lapply1(nil, v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = elt(env, 9); /* failed */
    if (!(v107 == v250)) goto v5;

v255:
    v250 = stack[-3];
    v107 = qcar(v250);
    v250 = elt(env, 5); /* infix */
    v250 = get(v107, v250);
    env = stack[-5];
    stack[-1] = v250;
    if (v250 == nil) goto v256;
    v107 = stack[-1];
    v250 = stack[-2];
    v250 = (Lisp_Object)greaterp2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v250 = v250 ? lisp_true : nil;
    env = stack[-5];
    v250 = (v250 == nil ? lisp_true : nil);
    stack[-2] = v250;
    v250 = stack[-2];
    if (v250 == nil) goto v257;
    v250 = qvalue(elt(env, 11)); /* orig!* */
    stack[0] = v250;
    v250 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v107 = qvalue(elt(env, 12)); /* posn!* */
    v250 = (Lisp_Object)289; /* 18 */
    v250 = (Lisp_Object)lessp2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v250 = v250 ? lisp_true : nil;
    env = stack[-5];
    if (v250 == nil) goto v258;
    v250 = qvalue(elt(env, 12)); /* posn!* */
    goto v259;

v259:
    qvalue(elt(env, 11)) = v250; /* orig!* */
    goto v257;

v257:
    v250 = stack[-3];
    v108 = qcar(v250);
    v107 = stack[-1];
    v250 = stack[-3];
    v250 = qcdr(v250);
    fn = elt(env, 16); /* inprint */
    v250 = (*qfnn(fn))(qenv(fn), 3, v108, v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = stack[-2];
    if (v250 == nil) goto v260;
    v250 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = stack[0];
    qvalue(elt(env, 11)) = v250; /* orig!* */
    goto v260;

v260:
    v250 = stack[-3];
    goto v52;

v258:
    v107 = qvalue(elt(env, 11)); /* orig!* */
    v250 = (Lisp_Object)49; /* 3 */
    v250 = plus2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v259;

v256:
    v250 = stack[-3];
    v250 = qcar(v250);
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v39;

v5:
    v250 = stack[-3];
    goto v52;

v200:
    v250 = stack[-3];
    v250 = Lsimple_vectorp(nil, v250);
    env = stack[-5];
    if (v250 == nil) goto v197;
    v107 = stack[-3];
    v250 = qvalue(elt(env, 1)); /* p!*!* */
    fn = elt(env, 17); /* vec!-maprin */
    v250 = (*qfn2(fn))(qenv(fn), v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v58;

v58:
    v250 = stack[-3];
    goto v52;

v197:
    v250 = stack[-3];
    if (is_number(v250)) goto v154;
    v250 = qvalue(elt(env, 3)); /* t */
    goto v261;

v261:
    if (v250 == nil) goto v262;
    v250 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v58;

v262:
    v250 = elt(env, 6); /* "(" */
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = stack[-3];
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    v250 = elt(env, 7); /* ")" */
    fn = elt(env, 15); /* prin2!* */
    v250 = (*qfn1(fn))(qenv(fn), v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    env = stack[-5];
    goto v58;

v154:
    v107 = stack[-3];
    v250 = (Lisp_Object)1; /* 0 */
    v250 = (Lisp_Object)lessp2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v250 = v250 ? lisp_true : nil;
    env = stack[-5];
    if (v250 == nil) goto v196;
    v108 = stack[-2];
    v107 = elt(env, 4); /* minus */
    v250 = elt(env, 5); /* infix */
    v250 = get(v107, v250);
    env = stack[-5];
    v250 = (Lisp_Object)lesseq2(v108, v250);
    nil = C_nil;
    if (exception_pending()) goto v252;
    v250 = v250 ? lisp_true : nil;
    env = stack[-5];
    goto v261;

v196:
    v250 = qvalue(elt(env, 3)); /* t */
    goto v261;

v40:
    v250 = qvalue(elt(env, 2)); /* nil */
    goto v52;
/* error exit handlers */
v252:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* p!*!* */
    popv(6);
    return nil;
}



/* Code for gperm1 */

static Lisp_Object MS_CDECL CC_gperm1(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v263, v28, v26;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "gperm1");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm1");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v47:
    v263 = stack[-4];
    if (v263 == nil) goto v40;
    v263 = stack[-4];
    v263 = qcdr(v263);
    stack[-5] = v263;
    v263 = stack[-4];
    v28 = qcar(v263);
    v263 = stack[-2];
    v263 = cons(v28, v263);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    stack[0] = v263;
    v28 = stack[-3];
    v263 = stack[-2];
    v263 = cons(v28, v263);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    fn = elt(env, 1); /* rev */
    v28 = (*qfn2(fn))(qenv(fn), stack[-4], v263);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    v263 = stack[-1];
    v263 = cons(v28, v263);
    nil = C_nil;
    if (exception_pending()) goto v49;
    env = stack[-6];
    stack[-1] = v263;
    v263 = stack[0];
    stack[-2] = v263;
    v263 = stack[-5];
    stack[-4] = v263;
    goto v47;

v40:
    v26 = stack[-3];
    v28 = stack[-2];
    v263 = stack[-1];
    popv(7);
    return acons(v26, v28, v263);
/* error exit handlers */
v49:
    popv(7);
    return nil;
}



/* Code for sfto_dcontentf1 */

static Lisp_Object CC_sfto_dcontentf1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v26, v27;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_dcontentf1");
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

v50:
    v27 = stack[0];
    v26 = (Lisp_Object)17; /* 1 */
    if (v27 == v26) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v26 = stack[-1];
    if (!consp(v26)) goto v30;
    v26 = stack[-1];
    v26 = qcar(v26);
    v26 = (consp(v26) ? nil : lisp_true);
    goto v55;

v55:
    if (v26 == nil) goto v146;
    v26 = stack[-1];
    fn = elt(env, 2); /* minusf */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    if (v26 == nil) goto v264;
    v26 = stack[-1];
    fn = elt(env, 3); /* negf */
    v26 = (*qfn1(fn))(qenv(fn), v26);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    v27 = v26;
    goto v249;

v249:
    v26 = stack[0];
    {
        popv(4);
        fn = elt(env, 4); /* sfto_gcdf */
        return (*qfn2(fn))(qenv(fn), v27, v26);
    }

v264:
    v26 = stack[-1];
    v27 = v26;
    goto v249;

v146:
    v26 = stack[-1];
    v26 = qcdr(v26);
    stack[-2] = v26;
    v26 = stack[-1];
    v26 = qcar(v26);
    v27 = qcdr(v26);
    v26 = stack[0];
    v26 = CC_sfto_dcontentf1(env, v27, v26);
    nil = C_nil;
    if (exception_pending()) goto v216;
    env = stack[-3];
    stack[0] = v26;
    v26 = stack[-2];
    stack[-1] = v26;
    goto v50;

v30:
    v26 = qvalue(elt(env, 1)); /* t */
    goto v55;
/* error exit handlers */
v216:
    popv(4);
    return nil;
}



/* Code for ckrn1 */

static Lisp_Object CC_ckrn1(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v138, v132;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ckrn1");
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
    v138 = stack[0];
    if (!consp(v138)) goto v38;
    v138 = stack[0];
    v138 = qcar(v138);
    v138 = (consp(v138) ? nil : lisp_true);
    goto v50;

v50:
    if (!(v138 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

v30:
    v138 = stack[0];
    v138 = qcar(v138);
    v138 = qcdr(v138);
    v132 = CC_ckrn1(env, v138);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-2];
    v138 = stack[-1];
    fn = elt(env, 3); /* gck2 */
    v138 = (*qfn2(fn))(qenv(fn), v132, v138);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-2];
    stack[-1] = v138;
    v138 = stack[0];
    v138 = qcdr(v138);
    if (v138 == nil) goto v249;
    v138 = stack[0];
    v138 = qcdr(v138);
    if (!consp(v138)) goto v23;
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v138 = (consp(v138) ? nil : lisp_true);
    goto v49;

v49:
    if (v138 == nil) goto v144;
    v138 = qvalue(elt(env, 1)); /* t */
    goto v246;

v246:
    if (v138 == nil) goto v37;
    v138 = stack[0];
    v138 = qcdr(v138);
    v132 = CC_ckrn1(env, v138);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-2];
    v138 = stack[-1];
    {
        popv(3);
        fn = elt(env, 3); /* gck2 */
        return (*qfn2(fn))(qenv(fn), v132, v138);
    }

v37:
    v138 = stack[0];
    v138 = qcdr(v138);
    stack[0] = v138;
    goto v30;

v144:
    v138 = stack[0];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v132 = qcar(v138);
    v138 = stack[0];
    v138 = qcdr(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = (v132 == v138 ? lisp_true : nil);
    v138 = (v138 == nil ? lisp_true : nil);
    goto v246;

v23:
    v138 = qvalue(elt(env, 1)); /* t */
    goto v49;

v249:
    v138 = qvalue(elt(env, 2)); /* !*ncmp */
    if (v138 == nil) goto v22;
    v138 = stack[0];
    v138 = qcar(v138);
    v138 = qcar(v138);
    v138 = qcar(v138);
    fn = elt(env, 4); /* noncomp1 */
    v138 = (*qfn1(fn))(qenv(fn), v138);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-2];
    if (!(v138 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }

v22:
    v138 = stack[0];
    v138 = qcar(v138);
    v132 = qcar(v138);
    v138 = stack[-1];
    v138 = cons(v132, v138);
    nil = C_nil;
    if (exception_pending()) goto v187;
    popv(3);
    return ncons(v138);

v38:
    v138 = qvalue(elt(env, 1)); /* t */
    goto v50;
/* error exit handlers */
v187:
    popv(3);
    return nil;
}



/* Code for ofsf_smwcpknowl */

static Lisp_Object CC_ofsf_smwcpknowl(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ofsf_smwcpknowl");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v0;
/* end of prologue */
    v56 = qvalue(elt(env, 1)); /* !*rlsusi */
    if (v56 == nil) goto v47;
    v56 = v57;
    {
        fn = elt(env, 2); /* cl_susicpknowl */
        return (*qfn1(fn))(qenv(fn), v56);
    }

v47:
    v56 = v57;
    {
        fn = elt(env, 3); /* ofsf_smcpknowl */
        return (*qfn1(fn))(qenv(fn), v56);
    }
}



/* Code for symbol */

static Lisp_Object CC_symbol(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for symbol");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v0;
/* end of prologue */
    v50 = elt(env, 1); /* symbol!-character */
    return get(v51, v50);
}



/* Code for kernord */

static Lisp_Object CC_kernord(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30, v58;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for kernord");
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
    v30 = v1;
    stack[0] = v0;
/* end of prologue */
    v58 = stack[0];
    fn = elt(env, 1); /* kernord!-split */
    v30 = (*qfn2(fn))(qenv(fn), v58, v30);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    stack[0] = v30;
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 2); /* kernord!-sort */
    stack[-1] = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v266;
    env = stack[-2];
    v30 = stack[0];
    v30 = qcdr(v30);
    fn = elt(env, 2); /* kernord!-sort */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v266;
    {
        Lisp_Object v17 = stack[-1];
        popv(3);
        return Lappend(nil, v17, v30);
    }
/* error exit handlers */
v266:
    popv(3);
    return nil;
}



/* Code for ibalp_istotal */

static Lisp_Object CC_ibalp_istotal(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v221, v197;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_istotal");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v221 = v0;
/* end of prologue */

v267:
    v197 = v221;
    if (v197 == nil) goto v220;
    v197 = v221;
    v197 = qcar(v197);
    v197 = qcdr(v197);
    v197 = qcdr(v197);
    v197 = qcar(v197);
    if (v197 == nil) goto v38;
    v221 = qcdr(v221);
    goto v267;

v38:
    v221 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v221);

v220:
    v221 = qvalue(elt(env, 1)); /* t */
    return onevalue(v221);
}



/* Code for multiom */

static Lisp_Object CC_multiom(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v17, v18;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for multiom");
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
    v17 = stack[0];
    v18 = Llength(nil, v17);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-1];
    v17 = (Lisp_Object)17; /* 1 */
    if (v18 == v17) goto v52;
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 2); /* objectom */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v268;
    env = stack[-1];
    v17 = stack[0];
    v17 = qcdr(v17);
    v17 = CC_multiom(env, v17);
    nil = C_nil;
    if (exception_pending()) goto v268;
    goto v59;

v59:
    v17 = nil;
    { popv(2); return onevalue(v17); }

v52:
    v17 = stack[0];
    v17 = qcar(v17);
    fn = elt(env, 2); /* objectom */
    v17 = (*qfn1(fn))(qenv(fn), v17);
    nil = C_nil;
    if (exception_pending()) goto v268;
    goto v59;
/* error exit handlers */
v268:
    popv(2);
    return nil;
}



/* Code for ps!:get!-term */

static Lisp_Object CC_psTgetKterm(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v186, v184, v31;
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
    v186 = stack[-2];
    fn = elt(env, 5); /* ps!:order */
    stack[0] = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    v186 = stack[-2];
    fn = elt(env, 6); /* ps!:last!-term */
    v186 = (*qfn1(fn))(qenv(fn), v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    stack[-3] = stack[0];
    stack[0] = v186;
    v184 = stack[-1];
    v186 = stack[-3];
    v186 = (Lisp_Object)lessp2(v184, v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v186 = v186 ? lisp_true : nil;
    env = stack[-4];
    if (v186 == nil) goto v145;
    v184 = qvalue(elt(env, 1)); /* nil */
    v186 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v184, v186);

v145:
    v184 = stack[-1];
    v186 = stack[0];
    v186 = (Lisp_Object)greaterp2(v184, v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v186 = v186 ? lisp_true : nil;
    env = stack[-4];
    if (v186 == nil) goto v147;
    v186 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v186); }

v147:
    v184 = stack[-1];
    v186 = stack[-3];
    stack[0] = difference2(v184, v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    v186 = stack[-2];
    if (!consp(v186)) goto v28;
    v186 = stack[-2];
    v184 = qcar(v186);
    v186 = elt(env, 3); /* !:ps!: */
    if (v184 == v186) goto v207;
    v186 = stack[-2];
    v184 = qcar(v186);
    v186 = elt(env, 4); /* dname */
    v186 = get(v184, v186);
    env = stack[-4];
    goto v263;

v263:
    if (v186 == nil) goto v182;
    v31 = (Lisp_Object)1; /* 0 */
    v184 = stack[-2];
    v186 = (Lisp_Object)17; /* 1 */
    v186 = list2star(v31, v184, v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    v186 = ncons(v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    goto v54;

v54:
    v186 = Lassoc(nil, stack[0], v186);
    v184 = v186;
    v186 = v184;
    if (v186 == nil) goto v135;
    v186 = v184;
    v186 = qcdr(v186);
    { popv(5); return onevalue(v186); }

v135:
    v184 = qvalue(elt(env, 1)); /* nil */
    v186 = (Lisp_Object)17; /* 1 */
    popv(5);
    return cons(v184, v186);

v182:
    v184 = stack[-2];
    v186 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 7); /* ps!:getv */
    v186 = (*qfn2(fn))(qenv(fn), v184, v186);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-4];
    goto v54;

v207:
    v186 = qvalue(elt(env, 1)); /* nil */
    goto v263;

v28:
    v186 = qvalue(elt(env, 2)); /* t */
    goto v263;
/* error exit handlers */
v242:
    popv(5);
    return nil;
}



/* Code for groebsearchinlist */

static Lisp_Object CC_groebsearchinlist(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v268, v145;
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

v59:
    v268 = stack[0];
    if (v268 == nil) goto v205;
    v268 = stack[0];
    v268 = qcar(v268);
    v268 = qcdr(v268);
    v145 = qcar(v268);
    v268 = stack[-1];
    fn = elt(env, 2); /* buchvevdivides!? */
    v268 = (*qfn2(fn))(qenv(fn), v145, v268);
    nil = C_nil;
    if (exception_pending()) goto v249;
    env = stack[-2];
    if (v268 == nil) goto v266;
    v268 = stack[0];
    v268 = qcar(v268);
    { popv(3); return onevalue(v268); }

v266:
    v268 = stack[0];
    v268 = qcdr(v268);
    stack[0] = v268;
    goto v59;

v205:
    v268 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v268); }
/* error exit handlers */
v249:
    popv(3);
    return nil;
}



/* Code for deg!*form */

static Lisp_Object CC_degHform(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v233, v275, v257;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for deg*form");
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

v267:
    v233 = stack[0];
    if (!consp(v233)) goto v205;
    v233 = stack[0];
    v233 = qcar(v233);
    v257 = v233;
    v275 = v257;
    v233 = elt(env, 3); /* indexvar */
    v233 = Lflagp(nil, v275, v233);
    env = stack[-2];
    if (v233 == nil) goto v24;
    v233 = stack[0];
    v233 = qcdr(v233);
    v257 = Llength(nil, v233);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-2];
    v233 = stack[0];
    v275 = qcar(v233);
    v233 = elt(env, 4); /* ifdegree */
    v233 = get(v275, v233);
    env = stack[-2];
    v233 = Lassoc(nil, v257, v233);
    v275 = v233;
    v233 = v275;
    if (v233 == nil) goto v208;
    v233 = v275;
    v233 = qcdr(v233);
    { popv(3); return onevalue(v233); }

v208:
    v233 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v233); }

v24:
    v275 = v257;
    v233 = elt(env, 5); /* wedge */
    if (v275 == v233) goto v49;
    v275 = v257;
    v233 = elt(env, 6); /* d */
    if (v275 == v233) goto v277;
    v275 = v257;
    v233 = elt(env, 7); /* hodge */
    if (v275 == v233) goto v137;
    v275 = v257;
    v233 = elt(env, 9); /* partdf */
    if (v275 == v233) goto v278;
    v275 = v257;
    v233 = elt(env, 10); /* liedf */
    if (v275 == v233) goto v279;
    v275 = v257;
    v233 = elt(env, 11); /* innerprod */
    if (v275 == v233) goto v237;
    v275 = v257;
    v233 = elt(env, 12); /* (plus minus difference quotient) */
    v233 = Lmemq(nil, v275, v233);
    if (v233 == nil) goto v280;
    v233 = stack[0];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    stack[0] = v233;
    goto v267;

v280:
    v275 = v257;
    v233 = elt(env, 13); /* times */
    if (v275 == v233) goto v281;
    v233 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v233); }

v281:
    v233 = stack[0];
    v233 = qcdr(v233);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v233);
    }

v237:
    stack[-1] = (Lisp_Object)-15; /* -1 */
    v233 = stack[0];
    v233 = qcdr(v233);
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v233 = CC_degHform(env, v233);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-2];
    {
        Lisp_Object v282 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v282, v233);
    }

v279:
    v233 = stack[0];
    v233 = qcdr(v233);
    v233 = qcdr(v233);
    v233 = qcar(v233);
    stack[0] = v233;
    goto v267;

v278:
    v233 = stack[0];
    v233 = qcdr(v233);
    v233 = qcdr(v233);
    if (v233 == nil) goto v243;
    v233 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v233); }

v243:
    v233 = (Lisp_Object)-15; /* -1 */
    { popv(3); return onevalue(v233); }

v137:
    stack[-1] = qvalue(elt(env, 8)); /* dimex!* */
    v233 = stack[0];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v233 = CC_degHform(env, v233);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-2];
    fn = elt(env, 16); /* negf */
    v233 = (*qfn1(fn))(qenv(fn), v233);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-2];
    {
        Lisp_Object v283 = stack[-1];
        popv(3);
        fn = elt(env, 17); /* addf */
        return (*qfn2(fn))(qenv(fn), v283, v233);
    }

v277:
    stack[-1] = (Lisp_Object)17; /* 1 */
    v233 = stack[0];
    v233 = qcdr(v233);
    v233 = qcar(v233);
    v233 = CC_degHform(env, v233);
    nil = C_nil;
    if (exception_pending()) goto v276;
    env = stack[-2];
    {
        Lisp_Object v122 = stack[-1];
        popv(3);
        fn = elt(env, 15); /* addd */
        return (*qfn2(fn))(qenv(fn), v122, v233);
    }

v49:
    v233 = stack[0];
    v233 = qcdr(v233);
    {
        popv(3);
        fn = elt(env, 14); /* deg!*farg */
        return (*qfn1(fn))(qenv(fn), v233);
    }

v205:
    v275 = stack[0];
    v233 = elt(env, 1); /* fdegree */
    v233 = get(v275, v233);
    env = stack[-2];
    v275 = v233;
    v233 = v275;
    if (v233 == nil) goto v30;
    v233 = v275;
    v233 = qcar(v233);
    { popv(3); return onevalue(v233); }

v30:
    v233 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v233); }
/* error exit handlers */
v276:
    popv(3);
    return nil;
}



/* Code for set!-ordp */

static Lisp_Object CC_setKordp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v18, v6, v268;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for set-ordp");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v6 = v1;
    v268 = v0;
/* end of prologue */
    v18 = v268;
    if (!(is_number(v18))) goto v55;
    v18 = v6;
    if (!(is_number(v18))) goto v55;
    v18 = v268;
        return Llessp(nil, v18, v6);

v55:
    v18 = v268;
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v18, v6);
    }
}



/* Code for noncomp2f */

static Lisp_Object CC_noncomp2f(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v146, v147;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for noncomp2f");
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

v59:
    v146 = stack[0];
    if (!consp(v146)) goto v38;
    v146 = stack[0];
    v146 = qcar(v146);
    v146 = (consp(v146) ? nil : lisp_true);
    goto v50;

v50:
    if (v146 == nil) goto v47;
    v146 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v146); }

v47:
    v146 = stack[0];
    v146 = qcar(v146);
    v146 = qcar(v146);
    v146 = qcar(v146);
    v147 = v146;
    if (!consp(v146)) goto v55;
    v146 = v147;
    v146 = qcar(v146);
    if (!symbolp(v146)) v146 = nil;
    else { v146 = qfastgets(v146);
           if (v146 != nil) { v146 = elt(v146, 0); /* noncom */
#ifdef RECORD_GET
             if (v146 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v146 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v146 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v146 == SPID_NOPROP) v146 = nil; else v146 = lisp_true; }}
#endif
    if (v146 == nil) goto v209;
    v146 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v146); }

v209:
    v146 = stack[0];
    v146 = qcar(v146);
    v146 = qcdr(v146);
    v146 = CC_noncomp2f(env, v146);
    nil = C_nil;
    if (exception_pending()) goto v210;
    env = stack[-1];
    if (v146 == nil) goto v203;
    v146 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v146); }

v203:
    v146 = stack[0];
    v146 = qcdr(v146);
    stack[0] = v146;
    goto v59;

v55:
    v146 = v147;
    if (!symbolp(v146)) v146 = nil;
    else { v146 = qfastgets(v146);
           if (v146 != nil) { v146 = elt(v146, 0); /* noncom */
#ifdef RECORD_GET
             if (v146 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v146 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v146 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v146 == SPID_NOPROP) v146 = nil; else v146 = lisp_true; }}
#endif
    if (v146 == nil) goto v203;
    v146 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v146); }

v38:
    v146 = qvalue(elt(env, 1)); /* t */
    goto v50;
/* error exit handlers */
v210:
    popv(2);
    return nil;
}



/* Code for sroad */

static Lisp_Object MS_CDECL CC_sroad(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v198, v21, v22;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "sroad");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sroad");
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
    v22 = nil;
    goto v203;

v203:
    v198 = stack[0];
    if (v198 == nil) goto v51;
    v21 = stack[-2];
    v198 = stack[0];
    v198 = qcar(v198);
    if (equal(v21, v198)) goto v197;
    v198 = stack[0];
    v198 = qcar(v198);
    v21 = v22;
    v198 = cons(v198, v21);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    v22 = v198;
    v198 = stack[0];
    v198 = qcdr(v198);
    stack[0] = v198;
    goto v203;

v197:
    stack[-2] = v22;
    v21 = stack[-1];
    v198 = stack[0];
    v198 = qcdr(v198);
    v198 = Lappend(nil, v21, v198);
    nil = C_nil;
    if (exception_pending()) goto v181;
    env = stack[-3];
    {
        Lisp_Object v194 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v194, v198);
    }

v51:
    v198 = v22;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v198);
    }
/* error exit handlers */
v181:
    popv(4);
    return nil;
}



/* Code for assert_analyze */

static Lisp_Object MS_CDECL CC_assert_analyze(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v250, v107;
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
    v250 = (Lisp_Object)1; /* 0 */
    stack[0] = v250;
    v250 = (Lisp_Object)1; /* 0 */
    stack[-4] = v250;
    v250 = (Lisp_Object)1; /* 0 */
    stack[-2] = v250;
    v107 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v250 = elt(env, 2); /* lambda_lqlbvb_1 */
    fn = elt(env, 8); /* sort */
    v250 = (*qfn2(fn))(qenv(fn), v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    qvalue(elt(env, 1)) = v250; /* assertstatistics!* */
    v250 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-3] = v250;
    goto v55;

v55:
    v250 = stack[-3];
    if (v250 == nil) goto v29;
    v250 = stack[-3];
    v250 = qcar(v250);
    stack[-1] = v250;
    v107 = stack[0];
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = plus2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    v107 = stack[-4];
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = plus2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[-4] = v250;
    v107 = stack[-2];
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = plus2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[-2] = v250;
    v250 = stack[-3];
    v250 = qcdr(v250);
    stack[-3] = v250;
    goto v55;

v29:
    v250 = elt(env, 4); /* (function !#calls !#bad! calls !#assertion! violations) 
*/
    stack[-3] = v250;
    stack[-1] = elt(env, 5); /* sum */
    v107 = stack[-4];
    v250 = stack[-2];
    v250 = list2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = list2star(stack[-1], stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[-4] = qvalue(elt(env, 3)); /* nil */
    stack[-2] = qvalue(elt(env, 3)); /* nil */
    stack[-1] = qvalue(elt(env, 3)); /* nil */
    stack[0] = v250;
    v107 = qvalue(elt(env, 3)); /* nil */
    v250 = qvalue(elt(env, 1)); /* assertstatistics!* */
    v250 = cons(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = list2star(stack[-1], stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Lnreverse(nil, v250);
    env = stack[-5];
    v250 = cons(stack[-2], v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = list2star(stack[-4], stack[-3], v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    qvalue(elt(env, 1)) = v250; /* assertstatistics!* */
    v250 = qvalue(elt(env, 1)); /* assertstatistics!* */
    stack[-2] = v250;
    goto v291;

v291:
    v250 = stack[-2];
    if (v250 == nil) goto v278;
    v250 = stack[-2];
    v250 = qcar(v250);
    stack[-1] = v250;
    v250 = stack[-1];
    if (v250 == nil) goto v292;
    v250 = stack[-1];
    v250 = qcar(v250);
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[-1];
    v250 = qcar(v250);
    v250 = Lexplodec(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = Lexplodec(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = plus2(stack[0], v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v293;

v293:
    v107 = (Lisp_Object)369; /* 23 */
    v250 = stack[0];
    v250 = difference2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Lminusp(nil, v250);
    env = stack[-5];
    if (v250 == nil) goto v294;
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = Lexplodec(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v270;

v270:
    v107 = (Lisp_Object)369; /* 23 */
    v250 = stack[0];
    v250 = difference2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Lminusp(nil, v250);
    env = stack[-5];
    if (v250 == nil) goto v124;
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = Lexplodec(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Llength(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v117;

v117:
    v107 = (Lisp_Object)369; /* 23 */
    v250 = stack[0];
    v250 = difference2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Lminusp(nil, v250);
    env = stack[-5];
    if (v250 == nil) goto v295;
    v250 = stack[-1];
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcdr(v250);
    v250 = qcar(v250);
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    goto v33;

v33:
    v250 = stack[-2];
    v250 = qcdr(v250);
    stack[-2] = v250;
    goto v291;

v295:
    v250 = elt(env, 6); /* " " */
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[0];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v117;

v124:
    v250 = elt(env, 6); /* " " */
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[0];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v270;

v294:
    v250 = elt(env, 6); /* " " */
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[0];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v293;

v292:
    v250 = (Lisp_Object)17; /* 1 */
    stack[0] = v250;
    goto v296;

v296:
    v107 = (Lisp_Object)1153; /* 72 */
    v250 = stack[0];
    v250 = difference2(v107, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = Lminusp(nil, v250);
    env = stack[-5];
    if (v250 == nil) goto v297;
    v250 = Lterpri(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    goto v33;

v297:
    v250 = elt(env, 7); /* "-" */
    v250 = Lprinc(nil, v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    v250 = stack[0];
    v250 = add1(v250);
    nil = C_nil;
    if (exception_pending()) goto v290;
    env = stack[-5];
    stack[0] = v250;
    goto v296;

v278:
    v250 = qvalue(elt(env, 3)); /* nil */
    qvalue(elt(env, 1)) = v250; /* assertstatistics!* */
    v250 = nil;
    { popv(6); return onevalue(v250); }
/* error exit handlers */
v290:
    popv(6);
    return nil;
}



/* Code for lambda_lqlbvb_1 */

static Lisp_Object CC_lambda_lqlbvb_1(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for lambda_lqlbvb_1");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v57 = v1;
    v56 = v0;
/* end of prologue */
    v57 = qcar(v57);
    v56 = qcar(v56);
    {
        fn = elt(env, 1); /* ordp */
        return (*qfn2(fn))(qenv(fn), v57, v56);
    }
}



/* Code for red!-ratios2 */

static Lisp_Object MS_CDECL CC_redKratios2(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, Lisp_Object v3, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v182, v206, v10, v9;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "red-ratios2");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for red-ratios2");
#endif
    if (stack >= stacklimit)
    {
        push4(v3,v2,v1,v0);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0,v1,v2,v3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-1] = v3;
    stack[-2] = v2;
    stack[-3] = v1;
    stack[-4] = v0;
/* end of prologue */

v267:
    v182 = stack[-4];
    if (v182 == nil) goto v50;
    v206 = stack[-2];
    v182 = stack[-3];
    v182 = qcar(v182);
    stack[0] = times2(v206, v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    stack[-5] = stack[0];
    v206 = stack[-1];
    v182 = stack[-4];
    v182 = qcar(v182);
    v182 = times2(v206, v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    if (equal(stack[0], v182)) goto v54;
    v182 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v42:
    if (v182 == nil) goto v277;
    v206 = stack[-1];
    v182 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* red!-lowest!-terms */
        return (*qfn2(fn))(qenv(fn), v206, v182);
    }

v277:
    v182 = stack[-4];
    v9 = qcdr(v182);
    v182 = stack[-3];
    v10 = qcdr(v182);
    v206 = stack[-2];
    v182 = stack[-1];
    stack[-4] = v9;
    stack[-3] = v10;
    stack[-2] = v206;
    stack[-1] = v182;
    goto v267;

v54:
    v206 = stack[-5];
    v182 = (Lisp_Object)1; /* 0 */
    if (v206 == v182) goto v193;
    v206 = stack[-1];
    v182 = stack[-2];
    v206 = Lgcd(nil, v206, v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v182 = stack[-1];
    v206 = Cremainder(v206, v182);
    nil = C_nil;
    if (exception_pending()) goto v187;
    env = stack[-6];
    v182 = (Lisp_Object)1; /* 0 */
    v182 = (v206 == v182 ? lisp_true : nil);
    goto v42;

v193:
    v182 = qvalue(elt(env, 1)); /* nil */
    goto v42;

v50:
    v182 = qvalue(elt(env, 1)); /* nil */
    { popv(7); return onevalue(v182); }
/* error exit handlers */
v187:
    popv(7);
    return nil;
}



/* Code for tsym4 */

static Lisp_Object MS_CDECL CC_tsym4(Lisp_Object env, int nargs,
                         Lisp_Object v0, Lisp_Object v1,
                         Lisp_Object v2, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v45;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "tsym4");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for tsym4");
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
    v25 = v0;
/* end of prologue */

v203:
    v45 = v25;
    if (v45 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v45 = v25;
    v45 = qcdr(v45);
    stack[-2] = v45;
    v45 = stack[-1];
    v45 = qcdr(v45);
    v25 = qcar(v25);
    fn = elt(env, 1); /* pv_applp */
    v45 = (*qfn2(fn))(qenv(fn), v45, v25);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v25 = stack[0];
    fn = elt(env, 2); /* sieve_pv */
    v25 = (*qfn2(fn))(qenv(fn), v45, v25);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    fn = elt(env, 3); /* pv_renorm */
    v45 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    v25 = stack[0];
    fn = elt(env, 4); /* insert_pv */
    v25 = (*qfn2(fn))(qenv(fn), v45, v25);
    nil = C_nil;
    if (exception_pending()) goto v196;
    env = stack[-3];
    stack[0] = v25;
    v25 = stack[-2];
    goto v203;
/* error exit handlers */
v196:
    popv(4);
    return nil;
}



/* Code for !*i2ar */

static Lisp_Object CC_Hi2ar(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v51, v50;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for *i2ar");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v51 = v0;
/* end of prologue */
    v50 = elt(env, 1); /* !:ar!: */
    return cons(v50, v51);
}



/* Code for polynommultiplybymonom */

static Lisp_Object CC_polynommultiplybymonom(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v54, v196;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for polynommultiplybymonom");
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
    v196 = v0;
/* end of prologue */
    v54 = v196;
    if (v54 == nil) goto v59;
    v54 = v196;
    fn = elt(env, 2); /* polynomclone */
    v54 = (*qfn1(fn))(qenv(fn), v54);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    stack[-1] = v54;
    v196 = stack[0];
    v54 = (Lisp_Object)17; /* 1 */
    v54 = *(Lisp_Object *)((char *)v196 + (CELL-TAG_VECTOR) + ((int32_t)v54/(16/CELL)));
    stack[0] = v54;
    goto v266;

v266:
    v54 = stack[0];
    v54 = qcar(v54);
    if (v54 == nil) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    v196 = stack[-1];
    v54 = stack[0];
    v54 = qcar(v54);
    fn = elt(env, 3); /* polynommultiplybyvariable */
    v54 = (*qfn2(fn))(qenv(fn), v196, v54);
    nil = C_nil;
    if (exception_pending()) goto v154;
    env = stack[-2];
    v54 = stack[0];
    v54 = qcdr(v54);
    stack[0] = v54;
    goto v266;

v59:
    v54 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v54); }
/* error exit handlers */
v154:
    popv(3);
    return nil;
}



/* Code for sfto_gcdf!* */

static Lisp_Object CC_sfto_gcdfH(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v56, v57, v39;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for sfto_gcdf*");
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
    v57 = v1;
    v39 = v0;
/* end of prologue */
    v56 = qvalue(elt(env, 1)); /* t */
    stack[0] = qvalue(elt(env, 2)); /* !*gcd */
    qvalue(elt(env, 2)) = v56; /* !*gcd */
    v56 = v39;
    fn = elt(env, 3); /* sfto_gcdf */
    v56 = (*qfn2(fn))(qenv(fn), v56, v57);
    nil = C_nil;
    if (exception_pending()) goto v41;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    { popv(2); return onevalue(v56); }
/* error exit handlers */
v41:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* !*gcd */
    popv(2);
    return nil;
}



/* Code for wulessp */

static Lisp_Object CC_wulessp(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v188;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for wulessp");
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
    v188 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (v188 == nil) goto v43;
    v188 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v188;
    goto v47;

v47:
    v188 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (v188 == nil) goto v145;
    v188 = qvalue(elt(env, 1)); /* nil */
    goto v51;

v51:
    fn = elt(env, 3); /* symbollessp */
    v188 = (*qfn2(fn))(qenv(fn), stack[-2], v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (!(v188 == nil)) { popv(4); return onevalue(v188); }
    v188 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (v188 == nil) goto v198;
    v188 = qvalue(elt(env, 1)); /* nil */
    stack[-2] = v188;
    goto v25;

v25:
    v188 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (v188 == nil) goto v19;
    v188 = qvalue(elt(env, 1)); /* nil */
    goto v45;

v45:
    if (equal(stack[-2], v188)) goto v24;
    v188 = qvalue(elt(env, 1)); /* nil */
    { popv(4); return onevalue(v188); }

v24:
    v188 = stack[-1];
    fn = elt(env, 2); /* wuconstantp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    env = stack[-3];
    if (v188 == nil) goto v143;
    v188 = (Lisp_Object)1; /* 0 */
    stack[-1] = v188;
    goto v53;

v53:
    v188 = stack[0];
    fn = elt(env, 2); /* wuconstantp */
    v188 = (*qfn1(fn))(qenv(fn), v188);
    nil = C_nil;
    if (exception_pending()) goto v9;
    if (v188 == nil) goto v245;
    v188 = (Lisp_Object)1; /* 0 */
    goto v193;

v193:
    {
        Lisp_Object v244 = stack[-1];
        popv(4);
        return Llessp(nil, v244, v188);
    }

v245:
    v188 = stack[0];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcdr(v188);
    goto v193;

v143:
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcdr(v188);
    stack[-1] = v188;
    goto v53;

v19:
    v188 = stack[0];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    goto v45;

v198:
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    stack[-2] = v188;
    goto v25;

v145:
    v188 = stack[0];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    goto v51;

v43:
    v188 = stack[-1];
    v188 = qcar(v188);
    v188 = qcar(v188);
    v188 = qcar(v188);
    stack[-2] = v188;
    goto v47;
/* error exit handlers */
v9:
    popv(4);
    return nil;
}



/* Code for ibalp_litlp */

static Lisp_Object CC_ibalp_litlp(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v30;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ibalp_litlp");
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

v267:
    v30 = stack[0];
    if (v30 == nil) goto v220;
    v30 = stack[0];
    v30 = qcar(v30);
    fn = elt(env, 3); /* ibalp_litp */
    v30 = (*qfn1(fn))(qenv(fn), v30);
    nil = C_nil;
    if (exception_pending()) goto v221;
    env = stack[-1];
    if (v30 == nil) goto v38;
    v30 = stack[0];
    v30 = qcdr(v30);
    stack[0] = v30;
    goto v267;

v38:
    v30 = qvalue(elt(env, 2)); /* nil */
    { popv(2); return onevalue(v30); }

v220:
    v30 = qvalue(elt(env, 1)); /* t */
    { popv(2); return onevalue(v30); }
/* error exit handlers */
v221:
    popv(2);
    return nil;
}



/* Code for carx */

static Lisp_Object CC_carx(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v35, v37, v249;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for carx");
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
    v37 = v1;
    v249 = v0;
/* end of prologue */
    v35 = v249;
    v35 = qcdr(v35);
    if (v35 == nil) goto v59;
    v35 = elt(env, 1); /* "Wrong number of arguments to" */
    v35 = list2(v35, v37);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[0];
    v37 = v35;
    v35 = v37;
    qvalue(elt(env, 2)) = v35; /* errmsg!* */
    v35 = qvalue(elt(env, 3)); /* !*protfg */
    if (!(v35 == nil)) goto v197;
    v35 = v37;
    fn = elt(env, 4); /* lprie */
    v35 = (*qfn1(fn))(qenv(fn), v35);
    nil = C_nil;
    if (exception_pending()) goto v209;
    env = stack[0];
    goto v197;

v197:
    v35 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v209;
    v35 = nil;
    { popv(1); return onevalue(v35); }

v59:
    v35 = v249;
    v35 = qcar(v35);
    { popv(1); return onevalue(v35); }
/* error exit handlers */
v209:
    popv(1);
    return nil;
}



/* Code for ps!:expression */

static Lisp_Object CC_psTexpression(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v196, v146, v147;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ps:expression");
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
    v146 = v0;
/* end of prologue */
    v196 = v146;
    if (!consp(v196)) goto v205;
    v196 = v146;
    v147 = qcar(v196);
    v196 = elt(env, 2); /* !:ps!: */
    if (v147 == v196) goto v249;
    v196 = v146;
    v147 = qcar(v196);
    v196 = elt(env, 3); /* dname */
    v196 = get(v147, v196);
    env = stack[0];
    goto v203;

v203:
    if (!(v196 == nil)) { popv(1); return onevalue(v146); }
    v196 = (Lisp_Object)97; /* 6 */
    {
        popv(1);
        fn = elt(env, 5); /* ps!:getv */
        return (*qfn2(fn))(qenv(fn), v146, v196);
    }

v249:
    v196 = qvalue(elt(env, 4)); /* nil */
    goto v203;

v205:
    v196 = qvalue(elt(env, 1)); /* t */
    goto v203;
}



/* Code for c!:extmult */

static Lisp_Object CC_cTextmult(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v133, v273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for c:extmult");
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
    v133 = stack[-2];
    if (v133 == nil) goto v47;
    v133 = stack[-1];
    v133 = (v133 == nil ? lisp_true : nil);
    goto v205;

v205:
    if (v133 == nil) goto v200;
    v133 = qvalue(elt(env, 2)); /* nil */
    { popv(5); return onevalue(v133); }

v200:
    v273 = stack[-1];
    v133 = (Lisp_Object)17; /* 1 */
    if (v273 == v133) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    v133 = stack[-2];
    v133 = qcar(v133);
    v133 = qcar(v133);
    v273 = qcar(v133);
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcar(v133);
    fn = elt(env, 3); /* c!:ordexn */
    v133 = (*qfn2(fn))(qenv(fn), v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v273 = v133;
    v133 = v273;
    if (v133 == nil) goto v218;
    v133 = v273;
    stack[0] = qcdr(v133);
    v133 = v273;
    v133 = qcar(v133);
    if (v133 == nil) goto v143;
    v133 = stack[-2];
    v133 = qcar(v133);
    v273 = qcdr(v133);
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    fn = elt(env, 4); /* c!:subs2multf */
    v133 = (*qfn2(fn))(qenv(fn), v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    fn = elt(env, 5); /* negf */
    v133 = (*qfn1(fn))(qenv(fn), v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    goto v181;

v181:
    v133 = cons(stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    stack[-3] = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v133 = stack[-2];
    v133 = qcar(v133);
    v273 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[0] = CC_cTextmult(env, v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v133 = stack[-2];
    v273 = qcdr(v133);
    v133 = stack[-1];
    v133 = CC_cTextmult(env, v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    fn = elt(env, 6); /* c!:extadd */
    v133 = (*qfn2(fn))(qenv(fn), stack[0], v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    {
        Lisp_Object v300 = stack[-3];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v300, v133);
    }

v143:
    v133 = stack[-2];
    v133 = qcar(v133);
    v273 = qcdr(v133);
    v133 = stack[-1];
    v133 = qcar(v133);
    v133 = qcdr(v133);
    fn = elt(env, 4); /* c!:subs2multf */
    v133 = (*qfn2(fn))(qenv(fn), v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    goto v181;

v218:
    v133 = stack[-2];
    v133 = qcar(v133);
    v273 = ncons(v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v133 = stack[-1];
    v133 = qcdr(v133);
    stack[0] = CC_cTextmult(env, v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    v133 = stack[-2];
    v273 = qcdr(v133);
    v133 = stack[-1];
    v133 = CC_cTextmult(env, v273, v133);
    nil = C_nil;
    if (exception_pending()) goto v239;
    env = stack[-4];
    {
        Lisp_Object v287 = stack[0];
        popv(5);
        fn = elt(env, 6); /* c!:extadd */
        return (*qfn2(fn))(qenv(fn), v287, v133);
    }

v47:
    v133 = qvalue(elt(env, 1)); /* t */
    goto v205;
/* error exit handlers */
v239:
    popv(5);
    return nil;
}



/* Code for testred */

static Lisp_Object CC_testred(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v31, v32, v33;
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
    v32 = qvalue(elt(env, 2)); /* maxvar */
    v31 = stack[0];
    v31 = plus2(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v32 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    v31 = (Lisp_Object)1; /* 0 */
    v31 = *(Lisp_Object *)((char *)v32 + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    if (v31 == nil) goto v59;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v32 = qvalue(elt(env, 2)); /* maxvar */
    v31 = stack[0];
    v31 = plus2(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v32 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    v31 = (Lisp_Object)17; /* 1 */
    v31 = *(Lisp_Object *)((char *)v32 + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    v31 = qcar(v31);
    v32 = qcar(v31);
    v31 = (Lisp_Object)33; /* 2 */
    v31 = (Lisp_Object)lessp2(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    v31 = v31 ? lisp_true : nil;
    env = stack[-2];
    if (v31 == nil) goto v59;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v32 = qvalue(elt(env, 2)); /* maxvar */
    v31 = stack[0];
    v31 = plus2(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v33 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    v32 = (Lisp_Object)1; /* 0 */
    v31 = qvalue(elt(env, 3)); /* nil */
    *(Lisp_Object *)((char *)v33 + (CELL-TAG_VECTOR) + ((int32_t)v32/(16/CELL))) = v31;
    stack[-1] = qvalue(elt(env, 1)); /* codmat */
    v32 = qvalue(elt(env, 2)); /* maxvar */
    v31 = stack[0];
    v31 = plus2(v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v32 = *(Lisp_Object *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    v31 = (Lisp_Object)65; /* 4 */
    v31 = *(Lisp_Object *)((char *)v32 + (CELL-TAG_VECTOR) + ((int32_t)v31/(16/CELL)));
    stack[-1] = v31;
    goto v219;

v219:
    v31 = stack[-1];
    if (v31 == nil) goto v244;
    v31 = stack[-1];
    v31 = qcar(v31);
    stack[0] = v31;
    v31 = stack[0];
    v32 = qcar(v31);
    v31 = stack[0];
    v31 = qcdr(v31);
    v31 = qcar(v31);
    fn = elt(env, 4); /* downwght1 */
    v31 = (*qfn2(fn))(qenv(fn), v32, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v31 = stack[0];
    v31 = qcar(v31);
    v31 = CC_testred(env, v31);
    nil = C_nil;
    if (exception_pending()) goto v242;
    env = stack[-2];
    v31 = stack[-1];
    v31 = qcdr(v31);
    stack[-1] = v31;
    goto v219;

v244:
    v31 = qvalue(elt(env, 3)); /* nil */
    { popv(3); return onevalue(v31); }

v59:
    v31 = nil;
    { popv(3); return onevalue(v31); }
/* error exit handlers */
v242:
    popv(3);
    return nil;
}



/* Code for bcone!? */

static Lisp_Object CC_bconeW(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v213, v148, v46;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for bcone?");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v46 = v0;
/* end of prologue */
    v213 = qvalue(elt(env, 1)); /* !*grmod!* */
    if (v213 == nil) goto v29;
    v148 = v46;
    v213 = (Lisp_Object)17; /* 1 */
        return Leqn(nil, v148, v213);

v29:
    v213 = v46;
    v148 = qcdr(v213);
    v213 = (Lisp_Object)17; /* 1 */
    if (v148 == v213) goto v18;
    v213 = qvalue(elt(env, 2)); /* nil */
    return onevalue(v213);

v18:
    v213 = v46;
    v148 = qcar(v213);
    v213 = (Lisp_Object)17; /* 1 */
    v213 = (v148 == v213 ? lisp_true : nil);
    return onevalue(v213);
}



/* Code for ncmpchk */

static Lisp_Object CC_ncmpchk(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v197, v266;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for ncmpchk");
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
    v266 = stack[-1];
    v197 = stack[0];
    fn = elt(env, 2); /* noncommuting */
    v197 = (*qfn2(fn))(qenv(fn), v266, v197);
    nil = C_nil;
    if (exception_pending()) goto v6;
    env = stack[-2];
    if (v197 == nil) goto v59;
    v266 = stack[-1];
    v197 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* ordop */
        return (*qfn2(fn))(qenv(fn), v266, v197);
    }

v59:
    v197 = qvalue(elt(env, 1)); /* t */
    { popv(3); return onevalue(v197); }
/* error exit handlers */
v6:
    popv(3);
    return nil;
}



/* Code for scan */

static Lisp_Object MS_CDECL CC_scan(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v383, v384, v385;
    Lisp_Object fn;
    CSL_IGNORE(nil);
    argcheck(nargs, 0, "scan");
#ifdef DEBUG
    if (check_env(env)) return aerror("env for scan");
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
    v384 = qvalue(elt(env, 1)); /* cursym!* */
    v383 = elt(env, 2); /* !*semicol!* */
    if (!(v384 == v383)) goto v203;

v52:
    fn = elt(env, 38); /* token1 */
    v383 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    goto v203;

v203:
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v383)) goto v48;
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    v385 = v383;
    v383 = v385;
    v383 = (is_number(v383) ? lisp_true : nil);
    if (!(v383 == nil)) goto v46;
    v384 = v385;
    v383 = elt(env, 4); /* !:dn!: */
    if (!consp(v384)) goto v263;
    v384 = qcar(v384);
    if (!(v384 == v383)) goto v263;
    v383 = qvalue(elt(env, 5)); /* t */
    goto v46;

v46:
    v383 = (v383 == nil ? lisp_true : nil);
    goto v209;

v209:
    if (v383 == nil) goto v191;
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    v384 = qcar(v383);
    v383 = elt(env, 36); /* string */
    if (!(v384 == v383)) goto v41;
    v384 = elt(env, 37); /* " " */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qcdr(v383);
    v383 = qcar(v383);
    v383 = Lmkquote(nil, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    v383 = qcdr(v383);
    v384 = qcar(v383);
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    goto v41;

v41:
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 1)) = v383; /* cursym!* */
    fn = elt(env, 38); /* token1 */
    v383 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 24)); /* !$eof!$ */
    if (v384 == v383) goto v387;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v388;

v388:
    if (v383 == nil) goto v42;
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v42:
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (is_number(v383)) goto v389;
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!consp(v383)) goto v390;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v391;

v391:
    if (!(v383 == nil)) goto v389;

v392:
    v383 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 1)) = v383; /* cursym!* */
    { popv(4); return onevalue(v383); }

v389:
    v384 = elt(env, 37); /* " " */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    goto v392;

v390:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 30); /* switch!* */
    v383 = get(v384, v383);
    env = stack[-3];
    v383 = (v383 == nil ? lisp_true : nil);
    goto v391;

v387:
    v384 = qvalue(elt(env, 14)); /* ttype!* */
    v383 = (Lisp_Object)49; /* 3 */
    v383 = (v384 == v383 ? lisp_true : nil);
    goto v388;

v191:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 8); /* else */
    if (v384 == v383) goto v288;
    v384 = qvalue(elt(env, 1)); /* cursym!* */
    v383 = elt(env, 2); /* !*semicol!* */
    v383 = (v384 == v383 ? lisp_true : nil);
    goto v193;

v193:
    if (v383 == nil) goto v13;
    v383 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 9)) = v383; /* outl!* */
    goto v13;

v13:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    goto v205;

v205:
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (!(symbolp(v383))) goto v41;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 10); /* newnam */
    v383 = get(v384, v383);
    env = stack[-3];
    stack[-1] = v383;
    if (v383 == nil) goto v185;
    v384 = stack[-1];
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    if (equal(v384, v383)) goto v185;
    v383 = stack[-1];
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    v383 = stack[-1];
    v383 = Lstringp(nil, v383);
    env = stack[-3];
    if (!(v383 == nil)) goto v41;
    v383 = stack[-1];
    if (!consp(v383)) goto v205;
    else goto v41;

v185:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 11); /* comment */
    if (v384 == v383) goto v8;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 13); /* !% */
    if (v384 == v383) goto v393;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v274;

v274:
    if (v383 == nil) goto v121;
    v383 = elt(env, 15); /* percent_comment */
    fn = elt(env, 40); /* read!-comment1 */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    stack[-1] = v383;
    v383 = qvalue(elt(env, 12)); /* !*comment */
    if (v383 == nil) goto v52;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v121:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 16); /* !#if */
    if (v384 == v383) goto v394;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 17); /* !#else */
    if (v384 == v383) goto v124;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 18); /* !#elif */
    v383 = (v384 == v383 ? lisp_true : nil);
    goto v280;

v280:
    if (v383 == nil) goto v228;
    v383 = qvalue(elt(env, 7)); /* nil */
    stack[-1] = v383;
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    goto v395;

v395:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 19); /* !#endif */
    if (v384 == v383) goto v396;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 16); /* !#if */
    if (v384 == v383) goto v397;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 17); /* !#else */
    if (v384 == v383) goto v398;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v399;

v399:
    if (!(v383 == nil)) goto v52;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 18); /* !#elif */
    if (v384 == v383) goto v400;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v401;

v401:
    if (!(v383 == nil)) goto v394;

v402:
    fn = elt(env, 38); /* token1 */
    v383 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    v384 = qvalue(elt(env, 14)); /* ttype!* */
    v383 = (Lisp_Object)49; /* 3 */
    if (v384 == v383) goto v403;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v404;

v404:
    if (v383 == nil) goto v395;
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v403:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 24)); /* !$eof!$ */
    v383 = (v384 == v383 ? lisp_true : nil);
    goto v404;

v394:
    v384 = elt(env, 21); /* " '" */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v385 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    v384 = qvalue(elt(env, 22)); /* !*backtrace */
    v383 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v383 = (*qfnn(fn))(qenv(fn), 3, v385, v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    stack[-1] = v383;
    v383 = stack[-1];
    if (!consp(v383)) goto v153;
    v383 = stack[-1];
    v383 = qcdr(v383);
    goto v152;

v152:
    if (v383 == nil) goto v149;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v62;

v62:
    if (!(v383 == nil)) goto v52;
    v383 = qvalue(elt(env, 7)); /* nil */
    stack[-1] = v383;
    goto v395;

v149:
    v383 = stack[-1];
    v383 = qcar(v383);
    goto v62;

v153:
    v383 = qvalue(elt(env, 5)); /* t */
    goto v152;

v400:
    v383 = stack[-1];
    v383 = (v383 == nil ? lisp_true : nil);
    goto v401;

v398:
    v383 = stack[-1];
    v383 = (v383 == nil ? lisp_true : nil);
    goto v399;

v397:
    v384 = qvalue(elt(env, 7)); /* nil */
    v383 = stack[-1];
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    stack[-1] = v383;
    goto v402;

v396:
    v383 = stack[-1];
    if (v383 == nil) goto v52;
    v383 = stack[-1];
    v383 = qcdr(v383);
    stack[-1] = v383;
    goto v402;

v228:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 19); /* !#endif */
    if (v384 == v383) goto v52;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 20); /* !#eval */
    if (v384 == v383) goto v405;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 23); /* !#define */
    if (v384 == v383) goto v406;
    v384 = qvalue(elt(env, 14)); /* ttype!* */
    v383 = (Lisp_Object)49; /* 3 */
    if (!(v384 == v383)) goto v41;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 24)); /* !$eof!$ */
    if (v384 == v383) goto v407;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 25); /* !' */
    if (v384 == v383) goto v158;
    v383 = qvalue(elt(env, 28)); /* !*eoldelimp */
    if (v383 == nil) goto v162;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 29)); /* !$eol!$ */
    if (!(v384 == v383)) goto v162;

v57:
    v383 = qvalue(elt(env, 3)); /* nxtsym!* */
    qvalue(elt(env, 35)) = v383; /* semic!* */
    v383 = elt(env, 2); /* !*semicol!* */
    qvalue(elt(env, 1)) = v383; /* cursym!* */
    { popv(4); return onevalue(v383); }

v162:
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = elt(env, 30); /* switch!* */
    v383 = get(v384, v383);
    env = stack[-3];
    stack[-1] = v383;
    if (v383 == nil) goto v41;
    v383 = stack[-1];
    v384 = qcdr(v383);
    v383 = elt(env, 2); /* !*semicol!* */
    if (!consp(v384)) goto v188;
    v384 = qcar(v384);
    if (v384 == v383) goto v57;
    else goto v188;

v188:
    v383 = qvalue(elt(env, 31)); /* crchar!* */
    v383 = Lwhitespace_char_p(nil, v383);
    env = stack[-3];
    stack[-2] = v383;
    goto v47;

v47:
    fn = elt(env, 38); /* token1 */
    v383 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 3)) = v383; /* nxtsym!* */
    v384 = qvalue(elt(env, 14)); /* ttype!* */
    v383 = (Lisp_Object)49; /* 3 */
    if (!(v384 == v383)) goto v51;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 24)); /* !$eof!$ */
    if (v384 == v383) goto v168;
    v383 = stack[-1];
    v383 = qcar(v383);
    if (v383 == nil) goto v51;
    v383 = stack[-2];
    if (!(v383 == nil)) goto v51;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = stack[-1];
    v383 = qcar(v383);
    v383 = Latsoc(nil, v384, v383);
    stack[0] = v383;
    if (v383 == nil) goto v51;
    v384 = qvalue(elt(env, 3)); /* nxtsym!* */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    v383 = stack[0];
    v383 = qcdr(v383);
    stack[-1] = v383;
    v383 = stack[-1];
    v383 = qcar(v383);
    if (v383 == nil) goto v408;
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v409;

v409:
    if (v383 == nil) goto v47;
    fn = elt(env, 43); /* read!-comment */
    v383 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 34)) = v383; /* comment!* */
    goto v52;

v408:
    v383 = stack[-1];
    v383 = qcdr(v383);
    v384 = qcar(v383);
    v383 = elt(env, 33); /* !*comment!* */
    v383 = (v384 == v383 ? lisp_true : nil);
    goto v409;

v51:
    v383 = stack[-1];
    v383 = qcdr(v383);
    v383 = qcar(v383);
    qvalue(elt(env, 1)) = v383; /* cursym!* */
    v384 = qvalue(elt(env, 1)); /* cursym!* */
    v383 = elt(env, 32); /* !*rpar!* */
    if (v384 == v383) goto v42;
    v383 = qvalue(elt(env, 1)); /* cursym!* */
    qvalue(elt(env, 1)) = v383; /* cursym!* */
    { popv(4); return onevalue(v383); }

v168:
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v158:
    v383 = qvalue(elt(env, 26)); /* !*protfg */
    if (!(v383 == nil)) goto v159;
    v383 = elt(env, 27); /* "Invalid QUOTE" */
    fn = elt(env, 44); /* lprie */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    goto v159;

v159:
    v383 = Lerror0(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    goto v188;

v407:
    {
        popv(4);
        fn = elt(env, 39); /* filenderr */
        return (*qfnn(fn))(qenv(fn), 0);
    }

v406:
    v384 = elt(env, 21); /* " '" */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v385 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    v384 = qvalue(elt(env, 22)); /* !*backtrace */
    v383 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v383 = (*qfnn(fn))(qenv(fn), 3, v385, v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    stack[-1] = v383;
    v383 = stack[-1];
    if (!consp(v383)) goto v108;
    v383 = stack[-1];
    v383 = qcdr(v383);
    goto v107;

v107:
    if (!(v383 == nil)) goto v52;
    v384 = elt(env, 21); /* " '" */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v385 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    v384 = qvalue(elt(env, 22)); /* !*backtrace */
    v383 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v383 = (*qfnn(fn))(qenv(fn), 3, v385, v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    stack[0] = v383;
    v383 = stack[0];
    if (!consp(v383)) goto v410;
    v383 = stack[0];
    v383 = qcdr(v383);
    goto v411;

v411:
    if (!(v383 == nil)) goto v52;
    v385 = stack[-1];
    v384 = elt(env, 10); /* newnam */
    v383 = stack[0];
    v383 = Lputprop(nil, 3, v385, v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    goto v52;

v410:
    v383 = qvalue(elt(env, 5)); /* t */
    goto v411;

v108:
    v383 = qvalue(elt(env, 5)); /* t */
    goto v107;

v405:
    v384 = elt(env, 21); /* " '" */
    v383 = qvalue(elt(env, 9)); /* outl!* */
    v383 = cons(v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    qvalue(elt(env, 9)) = v383; /* outl!* */
    fn = elt(env, 41); /* rread1 */
    v385 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    v384 = qvalue(elt(env, 22)); /* !*backtrace */
    v383 = qvalue(elt(env, 7)); /* nil */
    fn = elt(env, 42); /* errorset */
    v383 = (*qfnn(fn))(qenv(fn), 3, v385, v384, v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    goto v52;

v124:
    v383 = qvalue(elt(env, 5)); /* t */
    goto v280;

v393:
    v384 = qvalue(elt(env, 14)); /* ttype!* */
    v383 = (Lisp_Object)49; /* 3 */
    v383 = (v384 == v383 ? lisp_true : nil);
    goto v274;

v8:
    v383 = elt(env, 11); /* comment */
    fn = elt(env, 40); /* read!-comment1 */
    v383 = (*qfn1(fn))(qenv(fn), v383);
    nil = C_nil;
    if (exception_pending()) goto v386;
    env = stack[-3];
    stack[-1] = v383;
    v383 = qvalue(elt(env, 12)); /* !*comment */
    if (v383 == nil) goto v52;
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v288:
    v383 = qvalue(elt(env, 5)); /* t */
    goto v193;

v263:
    v384 = v385;
    v383 = elt(env, 6); /* !:int!: */
    v383 = Leqcar(nil, v384, v383);
    env = stack[-3];
    goto v46;

v48:
    v383 = qvalue(elt(env, 7)); /* nil */
    goto v209;
/* error exit handlers */
v386:
    popv(4);
    return nil;
}



/* Code for rnplus!: */

static Lisp_Object CC_rnplusT(Lisp_Object env,
                         Lisp_Object v0, Lisp_Object v1)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v147, v154;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for rnplus:");
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
    v147 = stack[-1];
    v147 = qcdr(v147);
    v154 = qcar(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    stack[-2] = times2(v154, v147);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v147 = stack[-1];
    v147 = qcdr(v147);
    v154 = qcdr(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcar(v147);
    v147 = times2(v154, v147);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    stack[-2] = plus2(stack[-2], v147);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    v147 = stack[-1];
    v147 = qcdr(v147);
    v154 = qcdr(v147);
    v147 = stack[0];
    v147 = qcdr(v147);
    v147 = qcdr(v147);
    v147 = times2(v154, v147);
    nil = C_nil;
    if (exception_pending()) goto v22;
    env = stack[-3];
    {
        Lisp_Object v247 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* mkrn */
        return (*qfn2(fn))(qenv(fn), v247, v147);
    }
/* error exit handlers */
v22:
    popv(4);
    return nil;
}



/* Code for dp!=ecart */

static Lisp_Object CC_dpMecart(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v25, v45;
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
    goto v52;

v52:
    v25 = stack[0];
    if (v25 == nil) goto v203;
    v25 = stack[0];
    fn = elt(env, 1); /* dp_lmon */
    v25 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    fn = elt(env, 2); /* mo_ecart */
    v45 = (*qfn1(fn))(qenv(fn), v25);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v25 = stack[-1];
    v25 = cons(v45, v25);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    stack[-1] = v25;
    v25 = stack[0];
    v25 = qcdr(v25);
    stack[0] = v25;
    goto v52;

v203:
    v25 = (Lisp_Object)1; /* 0 */
    v45 = v25;
    goto v205;

v205:
    v25 = stack[-1];
    if (v25 == nil) { popv(3); return onevalue(v45); }
    v25 = stack[-1];
    v25 = qcar(v25);
    v25 = Lmax2(nil, v25, v45);
    nil = C_nil;
    if (exception_pending()) goto v54;
    env = stack[-2];
    v45 = v25;
    v25 = stack[-1];
    v25 = qcdr(v25);
    stack[-1] = v25;
    goto v205;
/* error exit handlers */
v54:
    popv(3);
    return nil;
}



/* Code for gperm */

static Lisp_Object CC_gperm(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v24, v20;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for gperm");
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
    stack[-1] = nil;
    goto v56;

v56:
    v20 = stack[0];
    v24 = (Lisp_Object)1; /* 0 */
    v24 = (Lisp_Object)greaterp2(v20, v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    v24 = v24 ? lisp_true : nil;
    env = stack[-4];
    if (v24 == nil) goto v52;
    v20 = stack[0];
    v24 = stack[-1];
    v24 = cons(v20, v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    stack[-1] = v24;
    v24 = stack[0];
    v24 = sub1(v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    stack[0] = v24;
    goto v56;

v52:
    v24 = stack[-1];
    fn = elt(env, 2); /* gperm0 */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    stack[-3] = v24;
    v24 = stack[-3];
    if (v24 == nil) goto v213;
    v24 = stack[-3];
    v24 = qcar(v24);
    fn = elt(env, 3); /* pkp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    stack[-1] = v24;
    stack[-2] = v24;
    goto v209;

v209:
    v24 = stack[-3];
    v24 = qcdr(v24);
    stack[-3] = v24;
    v24 = stack[-3];
    if (v24 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v24 = stack[-3];
    v24 = qcar(v24);
    fn = elt(env, 3); /* pkp */
    v24 = (*qfn1(fn))(qenv(fn), v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v24 = ncons(v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v24 = Lrplacd(nil, stack[0], v24);
    nil = C_nil;
    if (exception_pending()) goto v191;
    env = stack[-4];
    v24 = stack[-1];
    v24 = qcdr(v24);
    stack[-1] = v24;
    goto v209;

v213:
    v24 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v24); }
/* error exit handlers */
v191:
    popv(5);
    return nil;
}



/* Code for cdarx */

static Lisp_Object CC_cdarx(Lisp_Object env,
                         Lisp_Object v0)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v50, v38;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG
    if (check_env(env)) return aerror("env for cdarx");
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
    v50 = v0;
/* end of prologue */
    v38 = v50;
    v50 = elt(env, 1); /* cdar */
    fn = elt(env, 2); /* carx */
    v50 = (*qfn2(fn))(qenv(fn), v38, v50);
    errexit();
    v50 = qcdr(v50);
    return onevalue(v50);
}



setup_type const u07_setup[] =
{
    {"mcharg2",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_mcharg2},
    {"mri_pasf2mriat",          too_few_2,      CC_mri_pasf2mriat,wrong_no_2},
    {"ibalp_varlt1",            too_few_2,      CC_ibalp_varlt1,wrong_no_2},
    {"checktag",                CC_checktag,    too_many_1,    wrong_no_1},
    {"reval1",                  too_few_2,      CC_reval1,     wrong_no_2},
    {"exchk2",                  too_few_2,      CC_exchk2,     wrong_no_2},
    {"vevtdeg",                 CC_vevtdeg,     too_many_1,    wrong_no_1},
    {"getphystype",             CC_getphystype, too_many_1,    wrong_no_1},
    {"form",                    CC_form,        too_many_1,    wrong_no_1},
    {"dp_ecart",                CC_dp_ecart,    too_many_1,    wrong_no_1},
    {"maprint",                 too_few_2,      CC_maprint,    wrong_no_2},
    {"gperm1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_gperm1},
    {"sfto_dcontentf1",         too_few_2,      CC_sfto_dcontentf1,wrong_no_2},
    {"ckrn1",                   CC_ckrn1,       too_many_1,    wrong_no_1},
    {"ofsf_smwcpknowl",         CC_ofsf_smwcpknowl,too_many_1, wrong_no_1},
    {"symbol",                  CC_symbol,      too_many_1,    wrong_no_1},
    {"kernord",                 too_few_2,      CC_kernord,    wrong_no_2},
    {"ibalp_istotal",           CC_ibalp_istotal,too_many_1,   wrong_no_1},
    {"multiom",                 CC_multiom,     too_many_1,    wrong_no_1},
    {"ps:get-term",             too_few_2,      CC_psTgetKterm,wrong_no_2},
    {"groebsearchinlist",       too_few_2,      CC_groebsearchinlist,wrong_no_2},
    {"deg*form",                CC_degHform,    too_many_1,    wrong_no_1},
    {"set-ordp",                too_few_2,      CC_setKordp,   wrong_no_2},
    {"noncomp2f",               CC_noncomp2f,   too_many_1,    wrong_no_1},
    {"sroad",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_sroad},
    {"assert_analyze",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_assert_analyze},
    {"lambda_lqlbvb_1",         too_few_2,      CC_lambda_lqlbvb_1,wrong_no_2},
    {"red-ratios2",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_redKratios2},
    {"tsym4",                   wrong_no_na,    wrong_no_nb,   (n_args *)CC_tsym4},
    {"*i2ar",                   CC_Hi2ar,       too_many_1,    wrong_no_1},
    {"polynommultiplybymonom",  too_few_2,      CC_polynommultiplybymonom,wrong_no_2},
    {"sfto_gcdf*",              too_few_2,      CC_sfto_gcdfH, wrong_no_2},
    {"wulessp",                 too_few_2,      CC_wulessp,    wrong_no_2},
    {"ibalp_litlp",             CC_ibalp_litlp, too_many_1,    wrong_no_1},
    {"carx",                    too_few_2,      CC_carx,       wrong_no_2},
    {"ps:expression",           CC_psTexpression,too_many_1,   wrong_no_1},
    {"c:extmult",               too_few_2,      CC_cTextmult,  wrong_no_2},
    {"testred",                 CC_testred,     too_many_1,    wrong_no_1},
    {"bcone?",                  CC_bconeW,      too_many_1,    wrong_no_1},
    {"ncmpchk",                 too_few_2,      CC_ncmpchk,    wrong_no_2},
    {"scan",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_scan},
    {"rnplus:",                 too_few_2,      CC_rnplusT,    wrong_no_2},
    {"dp=ecart",                CC_dpMecart,    too_many_1,    wrong_no_1},
    {"gperm",                   CC_gperm,       too_many_1,    wrong_no_1},
    {"cdarx",                   CC_cdarx,       too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u07", (two_args *)"3534 3818461 8332700", 0}
};

/* end of generated code */
