
// $destdir/u15.c        Machine generated C code

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
#ifndef DEBUG
#define NDEBUG 1
#endif
#if defined HAVE_COMPLEX_H && \
 defined HAVE_COMPLEX_DOUBLE && \
 defined HAVE_CSQRT
#define HAVE_COMPLEX 1
#endif
#if defined HAVE_SIGNAL_H && defined HAVE_SETJMP_H
#if defined HAVE_SIGSETJMP && defined HAVE_SIGLONGJMP
#if defined HAVE_SIGACTION && defined HAVE_SIGALTSTACK
#define USE_SIGALTSTACK 1
#endif
#endif
#endif
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS 1
#endif
#ifdef WIN32
#define __USE_MINGW_ANSI_STDIO 1
#endif
#ifdef WIN32
#include <winsock.h>
#include <semaphore.h>
#include <windows.h>
#else 
#define unix_posix 1 
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <fcntl.h>
#define WSAGetLastError() errno 
#define WSACleanup() 
#define closesocket(a) close(a)
#define SOCKET int
#define SOCKET_ERROR (-1)
#ifndef INADDR_NONE
# define INADDR_NONE 0xffffffff
#endif
#ifdef HAVE_LIBPTHREAD
#include <semaphore.h>
#include <pthread.h>
#endif
#endif 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <float.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <wctype.h>
#include <time.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <exception>
#include <errno.h>
#include <assert.h>
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
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
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 4)
typedef int32_t intptr_t;
#define INTPTR_MAX INT32_MAX
#define INTPTR_MIN INT32_MIN
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && (SIZEOF_VOID_P == 8)
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 4)
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && (SIZEOF_VOID_P == 8)
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#ifndef UINTPTR_MAX
#define UINTPTR_MAX ((uintptr_t)(-1))
#endif
#ifndef INTPTR_MAX
#define INTPTR_MAX ((intptr_t)((UINTPTR_MAX-1)/2))
#endif
#ifndef INTPTR_MIN
#define INTPTR_MIN (-1-INTPTR_MAX)
#endif
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
#ifdef HAVE_UINT128_T
#define HAVE_NATIVE_UINT128 1
#elif defined HAVE_UNSIGNED___INT128
typedef unsigned __int128 uint128_t;
#define HAVE_NATIVE_UINT128
#else
#include "uint128_t.h" 
#endif
#ifdef HAVE_INT128_T
#define HAVE_NATIVE_INT128 1
#elif defined HAVE___INT128
typedef __int128 int128_t;
#define HAVE_NATIVE_INT128
#elif defined HAVE_UINT128_T || defined HAVE_UNSIGNED___INT128
#error Seem to have unsigned 128-bit type but not a signed one!
#endif
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
static inline bool greaterp128(int128_t a, int128_t b)
{ return a > b;
}
static inline bool lessp128(int128_t a, int128_t b)
{ return a < b;
}
static inline bool geq128(int128_t a, int128_t b)
{ return a >= b;
}
static inline bool leq128(int128_t a, int128_t b)
{ return a <= b;
}
static inline int128_t ASL128(int128_t a, int n)
{ return (uint128_t)a << MAXSHIFT(n, int128_t);
}
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
static inline int128_t ASR128(int128_t a, int n)
{ return a >> MAXSHIFT(n, int128_t);
}
#else 
static inline int128_t ASR128(int128_t a, int n)
{ n = MAXSHIFT(n, int128_t);
 return (a & ~((uint128_t)1<<n - 1))/(int128_t)1<<n;
}
#endif 
static inline int64_t NARROW128(int128_t a)
{ return (int64_t)a;
}
static inline void divrem128(int128_t a, int128_t b,
 int128_t & q, int128_t & r)
{ uint128_t qq = a/b;
 q = qq;
 r = a - qq*b;
}
#else 
typedef uint128_t int128_t;
static inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa > bb;
}
static inline bool lessp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa < bb;
}
static inline bool geq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa >= bb;
}
static inline bool leq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa <= bb;
}
static inline int128_t ASL128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return
 int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
 a.lower()<<n);
 else if (n == 64) return int128_t(a.lower(), 0);
 else return int128_t(a.lower()<<(n-64), 0);
}
static inline int128_t ASR128(const int128_t & a, int n)
{ n = MAXSHIFT(n, int128_t);
 if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
 a.upper());
 else return int128_t(-(int64_t)(a.upper()<0),
 ASR(((int64_t)a.upper()), n-64));
}
static inline int64_t NARROW128(const int128_t & a)
{ return (int64_t)a.lower();
}
static inline void divrem128(const int128_t & a, const int128_t & b,
 int128_t & q, int128_t & r)
{ if ((int64_t)a.upper() < 0)
 { if ((int64_t)b.upper() < 0) q = (-a)/(-b);
 else q = -((-a)/b);
 }
 else
 { if ((int64_t)b.upper() < 0) q = -(a/(-b));
 else q = a/b;
 }
 r = a - q*b;
}
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
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
static inline bool is_forward(LispObject p)
{ return (p & TAG_BITS) == TAG_FORWARD;
}
static inline bool is_number(LispObject p)
{ return (p & TAG_BITS) >= TAG_NUMBERS;
}
static inline bool is_float(LispObject p)
{ return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}
static inline bool is_immed_or_cons(LispObject p)
{ return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool is_immed_cons_sym(LispObject p)
{ return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}
static inline bool need_more_than_eq(LispObject p)
{ return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}
static inline LispObject fixnum_of_int(intptr_t x)
{ return (LispObject)((((uintptr_t)x)<<4) + TAG_FIXNUM);
}
static inline intptr_t int_of_fixnum(LispObject x)
{ return ((intptr_t)x & ~(intptr_t)15)/16;
}
static inline bool valid_as_fixnum(int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
static inline bool intptr_valid_as_fixnum(intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
static inline bool valid_as_fixnum(uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((uintptr_t)1) << 28);
}
static inline bool valid_as_fixnum(uint64_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
static inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
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
#if 0
#define TYPE_MAPLEREF ( 0x2f <<Tw) 
 
#endif
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
typedef union _Float_union
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
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
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
extern LispObject err_table, progn_symbol, gcknt_symbol;
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
extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern bool next_gc_is_hard;
extern uint64_t force_cons, force_vec;
static inline bool cons_forced(size_t n)
{
#ifdef DEBUG
 if (force_cons == 0) return false;
 if (force_cons <= n)
 { force_cons = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_cons -= n;
#endif
 return false;
}
static inline bool vec_forced(size_t n)
{
#ifdef DEBUG
 if (force_vec == 0) return false;
 if (force_vec <= n)
 { force_vec = 0;
 next_gc_is_hard = true;
 return true;
 }
 force_vec -= n;
#endif
 return false;
}
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
extern bool isprime(uint64_t);
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
extern uint64_t sixty_four_bits_unsigned(LispObject a);
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
static inline bool equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return equal_fn(a, b);
 else return false;
}
static inline bool cl_equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
 else return false;
}
static inline bool eql(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return eql_fn(a, b);
 else return false;
}
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
extern unsigned char msd_table[256], lsd_table[256];
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
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND softfloat_round_near_even
#define FIX_FLOOR softfloat_round_min
#define FIX_CEILING softfloat_round_max
extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b, int roundmode);
static inline bool floating_edge_case(double r)
{ return (1.0/r == 0.0 || r != r);
}
static inline void floating_clear_flags()
{}
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
#define fixnum_minusp(a) ((intptr_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
static inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (int32_t)((uint64_t)a>>32);
 else aa.i = (int32_t)(a - XTAG_SFLOAT);
 return aa.f;
}
extern LispObject make_boxfloat(double a, int type);
extern LispObject make_boxfloat128(float128_t a);
static inline LispObject pack_short_float(double d)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with short float");
 }
 aa.i &= ~0xf;
 if (SIXTY_FOUR_BIT)
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT;
 else return aa.i + XTAG_SFLOAT;
}
static inline LispObject pack_single_float(double d)
{ if (SIXTY_FOUR_BIT)
 { Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return (LispObject)((uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
 }
 else
 { LispObject r = getvector(TAG_BOXFLOAT,
 TYPE_SINGLE_FLOAT, sizeof(Single_Float));
 single_float_val(r) = (float)d;
 if (trap_floating_overflow &&
 floating_edge_case(single_float_val(r)))
 { floating_clear_flags();
 aerror("exception with single float");
 }
 return r;
 }
}
static inline LispObject pack_immediate_float(double d,
 LispObject l1, LispObject l2=0)
{ Float_union aa;
 aa.f = d;
 if (trap_floating_overflow &&
 floating_edge_case(aa.f))
 { floating_clear_flags();
 if (((l1 | l2) & XTAG_FLOAT32) != 0)
 aerror("exception with single float");
 else aerror("exception with short float");
 }
 if (SIXTY_FOUR_BIT)
 { if (((l1 | l2) & XTAG_FLOAT32) == 0) aa.i &= ~0xf;
 return (LispObject)(((uint64_t)aa.i) << 32) + XTAG_SFLOAT +
 ((l1 | l2) & XTAG_FLOAT32);
 }
 aa.i &= ~0xf;
 return aa.i + XTAG_SFLOAT;
}
static inline bool eq_i64d(int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((uint64_t)1<<63)) return false;
 return a == (int64_t)b;
}
static inline bool lessp_i64d(int64_t a, double b)
{
 if (a <= ((int64_t)1<<53) &&
 a >= -((int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((uint64_t)1<<63))) return false;
 if (!(b < (double)((uint64_t)1<<63))) return true;
 return a < (int64_t)b;
}
static inline bool lessp_di64(double a, int64_t b)
{
 if (b <= ((int64_t)1<<53) &&
 b >= -((int64_t)1<<53)) return a < (double)b;
 if (!(a < (double)((uint64_t)1<<63))) return false;
 if (!(a >= -(double)((uint64_t)1<<63))) return true;
 return (int64_t)a < b;
}
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
extern "C" LispObject integer_decode_long_float(LispObject a);
extern "C" LispObject Linteger_decode_float(LispObject env, LispObject a);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_n_word_bignum(int32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_n4_word_bignum(int32_t a3, uint32_t a2,
 uint32_t a1, uint32_t a0, size_t n);
extern LispObject make_n5_word_bignum(int32_t a4, uint32_t a3,
 uint32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_power_of_two(size_t n);
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
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
static inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
extern LispObject make_lisp_integer128_fn(int128_t n);
static inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(NARROW128(n));
 else return make_lisp_integer128_fn(n);
}
extern LispObject make_lisp_unsigned128_fn(uint128_t n);
static inline LispObject make_lisp_unsigned128(uint128_t n)
{ if (uint128_valid_as_fixnum(n))
 return fixnum_of_int((uint64_t)NARROW128(n));
 else return make_lisp_unsigned128_fn(n);
}
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern float128_t float128_of_number(LispObject a);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern LispObject rationalf128(float128_t *d);
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
#ifdef WIN32
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
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
static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern "C" void f128M_ldexp(float128_t *p, int n);
extern "C" void f128M_frexp(float128_t *p, float128_t *r, int *x);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern "C" void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif
static inline bool f128M_zero(const float128_t *p)
{ return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_infinite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
static inline bool f128M_finite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}
static inline void f128M_make_infinite(float128_t *p)
{ p->v[HIPART] |= UINT64_C(0x7fff000000000000);
 p->v[HIPART] &= UINT64_C(0xffff000000000000);
 p->v[LOPART] = 0;
}
static inline void f128M_make_zero(float128_t *p)
{ p->v[HIPART] &= UINT64_C(0x8000000000000000);
 p->v[LOPART] = 0;
}
static inline bool f128M_subnorm(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_nan(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
static inline bool f128M_negative(const float128_t *x)
{ if (f128M_nan(x)) return false;
 return ((int64_t)x->v[HIPART]) < 0;
}
static inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
static inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((uint64_t)n + 0x3fff) << 48);
}
static inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
static inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
extern int double_to_binary(double d, int64_t &m);
extern int float128_to_binary(const float128_t *d,
 int64_t &mhi, uint64_t &mlo);
extern intptr_t double_to_3_digits(double d,
 int32_t &a2, uint32_t &a1, uint32_t &a0);
extern intptr_t float128_to_5_digits(float128_t *d,
 int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);
extern "C" float128_t f128_0, 
 f128_half, 
 f128_mhalf, 
 f128_1, 
 f128_10, 
 f128_10_17, 
 f128_10_18, 
 f128_r10, 
 f128_N1; 
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
static inline void f128M_to_f256M(const float128_t *a, float256_t *b)
{ b->hi = *a;
 b->lo = f128_0;
} 
extern "C" void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern "C" void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern "C" float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern "C" int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern "C" int f128M_print_E(int width, int precision, float128_t *p);
extern "C" int f128M_print_F(int width, int precision, float128_t *p);
extern "C" int f128M_print_G(int width, int precision, float128_t *p);
extern "C" float128_t atof128(const char *s);
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1); \
 case TYPE_RATNUM: \
 return name##_r(a1); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1); \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a2))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a2))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(static inline, type, name##_i, name) \
 \
arith_dispatch_1a(static inline, type, name##_b, name) \
 \
arith_dispatch_1a(static inline, type, name##_r, name) \
 \
arith_dispatch_1a(static inline, type, name##_c, name) \
 \
arith_dispatch_1a(static inline, type, name##_s, name) \
 \
arith_dispatch_1a(static inline, type, name##_f, name) \
 \
arith_dispatch_1a(static inline, type, name##_d, name) \
 \
arith_dispatch_1a(static inline, type, name##_l, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
 case (XTAG_SFLOAT & TAG_BITS): \
 return name##_s(a1, a2); \
 case TAG_NUMBERS: \
 switch (type_of_header(numhdr(a1))) \
 { \
 case TYPE_BIGNUM: \
 return name##_b(a1, a2); \
 case TYPE_RATNUM: \
 return name##_r(a1, a2); \
 case TYPE_COMPLEX_NUM: \
 return name##_c(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 case TAG_BOXFLOAT: \
 switch (type_of_header(flthdr(a1))) \
 { \
 case TYPE_SINGLE_FLOAT: \
 return name##_f(a1, a2); \
 case TYPE_DOUBLE_FLOAT: \
 return name##_d(a1, a2); \
 case TYPE_LONG_FLOAT: \
 return name##_l(a1, a2); \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
}
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



// Code for matsm!*1

static LispObject CC_matsmH1(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_8090, v_8091;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    v_8090 = v_7951;
// end of prologue
    goto v_7960;
v_7956:
    stack[-8] = elt(env, 1); // mat
    goto v_7957;
v_7958:
    stack[-7] = v_8090;
    v_8090 = stack[-7];
    if (v_8090 == nil) goto v_7971;
    else goto v_7972;
v_7971:
    v_8090 = nil;
    goto v_7966;
v_7972:
    v_8090 = stack[-7];
    v_8090 = qcar(v_8090);
    stack[-3] = v_8090;
    v_8090 = stack[-3];
    if (v_8090 == nil) goto v_7988;
    else goto v_7989;
v_7988:
    v_8090 = nil;
    goto v_7983;
v_7989:
    v_8090 = stack[-3];
    v_8090 = qcar(v_8090);
    fn = elt(env, 3); // subs2!*
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    v_8090 = ncons(v_8090);
    env = stack[-9];
    stack[-1] = v_8090;
    stack[-2] = v_8090;
v_7984:
    v_8090 = stack[-3];
    v_8090 = qcdr(v_8090);
    stack[-3] = v_8090;
    v_8090 = stack[-3];
    if (v_8090 == nil) goto v_8003;
    else goto v_8004;
v_8003:
    v_8090 = stack[-2];
    goto v_7983;
v_8004:
    goto v_8012;
v_8008:
    stack[0] = stack[-1];
    goto v_8009;
v_8010:
    v_8090 = stack[-3];
    v_8090 = qcar(v_8090);
    fn = elt(env, 3); // subs2!*
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    v_8090 = ncons(v_8090);
    env = stack[-9];
    goto v_8011;
v_8012:
    goto v_8008;
v_8009:
    goto v_8010;
v_8011:
    v_8090 = Lrplacd(nil, stack[0], v_8090);
    env = stack[-9];
    v_8090 = stack[-1];
    v_8090 = qcdr(v_8090);
    stack[-1] = v_8090;
    goto v_7984;
v_7983:
    v_8090 = ncons(v_8090);
    env = stack[-9];
    stack[-5] = v_8090;
    stack[-6] = v_8090;
v_7967:
    v_8090 = stack[-7];
    v_8090 = qcdr(v_8090);
    stack[-7] = v_8090;
    v_8090 = stack[-7];
    if (v_8090 == nil) goto v_8027;
    else goto v_8028;
v_8027:
    v_8090 = stack[-6];
    goto v_7966;
v_8028:
    goto v_8036;
v_8032:
    stack[-4] = stack[-5];
    goto v_8033;
v_8034:
    v_8090 = stack[-7];
    v_8090 = qcar(v_8090);
    stack[-3] = v_8090;
    v_8090 = stack[-3];
    if (v_8090 == nil) goto v_8051;
    else goto v_8052;
v_8051:
    v_8090 = nil;
    goto v_8046;
v_8052:
    v_8090 = stack[-3];
    v_8090 = qcar(v_8090);
    fn = elt(env, 3); // subs2!*
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    v_8090 = ncons(v_8090);
    env = stack[-9];
    stack[-1] = v_8090;
    stack[-2] = v_8090;
v_8047:
    v_8090 = stack[-3];
    v_8090 = qcdr(v_8090);
    stack[-3] = v_8090;
    v_8090 = stack[-3];
    if (v_8090 == nil) goto v_8066;
    else goto v_8067;
v_8066:
    v_8090 = stack[-2];
    goto v_8046;
v_8067:
    goto v_8075;
v_8071:
    stack[0] = stack[-1];
    goto v_8072;
v_8073:
    v_8090 = stack[-3];
    v_8090 = qcar(v_8090);
    fn = elt(env, 3); // subs2!*
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    fn = elt(env, 4); // !*q2a
    v_8090 = (*qfn1(fn))(fn, v_8090);
    env = stack[-9];
    v_8090 = ncons(v_8090);
    env = stack[-9];
    goto v_8074;
v_8075:
    goto v_8071;
v_8072:
    goto v_8073;
v_8074:
    v_8090 = Lrplacd(nil, stack[0], v_8090);
    env = stack[-9];
    v_8090 = stack[-1];
    v_8090 = qcdr(v_8090);
    stack[-1] = v_8090;
    goto v_8047;
v_8046:
    v_8090 = ncons(v_8090);
    env = stack[-9];
    goto v_8035;
v_8036:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    v_8090 = Lrplacd(nil, stack[-4], v_8090);
    env = stack[-9];
    v_8090 = stack[-5];
    v_8090 = qcdr(v_8090);
    stack[-5] = v_8090;
    goto v_7967;
v_7966:
    goto v_7959;
v_7960:
    goto v_7956;
v_7957:
    goto v_7958;
v_7959:
    v_8090 = cons(stack[-8], v_8090);
    env = stack[-9];
    v_8091 = nil;
    qvalue(elt(env, 2)) = v_8091; // !*sub2
    return onevalue(v_8090);
}



// Code for maxtype

static LispObject CC_maxtype(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7971, v_7972;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
// copy arguments values to proper place
    v_7972 = v_7951;
// end of prologue
    v_7971 = v_7972;
    if (!consp(v_7971)) goto v_7955;
    else goto v_7956;
v_7955:
    v_7971 = v_7972;
    goto v_7954;
v_7956:
    v_7971 = v_7972;
    v_7971 = qcdr(v_7971);
    v_7971 = Lconsp(nil, v_7971);
    if (v_7971 == nil) goto v_7960;
    v_7971 = v_7972;
    v_7971 = qcdr(v_7971);
    v_7971 = qcar(v_7971);
    goto v_7954;
v_7960:
    v_7971 = v_7972;
    v_7971 = qcar(v_7971);
    goto v_7954;
    v_7971 = nil;
v_7954:
    return onevalue(v_7971);
}



// Code for bind

static LispObject CC_bind(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7973, v_7974;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7974 = v_7952;
    v_7973 = v_7951;
// end of prologue
    goto v_7961;
v_7955:
    stack[-1] = v_7973;
    goto v_7956;
v_7957:
    stack[0] = elt(env, 1); // binding
    goto v_7958;
v_7959:
    goto v_7969;
v_7965:
    goto v_7966;
v_7967:
    if (!symbolp(v_7973)) v_7973 = nil;
    else { v_7973 = qfastgets(v_7973);
           if (v_7973 != nil) { v_7973 = elt(v_7973, 13); // binding
#ifdef RECORD_GET
             if (v_7973 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v_7973 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v_7973 == SPID_NOPROP) v_7973 = nil; }}
#endif
    goto v_7968;
v_7969:
    goto v_7965;
v_7966:
    goto v_7967;
v_7968:
    v_7973 = cons(v_7974, v_7973);
    goto v_7960;
v_7961:
    goto v_7955;
v_7956:
    goto v_7957;
v_7958:
    goto v_7959;
v_7960:
    {
        LispObject v_7977 = stack[-1];
        LispObject v_7978 = stack[0];
        return Lputprop(nil, 3, v_7977, v_7978, v_7973);
    }
}



// Code for triviallcm

static LispObject CC_triviallcm(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7970, v_7971;
    LispObject fn;
    LispObject v_7953, v_7952, v_7951;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "triviallcm");
    va_start(aa, nargs);
    v_7951 = va_arg(aa, LispObject);
    v_7952 = va_arg(aa, LispObject);
    v_7953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7953,v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7951,v_7952,v_7953);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    stack[0] = v_7953;
    v_7971 = v_7952;
    v_7970 = v_7951;
// end of prologue
    goto v_7959;
v_7955:
    goto v_7965;
v_7961:
    goto v_7962;
v_7963:
    goto v_7964;
v_7965:
    goto v_7961;
v_7962:
    goto v_7963;
v_7964:
    fn = elt(env, 1); // xdiv
    v_7971 = (*qfn2(fn))(fn, v_7971, v_7970);
    goto v_7956;
v_7957:
    v_7970 = stack[0];
    goto v_7958;
v_7959:
    goto v_7955;
v_7956:
    goto v_7957;
v_7958:
    v_7970 = (equal(v_7971, v_7970) ? lisp_true : nil);
    return onevalue(v_7970);
}



// Code for mkid

static LispObject CC_mkid(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8018, v_8019;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7952;
    v_8018 = v_7951;
// end of prologue
    v_8019 = v_8018;
    if (symbolp(v_8019)) goto v_7957;
    goto v_7964;
v_7960:
    v_8019 = v_8018;
    goto v_7961;
v_7962:
    v_8018 = elt(env, 1); // "MKID root"
    goto v_7963;
v_7964:
    goto v_7960;
v_7961:
    goto v_7962;
v_7963:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_8019, v_8018);
    }
v_7957:
    v_8019 = stack[0];
    if (!consp(v_8019)) goto v_7971;
    else goto v_7972;
v_7971:
    v_8019 = stack[0];
    v_8019 = Lsymbolp(nil, v_8019);
    env = stack[-2];
    if (v_8019 == nil) goto v_7976;
    else goto v_7975;
v_7976:
    v_8019 = stack[0];
    v_8019 = integerp(v_8019);
    if (v_8019 == nil) goto v_7981;
    else goto v_7982;
v_7981:
    v_8019 = nil;
    goto v_7980;
v_7982:
    v_8019 = stack[0];
    v_8019 = Lminusp(nil, v_8019);
    env = stack[-2];
    v_8019 = (v_8019 == nil ? lisp_true : nil);
    goto v_7980;
    v_8019 = nil;
v_7980:
v_7975:
    goto v_7970;
v_7972:
    v_8019 = nil;
    goto v_7970;
    v_8019 = nil;
v_7970:
    if (v_8019 == nil) goto v_7968;
    goto v_8001;
v_7997:
    fn = elt(env, 4); // get!-print!-name
    v_8018 = (*qfn1(fn))(fn, v_8018);
    env = stack[-2];
    stack[-1] = Lexplode(nil, v_8018);
    env = stack[-2];
    goto v_7998;
v_7999:
    v_8018 = stack[0];
    fn = elt(env, 4); // get!-print!-name
    v_8018 = (*qfn1(fn))(fn, v_8018);
    env = stack[-2];
    v_8018 = Lexplode(nil, v_8018);
    env = stack[-2];
    goto v_8000;
v_8001:
    goto v_7997;
v_7998:
    goto v_7999;
v_8000:
    v_8018 = Lnconc(nil, stack[-1], v_8018);
    env = stack[-2];
    v_8018 = Lcompress(nil, v_8018);
        return Lintern(nil, v_8018);
v_7968:
    goto v_8015;
v_8011:
    v_8019 = stack[0];
    goto v_8012;
v_8013:
    v_8018 = elt(env, 2); // "MKID index"
    goto v_8014;
v_8015:
    goto v_8011;
v_8012:
    goto v_8013;
v_8014:
    {
        fn = elt(env, 3); // typerr
        return (*qfn2(fn))(fn, v_8019, v_8018);
    }
    v_8018 = nil;
    return onevalue(v_8018);
}



// Code for aminusp!:1

static LispObject CC_aminuspT1(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_8071, v_8072, v_8073, v_8074;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7951;
// end of prologue
    v_8071 = stack[-1];
    fn = elt(env, 4); // aeval!*
    v_8071 = (*qfn1(fn))(fn, v_8071);
    env = stack[-3];
    stack[-1] = v_8071;
    v_8071 = stack[-1];
    stack[-2] = v_8071;
    v_8071 = stack[-2];
    v_8071 = integerp(v_8071);
    if (v_8071 == nil) goto v_7962;
    v_8071 = stack[-2];
        return Lminusp(nil, v_8071);
v_7962:
    goto v_7974;
v_7970:
    v_8072 = stack[-2];
    goto v_7971;
v_7972:
    v_8071 = elt(env, 1); // !*sq
    goto v_7973;
v_7974:
    goto v_7970;
v_7971:
    goto v_7972;
v_7973:
    if (!consp(v_8072)) goto v_7967;
    v_8072 = qcar(v_8072);
    if (v_8072 == v_8071) goto v_7968;
v_7967:
    goto v_7988;
v_7978:
    stack[0] = nil;
    goto v_7979;
v_7980:
    v_8071 = stack[-1];
    fn = elt(env, 5); // reval
    v_8074 = (*qfn1(fn))(fn, v_8071);
    env = stack[-3];
    goto v_7981;
v_7982:
    v_8073 = elt(env, 2); // "invalid in FOR statement"
    goto v_7983;
v_7984:
    v_8072 = nil;
    goto v_7985;
v_7986:
    v_8071 = lisp_true;
    goto v_7987;
v_7988:
    goto v_7978;
v_7979:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    goto v_7986;
v_7987:
    fn = elt(env, 6); // msgpri
    v_8071 = (*qfnn(fn))(fn, 5, stack[0], v_8074, v_8073, v_8072, v_8071);
    env = stack[-3];
    goto v_7960;
v_7968:
v_7960:
    v_8071 = stack[-2];
    v_8071 = qcdr(v_8071);
    v_8071 = qcar(v_8071);
    stack[-2] = v_8071;
    v_8071 = stack[-2];
    v_8071 = qcar(v_8071);
    v_8071 = integerp(v_8071);
    if (v_8071 == nil) goto v_8001;
    v_8071 = stack[-2];
    v_8071 = qcdr(v_8071);
    v_8071 = integerp(v_8071);
    if (v_8071 == nil) goto v_8001;
    v_8071 = stack[-2];
    v_8071 = qcar(v_8071);
        return Lminusp(nil, v_8071);
v_8001:
    goto v_8023;
v_8019:
    v_8071 = stack[-2];
    v_8072 = qcdr(v_8071);
    goto v_8020;
v_8021:
    v_8071 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8022;
v_8023:
    goto v_8019;
v_8020:
    goto v_8021;
v_8022:
    if (v_8072 == v_8071) goto v_8018;
    v_8071 = lisp_true;
    goto v_8016;
v_8018:
    v_8071 = stack[-2];
    v_8071 = qcar(v_8071);
    stack[-2] = v_8071;
    if (!consp(v_8071)) goto v_8032;
    else goto v_8033;
v_8032:
    v_8071 = lisp_true;
    goto v_8031;
v_8033:
    v_8071 = stack[-2];
    v_8071 = qcar(v_8071);
    v_8071 = (consp(v_8071) ? nil : lisp_true);
    goto v_8031;
    v_8071 = nil;
v_8031:
    v_8071 = (v_8071 == nil ? lisp_true : nil);
    goto v_8016;
    v_8071 = nil;
v_8016:
    if (v_8071 == nil) goto v_8014;
    goto v_8054;
v_8044:
    stack[0] = nil;
    goto v_8045;
v_8046:
    v_8071 = stack[-1];
    fn = elt(env, 5); // reval
    v_8074 = (*qfn1(fn))(fn, v_8071);
    env = stack[-3];
    goto v_8047;
v_8048:
    v_8073 = elt(env, 2); // "invalid in FOR statement"
    goto v_8049;
v_8050:
    v_8072 = nil;
    goto v_8051;
v_8052:
    v_8071 = lisp_true;
    goto v_8053;
v_8054:
    goto v_8044;
v_8045:
    goto v_8046;
v_8047:
    goto v_8048;
v_8049:
    goto v_8050;
v_8051:
    goto v_8052;
v_8053:
    fn = elt(env, 6); // msgpri
    v_8071 = (*qfnn(fn))(fn, 5, stack[0], v_8074, v_8073, v_8072, v_8071);
    goto v_7999;
v_8014:
    goto v_8068;
v_8064:
    v_8072 = elt(env, 3); // !:minusp
    goto v_8065;
v_8066:
    v_8071 = stack[-2];
    goto v_8067;
v_8068:
    goto v_8064;
v_8065:
    goto v_8066;
v_8067:
        return Lapply1(nil, v_8072, v_8071);
v_7999:
    v_8071 = nil;
    return onevalue(v_8071);
}



// Code for groeb!=better

static LispObject CC_groebMbetter(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8016, v_8017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    goto v_7963;
v_7959:
    v_8016 = stack[-1];
    v_8016 = qcdr(v_8016);
    v_8017 = qcar(v_8016);
    goto v_7960;
v_7961:
    v_8016 = stack[0];
    v_8016 = qcdr(v_8016);
    v_8016 = qcar(v_8016);
    goto v_7962;
v_7963:
    goto v_7959;
v_7960:
    goto v_7961;
v_7962:
    v_8016 = (LispObject)lessp2(v_8017, v_8016);
    v_8016 = v_8016 ? lisp_true : nil;
    env = stack[-2];
    if (v_8016 == nil) goto v_7957;
    v_8016 = lisp_true;
    goto v_7955;
v_7957:
    goto v_7977;
v_7973:
    v_8016 = stack[-1];
    v_8016 = qcdr(v_8016);
    v_8017 = qcar(v_8016);
    goto v_7974;
v_7975:
    v_8016 = stack[0];
    v_8016 = qcdr(v_8016);
    v_8016 = qcar(v_8016);
    goto v_7976;
v_7977:
    goto v_7973;
v_7974:
    goto v_7975;
v_7976:
    if (equal(v_8017, v_8016)) goto v_7971;
    else goto v_7972;
v_7971:
    goto v_7989;
v_7985:
    goto v_7995;
v_7991:
    goto v_8001;
v_7997:
    v_8017 = stack[-1];
    goto v_7998;
v_7999:
    v_8016 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8000;
v_8001:
    goto v_7997;
v_7998:
    goto v_7999;
v_8000:
    fn = elt(env, 1); // nth
    stack[-1] = (*qfn2(fn))(fn, v_8017, v_8016);
    env = stack[-2];
    goto v_7992;
v_7993:
    goto v_8009;
v_8005:
    v_8017 = stack[0];
    goto v_8006;
v_8007:
    v_8016 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    fn = elt(env, 1); // nth
    v_8016 = (*qfn2(fn))(fn, v_8017, v_8016);
    env = stack[-2];
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    fn = elt(env, 2); // mo_compare
    v_8017 = (*qfn2(fn))(fn, stack[-1], v_8016);
    goto v_7986;
v_7987:
    v_8016 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7988;
v_7989:
    goto v_7985;
v_7986:
    goto v_7987;
v_7988:
        return Lleq(nil, v_8017, v_8016);
v_7972:
    v_8016 = nil;
    goto v_7955;
    v_8016 = nil;
v_7955:
    return onevalue(v_8016);
}



// Code for dcombine

static LispObject CC_dcombine(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8447, v_8448, v_8449;
    LispObject fn;
    LispObject v_7953, v_7952, v_7951;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "dcombine");
    va_start(aa, nargs);
    v_7951 = va_arg(aa, LispObject);
    v_7952 = va_arg(aa, LispObject);
    v_7953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7953,v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7951,v_7952,v_7953);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-3] = v_7953;
    stack[-4] = v_7952;
    stack[-5] = v_7951;
// end of prologue
    v_8447 = stack[-5];
    if (!consp(v_8447)) goto v_7957;
    else goto v_7958;
v_7957:
    goto v_7967;
v_7961:
    goto v_7973;
v_7969:
    v_8447 = stack[-4];
    v_8448 = qcar(v_8447);
    goto v_7970;
v_7971:
    v_8447 = stack[-3];
    goto v_7972;
v_7973:
    goto v_7969;
v_7970:
    goto v_7971;
v_7972:
    stack[0] = get(v_8448, v_8447);
    env = stack[-7];
    goto v_7962;
v_7963:
    goto v_7982;
v_7978:
    v_8447 = stack[-4];
    v_8447 = qcar(v_8447);
    if (!symbolp(v_8447)) v_8448 = nil;
    else { v_8448 = qfastgets(v_8447);
           if (v_8448 != nil) { v_8448 = elt(v_8448, 34); // i2d
#ifdef RECORD_GET
             if (v_8448 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_8448 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_8448 == SPID_NOPROP) v_8448 = nil; }}
#endif
    goto v_7979;
v_7980:
    v_8447 = stack[-5];
    goto v_7981;
v_7982:
    goto v_7978;
v_7979:
    goto v_7980;
v_7981:
    v_8448 = Lapply1(nil, v_8448, v_8447);
    env = stack[-7];
    goto v_7964;
v_7965:
    v_8447 = stack[-4];
    goto v_7966;
v_7967:
    goto v_7961;
v_7962:
    goto v_7963;
v_7964:
    goto v_7965;
v_7966:
    v_8447 = Lapply2(nil, 3, stack[0], v_8448, v_8447);
    env = stack[-7];
    goto v_7956;
v_7958:
    v_8447 = stack[-4];
    if (!consp(v_8447)) goto v_7988;
    else goto v_7989;
v_7988:
    goto v_7998;
v_7992:
    goto v_8004;
v_8000:
    v_8447 = stack[-5];
    v_8448 = qcar(v_8447);
    goto v_8001;
v_8002:
    v_8447 = stack[-3];
    goto v_8003;
v_8004:
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    stack[-1] = get(v_8448, v_8447);
    env = stack[-7];
    goto v_7993;
v_7994:
    stack[0] = stack[-5];
    goto v_7995;
v_7996:
    goto v_8014;
v_8010:
    v_8447 = stack[-5];
    v_8447 = qcar(v_8447);
    if (!symbolp(v_8447)) v_8448 = nil;
    else { v_8448 = qfastgets(v_8447);
           if (v_8448 != nil) { v_8448 = elt(v_8448, 34); // i2d
#ifdef RECORD_GET
             if (v_8448 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v_8448 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v_8448 == SPID_NOPROP) v_8448 = nil; }}
#endif
    goto v_8011;
v_8012:
    v_8447 = stack[-4];
    goto v_8013;
v_8014:
    goto v_8010;
v_8011:
    goto v_8012;
v_8013:
    v_8447 = Lapply1(nil, v_8448, v_8447);
    env = stack[-7];
    goto v_7997;
v_7998:
    goto v_7992;
v_7993:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    v_8447 = Lapply2(nil, 3, stack[-1], stack[0], v_8447);
    env = stack[-7];
    goto v_7956;
v_7989:
    goto v_8025;
v_8021:
    v_8447 = stack[-5];
    v_8448 = qcar(v_8447);
    goto v_8022;
v_8023:
    v_8447 = stack[-4];
    v_8447 = qcar(v_8447);
    goto v_8024;
v_8025:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    if (v_8448 == v_8447) goto v_8019;
    else goto v_8020;
v_8019:
    goto v_8037;
v_8031:
    goto v_8043;
v_8039:
    v_8447 = stack[-5];
    v_8448 = qcar(v_8447);
    goto v_8040;
v_8041:
    v_8447 = stack[-3];
    goto v_8042;
v_8043:
    goto v_8039;
v_8040:
    goto v_8041;
v_8042:
    v_8449 = get(v_8448, v_8447);
    env = stack[-7];
    goto v_8032;
v_8033:
    v_8448 = stack[-5];
    goto v_8034;
v_8035:
    v_8447 = stack[-4];
    goto v_8036;
v_8037:
    goto v_8031;
v_8032:
    goto v_8033;
v_8034:
    goto v_8035;
v_8036:
    v_8447 = Lapply2(nil, 3, v_8449, v_8448, v_8447);
    env = stack[-7];
    goto v_7956;
v_8020:
    v_8447 = stack[-5];
    v_8448 = qcar(v_8447);
    v_8447 = stack[-4];
    v_8447 = qcar(v_8447);
    stack[-6] = v_8448;
    stack[-2] = v_8447;
    goto v_8062;
v_8058:
    v_8448 = stack[-6];
    goto v_8059;
v_8060:
    v_8447 = stack[-2];
    goto v_8061;
v_8062:
    goto v_8058;
v_8059:
    goto v_8060;
v_8061:
    v_8449 = get(v_8448, v_8447);
    env = stack[-7];
    v_8448 = elt(env, 1); // (!:crn!: !:gi!:)
    v_8447 = elt(env, 2); // (!:rd!: !:cr!:)
    stack[-1] = v_8449;
    stack[0] = v_8448;
    v_8449 = v_8447;
    v_8447 = stack[-1];
    if (v_8447 == nil) goto v_8077;
    v_8447 = stack[-1];
    if (!consp(v_8447)) goto v_8081;
    else goto v_8077;
v_8081:
    goto v_8078;
v_8077:
    v_8447 = lisp_true;
    goto v_8076;
v_8078:
    goto v_8097;
v_8093:
    v_8448 = stack[-6];
    goto v_8094;
v_8095:
    v_8447 = elt(env, 3); // cmpxfn
    goto v_8096;
v_8097:
    goto v_8093;
v_8094:
    goto v_8095;
v_8096:
    v_8447 = get(v_8448, v_8447);
    env = stack[-7];
    if (v_8447 == nil) goto v_8090;
    goto v_8106;
v_8102:
    v_8448 = stack[-2];
    goto v_8103;
v_8104:
    v_8447 = elt(env, 3); // cmpxfn
    goto v_8105;
v_8106:
    goto v_8102;
v_8103:
    goto v_8104;
v_8105:
    v_8447 = get(v_8448, v_8447);
    env = stack[-7];
    if (v_8447 == nil) goto v_8100;
    else goto v_8090;
v_8100:
    goto v_8089;
v_8090:
    goto v_8115;
v_8111:
    v_8448 = stack[-6];
    goto v_8112;
v_8113:
    v_8447 = v_8449;
    goto v_8114;
v_8115:
    goto v_8111;
v_8112:
    goto v_8113;
v_8114:
    v_8447 = Lmemq(nil, v_8448, v_8447);
    if (v_8447 == nil) goto v_8109;
    goto v_8124;
v_8120:
    v_8447 = stack[-2];
    goto v_8121;
v_8122:
    v_8448 = v_8449;
    goto v_8123;
v_8124:
    goto v_8120;
v_8121:
    goto v_8122;
v_8123:
    v_8447 = Lmemq(nil, v_8447, v_8448);
    if (v_8447 == nil) goto v_8119;
    else goto v_8109;
v_8119:
    goto v_8089;
v_8109:
    v_8447 = nil;
    goto v_8087;
v_8089:
    goto v_8136;
v_8132:
    v_8448 = stack[-2];
    goto v_8133;
v_8134:
    v_8447 = elt(env, 4); // !:ps!:
    goto v_8135;
v_8136:
    goto v_8132;
v_8133:
    goto v_8134;
v_8135:
    v_8447 = Lneq(nil, v_8448, v_8447);
    env = stack[-7];
    goto v_8087;
    v_8447 = nil;
v_8087:
    goto v_8076;
    v_8447 = nil;
v_8076:
    if (v_8447 == nil) goto v_8073;
    goto v_8145;
v_8141:
    v_8448 = stack[-2];
    goto v_8142;
v_8143:
    v_8447 = elt(env, 5); // noconvert
    goto v_8144;
v_8145:
    goto v_8141;
v_8142:
    goto v_8143;
v_8144:
    v_8447 = Lflagp(nil, v_8448, v_8447);
    env = stack[-7];
    if (v_8447 == nil) goto v_8139;
    else goto v_8073;
v_8139:
    goto v_8158;
v_8154:
    v_8448 = stack[-6];
    goto v_8155;
v_8156:
    v_8447 = stack[0];
    goto v_8157;
v_8158:
    goto v_8154;
v_8155:
    goto v_8156;
v_8157:
    v_8447 = Lmemq(nil, v_8448, v_8447);
    if (v_8447 == nil) goto v_8152;
    goto v_8167;
v_8163:
    v_8448 = stack[-2];
    goto v_8164;
v_8165:
    v_8447 = elt(env, 6); // !:rd!:
    goto v_8166;
v_8167:
    goto v_8163;
v_8164:
    goto v_8165;
v_8166:
    if (v_8448 == v_8447) goto v_8162;
    else goto v_8152;
v_8162:
    goto v_8150;
v_8152:
    goto v_8179;
v_8175:
    v_8448 = stack[-6];
    goto v_8176;
v_8177:
    v_8447 = elt(env, 6); // !:rd!:
    goto v_8178;
v_8179:
    goto v_8175;
v_8176:
    goto v_8177;
v_8178:
    if (v_8448 == v_8447) goto v_8173;
    else goto v_8174;
v_8173:
    goto v_8186;
v_8182:
    v_8448 = stack[-2];
    goto v_8183;
v_8184:
    v_8447 = stack[0];
    goto v_8185;
v_8186:
    goto v_8182;
v_8183:
    goto v_8184;
v_8185:
    v_8447 = Lmemq(nil, v_8448, v_8447);
    goto v_8172;
v_8174:
    v_8447 = nil;
    goto v_8172;
    v_8447 = nil;
v_8172:
    if (v_8447 == nil) goto v_8170;
    else goto v_8150;
v_8170:
    goto v_8151;
v_8150:
    goto v_8198;
v_8194:
    goto v_8204;
v_8200:
    v_8448 = stack[-6];
    goto v_8201;
v_8202:
    v_8447 = elt(env, 7); // !:cr!:
    goto v_8203;
v_8204:
    goto v_8200;
v_8201:
    goto v_8202;
v_8203:
    v_8448 = get(v_8448, v_8447);
    env = stack[-7];
    goto v_8195;
v_8196:
    v_8447 = stack[-5];
    goto v_8197;
v_8198:
    goto v_8194;
v_8195:
    goto v_8196;
v_8197:
    v_8447 = Lapply1(nil, v_8448, v_8447);
    env = stack[-7];
    stack[-5] = v_8447;
    v_8447 = elt(env, 7); // !:cr!:
    stack[-6] = v_8447;
    goto v_8149;
v_8151:
    goto v_8223;
v_8219:
    v_8448 = stack[-6];
    goto v_8220;
v_8221:
    v_8447 = elt(env, 8); // !:rn!:
    goto v_8222;
v_8223:
    goto v_8219;
v_8220:
    goto v_8221;
v_8222:
    if (v_8448 == v_8447) goto v_8217;
    else goto v_8218;
v_8217:
    goto v_8230;
v_8226:
    v_8448 = stack[-2];
    goto v_8227;
v_8228:
    v_8447 = elt(env, 9); // !:gi!:
    goto v_8229;
v_8230:
    goto v_8226;
v_8227:
    goto v_8228;
v_8229:
    v_8447 = (v_8448 == v_8447 ? lisp_true : nil);
    goto v_8216;
v_8218:
    v_8447 = nil;
    goto v_8216;
    v_8447 = nil;
v_8216:
    if (v_8447 == nil) goto v_8214;
    v_8447 = lisp_true;
    goto v_8212;
v_8214:
    goto v_8248;
v_8244:
    v_8448 = stack[-6];
    goto v_8245;
v_8246:
    v_8447 = elt(env, 9); // !:gi!:
    goto v_8247;
v_8248:
    goto v_8244;
v_8245:
    goto v_8246;
v_8247:
    if (v_8448 == v_8447) goto v_8242;
    else goto v_8243;
v_8242:
    goto v_8255;
v_8251:
    v_8448 = stack[-2];
    goto v_8252;
v_8253:
    v_8447 = elt(env, 8); // !:rn!:
    goto v_8254;
v_8255:
    goto v_8251;
v_8252:
    goto v_8253;
v_8254:
    v_8447 = (v_8448 == v_8447 ? lisp_true : nil);
    goto v_8241;
v_8243:
    v_8447 = nil;
    goto v_8241;
    v_8447 = nil;
v_8241:
    goto v_8212;
    v_8447 = nil;
v_8212:
    if (v_8447 == nil) goto v_8210;
    goto v_8267;
v_8263:
    goto v_8273;
v_8269:
    v_8448 = stack[-6];
    goto v_8270;
v_8271:
    v_8447 = elt(env, 10); // !:crn!:
    goto v_8272;
v_8273:
    goto v_8269;
v_8270:
    goto v_8271;
v_8272:
    v_8448 = get(v_8448, v_8447);
    env = stack[-7];
    goto v_8264;
v_8265:
    v_8447 = stack[-5];
    goto v_8266;
v_8267:
    goto v_8263;
v_8264:
    goto v_8265;
v_8266:
    v_8447 = Lapply1(nil, v_8448, v_8447);
    env = stack[-7];
    stack[-5] = v_8447;
    v_8447 = elt(env, 10); // !:crn!:
    stack[-6] = v_8447;
    goto v_8149;
v_8210:
v_8149:
    goto v_8283;
v_8279:
    goto v_8289;
v_8285:
    v_8448 = stack[-2];
    goto v_8286;
v_8287:
    v_8447 = stack[-6];
    goto v_8288;
v_8289:
    goto v_8285;
v_8286:
    goto v_8287;
v_8288:
    v_8448 = get(v_8448, v_8447);
    env = stack[-7];
    goto v_8280;
v_8281:
    v_8447 = stack[-4];
    goto v_8282;
v_8283:
    goto v_8279;
v_8280:
    goto v_8281;
v_8282:
    v_8447 = Lapply1(nil, v_8448, v_8447);
    env = stack[-7];
    stack[-4] = v_8447;
    goto v_8298;
v_8294:
    v_8448 = stack[-6];
    goto v_8295;
v_8296:
    v_8447 = stack[-3];
    goto v_8297;
v_8298:
    goto v_8294;
v_8295:
    goto v_8296;
v_8297:
    v_8447 = get(v_8448, v_8447);
    env = stack[-7];
    stack[-1] = v_8447;
    goto v_8071;
v_8073:
    goto v_8308;
v_8304:
    v_8448 = stack[-1];
    goto v_8305;
v_8306:
    v_8447 = stack[-5];
    goto v_8307;
v_8308:
    goto v_8304;
v_8305:
    goto v_8306;
v_8307:
    v_8447 = Lapply1(nil, v_8448, v_8447);
    env = stack[-7];
    stack[-5] = v_8447;
    goto v_8316;
v_8312:
    v_8448 = stack[-2];
    goto v_8313;
v_8314:
    v_8447 = stack[-3];
    goto v_8315;
v_8316:
    goto v_8312;
v_8313:
    goto v_8314;
v_8315:
    v_8447 = get(v_8448, v_8447);
    env = stack[-7];
    stack[-1] = v_8447;
    goto v_8071;
v_8071:
    goto v_8326;
v_8320:
    v_8449 = stack[-1];
    goto v_8321;
v_8322:
    v_8448 = stack[-5];
    goto v_8323;
v_8324:
    v_8447 = stack[-4];
    goto v_8325;
v_8326:
    goto v_8320;
v_8321:
    goto v_8322;
v_8323:
    goto v_8324;
v_8325:
    v_8447 = Lapply2(nil, 3, v_8449, v_8448, v_8447);
    env = stack[-7];
    goto v_7956;
    v_8447 = nil;
v_7956:
    stack[-5] = v_8447;
    v_8447 = qvalue(elt(env, 11)); // !*rounded
    if (v_8447 == nil) goto v_8333;
    v_8447 = qvalue(elt(env, 12)); // !*roundall
    if (v_8447 == nil) goto v_8333;
    v_8447 = stack[-5];
    if (!consp(v_8447)) goto v_8333;
    goto v_8354;
v_8350:
    v_8447 = stack[-5];
    v_8448 = qcar(v_8447);
    stack[-4] = v_8448;
    goto v_8351;
v_8352:
    v_8447 = elt(env, 8); // !:rn!:
    goto v_8353;
v_8354:
    goto v_8350;
v_8351:
    goto v_8352;
v_8353:
    if (v_8448 == v_8447) goto v_8348;
    else goto v_8349;
v_8348:
    goto v_8363;
v_8359:
    v_8447 = stack[-5];
    v_8447 = qcdr(v_8447);
    v_8448 = qcdr(v_8447);
    goto v_8360;
v_8361:
    v_8447 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8362;
v_8363:
    goto v_8359;
v_8360:
    goto v_8361;
v_8362:
    v_8447 = Lneq(nil, v_8448, v_8447);
    env = stack[-7];
    goto v_8347;
v_8349:
    v_8447 = nil;
    goto v_8347;
    v_8447 = nil;
v_8347:
    if (v_8447 == nil) goto v_8345;
    v_8447 = stack[-5];
    fn = elt(env, 14); // !*rn2rd
    v_8447 = (*qfn1(fn))(fn, v_8447);
    env = stack[-7];
    goto v_8343;
v_8345:
    goto v_8383;
v_8379:
    v_8448 = stack[-4];
    goto v_8380;
v_8381:
    v_8447 = elt(env, 10); // !:crn!:
    goto v_8382;
v_8383:
    goto v_8379;
v_8380:
    goto v_8381;
v_8382:
    if (v_8448 == v_8447) goto v_8377;
    else goto v_8378;
v_8377:
    goto v_8394;
v_8390:
    v_8447 = stack[-5];
    v_8447 = qcdr(v_8447);
    v_8447 = qcar(v_8447);
    v_8448 = qcdr(v_8447);
    goto v_8391;
v_8392:
    v_8447 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8393;
v_8394:
    goto v_8390;
v_8391:
    goto v_8392;
v_8393:
    if (v_8448 == v_8447) goto v_8389;
    v_8447 = lisp_true;
    goto v_8387;
v_8389:
    goto v_8408;
v_8404:
    v_8447 = stack[-5];
    v_8447 = qcdr(v_8447);
    v_8447 = qcdr(v_8447);
    v_8448 = qcdr(v_8447);
    goto v_8405;
v_8406:
    v_8447 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_8407;
v_8408:
    goto v_8404;
v_8405:
    goto v_8406;
v_8407:
    v_8447 = Lneq(nil, v_8448, v_8447);
    env = stack[-7];
    goto v_8387;
    v_8447 = nil;
v_8387:
    goto v_8376;
v_8378:
    v_8447 = nil;
    goto v_8376;
    v_8447 = nil;
v_8376:
    if (v_8447 == nil) goto v_8374;
    v_8447 = stack[-5];
    fn = elt(env, 15); // !*crn2cr
    v_8447 = (*qfn1(fn))(fn, v_8447);
    env = stack[-7];
    goto v_8343;
v_8374:
    v_8447 = stack[-5];
    goto v_8343;
    v_8447 = nil;
v_8343:
    {
        fn = elt(env, 16); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_8447);
    }
v_8333:
    goto v_8428;
v_8424:
    v_8448 = stack[-3];
    goto v_8425;
v_8426:
    v_8447 = elt(env, 13); // divide
    goto v_8427;
v_8428:
    goto v_8424;
v_8425:
    goto v_8426;
v_8427:
    if (v_8448 == v_8447) goto v_8422;
    else goto v_8423;
v_8422:
    goto v_8436;
v_8432:
    v_8447 = stack[-5];
    v_8447 = qcar(v_8447);
    fn = elt(env, 16); // int!-equiv!-chk
    stack[0] = (*qfn1(fn))(fn, v_8447);
    env = stack[-7];
    goto v_8433;
v_8434:
    v_8447 = stack[-5];
    v_8447 = qcdr(v_8447);
    fn = elt(env, 16); // int!-equiv!-chk
    v_8447 = (*qfn1(fn))(fn, v_8447);
    goto v_8435;
v_8436:
    goto v_8432;
v_8433:
    goto v_8434;
v_8435:
    {
        LispObject v_8457 = stack[0];
        return cons(v_8457, v_8447);
    }
v_8423:
    v_8447 = stack[-5];
    {
        fn = elt(env, 16); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_8447);
    }
    v_8447 = nil;
    return onevalue(v_8447);
}



// Code for general!-times!-mod!-p

static LispObject CC_generalKtimesKmodKp(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8169, v_8170, v_8171;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    v_8169 = stack[-1];
    if (v_8169 == nil) goto v_7960;
    else goto v_7961;
v_7960:
    v_8169 = lisp_true;
    goto v_7959;
v_7961:
    v_8169 = stack[0];
    v_8169 = (v_8169 == nil ? lisp_true : nil);
    goto v_7959;
    v_8169 = nil;
v_7959:
    if (v_8169 == nil) goto v_7957;
    v_8169 = nil;
    goto v_7955;
v_7957:
    v_8169 = stack[-1];
    if (!consp(v_8169)) goto v_7973;
    else goto v_7974;
v_7973:
    v_8169 = lisp_true;
    goto v_7972;
v_7974:
    v_8169 = stack[-1];
    v_8169 = qcar(v_8169);
    v_8169 = (consp(v_8169) ? nil : lisp_true);
    goto v_7972;
    v_8169 = nil;
v_7972:
    if (v_8169 == nil) goto v_7970;
    goto v_7987;
v_7983:
    v_8170 = stack[0];
    goto v_7984;
v_7985:
    v_8169 = stack[-1];
    goto v_7986;
v_7987:
    goto v_7983;
v_7984:
    goto v_7985;
v_7986:
    {
        fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
        return (*qfn2(fn))(fn, v_8170, v_8169);
    }
v_7970:
    v_8169 = stack[0];
    if (!consp(v_8169)) goto v_7994;
    else goto v_7995;
v_7994:
    v_8169 = lisp_true;
    goto v_7993;
v_7995:
    v_8169 = stack[0];
    v_8169 = qcar(v_8169);
    v_8169 = (consp(v_8169) ? nil : lisp_true);
    goto v_7993;
    v_8169 = nil;
v_7993:
    if (v_8169 == nil) goto v_7991;
    goto v_8008;
v_8004:
    v_8170 = stack[-1];
    goto v_8005;
v_8006:
    v_8169 = stack[0];
    goto v_8007;
v_8008:
    goto v_8004;
v_8005:
    goto v_8006;
v_8007:
    {
        fn = elt(env, 1); // gen!-mult!-by!-const!-mod!-p
        return (*qfn2(fn))(fn, v_8170, v_8169);
    }
v_7991:
    goto v_8017;
v_8013:
    v_8169 = stack[-1];
    v_8169 = qcar(v_8169);
    v_8169 = qcar(v_8169);
    v_8170 = qcar(v_8169);
    goto v_8014;
v_8015:
    v_8169 = stack[0];
    v_8169 = qcar(v_8169);
    v_8169 = qcar(v_8169);
    v_8169 = qcar(v_8169);
    goto v_8016;
v_8017:
    goto v_8013;
v_8014:
    goto v_8015;
v_8016:
    if (equal(v_8170, v_8169)) goto v_8011;
    else goto v_8012;
v_8011:
    goto v_8031;
v_8027:
    goto v_8037;
v_8033:
    goto v_8043;
v_8039:
    v_8169 = stack[-1];
    v_8170 = qcar(v_8169);
    goto v_8040;
v_8041:
    v_8169 = stack[0];
    goto v_8042;
v_8043:
    goto v_8039;
v_8040:
    goto v_8041;
v_8042:
    fn = elt(env, 2); // general!-times!-term!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, v_8170, v_8169);
    env = stack[-3];
    goto v_8034;
v_8035:
    goto v_8052;
v_8048:
    v_8169 = stack[0];
    v_8170 = qcar(v_8169);
    goto v_8049;
v_8050:
    v_8169 = stack[-1];
    v_8169 = qcdr(v_8169);
    goto v_8051;
v_8052:
    goto v_8048;
v_8049:
    goto v_8050;
v_8051:
    fn = elt(env, 2); // general!-times!-term!-mod!-p
    v_8169 = (*qfn2(fn))(fn, v_8170, v_8169);
    env = stack[-3];
    goto v_8036;
v_8037:
    goto v_8033;
v_8034:
    goto v_8035;
v_8036:
    fn = elt(env, 3); // general!-plus!-mod!-p
    stack[-2] = (*qfn2(fn))(fn, stack[-2], v_8169);
    env = stack[-3];
    goto v_8028;
v_8029:
    goto v_8062;
v_8058:
    v_8169 = stack[-1];
    v_8170 = qcdr(v_8169);
    goto v_8059;
v_8060:
    v_8169 = stack[0];
    v_8169 = qcdr(v_8169);
    goto v_8061;
v_8062:
    goto v_8058;
v_8059:
    goto v_8060;
v_8061:
    v_8169 = CC_generalKtimesKmodKp(elt(env, 0), v_8170, v_8169);
    env = stack[-3];
    goto v_8030;
v_8031:
    goto v_8027;
v_8028:
    goto v_8029;
v_8030:
    {
        LispObject v_8175 = stack[-2];
        fn = elt(env, 3); // general!-plus!-mod!-p
        return (*qfn2(fn))(fn, v_8175, v_8169);
    }
v_8012:
    goto v_8074;
v_8070:
    v_8169 = stack[-1];
    v_8169 = qcar(v_8169);
    v_8169 = qcar(v_8169);
    v_8170 = qcar(v_8169);
    goto v_8071;
v_8072:
    v_8169 = stack[0];
    v_8169 = qcar(v_8169);
    v_8169 = qcar(v_8169);
    v_8169 = qcar(v_8169);
    goto v_8073;
v_8074:
    goto v_8070;
v_8071:
    goto v_8072;
v_8073:
    fn = elt(env, 4); // ordop
    v_8169 = (*qfn2(fn))(fn, v_8170, v_8169);
    env = stack[-3];
    if (v_8169 == nil) goto v_8068;
    goto v_8088;
v_8084:
    v_8169 = stack[-1];
    v_8169 = qcar(v_8169);
    v_8170 = qcdr(v_8169);
    goto v_8085;
v_8086:
    v_8169 = stack[0];
    goto v_8087;
v_8088:
    goto v_8084;
v_8085:
    goto v_8086;
v_8087:
    stack[-2] = CC_generalKtimesKmodKp(elt(env, 0), v_8170, v_8169);
    env = stack[-3];
    goto v_8098;
v_8094:
    v_8169 = stack[-1];
    v_8170 = qcdr(v_8169);
    goto v_8095;
v_8096:
    v_8169 = stack[0];
    goto v_8097;
v_8098:
    goto v_8094;
v_8095:
    goto v_8096;
v_8097:
    v_8169 = CC_generalKtimesKmodKp(elt(env, 0), v_8170, v_8169);
    v_8170 = stack[-2];
    v_8171 = v_8170;
    if (v_8171 == nil) goto v_8106;
    else goto v_8107;
v_8106:
    goto v_8105;
v_8107:
    goto v_8119;
v_8113:
    v_8171 = stack[-1];
    v_8171 = qcar(v_8171);
    v_8171 = qcar(v_8171);
    goto v_8114;
v_8115:
    goto v_8116;
v_8117:
    goto v_8118;
v_8119:
    goto v_8113;
v_8114:
    goto v_8115;
v_8116:
    goto v_8117;
v_8118:
    return acons(v_8171, v_8170, v_8169);
    v_8169 = nil;
v_8105:
    goto v_7955;
v_8068:
    goto v_8132;
v_8128:
    v_8170 = stack[-1];
    goto v_8129;
v_8130:
    v_8169 = stack[0];
    v_8169 = qcar(v_8169);
    v_8169 = qcdr(v_8169);
    goto v_8131;
v_8132:
    goto v_8128;
v_8129:
    goto v_8130;
v_8131:
    stack[-2] = CC_generalKtimesKmodKp(elt(env, 0), v_8170, v_8169);
    env = stack[-3];
    goto v_8142;
v_8138:
    v_8170 = stack[-1];
    goto v_8139;
v_8140:
    v_8169 = stack[0];
    v_8169 = qcdr(v_8169);
    goto v_8141;
v_8142:
    goto v_8138;
v_8139:
    goto v_8140;
v_8141:
    v_8169 = CC_generalKtimesKmodKp(elt(env, 0), v_8170, v_8169);
    v_8170 = stack[-2];
    v_8171 = v_8170;
    if (v_8171 == nil) goto v_8150;
    else goto v_8151;
v_8150:
    goto v_8149;
v_8151:
    goto v_8163;
v_8157:
    v_8171 = stack[0];
    v_8171 = qcar(v_8171);
    v_8171 = qcar(v_8171);
    goto v_8158;
v_8159:
    goto v_8160;
v_8161:
    goto v_8162;
v_8163:
    goto v_8157;
v_8158:
    goto v_8159;
v_8160:
    goto v_8161;
v_8162:
    return acons(v_8171, v_8170, v_8169);
    v_8169 = nil;
v_8149:
    goto v_7955;
    v_8169 = nil;
v_7955:
    return onevalue(v_8169);
}



// Code for setk

static LispObject CC_setk(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8047, v_8048, v_8049;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7952;
    v_8048 = v_7951;
// end of prologue
    v_8047 = v_8048;
    if (!consp(v_8047)) goto v_7957;
    goto v_7964;
v_7960:
    v_8047 = v_8048;
    v_8049 = qcar(v_8047);
    goto v_7961;
v_7962:
    v_8047 = elt(env, 1); // evalargfn
    goto v_7963;
v_7964:
    goto v_7960;
v_7961:
    goto v_7962;
v_7963:
    v_8047 = get(v_8049, v_8047);
    env = stack[-2];
    v_8049 = v_8047;
    v_8047 = v_8049;
    if (v_8047 == nil) goto v_7972;
    goto v_7979;
v_7975:
    goto v_7985;
v_7981:
    v_8047 = v_8048;
    stack[-1] = qcar(v_8047);
    goto v_7982;
v_7983:
    goto v_7993;
v_7989:
    v_8047 = v_8049;
    goto v_7990;
v_7991:
    v_8048 = qcdr(v_8048);
    goto v_7992;
v_7993:
    goto v_7989;
v_7990:
    goto v_7991;
v_7992:
    v_8047 = Lapply1(nil, v_8047, v_8048);
    env = stack[-2];
    goto v_7984;
v_7985:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    v_8048 = cons(stack[-1], v_8047);
    env = stack[-2];
    goto v_7976;
v_7977:
    v_8047 = stack[0];
    goto v_7978;
v_7979:
    goto v_7975;
v_7976:
    goto v_7977;
v_7978:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8048, v_8047);
    }
v_7972:
    goto v_8004;
v_8000:
    v_8047 = v_8048;
    v_8047 = qcar(v_8047);
    if (!symbolp(v_8047)) v_8049 = nil;
    else { v_8049 = qfastgets(v_8047);
           if (v_8049 != nil) { v_8049 = elt(v_8049, 2); // rtype
#ifdef RECORD_GET
             if (v_8049 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_8049 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_8049 == SPID_NOPROP) v_8049 = nil; }}
#endif
    goto v_8001;
v_8002:
    v_8047 = elt(env, 2); // matrix
    goto v_8003;
v_8004:
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    if (v_8049 == v_8047) goto v_7998;
    else goto v_7999;
v_7998:
    goto v_8014;
v_8010:
    goto v_8011;
v_8012:
    v_8047 = stack[0];
    goto v_8013;
v_8014:
    goto v_8010;
v_8011:
    goto v_8012;
v_8013:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8048, v_8047);
    }
v_7999:
    goto v_8024;
v_8020:
    goto v_8030;
v_8026:
    v_8047 = v_8048;
    stack[-1] = qcar(v_8047);
    goto v_8027;
v_8028:
    v_8047 = v_8048;
    v_8047 = qcdr(v_8047);
    fn = elt(env, 4); // revlis
    v_8047 = (*qfn1(fn))(fn, v_8047);
    env = stack[-2];
    goto v_8029;
v_8030:
    goto v_8026;
v_8027:
    goto v_8028;
v_8029:
    v_8048 = cons(stack[-1], v_8047);
    env = stack[-2];
    goto v_8021;
v_8022:
    v_8047 = stack[0];
    goto v_8023;
v_8024:
    goto v_8020;
v_8021:
    goto v_8022;
v_8023:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8048, v_8047);
    }
    v_8047 = nil;
    goto v_7955;
v_7957:
    goto v_8044;
v_8040:
    goto v_8041;
v_8042:
    v_8047 = stack[0];
    goto v_8043;
v_8044:
    goto v_8040;
v_8041:
    goto v_8042;
v_8043:
    {
        fn = elt(env, 3); // setk0
        return (*qfn2(fn))(fn, v_8048, v_8047);
    }
    v_8047 = nil;
v_7955:
    return onevalue(v_8047);
}



// Code for lalr_resolve_conflicts

static LispObject CC_lalr_resolve_conflicts(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8230, v_8231, v_8232;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(11);
// copy arguments values to proper place
    stack[-7] = v_7952;
    stack[-8] = v_7951;
// end of prologue
    stack[-9] = nil;
    stack[-2] = nil;
    goto v_7971;
v_7967:
    v_8231 = stack[-8];
    goto v_7968;
v_7969:
    v_8230 = elt(env, 1); // orderactions
    goto v_7970;
v_7971:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    fn = elt(env, 5); // sort
    v_8230 = (*qfn2(fn))(fn, v_8231, v_8230);
    env = stack[-10];
    stack[-8] = v_8230;
v_7976:
    v_8230 = stack[-8];
    if (v_8230 == nil) goto v_7979;
    else goto v_7980;
v_7979:
    goto v_7975;
v_7980:
    v_8230 = stack[-8];
    v_8230 = qcar(v_8230);
    v_8230 = ncons(v_8230);
    env = stack[-10];
    v_8232 = v_8230;
    v_8230 = stack[-8];
    v_8230 = qcdr(v_8230);
    stack[-8] = v_8230;
v_7990:
    v_8230 = stack[-8];
    if (v_8230 == nil) goto v_7993;
    goto v_8002;
v_7998:
    v_8230 = stack[-8];
    v_8230 = qcar(v_8230);
    v_8231 = qcar(v_8230);
    goto v_7999;
v_8000:
    v_8230 = v_8232;
    v_8230 = qcar(v_8230);
    v_8230 = qcar(v_8230);
    goto v_8001;
v_8002:
    goto v_7998;
v_7999:
    goto v_8000;
v_8001:
    if (equal(v_8231, v_8230)) goto v_7997;
    else goto v_7993;
v_7997:
    goto v_7994;
v_7993:
    goto v_7989;
v_7994:
    goto v_8015;
v_8011:
    v_8230 = stack[-8];
    v_8230 = qcar(v_8230);
    goto v_8012;
v_8013:
    v_8231 = v_8232;
    goto v_8014;
v_8015:
    goto v_8011;
v_8012:
    goto v_8013;
v_8014:
    v_8230 = cons(v_8230, v_8231);
    env = stack[-10];
    v_8232 = v_8230;
    v_8230 = stack[-8];
    v_8230 = qcdr(v_8230);
    stack[-8] = v_8230;
    goto v_7990;
v_7989:
    v_8230 = nil;
    stack[-4] = v_8230;
    stack[-5] = v_8230;
    stack[-6] = v_8230;
    v_8230 = v_8232;
    v_8230 = qcdr(v_8230);
    if (v_8230 == nil) goto v_8024;
    else goto v_8025;
v_8024:
    v_8230 = v_8232;
    v_8230 = qcar(v_8230);
    stack[-4] = v_8230;
    goto v_8023;
v_8025:
    v_8230 = v_8232;
    stack[0] = v_8230;
v_8035:
    v_8230 = stack[0];
    if (v_8230 == nil) goto v_8039;
    else goto v_8040;
v_8039:
    goto v_8034;
v_8040:
    v_8230 = stack[0];
    v_8230 = qcar(v_8230);
    v_8231 = v_8230;
    goto v_8054;
v_8050:
    v_8230 = v_8231;
    v_8230 = qcdr(v_8230);
    v_8230 = qcar(v_8230);
    v_8232 = qcar(v_8230);
    goto v_8051;
v_8052:
    v_8230 = elt(env, 2); // shift
    goto v_8053;
v_8054:
    goto v_8050;
v_8051:
    goto v_8052;
v_8053:
    if (v_8232 == v_8230) goto v_8048;
    else goto v_8049;
v_8048:
    v_8230 = v_8231;
    stack[-6] = v_8230;
    goto v_8047;
v_8049:
    v_8230 = stack[-5];
    if (v_8230 == nil) goto v_8061;
    else goto v_8062;
v_8061:
    v_8230 = v_8231;
    stack[-5] = v_8230;
    goto v_8047;
v_8062:
    goto v_8074;
v_8068:
    v_8232 = stack[-5];
    goto v_8069;
v_8070:
    goto v_8071;
v_8072:
    v_8230 = stack[-7];
    goto v_8073;
v_8074:
    goto v_8068;
v_8069:
    goto v_8070;
v_8071:
    goto v_8072;
v_8073:
    fn = elt(env, 6); // lalr_warn_reduce_reduce_conflict
    v_8230 = (*qfnn(fn))(fn, 3, v_8232, v_8231, v_8230);
    env = stack[-10];
    goto v_8047;
v_8047:
    v_8230 = stack[-6];
    if (v_8230 == nil) goto v_8081;
    v_8230 = stack[-5];
    if (v_8230 == nil) goto v_8081;
    v_8230 = stack[-6];
    v_8230 = qcar(v_8230);
    stack[-3] = v_8230;
    v_8230 = stack[-5];
    v_8230 = qcdr(v_8230);
    v_8230 = qcar(v_8230);
    v_8230 = qcdr(v_8230);
    v_8230 = qcar(v_8230);
    v_8232 = v_8230;
v_8091:
    v_8230 = v_8232;
    if (v_8230 == nil) goto v_8099;
    else goto v_8100;
v_8099:
    goto v_8090;
v_8100:
    v_8230 = v_8232;
    v_8230 = qcar(v_8230);
    v_8231 = v_8230;
    v_8230 = v_8231;
    if (is_number(v_8230)) goto v_8108;
    else goto v_8109;
v_8108:
    v_8230 = v_8231;
    stack[-2] = v_8230;
    goto v_8107;
v_8109:
v_8107:
    v_8230 = v_8232;
    v_8230 = qcdr(v_8230);
    v_8232 = v_8230;
    goto v_8091;
v_8090:
    v_8230 = stack[-3];
    if (v_8230 == nil) goto v_8117;
    v_8230 = stack[-2];
    if (v_8230 == nil) goto v_8117;
    v_8230 = stack[-3];
    fn = elt(env, 7); // lalr_precedence
    v_8230 = (*qfn1(fn))(fn, v_8230);
    env = stack[-10];
    stack[-1] = v_8230;
    v_8230 = stack[-2];
    fn = elt(env, 7); // lalr_precedence
    v_8230 = (*qfn1(fn))(fn, v_8230);
    env = stack[-10];
    v_8232 = v_8230;
    v_8230 = stack[-1];
    if (v_8230 == nil) goto v_8129;
    v_8230 = v_8232;
    if (v_8230 == nil) goto v_8129;
    goto v_8142;
v_8138:
    v_8231 = stack[-1];
    goto v_8139;
v_8140:
    v_8230 = v_8232;
    goto v_8141;
v_8142:
    goto v_8138;
v_8139:
    goto v_8140;
v_8141:
    if (equal(v_8231, v_8230)) goto v_8136;
    else goto v_8137;
v_8136:
    v_8230 = stack[-3];
    fn = elt(env, 8); // lalr_associativity
    v_8230 = (*qfn1(fn))(fn, v_8230);
    env = stack[-10];
    v_8232 = v_8230;
    goto v_8155;
v_8151:
    v_8231 = v_8232;
    goto v_8152;
v_8153:
    v_8230 = elt(env, 3); // !:left
    goto v_8154;
v_8155:
    goto v_8151;
v_8152:
    goto v_8153;
v_8154:
    if (v_8231 == v_8230) goto v_8149;
    else goto v_8150;
v_8149:
    v_8230 = nil;
    stack[-6] = v_8230;
    goto v_8148;
v_8150:
    goto v_8165;
v_8161:
    v_8231 = v_8232;
    goto v_8162;
v_8163:
    v_8230 = elt(env, 4); // !:right
    goto v_8164;
v_8165:
    goto v_8161;
v_8162:
    goto v_8163;
v_8164:
    if (v_8231 == v_8230) goto v_8159;
    else goto v_8160;
v_8159:
    v_8230 = nil;
    stack[-5] = v_8230;
    goto v_8148;
v_8160:
    v_8230 = nil;
    stack[-5] = v_8230;
    stack[-6] = v_8230;
    goto v_8148;
v_8148:
    goto v_8135;
v_8137:
    goto v_8179;
v_8175:
    v_8230 = stack[-1];
    goto v_8176;
v_8177:
    v_8231 = v_8232;
    goto v_8178;
v_8179:
    goto v_8175;
v_8176:
    goto v_8177;
v_8178:
    v_8230 = (LispObject)lessp2(v_8230, v_8231);
    v_8230 = v_8230 ? lisp_true : nil;
    env = stack[-10];
    if (v_8230 == nil) goto v_8173;
    v_8230 = nil;
    stack[-5] = v_8230;
    goto v_8135;
v_8173:
    v_8230 = nil;
    stack[-6] = v_8230;
    goto v_8135;
v_8135:
    goto v_8127;
v_8129:
v_8127:
    goto v_8115;
v_8117:
v_8115:
    goto v_8079;
v_8081:
v_8079:
    v_8230 = stack[0];
    v_8230 = qcdr(v_8230);
    stack[0] = v_8230;
    goto v_8035;
v_8034:
    goto v_8023;
v_8023:
    v_8230 = stack[-6];
    if (v_8230 == nil) goto v_8191;
    v_8230 = stack[-5];
    if (v_8230 == nil) goto v_8191;
    goto v_8203;
v_8197:
    v_8232 = stack[-6];
    goto v_8198;
v_8199:
    v_8231 = stack[-5];
    goto v_8200;
v_8201:
    v_8230 = stack[-7];
    goto v_8202;
v_8203:
    goto v_8197;
v_8198:
    goto v_8199;
v_8200:
    goto v_8201;
v_8202:
    fn = elt(env, 9); // lalr_warn_shift_reduce_conflict
    v_8230 = (*qfnn(fn))(fn, 3, v_8232, v_8231, v_8230);
    env = stack[-10];
    goto v_8189;
v_8191:
v_8189:
    v_8230 = stack[-4];
    if (v_8230 == nil) goto v_8209;
    else goto v_8208;
v_8209:
    v_8230 = stack[-6];
    if (v_8230 == nil) goto v_8213;
    else goto v_8212;
v_8213:
    v_8230 = stack[-5];
v_8212:
v_8208:
    stack[-4] = v_8230;
    v_8230 = stack[-4];
    if (v_8230 == nil) goto v_8219;
    goto v_8226;
v_8222:
    v_8231 = stack[-4];
    goto v_8223;
v_8224:
    v_8230 = stack[-9];
    goto v_8225;
v_8226:
    goto v_8222;
v_8223:
    goto v_8224;
v_8225:
    v_8230 = cons(v_8231, v_8230);
    env = stack[-10];
    stack[-9] = v_8230;
    goto v_8217;
v_8219:
v_8217:
    goto v_7976;
v_7975:
    v_8230 = stack[-9];
    return onevalue(v_8230);
}



// Code for cl_atml1

static LispObject CC_cl_atml1(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7961, v_7962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7961 = v_7951;
// end of prologue
    goto v_7958;
v_7954:
    v_7962 = v_7961;
    goto v_7955;
v_7956:
    v_7961 = elt(env, 1); // cl_atmlc
    goto v_7957;
v_7958:
    goto v_7954;
v_7955:
    goto v_7956;
v_7957:
    {
        fn = elt(env, 2); // cl_f2ml
        return (*qfn2(fn))(fn, v_7962, v_7961);
    }
}



// Code for simp!*sq

static LispObject CC_simpHsq(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7970, v_7971;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7971 = v_7951;
// end of prologue
    v_7970 = v_7971;
    v_7970 = qcdr(v_7970);
    v_7970 = qcar(v_7970);
    if (v_7970 == nil) goto v_7956;
    v_7970 = qvalue(elt(env, 1)); // !*resimp
    if (v_7970 == nil) goto v_7961;
    else goto v_7956;
v_7961:
    v_7970 = v_7971;
    v_7970 = qcar(v_7970);
    goto v_7954;
v_7956:
    v_7970 = v_7971;
    v_7970 = qcar(v_7970);
    {
        fn = elt(env, 2); // resimp1
        return (*qfn1(fn))(fn, v_7970);
    }
    v_7970 = nil;
v_7954:
    return onevalue(v_7970);
}



// Code for mri_realvarp

static LispObject CC_mri_realvarp(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7976, v_7977;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7977 = v_7951;
// end of prologue
    v_7976 = v_7977;
    if (symbolp(v_7976)) goto v_7956;
    v_7976 = nil;
    goto v_7954;
v_7956:
    goto v_7965;
v_7961:
    goto v_7971;
v_7967:
    goto v_7968;
v_7969:
    v_7976 = elt(env, 1); // mri_type
    goto v_7970;
v_7971:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    v_7976 = get(v_7977, v_7976);
    env = stack[0];
    goto v_7962;
v_7963:
    v_7977 = elt(env, 2); // real
    goto v_7964;
v_7965:
    goto v_7961;
v_7962:
    goto v_7963;
v_7964:
    v_7976 = (v_7976 == v_7977 ? lisp_true : nil);
    goto v_7954;
    v_7976 = nil;
v_7954:
    return onevalue(v_7976);
}



// Code for kernord!-split

static LispObject CC_kernordKsplit(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8066, v_8067, v_8068;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_7952;
    stack[-3] = v_7951;
// end of prologue
    stack[-4] = nil;
    stack[-1] = nil;
    v_8066 = stack[-3];
    fn = elt(env, 1); // powers
    v_8066 = (*qfn1(fn))(fn, v_8066);
    env = stack[-5];
    stack[-3] = v_8066;
    v_8066 = stack[-2];
    fn = elt(env, 1); // powers
    v_8066 = (*qfn1(fn))(fn, v_8066);
    env = stack[-5];
    stack[-2] = v_8066;
    v_8066 = stack[-3];
    stack[0] = v_8066;
v_7965:
    v_8066 = stack[0];
    if (v_8066 == nil) goto v_7969;
    else goto v_7970;
v_7969:
    goto v_7964;
v_7970:
    v_8066 = stack[0];
    v_8066 = qcar(v_8066);
    v_8068 = v_8066;
    goto v_7984;
v_7980:
    v_8066 = v_8068;
    v_8067 = qcar(v_8066);
    goto v_7981;
v_7982:
    v_8066 = stack[-2];
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    v_8066 = Lassoc(nil, v_8067, v_8066);
    if (v_8066 == nil) goto v_7979;
    goto v_7994;
v_7990:
    v_8067 = v_8068;
    goto v_7991;
v_7992:
    v_8066 = stack[-1];
    goto v_7993;
v_7994:
    goto v_7990;
v_7991:
    goto v_7992;
v_7993:
    v_8066 = cons(v_8067, v_8066);
    env = stack[-5];
    stack[-1] = v_8066;
    goto v_7977;
v_7979:
    goto v_8004;
v_8000:
    v_8067 = v_8068;
    goto v_8001;
v_8002:
    v_8066 = stack[-4];
    goto v_8003;
v_8004:
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    v_8066 = cons(v_8067, v_8066);
    env = stack[-5];
    stack[-4] = v_8066;
    goto v_7977;
v_7977:
    v_8066 = stack[0];
    v_8066 = qcdr(v_8066);
    stack[0] = v_8066;
    goto v_7965;
v_7964:
    v_8066 = stack[-2];
    stack[0] = v_8066;
v_8012:
    v_8066 = stack[0];
    if (v_8066 == nil) goto v_8016;
    else goto v_8017;
v_8016:
    goto v_8011;
v_8017:
    v_8066 = stack[0];
    v_8066 = qcar(v_8066);
    v_8068 = v_8066;
    goto v_8031;
v_8027:
    v_8066 = v_8068;
    v_8067 = qcar(v_8066);
    goto v_8028;
v_8029:
    v_8066 = stack[-3];
    goto v_8030;
v_8031:
    goto v_8027;
v_8028:
    goto v_8029;
v_8030:
    v_8066 = Lassoc(nil, v_8067, v_8066);
    if (v_8066 == nil) goto v_8026;
    goto v_8041;
v_8037:
    v_8067 = v_8068;
    goto v_8038;
v_8039:
    v_8066 = stack[-1];
    goto v_8040;
v_8041:
    goto v_8037;
v_8038:
    goto v_8039;
v_8040:
    v_8066 = cons(v_8067, v_8066);
    env = stack[-5];
    stack[-1] = v_8066;
    goto v_8024;
v_8026:
    goto v_8051;
v_8047:
    v_8067 = v_8068;
    goto v_8048;
v_8049:
    v_8066 = stack[-4];
    goto v_8050;
v_8051:
    goto v_8047;
v_8048:
    goto v_8049;
v_8050:
    v_8066 = cons(v_8067, v_8066);
    env = stack[-5];
    stack[-4] = v_8066;
    goto v_8024;
v_8024:
    v_8066 = stack[0];
    v_8066 = qcdr(v_8066);
    stack[0] = v_8066;
    goto v_8012;
v_8011:
    goto v_8061;
v_8057:
    v_8066 = stack[-4];
    v_8067 = Lnreverse(nil, v_8066);
    env = stack[-5];
    goto v_8058;
v_8059:
    v_8066 = stack[-1];
    v_8066 = Lnreverse(nil, v_8066);
    goto v_8060;
v_8061:
    goto v_8057;
v_8058:
    goto v_8059;
v_8060:
    return cons(v_8067, v_8066);
    return onevalue(v_8066);
}



// Code for aex_varl

static LispObject CC_aex_varl(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7957;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7957 = v_7951;
// end of prologue
    fn = elt(env, 1); // aex_ex
    v_7957 = (*qfn1(fn))(fn, v_7957);
    env = stack[0];
    v_7957 = qcar(v_7957);
    {
        fn = elt(env, 2); // kernels
        return (*qfn1(fn))(fn, v_7957);
    }
}



// Code for cgp_ci

static LispObject CC_cgp_ci(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7961, v_7962;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7961 = v_7951;
// end of prologue
    goto v_7958;
v_7954:
    v_7962 = v_7961;
    goto v_7955;
v_7956:
    v_7961 = (LispObject)96+TAG_FIXNUM; // 6
    goto v_7957;
v_7958:
    goto v_7954;
v_7955:
    goto v_7956;
v_7957:
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_7962, v_7961);
    }
}



// Code for image!-of!-power

static LispObject CC_imageKofKpower(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7995, v_7996, v_7997;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    goto v_7961;
v_7957:
    v_7996 = stack[-1];
    goto v_7958;
v_7959:
    v_7995 = qvalue(elt(env, 1)); // image!-set
    goto v_7960;
v_7961:
    goto v_7957;
v_7958:
    goto v_7959;
v_7960:
    v_7995 = Lassoc(nil, v_7996, v_7995);
    stack[-2] = v_7995;
    v_7995 = stack[-2];
    if (v_7995 == nil) goto v_7967;
    else goto v_7968;
v_7967:
    fn = elt(env, 2); // next!-random!-number
    v_7995 = (*qfnn(fn))(fn, 0);
    env = stack[-3];
    v_7995 = Lmodular_number(nil, v_7995);
    env = stack[-3];
    stack[-2] = v_7995;
    goto v_7979;
v_7973:
    v_7997 = stack[-1];
    goto v_7974;
v_7975:
    v_7996 = stack[-2];
    goto v_7976;
v_7977:
    v_7995 = qvalue(elt(env, 1)); // image!-set
    goto v_7978;
v_7979:
    goto v_7973;
v_7974:
    goto v_7975;
v_7976:
    goto v_7977;
v_7978:
    v_7995 = acons(v_7997, v_7996, v_7995);
    env = stack[-3];
    qvalue(elt(env, 1)) = v_7995; // image!-set
    goto v_7966;
v_7968:
    v_7995 = stack[-2];
    v_7995 = qcdr(v_7995);
    stack[-2] = v_7995;
    goto v_7966;
v_7966:
    goto v_7992;
v_7988:
    v_7996 = stack[-2];
    goto v_7989;
v_7990:
    v_7995 = stack[0];
    goto v_7991;
v_7992:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
        return Lmodular_expt(nil, v_7996, v_7995);
    return onevalue(v_7995);
}



// Code for gsugar

static LispObject CC_gsugar(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_8013, v_8014;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7951;
// end of prologue
    v_8013 = qvalue(elt(env, 1)); // !*gsugar
    if (v_8013 == nil) goto v_7956;
    v_8013 = stack[0];
    if (v_8013 == nil) goto v_7964;
    else goto v_7965;
v_7964:
    v_8013 = lisp_true;
    goto v_7963;
v_7965:
    v_8013 = stack[0];
    v_8013 = qcdr(v_8013);
    v_8013 = qcdr(v_8013);
    v_8013 = qcdr(v_8013);
    v_8013 = qcar(v_8013);
    v_8013 = (v_8013 == nil ? lisp_true : nil);
    goto v_7963;
    v_8013 = nil;
v_7963:
    if (v_8013 == nil) goto v_7961;
    v_8013 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7959;
v_7961:
    goto v_7984;
v_7980:
    v_8014 = stack[0];
    goto v_7981;
v_7982:
    v_8013 = elt(env, 2); // sugar
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    fn = elt(env, 4); // vdpgetprop
    v_8013 = (*qfn2(fn))(fn, v_8014, v_8013);
    env = stack[-2];
    goto v_7959;
    v_8013 = nil;
v_7959:
    stack[-1] = v_8013;
    v_8013 = stack[-1];
    if (v_8013 == nil) goto v_7990;
    else goto v_7989;
v_7990:
    goto v_7998;
v_7994:
    v_8014 = elt(env, 3); // "*** missing sugar"
    goto v_7995;
v_7996:
    v_8013 = stack[0];
    goto v_7997;
v_7998:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    v_8013 = list2(v_8014, v_8013);
    env = stack[-2];
    v_8013 = Lprint(nil, v_8013);
    env = stack[-2];
    fn = elt(env, 5); // backtrace
    v_8013 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_8013 = stack[0];
    fn = elt(env, 6); // vdptdeg
    v_8013 = (*qfn1(fn))(fn, v_8013);
    env = stack[-2];
    stack[-1] = v_8013;
    goto v_8009;
v_8005:
    v_8014 = stack[0];
    goto v_8006;
v_8007:
    v_8013 = stack[-1];
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    fn = elt(env, 7); // gsetsugar
    v_8013 = (*qfn2(fn))(fn, v_8014, v_8013);
    v_8013 = stack[-1];
v_7989:
    goto v_7954;
v_7956:
    v_8013 = nil;
v_7954:
    return onevalue(v_8013);
}



// Code for formprogn

static LispObject CC_formprogn(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7974, v_7975, v_7976;
    LispObject fn;
    LispObject v_7953, v_7952, v_7951;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "formprogn");
    va_start(aa, nargs);
    v_7951 = va_arg(aa, LispObject);
    v_7952 = va_arg(aa, LispObject);
    v_7953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7953,v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7951,v_7952,v_7953);
    }
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7974 = v_7953;
    v_7975 = v_7952;
    v_7976 = v_7951;
// end of prologue
    goto v_7960;
v_7956:
    stack[0] = elt(env, 1); // progn
    goto v_7957;
v_7958:
    goto v_7969;
v_7963:
    v_7976 = qcdr(v_7976);
    goto v_7964;
v_7965:
    goto v_7966;
v_7967:
    goto v_7968;
v_7969:
    goto v_7963;
v_7964:
    goto v_7965;
v_7966:
    goto v_7967;
v_7968:
    fn = elt(env, 2); // formclis
    v_7974 = (*qfnn(fn))(fn, 3, v_7976, v_7975, v_7974);
    goto v_7959;
v_7960:
    goto v_7956;
v_7957:
    goto v_7958;
v_7959:
    {
        LispObject v_7978 = stack[0];
        return cons(v_7978, v_7974);
    }
}



// Code for mv!-domainlist!-!*

static LispObject CC_mvKdomainlistKH(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7985, v_7986;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    stack[-2] = nil;
v_7957:
    v_7985 = stack[0];
    if (v_7985 == nil) goto v_7960;
    else goto v_7961;
v_7960:
    v_7985 = stack[-2];
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_7985);
    }
v_7961:
    goto v_7972;
v_7968:
    goto v_7978;
v_7974:
    v_7986 = stack[-1];
    goto v_7975;
v_7976:
    v_7985 = stack[0];
    v_7985 = qcar(v_7985);
    goto v_7977;
v_7978:
    goto v_7974;
v_7975:
    goto v_7976;
v_7977:
    v_7986 = times2(v_7986, v_7985);
    env = stack[-3];
    goto v_7969;
v_7970:
    v_7985 = stack[-2];
    goto v_7971;
v_7972:
    goto v_7968;
v_7969:
    goto v_7970;
v_7971:
    v_7985 = cons(v_7986, v_7985);
    env = stack[-3];
    stack[-2] = v_7985;
    v_7985 = stack[0];
    v_7985 = qcdr(v_7985);
    stack[0] = v_7985;
    goto v_7957;
    v_7985 = nil;
    return onevalue(v_7985);
}



// Code for pv_times2

static LispObject CC_pv_times2(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_7987, v_7988;
    LispObject fn;
    LispObject v_7953, v_7952, v_7951;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "pv_times2");
    va_start(aa, nargs);
    v_7951 = va_arg(aa, LispObject);
    v_7952 = va_arg(aa, LispObject);
    v_7953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7953,v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7951,v_7952,v_7953);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7953;
    v_7987 = v_7952;
    stack[-1] = v_7951;
// end of prologue
v_7958:
    v_7988 = v_7987;
    if (v_7988 == nil) goto v_7961;
    else goto v_7962;
v_7961:
    v_7987 = stack[0];
    goto v_7957;
v_7962:
    v_7988 = v_7987;
    v_7988 = qcdr(v_7988);
    stack[-2] = v_7988;
    goto v_7974;
v_7970:
    goto v_7981;
v_7977:
    v_7988 = stack[-1];
    goto v_7978;
v_7979:
    v_7987 = qcar(v_7987);
    goto v_7980;
v_7981:
    goto v_7977;
v_7978:
    goto v_7979;
v_7980:
    fn = elt(env, 1); // pv_times3
    v_7987 = (*qfn2(fn))(fn, v_7988, v_7987);
    env = stack[-3];
    v_7988 = ncons(v_7987);
    env = stack[-3];
    goto v_7971;
v_7972:
    v_7987 = stack[0];
    goto v_7973;
v_7974:
    goto v_7970;
v_7971:
    goto v_7972;
v_7973:
    fn = elt(env, 2); // pv_add
    v_7987 = (*qfn2(fn))(fn, v_7988, v_7987);
    env = stack[-3];
    stack[0] = v_7987;
    v_7987 = stack[-2];
    goto v_7958;
    v_7987 = nil;
v_7957:
    return onevalue(v_7987);
}



// Code for conv!:mt

static LispObject CC_convTmt(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8106, v_8107;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-2] = v_7951;
// end of prologue
    goto v_7971;
v_7967:
    v_8107 = stack[-2];
    goto v_7968;
v_7969:
    v_8106 = elt(env, 1); // !:rd!:
    goto v_7970;
v_7971:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    if (!consp(v_8107)) goto v_7965;
    v_8107 = qcar(v_8107);
    if (v_8107 == v_8106) goto v_7964;
    else goto v_7965;
v_7964:
    v_8106 = stack[-2];
    v_8106 = qcdr(v_8106);
    v_8106 = (consp(v_8106) ? nil : lisp_true);
    v_8106 = (v_8106 == nil ? lisp_true : nil);
    goto v_7963;
v_7965:
    v_8106 = nil;
    goto v_7963;
    v_8106 = nil;
v_7963:
    if (v_8106 == nil) goto v_7961;
    v_8106 = stack[0];
    v_8106 = integerp(v_8106);
    if (v_8106 == nil) goto v_7983;
    else goto v_7984;
v_7983:
    v_8106 = nil;
    goto v_7982;
v_7984:
    goto v_7995;
v_7991:
    v_8107 = stack[0];
    goto v_7992;
v_7993:
    v_8106 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7994;
v_7995:
    goto v_7991;
v_7992:
    goto v_7993;
v_7994:
    v_8106 = (LispObject)greaterp2(v_8107, v_8106);
    v_8106 = v_8106 ? lisp_true : nil;
    env = stack[-4];
    goto v_7982;
    v_8106 = nil;
v_7982:
    goto v_7959;
v_7961:
    v_8106 = nil;
    goto v_7959;
    v_8106 = nil;
v_7959:
    if (v_8106 == nil) goto v_7957;
    goto v_8009;
v_8005:
    goto v_8015;
v_8011:
    v_8106 = stack[-2];
    v_8106 = qcdr(v_8106);
    v_8106 = qcar(v_8106);
    v_8106 = Labsval(nil, v_8106);
    env = stack[-4];
    fn = elt(env, 2); // msd
    v_8107 = (*qfn1(fn))(fn, v_8106);
    env = stack[-4];
    goto v_8012;
v_8013:
    v_8106 = stack[0];
    goto v_8014;
v_8015:
    goto v_8011;
v_8012:
    goto v_8013;
v_8014:
    v_8107 = difference2(v_8107, v_8106);
    env = stack[-4];
    stack[0] = v_8107;
    goto v_8006;
v_8007:
    v_8106 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    if (v_8107 == v_8106) goto v_8003;
    else goto v_8004;
v_8003:
    v_8106 = stack[-2];
    goto v_8002;
v_8004:
    goto v_8031;
v_8027:
    v_8107 = stack[0];
    goto v_8028;
v_8029:
    v_8106 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8030;
v_8031:
    goto v_8027;
v_8028:
    goto v_8029;
v_8030:
    v_8106 = (LispObject)lessp2(v_8107, v_8106);
    v_8106 = v_8106 ? lisp_true : nil;
    env = stack[-4];
    if (v_8106 == nil) goto v_8025;
    v_8106 = stack[0];
    v_8106 = negate(v_8106);
    env = stack[-4];
    stack[-3] = v_8106;
    goto v_8044;
v_8038:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_8039;
v_8040:
    goto v_8051;
v_8047:
    v_8106 = stack[-2];
    v_8106 = qcdr(v_8106);
    v_8107 = qcar(v_8106);
    goto v_8048;
v_8049:
    v_8106 = stack[-3];
    goto v_8050;
v_8051:
    goto v_8047;
v_8048:
    goto v_8049;
v_8050:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, v_8107, v_8106);
    env = stack[-4];
    goto v_8041;
v_8042:
    goto v_8061;
v_8057:
    v_8106 = stack[-2];
    v_8106 = qcdr(v_8106);
    v_8107 = qcdr(v_8106);
    goto v_8058;
v_8059:
    v_8106 = stack[-3];
    goto v_8060;
v_8061:
    goto v_8057;
v_8058:
    goto v_8059;
v_8060:
    v_8106 = difference2(v_8107, v_8106);
    goto v_8043;
v_8044:
    goto v_8038;
v_8039:
    goto v_8040;
v_8041:
    goto v_8042;
v_8043:
    {
        LispObject v_8112 = stack[-1];
        LispObject v_8113 = stack[0];
        return list2star(v_8112, v_8113, v_8106);
    }
v_8025:
    v_8106 = stack[0];
    v_8106 = sub1(v_8106);
    env = stack[-4];
    stack[-3] = v_8106;
    goto v_8079;
v_8073:
    stack[-1] = elt(env, 1); // !:rd!:
    goto v_8074;
v_8075:
    goto v_8086;
v_8082:
    v_8106 = stack[-2];
    v_8106 = qcdr(v_8106);
    stack[0] = qcar(v_8106);
    goto v_8083;
v_8084:
    v_8106 = stack[-3];
    v_8106 = negate(v_8106);
    env = stack[-4];
    goto v_8085;
v_8086:
    goto v_8082;
v_8083:
    goto v_8084;
v_8085:
    fn = elt(env, 3); // ashift
    stack[0] = (*qfn2(fn))(fn, stack[0], v_8106);
    env = stack[-4];
    goto v_8076;
v_8077:
    goto v_8097;
v_8093:
    v_8106 = stack[-2];
    v_8106 = qcdr(v_8106);
    v_8107 = qcdr(v_8106);
    goto v_8094;
v_8095:
    v_8106 = stack[-3];
    goto v_8096;
v_8097:
    goto v_8093;
v_8094:
    goto v_8095;
v_8096:
    v_8106 = plus2(v_8107, v_8106);
    env = stack[-4];
    goto v_8078;
v_8079:
    goto v_8073;
v_8074:
    goto v_8075;
v_8076:
    goto v_8077;
v_8078:
    v_8106 = list2star(stack[-1], stack[0], v_8106);
    env = stack[-4];
    {
        fn = elt(env, 4); // round!:last
        return (*qfn1(fn))(fn, v_8106);
    }
    v_8106 = nil;
v_8002:
    goto v_7955;
v_7957:
    v_8106 = elt(env, 0); // conv!:mt
    {
        fn = elt(env, 5); // bflerrmsg
        return (*qfn1(fn))(fn, v_8106);
    }
    v_8106 = nil;
v_7955:
    return onevalue(v_8106);
}



// Code for multd!*

static LispObject CC_multdH(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8003, v_8004;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    goto v_7963;
v_7959:
    v_8004 = stack[0];
    goto v_7960;
v_7961:
    v_8003 = elt(env, 1); // kernel
    goto v_7962;
v_7963:
    goto v_7959;
v_7960:
    goto v_7961;
v_7962:
    fn = elt(env, 2); // xtype
    v_8003 = (*qfn2(fn))(fn, v_8004, v_8003);
    env = stack[-2];
    if (v_8003 == nil) goto v_7957;
    goto v_7971;
v_7967:
    v_8003 = stack[-1];
    fn = elt(env, 3); // value
    stack[-1] = (*qfn1(fn))(fn, v_8003);
    env = stack[-2];
    goto v_7968;
v_7969:
    goto v_7980;
v_7976:
    goto v_7986;
v_7982:
    v_8003 = stack[0];
    fn = elt(env, 3); // value
    v_8004 = (*qfn1(fn))(fn, v_8003);
    env = stack[-2];
    goto v_7983;
v_7984:
    v_8003 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7985;
v_7986:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    fn = elt(env, 4); // to
    v_8004 = (*qfn2(fn))(fn, v_8004, v_8003);
    env = stack[-2];
    goto v_7977;
v_7978:
    v_8003 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7979;
v_7980:
    goto v_7976;
v_7977:
    goto v_7978;
v_7979:
    v_8003 = cons(v_8004, v_8003);
    env = stack[-2];
    v_8003 = ncons(v_8003);
    env = stack[-2];
    goto v_7970;
v_7971:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    {
        LispObject v_8007 = stack[-1];
        fn = elt(env, 5); // multd
        return (*qfn2(fn))(fn, v_8007, v_8003);
    }
v_7957:
    goto v_7998;
v_7994:
    v_8003 = stack[-1];
    fn = elt(env, 3); // value
    stack[-1] = (*qfn1(fn))(fn, v_8003);
    env = stack[-2];
    goto v_7995;
v_7996:
    v_8003 = stack[0];
    fn = elt(env, 3); // value
    v_8003 = (*qfn1(fn))(fn, v_8003);
    env = stack[-2];
    goto v_7997;
v_7998:
    goto v_7994;
v_7995:
    goto v_7996;
v_7997:
    {
        LispObject v_8008 = stack[-1];
        fn = elt(env, 5); // multd
        return (*qfn2(fn))(fn, v_8008, v_8003);
    }
    v_8003 = nil;
    return onevalue(v_8003);
}



// Code for reduce!-degree!-mod!-p

static LispObject CC_reduceKdegreeKmodKp(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8049, v_8050, v_8051;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    goto v_7963;
v_7959:
    v_8049 = stack[-1];
    v_8049 = qcar(v_8049);
    v_8049 = qcdr(v_8049);
    {   intptr_t w = int_of_fixnum(v_8049);
        if (w != 0) w = current_modulus - w;
        v_8050 = fixnum_of_int(w);
    }
    goto v_7960;
v_7961:
    v_8049 = stack[0];
    v_8049 = qcar(v_8049);
    v_8049 = qcdr(v_8049);
    goto v_7962;
v_7963:
    goto v_7959;
v_7960:
    goto v_7961;
v_7962:
    v_8049 = Lmodular_quotient(nil, v_8050, v_8049);
    env = stack[-3];
    stack[-2] = v_8049;
    goto v_7975;
v_7971:
    v_8049 = stack[-1];
    v_8049 = qcar(v_8049);
    v_8049 = qcar(v_8049);
    v_8050 = qcdr(v_8049);
    goto v_7972;
v_7973:
    v_8049 = stack[0];
    v_8049 = qcar(v_8049);
    v_8049 = qcar(v_8049);
    v_8049 = qcdr(v_8049);
    goto v_7974;
v_7975:
    goto v_7971;
v_7972:
    goto v_7973;
v_7974:
    v_8049 = (LispObject)(intptr_t)((intptr_t)v_8050 - (intptr_t)v_8049 + TAG_FIXNUM);
    v_8051 = v_8049;
    goto v_7993;
v_7989:
    v_8050 = v_8051;
    goto v_7990;
v_7991:
    v_8049 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7992;
v_7993:
    goto v_7989;
v_7990:
    goto v_7991;
v_7992:
    if (v_8050 == v_8049) goto v_7987;
    else goto v_7988;
v_7987:
    goto v_8001;
v_7997:
    v_8049 = stack[-1];
    stack[-1] = qcdr(v_8049);
    goto v_7998;
v_7999:
    goto v_8009;
v_8005:
    v_8049 = stack[0];
    v_8050 = qcdr(v_8049);
    goto v_8006;
v_8007:
    v_8049 = stack[-2];
    goto v_8008;
v_8009:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    fn = elt(env, 1); // multiply!-by!-constant!-mod!-p
    v_8049 = (*qfn2(fn))(fn, v_8050, v_8049);
    env = stack[-3];
    goto v_8000;
v_8001:
    goto v_7997;
v_7998:
    goto v_7999;
v_8000:
    {
        LispObject v_8055 = stack[-1];
        fn = elt(env, 2); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_8055, v_8049);
    }
v_7988:
    goto v_8020;
v_8016:
    v_8049 = stack[-1];
    stack[-1] = qcdr(v_8049);
    goto v_8017;
v_8018:
    goto v_8028;
v_8024:
    goto v_8034;
v_8030:
    goto v_8040;
v_8036:
    v_8049 = stack[0];
    v_8049 = qcar(v_8049);
    v_8049 = qcar(v_8049);
    v_8049 = qcar(v_8049);
    goto v_8037;
v_8038:
    v_8050 = v_8051;
    goto v_8039;
v_8040:
    goto v_8036;
v_8037:
    goto v_8038;
v_8039:
    fn = elt(env, 3); // mksp
    v_8050 = (*qfn2(fn))(fn, v_8049, v_8050);
    env = stack[-3];
    goto v_8031;
v_8032:
    v_8049 = stack[-2];
    goto v_8033;
v_8034:
    goto v_8030;
v_8031:
    goto v_8032;
v_8033:
    v_8050 = cons(v_8050, v_8049);
    env = stack[-3];
    goto v_8025;
v_8026:
    v_8049 = stack[0];
    v_8049 = qcdr(v_8049);
    goto v_8027;
v_8028:
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    fn = elt(env, 4); // times!-term!-mod!-p
    v_8049 = (*qfn2(fn))(fn, v_8050, v_8049);
    env = stack[-3];
    goto v_8019;
v_8020:
    goto v_8016;
v_8017:
    goto v_8018;
v_8019:
    {
        LispObject v_8056 = stack[-1];
        fn = elt(env, 2); // plus!-mod!-p
        return (*qfn2(fn))(fn, v_8056, v_8049);
    }
    v_8049 = nil;
    return onevalue(v_8049);
}



// Code for lalr_make_compressed_action_row1

static LispObject CC_lalr_make_compressed_action_row1(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_8101, v_8102, v_8103, v_8104, v_8105;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7951;
// end of prologue
    stack[-2] = nil;
    v_8101 = stack[0];
    fn = elt(env, 4); // lalr_most_common_reduction
    v_8101 = (*qfn1(fn))(fn, v_8101);
    env = stack[-4];
    stack[-3] = v_8101;
    v_8101 = stack[0];
    stack[-1] = v_8101;
v_7964:
    v_8101 = stack[-1];
    if (v_8101 == nil) goto v_7968;
    else goto v_7969;
v_7968:
    goto v_7963;
v_7969:
    v_8101 = stack[-1];
    v_8101 = qcar(v_8101);
    v_8103 = v_8101;
    goto v_7983;
v_7979:
    v_8101 = v_8103;
    v_8101 = qcdr(v_8101);
    v_8102 = qcar(v_8101);
    goto v_7980;
v_7981:
    v_8101 = stack[-3];
    goto v_7982;
v_7983:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    if (equal(v_8102, v_8101)) goto v_7978;
    v_8101 = v_8103;
    v_8101 = qcar(v_8101);
    v_8105 = v_8101;
    v_8101 = v_8103;
    v_8101 = qcdr(v_8101);
    v_8101 = qcar(v_8101);
    v_8101 = qcar(v_8101);
    v_8104 = v_8101;
    goto v_8002;
v_7998:
    v_8102 = v_8104;
    goto v_7999;
v_8000:
    v_8101 = elt(env, 1); // shift
    goto v_8001;
v_8002:
    goto v_7998;
v_7999:
    goto v_8000;
v_8001:
    if (v_8102 == v_8101) goto v_7996;
    else goto v_7997;
v_7996:
    goto v_8012;
v_8006:
    v_8102 = v_8105;
    goto v_8007;
v_8008:
    v_8101 = v_8103;
    v_8101 = qcdr(v_8101);
    v_8101 = qcar(v_8101);
    v_8101 = qcdr(v_8101);
    v_8103 = qcar(v_8101);
    goto v_8009;
v_8010:
    v_8101 = stack[-2];
    goto v_8011;
v_8012:
    goto v_8006;
v_8007:
    goto v_8008;
v_8009:
    goto v_8010;
v_8011:
    v_8101 = acons(v_8102, v_8103, v_8101);
    env = stack[-4];
    stack[-2] = v_8101;
    goto v_7995;
v_7997:
    goto v_8026;
v_8022:
    v_8102 = v_8104;
    goto v_8023;
v_8024:
    v_8101 = elt(env, 2); // accept
    goto v_8025;
v_8026:
    goto v_8022;
v_8023:
    goto v_8024;
v_8025:
    if (v_8102 == v_8101) goto v_8020;
    else goto v_8021;
v_8020:
    goto v_8036;
v_8030:
    v_8103 = v_8105;
    goto v_8031;
v_8032:
    v_8102 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8033;
v_8034:
    v_8101 = stack[-2];
    goto v_8035;
v_8036:
    goto v_8030;
v_8031:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    v_8101 = acons(v_8103, v_8102, v_8101);
    env = stack[-4];
    stack[-2] = v_8101;
    goto v_7995;
v_8021:
    goto v_8046;
v_8042:
    v_8102 = v_8104;
    goto v_8043;
v_8044:
    v_8101 = elt(env, 3); // reduce
    goto v_8045;
v_8046:
    goto v_8042;
v_8043:
    goto v_8044;
v_8045:
    if (v_8102 == v_8101) goto v_8040;
    else goto v_8041;
v_8040:
    goto v_8056;
v_8050:
    stack[0] = v_8105;
    goto v_8051;
v_8052:
    v_8101 = v_8103;
    v_8101 = qcdr(v_8101);
    v_8101 = qcar(v_8101);
    v_8101 = qcdr(v_8101);
    v_8101 = qcdr(v_8101);
    v_8101 = qcar(v_8101);
    v_8102 = negate(v_8101);
    env = stack[-4];
    goto v_8053;
v_8054:
    v_8101 = stack[-2];
    goto v_8055;
v_8056:
    goto v_8050;
v_8051:
    goto v_8052;
v_8053:
    goto v_8054;
v_8055:
    v_8101 = acons(stack[0], v_8102, v_8101);
    env = stack[-4];
    stack[-2] = v_8101;
    goto v_7995;
v_8041:
v_7995:
    goto v_7976;
v_7978:
v_7976:
    v_8101 = stack[-1];
    v_8101 = qcdr(v_8101);
    stack[-1] = v_8101;
    goto v_7964;
v_7963:
    v_8101 = stack[-3];
    if (v_8101 == nil) goto v_8071;
    goto v_8081;
v_8077:
    v_8101 = stack[-3];
    v_8102 = qcar(v_8101);
    goto v_8078;
v_8079:
    v_8101 = elt(env, 2); // accept
    goto v_8080;
v_8081:
    goto v_8077;
v_8078:
    goto v_8079;
v_8080:
    if (v_8102 == v_8101) goto v_8075;
    else goto v_8076;
v_8075:
    v_8101 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_8074;
v_8076:
    v_8101 = stack[-3];
    v_8101 = qcdr(v_8101);
    v_8101 = qcdr(v_8101);
    v_8101 = qcar(v_8101);
    v_8101 = negate(v_8101);
    goto v_8074;
    v_8101 = nil;
v_8074:
    stack[-3] = v_8101;
    goto v_8069;
v_8071:
v_8069:
    goto v_8098;
v_8094:
    v_8102 = stack[-2];
    goto v_8095;
v_8096:
    v_8101 = stack[-3];
    goto v_8097;
v_8098:
    goto v_8094;
v_8095:
    goto v_8096;
v_8097:
    return cons(v_8102, v_8101);
    return onevalue(v_8101);
}



// Code for rl_prepfof

static LispObject CC_rl_prepfof(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7956;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7956 = v_7951;
// end of prologue
    fn = elt(env, 1); // rl_csimpl
    v_7956 = (*qfn1(fn))(fn, v_7956);
    env = stack[0];
    {
        fn = elt(env, 2); // rl_prepfof1
        return (*qfn1(fn))(fn, v_7956);
    }
}



// Code for updtemplate

static LispObject CC_updtemplate(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8075, v_8076, v_8077;
    LispObject fn;
    LispObject v_7953, v_7952, v_7951;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "updtemplate");
    va_start(aa, nargs);
    v_7951 = va_arg(aa, LispObject);
    v_7952 = va_arg(aa, LispObject);
    v_7953 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v_7953,v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v_7951,v_7952,v_7953);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-5] = v_7953;
    v_8075 = v_7952;
    stack[-6] = v_7951;
// end of prologue
    stack[-4] = v_8075;
    v_8075 = stack[-4];
    if (v_8075 == nil) goto v_7968;
    else goto v_7969;
v_7968:
    v_8075 = nil;
    goto v_7963;
v_7969:
    v_8075 = stack[-4];
    v_8075 = qcar(v_8075);
    stack[0] = v_8075;
    goto v_7984;
v_7980:
    goto v_7990;
v_7986:
    v_8076 = stack[-6];
    goto v_7987;
v_7988:
    v_8075 = stack[0];
    goto v_7989;
v_7990:
    goto v_7986;
v_7987:
    goto v_7988;
v_7989:
    v_8076 = Lsubla(nil, v_8076, v_8075);
    env = stack[-8];
    stack[-7] = v_8076;
    goto v_7981;
v_7982:
    v_8075 = stack[0];
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    if (equal(v_8076, v_8075)) goto v_7978;
    else goto v_7979;
v_7978:
    v_8075 = stack[0];
    goto v_7977;
v_7979:
    goto v_8001;
v_7997:
    goto v_8007;
v_8003:
    v_8076 = stack[-7];
    goto v_8004;
v_8005:
    v_8075 = stack[-5];
    goto v_8006;
v_8007:
    goto v_8003;
v_8004:
    goto v_8005;
v_8006:
    fn = elt(env, 1); // reval!-without
    v_8076 = (*qfn2(fn))(fn, v_8076, v_8075);
    env = stack[-8];
    v_8077 = v_8076;
    goto v_7998;
v_7999:
    v_8075 = stack[-7];
    goto v_8000;
v_8001:
    goto v_7997;
v_7998:
    goto v_7999;
v_8000:
    if (equal(v_8076, v_8075)) goto v_7996;
    v_8075 = v_8077;
    goto v_7977;
v_7996:
    v_8075 = stack[-7];
    goto v_7977;
    v_8075 = nil;
v_7977:
    v_8075 = ncons(v_8075);
    env = stack[-8];
    stack[-2] = v_8075;
    stack[-3] = v_8075;
v_7964:
    v_8075 = stack[-4];
    v_8075 = qcdr(v_8075);
    stack[-4] = v_8075;
    v_8075 = stack[-4];
    if (v_8075 == nil) goto v_8019;
    else goto v_8020;
v_8019:
    v_8075 = stack[-3];
    goto v_7963;
v_8020:
    goto v_8028;
v_8024:
    stack[-1] = stack[-2];
    goto v_8025;
v_8026:
    v_8075 = stack[-4];
    v_8075 = qcar(v_8075);
    stack[0] = v_8075;
    goto v_8042;
v_8038:
    goto v_8048;
v_8044:
    v_8076 = stack[-6];
    goto v_8045;
v_8046:
    v_8075 = stack[0];
    goto v_8047;
v_8048:
    goto v_8044;
v_8045:
    goto v_8046;
v_8047:
    v_8076 = Lsubla(nil, v_8076, v_8075);
    env = stack[-8];
    stack[-7] = v_8076;
    goto v_8039;
v_8040:
    v_8075 = stack[0];
    goto v_8041;
v_8042:
    goto v_8038;
v_8039:
    goto v_8040;
v_8041:
    if (equal(v_8076, v_8075)) goto v_8036;
    else goto v_8037;
v_8036:
    v_8075 = stack[0];
    goto v_8035;
v_8037:
    goto v_8059;
v_8055:
    goto v_8065;
v_8061:
    v_8076 = stack[-7];
    goto v_8062;
v_8063:
    v_8075 = stack[-5];
    goto v_8064;
v_8065:
    goto v_8061;
v_8062:
    goto v_8063;
v_8064:
    fn = elt(env, 1); // reval!-without
    v_8076 = (*qfn2(fn))(fn, v_8076, v_8075);
    env = stack[-8];
    v_8077 = v_8076;
    goto v_8056;
v_8057:
    v_8075 = stack[-7];
    goto v_8058;
v_8059:
    goto v_8055;
v_8056:
    goto v_8057;
v_8058:
    if (equal(v_8076, v_8075)) goto v_8054;
    v_8075 = v_8077;
    goto v_8035;
v_8054:
    v_8075 = stack[-7];
    goto v_8035;
    v_8075 = nil;
v_8035:
    v_8075 = ncons(v_8075);
    env = stack[-8];
    goto v_8027;
v_8028:
    goto v_8024;
v_8025:
    goto v_8026;
v_8027:
    v_8075 = Lrplacd(nil, stack[-1], v_8075);
    env = stack[-8];
    v_8075 = stack[-2];
    v_8075 = qcdr(v_8075);
    stack[-2] = v_8075;
    goto v_7964;
v_7963:
    return onevalue(v_8075);
}



// Code for talp_subalchk

static LispObject CC_talp_subalchk(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7954;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7954 = v_7951;
// end of prologue
    v_7954 = nil;
    return onevalue(v_7954);
}



// Code for ibalp_clausep

static LispObject CC_ibalp_clausep(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7984, v_7985;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7951;
// end of prologue
    v_7984 = stack[0];
    fn = elt(env, 2); // ibalp_litp
    v_7984 = (*qfn1(fn))(fn, v_7984);
    env = stack[-1];
    if (v_7984 == nil) goto v_7955;
    else goto v_7954;
v_7955:
    goto v_7966;
v_7962:
    v_7984 = stack[0];
    if (!consp(v_7984)) goto v_7969;
    else goto v_7970;
v_7969:
    v_7984 = stack[0];
    v_7985 = v_7984;
    goto v_7968;
v_7970:
    v_7984 = stack[0];
    v_7984 = qcar(v_7984);
    v_7985 = v_7984;
    goto v_7968;
    v_7985 = nil;
v_7968:
    goto v_7963;
v_7964:
    v_7984 = elt(env, 1); // or
    goto v_7965;
v_7966:
    goto v_7962;
v_7963:
    goto v_7964;
v_7965:
    if (v_7985 == v_7984) goto v_7960;
    else goto v_7961;
v_7960:
    v_7984 = stack[0];
    v_7984 = qcdr(v_7984);
    {
        fn = elt(env, 3); // ibalp_litlp
        return (*qfn1(fn))(fn, v_7984);
    }
v_7961:
    v_7984 = nil;
    goto v_7959;
    v_7984 = nil;
v_7959:
v_7954:
    return onevalue(v_7984);
}



// Code for cird

static LispObject CC_cird(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8007, v_8008, v_8009;
    LispObject fn;
    argcheck(nargs, 0, "cird");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    goto v_7967;
v_7963:
    v_8008 = qvalue(elt(env, 1)); // atts
    goto v_7964;
v_7965:
    v_8007 = elt(env, 2); // (type)
    goto v_7966;
v_7967:
    goto v_7963;
v_7964:
    goto v_7965;
v_7966:
    fn = elt(env, 5); // retattributes
    v_8007 = (*qfn2(fn))(fn, v_8008, v_8007);
    env = stack[-2];
    stack[0] = v_8007;
    fn = elt(env, 6); // lex
    v_8007 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_8007 = qvalue(elt(env, 3)); // char
    stack[-1] = v_8007;
    fn = elt(env, 6); // lex
    v_8007 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    v_8007 = stack[-1];
    v_8007 = Lcompress(nil, v_8007);
    env = stack[-2];
    v_8008 = v_8007;
    v_8007 = v_8008;
    if (is_number(v_8007)) goto v_7977;
    else goto v_7978;
v_7977:
    goto v_7985;
v_7981:
    goto v_7982;
v_7983:
    v_8007 = (LispObject)64+TAG_FIXNUM; // 4
    goto v_7984;
v_7985:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    fn = elt(env, 7); // errorml
    v_8007 = (*qfn2(fn))(fn, v_8008, v_8007);
    env = stack[-2];
    goto v_7976;
v_7978:
v_7976:
    v_8007 = stack[-1];
    fn = elt(env, 8); // compress!*
    v_8007 = (*qfn1(fn))(fn, v_8007);
    env = stack[-2];
    v_8008 = v_8007;
    v_8007 = stack[0];
    if (v_8007 == nil) goto v_7992;
    else goto v_7993;
v_7992:
    v_8007 = v_8008;
    goto v_7958;
v_7993:
    goto v_8003;
v_7997:
    v_8009 = elt(env, 4); // ci
    goto v_7998;
v_7999:
    v_8007 = stack[0];
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    goto v_7997;
v_7998:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    return list3(v_8009, v_8007, v_8008);
v_7958:
    return onevalue(v_8007);
}



// Code for getcomb

static LispObject CC_getcomb(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7992, v_7993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_7992 = v_7952;
    stack[0] = v_7951;
// end of prologue
    goto v_7962;
v_7958:
    v_7993 = v_7992;
    goto v_7959;
v_7960:
    v_7992 = qvalue(elt(env, 1)); // i
    goto v_7961;
v_7962:
    goto v_7958;
v_7959:
    goto v_7960;
v_7961:
    fn = elt(env, 3); // nextcomb
    v_7992 = (*qfn2(fn))(fn, v_7993, v_7992);
    env = stack[-2];
    qvalue(elt(env, 2)) = v_7992; // comb
    v_7992 = qvalue(elt(env, 2)); // comb
    v_7992 = qcar(v_7992);
    v_7993 = qvalue(elt(env, 2)); // comb
    v_7993 = qcdr(v_7993);
    qvalue(elt(env, 2)) = v_7993; // comb
    v_7993 = v_7992;
    if (v_7993 == nil) goto v_7972;
    goto v_7979;
v_7975:
    stack[-1] = v_7992;
    goto v_7976;
v_7977:
    goto v_7986;
v_7982:
    v_7993 = stack[0];
    goto v_7983;
v_7984:
    goto v_7985;
v_7986:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    fn = elt(env, 4); // setdiff
    v_7992 = (*qfn2(fn))(fn, v_7993, v_7992);
    goto v_7978;
v_7979:
    goto v_7975;
v_7976:
    goto v_7977;
v_7978:
    {
        LispObject v_7996 = stack[-1];
        return cons(v_7996, v_7992);
    }
v_7972:
    v_7992 = nil;
    goto v_7970;
    v_7992 = nil;
v_7970:
    return onevalue(v_7992);
}



// Code for setdmode1

static LispObject CC_setdmode1(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8130, v_8131, v_8132, v_8133;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_8131 = v_7952;
    stack[-5] = v_7951;
// end of prologue
    goto v_7964;
v_7960:
    v_8132 = stack[-5];
    goto v_7961;
v_7962:
    v_8130 = elt(env, 1); // tag
    goto v_7963;
v_7964:
    goto v_7960;
v_7961:
    goto v_7962;
v_7963:
    v_8130 = get(v_8132, v_8130);
    env = stack[-7];
    stack[-6] = v_8130;
    v_8130 = qvalue(elt(env, 2)); // dmode!*
    stack[-4] = v_8130;
    v_8130 = v_8131;
    if (v_8130 == nil) goto v_7970;
    else goto v_7971;
v_7970:
    v_8130 = stack[-4];
    if (v_8130 == nil) goto v_7975;
    else goto v_7976;
v_7975:
    v_8130 = nil;
    goto v_7974;
v_7976:
    goto v_7985;
v_7981:
    v_8131 = stack[-5];
    goto v_7982;
v_7983:
    v_8130 = stack[-4];
    if (!symbolp(v_8130)) v_8130 = nil;
    else { v_8130 = qfastgets(v_8130);
           if (v_8130 != nil) { v_8130 = elt(v_8130, 8); // dname
#ifdef RECORD_GET
             if (v_8130 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_8130 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_8130 == SPID_NOPROP) v_8130 = nil; }}
#endif
    stack[-4] = v_8130;
    goto v_7984;
v_7985:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    if (v_8131 == v_8130) goto v_7979;
    else goto v_7980;
v_7979:
    fn = elt(env, 11); // rmsubs
    v_8130 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_8130 = nil;
    qvalue(elt(env, 2)) = v_8130; // dmode!*
    qvalue(elt(env, 3)) = v_8130; // gdmode!*
    v_8130 = stack[-4];
    goto v_7974;
v_7980:
    goto v_7999;
v_7995:
    v_8131 = stack[-5];
    goto v_7996;
v_7997:
    v_8130 = stack[-4];
    goto v_7998;
v_7999:
    goto v_7995;
v_7996:
    goto v_7997;
v_7998:
    {
        fn = elt(env, 12); // offmoderr
        return (*qfn2(fn))(fn, v_8131, v_8130);
    }
    v_8130 = nil;
v_7974:
    goto v_7958;
v_7971:
    goto v_8012;
v_8008:
    v_8131 = stack[-5];
    goto v_8009;
v_8010:
    v_8130 = elt(env, 4); // (rounded complex!-rounded)
    goto v_8011;
v_8012:
    goto v_8008;
v_8009:
    goto v_8010;
v_8011:
    v_8130 = Lmemq(nil, v_8131, v_8130);
    if (v_8130 == nil) goto v_8007;
    fn = elt(env, 13); // !!mfefix
    v_8130 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    goto v_8005;
v_8007:
v_8005:
    goto v_8025;
v_8021:
    v_8131 = stack[-6];
    goto v_8022;
v_8023:
    v_8130 = stack[-4];
    goto v_8024;
v_8025:
    goto v_8021;
v_8022:
    goto v_8023;
v_8024:
    if (v_8131 == v_8130) goto v_8019;
    else goto v_8020;
v_8019:
    v_8130 = stack[-6];
    goto v_7958;
v_8020:
    goto v_7969;
v_7969:
    goto v_8038;
v_8034:
    v_8131 = stack[-6];
    goto v_8035;
v_8036:
    v_8130 = elt(env, 5); // realtype
    goto v_8037;
v_8038:
    goto v_8034;
v_8035:
    goto v_8036;
v_8037:
    v_8130 = get(v_8131, v_8130);
    env = stack[-7];
    stack[-3] = v_8130;
    if (v_8130 == nil) goto v_8031;
    else goto v_8032;
v_8031:
    v_8130 = stack[-6];
    stack[-3] = v_8130;
    goto v_8030;
v_8032:
v_8030:
    v_8130 = qvalue(elt(env, 6)); // domainlist!*
    stack[-2] = v_8130;
v_8045:
    v_8130 = stack[-2];
    if (v_8130 == nil) goto v_8049;
    else goto v_8050;
v_8049:
    goto v_8044;
v_8050:
    v_8130 = stack[-2];
    v_8130 = qcar(v_8130);
    stack[-1] = v_8130;
    goto v_8068;
v_8064:
    v_8131 = stack[-1];
    goto v_8065;
v_8066:
    v_8130 = elt(env, 7); // !:gi!:
    goto v_8067;
v_8068:
    goto v_8064;
v_8065:
    goto v_8066;
v_8067:
    if (v_8131 == v_8130) goto v_8063;
    goto v_8075;
v_8071:
    v_8131 = stack[-1];
    goto v_8072;
v_8073:
    v_8130 = stack[-3];
    goto v_8074;
v_8075:
    goto v_8071;
v_8072:
    goto v_8073;
v_8074:
    v_8130 = (v_8131 == v_8130 ? lisp_true : nil);
    v_8130 = (v_8130 == nil ? lisp_true : nil);
    goto v_8061;
v_8063:
    v_8130 = nil;
    goto v_8061;
    v_8130 = nil;
v_8061:
    if (v_8130 == nil) goto v_8059;
    goto v_8088;
v_8084:
    goto v_8096;
v_8092:
    v_8130 = elt(env, 8); // !*
    stack[0] = Lexplode(nil, v_8130);
    env = stack[-7];
    goto v_8093;
v_8094:
    v_8130 = stack[-1];
    if (!symbolp(v_8130)) v_8130 = nil;
    else { v_8130 = qfastgets(v_8130);
           if (v_8130 != nil) { v_8130 = elt(v_8130, 8); // dname
#ifdef RECORD_GET
             if (v_8130 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_8130 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_8130 == SPID_NOPROP) v_8130 = nil; }}
#endif
    v_8130 = Lexplode(nil, v_8130);
    env = stack[-7];
    goto v_8095;
v_8096:
    goto v_8092;
v_8093:
    goto v_8094;
v_8095:
    v_8130 = Lappend(nil, stack[0], v_8130);
    env = stack[-7];
    v_8130 = Lcompress(nil, v_8130);
    env = stack[-7];
    v_8131 = Lintern(nil, v_8130);
    env = stack[-7];
    goto v_8085;
v_8086:
    v_8130 = nil;
    goto v_8087;
v_8088:
    goto v_8084;
v_8085:
    goto v_8086;
v_8087:
    v_8130 = Lset(nil, v_8131, v_8130);
    env = stack[-7];
    goto v_8057;
v_8059:
v_8057:
    v_8130 = stack[-2];
    v_8130 = qcdr(v_8130);
    stack[-2] = v_8130;
    goto v_8045;
v_8044:
    fn = elt(env, 11); // rmsubs
    v_8130 = (*qfnn(fn))(fn, 0);
    env = stack[-7];
    v_8130 = stack[-4];
    if (!symbolp(v_8130)) v_8130 = nil;
    else { v_8130 = qfastgets(v_8130);
           if (v_8130 != nil) { v_8130 = elt(v_8130, 8); // dname
#ifdef RECORD_GET
             if (v_8130 != SPID_NOPROP)
                record_get(elt(fastget_names, 8), 1);
             else record_get(elt(fastget_names, 8), 0),
                v_8130 = nil; }
           else record_get(elt(fastget_names, 8), 0); }
#else
             if (v_8130 == SPID_NOPROP) v_8130 = nil; }}
#endif
    stack[-4] = v_8130;
    v_8130 = stack[-4];
    if (v_8130 == nil) goto v_8111;
    goto v_8123;
v_8115:
    v_8133 = elt(env, 9); // "Domain mode"
    goto v_8116;
v_8117:
    v_8132 = stack[-4];
    goto v_8118;
v_8119:
    v_8131 = elt(env, 10); // "changed to"
    goto v_8120;
v_8121:
    v_8130 = stack[-5];
    goto v_8122;
v_8123:
    goto v_8115;
v_8116:
    goto v_8117;
v_8118:
    goto v_8119;
v_8120:
    goto v_8121;
v_8122:
    v_8130 = list4(v_8133, v_8132, v_8131, v_8130);
    env = stack[-7];
    fn = elt(env, 14); // lprim
    v_8130 = (*qfn1(fn))(fn, v_8130);
    env = stack[-7];
    goto v_8109;
v_8111:
v_8109:
    v_8130 = stack[-6];
    qvalue(elt(env, 2)) = v_8130; // dmode!*
    qvalue(elt(env, 3)) = v_8130; // gdmode!*
    v_8130 = stack[-4];
v_7958:
    return onevalue(v_8130);
}



// Code for wedgepf

static LispObject CC_wedgepf(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7964, v_7965;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7964 = v_7952;
    v_7965 = v_7951;
// end of prologue
    goto v_7960;
v_7956:
    stack[0] = v_7965;
    goto v_7957;
v_7958:
    fn = elt(env, 1); // !*pf2wedgepf
    v_7964 = (*qfn1(fn))(fn, v_7964);
    env = stack[-1];
    goto v_7959;
v_7960:
    goto v_7956;
v_7957:
    goto v_7958;
v_7959:
    fn = elt(env, 2); // wedgepf2
    v_7964 = (*qfn2(fn))(fn, stack[0], v_7964);
    env = stack[-1];
    {
        fn = elt(env, 3); // !*wedgepf2pf
        return (*qfn1(fn))(fn, v_7964);
    }
}



// Code for noncommuting

static LispObject CC_noncommuting(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8028, v_8029, v_8030, v_8031;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
// copy arguments values to proper place
    v_8029 = v_7952;
    v_8030 = v_7951;
// end of prologue
    v_8031 = nil;
    v_8028 = v_8030;
    if (!consp(v_8028)) goto v_7960;
    else goto v_7961;
v_7960:
    v_8028 = v_8030;
    goto v_7959;
v_7961:
    v_8028 = v_8030;
    v_8028 = qcar(v_8028);
    goto v_7959;
    v_8028 = nil;
v_7959:
    v_8030 = v_8028;
    v_8028 = v_8029;
    if (!consp(v_8028)) goto v_7970;
    else goto v_7971;
v_7970:
    v_8028 = v_8029;
    goto v_7969;
v_7971:
    v_8028 = v_8029;
    v_8028 = qcar(v_8028);
    goto v_7969;
    v_8028 = nil;
v_7969:
    v_8029 = v_8028;
    v_8028 = v_8030;
    if (!consp(v_8028)) goto v_7985;
    else goto v_7986;
v_7985:
    v_8028 = v_8030;
    if (!symbolp(v_8028)) v_8028 = nil;
    else { v_8028 = qfastgets(v_8028);
           if (v_8028 != nil) { v_8028 = elt(v_8028, 0); // noncom
#ifdef RECORD_GET
             if (v_8028 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8028 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8028 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8028 == SPID_NOPROP) v_8028 = nil; else v_8028 = lisp_true; }}
#endif
    goto v_7984;
v_7986:
    v_8028 = v_8030;
    v_8028 = qcar(v_8028);
    if (!symbolp(v_8028)) v_8028 = nil;
    else { v_8028 = qfastgets(v_8028);
           if (v_8028 != nil) { v_8028 = elt(v_8028, 0); // noncom
#ifdef RECORD_GET
             if (v_8028 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8028 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8028 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8028 == SPID_NOPROP) v_8028 = nil; else v_8028 = lisp_true; }}
#endif
    goto v_7984;
    v_8028 = nil;
v_7984:
    if (v_8028 == nil) goto v_7980;
    v_8028 = v_8029;
    if (!consp(v_8028)) goto v_7998;
    else goto v_7999;
v_7998:
    v_8028 = v_8029;
    if (!symbolp(v_8028)) v_8028 = nil;
    else { v_8028 = qfastgets(v_8028);
           if (v_8028 != nil) { v_8028 = elt(v_8028, 0); // noncom
#ifdef RECORD_GET
             if (v_8028 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8028 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8028 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8028 == SPID_NOPROP) v_8028 = nil; else v_8028 = lisp_true; }}
#endif
    goto v_7997;
v_7999:
    v_8028 = v_8029;
    v_8028 = qcar(v_8028);
    if (!symbolp(v_8028)) v_8028 = nil;
    else { v_8028 = qfastgets(v_8028);
           if (v_8028 != nil) { v_8028 = elt(v_8028, 0); // noncom
#ifdef RECORD_GET
             if (v_8028 == SPID_NOPROP)
                record_get(elt(fastget_names, 0), 0),
                v_8028 = nil;
             else record_get(elt(fastget_names, 0), 1),
                v_8028 = lisp_true; }
           else record_get(elt(fastget_names, 0), 0); }
#else
             if (v_8028 == SPID_NOPROP) v_8028 = nil; else v_8028 = lisp_true; }}
#endif
    goto v_7997;
    v_8028 = nil;
v_7997:
    if (v_8028 == nil) goto v_7980;
    goto v_7981;
v_7980:
    goto v_7979;
v_7981:
    goto v_8016;
v_8012:
    goto v_8013;
v_8014:
    v_8028 = elt(env, 1); // noncommutes
    goto v_8015;
v_8016:
    goto v_8012;
v_8013:
    goto v_8014;
v_8015:
    v_8028 = get(v_8030, v_8028);
    goto v_8023;
v_8019:
    goto v_8020;
v_8021:
    goto v_8022;
v_8023:
    goto v_8019;
v_8020:
    goto v_8021;
v_8022:
    v_8028 = Lmember(nil, v_8029, v_8028);
    v_8031 = v_8028;
    goto v_7979;
v_7979:
    v_8028 = v_8031;
    return onevalue(v_8028);
}



// Code for all_edge

static LispObject CC_all_edge(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7991, v_7992, v_7993;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    v_7993 = nil;
v_7957:
    v_7991 = stack[0];
    if (v_7991 == nil) goto v_7960;
    else goto v_7961;
v_7960:
    v_7991 = v_7993;
    {
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_7991);
    }
v_7961:
    goto v_7971;
v_7967:
    v_7992 = stack[-1];
    goto v_7968;
v_7969:
    v_7991 = stack[0];
    v_7991 = qcar(v_7991);
    v_7991 = qcar(v_7991);
    goto v_7970;
v_7971:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    if (v_7992 == v_7991) goto v_7965;
    else goto v_7966;
v_7965:
    goto v_7981;
v_7977:
    v_7991 = stack[0];
    v_7991 = qcar(v_7991);
    goto v_7978;
v_7979:
    v_7992 = v_7993;
    goto v_7980;
v_7981:
    goto v_7977;
v_7978:
    goto v_7979;
v_7980:
    v_7991 = cons(v_7991, v_7992);
    env = stack[-2];
    v_7993 = v_7991;
    v_7991 = stack[0];
    v_7991 = qcdr(v_7991);
    stack[0] = v_7991;
    goto v_7957;
v_7966:
    v_7991 = stack[0];
    v_7991 = qcdr(v_7991);
    stack[0] = v_7991;
    goto v_7957;
    v_7991 = nil;
    return onevalue(v_7991);
}



// Code for mv!-pow!-chk

static LispObject CC_mvKpowKchk(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7981, v_7982;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7981 = v_7952;
    stack[0] = v_7951;
// end of prologue
    v_7982 = v_7981;
    if (v_7982 == nil) goto v_7957;
    goto v_7967;
v_7963:
    v_7982 = stack[0];
    v_7982 = qcar(v_7982);
    v_7982 = qcar(v_7982);
    goto v_7964;
v_7965:
    v_7981 = qcar(v_7981);
    v_7981 = qcar(v_7981);
    goto v_7966;
v_7967:
    goto v_7963;
v_7964:
    goto v_7965;
v_7966:
    fn = elt(env, 1); // mv!-pow!-!-
    v_7981 = (*qfn2(fn))(fn, v_7982, v_7981);
    env = stack[-1];
    stack[0] = v_7981;
    if (v_7981 == nil) goto v_7957;
    v_7981 = stack[0];
    fn = elt(env, 2); // mv!-pow!-minusp
    v_7981 = (*qfn1(fn))(fn, v_7981);
    if (v_7981 == nil) goto v_7974;
    else goto v_7957;
v_7974:
    v_7981 = stack[0];
    goto v_7955;
v_7957:
    v_7981 = nil;
    goto v_7955;
    v_7981 = nil;
v_7955:
    return onevalue(v_7981);
}



// Code for !:divide

static LispObject CC_Tdivide(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8008, v_8009, v_8010;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8009 = v_7952;
    v_8010 = v_7951;
// end of prologue
    v_8008 = v_8010;
    if (v_8008 == nil) goto v_7956;
    else goto v_7957;
v_7956:
    v_8008 = nil;
    return ncons(v_8008);
v_7957:
    v_8008 = v_8009;
    if (v_8008 == nil) goto v_7961;
    else goto v_7962;
v_7961:
    goto v_7971;
v_7965:
    v_8010 = elt(env, 1); // poly
    goto v_7966;
v_7967:
    v_8009 = (LispObject)3232+TAG_FIXNUM; // 202
    goto v_7968;
v_7969:
    v_8008 = elt(env, 2); // "zero divisor"
    goto v_7970;
v_7971:
    goto v_7965;
v_7966:
    goto v_7967;
v_7968:
    goto v_7969;
v_7970:
    {
        fn = elt(env, 4); // rerror
        return (*qfnn(fn))(fn, 3, v_8010, v_8009, v_8008);
    }
v_7962:
    v_8008 = v_8010;
    if (!consp(v_8008)) goto v_7979;
    else goto v_7980;
v_7979:
    v_8008 = v_8009;
    v_8008 = (consp(v_8008) ? nil : lisp_true);
    goto v_7978;
v_7980:
    v_8008 = nil;
    goto v_7978;
    v_8008 = nil;
v_7978:
    if (v_8008 == nil) goto v_7976;
    goto v_7992;
v_7988:
    v_8008 = v_8010;
    goto v_7989;
v_7990:
    goto v_7991;
v_7992:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
    {
        fn = elt(env, 5); // dividef
        return (*qfn2(fn))(fn, v_8008, v_8009);
    }
v_7976:
    goto v_8004;
v_7998:
    goto v_7999;
v_8000:
    goto v_8001;
v_8002:
    v_8008 = elt(env, 3); // divide
    goto v_8003;
v_8004:
    goto v_7998;
v_7999:
    goto v_8000;
v_8001:
    goto v_8002;
v_8003:
    {
        fn = elt(env, 6); // dcombine
        return (*qfnn(fn))(fn, 3, v_8010, v_8009, v_8008);
    }
    v_8008 = nil;
    return onevalue(v_8008);
}



// Code for gperm0

static LispObject CC_gperm0(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7973, v_7974;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7974 = v_7951;
// end of prologue
    v_7973 = v_7974;
    if (v_7973 == nil) goto v_7955;
    else goto v_7956;
v_7955:
    v_7973 = nil;
    goto v_7954;
v_7956:
    goto v_7966;
v_7962:
    v_7973 = v_7974;
    stack[0] = qcdr(v_7973);
    goto v_7963;
v_7964:
    v_7973 = v_7974;
    v_7973 = qcar(v_7973);
    v_7973 = ncons(v_7973);
    env = stack[-1];
    v_7973 = ncons(v_7973);
    env = stack[-1];
    goto v_7965;
v_7966:
    goto v_7962;
v_7963:
    goto v_7964;
v_7965:
    {
        LispObject v_7976 = stack[0];
        fn = elt(env, 1); // gperm3
        return (*qfn2(fn))(fn, v_7976, v_7973);
    }
    v_7973 = nil;
v_7954:
    return onevalue(v_7973);
}



// Code for b!:extmult

static LispObject CC_bTextmult(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8110, v_8111, v_8112;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_7952;
    stack[-4] = v_7951;
// end of prologue
    stack[-5] = nil;
v_7960:
    v_8110 = stack[-4];
    if (v_8110 == nil) goto v_7968;
    else goto v_7969;
v_7968:
    v_8110 = lisp_true;
    goto v_7967;
v_7969:
    v_8110 = stack[-3];
    v_8110 = (v_8110 == nil ? lisp_true : nil);
    goto v_7967;
    v_8110 = nil;
v_7967:
    if (v_8110 == nil) goto v_7965;
    v_8110 = nil;
    stack[0] = v_8110;
    goto v_7961;
v_7965:
    goto v_7983;
v_7979:
    v_8111 = stack[-3];
    goto v_7980;
v_7981:
    v_8110 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7982;
v_7983:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    if (v_8111 == v_8110) goto v_7977;
    else goto v_7978;
v_7977:
    v_8110 = stack[-4];
    stack[0] = v_8110;
    goto v_7961;
v_7978:
    goto v_7994;
v_7988:
    v_8112 = stack[-4];
    goto v_7989;
v_7990:
    v_8111 = stack[-3];
    goto v_7991;
v_7992:
    v_8110 = stack[-5];
    goto v_7993;
v_7994:
    goto v_7988;
v_7989:
    goto v_7990;
v_7991:
    goto v_7992;
v_7993:
    v_8110 = acons(v_8112, v_8111, v_8110);
    env = stack[-6];
    stack[-5] = v_8110;
    v_8110 = stack[-4];
    v_8110 = qcdr(v_8110);
    if (v_8110 == nil) goto v_8001;
    v_8110 = stack[-4];
    v_8110 = qcar(v_8110);
    v_8110 = ncons(v_8110);
    env = stack[-6];
    stack[-4] = v_8110;
    goto v_7999;
v_8001:
v_7999:
    v_8110 = stack[-3];
    v_8110 = qcdr(v_8110);
    stack[-3] = v_8110;
    goto v_7960;
v_7961:
v_8011:
    v_8110 = stack[-5];
    if (v_8110 == nil) goto v_8014;
    else goto v_8015;
v_8014:
    goto v_8010;
v_8015:
    v_8110 = stack[-5];
    v_8110 = qcar(v_8110);
    v_8110 = qcar(v_8110);
    stack[-4] = v_8110;
    v_8110 = stack[-5];
    v_8110 = qcar(v_8110);
    v_8110 = qcdr(v_8110);
    stack[-3] = v_8110;
    v_8110 = stack[-5];
    v_8110 = qcdr(v_8110);
    stack[-5] = v_8110;
    goto v_8031;
v_8027:
    v_8110 = stack[-4];
    v_8110 = qcar(v_8110);
    v_8110 = qcar(v_8110);
    v_8111 = qcar(v_8110);
    goto v_8028;
v_8029:
    v_8110 = stack[-3];
    v_8110 = qcar(v_8110);
    v_8110 = qcar(v_8110);
    goto v_8030;
v_8031:
    goto v_8027;
v_8028:
    goto v_8029;
v_8030:
    fn = elt(env, 1); // b!:ordexn
    v_8110 = (*qfn2(fn))(fn, v_8111, v_8110);
    env = stack[-6];
    stack[-1] = v_8110;
    v_8110 = stack[-1];
    if (v_8110 == nil) goto v_8042;
    goto v_8049;
v_8045:
    v_8110 = stack[-4];
    v_8110 = qcar(v_8110);
    v_8111 = qcdr(v_8110);
    goto v_8046;
v_8047:
    v_8110 = stack[-3];
    v_8110 = qcar(v_8110);
    v_8110 = qcdr(v_8110);
    goto v_8048;
v_8049:
    goto v_8045;
v_8046:
    goto v_8047;
v_8048:
    fn = elt(env, 2); // multf
    v_8110 = (*qfn2(fn))(fn, v_8111, v_8110);
    env = stack[-6];
    v_8111 = v_8110;
    v_8110 = stack[-1];
    v_8110 = qcar(v_8110);
    if (v_8110 == nil) goto v_8059;
    v_8110 = v_8111;
    fn = elt(env, 3); // negf
    v_8110 = (*qfn1(fn))(fn, v_8110);
    env = stack[-6];
    v_8111 = v_8110;
    goto v_8057;
v_8059:
v_8057:
    goto v_8071;
v_8065:
    v_8110 = stack[-1];
    stack[-2] = qcdr(v_8110);
    goto v_8066;
v_8067:
    stack[-1] = v_8111;
    goto v_8068;
v_8069:
    goto v_8080;
v_8076:
    goto v_8077;
v_8078:
    goto v_8087;
v_8083:
    v_8110 = stack[-4];
    v_8111 = qcdr(v_8110);
    goto v_8084;
v_8085:
    v_8110 = stack[-3];
    goto v_8086;
v_8087:
    goto v_8083;
v_8084:
    goto v_8085;
v_8086:
    v_8110 = CC_bTextmult(elt(env, 0), v_8111, v_8110);
    env = stack[-6];
    goto v_8079;
v_8080:
    goto v_8076;
v_8077:
    goto v_8078;
v_8079:
    fn = elt(env, 4); // b!:extadd
    v_8110 = (*qfn2(fn))(fn, stack[0], v_8110);
    env = stack[-6];
    goto v_8070;
v_8071:
    goto v_8065;
v_8066:
    goto v_8067;
v_8068:
    goto v_8069;
v_8070:
    v_8110 = acons(stack[-2], stack[-1], v_8110);
    env = stack[-6];
    stack[0] = v_8110;
    goto v_8040;
v_8042:
    goto v_8098;
v_8094:
    goto v_8104;
v_8100:
    v_8110 = stack[-4];
    v_8111 = qcdr(v_8110);
    goto v_8101;
v_8102:
    v_8110 = stack[-3];
    goto v_8103;
v_8104:
    goto v_8100;
v_8101:
    goto v_8102;
v_8103:
    v_8111 = CC_bTextmult(elt(env, 0), v_8111, v_8110);
    env = stack[-6];
    goto v_8095;
v_8096:
    v_8110 = stack[0];
    goto v_8097;
v_8098:
    goto v_8094;
v_8095:
    goto v_8096;
v_8097:
    fn = elt(env, 4); // b!:extadd
    v_8110 = (*qfn2(fn))(fn, v_8111, v_8110);
    env = stack[-6];
    stack[0] = v_8110;
    goto v_8040;
v_8040:
    goto v_8011;
v_8010:
    v_8110 = stack[0];
    return onevalue(v_8110);
}



// Code for tr_write

static LispObject CC_tr_write(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7977, v_7978;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_7978 = v_7951;
// end of prologue
    v_7977 = qvalue(elt(env, 1)); // !*trsolve
    if (v_7977 == nil) goto v_7956;
    v_7977 = v_7978;
    stack[0] = v_7977;
v_7961:
    v_7977 = stack[0];
    if (v_7977 == nil) goto v_7965;
    else goto v_7966;
v_7965:
    goto v_7960;
v_7966:
    v_7977 = stack[0];
    v_7977 = qcar(v_7977);
    v_7977 = Lprinc(nil, v_7977);
    env = stack[-1];
    v_7977 = stack[0];
    v_7977 = qcdr(v_7977);
    stack[0] = v_7977;
    goto v_7961;
v_7960:
        return Lterpri(nil, 0);
v_7956:
    v_7977 = nil;
    return onevalue(v_7977);
}



// Code for rread1

static LispObject CC_rread1(LispObject env, int nargs, ...)
{
    env = qenv(env);
    LispObject v_8107, v_8108, v_8109;
    LispObject fn;
    argcheck(nargs, 0, "rread1");
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    fn = elt(env, 13); // ptoken
    v_8107 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[-1] = v_8107;
    goto v_7965;
v_7961:
    v_8108 = qvalue(elt(env, 1)); // ttype!*
    goto v_7962;
v_7963:
    v_8107 = (LispObject)48+TAG_FIXNUM; // 3
    goto v_7964;
v_7965:
    goto v_7961;
v_7962:
    goto v_7963;
v_7964:
    if (v_8108 == v_8107) goto v_7960;
    v_8107 = stack[-1];
    if (symbolp(v_8107)) goto v_7970;
    else goto v_7971;
v_7970:
    v_8107 = qvalue(elt(env, 2)); // !*quotenewnam
    if (v_8107 == nil) goto v_7976;
    goto v_7985;
v_7981:
    v_8108 = stack[-1];
    goto v_7982;
v_7983:
    v_8107 = elt(env, 3); // quotenewnam
    goto v_7984;
v_7985:
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    v_8107 = get(v_8108, v_8107);
    stack[0] = v_8107;
    if (v_8107 == nil) goto v_7976;
    v_8107 = stack[0];
    goto v_7974;
v_7976:
    v_8107 = stack[-1];
    goto v_7974;
    v_8107 = nil;
v_7974:
    goto v_7969;
v_7971:
    goto v_7999;
v_7995:
    v_8108 = stack[-1];
    goto v_7996;
v_7997:
    v_8107 = elt(env, 4); // !:dn!:
    goto v_7998;
v_7999:
    goto v_7995;
v_7996:
    goto v_7997;
v_7998:
    if (!consp(v_8108)) goto v_7993;
    v_8108 = qcar(v_8108);
    if (v_8108 == v_8107) goto v_7992;
    else goto v_7993;
v_7992:
    goto v_8009;
v_8003:
    v_8109 = stack[-1];
    goto v_8004;
v_8005:
    v_8108 = nil;
    goto v_8006;
v_8007:
    v_8107 = elt(env, 5); // symbolic
    goto v_8008;
v_8009:
    goto v_8003;
v_8004:
    goto v_8005;
v_8006:
    goto v_8007;
v_8008:
    {
        fn = elt(env, 14); // dnform
        return (*qfnn(fn))(fn, 3, v_8109, v_8108, v_8107);
    }
v_7993:
    v_8107 = stack[-1];
    goto v_7969;
    v_8107 = nil;
v_7969:
    goto v_7955;
v_7960:
    goto v_8022;
v_8018:
    v_8108 = stack[-1];
    goto v_8019;
v_8020:
    v_8107 = elt(env, 6); // !(
    goto v_8021;
v_8022:
    goto v_8018;
v_8019:
    goto v_8020;
v_8021:
    if (v_8108 == v_8107) goto v_8016;
    else goto v_8017;
v_8016:
    {
        fn = elt(env, 15); // rrdls
        return (*qfnn(fn))(fn, 0);
    }
v_8017:
    goto v_8036;
v_8032:
    v_8108 = stack[-1];
    goto v_8033;
v_8034:
    v_8107 = elt(env, 7); // !+
    goto v_8035;
v_8036:
    goto v_8032;
v_8033:
    goto v_8034;
v_8035:
    if (v_8108 == v_8107) goto v_8030;
    else goto v_8031;
v_8030:
    v_8107 = lisp_true;
    goto v_8029;
v_8031:
    goto v_8046;
v_8042:
    v_8108 = stack[-1];
    goto v_8043;
v_8044:
    v_8107 = elt(env, 8); // !-
    goto v_8045;
v_8046:
    goto v_8042;
v_8043:
    goto v_8044;
v_8045:
    v_8107 = (v_8108 == v_8107 ? lisp_true : nil);
    goto v_8029;
    v_8107 = nil;
v_8029:
    if (v_8107 == nil) goto v_8026;
    else goto v_8027;
v_8026:
    v_8107 = stack[-1];
    goto v_7955;
v_8027:
    fn = elt(env, 13); // ptoken
    v_8107 = (*qfnn(fn))(fn, 0);
    env = stack[-2];
    stack[0] = v_8107;
    goto v_8061;
v_8057:
    v_8108 = stack[0];
    goto v_8058;
v_8059:
    v_8107 = elt(env, 4); // !:dn!:
    goto v_8060;
v_8061:
    goto v_8057;
v_8058:
    goto v_8059;
v_8060:
    if (!consp(v_8108)) goto v_8055;
    v_8108 = qcar(v_8108);
    if (v_8108 == v_8107) goto v_8054;
    else goto v_8055;
v_8054:
    goto v_8071;
v_8065:
    v_8109 = stack[0];
    goto v_8066;
v_8067:
    v_8108 = nil;
    goto v_8068;
v_8069:
    v_8107 = elt(env, 5); // symbolic
    goto v_8070;
v_8071:
    goto v_8065;
v_8066:
    goto v_8067;
v_8068:
    goto v_8069;
v_8070:
    fn = elt(env, 14); // dnform
    v_8107 = (*qfnn(fn))(fn, 3, v_8109, v_8108, v_8107);
    env = stack[-2];
    stack[0] = v_8107;
    goto v_8053;
v_8055:
v_8053:
    v_8107 = stack[0];
    if (is_number(v_8107)) goto v_8078;
    v_8107 = elt(env, 9); // " "
    qvalue(elt(env, 10)) = v_8107; // nxtsym!*
    goto v_8086;
v_8082:
    v_8108 = elt(env, 11); // "Syntax error: improper number"
    goto v_8083;
v_8084:
    v_8107 = nil;
    goto v_8085;
v_8086:
    goto v_8082;
v_8083:
    goto v_8084;
v_8085:
    fn = elt(env, 16); // symerr
    v_8107 = (*qfn2(fn))(fn, v_8108, v_8107);
    goto v_8076;
v_8078:
    goto v_8095;
v_8091:
    v_8108 = stack[-1];
    goto v_8092;
v_8093:
    v_8107 = elt(env, 8); // !-
    goto v_8094;
v_8095:
    goto v_8091;
v_8092:
    goto v_8093;
v_8094:
    if (v_8108 == v_8107) goto v_8089;
    else goto v_8090;
v_8089:
    goto v_8103;
v_8099:
    v_8108 = elt(env, 12); // minus
    goto v_8100;
v_8101:
    v_8107 = stack[0];
    goto v_8102;
v_8103:
    goto v_8099;
v_8100:
    goto v_8101;
v_8102:
    v_8107 = Lapply1(nil, v_8108, v_8107);
    stack[0] = v_8107;
    goto v_8076;
v_8090:
v_8076:
    v_8107 = stack[0];
v_7955:
    return onevalue(v_8107);
}



// Code for powers3

static LispObject CC_powers3(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8007, v_8008;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7952;
    v_8007 = v_7951;
// end of prologue
v_7957:
    v_8008 = v_8007;
    if (!consp(v_8008)) goto v_7964;
    else goto v_7965;
v_7964:
    v_8008 = lisp_true;
    goto v_7963;
v_7965:
    v_8008 = v_8007;
    v_8008 = qcar(v_8008);
    v_8008 = (consp(v_8008) ? nil : lisp_true);
    goto v_7963;
    v_8008 = nil;
v_7963:
    if (v_8008 == nil) goto v_7961;
    v_8007 = stack[-1];
    goto v_7956;
v_7961:
    v_8008 = v_8007;
    v_8008 = qcar(v_8008);
    v_8008 = qcdr(v_8008);
    stack[-2] = v_8008;
    goto v_7986;
v_7980:
    v_8008 = v_8007;
    v_8008 = qcar(v_8008);
    v_8008 = qcar(v_8008);
    stack[0] = qcar(v_8008);
    goto v_7981;
v_7982:
    goto v_7996;
v_7992:
    v_8008 = v_8007;
    v_8008 = qcar(v_8008);
    v_8008 = qcar(v_8008);
    v_8008 = qcdr(v_8008);
    goto v_7993;
v_7994:
    v_8007 = qcar(v_8007);
    v_8007 = qcar(v_8007);
    v_8007 = qcdr(v_8007);
    goto v_7995;
v_7996:
    goto v_7992;
v_7993:
    goto v_7994;
v_7995:
    v_8008 = cons(v_8008, v_8007);
    env = stack[-3];
    goto v_7983;
v_7984:
    v_8007 = stack[-1];
    goto v_7985;
v_7986:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    goto v_7984;
v_7985:
    v_8007 = acons(stack[0], v_8008, v_8007);
    env = stack[-3];
    stack[-1] = v_8007;
    v_8007 = stack[-2];
    goto v_7957;
    v_8007 = nil;
v_7956:
    return onevalue(v_8007);
}



// Code for rsubla

static LispObject CC_rsubla(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_8018, v_8019;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_7952;
    stack[-1] = v_7951;
// end of prologue
    v_8018 = stack[-1];
    if (v_8018 == nil) goto v_7963;
    else goto v_7964;
v_7963:
    v_8018 = lisp_true;
    goto v_7962;
v_7964:
    v_8018 = stack[0];
    v_8018 = (v_8018 == nil ? lisp_true : nil);
    goto v_7962;
    v_8018 = nil;
v_7962:
    if (v_8018 == nil) goto v_7960;
    v_8018 = stack[0];
    goto v_7956;
v_7960:
    v_8018 = stack[0];
    if (!consp(v_8018)) goto v_7972;
    else goto v_7973;
v_7972:
    goto v_7984;
v_7980:
    v_8019 = stack[0];
    goto v_7981;
v_7982:
    v_8018 = stack[-1];
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    fn = elt(env, 1); // rassoc
    v_8018 = (*qfn2(fn))(fn, v_8019, v_8018);
    v_8019 = v_8018;
    if (v_8018 == nil) goto v_7978;
    v_8018 = v_8019;
    v_8018 = qcar(v_8018);
    goto v_7976;
v_7978:
    v_8018 = stack[0];
    goto v_7976;
    v_8018 = nil;
v_7976:
    goto v_7956;
v_7973:
    goto v_7999;
v_7995:
    goto v_8005;
v_8001:
    v_8019 = stack[-1];
    goto v_8002;
v_8003:
    v_8018 = stack[0];
    v_8018 = qcar(v_8018);
    goto v_8004;
v_8005:
    goto v_8001;
v_8002:
    goto v_8003;
v_8004:
    stack[-2] = CC_rsubla(elt(env, 0), v_8019, v_8018);
    env = stack[-3];
    goto v_7996;
v_7997:
    goto v_8014;
v_8010:
    v_8019 = stack[-1];
    goto v_8011;
v_8012:
    v_8018 = stack[0];
    v_8018 = qcdr(v_8018);
    goto v_8013;
v_8014:
    goto v_8010;
v_8011:
    goto v_8012;
v_8013:
    v_8018 = CC_rsubla(elt(env, 0), v_8019, v_8018);
    goto v_7998;
v_7999:
    goto v_7995;
v_7996:
    goto v_7997;
v_7998:
    {
        LispObject v_8023 = stack[-2];
        return cons(v_8023, v_8018);
    }
    v_8018 = nil;
v_7956:
    return onevalue(v_8018);
}



// Code for qqe_id!-nyt!-branchq

static LispObject CC_qqe_idKnytKbranchq(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7976;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_7951;
// end of prologue
    v_7976 = stack[0];
    if (!consp(v_7976)) goto v_7955;
    else goto v_7956;
v_7955:
    v_7976 = stack[0];
    fn = elt(env, 1); // qqe_qtidp
    v_7976 = (*qfn1(fn))(fn, v_7976);
    env = stack[-1];
    if (v_7976 == nil) goto v_7960;
    else goto v_7959;
v_7960:
    v_7976 = stack[0];
    {
        fn = elt(env, 2); // qqe_nytidp
        return (*qfn1(fn))(fn, v_7976);
    }
v_7959:
    goto v_7954;
v_7956:
    v_7976 = stack[0];
    v_7976 = qcar(v_7976);
    fn = elt(env, 3); // qqe_qopaddp
    v_7976 = (*qfn1(fn))(fn, v_7976);
    env = stack[-1];
    if (v_7976 == nil) goto v_7969;
    else goto v_7968;
v_7969:
    v_7976 = stack[0];
    v_7976 = qcar(v_7976);
    {
        fn = elt(env, 4); // qqe_qoptailp
        return (*qfn1(fn))(fn, v_7976);
    }
v_7968:
    goto v_7954;
    v_7976 = nil;
v_7954:
    return onevalue(v_7976);
}



// Code for setunion

static LispObject CC_setunion(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7990, v_7991, v_7992;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_7952;
    v_7991 = v_7951;
// end of prologue
v_7956:
    v_7990 = stack[0];
    if (v_7990 == nil) goto v_7959;
    else goto v_7960;
v_7959:
    v_7990 = v_7991;
    goto v_7955;
v_7960:
    goto v_7969;
v_7965:
    v_7990 = stack[0];
    v_7992 = qcar(v_7990);
    goto v_7966;
v_7967:
    v_7990 = v_7991;
    goto v_7968;
v_7969:
    goto v_7965;
v_7966:
    goto v_7967;
v_7968:
    v_7990 = Lmember(nil, v_7992, v_7990);
    if (v_7990 == nil) goto v_7964;
    v_7990 = stack[0];
    v_7990 = qcdr(v_7990);
    stack[0] = v_7990;
    goto v_7956;
v_7964:
    goto v_7983;
v_7979:
    stack[-1] = v_7991;
    goto v_7980;
v_7981:
    v_7990 = stack[0];
    v_7990 = qcar(v_7990);
    v_7990 = ncons(v_7990);
    env = stack[-2];
    goto v_7982;
v_7983:
    goto v_7979;
v_7980:
    goto v_7981;
v_7982:
    v_7990 = Lappend(nil, stack[-1], v_7990);
    env = stack[-2];
    v_7991 = v_7990;
    v_7990 = stack[0];
    v_7990 = qcdr(v_7990);
    stack[0] = v_7990;
    goto v_7956;
    v_7990 = nil;
v_7955:
    return onevalue(v_7990);
}



// Code for ibalp_redclause

static LispObject CC_ibalp_redclause(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_7990, v_7991;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_7951;
// end of prologue
    stack[0] = nil;
    v_7990 = stack[-1];
    v_7990 = qcar(v_7990);
    stack[-2] = v_7990;
v_7961:
    v_7990 = stack[-2];
    if (v_7990 == nil) goto v_7964;
    v_7990 = stack[0];
    if (v_7990 == nil) goto v_7968;
    else goto v_7964;
v_7968:
    goto v_7965;
v_7964:
    goto v_7960;
v_7965:
    goto v_7980;
v_7976:
    v_7990 = stack[-2];
    v_7991 = qcar(v_7990);
    goto v_7977;
v_7978:
    v_7990 = stack[-1];
    v_7990 = qcdr(v_7990);
    v_7990 = qcar(v_7990);
    goto v_7979;
v_7980:
    goto v_7976;
v_7977:
    goto v_7978;
v_7979:
    fn = elt(env, 1); // ibalp_vmember
    v_7990 = (*qfn2(fn))(fn, v_7991, v_7990);
    env = stack[-3];
    if (v_7990 == nil) goto v_7974;
    v_7990 = lisp_true;
    stack[0] = v_7990;
    goto v_7972;
v_7974:
v_7972:
    v_7990 = stack[-2];
    v_7990 = qcdr(v_7990);
    stack[-2] = v_7990;
    goto v_7961;
v_7960:
    v_7990 = stack[0];
    return onevalue(v_7990);
}



// Code for quotodd

static LispObject CC_quotodd(LispObject env,
                         LispObject v_7951, LispObject v_7952)
{
    env = qenv(env);
    LispObject v_7987, v_7988, v_7989;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v_7952,v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v_7951,v_7952);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7988 = v_7952;
    v_7989 = v_7951;
// end of prologue
    v_7987 = v_7989;
    if (!consp(v_7987)) goto v_7960;
    else goto v_7961;
v_7960:
    v_7987 = v_7988;
    v_7987 = (consp(v_7987) ? nil : lisp_true);
    goto v_7959;
v_7961:
    v_7987 = nil;
    goto v_7959;
    v_7987 = nil;
v_7959:
    if (v_7987 == nil) goto v_7957;
    goto v_7974;
v_7970:
    v_7987 = v_7989;
    goto v_7971;
v_7972:
    goto v_7973;
v_7974:
    goto v_7970;
v_7971:
    goto v_7972;
v_7973:
    fn = elt(env, 1); // mkrn
    v_7987 = (*qfn2(fn))(fn, v_7987, v_7988);
    env = stack[0];
    {
        fn = elt(env, 2); // int!-equiv!-chk
        return (*qfn1(fn))(fn, v_7987);
    }
v_7957:
    goto v_7984;
v_7980:
    v_7987 = v_7989;
    goto v_7981;
v_7982:
    goto v_7983;
v_7984:
    goto v_7980;
v_7981:
    goto v_7982;
v_7983:
    {
        fn = elt(env, 3); // lowest!-terms
        return (*qfn2(fn))(fn, v_7987, v_7988);
    }
    v_7987 = nil;
    return onevalue(v_7987);
}



// Code for bsubs

static LispObject CC_bsubs(LispObject env,
                         LispObject v_7951)
{
    env = qenv(env);
    LispObject v_8017;
    LispObject fn;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v_7951);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7951);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_7951;
// end of prologue
    v_8017 = stack[0];
    if (v_8017 == nil) goto v_7955;
    else goto v_7956;
v_7955:
    v_8017 = stack[0];
    goto v_7954;
v_7956:
    v_8017 = stack[0];
    if (!consp(v_8017)) goto v_7959;
    else goto v_7960;
v_7959:
    v_8017 = stack[0];
    fn = elt(env, 1); // bound
    v_8017 = (*qfn1(fn))(fn, v_8017);
    env = stack[-4];
    if (v_8017 == nil) goto v_7965;
    v_8017 = stack[0];
    {
        fn = elt(env, 2); // binding
        return (*qfn1(fn))(fn, v_8017);
    }
v_7965:
    v_8017 = stack[0];
    goto v_7963;
    v_8017 = nil;
v_7963:
    goto v_7954;
v_7960:
    v_8017 = stack[0];
    stack[-3] = v_8017;
    v_8017 = stack[-3];
    if (v_8017 == nil) goto v_7984;
    else goto v_7985;
v_7984:
    v_8017 = nil;
    goto v_7979;
v_7985:
    v_8017 = stack[-3];
    v_8017 = qcar(v_8017);
    v_8017 = CC_bsubs(elt(env, 0), v_8017);
    env = stack[-4];
    v_8017 = ncons(v_8017);
    env = stack[-4];
    stack[-1] = v_8017;
    stack[-2] = v_8017;
v_7980:
    v_8017 = stack[-3];
    v_8017 = qcdr(v_8017);
    stack[-3] = v_8017;
    v_8017 = stack[-3];
    if (v_8017 == nil) goto v_7998;
    else goto v_7999;
v_7998:
    v_8017 = stack[-2];
    goto v_7979;
v_7999:
    goto v_8007;
v_8003:
    stack[0] = stack[-1];
    goto v_8004;
v_8005:
    v_8017 = stack[-3];
    v_8017 = qcar(v_8017);
    v_8017 = CC_bsubs(elt(env, 0), v_8017);
    env = stack[-4];
    v_8017 = ncons(v_8017);
    env = stack[-4];
    goto v_8006;
v_8007:
    goto v_8003;
v_8004:
    goto v_8005;
v_8006:
    v_8017 = Lrplacd(nil, stack[0], v_8017);
    env = stack[-4];
    v_8017 = stack[-1];
    v_8017 = qcdr(v_8017);
    stack[-1] = v_8017;
    goto v_7980;
v_7979:
    goto v_7954;
    v_8017 = nil;
v_7954:
    return onevalue(v_8017);
}



setup_type const u15_setup[] =
{
    {"matsm*1",                 CC_matsmH1,     TOO_MANY_1,    WRONG_NO_1},
    {"maxtype",                 CC_maxtype,     TOO_MANY_1,    WRONG_NO_1},
    {"bind",                    TOO_FEW_2,      CC_bind,       WRONG_NO_2},
    {"triviallcm",              WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_triviallcm},
    {"mkid",                    TOO_FEW_2,      CC_mkid,       WRONG_NO_2},
    {"aminusp:1",               CC_aminuspT1,   TOO_MANY_1,    WRONG_NO_1},
    {"groeb=better",            TOO_FEW_2,      CC_groebMbetter,WRONG_NO_2},
    {"dcombine",                WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_dcombine},
    {"general-times-mod-p",     TOO_FEW_2,      CC_generalKtimesKmodKp,WRONG_NO_2},
    {"setk",                    TOO_FEW_2,      CC_setk,       WRONG_NO_2},
    {"lalr_resolve_conflicts",  TOO_FEW_2,      CC_lalr_resolve_conflicts,WRONG_NO_2},
    {"cl_atml1",                CC_cl_atml1,    TOO_MANY_1,    WRONG_NO_1},
    {"simp*sq",                 CC_simpHsq,     TOO_MANY_1,    WRONG_NO_1},
    {"mri_realvarp",            CC_mri_realvarp,TOO_MANY_1,    WRONG_NO_1},
    {"kernord-split",           TOO_FEW_2,      CC_kernordKsplit,WRONG_NO_2},
    {"aex_varl",                CC_aex_varl,    TOO_MANY_1,    WRONG_NO_1},
    {"cgp_ci",                  CC_cgp_ci,      TOO_MANY_1,    WRONG_NO_1},
    {"image-of-power",          TOO_FEW_2,      CC_imageKofKpower,WRONG_NO_2},
    {"gsugar",                  CC_gsugar,      TOO_MANY_1,    WRONG_NO_1},
    {"formprogn",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_formprogn},
    {"mv-domainlist-*",         TOO_FEW_2,      CC_mvKdomainlistKH,WRONG_NO_2},
    {"pv_times2",               WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_pv_times2},
    {"conv:mt",                 TOO_FEW_2,      CC_convTmt,    WRONG_NO_2},
    {"multd*",                  TOO_FEW_2,      CC_multdH,     WRONG_NO_2},
    {"reduce-degree-mod-p",     TOO_FEW_2,      CC_reduceKdegreeKmodKp,WRONG_NO_2},
    {"lalr_make_compressed_action_row1",CC_lalr_make_compressed_action_row1,TOO_MANY_1,WRONG_NO_1},
    {"rl_prepfof",              CC_rl_prepfof,  TOO_MANY_1,    WRONG_NO_1},
    {"updtemplate",             WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_updtemplate},
    {"talp_subalchk",           CC_talp_subalchk,TOO_MANY_1,   WRONG_NO_1},
    {"ibalp_clausep",           CC_ibalp_clausep,TOO_MANY_1,   WRONG_NO_1},
    {"cird",                    WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_cird},
    {"getcomb",                 TOO_FEW_2,      CC_getcomb,    WRONG_NO_2},
    {"setdmode1",               TOO_FEW_2,      CC_setdmode1,  WRONG_NO_2},
    {"wedgepf",                 TOO_FEW_2,      CC_wedgepf,    WRONG_NO_2},
    {"noncommuting",            TOO_FEW_2,      CC_noncommuting,WRONG_NO_2},
    {"all_edge",                TOO_FEW_2,      CC_all_edge,   WRONG_NO_2},
    {"mv-pow-chk",              TOO_FEW_2,      CC_mvKpowKchk, WRONG_NO_2},
    {":divide",                 TOO_FEW_2,      CC_Tdivide,    WRONG_NO_2},
    {"gperm0",                  CC_gperm0,      TOO_MANY_1,    WRONG_NO_1},
    {"b:extmult",               TOO_FEW_2,      CC_bTextmult,  WRONG_NO_2},
    {"tr_write",                CC_tr_write,    TOO_MANY_1,    WRONG_NO_1},
    {"rread1",                  WRONG_NO_NA,    WRONG_NO_NB,   (n_args *)CC_rread1},
    {"powers3",                 TOO_FEW_2,      CC_powers3,    WRONG_NO_2},
    {"rsubla",                  TOO_FEW_2,      CC_rsubla,     WRONG_NO_2},
    {"qqe_id-nyt-branchq",      CC_qqe_idKnytKbranchq,TOO_MANY_1,WRONG_NO_1},
    {"setunion",                TOO_FEW_2,      CC_setunion,   WRONG_NO_2},
    {"ibalp_redclause",         CC_ibalp_redclause,TOO_MANY_1, WRONG_NO_1},
    {"quotodd",                 TOO_FEW_2,      CC_quotodd,    WRONG_NO_2},
    {"bsubs",                   CC_bsubs,       TOO_MANY_1,    WRONG_NO_1},
    {NULL, (one_args *)"u15", (two_args *)"93479 2123043 2673964", 0}
};

// end of generated code
