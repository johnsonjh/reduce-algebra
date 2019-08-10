
// $destdir/u40.c        Machine generated C code

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
#ifndef NDEBUG
#define NDEBUG 1
#endif
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
#ifdef __cpp_inline_variables
#define INLINE_VAR inline
#else
#define INLINE_VAR static
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
#ifndef __has_cpp_attribute
#define __has_cpp_attribute(name) 0
#endif
#if __has_cpp_attribute(maybe_unused)
#define MAYBE_UNUSED [[maybe_unused]]
#else
#define MAYBE_UNUSED
#endif
#ifdef WIN32
#define __USE_MINGW_ANSI_STDIO 1
#endif
#ifdef WIN32
#include <winsock.h>
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
#endif 
#include <iostream>
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
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
#include <ffi.h>
#undef PACKAGE
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef VERSION
#undef PACKAGE_VERSION
#undef PACKAGE_BUGREPORT
#undef PACKAGE_TARNAME
#undef PACKAGE_URL
#ifndef EMBEDDED
extern "C"
{
#include "softfloat.h"
}
#endif
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
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
inline int32_t ASR(int32_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int32_t)) n=0;
 return a >> n;
}
inline int64_t ASR(int64_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int64_t)) n=0;
 return a >> n;
}
#else 
inline int32_t ASR(int32_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int32_t)) n=0;
 uint32_t r = ((uint32_t)a) >> n;
 uint32_t signbit = ((uint32_t)a) >> (8*sizeof(uint32_t)-1);
 if (n != 0) r |= ((-signbit) << (8*sizeof(uint32_t) - n));
 return (int32_t)r;
}
inline int64_t ASR(int64_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int64_t)) n=0;
 uint64_t r = ((uint64_t)a) >> n;
 uint64_t signbit = ((uint64_t)a) >> (8*sizeof(uint64_t)-1);
 if (n != 0) r |= ((-signbit) << (8*sizeof(uint64_t) - n));
 return (int64_t)r;
}
#endif 
inline int32_t ASL(int32_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(uint32_t)) n = 0;
 return (int32_t)(((uint32_t)a) << n);
}
inline int64_t ASL(int64_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(uint64_t)) n = 0;
 return (int64_t)(((uint64_t)a) << n);
}
inline uint64_t ASL(uint64_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(uint64_t)) n = 0;
 return a << n;
}
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
#ifdef MAXALING4
inline void *aligned_malloc(size_t n)
{ void *p = (void *)malloc(n + 32);
 if (p == NULL) return p;
 void *r = (void *)((((uintptr_t)p + 15) & -(uint64_t)16) + 16);
 (void *)((uintptr_t)r - 16) = p;
 return r;
}
inline void aligned_free(void *p)
{ if (p == NULL) return;
 free(*(void *)((uintptr_t)p - 16));
}
#else 
inline void *aligned_malloc(size_t n)
{ return (void *)malloc(n);
}
inline void aligned_free(void *p)
{ free(p);
}
#endif 
#endif 
#ifndef header_fwin_h
#define header_fwin_h 1
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <signal.h>
#ifdef DEBUG
extern void fwin_write_log(const char *s, ...);
#define FWIN_LOG(...) fwin_write_log(__VA_ARGS__)
#else
#define FWIN_LOG(...) ((void)0)
#endif
typedef int fwin_entrypoint(int argc, const char *argv[]);
extern int fwin_startup(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern const char *fullProgramName;
extern const char *programName;
extern const char *programDir;
#define FWIN_WITH_TERMED 1
#define FWIN_IN_WINDOW 2
extern int fwin_windowmode();
extern void fwin_exit(int return_code);
extern bool fwin_pause_at_end;
extern void fwin_minimize(void);
extern void fwin_restore(void);
extern void fwin_putchar(int c);
extern void fwin_puts(const char *s);
extern void fwin_showmath(const char *s);
extern void fwin_printf(const char *fmt, ...);
extern void fwin_vfprintf(const char *fmt, va_list a);
extern int fwin_linelength;
extern void fwin_ensure_screen(void);
extern int fwin_getchar(void);
#define MAX_PROMPT_LENGTH 80
extern void fwin_set_prompt(const char *s);
extern void fwin_clear_screen();
extern int fwin_screen_size();
typedef char *lookup_function(char *s, int ch);
extern void fwin_set_lookup(lookup_function *f);
typedef void delay_callback_t(int);
extern void fwin_callback_on_delay(delay_callback_t *f);
#define QUERY_INTERRUPT 0
#define QUIET_INTERRUPT 1
#define NOISY_INTERRUPT 2
#define BREAK_LOOP 3
#define QUIT_PROGRAM 4
typedef void review_switch_settings_function();
extern void fwin_menus(char **modules, char **switches,
 review_switch_settings_function *f);
extern void fwin_refresh_switches(char **switches, char **packages);
extern void fwin_report_left(const char *msg);
extern void fwin_report_mid(const char *msg);
extern void fwin_report_right(const char *msg);
extern char about_box_title[40]; 
extern char about_box_description[40]; 
extern char about_box_rights_1[40]; 
extern char about_box_rights_2[40]; 
extern char about_box_rights_3[40]; 
extern char about_box_rights_4[40]; 
extern void fwin_set_help_file(const char *key, const char *path);
extern int plain_worker(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern delay_callback_t *delay_callback;
extern void fwin_putchar_overwrite(int c);
extern void fwin_move_cursor_vertically(int n);
extern void fwin_move_to_column(int column);
#define INPUT_HISTORY_SIZE 100
extern wchar_t *input_history[INPUT_HISTORY_SIZE];
extern int input_history_next;
extern void input_history_init();
extern void input_history_end();
extern void input_history_add(const wchar_t *s);
extern const wchar_t *input_history_get(int n);
#ifndef INT_VERSION
#define INT_VERSION(a,b,c) (((a*1000) + b)*1000 + c)
#endif
extern int find_program_directory(const char *argv0);
typedef struct date_and_type_
{ unsigned long int date;
 unsigned long int type;
} date_and_type;
extern void set_filedate(const char *name, unsigned long int datestamp,
 unsigned long int ftype);
extern void put_fileinfo(date_and_type *p, const char *name);
extern int windowed;
extern int windowed_worker(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern bool fwin_use_xft;
extern bool directoryp(char *f, const char *o, size_t n);
extern bool using_termed;
extern int fwin_plain_getchar();
extern bool texmacs_mode;
#ifdef HAVE_SIGACTION
extern void sigint_handler(int signo, siginfo_t *t, void *v);
#else 
extern void sigint_handler(int signo);
#endif 
extern int plain_worker(int argc, const char *argv[], fwin_entrypoint *fwin_main);
extern char fwin_prompt_string[MAX_PROMPT_LENGTH];
extern int get_current_directory(char *s, size_t n);
extern bool file_readable(char *filename, const char *old, size_t n);
extern bool file_writeable(char *filename, const char *old, size_t n);
extern bool file_executable(char *filename, const char *old, size_t n);
extern int rename_file(char *from_name, const char *from_old, size_t from_size,
 char *to_name, const char *to_old, size_t to_size);
extern int get_home_directory(char *b, size_t len);
extern int get_users_home_directory(char *b, size_t len);
extern int my_system(const char *s);
extern int truncate_file(FILE *f, long int where);
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
inline uint128_t uint128(int128_t v)
{ return (uint128_t)v;
}
inline uint128_t uint128(uint64_t v)
{ return (uint128_t)v;
}
inline uint128_t uint128(int64_t v)
{ return (uint128_t)v;
}
inline int128_t int128(int64_t v)
{ return (int128_t)v;
}
inline bool greaterp128(int128_t a, int128_t b)
{ return a > b;
}
inline bool lessp128(int128_t a, int128_t b)
{ return a < b;
}
inline bool geq128(int128_t a, int128_t b)
{ return a >= b;
}
inline bool leq128(int128_t a, int128_t b)
{ return a <= b;
}
inline int128_t ASL128(int128_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int128_t)) n = 0;
 return(int128_t) ((uint128_t)a) << n;
}
#ifdef SIGNED_SHIFTS_ARE_ARITHMETIC
inline int128_t ASR128(int128_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(int128_t)) n = 0;
 return a >> n;
}
#else 
inline int128_t ASR128(int128_t a, int n)
{ if (n<0 || n>=sizeof(uint128_t)) n = 0;
 uint128_t r = ((uint128_t)a) >> n;
 uint128_t signbit = ((uint128_t)a) >> (8*sizeof(uint128_t)-1);
 if (n != 0) r |= ((-signbit) << (8*sizeof(uint128_t) - n);
 return (int128_t)r;
}
#endif 
inline int64_t NARROW128(int128_t a)
{ return (int64_t)a;
}
inline void divrem128(int128_t a, int128_t b,
 int128_t &q, int128_t &r)
{ uint128_t qq = a/b;
 q = qq;
 r = a - qq*b;
}
#else 
typedef uint128_t int128_t;
inline uint128_t uint128(int128_t v)
{ uint128_t r = v;
 return r;
}
inline uint128_t uint128(int64_t v)
{ uint128_t r = (uint64_t)v;
 return r;
}
inline uint128_t uint128(uint64_t v)
{ uint128_t r = v;
 return r;
}
inline int128_t int128(int64_t v)
{ int128_t r = (uint64_t)v;
 if (v < 0)
 { int128_t w = -(uint64_t)1;
 w = w <<64;
 r = r | w;
 }
 return r;
}
inline bool greaterp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa > bb;
}
inline bool lessp128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa < bb;
}
inline bool geq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa >= bb;
}
inline bool leq128(const uint128_t & a, const uint128_t & b)
{ uint128_t aa(a.upper() ^ UINT64_C(0x8000000000000000), a.lower());
 uint128_t bb(b.upper() ^ UINT64_C(0x8000000000000000), b.lower());
 return aa <= bb;
}
inline int128_t ASL128(const int128_t & a, int n)
{ if (n >= 128) return 0;
 if (n < 64) return
 int128_t((a.upper()<<n) | (a.lower()>>(64-n)),
 a.lower()<<n);
 else if (n == 64) return int128_t(a.lower(), 0);
 else return int128_t(a.lower()<<(n-64), 0);
}
inline int128_t ASR128(const int128_t & a, int n)
{ if (n >= 128) return (a < 0 ? -1 : 0);
 if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(int64_t)(a.upper()<0),
 a.upper());
 else if (n < 64) return int128_t(ASR((int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else return int128_t(-(int64_t)(a.upper()<0),
 ASR(((int64_t)a.upper()), n-64));
}
inline int64_t NARROW128(const int128_t & a)
{ return (int64_t)a.lower();
}
inline void divrem128(const int128_t & a, const int128_t & b,
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
typedef intptr_t LispObject;
extern LispObject nil;
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
inline void CSL_IGNORE(LispObject x)
{ (void)x;
}
#ifndef PAGE_BITS
# define PAGE_BITS 23
#endif 
#define PAGE_POWER_OF_TWO (((size_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO)
#ifndef MAX_HEAPSIZE
#define MAX_HEAPBITS (SIXTY_FOUR_BIT ? 41 : 31)
#define MAX_HEAPSIZE (((size_t)1) << (MAX_HEAPBITS-20))
#endif 
#define MEGABYTE ((size_t)0x100000)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#endif
#define LONGEST_LEGAL_FILENAME 1024
#define CELL ((size_t)sizeof(LispObject))
static const int TAG_BITS = 0x7;
static const int XTAG_BITS = 0xf;
static const int TAG_CONS = 0; 
static const int TAG_VECTOR = 1; 
static const int TAG_HDR_IMMED = 2; 
static const int TAG_FORWARD = 3; 
static const int TAG_SYMBOL = 4; 
static const int TAG_NUMBERS = 5; 
static const int TAG_BOXFLOAT = 6; 
static const int TAG_FIXNUM = 7; 
static const int TAG_XBIT = 8; 
static const int XTAG_SFLOAT = 15; 
static const int XTAG_FLOAT32 = 16;
inline bool is_forward(LispObject p)
{ return (p & TAG_BITS) == TAG_FORWARD;
}
inline bool is_number(LispObject p)
{ return (p & TAG_BITS) >= TAG_NUMBERS;
}
inline bool is_float(LispObject p)
{ return ((0xc040 >> (p & XTAG_BITS)) & 1) != 0;
}
inline bool is_immed_or_cons(LispObject p)
{ return ((0x85 >> (p & TAG_BITS)) & 1) != 0;
}
inline bool is_immed_cons_sym(LispObject p)
{ return ((0x95 >> (p & TAG_BITS)) & 1) != 0;
}
inline bool need_more_than_eq(LispObject p)
{ return ((0x63 >> (p & TAG_BITS)) & 1) != 0;
}
inline constexpr LispObject fixnum_of_int(intptr_t x)
{ return (LispObject)((((uintptr_t)x)<<4) + TAG_FIXNUM);
}
#define FIXNUM_OF_INT(n) (16*(n)+TAG_FIXNUM)
inline constexpr intptr_t int_of_fixnum(LispObject x)
{ return ((intptr_t)x & ~(intptr_t)15)/16;
}
inline bool valid_as_fixnum(int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
inline bool intptr_valid_as_fixnum(intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((uintptr_t)1) << 28);
}
inline bool valid_as_fixnum(uint64_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
#define MOST_POSITIVE_FIXVAL (((intptr_t)1 << (8*sizeof(LispObject)-5)) - 1)
#define MOST_NEGATIVE_FIXVAL (-((intptr_t)1 << (8*sizeof(LispObject)-5)))
#define MOST_POSITIVE_FIXNUM fixnum_of_int(MOST_POSITIVE_FIXVAL)
#define MOST_NEGATIVE_FIXNUM fixnum_of_int(MOST_NEGATIVE_FIXVAL)
inline bool is_cons(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_CONS);
}
inline bool is_fixnum(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == TAG_FIXNUM);
}
inline bool is_odds(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_HDR_IMMED); 
}
inline bool is_sfloat(LispObject p)
{ return ((((int)(p)) & XTAG_BITS) == XTAG_SFLOAT);
}
inline bool is_symbol(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_SYMBOL);
}
inline bool is_numbers(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_NUMBERS);
}
inline bool is_vector(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_VECTOR);
}
inline bool is_bfloat(LispObject p)
{ return ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT);
}
inline bool consp(LispObject p)
{ return is_cons(p);
}
inline bool symbolp(LispObject p)
{ return is_symbol(p);
}
inline bool car_legal(LispObject p)
{ return is_cons(p);
}
typedef struct Cons_Cell_
{ std::atomic<LispObject> car;
 std::atomic<LispObject> cdr;
} Cons_Cell;
extern bool valid_address(void *pointer);
[[noreturn]] extern void my_abort();
inline std::atomic<LispObject>& qcar(LispObject p)
{ 
 return ((Cons_Cell *)p)->car;
}
inline std::atomic<LispObject>& qcdr(LispObject p)
{ 
 return ((Cons_Cell *)p)->cdr;
}
inline LispObject car(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ 
 return ((Cons_Cell *)p)->car.load(mo);
}
inline LispObject cdr(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ 
 return ((Cons_Cell *)p)->cdr.load(mo);
}
inline void setcar(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ 
 ((Cons_Cell *)p)->car.store(q, mo);
}
inline void setcdr(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ 
 ((Cons_Cell *)p)->cdr.store(q, mo);
}
inline std::atomic<LispObject> *caraddr(LispObject p)
{ 
 return &(((Cons_Cell *)p)->car);
}
inline std::atomic<LispObject> *cdraddr(LispObject p)
{ 
 return &(((Cons_Cell *)p)->cdr);
}
inline LispObject *vcaraddr(LispObject p)
{ 
 return (LispObject *)&(((Cons_Cell *)p)->car);
}
inline LispObject *vcdraddr(LispObject p)
{ 
 return (LispObject *)&(((Cons_Cell *)p)->cdr);
}
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject no_args(LispObject);
typedef LispObject one_arg(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject three_args(LispObject, LispObject, LispObject, LispObject);
typedef LispObject fourup_args(LispObject, LispObject, LispObject,
 LispObject, LispObject);
typedef uintptr_t Header;
#define Tw (3)
#define header_mask (0x7f<<Tw)
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
#define TYPE_PADDER ( 0x7b <<Tw) 
inline bool vector_holds_binary(Header h)
{ return ((h) & (0x2<<Tw)) != 0;
}
#define TYPE_SIMPLE_VEC ( 0x01 <<Tw) 
#define TYPE_INDEXVEC ( 0x11 <<Tw) 
#define TYPE_HASH ( 0x15 <<Tw) 
#define TYPE_HASHX ( 0x19 <<Tw) 
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
#define VIRTUAL_TYPE_REF ( 0x17d <<Tw)
#define VIRTUAL_TYPE_NIL ( 0x27d <<Tw)
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
inline Header vechdr(LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)v - TAG_VECTOR))->load(mo);
}
inline void setvechdr(LispObject v, Header h, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)v - TAG_VECTOR))->store(h, mo);
}
inline unsigned int type_of_header(Header h)
{ return ((unsigned int)h) & header_mask;
}
inline size_t length_of_header(Header h)
{ return (((size_t)h) >> (Tw+7)) << 2;
}
inline size_t length_of_bitheader(Header h)
{ return (((size_t)h) >> (Tw+2)) - 31;
}
inline size_t length_of_byteheader(Header h)
{ return (((size_t)h) >> (Tw+5)) - 3;
}
inline size_t length_of_hwordheader(Header h)
{ return (((size_t)h) >> (Tw+6)) - 1;
}
inline Header bitvechdr_(size_t n)
{ return TYPE_BITVEC_1 + (((n+31)&31)<<(Tw+2));
}
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
inline bool is_symbol_header(Header h)
{ return ((int)h & (0xf<<Tw)) == TYPE_SYMBOL;
}
inline bool is_symbol_header_full_test(Header h)
{ return ((int)h & ((0xf<<Tw) + TAG_BITS)) == (TYPE_SYMBOL + TAG_HDR_IMMED);
}
inline int header_fastget(Header h)
{ return (h >> SYM_FASTGET_SHIFT) & 0x3f;
}
inline bool is_number_header_full_test(Header h)
{ return ((int)h & ((0x1d<<Tw) + TAG_BITS)) == ((0x1d<<Tw) + TAG_HDR_IMMED);
}
inline bool is_vector_header_full_test(Header h)
{ return is_odds(h) && (((int)h & (0x3<<Tw)) != 0);
}
inline bool is_array_header(Header h)
{ return type_of_header(h) == TYPE_ARRAY;
}
inline bool is_basic_vector(LispObject v)
{ return type_of_header(vechdr(v)) != TYPE_INDEXVEC;
}
inline bool vector_i8(Header h)
{ return ((0x7f070707u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i16(Header h)
{ return ((0x00080008u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i32(Header h)
{ return ((0x00000090u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i64(Header h)
{ return ((0x00007820u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_i128(Header h)
{ return ((0x00000040u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_f32(Header h)
{ return ((0x00108000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_f64(Header h)
{ return ((0x00a00000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline bool vector_f128(Header h)
{ return ((0x80400000u >> ((h >> (Tw+2)) & 0x1f)) & 1) != 0;
}
inline std::atomic<LispObject>& basic_elt(LispObject v, size_t n)
{ return *(std::atomic<LispObject> *)((char *)v +
 (CELL-TAG_VECTOR) +
 (n*sizeof(LispObject)));
}
inline bool vector_i8(LispObject n)
{ if (is_basic_vector(n)) return vector_i8(vechdr(n));
 else return vector_i8(vechdr(basic_elt(n, 0)));
}
inline bool vector_i16(LispObject n)
{ if (is_basic_vector(n)) return vector_i16(vechdr(n));
 else return vector_i16(vechdr(basic_elt(n, 0)));
}
inline bool vector_i32(LispObject n)
{ if (is_basic_vector(n)) return vector_i32(vechdr(n));
 else return vector_i32(vechdr(basic_elt(n, 0)));
}
inline bool vector_i64(LispObject n)
{ if (is_basic_vector(n)) return vector_i64(vechdr(n));
 else return vector_i64(vechdr(basic_elt(n, 0)));
}
inline bool vector_i128(LispObject n)
{ if (is_basic_vector(n)) return vector_i128(vechdr(n));
 else return vector_i128(vechdr(basic_elt(n, 0)));
}
inline bool vector_f32(LispObject n)
{ if (is_basic_vector(n)) return vector_f32(vechdr(n));
 else return vector_f32(vechdr(basic_elt(n, 0)));
}
inline bool vector_f64(LispObject n)
{ if (is_basic_vector(n)) return vector_f64(vechdr(n));
 else return vector_f64(vechdr(basic_elt(n, 0)));
}
inline bool vector_f128(LispObject n)
{ if (is_basic_vector(n)) return vector_f128(vechdr(n));
 else return vector_f128(vechdr(basic_elt(n, 0)));
}
#define TYPE_BIGNUMINDEX ( 0x1d <<Tw)
#define TYPE_BIGNUM ( 0x1f <<Tw)
#define TYPE_RATNUM ( 0x3d <<Tw)
#define TYPE_SINGLE_FLOAT ( 0x3f <<Tw)
#define TYPE_COMPLEX_NUM ( 0x5d <<Tw)
#define TYPE_DOUBLE_FLOAT ( 0x5f <<Tw)
#define TYPE_NEW_BIGNUM ( 0x7d <<Tw) 
#define TYPE_LONG_FLOAT ( 0x7f <<Tw)
inline Header numhdr(LispObject v, std::memory_order mo = std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)(v) - TAG_NUMBERS))->load(mo);
}
inline Header flthdr(LispObject v, std::memory_order mo = std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)(v) - TAG_BOXFLOAT))->load(mo);
}
inline void setnumhdr(LispObject v, Header h, std::memory_order mo = std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)(v) - TAG_NUMBERS))->store(h, mo);
}
inline void setflthdr(LispObject v, Header h, std::memory_order mo = std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)(v) - TAG_BOXFLOAT))->store(h, mo);
}
inline bool is_short_float(LispObject v)
{ if (!is_sfloat(v)) return false;
 if (SIXTY_FOUR_BIT && (v & XTAG_FLOAT32) != 0) return false;
 return true;
}
inline bool is_single_float(LispObject v)
{ if (SIXTY_FOUR_BIT && is_sfloat(v) && (v & XTAG_FLOAT32) != 0) return true;
 return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_SINGLE_FLOAT;
}
inline bool is_double_float(LispObject v)
{ return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_DOUBLE_FLOAT;
}
inline bool is_long_float(LispObject v)
{ return is_bfloat(v) && type_of_header(flthdr(v)) == TYPE_LONG_FLOAT;
}
inline bool is_ratio(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_RATNUM;
}
inline bool is_complex(LispObject n)
{ return type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM;
}
inline bool is_bignum_header(Header h)
{ return type_of_header(h) == TYPE_BIGNUM;
}
inline bool is_bignum(LispObject n)
{ return is_bignum_header(numhdr(n));
 
}
inline bool is_new_bignum_header(Header h)
{ return type_of_header(h) == TYPE_NEW_BIGNUM;
}
inline bool is_new_bignum(LispObject n)
{ return is_new_bignum_header(numhdr(n));
 
}
inline bool is_string_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_STRING_1;
}
inline bool is_string(LispObject n)
{ if (is_basic_vector(n)) return is_string_header(vechdr(n));
 else return is_string_header(vechdr(basic_elt(n, 0)));
}
inline bool is_vec8_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_VEC8_1;
}
inline bool is_vec8(LispObject n)
{ if (is_basic_vector(n)) return is_vec8_header(vechdr(n));
 else return is_vec8_header(vechdr(basic_elt(n, 0)));
}
inline bool is_bps_header(Header h)
{ return (type_of_header(h) & (0x1f<<Tw)) == TYPE_BPS_1;
}
inline bool is_bps(LispObject n)
{ return is_bps_header(vechdr(n));
}
inline bool is_vec16_header(Header h)
{ return (type_of_header(h) & (0x3f<<Tw)) == TYPE_VEC16_1;
}
inline bool is_vec16(LispObject n)
{ if (is_basic_vector(n)) return is_vec16_header(vechdr(n));
 else return is_vec16_header(vechdr(basic_elt(n, 0)));
}
inline bool is_bitvec_header(Header h)
{ return (type_of_header(h) & (0x03<<Tw)) == TYPE_BITVEC_1;
}
inline bool is_bitvec(LispObject n)
{ if (is_basic_vector(n)) return is_bitvec_header(vechdr(n));
 else return is_bitvec_header(vechdr(basic_elt(n, 0)));
}
inline char& basic_celt(LispObject v, size_t n)
{ return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}
inline unsigned char& basic_ucelt(LispObject v, size_t n)
{ return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}
inline signed char& basic_scelt(LispObject v, size_t n)
{ return *((signed char *)v + (CELL-TAG_VECTOR) + n);
}
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
inline unsigned char* data_of_bps(LispObject v)
{ return (unsigned char *)v + BPS_DATA_OFFSET;
}
inline LispObject& vselt(LispObject v, size_t n)
{ return *(LispObject *)(((intptr_t)v & ~((intptr_t)TAG_BITS)) +
 ((1 + n)*sizeof(LispObject)));
}
inline int16_t& basic_helt(LispObject v, size_t n)
{ return *(int16_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int16_t));
}
inline intptr_t& basic_ielt(LispObject v, size_t n)
{ return *(intptr_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(intptr_t));
}
inline int32_t& basic_ielt32(LispObject v, size_t n)
{ return *(int32_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(int32_t));
}
inline float& basic_felt(LispObject v, size_t n)
{ return *(float *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(float));
}
inline double& basic_delt(LispObject v, size_t n)
{ return *(double *)((char *)v +
 (8-TAG_VECTOR) +
 n*sizeof(double));
}
#define LOG2_VECTOR_CHUNK_BYTES (PAGE_BITS-2)
#define VECTOR_CHUNK_BYTES ((size_t)(((size_t)1)<<LOG2_VECTOR_CHUNK_BYTES))
inline bool is_power_of_two(uint64_t n)
{ return (n == (n & (-n)));
}
inline int intlog2(uint64_t n)
{
 static const unsigned char intlog2_table[] =
 {
 0, 0, 1, 39, 2, 15, 40, 23,
 3, 12, 16, 59, 41, 19, 24, 54,
 4,0, 13, 10, 17, 62, 60, 28,
 42, 30, 20, 51, 25, 44, 55, 47,
 5,32, 0, 38, 14, 22, 11, 58,
 18, 53, 63, 9, 61, 27, 29, 50,
 43, 46, 31, 37, 21, 57, 52, 8,
 26, 49, 45, 36, 56, 7, 48, 35,
 6,34, 33
 };
 return intlog2_table[n % (sizeof(intlog2_table)/sizeof(intlog2_table[0]))];
}
inline int type_of_vector(LispObject v)
{ if (is_basic_vector(v)) return type_of_header(vechdr(v));
 else return type_of_header(vechdr(basic_elt(v, 0)));
}
inline size_t bytes_in_bytevector(LispObject v)
{ if (is_basic_vector(v)) return length_of_byteheader(vechdr(v)) - CELL;
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_byteheader(vechdr(basic_elt(v, n-1))) - CELL;
}
inline size_t hwords_in_hwordvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_hwordheader(vechdr(v)) - (CELL/2);
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (VECTOR_CHUNK_BYTES/2)*(n-1) +
 length_of_hwordheader(vechdr(basic_elt(v, n-1))) - (CELL/2);
}
inline size_t bits_in_bitvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_bitheader(vechdr(v)) - 8*CELL;
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (8*VECTOR_CHUNK_BYTES)*(n-1) +
 length_of_bitheader(vechdr(basic_elt(v, n-1))) - 8*CELL;
}
inline size_t bytes_in_vector(LispObject v)
{ if (is_basic_vector(v)) return length_of_header(vechdr(v)) - CELL;
 size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_header(vechdr(basic_elt(v, n-1))) - CELL;
}
inline size_t cells_in_vector(LispObject v)
{ return bytes_in_vector(v)/CELL;
}
inline bool vector_holds_binary(LispObject v)
{ if (is_basic_vector(v)) return vector_holds_binary(vechdr(v));
 else return vector_holds_binary(vechdr(basic_elt(v, 0)));
}
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];
inline void discard_basic_vector(LispObject v)
{ size_t size = length_of_header(vechdr(v));
 size_t n = size/CELL - 1;
 if (is_power_of_two(n)) 
 { int i = intlog2(n); 
 if (i <= LOG2_VECTOR_CHUNK_BYTES)
 { basic_elt(v, 0) = free_vectors[i];
 setvechdr(v,TYPE_SIMPLE_VEC +
 (size << (Tw+5)) +
 TAG_HDR_IMMED);
 v = (v & ~(uintptr_t)TAG_BITS) | TAG_VECTOR;
 free_vectors[i] = v;
 }
 }
}
inline void discard_vector(LispObject v)
{ if (is_basic_vector(v)) discard_basic_vector(v);
 else
 { size_t n1 = length_of_header(vechdr(v))/CELL - 1;
 for (size_t i=0; i<n1; i++)
 discard_basic_vector(basic_elt(v, i));
 discard_basic_vector(v);
 }
}
inline std::atomic<LispObject>& elt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_elt(v, n);
 return basic_elt(basic_elt(v, n/(VECTOR_CHUNK_BYTES/CELL)),
 n%(VECTOR_CHUNK_BYTES/CELL));
}
inline char& celt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_celt(v, n);
 return basic_celt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline unsigned char& ucelt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_ucelt(v, n);
 return basic_ucelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline signed char& scelt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_scelt(v, n);
 return basic_scelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline int16_t& helt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_helt(v, n);
 return basic_helt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(int16_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(int16_t)));
}
inline intptr_t& ielt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_ielt(v, n);
 return basic_ielt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(intptr_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(intptr_t)));
}
inline int32_t& ielt32(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_ielt32(v, n);
 return basic_ielt32(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(int32_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(int32_t)));
}
inline float& felt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_felt(v, n);
 return basic_felt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(float))),
 n%(VECTOR_CHUNK_BYTES/sizeof(float)));
}
inline double& delt(LispObject v, size_t n)
{ if (is_basic_vector(v)) return basic_delt(v, n);
 return basic_delt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(double))),
 n%(VECTOR_CHUNK_BYTES/sizeof(double)));
}
inline bool is_header(LispObject x)
{ return ((int)x & (0x3<<Tw)) != 0; 
}
inline bool is_char(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_CHAR;
}
inline bool is_spid(LispObject x)
{ return ((int)x & HDR_IMMED_MASK) == TAG_SPID;
}
inline bool is_library(LispObject x)
{ return ((int)x & 0xfffff) == SPID_LIBRARY;
}
inline unsigned int library_number(LispObject x)
{ return (x >> 20) & 0xfff;
}
inline int font_of_char(LispObject n)
{ return ((int32_t)n >> (21+4+Tw)) & 0xf;
}
inline int bits_of_char(LispObject n)
{ return 0;
}
inline unsigned int code_of_char(LispObject n)
{ return ((uint32_t)(n) >> (4+Tw)) & 0x001fffff;
}
inline LispObject pack_char(int font, unsigned int code)
{ return (LispObject)((((uint32_t)(font)) << (21+4+Tw)) |
 (((uint32_t)(code)) << (4+Tw)) | TAG_CHAR);
}
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head_
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
 intptr_t function4up;
 uint64_t count; 
} Symbol_Head;
#ifdef FUTURE_IDEA
typedef struct Symbol_Head_
{ Header header; 
 LispObject value; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject pname; 
 LispObject package; 
 LispObject function; 
 uintptr_t count; 
} Symbol_Head;
typedef struct Function_Object_
{ Header header; 
 LispObject env; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 intptr_t function4up;
 uintptr_t count; 
} Function_Object;
typedef struct Bytecoded_Function_Object_
{ Header header; 
 LispObject env; 
 intptr_t function0; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t function3; 
 intptr_t function4up;
 uintptr_t count; 
 unsigned char bytecodes[]; 
} Bytecoded_Function_Object;
#endif 
#define MAX_FASTGET_SIZE 63
inline Header qheader(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<Header> *)((char *)p + (0*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qvalue(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (1*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qenv(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (2*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qplist(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (3*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qfastgets(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (4*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qpackage(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (5*CELL-TAG_SYMBOL)))->load(mo);
}
inline LispObject qpname(LispObject p, std::memory_order mo=std::memory_order_relaxed)
{ return ((std::atomic<LispObject> *)((char *)p + (6*CELL-TAG_SYMBOL)))->load(mo);
}
inline std::atomic<LispObject> *valueaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (1*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *envaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (2*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *plistaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (3*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *fastgetsaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (4*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *packageaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (5*CELL-TAG_SYMBOL));
}
inline std::atomic<LispObject> *pnameaddr(LispObject p)
{ return (std::atomic<LispObject> *)((char *)p + (6*CELL-TAG_SYMBOL));
}
inline void setheader(LispObject p, Header h, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<Header> *)((char *)p + (0*CELL-TAG_SYMBOL)))->store(h, mo);
}
inline void setvalue(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (1*CELL-TAG_SYMBOL)))->store(q, mo); 
}
inline void setenv(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (2*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setplist(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (3*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setfastgets(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (4*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setpackage(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (5*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline void setpname(LispObject p, LispObject q, std::memory_order mo=std::memory_order_relaxed)
{ ((std::atomic<LispObject> *)((char *)p + (6*CELL-TAG_SYMBOL)))->store(q, mo);
}
inline intptr_t& ifn0(LispObject p)
{ return *(intptr_t *)((char *)p + (7*CELL-TAG_SYMBOL));
}
inline intptr_t& ifn1(LispObject p)
{ return *(intptr_t *)((char *)p + (8*CELL-TAG_SYMBOL));
}
inline intptr_t& ifn2(LispObject p)
{ return *(intptr_t *)((char *)p + (9*CELL-TAG_SYMBOL));
}
inline intptr_t& ifn3(LispObject p)
{ return *(intptr_t *)((char *)p + (10*CELL-TAG_SYMBOL));
}
inline intptr_t& ifn4up(LispObject p)
{ return *(intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
inline intptr_t& ifnunused(LispObject p)
{ return *(intptr_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}
inline intptr_t& ifnn(LispObject p)
{ return *(intptr_t *)((char *)p + (13*CELL-TAG_SYMBOL));
}
inline no_args*& qfn0(LispObject p)
{ return *((no_args **)((char *)p + (7*CELL-TAG_SYMBOL)));
}
inline one_arg*& qfn1(LispObject p)
{ return *(one_arg **)((char *)p + (8*CELL-TAG_SYMBOL));
}
inline two_args*& qfn2(LispObject p)
{ return *(two_args **)((char *)p + (9*CELL-TAG_SYMBOL));
}
inline three_args*& qfn3(LispObject p)
{ return *(three_args **)((char *)p + (10*CELL-TAG_SYMBOL));
}
inline fourup_args*& qfn4up(LispObject p)
{ return *(fourup_args **)((char *)p + (11*CELL-TAG_SYMBOL));
}
[[noreturn]] extern void aerror1(const char *s, LispObject a);
inline LispObject arg4(const char *name, LispObject a4up)
{ if (cdr(a4up) != nil) aerror1(name, a4up); 
 return car(a4up);
}
inline void a4a5(const char *name, LispObject a4up,
 LispObject& a4, LispObject& a5)
{ a4 = car(a4up);
 a4up = cdr(a4up);
 if (a4up==nil || cdr(a4up) != nil) aerror1(name, a4up); 
 a5 = car(a4up);
}
inline void a4a5a6(const char *name, LispObject a4up,
 LispObject& a4, LispObject& a5, LispObject& a6)
{ a4 = car(a4up);
 a4up = cdr(a4up);
 if (a4up == nil) aerror1(name, a4up); 
 a5 = car(a4up);
 a4up = cdr(a4up);
 if (a4up==nil || cdr(a4up) != nil) aerror1(name, a4up); 
 a6 = car(a4up);
}
inline std::atomic<uint64_t>& qcount(LispObject p)
{ return *(std::atomic<uint64_t> *)((char *)p + (12*CELL-TAG_SYMBOL));
}
#ifndef HAVE_SOFTFLOAT
typedef struct _float32_t
{ uint32_t v;
} float32_t;
typedef struct _float64_t
{ uint64_t v;
} float64_t;
#endif
typedef union _Float_union
{ float f;
 uint32_t i;
 float32_t f32;
} Float_union;
inline LispObject low32(LispObject a)
{ return (LispObject)(uint32_t)a;
}
typedef struct Big_Number_
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
inline size_t bignum_length(LispObject b)
{ return length_of_header(numhdr(b));
}
inline uint32_t* bignum_digits(LispObject b)
{ return (uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
inline uint32_t* vbignum_digits(LispObject b)
{ return (uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
inline int64_t bignum_digits64(LispObject b, size_t n)
{ return (int64_t)((int32_t *)((char *)b+(CELL-TAG_NUMBERS)))[n];
}
inline Header make_bighdr(size_t n)
{ return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}
inline Header make_new_bighdr(size_t n)
{ return TAG_HDR_IMMED+TYPE_NEW_BIGNUM+(n<<(Tw+8));
}
inline uint64_t* new_bignum_digits(LispObject b)
{ return (uint64_t *)((char *)b + (8-TAG_NUMBERS));
}
#define pack_hdrlength(n) (((intptr_t)(n))<<(Tw+7))
typedef struct Rational_Number_
{ std::atomic<Header> header;
 std::atomic<LispObject> num;
 std::atomic<LispObject> den;
} Rational_Number;
inline LispObject numerator(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->num.load(mo);
}
inline LispObject denominator(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den.load(mo);
}
inline void setnumerator(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ ((Rational_Number *)((char *)r-TAG_NUMBERS))->num.store(v, mo);
}
inline void setdenominator(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((Rational_Number *)((char *)r-TAG_NUMBERS))->den.store(v, mo);
}
typedef struct Complex_Number_
{ std::atomic<Header> header;
 std::atomic<LispObject> real;
 std::atomic<LispObject> imag;
} Complex_Number;
inline LispObject real_part(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real.load(mo);
}
inline LispObject imag_part(LispObject r, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag.load(mo);
}
inline void setreal_part(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->real.store(v, mo);
}
inline void setimag_part(LispObject r, LispObject v, std::memory_order mo=std::memory_order_relaxed)
{ return ((Complex_Number *)((char *)r-TAG_NUMBERS))->imag.store(v, mo);
}
typedef struct Single_Float_
{ std::atomic<Header> header;
 union float_or_int
 { float f;
 float32_t f32;
 int32_t i;
 } f;
} Single_Float;
inline float& single_float_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f;
}
inline float32_t& float32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f32;
}
inline int32_t& intfloat32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.i;
}
typedef union _Double_union
{ double f;
 uint32_t i[2];
 uint64_t i64;
 float64_t f64;
} Double_union;
#define SIZEOF_DOUBLE_FLOAT 16
inline double *double_float_addr(LispObject v)
{ return (double *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int32_t& double_float_pad(LispObject v)
{ return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
inline double& double_float_val(LispObject v)
{ return *(double *)((char *)v + (8-TAG_BOXFLOAT));
}
inline float64_t& float64_t_val(LispObject v)
{ return *(float64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int64_t& intfloat64_t_val(LispObject v)
{ return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int32_t& intfloat64_t_val_hi(LispObject v)
{ return *(int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int32_t& intfloat64_t_val_lo(LispObject v)
{ return *(int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
#ifdef HAVE_SOFTFLOAT
#define SIZEOF_LONG_FLOAT 24
inline float128_t *long_float_addr(LispObject v)
{ return (float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int32_t& long_float_pad(LispObject v)
{ return *(int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
inline float128_t& long_float_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline float128_t& float128_t_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int64_t& intfloat128_t_val0(LispObject v)
{ return *(int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int64_t& intfloat128_t_val1(LispObject v)
{ return *(int64_t *)((char *)v + (16-TAG_BOXFLOAT));
}
inline int32_t& intfloat128_t_val32_0(LispObject v)
{ return *(int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline int32_t& intfloat128_t_val32_1(LispObject v)
{ return *(int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
inline int32_t& intfloat128_t_val32_2(LispObject v)
{ return *(int32_t *)((char *)v + (16-TAG_BOXFLOAT));
}
inline int32_t& intfloat128_t_val32_3(LispObject v)
{ return *(int32_t *)((char *)v + (20-TAG_BOXFLOAT));
}
#endif 
inline uintptr_t word_align_up(uintptr_t n)
{ return (LispObject)((n + 3) & (-(uintptr_t)4U));
}
inline uintptr_t doubleword_align_up(uintptr_t n)
{ return (uintptr_t)((n + 7) & (-(uintptr_t)8U));
}
inline LispObject doubleword_align_up(LispObject n)
{ return (LispObject)(((uintptr_t)n + 7) & (-(uintptr_t)8U));
}
inline uintptr_t doubleword_align_down(uintptr_t n)
{ return (uintptr_t)((intptr_t)n & (-(uintptr_t)8U));
}
inline uintptr_t object_align_up(uintptr_t n)
{ return (uintptr_t)((n + sizeof(LispObject) - 1) &
 (-(uintptr_t)sizeof(LispObject)));
}
inline uintptr_t object_2_align_up(uintptr_t n)
{ return (uintptr_t)((n + 2*sizeof(LispObject) - 1) &
 (-(uintptr_t)2*sizeof(LispObject)));
}
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
#define HASH_AS_EQ 0
#define HASH_AS_EQL 1
#define HASH_AS_CL_EQUAL 2
#define HASH_AS_EQUAL 3
#define HASH_AS_EQUALP 4
#define HASH_AS_SYMBOL 5
#define HASH_AS_SXHASH 6
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern void interrupted(bool noisy);
[[noreturn]] extern void error(int nargs, int code, ...);
[[noreturn]] extern void cerror(int nargs, int code1, int code2, ...);
[[noreturn]] extern void got_0_wanted_1(LispObject env);
[[noreturn]] extern void got_0_wanted_2(LispObject env);
[[noreturn]] extern void got_0_wanted_3(LispObject env);
[[noreturn]] extern void got_0_wanted_4up(LispObject env);
[[noreturn]] extern void got_0_wanted_other(LispObject env);
[[noreturn]] extern void got_1_wanted_0(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_2(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_3(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_4up(LispObject env, LispObject a1);
[[noreturn]] extern void got_1_wanted_other(LispObject env, LispObject a1);
[[noreturn]] extern void got_2_wanted_0(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_1(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_3(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_4up(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_2_wanted_other(LispObject env, LispObject a1,
 LispObject a2);
[[noreturn]] extern void got_3_wanted_0(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_1(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_2(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_4up(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_3_wanted_other(LispObject env, LispObject a1,
 LispObject a2, LispObject a3);
[[noreturn]] extern void got_4up_wanted_0(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_1(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_2(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_3(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void got_4up_wanted_other(LispObject env, LispObject a1,
 LispObject a2, LispObject a3,
 LispObject a4up);
[[noreturn]] extern void bad_specialfn_0(LispObject env);
[[noreturn]] extern void bad_specialfn_2(LispObject env, LispObject, LispObject);
[[noreturn]] extern void bad_specialfn_3(LispObject env, LispObject, LispObject, LispObject);
[[noreturn]] extern void bad_specialfn_4up(LispObject env, LispObject, LispObject, LispObject, LispObject);
#define G0W1 ((no_args *)got_0_wanted_1)
#define G0W2 ((no_args *)got_0_wanted_2)
#define G0W3 ((no_args *)got_0_wanted_3)
#define G0W4up ((no_args *)got_0_wanted_4up)
#define G0Wother ((no_args *)got_0_wanted_other)
#define G1W0 ((one_arg *)got_1_wanted_0)
#define G1W2 ((one_arg *)got_1_wanted_2)
#define G1W3 ((one_arg *)got_1_wanted_3)
#define G1W4up ((one_arg *)got_1_wanted_4up)
#define G1Wother ((one_arg *)got_1_wanted_other)
#define G2W0 ((two_args *)got_2_wanted_0)
#define G2W1 ((two_args *)got_2_wanted_1)
#define G2W3 ((two_args *)got_2_wanted_3)
#define G2W4up ((two_args *)got_2_wanted_4up)
#define G2Wother ((two_args *)got_2_wanted_other)
#define G3W0 ((three_args *)got_3_wanted_0)
#define G3W1 ((three_args *)got_3_wanted_1)
#define G3W2 ((three_args *)got_3_wanted_2)
#define G3W4up ((three_args *)got_3_wanted_4up)
#define G3Wother ((three_args *)got_3_wanted_other)
#define G4W0 ((fourup_args *)got_4up_wanted_0)
#define G4W1 ((fourup_args *)got_4up_wanted_1)
#define G4W2 ((fourup_args *)got_4up_wanted_2)
#define G4W3 ((fourup_args *)got_4up_wanted_3)
#define G4Wother ((fourup_args *)got_4up_wanted_other)
#define BAD_SPECIAL_0 ((no_args *)bad_specialfn_0)
#define BAD_SPECIAL_2 ((two_args *)bad_specialfn_2)
#define BAD_SPECIAL_3 ((three_args *)bad_specialfn_3)
#define BAD_SPECIAL_4up ((fourup_args *)bad_specialfn_4up)
[[noreturn]] extern void aerror(const char *s); 
[[noreturn]] extern void aerror0(const char *s);
[[noreturn]] extern void aerror1(const char *s, LispObject a);
[[noreturn]] extern void aerror2(const char *s, LispObject a, LispObject b);
[[noreturn]] extern void aerror2(const char *s, const char *a, LispObject b);
[[noreturn]] extern void aerror3(const char *s, LispObject a, LispObject b, LispObject c);
[[noreturn]] extern void fatal_error(int code, ...);
extern LispObject carerror(LispObject a);
extern LispObject cdrerror(LispObject a);
[[noreturn]] extern void car_fails(LispObject a);
[[noreturn]] extern void cdr_fails(LispObject a);
[[noreturn]] extern void rplaca_fails(LispObject a);
[[noreturn]] extern void rplacd_fails(LispObject a);
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
#define err_undefined_function_4up 7 
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
 "undefined function (0 args)",
 "undefined function (1 arg)",
 "undefined function (2 args)",
 "undefined function (3 args)",
 "undefined function (4 or more args)",
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
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
extern size_t pages_count, heap_pages_count, vheap_pages_count;
extern size_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *nilsegmentbase, *stacksegmentbase;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern double max_store_size;
extern bool restartp;
extern char *big_chunk_start, *big_chunk_end;
extern uintptr_t *C_stackbase, C_stacklimit;
extern LispObject multiplication_buffer;
#ifdef CONSERVATIVE
extern void write_barrier(std::atomic<LispObject> *p);
extern void write_barrier(LispObject *p);
#else 
inline void write_barrier(std::atomic<LispObject> *p)
{}
inline void write_barrier(LispObject *p)
{}
#endif 
extern std::mutex debug_lock;
extern const char *debug_file;
extern int debug_line;
extern void DebugTrace();
extern void DebugTrace(int i);
extern void DebugTrace(const char *msg);
extern void DebugTrace(const char *fmt, int i);
#define Tr(...) \
 { std::lock_guard<std::mutex> lk(debug_lock); \
 debug_file = __FILE__; \
 debug_line = __LINE__; \
 DebugTrace(__VA_ARGS__); \
 }
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
inline void if_check_stack()
{ if (check_stack("@" __FILE__,__LINE__))
 { show_stack();
 aerror("stack overflow");
 }
}
#else
inline void if_check_stack()
{ const char *_p_ = (const char *)&_p_; \
 if ((uintptr_t)_p_ < C_stacklimit) aerror("stack overflow"); \
}
#endif
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
#define debug_record_string(s) debug_record((const char *)&celt(s, 0))
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
#define first_nil_offset 50 
#define work_0_offset 250
#define last_nil_offset 301
#define NIL_SEGMENT_SIZE (((1 + last_nil_offset) & ~1) * \
 sizeof(LispObject) + 32)
#define SPARE 512
#ifdef CONSERVATIVE
extern uintptr_t heapstart;
extern uintptr_t fringe;
extern uintptr_t heaplimit;
extern uintptr_t len;
extern uintptr_t xor_chain;
extern uintptr_t vheapstart;
extern uintptr_t vfringe;
extern uintptr_t vheaplimit;
extern uintptr_t vlen;
extern uintptr_t vxor_chain;
extern LispObject *stacklimit;
#else 
extern LispObject fringe, next_fringe;
extern LispObject heaplimit;
extern LispObject vfringe, next_vfringe;
extern LispObject vheaplimit;
extern LispObject *stacklimit;
#endif 
extern volatile std::atomic<uintptr_t> event_flag;
extern intptr_t nwork;
extern unsigned int exit_count;
extern uint64_t gensym_ser;
extern intptr_t print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol, apply_symbol;
extern LispObject list_symbol, liststar_symbol, eq_symbol, eql_symbol;
extern LispObject cl_equal_symbol, equal_symbol, equalp_symbol;
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
extern LispObject sys_hash_table, sxhash_hash_table;
extern LispObject help_index, cfunarg, lex_words;
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
#define mv_4 workbase[4]
#define work_50 workbase[50]
extern void copy_into_nilseg();
extern void copy_out_of_nilseg();
extern void rehash_this_table(LispObject v);
extern void simple_print(LispObject x);
extern void simple_msg(const char *s, LispObject x);
extern uint64_t hash_equal(LispObject key);
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
extern bool force_verbos, force_echo, force_backtrace;
extern bool stop_on_error;
extern uint64_t force_cons, force_vec;
extern size_t number_of_input_files,
 number_of_symbols_to_define,
 number_of_fasl_paths;
extern int init_flags;
extern const char *standard_directory;
extern int64_t gc_number;
extern int64_t reclaim_trap_count;
extern uintptr_t reclaim_stack_limit;
extern uint64_t reclaim_trigger_count, reclaim_trigger_target;
#ifdef CONSERVATIVE
extern void reclaim(const char *why);
#else
extern LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, size_t size);
#endif
extern void use_gchook(LispObject arg);
extern uint64_t force_cons, force_vec;
extern bool next_gc_is_hard;
inline bool cons_forced(size_t n)
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
inline bool vec_forced(size_t n)
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
{ one_arg *p;
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
typedef struct _entry_point4up
{ fourup_args *p;
 const char *s;
} entry_point4up;
extern entry_point0 entries_table0[];
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_point3 entries_table3[];
extern entry_point4up entries_table4up[];
extern entry_point1 entries_tableio[];
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject env, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
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
extern const char *CSLtmpnam(const char *suffix, size_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern void ensure_screen();
extern int window_heading;
[[noreturn]] extern void my_exit(int n);
extern uint64_t base_time;
extern std::chrono::high_resolution_clock::time_point base_walltime;
extern uint64_t gc_time;
extern bool trap_floating_overflow;
extern const volatile char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, bool findcatch);
extern bool segvtrap;
extern bool batch_flag;
extern int escaped_printing;
void set_up_signal_handlers();
extern int async_interrupt(int a);
extern void record_get(LispObject tag, bool found);
extern bool isprime(uint64_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern LispObject acons(LispObject a, LispObject b, LispObject c);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject acons_no_gc(LispObject a, LispObject b, LispObject c);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern uint32_t Crand();
extern LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a);
extern void discard(LispObject a);
extern bool eql_fn(LispObject a, LispObject b);
extern bool cl_equal_fn(LispObject a, LispObject b);
extern bool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern bool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern bool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, LispObject args, LispObject env,
 LispObject from);
extern LispObject apply_lambda(LispObject def, LispObject args,
 LispObject env, LispObject name);
extern void deallocate_pages();
extern void drop_heap_segments();
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
extern LispObject get(LispObject a, LispObject b, LispObject c=nil);
extern LispObject get_basic_vector(int tag, int type, size_t length);
extern LispObject get_basic_vector_init(size_t n, LispObject v);
extern LispObject reduce_basic_vector_size(LispObject v, size_t len);
extern LispObject get_vector(int tag, int type, size_t length);
extern LispObject get_vector_init(size_t n, LispObject v);
extern LispObject reduce_vector_size(LispObject n, size_t length);
extern void prepare_for_borrowing();
inline void zero_out(void *p)
{ char *p1 = (char *)doubleword_align_up((uintptr_t)p);
 memset(p1, 0, CSL_PAGE_SIZE);
}
extern LispObject borrow_basic_vector(int tag, int type, size_t length);
extern LispObject borrow_vector(int tag, int type, size_t length);
extern uint64_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern bool geq2(LispObject a, LispObject b);
extern bool greaterp2(LispObject a, LispObject b);
extern bool lesseq2(LispObject a, LispObject b);
extern bool lessp2(LispObject a, LispObject b);
extern LispObject list2(LispObject a, LispObject b);
extern LispObject list2star(LispObject a, LispObject b, LispObject c);
extern LispObject list2starrev(LispObject a, LispObject b, LispObject c);
extern LispObject list3(LispObject a, LispObject b, LispObject c);
extern LispObject list3rev(LispObject a, LispObject b, LispObject c);
extern LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, size_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 no_args *f0, one_arg *f1, two_args *f2,
 three_args *f3, fourup_args *f4up);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern LispObject nreverse2(LispObject a, LispObject b);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, size_t len);
extern LispObject prin(LispObject u);
extern void debugprint(LispObject a, int depth=10);
extern void debugprint(const char *s, LispObject a);
extern void debugprint(const char *s);
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
extern void print_newbignum(LispObject u, bool blankp, int nobreak);
extern void print_newbighexoctbin(LispObject u,
 int radix, int width, bool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject quotrem2(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern void set_fns(LispObject sym, no_args *f0, one_arg *f1,
 two_args *f2, three_args *f3, fourup_args *f4up);
extern void init_heap_segments(double size);
extern void grab_more_memory(size_t npages);
extern bool allocate_more_memory();
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
extern uint32_t thirty_two_bits_unsigned(LispObject a);
extern int64_t sixty_four_bits(LispObject a);
extern uint64_t sixty_four_bits_unsigned(LispObject a);
extern uint64_t crc64(uint64_t crc, const void *buf, size_t size);
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
inline LispObject onevalue(LispObject r)
{ exit_count = 1;
 return r;
}
inline LispObject nvalues(LispObject r, int n)
{ exit_count = n;
 return r;
}
inline bool equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return equal_fn(a, b);
 else return false;
}
inline bool cl_equal(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return cl_equal_fn(a, b);
 else return false;
}
inline bool eql(LispObject a, LispObject b)
{ if (a == b) return true; 
 else if ((a & TAG_BITS) != (b & TAG_BITS)) return false;
 else if (need_more_than_eq(a)) return eql_fn(a, b);
 else return false;
}
extern no_args *no_arg_functions[];
extern one_arg *one_arg_functions[];
extern two_args *two_arg_functions[];
extern three_args *three_arg_functions[];
extern fourup_args *fourup_arg_functions[];
extern bool no_arg_traceflags[];
extern bool one_arg_traceflags[];
extern bool two_arg_traceflags[];
extern bool three_arg_traceflags[];
extern bool fourup_arg_traceflags[];
extern const char *no_arg_names[];
extern const char *one_arg_names[];
extern const char *two_arg_names[];
extern const char *three_arg_names[];
extern const char *fourup_arg_names[];
typedef struct setup_type
{ const char *name;
 no_args *zero;
 one_arg *one;
 two_args *two;
 three_args *three;
 fourup_args *fourup;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 no_args *zero;
 one_arg *one;
 two_args *two;
 three_args *three;
 fourup_args *fourup;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
 arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 lisphash_setup[], print_setup[], read_setup[],
 restart_setup[], mpi_setup[];
#ifdef ARITHLIB
extern setup_type const arith_setup[];
#endif
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
[[noreturn]] extern void resource_exceeded();
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
#define clear_top_bit(n) ((int32_t)((uint32_t)(n) & 0x7fffffff))
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
#ifdef HAVE_SOFTFLOAT
#define FIX_TRUNCATE softfloat_round_minMag
#define FIX_ROUND softfloat_round_near_even
#define FIX_FLOOR softfloat_round_min
#define FIX_CEILING softfloat_round_max
#else
#define FIX_TRUNCATE 1
#define FIX_ROUND 0
#define FIX_FLOOR 2
#define FIX_CEILING 3
#endif 
extern LispObject lisp_fix(LispObject a, int roundmode);
extern LispObject lisp_ifix(LispObject a, LispObject b, int roundmode);
inline bool floating_edge_case(double r)
{ return (1.0/r == 0.0 || r != r);
}
inline void floating_clear_flags()
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
inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (int32_t)((uint64_t)a>>32);
 else aa.i = (int32_t)(a - XTAG_SFLOAT);
 return aa.f;
}
extern LispObject make_boxfloat(double a, int type=TYPE_DOUBLE_FLOAT);
#ifdef HAVE_SOFTFLOAT
extern LispObject make_boxfloat128(float128_t a);
#endif 
inline LispObject pack_short_float(double d)
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
inline LispObject pack_single_float(double d)
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
 { LispObject r = get_basic_vector(TAG_BOXFLOAT,
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
inline LispObject pack_immediate_float(double d,
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
inline bool eq_i64d(int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((uint64_t)1<<63)) return false;
 return a == (int64_t)b;
}
inline bool lessp_i64d(int64_t a, double b)
{
 if (a <= ((int64_t)1<<53) &&
 a >= -((int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((uint64_t)1<<63))) return false;
 if (!(b < (double)((uint64_t)1<<63))) return true;
 return a < (int64_t)b;
}
inline bool lessp_di64(double a, int64_t b)
{
 if (b <= ((int64_t)1<<53) &&
 b >= -((int64_t)1<<53)) return a < (double)b;
 if (!(a < (double)((uint64_t)1<<63))) return false;
 if (!(a >= -(double)((uint64_t)1<<63))) return true;
 return (int64_t)a < b;
}
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern LispObject quotbb(LispObject a, LispObject b, int needs);
extern LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, size_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern bool numeq2(LispObject a, LispObject b);
extern bool SL_numeq2(LispObject a, LispObject b);
extern bool zerop(LispObject a);
extern bool onep(LispObject a);
extern bool minusp(LispObject a);
extern bool plusp(LispObject a);
extern LispObject integer_decode_long_float(LispObject a);
extern LispObject Linteger_decode_float(LispObject env, LispObject a);
extern LispObject validate_number(const char *s, LispObject a,
 LispObject b, LispObject c);
extern LispObject make_fake_bignum(intptr_t n);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_four_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d);
extern LispObject make_five_word_bignum(int32_t a, uint32_t b,
 uint32_t c, uint32_t d, uint32_t e);
extern LispObject make_n_word_bignum(int32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_n4_word_bignum(int32_t a3, uint32_t a2,
 uint32_t a1, uint32_t a0, size_t n);
extern LispObject make_n5_word_bignum(int32_t a4, uint32_t a3,
 uint32_t a2, uint32_t a1,
 uint32_t a0, size_t n);
extern LispObject make_power_of_two(size_t n);
extern LispObject make_lisp_integer32_fn(int32_t n);
inline LispObject make_lisp_integer32(int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(int64_t n);
inline LispObject make_lisp_integer64(int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(uint64_t n);
inline LispObject make_lisp_unsigned64(uint64_t n)
{ if (n < ((uint64_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(intptr_t n);
inline LispObject make_lisp_integerptr(intptr_t n)
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(uintptr_t n);
inline LispObject make_lisp_unsignedptr(uintptr_t n)
{ if (n < ((uintptr_t)1)<<(8*sizeof(intptr_t)-5))
 return fixnum_of_int((intptr_t)n);
 else return make_lisp_unsignedptr_fn(n);
}
extern LispObject make_lisp_integer128_fn(int128_t n);
inline LispObject make_lisp_integer128(int128_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int(NARROW128(n));
 else return make_lisp_integer128_fn(n);
}
extern LispObject make_lisp_unsigned128_fn(uint128_t n);
inline LispObject make_lisp_unsigned128(uint128_t n)
{ if (uint128_valid_as_fixnum(n))
 return fixnum_of_int((uint64_t)NARROW128(n));
 else return make_lisp_unsigned128_fn(n);
}
inline void validate_number(LispObject n)
{
}
extern double float_of_integer(LispObject a);
extern LispObject add1(LispObject p);
extern LispObject sub1(LispObject p);
extern LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
#ifdef HAVE_SOFTFLOAT
extern float128_t float128_of_number(LispObject a);
#endif 
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern LispObject make_approx_ratio(LispObject p, LispObject q, int bits);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
#ifdef HAVE_SOFTFLOAT
extern LispObject rationalf128(float128_t *d);
#endif 
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
#ifndef HAVE_CILK
extern std::thread kara_thread[2];
#define KARA_0 (1<<0)
#define KARA_1 (1<<1)
#define KARA_QUIT (1<<2)
extern void kara_worker(int id);
extern std::mutex kara_mutex;
extern std::condition_variable cv_kara_ready,
 cv_kara_done;
extern unsigned int kara_ready;
extern int kara_done;
#endif
extern size_t kparallel, karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#ifdef HAVE_SOFTFLOAT
static int f128M_exponent(const float128_t *p);
static void f128M_set_exponent(float128_t *p, int n);
extern void f128M_ldexp(float128_t *p, int n);
extern void f128M_frexp(float128_t *p, float128_t *r, int *x);
static bool f128M_infinite(const float128_t *p);
static bool f128M_finite(const float128_t *p);
static bool f128M_nan(const float128_t *x);
static bool f128M_subnorm(const float128_t *x);
static bool f128M_negative(const float128_t *x);
static void f128M_negate(float128_t *x);
extern void f128M_split(
 const float128_t *x, float128_t *yhi, float128_t *ylo);
#ifdef LITTLEENDIAN
#define HIPART 1
#define LOPART 0
#else
#define HIPART 0
#define LOPART 1
#endif
inline bool f128M_zero(const float128_t *p)
{ return ((p->v[HIPART] & INT64_C(0x7fffffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
inline bool f128M_infinite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 ((p->v[HIPART] & INT64_C(0xffffffffffff)) == 0) &&
 (p->v[LOPART] == 0);
}
inline bool f128M_finite(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) != 0x7fff);
}
inline void f128M_make_infinite(float128_t *p)
{ p->v[HIPART] |= UINT64_C(0x7fff000000000000);
 p->v[HIPART] &= UINT64_C(0xffff000000000000);
 p->v[LOPART] = 0;
}
inline void f128M_make_zero(float128_t *p)
{ p->v[HIPART] &= UINT64_C(0x8000000000000000);
 p->v[LOPART] = 0;
}
inline bool f128M_subnorm(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
inline bool f128M_nan(const float128_t *p)
{ return (((p->v[HIPART] >> 48) & 0x7fff) == 0x7fff) &&
 (((p->v[HIPART] & INT64_C(0xffffffffffff)) != 0) ||
 (p->v[LOPART] != 0));
}
inline bool f128M_negative(const float128_t *x)
{ if (f128M_nan(x)) return false;
 return ((int64_t)x->v[HIPART]) < 0;
}
inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((uint64_t)n + 0x3fff) << 48);
}
inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
#endif 
extern int double_to_binary(double d, int64_t &m);
#ifdef HAVE_SOFTFLOAT
extern int float128_to_binary(const float128_t *d,
 int64_t &mhi, uint64_t &mlo);
#endif 
extern intptr_t double_to_3_digits(double d,
 int32_t &a2, uint32_t &a1, uint32_t &a0);
#ifdef HAVE_SOFTFLOAT
extern intptr_t float128_to_5_digits(float128_t *d,
 int32_t &a4, uint32_t &a3, uint32_t &a2, uint32_t &a1, uint32_t &a0);
extern float128_t f128_0, 
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
inline void f128M_to_f256M(const float128_t *a, float256_t *b)
{ b->hi = *a;
 b->lo = f128_0;
} 
extern void f256M_add(
 const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_mul(
 const float256_t *x, const float256_t *y, float256_t *z);
extern void f256M_pow(const float256_t *x, unsigned int y, float256_t *z);
extern float256_t f256_1, f256_10, f256_r10, f256_5, f256_r5;
extern int f128M_sprint_E(char *s, int width, int precision, float128_t *p);
extern int f128M_sprint_F(char *s, int width, int precision, float128_t *p);
extern int f128M_sprint_G(char *s, int width, int precision, float128_t *p);
extern int f128M_print_E(int width, int precision, float128_t *p);
extern int f128M_print_F(int width, int precision, float128_t *p);
extern int f128M_print_G(int width, int precision, float128_t *p);
extern float128_t atof128(const char *s);
#endif 
#ifdef HAVE_SOFTFLOAT
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
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
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0) \
 return name##_f(a1); \
 else return name##_s(a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
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
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a2 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(inline, type, name##_i, name) \
 \
arith_dispatch_1a(inline, type, name##_b, name) \
 \
arith_dispatch_1a(inline, type, name##_r, name) \
 \
arith_dispatch_1a(inline, type, name##_c, name) \
 \
arith_dispatch_1a(inline, type, name##_s, name) \
 \
arith_dispatch_1a(inline, type, name##_f, name) \
 \
arith_dispatch_1a(inline, type, name##_d, name) \
 \
arith_dispatch_1a(inline, type, name##_l, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
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
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#else 
#define arith_dispatch_1(stgclass, type, name) \
stgclass type name(LispObject a1) \
{ if (is_fixnum(a1)) return name##_i(a1); \
 switch (a1 & TAG_BITS) \
 { \
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
 default: \
 aerror1("bad arg for " #name, a1); \
 } \
 default: \
 aerror1("bad arg for " #name, a1); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1); \
 else return name##_s(a1); \
 } \
}
#define arith_dispatch_1a(stgclass, type, name, rawname) \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a2)) return name##_i(a1, a2); \
 switch (a2 & TAG_BITS) \
 { \
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
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #rawname, a1, a2); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a2 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#define arith_dispatch_2(stgclass, type, name) \
arith_dispatch_1a(inline, type, name##_i, name) \
 \
arith_dispatch_1a(inline, type, name##_b, name) \
 \
arith_dispatch_1a(inline, type, name##_r, name) \
 \
arith_dispatch_1a(inline, type, name##_c, name) \
 \
arith_dispatch_1a(inline, type, name##_s, name) \
 \
arith_dispatch_1a(inline, type, name##_f, name) \
 \
arith_dispatch_1a(inline, type, name##_d, name) \
 \
stgclass type name(LispObject a1, LispObject a2) \
{ if (is_fixnum(a1)) return name##_i(a1, a2); \
 switch (a1 & TAG_BITS) \
 { \
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
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 } \
 default: \
 aerror2("bad arg for " #name, a1, a2); \
 case (XTAG_SFLOAT & TAG_BITS): \
 if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0)) \
 return name##_f(a1, a2); \
 else return name##_s(a1, a2); \
 } \
}
#endif 
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern LispObject Lbatchp(LispObject env);
extern LispObject Ldate(LispObject env);
extern LispObject Ldatestamp(LispObject env);
extern LispObject Leject(LispObject env);
[[noreturn]] extern void Lerror_0(LispObject env);
extern LispObject Lall_symbols0(LispObject env);
extern LispObject Lflush(LispObject env);
extern LispObject Lgc0(LispObject env);
extern LispObject Lgctime(LispObject env);
extern LispObject Lgensym(LispObject env);
extern LispObject Llist_modules(LispObject env);
extern LispObject Llibrary_members0(LispObject env);
extern LispObject Lload_source0(LispObject env);
extern LispObject Lload_selected_source0(LispObject env);
extern LispObject Lload_spid(LispObject);
extern LispObject Llposn(LispObject env);
extern LispObject Lmapstore0(LispObject env);
extern LispObject Lnext_random(LispObject env);
extern LispObject Lnilfn(LispObject env);
extern LispObject Lposn(LispObject env);
extern LispObject Lread(LispObject env);
extern LispObject Lreadch(LispObject env);
extern LispObject Lrtell(LispObject env);
extern LispObject Lterpri(LispObject env);
extern LispObject Ltime(LispObject env);
extern LispObject Ltmpnam(LispObject env);
extern LispObject Ltyi(LispObject env);
extern LispObject Lunserialize(LispObject env);
extern LispObject autoload_0(LispObject env);
extern LispObject bytecoded_0(LispObject env);
extern LispObject Lbytecounts_0(LispObject env);
extern LispObject byteopt_0(LispObject def);
extern LispObject byteoptrest_0(LispObject def);
extern LispObject funarged_0(LispObject env);
extern LispObject tracefunarged_0(LispObject env);
extern LispObject hardopt_0(LispObject def);
extern LispObject hardoptrest_0(LispObject def);
extern LispObject interpreted_0(LispObject env);
extern LispObject tracebytecoded_0(LispObject env);
extern LispObject tracebyteopt_0(LispObject def);
extern LispObject tracebyteoptrest_0(LispObject def);
extern LispObject tracebytecoded_0(LispObject env);
extern LispObject traceinterpreted_0(LispObject env);
extern LispObject tracehardopt_0(LispObject def);
extern LispObject tracehardoptrest_0(LispObject def);
extern LispObject undefined_0(LispObject env);
extern LispObject f0_as_0(LispObject env);
extern LispObject autoload_1(LispObject env, LispObject a);
extern LispObject bytecoded_1(LispObject env, LispObject a);
extern LispObject Lbytecounts_1(LispObject env, LispObject a);
extern LispObject byteopt_1(LispObject def, LispObject a);
extern LispObject byteoptrest_1(LispObject def, LispObject a);
extern LispObject funarged_1(LispObject env, LispObject a1);
extern LispObject tracefunarged_1(LispObject env, LispObject a1);
extern LispObject hardopt_1(LispObject def, LispObject a);
extern LispObject hardoptrest_1(LispObject def, LispObject a);
extern LispObject interpreted_1(LispObject env, LispObject a1);
extern LispObject tracebytecoded_1(LispObject env, LispObject a);
extern LispObject tracebyteopt_1(LispObject def, LispObject a);
extern LispObject tracebyteoptrest_1(LispObject def, LispObject a);
extern LispObject tracebytecoded_1(LispObject env, LispObject a);
extern LispObject traceinterpreted_1(LispObject env, LispObject a1);
extern LispObject tracehardopt_1(LispObject def, LispObject a);
extern LispObject tracehardoptrest_1(LispObject def, LispObject a);
extern LispObject undefined_1(LispObject env, LispObject a1);
extern LispObject f1_as_0(LispObject env, LispObject a);
extern LispObject f1_as_1(LispObject env, LispObject a);
extern LispObject Labsval(LispObject env, LispObject a);
extern LispObject Ladd1(LispObject env, LispObject a);
extern LispObject Lalpha_char_p(LispObject env, LispObject a);
extern LispObject Lall_symbols(LispObject env, LispObject a1);
extern LispObject Lapply0(LispObject env, LispObject a);
extern LispObject Lapply_1(LispObject env, LispObject fn);
extern LispObject Latan(LispObject env, LispObject a);
extern LispObject Latom(LispObject env, LispObject a);
extern LispObject Lbanner(LispObject env, LispObject a);
extern LispObject Lboundp(LispObject env, LispObject a);
extern LispObject Lbpsp(LispObject env, LispObject a);
extern LispObject Lbpsupbv(LispObject env, LispObject v);
extern LispObject Lcaaaar(LispObject env, LispObject a);
extern LispObject Lcaaadr(LispObject env, LispObject a);
extern LispObject Lcaaar(LispObject env, LispObject a);
extern LispObject Lcaadar(LispObject env, LispObject a);
extern LispObject Lcaaddr(LispObject env, LispObject a);
extern LispObject Lcaadr(LispObject env, LispObject a);
extern LispObject Lcaar(LispObject env, LispObject a);
extern LispObject Lcaar(LispObject env, LispObject a);
extern LispObject Lcadaar(LispObject env, LispObject a);
extern LispObject Lcadadr(LispObject env, LispObject a);
extern LispObject Lcadar(LispObject env, LispObject a);
extern LispObject Lcaddar(LispObject env, LispObject a);
extern LispObject Lcadddr(LispObject env, LispObject a);
extern LispObject Lcaddr(LispObject env, LispObject a);
extern LispObject Lcadr(LispObject env, LispObject a);
extern LispObject Lcadr(LispObject env, LispObject a);
extern LispObject Lcar(LispObject env, LispObject a);
extern LispObject Lcar(LispObject env, LispObject a);
extern LispObject Lcdaaar(LispObject env, LispObject a);
extern LispObject Lcdaadr(LispObject env, LispObject a);
extern LispObject Lcdaar(LispObject env, LispObject a);
extern LispObject Lcdadar(LispObject env, LispObject a);
extern LispObject Lcdaddr(LispObject env, LispObject a);
extern LispObject Lcdadr(LispObject env, LispObject a);
extern LispObject Lcdar(LispObject env, LispObject a);
extern LispObject Lcdar(LispObject env, LispObject a);
extern LispObject Lcddaar(LispObject env, LispObject a);
extern LispObject Lcddadr(LispObject env, LispObject a);
extern LispObject Lcddar(LispObject env, LispObject a);
extern LispObject Lcdddar(LispObject env, LispObject a);
extern LispObject Lcddddr(LispObject env, LispObject a);
extern LispObject Lcdddr(LispObject env, LispObject a);
extern LispObject Lcddr(LispObject env, LispObject a);
extern LispObject Lcddr(LispObject env, LispObject a);
extern LispObject Lcdr(LispObject env, LispObject a);
extern LispObject Lcdr(LispObject env, LispObject a);
extern LispObject Lchar_code(LispObject env, LispObject a);
extern LispObject Lclose(LispObject env, LispObject a);
extern LispObject Lcodep(LispObject env, LispObject a);
extern LispObject Lcompress(LispObject env, LispObject a);
extern LispObject Lconsp(LispObject env, LispObject a);
extern LispObject Lconstantp(LispObject env, LispObject a);
extern LispObject Lcopy_module(LispObject env, LispObject a);
extern LispObject Ldefine_in_module(LispObject env, LispObject a);
extern LispObject Ldelete_module(LispObject env, LispObject a);
extern LispObject Ldigitp(LispObject env, LispObject a);
extern LispObject Lendp(LispObject env, LispObject a);
[[noreturn]] extern void Lerror_1(LispObject env, LispObject a1);
extern LispObject Lerrorset_1(LispObject env, LispObject form);
extern LispObject Leval(LispObject env, LispObject a);
extern LispObject Levenp(LispObject env, LispObject a);
extern LispObject Levlis(LispObject env, LispObject a);
extern LispObject Lexplode(LispObject env, LispObject a);
extern LispObject Lexplode2lc(LispObject env, LispObject a);
extern LispObject Lexplode2lcn(LispObject env, LispObject a);
extern LispObject Lexplode2n(LispObject env, LispObject a);
extern LispObject Lexplodec(LispObject env, LispObject a);
extern LispObject Lexplodecn(LispObject env, LispObject a);
extern LispObject Lexplodehex(LispObject env, LispObject a);
extern LispObject Lexploden(LispObject env, LispObject a);
extern LispObject Lexplodeoctal(LispObject env, LispObject a);
extern LispObject Lfixp(LispObject env, LispObject a);
extern LispObject Lfloat(LispObject env, LispObject a);
extern LispObject Lfloatp(LispObject env, LispObject a);
extern LispObject Lfrexp(LispObject env, LispObject a);
extern LispObject Lfuncall_1(LispObject env, LispObject fn);
extern LispObject Lgc(LispObject env, LispObject a);
extern LispObject Lgc_forcer1(LispObject env, LispObject a);
extern LispObject Lgensym0(LispObject env, LispObject a, const char *s);
extern LispObject Lgensym1(LispObject env, LispObject a);
extern LispObject Lgensym2(LispObject env, LispObject a);
extern LispObject Lgetd(LispObject env, LispObject a);
extern LispObject Lgetenv(LispObject env, LispObject a);
extern LispObject Lget_bps(LispObject env, LispObject a);
extern LispObject Liadd1(LispObject env, LispObject a);
extern LispObject Lidentity(LispObject env, LispObject a);
extern LispObject Liminus(LispObject env, LispObject a);
extern LispObject Liminusp(LispObject env, LispObject a);
extern LispObject Lindirect(LispObject env, LispObject a);
extern LispObject Lintegerp(LispObject env, LispObject a);
extern LispObject Lintern(LispObject env, LispObject a);
extern LispObject Lionep(LispObject env, LispObject a);
extern LispObject Lis_spid(LispObject env, LispObject a);
extern LispObject Lisub1(LispObject env, LispObject a);
extern LispObject Lizerop(LispObject env, LispObject a);
extern LispObject Llength(LispObject env, LispObject a);
extern LispObject Llengthc(LispObject env, LispObject a);
extern LispObject Llibrary_members(LispObject env, LispObject a);
extern LispObject Llinelength(LispObject env, LispObject a);
extern LispObject Llist_to_string(LispObject env, LispObject a);
extern LispObject Llist_to_vector(LispObject env, LispObject a);
extern LispObject Lload_module(LispObject env, LispObject a);
extern LispObject Lload_source(LispObject env, LispObject a);
extern LispObject Lload_selected_source(LispObject env, LispObject a);
extern LispObject Llognot(LispObject env, LispObject a);
extern LispObject Llog_1(LispObject env, LispObject a);
extern LispObject Llsd(LispObject env, LispObject a);
extern LispObject Lmacroexpand(LispObject env, LispObject a);
extern LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern LispObject Lmacro_function(LispObject env, LispObject a);
extern LispObject Lmake_global(LispObject env, LispObject a);
extern LispObject Lmake_keyword(LispObject env, LispObject a);
extern LispObject Lmake_special(LispObject env, LispObject a);
extern LispObject Lmapstore(LispObject env, LispObject a);
extern LispObject Lmd5(LispObject env, LispObject a1);
extern LispObject Lmd60(LispObject env, LispObject a1);
extern LispObject Lminus(LispObject env, LispObject a);
extern LispObject Lminusp(LispObject env, LispObject a);
extern LispObject Lmkevect(LispObject env, LispObject n);
extern LispObject Lmkhash_1(LispObject env, LispObject a);
extern LispObject Lmkhashset(LispObject env, LispObject a);
extern LispObject Lmkquote(LispObject env, LispObject a);
extern LispObject Lmkvect(LispObject env, LispObject a);
extern LispObject Lmodular_minus(LispObject env, LispObject a);
extern LispObject Lmodular_number(LispObject env, LispObject a);
extern LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern LispObject Lmodule_exists(LispObject env, LispObject a);
extern LispObject Lmsd(LispObject env, LispObject a);
extern LispObject Lmv_list(LispObject env, LispObject a);
extern LispObject Lncons(LispObject env, LispObject a);
extern LispObject Lnreverse(LispObject env, LispObject a);
extern LispObject Lnull(LispObject env, LispObject a);
extern LispObject Lnumberp(LispObject env, LispObject a);
extern LispObject Loddp(LispObject env, LispObject a);
extern LispObject Lonep(LispObject env, LispObject a);
extern LispObject Lpagelength(LispObject env, LispObject a);
extern LispObject Lplist(LispObject env, LispObject a);
extern LispObject Lplusp(LispObject env, LispObject a);
extern LispObject Lprin(LispObject env, LispObject a);
extern LispObject Lprin(LispObject env, LispObject a);
extern LispObject Lprin2a(LispObject env, LispObject a);
extern LispObject Lprinc(LispObject env, LispObject a);
extern LispObject Lprinc(LispObject env, LispObject a);
extern LispObject Lprint(LispObject env, LispObject a);
extern LispObject Lprintc(LispObject env, LispObject a);
extern LispObject Lrandom_1(LispObject env, LispObject a);
extern LispObject Lrational(LispObject env, LispObject a);
extern LispObject Lrdf1(LispObject env, LispObject a);
extern LispObject Lrds(LispObject env, LispObject a);
extern LispObject Lremd(LispObject env, LispObject a);
extern LispObject Lrepresentation1(LispObject env, LispObject a);
extern LispObject Lreverse(LispObject env, LispObject a);
extern LispObject Lserialize(LispObject env, LispObject a);
extern LispObject Lserialize1(LispObject env, LispObject a);
extern LispObject Lsetpchar(LispObject env, LispObject a);
extern LispObject Lset_small_modulus(LispObject env, LispObject a);
extern LispObject Lsmkvect(LispObject env, LispObject a);
extern LispObject Lspecial_char(LispObject env, LispObject a);
extern LispObject Lspecial_form_p(LispObject env, LispObject a);
extern LispObject Lspid_to_nil(LispObject env, LispObject a);
extern LispObject Lspool(LispObject env, LispObject a);
extern LispObject Lstart_module(LispObject env, LispObject a);
[[noreturn]] extern void Lstop1(LispObject env, LispObject a);
extern LispObject Lstringp(LispObject env, LispObject a);
extern LispObject Lsub1(LispObject env, LispObject a);
extern LispObject Lsymbolp(LispObject env, LispObject a);
extern LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern LispObject Lsymbol_env(LispObject env, LispObject a);
extern LispObject Lsymbol_function(LispObject env, LispObject a);
extern LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern LispObject Lsymbol_name(LispObject env, LispObject a);
extern LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern LispObject Lsymbol_value(LispObject env, LispObject a);
extern LispObject Lsystem(LispObject env, LispObject a);
extern LispObject Lthreevectorp(LispObject env, LispObject a);
extern LispObject Lthrow_nil(LispObject env, LispObject a);
extern LispObject Ltrace(LispObject env, LispObject a);
extern LispObject Ltruncate(LispObject env, LispObject a);
extern LispObject Lttab(LispObject env, LispObject a);
extern LispObject Ltyo(LispObject env, LispObject a);
extern LispObject Lunintern(LispObject env, LispObject a);
extern LispObject Lunmake_global(LispObject env, LispObject a);
extern LispObject Lunmake_keyword(LispObject env, LispObject a);
extern LispObject Lunmake_special(LispObject env, LispObject a);
extern LispObject Luntrace(LispObject env, LispObject a);
extern LispObject Lupbv(LispObject env, LispObject a);
extern LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern LispObject Lvectorp(LispObject env, LispObject a);
extern LispObject Lverbos(LispObject env, LispObject a);
extern LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern LispObject Lwrs(LispObject env, LispObject a);
extern LispObject Lxtab(LispObject env, LispObject a);
extern LispObject Lxtab(LispObject env, LispObject a);
extern LispObject Lzerop(LispObject env, LispObject a);
extern LispObject Lfind_symbol_1(LispObject env, LispObject str);
extern LispObject Llistp(LispObject env, LispObject a);
extern LispObject autoload_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject bytecoded_2(LispObject env, LispObject a, LispObject b);
extern LispObject byteopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject byteoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject funarged_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracefunarged_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject hardopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject hardoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject interpreted_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracebyteopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracebyteoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracebytecoded_2(LispObject env, LispObject a, LispObject b);
extern LispObject traceinterpreted_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject tracehardopt_2(LispObject def, LispObject a, LispObject b);
extern LispObject tracehardoptrest_2(LispObject def, LispObject a, LispObject b);
extern LispObject undefined_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lappend_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern LispObject Lash(LispObject env, LispObject a, LispObject b);
extern LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern LispObject Lbpsgetv(LispObject env, LispObject v, LispObject n);
extern LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern LispObject Ldifference_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ldivide_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern LispObject Leq(LispObject env, LispObject a, LispObject b);
extern LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern LispObject Leql(LispObject env, LispObject a, LispObject b);
extern LispObject Leqn_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern LispObject Lequal(LispObject env, LispObject a, LispObject b);
[[noreturn]] extern void Lerror_2(LispObject env, LispObject a1, LispObject a2);
extern LispObject Lerrorset_2(LispObject env, LispObject form, LispObject ffg1);
extern LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern LispObject Lfuncall_2(LispObject env, LispObject fn, LispObject a1);
extern LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b);
extern LispObject Lgcd_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lgeq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lget(LispObject env, LispObject a, LispObject b);
extern LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern LispObject Lgreaterp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lidifference_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ligeq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ligreaterp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lileq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lilessp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Limax_2(LispObject env, LispObject a, LispObject b);
extern LispObject Limin_2(LispObject env, LispObject a, LispObject b);
extern LispObject Linorm(LispObject env, LispObject a, LispObject k);
extern LispObject Lintersect(LispObject env, LispObject a, LispObject b);
extern LispObject Lintersect_symlist(LispObject env, LispObject a, LispObject b);
extern LispObject Liplus_2(LispObject env, LispObject a, LispObject b);
extern LispObject Liquotient_2(LispObject env, LispObject a, LispObject b);
extern LispObject Liremainder_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern LispObject Litimes_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llcm_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lleq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llessp_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llist_2(LispObject env, LispObject a, LispObject b);
extern LispObject Llog(LispObject env, LispObject a, LispObject b);
extern LispObject Llog_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern LispObject Lmax_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern LispObject Lmin_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmkhash_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmod_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern LispObject Lneq_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern LispObject Lpair(LispObject env, LispObject a, LispObject b);
extern LispObject Lplus_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lquotient_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrem_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern LispObject Lrepresentation2(LispObject env, LispObject a, LispObject b);
extern LispObject Lresource_limit_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern LispObject Lrseek(LispObject env, LispObject a);
extern LispObject Lset(LispObject env, LispObject a, LispObject b);
extern LispObject Lset_help_file(LispObject env, LispObject a, LispObject b);
extern LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
[[noreturn]] extern void Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern LispObject Ltimes_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lunion(LispObject env, LispObject a, LispObject b);
extern LispObject Lunion_symlist(LispObject env, LispObject a, LispObject b);
extern LispObject Lwrite_module(LispObject env, LispObject a, LispObject b);
extern LispObject Lxcons(LispObject env, LispObject a, LispObject b);
extern LispObject Laref_2(LispObject env, LispObject a, LispObject b);
extern LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern LispObject Lfloat_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lrandom_2(LispObject env, LispObject a, LispObject b);
extern LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
extern LispObject f3_as_0(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_1(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_2(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject f3_as_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lapply_3(LispObject env, LispObject fn, LispObject a1, LispObject a2);
extern LispObject Lapply2(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lacons(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Laref_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Laset_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Lbpsputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
[[noreturn]] extern void Lerror_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lerrorset_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject Lfuncall_3(LispObject env, LispObject fn, LispObject a1, LispObject a2);
extern LispObject Llist_2star(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Llist_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lput_hash(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lputprop(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lresource_limit_3(LispObject env, LispObject a, LispObject b, LispObject c);
extern LispObject Lsputv(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lsubst(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lget_3(LispObject env, LispObject a1, LispObject a2, LispObject a3);
extern LispObject Lmkhash_3(LispObject env, LispObject a, LispObject b, LispObject c);
extern LispObject autoload_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject bytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject byteopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject byteoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject funarged_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracefunarged_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject hardopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject hardoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject interpreted_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracebytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracebyteopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracebyteoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracebytecoded_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject traceinterpreted_3(LispObject env, LispObject, LispObject, LispObject);
extern LispObject tracehardopt_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject tracehardoptrest_3(LispObject def, LispObject, LispObject, LispObject);
extern LispObject undefined_3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3);
extern LispObject autoload_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject bytecoded_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject byteopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject byteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject funarged_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracefunarged_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject hardopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject hardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject interpreted_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebyteopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebyteoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebytecoded0(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracebytecoded_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject traceinterpreted_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracehardopt_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject tracehardoptrest_4up(LispObject def, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject undefined_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lapply_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lapply3(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
[[noreturn]] extern void Lerror_34up(LispObject env, LispObject a1, LispObject a2, LispObject a3, LispObject a4up);
extern LispObject Lerrorset_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lfuncall_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llist_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lliststar_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogand_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogeqv_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogor_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llogxor_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lmax_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lmin_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lresource_limit_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lvalues_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lappend_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Laref_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Laset_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Leqn_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgcd_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgeq_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lgreaterp_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llcm_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lleq_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Llessp_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject Lquotient_4up(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_openStringDev(LispObject env, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject env, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject env, LispObject ltimeout);
extern LispObject om_closeConn(LispObject env, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject env, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject env, LispObject lconn);
extern LispObject om_connectTCP(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
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
extern LispObject om_putSymbol2(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
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
extern LispObject om_listCDs(LispObject env, LispObject a1, LispObject a2,
 LispObject a3, LispObject a4up);
extern LispObject om_listSymbols(LispObject env, LispObject lcd);
extern LispObject om_whichCDs(LispObject env, LispObject lsym);
#endif
extern LispObject undefined_4up(LispObject env,
 LispObject a1, LispObject a2, LispObject a3, LispObject a4);
#endif 
#ifndef __lispthrow_h
#define __lispthrow_h 1
extern LispObject *stack;
extern jmp_buf *global_jb;
inline void push(LispObject a)
{ *++stack = a;
}
inline void push2(LispObject a, LispObject b)
{ *++stack = a;
 *++stack = b;
}
inline void push3(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
}
inline void push4(LispObject a, LispObject b, LispObject c,
 LispObject d)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
}
inline void push5(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
}
inline void push6(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
 *++stack = f;
}
inline void push(LispObject a, LispObject b)
{ *++stack = a;
 *++stack = b;
}
inline void push(LispObject a, LispObject b, LispObject c)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
}
inline void push(LispObject a, LispObject b, LispObject c, LispObject d)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
}
inline void push(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
}
inline void push(LispObject a, LispObject b, LispObject c,
 LispObject d, LispObject e, LispObject f)
{ *++stack = a;
 *++stack = b;
 *++stack = c;
 *++stack = d;
 *++stack = e;
 *++stack = f;
}
inline void pop(LispObject& a)
{ a = *stack--;
}
inline void pop(volatile LispObject& a)
{ a = *stack--;
}
inline void pop2(LispObject& a, LispObject& b)
{ a = *stack--;
 b = *stack--;
}
inline void pop3(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
}
inline void pop4(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
}
inline void pop5(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
}
inline void pop6(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
 f = *stack--;
}
inline void pop(LispObject& a, LispObject& b)
{ a = *stack--;
 b = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c, LispObject& d)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
}
inline void pop(LispObject& a, LispObject& b, LispObject& c,
 LispObject& d, LispObject& e, LispObject& f)
{ a = *stack--;
 b = *stack--;
 c = *stack--;
 d = *stack--;
 e = *stack--;
 f = *stack--;
}
inline void popv(int n)
{ stack -= n;
}
extern volatile bool tick_pending;
extern volatile int unwind_pending;
extern void respond_to_stack_event();
inline void stackcheck0()
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit) respond_to_stack_event();
}
inline void stackcheck1(LispObject& a1) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1);
 respond_to_stack_event();
 pop(a1);
 }
}
inline void stackcheck2(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1, a2);
 respond_to_stack_event();
 pop(a2, a1);
 }
}
inline void stackcheck3(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1, a2, a3);
 respond_to_stack_event();
 pop(a3, a2, a1);
 }
}
inline void stackcheck4(LispObject& a1, LispObject& a2, LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1, a2, a3, a4);
 respond_to_stack_event();
 pop(a4, a3, a2, a1);
 }
}
inline void stackcheck()
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit) respond_to_stack_event();
}
inline void stackcheck(LispObject& a1) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1);
 respond_to_stack_event();
 pop(a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1, a2);
 respond_to_stack_event();
 pop(a2, a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1, a2, a3);
 respond_to_stack_event();
 pop(a3, a2, a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2,
 LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (((uintptr_t)stack | event_flag.load()) >=
 (uintptr_t)stacklimit)
 { push(a1, a2, a3, a4);
 respond_to_stack_event();
 pop(a4, a3, a2, a1);
 }
}
inline void respond_to_fringe_event(LispObject &r, const char *msg)
{
#ifdef BOOTSTRAP
 if (msg == NULL)
 {
#ifdef CONSERVATIVE
 reclaim("gc-forcer");
#else
 r = reclaim(r, "gc-forcer", GC_USER_HARD, 0);
#endif
 return;
 }
#endif 
 uintptr_t f = event_flag.load();
 while (!event_flag.compare_exchange_weak(f, 0)) {}
 if (f == 0)
 {
#ifdef CONSERVATIVE
 reclaim(msg);
#else
 r = reclaim(r, "gc-forcer", GC_USER_HARD, 0);
#endif
 return;
 }
}
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
 setvalue(elt(savestack[env_loc], name_loc), savestack[val_loc]);
 }
};
#ifndef LISPEXCEPTION_DEFINED
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
#endif 
 struct LispResource : public LispError
 { virtual const char *what() const throw()
 { return "Lisp Resouce Limiter";
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
 {
#ifdef __cpp_lib_uncaught_exceptions
 if (saveStack != stack && !std::uncaught_exceptions() != 0)
#else
 if (saveStack != stack && !std::uncaught_exception())
#endif
 { err_printf("[Stack Sanity Oddity] %p => %p in %s : %s:%d\n",
 saveStack, stack, fname, file, line);
 err_printf("Data: ");
 prin_to_error(w);
 err_printf("\n");
 err_printf("exit_count = %d, exit_reason = %d\n",
 exit_count, exit_reason);
 }
 }
};
inline const char *tidy_filename(const char *a)
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
 { push(litvec, codevec);
 saveStack = stack;
 }
 ~RAIIsave_codevec()
 { stack = saveStack;
 pop(codevec, litvec);
 }
};
#define SAVE_CODEVEC RAIIsave_codevec save_codevec_object;
[[noreturn]] extern void global_longjmp();
#ifndef SAVE_STACK_AND_JB_DEFINED
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
#endif
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
 if (miscflags & HEADLINE_FLAG) \
 err_printf("\n+++ Error %s: ", errorset_msg); \
 throw LispSignal(); \
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
 catch (LispError &e) \
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
 catch (LispError &e) \
 { b; \
 }
#define ignore_error(a) \
 try \
 { START_TRY_BLOCK; \
 a; \
 } \
 catch (LispError &e) \
 { \
 }
#define ignore_exception(a) \
 try \
 { START_SETJMP_BLOCK; \
 a; \
 } \
 catch (LispError &e) \
 { \
 }
#endif 



// Code for redall

static LispObject CC_redall(LispObject env,
                         LispObject v_3, LispObject v_4,
                         LispObject v_5)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_184, v_185, v_186;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_3,v_4,v_5);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5,v_4,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_5;
    v_185 = v_4;
    v_184 = v_3;
// end of prologue
// Binding gg!*
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
    setvalue(basic_elt(env, 1), v_184); // gg!*
    v_184 = v_185;
    stack[-6] = v_184;
    v_184 = nil;
    setvalue(basic_elt(env, 2), v_184); // shortway!*
    setvalue(basic_elt(env, 3), v_184); // thirdway!*
    v_184 = lisp_true;
    stack[-1] = v_184;
v_25:
    v_184 = stack[-6];
    if (v_184 == nil) goto v_28;
    else goto v_29;
v_28:
    goto v_24;
v_29:
    v_184 = stack[-6];
    v_184 = Lreverse(nil, v_184);
    env = stack[-9];
    if (!car_legal(v_184)) v_184 = carerror(v_184); else
    v_184 = car(v_184);
    stack[-5] = v_184;
    v_185 = stack[-5];
    v_184 = stack[-6];
    v_184 = Ldelete(nil, v_185, v_184);
    env = stack[-9];
    stack[-6] = v_184;
    v_184 = stack[-5];
    if (!car_legal(v_184)) v_184 = carerror(v_184); else
    v_184 = car(v_184);
    stack[-2] = v_184;
    v_185 = qvalue(basic_elt(env, 4)); // gv!*
    v_184 = stack[-2];
    v_184 = Lgetv(nil, v_185, v_184);
    env = stack[-9];
    stack[-4] = v_184;
    v_184 = qvalue(basic_elt(env, 5)); // path
    if (v_184 == nil) goto v_46;
    v_184 = stack[-1];
    if (v_184 == nil) goto v_51;
    v_184 = stack[-4];
    {   LispObject fn = basic_elt(env, 10); // ljet
    v_184 = (*qfn1(fn))(fn, v_184);
    }
    env = stack[-9];
    v_184 = Lprinc(nil, v_184);
    env = stack[-9];
    v_184 = basic_elt(env, 6); // " ==> "
    v_184 = Lprinc(nil, v_184);
    env = stack[-9];
    goto v_49;
v_51:
    v_184 = stack[-4];
    {   LispObject fn = basic_elt(env, 10); // ljet
    v_184 = (*qfn1(fn))(fn, v_184);
    }
    env = stack[-9];
    v_184 = Lprinc(nil, v_184);
    env = stack[-9];
    v_184 = basic_elt(env, 7); // " --> "
    v_184 = Lprinc(nil, v_184);
    env = stack[-9];
    goto v_49;
v_49:
    goto v_44;
v_46:
v_44:
    stack[-3] = qvalue(basic_elt(env, 4)); // gv!*
    stack[0] = stack[-2];
    v_186 = stack[-4];
    v_185 = qvalue(basic_elt(env, 1)); // gg!*
    v_184 = stack[-7];
    {   LispObject fn = basic_elt(env, 11); // nf
    v_184 = (*qfn3(fn))(fn, v_186, v_185, v_184);
    }
    env = stack[-9];
    v_184 = Lputv(nil, stack[-3], stack[0], v_184);
    env = stack[-9];
    stack[-5] = v_184;
    v_184 = stack[-5];
    if (v_184 == nil) goto v_78;
    v_184 = stack[-5];
    {   LispObject fn = basic_elt(env, 10); // ljet
    v_184 = (*qfn1(fn))(fn, v_184);
    }
    env = stack[-9];
    goto v_76;
v_78:
    v_184 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_76;
    v_184 = nil;
v_76:
    stack[-3] = v_184;
    v_184 = qvalue(basic_elt(env, 5)); // path
    if (v_184 == nil) goto v_88;
    v_184 = stack[-3];
    v_184 = Lprinc(nil, v_184);
    env = stack[-9];
    v_184 = Lterpri(nil);
    env = stack[-9];
    goto v_86;
v_88:
v_86:
    v_184 = stack[-5];
    if (v_184 == nil) goto v_96;
    else goto v_97;
v_96:
    goto v_95;
v_97:
    v_184 = stack[-3];
    {   LispObject fn = basic_elt(env, 12); // ord
    v_185 = (*qfn1(fn))(fn, v_184);
    }
    env = stack[-9];
    v_184 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_185 == v_184) goto v_100;
    else goto v_101;
v_100:
    v_185 = stack[-5];
    v_184 = qvalue(basic_elt(env, 8)); // conds!*
    v_184 = cons(v_185, v_184);
    env = stack[-9];
    setvalue(basic_elt(env, 8), v_184); // conds!*
    goto v_95;
v_101:
    v_184 = stack[-5];
    {   LispObject fn = basic_elt(env, 10); // ljet
    stack[0] = (*qfn1(fn))(fn, v_184);
    }
    env = stack[-9];
    v_184 = stack[-4];
    {   LispObject fn = basic_elt(env, 10); // ljet
    v_184 = (*qfn1(fn))(fn, v_184);
    }
    env = stack[-9];
    if (equal(stack[0], v_184)) goto v_113;
    v_184 = lisp_true;
    setvalue(basic_elt(env, 2), v_184); // shortway!*
    goto v_111;
v_113:
v_111:
    v_184 = stack[-1];
    if (v_184 == nil) goto v_125;
    else goto v_126;
v_125:
    v_185 = stack[-5];
    v_184 = stack[-4];
    v_184 = Lneq_2(nil, v_185, v_184);
    env = stack[-9];
    goto v_124;
v_126:
    v_184 = nil;
    goto v_124;
    v_184 = nil;
v_124:
    if (v_184 == nil) goto v_122;
    v_184 = lisp_true;
    setvalue(basic_elt(env, 3), v_184); // thirdway!*
    goto v_120;
v_122:
v_120:
    v_184 = qvalue(basic_elt(env, 1)); // gg!*
    stack[-4] = v_184;
v_138:
    v_184 = stack[-4];
    if (v_184 == nil) goto v_142;
    else goto v_143;
v_142:
    goto v_137;
v_143:
    v_184 = stack[-4];
    if (!car_legal(v_184)) v_184 = carerror(v_184); else
    v_184 = car(v_184);
    stack[-1] = v_184;
    v_185 = stack[-3];
    v_184 = stack[-1];
    if (!car_legal(v_184)) v_184 = cdrerror(v_184); else
    v_184 = qcdr(v_184);
    {   LispObject fn = basic_elt(env, 13); // dd
    stack[0] = (*qfn2(fn))(fn, v_185, v_184);
    }
    env = stack[-9];
    v_185 = stack[-7];
    v_184 = (LispObject)32+TAG_FIXNUM; // 2
    v_184 = plus2(v_185, v_184);
    env = stack[-9];
    v_184 = (LispObject)geq2(stack[0], v_184);
    v_184 = v_184 ? lisp_true : nil;
    env = stack[-9];
    if (v_184 == nil) goto v_152;
    v_185 = stack[-1];
    v_184 = qvalue(basic_elt(env, 1)); // gg!*
    v_184 = Ldelete(nil, v_185, v_184);
    env = stack[-9];
    setvalue(basic_elt(env, 1), v_184); // gg!*
    v_185 = stack[-1];
    v_184 = stack[-6];
    {   LispObject fn = basic_elt(env, 14); // insert
    v_184 = (*qfn2(fn))(fn, v_185, v_184);
    }
    env = stack[-9];
    stack[-6] = v_184;
    v_186 = qvalue(basic_elt(env, 9)); // bv!*
    v_184 = stack[-1];
    if (!car_legal(v_184)) v_185 = carerror(v_184); else
    v_185 = car(v_184);
    v_184 = lisp_true;
    v_184 = Lputv(nil, v_186, v_185, v_184);
    env = stack[-9];
    goto v_150;
v_152:
v_150:
    v_184 = stack[-4];
    if (!car_legal(v_184)) v_184 = cdrerror(v_184); else
    v_184 = qcdr(v_184);
    stack[-4] = v_184;
    goto v_138;
v_137:
    v_185 = stack[-2];
    v_184 = stack[-3];
    v_185 = cons(v_185, v_184);
    env = stack[-9];
    v_184 = qvalue(basic_elt(env, 1)); // gg!*
    {   LispObject fn = basic_elt(env, 14); // insert
    v_184 = (*qfn2(fn))(fn, v_185, v_184);
    }
    env = stack[-9];
    setvalue(basic_elt(env, 1), v_184); // gg!*
    v_184 = nil;
    stack[-1] = v_184;
    goto v_95;
v_95:
    goto v_25;
v_24:
    v_184 = qvalue(basic_elt(env, 1)); // gg!*
    ;}  // end of a binding scope
    return onevalue(v_184);
}



// Code for fd2q

static LispObject CC_fd2q(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48, v_49;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
v_6:
    v_48 = stack[0];
    if (!consp(v_48)) goto v_9;
    else goto v_10;
v_9:
    v_49 = stack[0];
    v_48 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_49, v_48);
v_10:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = car(v_48);
    v_48 = basic_elt(env, 1); // !:ar!:
    if (v_49 == v_48) goto v_15;
    else goto v_16;
v_15:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    stack[0] = v_48;
    goto v_6;
v_16:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = car(v_48);
    v_48 = basic_elt(env, 2); // !:rn!:
    if (v_49 == v_48) goto v_22;
    else goto v_23;
v_22:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    goto v_5;
v_23:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_48)) v_49 = carerror(v_48); else
    v_49 = car(v_48);
    v_48 = (LispObject)16+TAG_FIXNUM; // 1
    v_48 = cons(v_49, v_48);
    env = stack[-2];
    v_49 = ncons(v_48);
    env = stack[-2];
    v_48 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = cons(v_49, v_48);
    env = stack[-2];
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    v_48 = CC_fd2q(basic_elt(env, 0), v_48);
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 3); // multsq
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_48);
    }
    env = stack[-2];
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = qcdr(v_48);
    v_48 = CC_fd2q(basic_elt(env, 0), v_48);
    env = stack[-2];
    {
        LispObject v_52 = stack[-1];
        LispObject fn = basic_elt(env, 4); // addsq
        return (*qfn2(fn))(fn, v_52, v_48);
    }
    v_48 = nil;
v_5:
    return onevalue(v_48);
}



// Code for oddext

static LispObject CC_oddext(LispObject env,
                         LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_39, v_40;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_39 = v_3;
// end of prologue
// Binding odd_var
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    setvalue(basic_elt(env, 1), v_39); // odd_var
    v_40 = qvalue(basic_elt(env, 1)); // odd_var
    v_39 = qvalue(basic_elt(env, 2)); // all_parametric_odd!*
    v_39 = Lmember(nil, v_40, v_39);
    if (v_39 == nil) goto v_13;
    stack[0] = basic_elt(env, 3); // ext
    v_40 = qvalue(basic_elt(env, 1)); // odd_var
    v_39 = qvalue(basic_elt(env, 2)); // all_parametric_odd!*
    {   LispObject fn = basic_elt(env, 7); // cde_position
    v_39 = (*qfn2(fn))(fn, v_40, v_39);
    }
    env = stack[-3];
    v_39 = list2(stack[0], v_39);
    goto v_11;
v_13:
    v_40 = qvalue(basic_elt(env, 1)); // odd_var
    v_39 = qvalue(basic_elt(env, 4)); // all_principal_odd!*
    v_39 = Lmember(nil, v_40, v_39);
    if (v_39 == nil) goto v_23;
    stack[-1] = basic_elt(env, 3); // ext
    stack[0] = qvalue(basic_elt(env, 5)); // n_all_parametric_ext
    v_40 = qvalue(basic_elt(env, 1)); // odd_var
    v_39 = qvalue(basic_elt(env, 4)); // all_principal_odd!*
    {   LispObject fn = basic_elt(env, 7); // cde_position
    v_39 = (*qfn2(fn))(fn, v_40, v_39);
    }
    env = stack[-3];
    v_39 = plus2(stack[0], v_39);
    env = stack[-3];
    v_39 = list2(stack[-1], v_39);
    goto v_11;
v_23:
    v_39 = basic_elt(env, 6); // "the argument of oddext must be an odd variable"
    {   LispObject fn = basic_elt(env, 8); // rederr
    v_39 = (*qfn1(fn))(fn, v_39);
    }
    goto v_11;
    v_39 = nil;
v_11:
    ;}  // end of a binding scope
    return onevalue(v_39);
}



// Code for ra_intequiv

static LispObject CC_ra_intequiv(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    stack[0] = basic_elt(env, 1); // ra_intequiv0
    v_8 = ncons(v_8);
    env = stack[-1];
    {
        LispObject v_10 = stack[0];
        LispObject fn = basic_elt(env, 2); // ra_wrapper
        return (*qfn2(fn))(fn, v_10, v_8);
    }
}



// Code for polynomread

static LispObject CC_polynomread(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_78, v_79, v_80;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_78 = stack[0];
    if (v_78 == nil) goto v_6;
    else goto v_7;
v_6:
    v_78 = nil;
    return ncons(v_78);
v_7:
    v_78 = stack[0];
    if (!consp(v_78)) goto v_15;
    else goto v_16;
v_15:
    v_78 = lisp_true;
    goto v_14;
v_16:
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    v_78 = (consp(v_78) ? nil : lisp_true);
    goto v_14;
    v_78 = nil;
v_14:
    if (v_78 == nil) goto v_12;
    v_79 = stack[0];
    v_78 = (LispObject)32+TAG_FIXNUM; // 2
    v_79 = Cremainder(v_79, v_78);
    env = stack[-2];
    v_78 = (LispObject)16+TAG_FIXNUM; // 1
    v_78 = Leqn_2(nil, v_79, v_78);
    env = stack[-2];
    if (v_78 == nil) goto v_27;
    {   LispObject fn = basic_elt(env, 3); // createmonomunit
    v_80 = (*qfn0(fn))(fn);
    }
    v_79 = nil;
    v_78 = nil;
    return list2star(v_80, v_79, v_78);
v_27:
    v_78 = nil;
    return ncons(v_78);
    v_78 = nil;
    goto v_5;
v_12:
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    if (!car_legal(v_78)) v_79 = carerror(v_78); else
    v_79 = car(v_78);
    v_78 = qvalue(basic_elt(env, 1)); // fluidbibasisvariables
    v_78 = Lmember(nil, v_79, v_78);
    if (v_78 == nil) goto v_42;
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    v_80 = CC_polynomread(basic_elt(env, 0), v_78);
    env = stack[-2];
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    if (!car_legal(v_78)) v_79 = carerror(v_78); else
    v_79 = car(v_78);
    v_78 = qvalue(basic_elt(env, 2)); // fluidbibasissinglevariablemonomialsa
    v_78 = Lassoc(nil, v_79, v_78);
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    {   LispObject fn = basic_elt(env, 4); // polynommultiplybymonom
    stack[-1] = (*qfn2(fn))(fn, v_80, v_78);
    }
    env = stack[-2];
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    v_78 = CC_polynomread(basic_elt(env, 0), v_78);
    env = stack[-2];
    {
        LispObject v_83 = stack[-1];
        LispObject fn = basic_elt(env, 5); // polynomadd
        return (*qfn2(fn))(fn, v_83, v_78);
    }
v_42:
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = carerror(v_78); else
    v_78 = car(v_78);
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    stack[-1] = CC_polynomread(basic_elt(env, 0), v_78);
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 3); // createmonomunit
    v_78 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 4); // polynommultiplybymonom
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_78);
    }
    env = stack[-2];
    v_78 = stack[0];
    if (!car_legal(v_78)) v_78 = cdrerror(v_78); else
    v_78 = qcdr(v_78);
    v_78 = CC_polynomread(basic_elt(env, 0), v_78);
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 5); // polynomadd
    v_78 = (*qfn2(fn))(fn, stack[-1], v_78);
    }
    v_78 = nil;
    goto v_5;
    v_78 = nil;
v_5:
    return onevalue(v_78);
}



// Code for mri_2ofsfat

static LispObject CC_mri_2ofsfat(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_10 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // mri_op
    stack[-1] = (*qfn1(fn))(fn, v_10);
    }
    env = stack[-2];
    v_10 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // mri_arg2l
    v_11 = (*qfn1(fn))(fn, v_10);
    }
    v_10 = nil;
    {
        LispObject v_14 = stack[-1];
        return list3(v_14, v_11, v_10);
    }
}



// Code for rl_multsurep

static LispObject CC_rl_multsurep(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    stack[0] = qvalue(basic_elt(env, 1)); // rl_multsurep!*
    v_10 = list2(v_11, v_10);
    env = stack[-1];
    {
        LispObject v_13 = stack[0];
        LispObject fn = basic_elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13, v_10);
    }
}



// Code for make!-modular!-symmetric

static LispObject CC_makeKmodularKsymmetric(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_62, v_63, v_64;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_62 = stack[0];
    if (v_62 == nil) goto v_6;
    else goto v_7;
v_6:
    v_62 = nil;
    goto v_5;
v_7:
    v_62 = stack[0];
    if (!consp(v_62)) goto v_14;
    else goto v_15;
v_14:
    v_62 = lisp_true;
    goto v_13;
v_15:
    v_62 = stack[0];
    if (!car_legal(v_62)) v_62 = carerror(v_62); else
    v_62 = car(v_62);
    v_62 = (consp(v_62) ? nil : lisp_true);
    goto v_13;
    v_62 = nil;
v_13:
    if (v_62 == nil) goto v_11;
    v_63 = stack[0];
    v_62 = qvalue(basic_elt(env, 1)); // modulus!/2
    v_62 = (LispObject)greaterp2(v_63, v_62);
    v_62 = v_62 ? lisp_true : nil;
    env = stack[-2];
    if (v_62 == nil) goto v_26;
    v_63 = stack[0];
    v_62 = qvalue(basic_elt(env, 2)); // current!-modulus
    v_62 = difference2(v_63, v_62);
    env = stack[-2];
    {
        LispObject fn = basic_elt(env, 3); // !*n2f
        return (*qfn1(fn))(fn, v_62);
    }
v_26:
    v_62 = stack[0];
    goto v_24;
    v_62 = nil;
v_24:
    goto v_5;
v_11:
    v_62 = stack[0];
    if (!car_legal(v_62)) v_62 = carerror(v_62); else
    v_62 = car(v_62);
    if (!car_legal(v_62)) v_62 = cdrerror(v_62); else
    v_62 = qcdr(v_62);
    stack[-1] = CC_makeKmodularKsymmetric(basic_elt(env, 0), v_62);
    env = stack[-2];
    v_62 = stack[0];
    if (!car_legal(v_62)) v_62 = cdrerror(v_62); else
    v_62 = qcdr(v_62);
    v_62 = CC_makeKmodularKsymmetric(basic_elt(env, 0), v_62);
    v_63 = stack[-1];
    v_64 = v_63;
    if (v_64 == nil) goto v_50;
    else goto v_51;
v_50:
    goto v_49;
v_51:
    v_64 = stack[0];
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    return acons(v_64, v_63, v_62);
    v_62 = nil;
v_49:
    goto v_5;
    v_62 = nil;
v_5:
    return onevalue(v_62);
}



// Code for upperlimitrd

static LispObject CC_upperlimitrd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_30, v_31;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    {   LispObject fn = basic_elt(env, 6); // lex
    v_30 = (*qfn0(fn))(fn);
    }
    env = stack[-1];
    v_31 = qvalue(basic_elt(env, 1)); // char
    v_30 = basic_elt(env, 2); // (u p l i m i t)
    if (equal(v_31, v_30)) goto v_10;
    v_31 = basic_elt(env, 3); // "<uplimit>"
    v_30 = (LispObject)160+TAG_FIXNUM; // 10
    {   LispObject fn = basic_elt(env, 7); // errorml
    v_30 = (*qfn2(fn))(fn, v_31, v_30);
    }
    env = stack[-1];
    goto v_8;
v_10:
v_8:
    {   LispObject fn = basic_elt(env, 8); // mathml
    v_30 = (*qfn0(fn))(fn);
    }
    env = stack[-1];
    stack[0] = v_30;
    {   LispObject fn = basic_elt(env, 6); // lex
    v_30 = (*qfn0(fn))(fn);
    }
    env = stack[-1];
    v_31 = qvalue(basic_elt(env, 1)); // char
    v_30 = basic_elt(env, 4); // (!/ u p l i m i t)
    if (equal(v_31, v_30)) goto v_20;
    else goto v_21;
v_20:
    v_30 = stack[0];
    goto v_5;
v_21:
    v_31 = basic_elt(env, 5); // "</uplimit>"
    v_30 = (LispObject)32+TAG_FIXNUM; // 2
    {   LispObject fn = basic_elt(env, 7); // errorml
    v_30 = (*qfn2(fn))(fn, v_31, v_30);
    }
    goto v_19;
v_19:
    v_30 = nil;
v_5:
    return onevalue(v_30);
}



// Code for reduceroots

static LispObject CC_reduceroots(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_35, v_36, v_37;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_35 = nil;
v_10:
    v_36 = stack[-1];
    if (v_36 == nil) goto v_13;
    else goto v_14;
v_13:
    goto v_9;
v_14:
    v_36 = stack[0];
    if (!car_legal(v_36)) v_37 = carerror(v_36); else
    v_37 = car(v_36);
    v_36 = basic_elt(env, 1); // sqrt
    if (!consp(v_37)) goto v_20;
    v_37 = car(v_37);
    if (v_37 == v_36) goto v_19;
    else goto v_20;
v_19:
    v_37 = stack[-1];
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = carerror(v_36); else
    v_36 = car(v_36);
    {   LispObject fn = basic_elt(env, 2); // tryreduction
    v_35 = (*qfn3(fn))(fn, v_37, v_36, v_35);
    }
    env = stack[-2];
    goto v_18;
v_20:
v_18:
    v_36 = stack[-1];
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    stack[-1] = v_36;
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    stack[0] = v_36;
    goto v_10;
v_9:
    return onevalue(v_35);
}



// Code for suspend

static LispObject CC_suspend(LispObject env,
                         LispObject v_5, LispObject v_6,
                         LispObject v_7, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_43, v_44, v_45, v_46;
    LispObject v_8, v_9;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_8 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_9 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_5,v_6,v_7,v_8,v_9);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_9,v_8,v_7,v_6,v_5);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_9;
    v_44 = v_8;
    v_45 = v_7;
    v_46 = v_6;
    v_43 = v_5;
// end of prologue
// Binding op
// FLUIDBIND: reloadenv=9 litvec-offset=1 saveloc=8
{   bind_fluid_stack bind_fluid_var(-9, 1, -8);
// Binding r
// FLUIDBIND: reloadenv=9 litvec-offset=2 saveloc=6
{   bind_fluid_stack bind_fluid_var(-9, 2, -6);
// Binding p
// FLUIDBIND: reloadenv=9 litvec-offset=3 saveloc=5
{   bind_fluid_stack bind_fluid_var(-9, 3, -5);
    setvalue(basic_elt(env, 1), v_43); // op
    v_43 = v_46;
    setvalue(basic_elt(env, 2), v_43); // r
    v_43 = v_45;
    setvalue(basic_elt(env, 3), v_43); // p
    v_43 = qvalue(basic_elt(env, 2)); // r
    if (!car_legal(v_43)) stack[-4] = carerror(v_43); else
    stack[-4] = car(v_43);
    v_43 = qvalue(basic_elt(env, 3)); // p
    if (!car_legal(v_43)) stack[-3] = carerror(v_43); else
    stack[-3] = car(v_43);
    stack[-2] = v_44;
    stack[-1] = qvalue(basic_elt(env, 1)); // op
    v_43 = qvalue(basic_elt(env, 2)); // r
    if (!car_legal(v_43)) stack[0] = cdrerror(v_43); else
    stack[0] = qcdr(v_43);
    v_44 = qvalue(basic_elt(env, 1)); // op
    v_43 = qvalue(basic_elt(env, 3)); // p
    if (!car_legal(v_43)) v_43 = cdrerror(v_43); else
    v_43 = qcdr(v_43);
    v_43 = cons(v_44, v_43);
    env = stack[-9];
    v_43 = ncons(v_43);
    env = stack[-9];
    v_44 = acons(stack[-1], stack[0], v_43);
    env = stack[-9];
    v_43 = stack[-7];
    v_43 = cons(v_44, v_43);
    env = stack[-9];
    v_43 = ncons(v_43);
    env = stack[-9];
    {   LispObject fn = basic_elt(env, 4); // amatch
    v_43 = (*qfn4up(fn))(fn, stack[-4], stack[-3], stack[-2], v_43);
    }
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    return onevalue(v_43);
}



// Code for a2bc

static LispObject CC_a2bc(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_36, v_37;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_36 = v_2;
// end of prologue
    v_37 = qvalue(basic_elt(env, 1)); // !*grmod!*
    if (v_37 == nil) goto v_7;
    v_37 = v_36;
    if (!consp(v_37)) goto v_15;
    else goto v_16;
v_15:
    v_37 = lisp_true;
    goto v_14;
v_16:
    v_37 = v_36;
    if (!car_legal(v_37)) v_37 = carerror(v_37); else
    v_37 = car(v_37);
    v_37 = (consp(v_37) ? nil : lisp_true);
    goto v_14;
    v_37 = nil;
v_14:
    if (v_37 == nil) goto v_11;
    else goto v_12;
v_11:
    v_37 = basic_elt(env, 2); // " Invalid coefficient "
    v_36 = list2(v_37, v_36);
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_36);
    }
v_12:
    {
        LispObject fn = basic_elt(env, 4); // bcfd
        return (*qfn1(fn))(fn, v_36);
    }
    v_36 = nil;
    goto v_5;
v_7:
    {
        LispObject fn = basic_elt(env, 5); // simp!*
        return (*qfn1(fn))(fn, v_36);
    }
    v_36 = nil;
v_5:
    return onevalue(v_36);
}



// Code for simpwedge

static LispObject CC_simpwedge(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // partitwedge
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // !*pf2sq
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for rd!:difference

static LispObject CC_rdTdifference(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_153, v_154, v_155;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_153 = nil;
    stack[-3] = v_153;
    v_153 = qvalue(basic_elt(env, 1)); // !*!*roundbf
    if (v_153 == nil) goto v_13;
    else goto v_14;
v_13:
    v_153 = stack[-2];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = qcdr(v_153);
    if (!consp(v_153)) goto v_18;
    else goto v_19;
v_18:
    v_153 = stack[0];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = qcdr(v_153);
    if (!consp(v_153)) goto v_24;
    else goto v_25;
v_24:
    v_153 = stack[-2];
    if (!car_legal(v_153)) stack[-1] = cdrerror(v_153); else
    stack[-1] = qcdr(v_153);
    v_153 = stack[0];
    if (!car_legal(v_153)) v_153 = cdrerror(v_153); else
    v_153 = qcdr(v_153);
    {   LispObject fn = basic_elt(env, 4); // safe!-fp!-minus
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 5); // safe!-fp!-plus
    v_153 = (*qfn2(fn))(fn, stack[-1], v_153);
    }
    env = stack[-4];
    stack[-3] = v_153;
    goto v_23;
v_25:
    v_153 = nil;
    goto v_23;
    v_153 = nil;
v_23:
    goto v_17;
v_19:
    v_153 = nil;
    goto v_17;
    v_153 = nil;
v_17:
    goto v_12;
v_14:
    v_153 = nil;
    goto v_12;
    v_153 = nil;
v_12:
    if (v_153 == nil) goto v_10;
    v_154 = basic_elt(env, 2); // !:rd!:
    v_153 = stack[-3];
    return cons(v_154, v_153);
v_10:
    v_154 = stack[-2];
    v_153 = stack[0];
    {   LispObject fn = basic_elt(env, 6); // convprc2
    v_153 = (*qfn2(fn))(fn, v_154, v_153);
    }
    env = stack[-4];
    stack[-1] = v_153;
    v_153 = qvalue(basic_elt(env, 3)); // yy!!
    stack[0] = v_153;
    v_153 = stack[-1];
    if (!consp(v_153)) goto v_59;
    v_154 = stack[-1];
    v_153 = stack[0];
    {   LispObject fn = basic_elt(env, 7); // difbf
    v_153 = (*qfn2(fn))(fn, v_154, v_153);
    }
    env = stack[-4];
    goto v_57;
v_59:
    v_154 = stack[-1];
    v_153 = stack[0];
    v_153 = difference2(v_154, v_153);
    env = stack[-4];
    stack[-3] = v_153;
    v_153 = stack[-3];
    {   LispObject fn = basic_elt(env, 8); // fp!-infinite
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    if (v_153 == nil) goto v_72;
    {   LispObject fn = basic_elt(env, 9); // rndbfon
    v_153 = (*qfn0(fn))(fn);
    }
    env = stack[-4];
    v_153 = stack[-1];
    v_153 = Lfloatp(nil, v_153);
    env = stack[-4];
    if (v_153 == nil) goto v_80;
    v_153 = stack[-1];
    {   LispObject fn = basic_elt(env, 10); // fl2bf
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    stack[-2] = v_153;
    goto v_78;
v_80:
    v_153 = stack[-1];
    if (!consp(v_153)) goto v_91;
    v_153 = stack[-1];
    goto v_89;
v_91:
    v_153 = stack[-1];
    v_153 = integerp(v_153);
    if (v_153 == nil) goto v_95;
    v_155 = basic_elt(env, 2); // !:rd!:
    v_154 = stack[-1];
    v_153 = (LispObject)0+TAG_FIXNUM; // 0
    v_153 = list2star(v_155, v_154, v_153);
    env = stack[-4];
    goto v_89;
v_95:
    v_153 = stack[-1];
    {   LispObject fn = basic_elt(env, 11); // read!:num
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    goto v_89;
    v_153 = nil;
v_89:
    {   LispObject fn = basic_elt(env, 12); // normbf
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    stack[-2] = v_153;
    goto v_78;
    stack[-2] = nil;
v_78:
    stack[-1] = stack[-2];
    v_153 = stack[0];
    v_153 = Lfloatp(nil, v_153);
    env = stack[-4];
    if (v_153 == nil) goto v_109;
    v_153 = stack[0];
    {   LispObject fn = basic_elt(env, 10); // fl2bf
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    goto v_107;
v_109:
    v_153 = stack[0];
    if (!consp(v_153)) goto v_120;
    v_153 = stack[0];
    goto v_118;
v_120:
    v_153 = stack[0];
    v_153 = integerp(v_153);
    if (v_153 == nil) goto v_124;
    v_155 = basic_elt(env, 2); // !:rd!:
    v_154 = stack[0];
    v_153 = (LispObject)0+TAG_FIXNUM; // 0
    v_153 = list2star(v_155, v_154, v_153);
    env = stack[-4];
    goto v_118;
v_124:
    v_153 = stack[0];
    {   LispObject fn = basic_elt(env, 11); // read!:num
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    goto v_118;
    v_153 = nil;
v_118:
    {   LispObject fn = basic_elt(env, 12); // normbf
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    goto v_107;
    v_153 = nil;
v_107:
    stack[0] = v_153;
    {   LispObject fn = basic_elt(env, 7); // difbf
    v_153 = (*qfn2(fn))(fn, stack[-2], v_153);
    }
    env = stack[-4];
    goto v_70;
v_72:
    v_153 = stack[-3];
    goto v_70;
    v_153 = nil;
v_70:
    goto v_57;
    v_153 = nil;
v_57:
    stack[-2] = v_153;
    v_153 = stack[0];
    if (!consp(v_153)) goto v_144;
    else goto v_145;
v_144:
    v_153 = stack[0];
    v_153 = negate(v_153);
    env = stack[-4];
    goto v_143;
v_145:
    v_153 = stack[0];
    {   LispObject fn = basic_elt(env, 13); // minus!:
    v_153 = (*qfn1(fn))(fn, v_153);
    }
    env = stack[-4];
    goto v_143;
    v_153 = nil;
v_143:
    {   LispObject fn = basic_elt(env, 14); // rdzchk
    v_153 = (*qfn3(fn))(fn, stack[-2], stack[-1], v_153);
    }
    env = stack[-4];
    {
        LispObject fn = basic_elt(env, 15); // mkround
        return (*qfn1(fn))(fn, v_153);
    }
    goto v_8;
    v_153 = nil;
v_8:
    return onevalue(v_153);
}



// Code for cvitimes2

static LispObject CC_cvitimes2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_38, v_39, v_40, v_41;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_40 = v_3;
    v_41 = v_2;
// end of prologue
    v_39 = v_41;
    v_38 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_39 == v_38) goto v_11;
    else goto v_12;
v_11:
    v_38 = lisp_true;
    goto v_10;
v_12:
    v_39 = v_40;
    v_38 = (LispObject)0+TAG_FIXNUM; // 0
    v_38 = (v_39 == v_38 ? lisp_true : nil);
    goto v_10;
    v_38 = nil;
v_10:
    if (v_38 == nil) goto v_8;
    v_38 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6;
v_8:
    v_39 = v_41;
    v_38 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_39 == v_38) goto v_22;
    else goto v_23;
v_22:
    v_38 = v_40;
    goto v_6;
v_23:
    v_39 = v_40;
    v_38 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_39 == v_38) goto v_27;
    else goto v_28;
v_27:
    v_38 = v_41;
    goto v_6;
v_28:
    v_38 = basic_elt(env, 1); // times
    v_39 = v_41;
    return list3(v_38, v_39, v_40);
    v_38 = nil;
v_6:
    return onevalue(v_38);
}



// Code for ratnump

static LispObject CC_ratnump(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_29, v_30, v_31;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_29 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 2); // simp!*
    v_30 = (*qfn1(fn))(fn, v_29);
    }
    env = stack[0];
    v_29 = v_30;
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    if (!consp(v_30)) goto v_10;
    else goto v_11;
v_10:
    v_30 = lisp_true;
    goto v_9;
v_11:
    v_30 = v_29;
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    v_31 = basic_elt(env, 1); // !:rn!:
    v_30 = (v_30 == v_31 ? lisp_true : nil);
    goto v_9;
    v_30 = nil;
v_9:
    if (v_30 == nil) goto v_7;
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = qcdr(v_29);
    v_29 = (consp(v_29) ? nil : lisp_true);
    goto v_5;
v_7:
    v_29 = nil;
    goto v_5;
    v_29 = nil;
v_5:
    return onevalue(v_29);
}



// Code for miller!-rabin

static LispObject CC_millerKrabin(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_104, v_105;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[-2] = v_3;
    stack[0] = v_2;
// end of prologue
    v_105 = stack[-2];
    v_104 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_105 == v_104) goto v_13;
    else goto v_14;
v_13:
    v_104 = nil;
    goto v_9;
v_14:
    v_105 = stack[-2];
    v_104 = (LispObject)32+TAG_FIXNUM; // 2
    v_105 = Cremainder(v_105, v_104);
    env = stack[-4];
    v_104 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_105 == v_104) goto v_18;
    else goto v_19;
v_18:
    v_105 = stack[-2];
    v_104 = (LispObject)32+TAG_FIXNUM; // 2
    v_104 = (v_105 == v_104 ? lisp_true : nil);
    goto v_9;
v_19:
    v_105 = stack[-2];
    v_104 = (LispObject)112+TAG_FIXNUM; // 7
    v_104 = (LispObject)lesseq2(v_105, v_104);
    v_104 = v_104 ? lisp_true : nil;
    env = stack[-4];
    if (v_104 == nil) goto v_28;
    v_104 = lisp_true;
    goto v_9;
v_28:
    v_104 = stack[-2];
    v_104 = sub1(v_104);
    env = stack[-4];
    stack[-1] = v_104;
    v_104 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_104;
v_38:
    v_105 = stack[-1];
    v_104 = (LispObject)32+TAG_FIXNUM; // 2
    v_105 = Cremainder(v_105, v_104);
    env = stack[-4];
    v_104 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_105 == v_104) goto v_42;
    goto v_37;
v_42:
    v_105 = stack[-1];
    v_104 = (LispObject)32+TAG_FIXNUM; // 2
    v_104 = quot2(v_105, v_104);
    env = stack[-4];
    stack[-1] = v_104;
    v_104 = stack[-3];
    v_104 = add1(v_104);
    env = stack[-4];
    stack[-3] = v_104;
    goto v_38;
v_37:
    v_104 = stack[-2];
    {   LispObject fn = basic_elt(env, 1); // set!-modulus
    v_104 = (*qfn1(fn))(fn, v_104);
    }
    env = stack[-4];
    v_105 = stack[0];
    v_104 = stack[-2];
    v_104 = Cremainder(v_105, v_104);
    env = stack[-4];
    stack[0] = v_104;
    v_105 = stack[0];
    v_104 = stack[-1];
    v_104 = Lmodular_expt(nil, v_105, v_104);
    env = stack[-4];
    stack[-1] = v_104;
    v_105 = stack[-1];
    v_104 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_105 == v_104) goto v_67;
    else goto v_68;
v_67:
    v_104 = lisp_true;
    goto v_66;
v_68:
    stack[0] = stack[-1];
    v_104 = stack[-2];
    v_104 = sub1(v_104);
    env = stack[-4];
    v_104 = (equal(stack[0], v_104) ? lisp_true : nil);
    goto v_66;
    v_104 = nil;
v_66:
    if (v_104 == nil) goto v_64;
    v_104 = lisp_true;
    goto v_9;
v_64:
v_10:
    v_105 = stack[-3];
    v_104 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_105 == v_104) goto v_81;
    else goto v_82;
v_81:
    v_104 = nil;
    goto v_9;
v_82:
    v_105 = stack[-1];
    v_104 = stack[-1];
    v_104 = Lmodular_times(nil, v_105, v_104);
    env = stack[-4];
    stack[-1] = v_104;
    v_105 = stack[-1];
    v_104 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_105 == v_104) goto v_91;
    else goto v_92;
v_91:
    v_104 = nil;
    goto v_9;
v_92:
    stack[0] = stack[-1];
    v_104 = stack[-2];
    v_104 = sub1(v_104);
    env = stack[-4];
    if (equal(stack[0], v_104)) goto v_96;
    else goto v_97;
v_96:
    v_104 = lisp_true;
    goto v_9;
v_97:
    v_104 = stack[-3];
    v_104 = sub1(v_104);
    env = stack[-4];
    stack[-3] = v_104;
    goto v_10;
v_9:
    return onevalue(v_104);
}



// Code for pa_list2vect

static LispObject CC_pa_list2vect(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_102, v_103;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-5] = v_3;
    stack[0] = v_2;
// end of prologue
    stack[-4] = nil;
    v_102 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_102;
    v_102 = stack[-5];
    v_102 = sub1(v_102);
    env = stack[-7];
    v_102 = Lmkvect(nil, v_102);
    env = stack[-7];
    stack[-6] = v_102;
    v_102 = stack[0];
    stack[-2] = v_102;
v_17:
    v_102 = stack[-2];
    if (v_102 == nil) goto v_21;
    else goto v_22;
v_21:
    goto v_16;
v_22:
    v_102 = stack[-2];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    stack[0] = v_102;
    v_103 = basic_elt(env, 1); // min
    v_102 = stack[0];
    v_102 = cons(v_103, v_102);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 2); // eval
    v_103 = (*qfn1(fn))(fn, v_102);
    }
    env = stack[-7];
    v_102 = stack[-4];
    v_102 = cons(v_103, v_102);
    env = stack[-7];
    stack[-4] = v_102;
    v_102 = stack[0];
    stack[-1] = v_102;
v_37:
    v_102 = stack[-1];
    if (v_102 == nil) goto v_41;
    else goto v_42;
v_41:
    goto v_36;
v_42:
    v_102 = stack[-1];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    stack[0] = stack[-6];
    v_103 = sub1(v_102);
    env = stack[-7];
    v_102 = stack[-4];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    v_102 = Lputv(nil, stack[0], v_103, v_102);
    env = stack[-7];
    v_102 = stack[-1];
    if (!car_legal(v_102)) v_102 = cdrerror(v_102); else
    v_102 = qcdr(v_102);
    stack[-1] = v_102;
    goto v_37;
v_36:
    v_102 = stack[-2];
    if (!car_legal(v_102)) v_102 = cdrerror(v_102); else
    v_102 = qcdr(v_102);
    stack[-2] = v_102;
    goto v_17;
v_16:
    v_102 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-1] = v_102;
v_62:
    v_103 = stack[-5];
    v_102 = stack[-1];
    v_102 = difference2(v_103, v_102);
    env = stack[-7];
    v_102 = Lminusp(nil, v_102);
    env = stack[-7];
    if (v_102 == nil) goto v_67;
    goto v_61;
v_67:
    stack[0] = stack[-6];
    v_102 = stack[-1];
    v_102 = sub1(v_102);
    env = stack[-7];
    v_102 = Lgetv(nil, stack[0], v_102);
    env = stack[-7];
    if (v_102 == nil) goto v_75;
    else goto v_76;
v_75:
    v_103 = stack[-3];
    v_102 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_103 == v_102) goto v_83;
    else goto v_84;
v_83:
    v_102 = stack[-1];
    stack[-3] = v_102;
    v_103 = stack[-3];
    v_102 = stack[-4];
    v_102 = cons(v_103, v_102);
    env = stack[-7];
    stack[-4] = v_102;
    goto v_82;
v_84:
v_82:
    stack[0] = stack[-6];
    v_102 = stack[-1];
    v_103 = sub1(v_102);
    env = stack[-7];
    v_102 = stack[-3];
    v_102 = Lputv(nil, stack[0], v_103, v_102);
    env = stack[-7];
    goto v_74;
v_76:
v_74:
    v_102 = stack[-1];
    v_102 = add1(v_102);
    env = stack[-7];
    stack[-1] = v_102;
    goto v_62;
v_61:
    v_102 = stack[-4];
    v_103 = Lreverse(nil, v_102);
    v_102 = stack[-6];
    return cons(v_103, v_102);
    return onevalue(v_102);
}



// Code for get!-current!-representation

static LispObject CC_getKcurrentKrepresentation(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7, v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    v_8 = basic_elt(env, 1); // currep
    return get(v_7, v_8);
}



// Code for isimp1

static LispObject CC_isimp1(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_102, v_103;
    LispObject v_5, v_6;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_6 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3,v_4,v_5,v_6);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_6,v_5,v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-2] = v_6;
    stack[-3] = v_5;
    stack[-4] = v_4;
    stack[-5] = v_3;
    stack[-6] = v_2;
// end of prologue
    v_102 = stack[-6];
    if (v_102 == nil) goto v_10;
    else goto v_11;
v_10:
    v_102 = nil;
    goto v_9;
v_11:
    v_102 = stack[-6];
    if (!consp(v_102)) goto v_18;
    else goto v_19;
v_18:
    v_102 = lisp_true;
    goto v_17;
v_19:
    v_102 = stack[-6];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    v_102 = (consp(v_102) ? nil : lisp_true);
    goto v_17;
    v_102 = nil;
v_17:
    if (v_102 == nil) goto v_15;
    v_102 = stack[-2];
    if (v_102 == nil) goto v_30;
    stack[-1] = stack[-6];
    v_102 = qvalue(basic_elt(env, 1)); // !*cvit
    if (v_102 == nil) goto v_37;
    stack[0] = stack[-5];
    v_102 = stack[-2];
    v_102 = ncons(v_102);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 2); // calc_spurx
    v_102 = (*qfn4up(fn))(fn, stack[0], stack[-4], stack[-3], v_102);
    }
    env = stack[-8];
    goto v_35;
v_37:
    v_102 = stack[-2];
    if (!car_legal(v_102)) stack[0] = carerror(v_102); else
    stack[0] = car(v_102);
    v_103 = stack[-3];
    v_102 = stack[-2];
    if (!car_legal(v_102)) v_102 = cdrerror(v_102); else
    v_102 = qcdr(v_102);
    v_102 = list2(v_103, v_102);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 3); // spur0
    v_102 = (*qfn4up(fn))(fn, stack[0], stack[-5], stack[-4], v_102);
    }
    env = stack[-8];
    goto v_35;
    v_102 = nil;
v_35:
    {
        LispObject v_112 = stack[-1];
        LispObject fn = basic_elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_112, v_102);
    }
v_30:
    v_102 = stack[-4];
    if (v_102 == nil) goto v_57;
    stack[-1] = stack[-6];
    stack[0] = (LispObject)16+TAG_FIXNUM; // 1
    stack[-2] = stack[-5];
    v_102 = stack[-3];
    v_102 = ncons(v_102);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 5); // index_simp
    v_102 = (*qfn4up(fn))(fn, stack[0], stack[-2], stack[-4], v_102);
    }
    env = stack[-8];
    {
        LispObject v_113 = stack[-1];
        LispObject fn = basic_elt(env, 4); // multd
        return (*qfn2(fn))(fn, v_113, v_102);
    }
v_57:
    v_102 = stack[-3];
    if (v_102 == nil) goto v_68;
    v_102 = stack[-3];
    {   LispObject fn = basic_elt(env, 6); // emult
    stack[0] = (*qfn1(fn))(fn, v_102);
    }
    env = stack[-8];
    stack[-1] = stack[-6];
    stack[-2] = stack[-5];
    stack[-3] = stack[-4];
    v_103 = nil;
    v_102 = nil;
    v_102 = list2(v_103, v_102);
    env = stack[-8];
    v_102 = CC_isimp1(basic_elt(env, 0), stack[-1], stack[-2], stack[-3], v_102);
    env = stack[-8];
    {
        LispObject v_114 = stack[0];
        LispObject fn = basic_elt(env, 7); // multf
        return (*qfn2(fn))(fn, v_114, v_102);
    }
v_68:
    v_102 = stack[-6];
    goto v_28;
    v_102 = nil;
v_28:
    goto v_9;
v_15:
    v_102 = stack[-6];
    if (!car_legal(v_102)) stack[-7] = carerror(v_102); else
    stack[-7] = car(v_102);
    stack[-1] = stack[-5];
    stack[0] = stack[-4];
    v_103 = stack[-3];
    v_102 = stack[-2];
    v_102 = list2(v_103, v_102);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 8); // isimp2
    stack[0] = (*qfn4up(fn))(fn, stack[-7], stack[-1], stack[0], v_102);
    }
    env = stack[-8];
    v_102 = stack[-6];
    if (!car_legal(v_102)) stack[-1] = cdrerror(v_102); else
    stack[-1] = qcdr(v_102);
    v_103 = stack[-3];
    v_102 = stack[-2];
    v_102 = list2(v_103, v_102);
    env = stack[-8];
    v_102 = CC_isimp1(basic_elt(env, 0), stack[-1], stack[-5], stack[-4], v_102);
    env = stack[-8];
    {
        LispObject v_115 = stack[0];
        LispObject fn = basic_elt(env, 9); // addf
        return (*qfn2(fn))(fn, v_115, v_102);
    }
    v_102 = nil;
v_9:
    return onevalue(v_102);
}



// Code for maxfrom

static LispObject CC_maxfrom(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    stack[0] = v_11;
    v_11 = add1(v_10);
    env = stack[-1];
    v_10 = (LispObject)0+TAG_FIXNUM; // 0
    {
        LispObject v_13 = stack[0];
        LispObject fn = basic_elt(env, 1); // maxfrom1
        return (*qfn3(fn))(fn, v_13, v_11, v_10);
    }
}



// Code for cl_nnf1

static LispObject CC_cl_nnf1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_275, v_276, v_277;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-4] = v_3;
    stack[-2] = v_2;
// end of prologue
v_1:
    v_275 = stack[-2];
    if (!consp(v_275)) goto v_10;
    else goto v_11;
v_10:
    v_275 = stack[-2];
    goto v_9;
v_11:
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = carerror(v_275); else
    v_275 = car(v_275);
    goto v_9;
    v_275 = nil;
v_9:
    v_277 = v_275;
    v_276 = v_277;
    v_275 = basic_elt(env, 1); // not
    if (v_276 == v_275) goto v_20;
    else goto v_21;
v_20:
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = (v_275 == nil ? lisp_true : nil);
    stack[-2] = v_276;
    stack[-4] = v_275;
    goto v_1;
v_21:
    v_276 = v_277;
    v_275 = basic_elt(env, 2); // impl
    if (v_276 == v_275) goto v_32;
    else goto v_33;
v_32:
    v_276 = basic_elt(env, 3); // or
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = (v_275 == nil ? lisp_true : nil);
    stack[0] = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    {
        LispObject v_284 = stack[-1];
        LispObject v_285 = stack[0];
        return list2star(v_284, v_285, v_275);
    }
v_33:
    v_276 = v_277;
    v_275 = basic_elt(env, 4); // repl
    if (v_276 == v_275) goto v_55;
    else goto v_56;
v_55:
    v_276 = basic_elt(env, 3); // or
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    stack[0] = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = (v_275 == nil ? lisp_true : nil);
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    {
        LispObject v_286 = stack[-1];
        LispObject v_287 = stack[0];
        return list2star(v_286, v_287, v_275);
    }
v_56:
    v_276 = v_277;
    v_275 = basic_elt(env, 5); // equiv
    if (v_276 == v_275) goto v_78;
    else goto v_79;
v_78:
    v_276 = basic_elt(env, 3); // or
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_276 = basic_elt(env, 6); // and
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    stack[0] = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    env = stack[-6];
    stack[-3] = list2star(stack[-1], stack[0], v_275);
    env = stack[-6];
    v_276 = basic_elt(env, 6); // and
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = (v_275 == nil ? lisp_true : nil);
    stack[0] = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = (v_275 == nil ? lisp_true : nil);
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    env = stack[-6];
    v_275 = list2star(stack[-1], stack[0], v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    {
        LispObject v_288 = stack[-5];
        LispObject v_289 = stack[-3];
        return list2star(v_288, v_289, v_275);
    }
v_79:
    v_276 = v_277;
    v_275 = basic_elt(env, 7); // true
    if (v_276 == v_275) goto v_127;
    else goto v_128;
v_127:
    v_275 = lisp_true;
    goto v_126;
v_128:
    v_276 = v_277;
    v_275 = basic_elt(env, 8); // false
    v_275 = (v_276 == v_275 ? lisp_true : nil);
    goto v_126;
    v_275 = nil;
v_126:
    if (v_275 == nil) goto v_124;
    v_276 = stack[-2];
    v_275 = stack[-4];
    {
        LispObject fn = basic_elt(env, 13); // cl_cflip
        return (*qfn2(fn))(fn, v_276, v_275);
    }
v_124:
    v_276 = v_277;
    v_275 = basic_elt(env, 9); // ex
    if (v_276 == v_275) goto v_146;
    else goto v_147;
v_146:
    v_275 = lisp_true;
    goto v_145;
v_147:
    v_276 = v_277;
    v_275 = basic_elt(env, 10); // all
    v_275 = (v_276 == v_275 ? lisp_true : nil);
    goto v_145;
    v_275 = nil;
v_145:
    if (v_275 == nil) goto v_143;
    v_276 = v_277;
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) stack[0] = carerror(v_275); else
    stack[0] = car(v_275);
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    {
        LispObject v_290 = stack[-1];
        LispObject v_291 = stack[0];
        return list3(v_290, v_291, v_275);
    }
v_143:
    v_276 = v_277;
    v_275 = basic_elt(env, 11); // bex
    if (v_276 == v_275) goto v_175;
    else goto v_176;
v_175:
    v_275 = lisp_true;
    goto v_174;
v_176:
    v_276 = v_277;
    v_275 = basic_elt(env, 12); // ball
    v_275 = (v_276 == v_275 ? lisp_true : nil);
    goto v_174;
    v_275 = nil;
v_174:
    if (v_275 == nil) goto v_172;
    v_276 = v_277;
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-1] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) stack[0] = carerror(v_275); else
    stack[0] = car(v_275);
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = stack[-4];
    stack[-3] = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    if (!car_legal(v_275)) v_276 = carerror(v_275); else
    v_276 = car(v_275);
    v_275 = lisp_true;
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    {
        LispObject v_292 = stack[-1];
        LispObject v_293 = stack[0];
        LispObject v_294 = stack[-3];
        return list4(v_292, v_293, v_294, v_275);
    }
v_172:
    v_276 = v_277;
    v_275 = basic_elt(env, 3); // or
    if (v_276 == v_275) goto v_211;
    else goto v_212;
v_211:
    v_275 = lisp_true;
    goto v_210;
v_212:
    v_276 = v_277;
    v_275 = basic_elt(env, 6); // and
    v_275 = (v_276 == v_275 ? lisp_true : nil);
    goto v_210;
    v_275 = nil;
v_210:
    if (v_275 == nil) goto v_208;
    v_276 = v_277;
    v_275 = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // cl_cflip
    stack[-5] = (*qfn2(fn))(fn, v_276, v_275);
    }
    env = stack[-6];
    v_275 = stack[-2];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    stack[-3] = v_275;
    v_275 = stack[-3];
    if (v_275 == nil) goto v_235;
    else goto v_236;
v_235:
    v_275 = nil;
    goto v_229;
v_236:
    v_275 = stack[-3];
    if (!car_legal(v_275)) v_275 = carerror(v_275); else
    v_275 = car(v_275);
    v_276 = v_275;
    v_275 = stack[-4];
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    env = stack[-6];
    stack[-1] = v_275;
    stack[-2] = v_275;
v_230:
    v_275 = stack[-3];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    stack[-3] = v_275;
    v_275 = stack[-3];
    if (v_275 == nil) goto v_250;
    else goto v_251;
v_250:
    v_275 = stack[-2];
    goto v_229;
v_251:
    stack[0] = stack[-1];
    v_275 = stack[-3];
    if (!car_legal(v_275)) v_275 = carerror(v_275); else
    v_275 = car(v_275);
    v_276 = v_275;
    v_275 = stack[-4];
    v_275 = CC_cl_nnf1(basic_elt(env, 0), v_276, v_275);
    env = stack[-6];
    v_275 = ncons(v_275);
    env = stack[-6];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_275);
    v_275 = stack[-1];
    if (!car_legal(v_275)) v_275 = cdrerror(v_275); else
    v_275 = qcdr(v_275);
    stack[-1] = v_275;
    goto v_230;
v_229:
    {
        LispObject v_295 = stack[-5];
        return cons(v_295, v_275);
    }
v_208:
    v_275 = stack[-4];
    if (v_275 == nil) goto v_268;
    v_275 = stack[-2];
    goto v_266;
v_268:
    v_275 = stack[-2];
    {
        LispObject fn = basic_elt(env, 14); // rl_negateat
        return (*qfn1(fn))(fn, v_275);
    }
    v_275 = nil;
v_266:
    return onevalue(v_275);
}



// Code for iv_cutcongs2

static LispObject CC_iv_cutcongs2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_36, v_37, v_38;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_3;
    v_38 = v_2;
// end of prologue
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = carerror(v_36); else
    v_36 = car(v_36);
    if (!car_legal(v_36)) v_37 = carerror(v_36); else
    v_37 = car(v_36);
    v_36 = basic_elt(env, 1); // cong
    if (v_37 == v_36) goto v_7;
    else goto v_8;
v_7:
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    v_37 = v_38;
    v_37 = difference2(v_36, v_37);
    env = stack[-1];
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = carerror(v_36); else
    v_36 = car(v_36);
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    v_37 = Cremainder(v_37, v_36);
    v_36 = (LispObject)0+TAG_FIXNUM; // 0
    v_36 = (v_37 == v_36 ? lisp_true : nil);
    goto v_6;
v_8:
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    v_37 = v_38;
    v_37 = difference2(v_36, v_37);
    env = stack[-1];
    v_36 = stack[0];
    if (!car_legal(v_36)) v_36 = carerror(v_36); else
    v_36 = car(v_36);
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = qcdr(v_36);
    v_37 = Cremainder(v_37, v_36);
    v_36 = (LispObject)0+TAG_FIXNUM; // 0
    v_36 = (v_37 == v_36 ? lisp_true : nil);
    v_36 = (v_36 == nil ? lisp_true : nil);
    goto v_6;
    v_36 = nil;
v_6:
    return onevalue(v_36);
}



// Code for intervalrd

static LispObject CC_intervalrd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_31, v_32;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// end of prologue
    v_32 = qvalue(basic_elt(env, 1)); // atts
    v_31 = basic_elt(env, 2); // (closure)
    {   LispObject fn = basic_elt(env, 7); // retattributes
    v_31 = (*qfn2(fn))(fn, v_32, v_31);
    }
    env = stack[-4];
    stack[0] = v_31;
    {   LispObject fn = basic_elt(env, 8); // mathml
    v_31 = (*qfn0(fn))(fn);
    }
    env = stack[-4];
    stack[-3] = v_31;
    {   LispObject fn = basic_elt(env, 8); // mathml
    v_31 = (*qfn0(fn))(fn);
    }
    env = stack[-4];
    stack[-2] = v_31;
    {   LispObject fn = basic_elt(env, 9); // lex
    v_31 = (*qfn0(fn))(fn);
    }
    env = stack[-4];
    v_32 = qvalue(basic_elt(env, 3)); // char
    v_31 = basic_elt(env, 4); // (!/ i n t e r v a l)
    if (equal(v_32, v_31)) goto v_16;
    else goto v_17;
v_16:
    stack[-1] = basic_elt(env, 5); // interval
    v_32 = stack[-3];
    v_31 = stack[-2];
    v_31 = list2(v_32, v_31);
    {
        LispObject v_37 = stack[-1];
        LispObject v_38 = stack[0];
        return list2star(v_37, v_38, v_31);
    }
v_17:
    v_32 = basic_elt(env, 6); // "</interval>"
    v_31 = (LispObject)32+TAG_FIXNUM; // 2
    {   LispObject fn = basic_elt(env, 10); // errorml
    v_31 = (*qfn2(fn))(fn, v_32, v_31);
    }
    goto v_15;
v_15:
    v_31 = nil;
    return onevalue(v_31);
}



// Code for compl

static LispObject CC_compl(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_32, v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_34 = nil;
v_8:
    v_32 = stack[-1];
    if (v_32 == nil) goto v_11;
    else goto v_12;
v_11:
    v_32 = v_34;
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_32);
    }
v_12:
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_33 = carerror(v_32); else
    v_33 = car(v_32);
    v_32 = stack[0];
    v_32 = Lmember(nil, v_33, v_32);
    if (v_32 == nil) goto v_17;
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = qcdr(v_32);
    stack[-1] = v_32;
    goto v_8;
v_17:
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = car(v_32);
    v_33 = v_34;
    v_32 = cons(v_32, v_33);
    env = stack[-2];
    v_34 = v_32;
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = qcdr(v_32);
    stack[-1] = v_32;
    goto v_8;
    v_32 = nil;
    return onevalue(v_32);
}



// Code for dipcontevmin

static LispObject CC_dipcontevmin(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_58, v_59, v_60;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_60 = nil;
v_10:
    v_58 = stack[-1];
    if (v_58 == nil) goto v_13;
    v_58 = stack[0];
    if (v_58 == nil) goto v_13;
    goto v_14;
v_13:
    goto v_9;
v_14:
    v_58 = stack[-1];
    if (!car_legal(v_58)) v_59 = carerror(v_58); else
    v_59 = car(v_58);
    v_58 = stack[0];
    if (!car_legal(v_58)) v_58 = carerror(v_58); else
    v_58 = car(v_58);
    if (((intptr_t)(v_59)) < ((intptr_t)(v_58))) goto v_23;
    else goto v_24;
v_23:
    v_58 = stack[-1];
    if (!car_legal(v_58)) v_58 = carerror(v_58); else
    v_58 = car(v_58);
    goto v_22;
v_24:
    v_58 = stack[0];
    if (!car_legal(v_58)) v_58 = carerror(v_58); else
    v_58 = car(v_58);
    goto v_22;
    v_58 = nil;
v_22:
    v_59 = v_60;
    v_58 = cons(v_58, v_59);
    env = stack[-2];
    v_60 = v_58;
    v_58 = stack[-1];
    if (!car_legal(v_58)) v_58 = cdrerror(v_58); else
    v_58 = qcdr(v_58);
    stack[-1] = v_58;
    v_58 = stack[0];
    if (!car_legal(v_58)) v_58 = cdrerror(v_58); else
    v_58 = qcdr(v_58);
    stack[0] = v_58;
    goto v_10;
v_9:
v_42:
    v_58 = v_60;
    if (v_58 == nil) goto v_45;
    v_59 = (LispObject)0+TAG_FIXNUM; // 0
    v_58 = v_60;
    if (!car_legal(v_58)) v_58 = carerror(v_58); else
    v_58 = car(v_58);
    if (v_59 == v_58) goto v_49;
    else goto v_45;
v_49:
    goto v_46;
v_45:
    goto v_41;
v_46:
    v_58 = v_60;
    if (!car_legal(v_58)) v_58 = cdrerror(v_58); else
    v_58 = qcdr(v_58);
    v_60 = v_58;
    goto v_42;
v_41:
    v_58 = v_60;
        return Lnreverse(nil, v_58);
    return onevalue(v_58);
}



// Code for mk_binding

static LispObject CC_mk_binding(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_20, v_21;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_20 = stack[-1];
    if (!car_legal(v_20)) v_21 = carerror(v_20); else
    v_21 = car(v_20);
    v_20 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // can_be_proved
    v_20 = (*qfn2(fn))(fn, v_21, v_20);
    }
    env = stack[-2];
    if (v_20 == nil) goto v_7;
    else goto v_8;
v_7:
    v_20 = nil;
    goto v_6;
v_8:
    v_20 = stack[-1];
    if (!car_legal(v_20)) v_21 = cdrerror(v_20); else
    v_21 = qcdr(v_20);
    v_20 = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // edge_bind
        return (*qfn2(fn))(fn, v_21, v_20);
    }
    v_20 = nil;
v_6:
    return onevalue(v_20);
}



// Code for equiv!-coeffs

static LispObject CC_equivKcoeffs(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_59, v_60;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    stack[-2] = nil;
v_8:
    v_59 = stack[-1];
    if (v_59 == nil) goto v_11;
    else goto v_12;
v_11:
    stack[-1] = stack[-2];
    v_59 = stack[0];
    v_59 = Llength(nil, v_59);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 1); // nzeros
    v_59 = (*qfn1(fn))(fn, v_59);
    }
    env = stack[-3];
    {
        LispObject v_64 = stack[-1];
        LispObject fn = basic_elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_64, v_59);
    }
v_12:
    v_59 = stack[0];
    if (v_59 == nil) goto v_19;
    else goto v_20;
v_19:
    v_59 = stack[-2];
    {
        LispObject fn = basic_elt(env, 2); // nreverse
        return (*qfn1(fn))(fn, v_59);
    }
v_20:
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    if (!car_legal(v_59)) v_60 = carerror(v_59); else
    v_60 = car(v_59);
    v_59 = stack[0];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    if (equal(v_60, v_59)) goto v_24;
    else goto v_25;
v_24:
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    if (!car_legal(v_59)) v_60 = cdrerror(v_59); else
    v_60 = qcdr(v_59);
    v_59 = stack[-2];
    v_59 = cons(v_60, v_59);
    env = stack[-3];
    stack[-2] = v_59;
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[-1] = v_59;
    v_59 = stack[0];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[0] = v_59;
    goto v_8;
v_25:
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    if (!car_legal(v_59)) v_60 = carerror(v_59); else
    v_60 = car(v_59);
    v_59 = stack[0];
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    if (!car_legal(v_59)) v_59 = carerror(v_59); else
    v_59 = car(v_59);
    {   LispObject fn = basic_elt(env, 3); // mv!-pow!-!>
    v_59 = (*qfn2(fn))(fn, v_60, v_59);
    }
    env = stack[-3];
    if (v_59 == nil) goto v_42;
    v_59 = stack[-1];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[-1] = v_59;
    goto v_8;
v_42:
    v_60 = (LispObject)0+TAG_FIXNUM; // 0
    v_59 = stack[-2];
    v_59 = cons(v_60, v_59);
    env = stack[-3];
    stack[-2] = v_59;
    v_59 = stack[0];
    if (!car_legal(v_59)) v_59 = cdrerror(v_59); else
    v_59 = qcdr(v_59);
    stack[0] = v_59;
    goto v_8;
    v_59 = nil;
    return onevalue(v_59);
}



// Code for lesspcar

static LispObject CC_lesspcar(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    if (!car_legal(v_11)) v_11 = carerror(v_11); else
    v_11 = car(v_11);
    if (!car_legal(v_10)) v_10 = carerror(v_10); else
    v_10 = car(v_10);
        return Llessp_2(nil, v_11, v_10);
}



// Code for rl_qe

static LispObject CC_rl_qe(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    stack[0] = qvalue(basic_elt(env, 1)); // rl_qe!*
    v_10 = list2(v_11, v_10);
    env = stack[-1];
    {
        LispObject v_13 = stack[0];
        LispObject fn = basic_elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13, v_10);
    }
}



// Code for mk!+mat!+plus!+mat

static LispObject CC_mkLmatLplusLmat(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_215, v_216, v_217;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(14);
// copy arguments values to proper place
    stack[-10] = v_3;
    stack[-11] = v_2;
// end of prologue
    v_215 = stack[-11];
    {   LispObject fn = basic_elt(env, 4); // matrix!+p
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    if (v_215 == nil) goto v_15;
    else goto v_16;
v_15:
    v_215 = basic_elt(env, 1); // "no matrix in add"
    {   LispObject fn = basic_elt(env, 5); // rederr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    goto v_14;
v_16:
v_14:
    v_215 = stack[-10];
    {   LispObject fn = basic_elt(env, 4); // matrix!+p
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    if (v_215 == nil) goto v_23;
    else goto v_24;
v_23:
    v_215 = basic_elt(env, 1); // "no matrix in add"
    {   LispObject fn = basic_elt(env, 5); // rederr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    goto v_22;
v_24:
v_22:
    v_215 = stack[-11];
    {   LispObject fn = basic_elt(env, 6); // get!+col!+nr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    stack[-12] = v_215;
    v_215 = stack[-11];
    {   LispObject fn = basic_elt(env, 7); // get!+row!+nr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    stack[-9] = v_215;
    stack[0] = stack[-12];
    v_215 = stack[-10];
    {   LispObject fn = basic_elt(env, 6); // get!+col!+nr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    if (equal(stack[0], v_215)) goto v_36;
    v_215 = basic_elt(env, 2); // "wrong dimensions in add"
    {   LispObject fn = basic_elt(env, 5); // rederr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    goto v_34;
v_36:
v_34:
    stack[0] = stack[-9];
    v_215 = stack[-10];
    {   LispObject fn = basic_elt(env, 7); // get!+row!+nr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    if (equal(stack[0], v_215)) goto v_45;
    v_215 = basic_elt(env, 2); // "wrong dimensions in add"
    {   LispObject fn = basic_elt(env, 5); // rederr
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    goto v_43;
v_45:
v_43:
    v_215 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-8] = v_215;
    v_216 = stack[-9];
    v_215 = stack[-8];
    v_215 = difference2(v_216, v_215);
    env = stack[-13];
    v_215 = Lminusp(nil, v_215);
    env = stack[-13];
    if (v_215 == nil) goto v_61;
    v_215 = nil;
    goto v_55;
v_61:
    v_215 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_215;
    v_216 = stack[-12];
    v_215 = stack[-4];
    v_215 = difference2(v_216, v_215);
    env = stack[-13];
    v_215 = Lminusp(nil, v_215);
    env = stack[-13];
    if (v_215 == nil) goto v_78;
    v_215 = nil;
    goto v_72;
v_78:
    v_217 = stack[-11];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    v_217 = stack[-10];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    v_215 = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    {   LispObject fn = basic_elt(env, 9); // addsq
    v_215 = (*qfn2(fn))(fn, stack[0], v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    v_215 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    setvalue(basic_elt(env, 3), v_215); // !*sub2
    v_215 = v_216;
    {   LispObject fn = basic_elt(env, 10); // subs2
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    ;}  // end of a binding scope
    v_215 = v_216;
    v_215 = ncons(v_215);
    env = stack[-13];
    stack[-2] = v_215;
    stack[-3] = v_215;
v_73:
    v_215 = stack[-4];
    v_215 = add1(v_215);
    env = stack[-13];
    stack[-4] = v_215;
    v_216 = stack[-12];
    v_215 = stack[-4];
    v_215 = difference2(v_216, v_215);
    env = stack[-13];
    v_215 = Lminusp(nil, v_215);
    env = stack[-13];
    if (v_215 == nil) goto v_106;
    v_215 = stack[-3];
    goto v_72;
v_106:
    stack[-1] = stack[-2];
    v_217 = stack[-11];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    v_217 = stack[-10];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    v_215 = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    {   LispObject fn = basic_elt(env, 9); // addsq
    v_215 = (*qfn2(fn))(fn, stack[0], v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    v_215 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    setvalue(basic_elt(env, 3), v_215); // !*sub2
    v_215 = v_216;
    {   LispObject fn = basic_elt(env, 10); // subs2
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    ;}  // end of a binding scope
    v_215 = v_216;
    v_215 = ncons(v_215);
    env = stack[-13];
    if (!car_legal(stack[-1])) rplacd_fails(stack[-1]);
    setcdr(stack[-1], v_215);
    v_215 = stack[-2];
    if (!car_legal(v_215)) v_215 = cdrerror(v_215); else
    v_215 = qcdr(v_215);
    stack[-2] = v_215;
    goto v_73;
v_72:
    v_215 = ncons(v_215);
    env = stack[-13];
    stack[-6] = v_215;
    stack[-7] = v_215;
v_56:
    v_215 = stack[-8];
    v_215 = add1(v_215);
    env = stack[-13];
    stack[-8] = v_215;
    v_216 = stack[-9];
    v_215 = stack[-8];
    v_215 = difference2(v_216, v_215);
    env = stack[-13];
    v_215 = Lminusp(nil, v_215);
    env = stack[-13];
    if (v_215 == nil) goto v_138;
    v_215 = stack[-7];
    goto v_55;
v_138:
    stack[-5] = stack[-6];
    v_215 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_215;
    v_216 = stack[-12];
    v_215 = stack[-4];
    v_215 = difference2(v_216, v_215);
    env = stack[-13];
    v_215 = Lminusp(nil, v_215);
    env = stack[-13];
    if (v_215 == nil) goto v_156;
    v_215 = nil;
    goto v_150;
v_156:
    v_217 = stack[-11];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    v_217 = stack[-10];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    v_215 = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    {   LispObject fn = basic_elt(env, 9); // addsq
    v_215 = (*qfn2(fn))(fn, stack[0], v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    v_215 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    setvalue(basic_elt(env, 3), v_215); // !*sub2
    v_215 = v_216;
    {   LispObject fn = basic_elt(env, 10); // subs2
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    ;}  // end of a binding scope
    v_215 = v_216;
    v_215 = ncons(v_215);
    env = stack[-13];
    stack[-2] = v_215;
    stack[-3] = v_215;
v_151:
    v_215 = stack[-4];
    v_215 = add1(v_215);
    env = stack[-13];
    stack[-4] = v_215;
    v_216 = stack[-12];
    v_215 = stack[-4];
    v_215 = difference2(v_216, v_215);
    env = stack[-13];
    v_215 = Lminusp(nil, v_215);
    env = stack[-13];
    if (v_215 == nil) goto v_184;
    v_215 = stack[-3];
    goto v_150;
v_184:
    stack[-1] = stack[-2];
    v_217 = stack[-11];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    stack[0] = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    v_217 = stack[-10];
    v_216 = stack[-8];
    v_215 = stack[-4];
    {   LispObject fn = basic_elt(env, 8); // get!+mat!+entry
    v_215 = (*qfn3(fn))(fn, v_217, v_216, v_215);
    }
    env = stack[-13];
    {   LispObject fn = basic_elt(env, 9); // addsq
    v_215 = (*qfn2(fn))(fn, stack[0], v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    v_215 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=13 litvec-offset=3 saveloc=0
{   bind_fluid_stack bind_fluid_var(-13, 3, 0);
    setvalue(basic_elt(env, 3), v_215); // !*sub2
    v_215 = v_216;
    {   LispObject fn = basic_elt(env, 10); // subs2
    v_215 = (*qfn1(fn))(fn, v_215);
    }
    env = stack[-13];
    v_216 = v_215;
    ;}  // end of a binding scope
    v_215 = v_216;
    v_215 = ncons(v_215);
    env = stack[-13];
    if (!car_legal(stack[-1])) rplacd_fails(stack[-1]);
    setcdr(stack[-1], v_215);
    v_215 = stack[-2];
    if (!car_legal(v_215)) v_215 = cdrerror(v_215); else
    v_215 = qcdr(v_215);
    stack[-2] = v_215;
    goto v_151;
v_150:
    v_215 = ncons(v_215);
    env = stack[-13];
    if (!car_legal(stack[-5])) rplacd_fails(stack[-5]);
    setcdr(stack[-5], v_215);
    v_215 = stack[-6];
    if (!car_legal(v_215)) v_215 = cdrerror(v_215); else
    v_215 = qcdr(v_215);
    stack[-6] = v_215;
    goto v_56;
v_55:
    return onevalue(v_215);
}



// Code for repr_ldeg

static LispObject CC_repr_ldeg(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10 = v_2;
// end of prologue
    if (!car_legal(v_10)) v_10 = cdrerror(v_10); else
    v_10 = qcdr(v_10);
    if (!car_legal(v_10)) v_10 = cdrerror(v_10); else
    v_10 = qcdr(v_10);
    if (!car_legal(v_10)) v_10 = cdrerror(v_10); else
    v_10 = qcdr(v_10);
    if (!car_legal(v_10)) v_10 = cdrerror(v_10); else
    v_10 = qcdr(v_10);
    if (!car_legal(v_10)) v_10 = carerror(v_10); else
    v_10 = car(v_10);
    return onevalue(v_10);
}



// Code for transposerd

static LispObject CC_transposerd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // mathml
    v_10 = (*qfn0(fn))(fn);
    }
    env = stack[-1];
    stack[0] = v_10;
    {   LispObject fn = basic_elt(env, 2); // lex
    v_10 = (*qfn0(fn))(fn);
    }
    v_10 = stack[0];
    return ncons(v_10);
    return onevalue(v_10);
}



// Code for prlist

static LispObject CC_prlist(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_30, v_31;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_31 = nil;
v_7:
    v_30 = stack[0];
    if (v_30 == nil) goto v_10;
    else goto v_11;
v_10:
    v_30 = v_31;
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30);
    }
v_11:
    v_30 = stack[0];
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    v_30 = Lconsp(nil, v_30);
    env = stack[-1];
    if (v_30 == nil) goto v_16;
    v_30 = stack[0];
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    v_30 = cons(v_30, v_31);
    env = stack[-1];
    v_31 = v_30;
    v_30 = stack[0];
    if (!car_legal(v_30)) v_30 = cdrerror(v_30); else
    v_30 = qcdr(v_30);
    stack[0] = v_30;
    goto v_7;
v_16:
    v_30 = stack[0];
    if (!car_legal(v_30)) v_30 = cdrerror(v_30); else
    v_30 = qcdr(v_30);
    stack[0] = v_30;
    goto v_7;
    v_30 = nil;
    return onevalue(v_30);
}



// Code for extbrsea

static LispObject CC_extbrsea(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_145, v_146, v_147;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// end of prologue
    v_145 = qvalue(basic_elt(env, 1)); // rowmin
    stack[-1] = v_145;
v_9:
    v_146 = qvalue(basic_elt(env, 2)); // rowmax
    v_145 = stack[-1];
    v_145 = difference2(v_146, v_145);
    env = stack[-2];
    v_145 = Lminusp(nil, v_145);
    env = stack[-2];
    if (v_145 == nil) goto v_14;
    goto v_8;
v_14:
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_146 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_145 = (LispObject)48+TAG_FIXNUM; // 3
    v_146 = Lgetv(nil, v_146, v_145);
    env = stack[-2];
    v_145 = (LispObject)-16+TAG_FIXNUM; // -1
    if (v_146 == v_145) goto v_26;
    else goto v_27;
v_26:
    v_145 = lisp_true;
    goto v_25;
v_27:
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_146 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_145 = (LispObject)48+TAG_FIXNUM; // 3
    v_146 = Lgetv(nil, v_146, v_145);
    env = stack[-2];
    v_145 = (LispObject)-32+TAG_FIXNUM; // -2
    v_145 = (v_146 == v_145 ? lisp_true : nil);
    goto v_25;
    v_145 = nil;
v_25:
    if (v_145 == nil) goto v_23;
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_147 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_146 = (LispObject)0+TAG_FIXNUM; // 0
    v_145 = nil;
    v_145 = Lputv(nil, v_147, v_146, v_145);
    env = stack[-2];
    goto v_21;
v_23:
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_147 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_146 = (LispObject)0+TAG_FIXNUM; // 0
    v_145 = lisp_true;
    v_145 = Lputv(nil, v_147, v_146, v_145);
    env = stack[-2];
    goto v_21;
v_21:
    v_145 = stack[-1];
    v_145 = add1(v_145);
    env = stack[-2];
    stack[-1] = v_145;
    goto v_9;
v_8:
    {   LispObject fn = basic_elt(env, 6); // initbrsea
    v_145 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 7); // extbrsea1
    v_145 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
v_72:
    {   LispObject fn = basic_elt(env, 8); // expandprod
    v_145 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    v_145 = qvalue(basic_elt(env, 1)); // rowmin
    stack[-1] = v_145;
v_77:
    v_146 = qvalue(basic_elt(env, 2)); // rowmax
    v_145 = stack[-1];
    v_145 = difference2(v_146, v_145);
    env = stack[-2];
    v_145 = Lminusp(nil, v_145);
    env = stack[-2];
    if (v_145 == nil) goto v_82;
    goto v_76;
v_82:
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_146 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_145 = (LispObject)48+TAG_FIXNUM; // 3
    v_146 = Lgetv(nil, v_146, v_145);
    env = stack[-2];
    v_145 = (LispObject)-16+TAG_FIXNUM; // -1
    if (v_146 == v_145) goto v_95;
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_146 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_145 = (LispObject)32+TAG_FIXNUM; // 2
    v_146 = Lgetv(nil, v_146, v_145);
    env = stack[-2];
    v_145 = basic_elt(env, 5); // times
    v_145 = (v_146 == v_145 ? lisp_true : nil);
    goto v_93;
v_95:
    v_145 = nil;
    goto v_93;
    v_145 = nil;
v_93:
    if (v_145 == nil) goto v_91;
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_147 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_146 = (LispObject)0+TAG_FIXNUM; // 0
    v_145 = lisp_true;
    v_145 = Lputv(nil, v_147, v_146, v_145);
    env = stack[-2];
    goto v_89;
v_91:
    stack[0] = qvalue(basic_elt(env, 3)); // codmat
    v_146 = qvalue(basic_elt(env, 4)); // maxvar
    v_145 = stack[-1];
    v_145 = plus2(v_146, v_145);
    env = stack[-2];
    v_147 = Lgetv(nil, stack[0], v_145);
    env = stack[-2];
    v_146 = (LispObject)0+TAG_FIXNUM; // 0
    v_145 = nil;
    v_145 = Lputv(nil, v_147, v_146, v_145);
    env = stack[-2];
    goto v_89;
v_89:
    v_145 = stack[-1];
    v_145 = add1(v_145);
    env = stack[-2];
    stack[-1] = v_145;
    goto v_77;
v_76:
    {   LispObject fn = basic_elt(env, 6); // initbrsea
    v_145 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 7); // extbrsea1
    v_145 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 9); // shrinkprod
    v_145 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    if (v_145 == nil) goto v_143;
    goto v_72;
v_143:
    v_145 = nil;
    return onevalue(v_145);
}



// Code for copy_mat

static LispObject CC_copy_mat(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_67, v_68, v_69;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(10);
// copy arguments values to proper place
    stack[-7] = v_2;
// end of prologue
    v_67 = stack[-7];
    {   LispObject fn = basic_elt(env, 1); // matrix_input_test
    v_67 = (*qfn1(fn))(fn, v_67);
    }
    env = stack[-9];
    v_67 = stack[-7];
    {   LispObject fn = basic_elt(env, 2); // size_of_matrix
    v_67 = (*qfn1(fn))(fn, v_67);
    }
    env = stack[-9];
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = car(v_67);
    stack[-6] = v_67;
    v_67 = stack[-7];
    {   LispObject fn = basic_elt(env, 2); // size_of_matrix
    v_67 = (*qfn1(fn))(fn, v_67);
    }
    env = stack[-9];
    if (!car_legal(v_67)) v_67 = cdrerror(v_67); else
    v_67 = qcdr(v_67);
    if (!car_legal(v_67)) v_67 = carerror(v_67); else
    v_67 = car(v_67);
    stack[-5] = v_67;
    v_68 = stack[-6];
    v_67 = stack[-5];
    {   LispObject fn = basic_elt(env, 3); // mkmatrix
    v_67 = (*qfn2(fn))(fn, v_68, v_67);
    }
    env = stack[-9];
    stack[-8] = v_67;
    v_67 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-4] = v_67;
v_26:
    v_68 = stack[-6];
    v_67 = stack[-4];
    v_67 = difference2(v_68, v_67);
    env = stack[-9];
    v_67 = Lminusp(nil, v_67);
    env = stack[-9];
    if (v_67 == nil) goto v_31;
    goto v_25;
v_31:
    v_67 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_67;
v_40:
    v_68 = stack[-5];
    v_67 = stack[-3];
    v_67 = difference2(v_68, v_67);
    env = stack[-9];
    v_67 = Lminusp(nil, v_67);
    env = stack[-9];
    if (v_67 == nil) goto v_45;
    goto v_39;
v_45:
    stack[-2] = stack[-8];
    stack[-1] = stack[-4];
    stack[0] = stack[-3];
    v_69 = stack[-7];
    v_68 = stack[-4];
    v_67 = stack[-3];
    {   LispObject fn = basic_elt(env, 4); // getmat
    v_67 = (*qfn3(fn))(fn, v_69, v_68, v_67);
    }
    env = stack[-9];
    v_67 = ncons(v_67);
    env = stack[-9];
    {   LispObject fn = basic_elt(env, 5); // setmat
    v_67 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_67);
    }
    env = stack[-9];
    v_67 = stack[-3];
    v_67 = add1(v_67);
    env = stack[-9];
    stack[-3] = v_67;
    goto v_40;
v_39:
    v_67 = stack[-4];
    v_67 = add1(v_67);
    env = stack[-9];
    stack[-4] = v_67;
    goto v_26;
v_25:
    v_67 = stack[-8];
    return onevalue(v_67);
}



// Code for exdf0

static LispObject CC_exdf0(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_19 = stack[0];
    if (!car_legal(v_19)) v_19 = carerror(v_19); else
    v_19 = car(v_19);
    {   LispObject fn = basic_elt(env, 1); // exdff0
    stack[-1] = (*qfn1(fn))(fn, v_19);
    }
    env = stack[-2];
    v_19 = stack[0];
    if (!car_legal(v_19)) v_19 = cdrerror(v_19); else
    v_19 = qcdr(v_19);
    {   LispObject fn = basic_elt(env, 2); // negf
    v_19 = (*qfn1(fn))(fn, v_19);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 1); // exdff0
    v_20 = (*qfn1(fn))(fn, v_19);
    }
    env = stack[-2];
    v_19 = stack[0];
    {   LispObject fn = basic_elt(env, 3); // multpfsq
    v_19 = (*qfn2(fn))(fn, v_20, v_19);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 4); // addpf
    stack[-1] = (*qfn2(fn))(fn, stack[-1], v_19);
    }
    env = stack[-2];
    v_20 = (LispObject)16+TAG_FIXNUM; // 1
    v_19 = stack[0];
    if (!car_legal(v_19)) v_19 = cdrerror(v_19); else
    v_19 = qcdr(v_19);
    v_19 = cons(v_20, v_19);
    env = stack[-2];
    {
        LispObject v_23 = stack[-1];
        LispObject fn = basic_elt(env, 3); // multpfsq
        return (*qfn2(fn))(fn, v_23, v_19);
    }
}



// Code for gbfdiff

static LispObject CC_gbfdiff(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_16, v_17;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_16 = stack[-1];
    if (!car_legal(v_16)) v_17 = carerror(v_16); else
    v_17 = car(v_16);
    v_16 = stack[0];
    if (!car_legal(v_16)) v_16 = carerror(v_16); else
    v_16 = car(v_16);
    {   LispObject fn = basic_elt(env, 1); // difbf
    stack[-2] = (*qfn2(fn))(fn, v_17, v_16);
    }
    env = stack[-3];
    v_16 = stack[-1];
    if (!car_legal(v_16)) v_17 = cdrerror(v_16); else
    v_17 = qcdr(v_16);
    v_16 = stack[0];
    if (!car_legal(v_16)) v_16 = cdrerror(v_16); else
    v_16 = qcdr(v_16);
    {   LispObject fn = basic_elt(env, 1); // difbf
    v_16 = (*qfn2(fn))(fn, v_17, v_16);
    }
    {
        LispObject v_21 = stack[-2];
        return cons(v_21, v_16);
    }
}



// Code for numprintlen

static LispObject CC_numprintlen(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_128, v_129;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-1] = v_2;
// end of prologue
v_6:
    v_128 = stack[-1];
    if (!consp(v_128)) goto v_9;
    else goto v_10;
v_9:
    v_128 = stack[-1];
    v_128 = Lexplode(nil, v_128);
        return Llength(nil, v_128);
v_10:
    v_128 = stack[-1];
    v_128 = Llength(nil, v_128);
    env = stack[-6];
    v_128 = Lonep(nil, v_128);
    env = stack[-6];
    if (v_128 == nil) goto v_16;
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    stack[-1] = v_128;
    goto v_6;
v_16:
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_129 = carerror(v_128); else
    v_129 = car(v_128);
    v_128 = basic_elt(env, 1); // !:rd!:
    if (v_129 == v_128) goto v_22;
    else goto v_23;
v_22:
    v_128 = stack[-1];
    {   LispObject fn = basic_elt(env, 4); // rd!:explode
    v_128 = (*qfn1(fn))(fn, v_128);
    }
    env = stack[-6];
    stack[-1] = v_128;
    stack[-2] = (LispObject)32+TAG_FIXNUM; // 2
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    stack[0] = Llength(nil, v_128);
    env = stack[-6];
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    v_128 = Lexplode(nil, v_128);
    env = stack[-6];
    v_128 = Llength(nil, v_128);
    env = stack[-6];
    v_128 = plus2(stack[0], v_128);
    {
        LispObject v_136 = stack[-2];
        return plus2(v_136, v_128);
    }
v_23:
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_129 = carerror(v_128); else
    v_129 = car(v_128);
    v_128 = basic_elt(env, 2); // (!:cr!: !:crn!: !:gi!:)
    v_128 = Lmemq(nil, v_129, v_128);
    if (v_128 == nil) goto v_41;
    v_129 = basic_elt(env, 1); // !:rd!:
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    v_128 = cons(v_129, v_128);
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 4); // rd!:explode
    stack[0] = (*qfn1(fn))(fn, v_128);
    }
    env = stack[-6];
    v_129 = basic_elt(env, 1); // !:rd!:
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    v_128 = cons(v_129, v_128);
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 4); // rd!:explode
    v_128 = (*qfn1(fn))(fn, v_128);
    }
    env = stack[-6];
    v_128 = cons(stack[0], v_128);
    env = stack[-6];
    stack[-1] = v_128;
    stack[-4] = (LispObject)192+TAG_FIXNUM; // 12
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    stack[-3] = Llength(nil, v_128);
    env = stack[-6];
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    v_128 = Lexplode(nil, v_128);
    env = stack[-6];
    stack[-2] = Llength(nil, v_128);
    env = stack[-6];
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    stack[0] = Llength(nil, v_128);
    env = stack[-6];
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    v_128 = Lexplode(nil, v_128);
    env = stack[-6];
    v_128 = Llength(nil, v_128);
    env = stack[-6];
    v_128 = plus2(stack[0], v_128);
    env = stack[-6];
    v_128 = plus2(stack[-2], v_128);
    env = stack[-6];
    v_128 = plus2(stack[-3], v_128);
    {
        LispObject v_137 = stack[-4];
        return plus2(v_137, v_128);
    }
v_41:
    v_128 = stack[-1];
    stack[-5] = Llength(nil, v_128);
    env = stack[-6];
    stack[-4] = basic_elt(env, 3); // plus
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    stack[-3] = v_128;
    v_128 = stack[-3];
    if (v_128 == nil) goto v_100;
    else goto v_101;
v_100:
    v_128 = nil;
    goto v_94;
v_101:
    v_128 = stack[-3];
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    v_128 = CC_numprintlen(basic_elt(env, 0), v_128);
    env = stack[-6];
    v_128 = ncons(v_128);
    env = stack[-6];
    stack[-1] = v_128;
    stack[-2] = v_128;
v_95:
    v_128 = stack[-3];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    stack[-3] = v_128;
    v_128 = stack[-3];
    if (v_128 == nil) goto v_114;
    else goto v_115;
v_114:
    v_128 = stack[-2];
    goto v_94;
v_115:
    stack[0] = stack[-1];
    v_128 = stack[-3];
    if (!car_legal(v_128)) v_128 = carerror(v_128); else
    v_128 = car(v_128);
    v_128 = CC_numprintlen(basic_elt(env, 0), v_128);
    env = stack[-6];
    v_128 = ncons(v_128);
    env = stack[-6];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_128);
    v_128 = stack[-1];
    if (!car_legal(v_128)) v_128 = cdrerror(v_128); else
    v_128 = qcdr(v_128);
    stack[-1] = v_128;
    goto v_95;
v_94:
    v_128 = cons(stack[-4], v_128);
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 5); // lispeval
    v_128 = (*qfn1(fn))(fn, v_128);
    }
    {
        LispObject v_138 = stack[-5];
        return plus2(v_138, v_128);
    }
    v_128 = nil;
    return onevalue(v_128);
}



// Code for formsetq0

static LispObject CC_formsetq0(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_315, v_316, v_317;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[-4] = v_4;
    stack[-5] = v_3;
    stack[-6] = v_2;
// end of prologue
    stack[-7] = nil;
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    stack[-6] = v_315;
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    stack[-3] = v_315;
    if (symbolp(v_315)) goto v_13;
    else goto v_14;
v_13:
    v_316 = stack[-3];
    v_315 = stack[-5];
    v_315 = Latsoc(nil, v_316, v_315);
    stack[-7] = v_315;
    goto v_12;
v_14:
v_12:
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) v_316 = carerror(v_315); else
    v_316 = car(v_315);
    v_315 = basic_elt(env, 1); // quote
    if (!consp(v_316)) goto v_24;
    v_316 = car(v_316);
    if (v_316 == v_315) goto v_23;
    else goto v_24;
v_23:
    v_315 = basic_elt(env, 2); // symbolic
    stack[-4] = v_315;
    goto v_22;
v_24:
v_22:
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) stack[-2] = carerror(v_315); else
    stack[-2] = car(v_315);
    stack[-1] = stack[-5];
    stack[0] = basic_elt(env, 2); // symbolic
    v_315 = stack[-4];
    v_315 = ncons(v_315);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 22); // convertmode
    v_315 = (*qfn4up(fn))(fn, stack[-2], stack[-1], stack[0], v_315);
    }
    env = stack[-8];
    stack[0] = v_315;
    v_315 = stack[-3];
    if (!consp(v_315)) goto v_46;
    v_315 = qvalue(basic_elt(env, 3)); // !*savedef
    if (v_315 == nil) goto v_51;
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_316 = carerror(v_315); else
    v_316 = car(v_315);
    v_315 = basic_elt(env, 4); // inline
    v_315 = get(v_316, v_315);
    env = stack[-8];
    if (v_315 == nil) goto v_55;
    else goto v_54;
v_55:
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_316 = carerror(v_315); else
    v_316 = car(v_315);
    v_315 = basic_elt(env, 5); // smacro
    v_315 = get(v_316, v_315);
    env = stack[-8];
    if (v_315 == nil) goto v_60;
    else goto v_54;
v_60:
    goto v_51;
v_54:
    v_315 = Lposn(nil);
    env = stack[-8];
    v_315 = (LispObject)zerop(v_315);
    v_315 = v_315 ? lisp_true : nil;
    env = stack[-8];
    if (v_315 == nil) goto v_67;
    else goto v_68;
v_67:
    v_315 = Lterpri(nil);
    env = stack[-8];
    goto v_66;
v_68:
v_66:
    v_315 = basic_elt(env, 6); // "+++ Assign via inline or smacro: "
    v_315 = Lprinc(nil, v_315);
    env = stack[-8];
    v_315 = stack[-3];
    v_315 = Lprint(nil, v_315);
    env = stack[-8];
    goto v_49;
v_51:
v_49:
    v_315 = lisp_true;
    goto v_44;
v_46:
    v_315 = nil;
    goto v_44;
    v_315 = nil;
v_44:
    if (v_315 == nil) goto v_42;
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    if (symbolp(v_315)) goto v_83;
    v_316 = stack[-3];
    v_315 = basic_elt(env, 7); // "assignment"
    {
        LispObject fn = basic_elt(env, 23); // typerr
        return (*qfn2(fn))(fn, v_316, v_315);
    }
v_83:
    v_316 = stack[-3];
    v_315 = stack[-4];
    {   LispObject fn = basic_elt(env, 24); // macrochk
    v_315 = (*qfn2(fn))(fn, v_316, v_315);
    }
    env = stack[-8];
    stack[-3] = v_315;
    if (!consp(v_315)) goto v_94;
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    {   LispObject fn = basic_elt(env, 25); // arrayp
    v_315 = (*qfn1(fn))(fn, v_315);
    }
    env = stack[-8];
    goto v_92;
v_94:
    v_315 = nil;
    goto v_92;
    v_315 = nil;
v_92:
    if (v_315 == nil) goto v_90;
    stack[-1] = basic_elt(env, 8); // setel
    v_317 = stack[-3];
    v_316 = stack[-5];
    v_315 = stack[-4];
    {   LispObject fn = basic_elt(env, 26); // intargfn
    v_316 = (*qfn3(fn))(fn, v_317, v_316, v_315);
    }
    v_315 = stack[0];
    {
        LispObject v_326 = stack[-1];
        return list3(v_326, v_316, v_315);
    }
v_90:
    v_315 = stack[-3];
    if (!consp(v_315)) goto v_116;
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (v_315 == nil) goto v_120;
    else goto v_121;
v_120:
    v_315 = nil;
    goto v_119;
v_121:
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    if (!symbolp(v_315)) v_316 = nil;
    else { v_316 = qfastgets(v_315);
           if (v_316 != nil) { v_316 = elt(v_316, 2); // rtype
#ifdef RECORD_GET
             if (v_316 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_316 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_316 == SPID_NOPROP) v_316 = nil; }}
#endif
    v_315 = basic_elt(env, 9); // vector
    if (v_316 == v_315) goto v_129;
    else goto v_130;
v_129:
    v_315 = lisp_true;
    goto v_128;
v_130:
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    v_315 = Lsimple_vectorp(nil, v_315);
    env = stack[-8];
    if (v_315 == nil) goto v_140;
    else goto v_139;
v_140:
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) v_316 = carerror(v_315); else
    v_316 = car(v_315);
    v_315 = basic_elt(env, 10); // vecfn
    v_315 = Lflagpcar(nil, v_316, v_315);
    env = stack[-8];
v_139:
    goto v_128;
    v_315 = nil;
v_128:
    goto v_119;
    v_315 = nil;
v_119:
    goto v_114;
v_116:
    v_315 = nil;
    goto v_114;
    v_315 = nil;
v_114:
    if (v_315 == nil) goto v_112;
    v_317 = stack[-6];
    v_316 = stack[-5];
    v_315 = stack[-4];
    {
        LispObject fn = basic_elt(env, 27); // putvect
        return (*qfn3(fn))(fn, v_317, v_316, v_315);
    }
v_112:
    v_316 = stack[-3];
    v_315 = basic_elt(env, 11); // part
    if (!consp(v_316)) goto v_158;
    v_316 = car(v_316);
    if (v_316 == v_315) goto v_157;
    else goto v_158;
v_157:
    stack[-2] = basic_elt(env, 12); // list
    v_315 = basic_elt(env, 13); // setpart!*
    stack[-1] = Lmkquote(nil, v_315);
    env = stack[-8];
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_317 = cdrerror(v_315); else
    v_317 = qcdr(v_315);
    v_316 = stack[-5];
    v_315 = stack[-4];
    {   LispObject fn = basic_elt(env, 28); // formlis
    v_315 = (*qfn3(fn))(fn, v_317, v_316, v_315);
    }
    env = stack[-8];
    v_316 = list2star(stack[-2], stack[-1], v_315);
    env = stack[-8];
    v_315 = stack[0];
    {
        LispObject fn = basic_elt(env, 29); // aconc
        return (*qfn2(fn))(fn, v_316, v_315);
    }
v_158:
    v_315 = stack[-3];
    if (!consp(v_315)) goto v_178;
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_316 = carerror(v_315); else
    v_316 = car(v_315);
    v_315 = basic_elt(env, 14); // setqfn
    v_315 = get(v_316, v_315);
    env = stack[-8];
    stack[-7] = v_315;
    goto v_176;
v_178:
    v_315 = nil;
    goto v_176;
    v_315 = nil;
v_176:
    if (v_315 == nil) goto v_174;
    stack[0] = stack[-7];
    v_315 = stack[-3];
    if (!car_legal(v_315)) v_316 = cdrerror(v_315); else
    v_316 = qcdr(v_315);
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    v_316 = Lappend_2(nil, v_316, v_315);
    env = stack[-8];
    v_315 = nil;
    {   LispObject fn = basic_elt(env, 30); // applsmacro
    v_317 = (*qfn3(fn))(fn, stack[0], v_316, v_315);
    }
    env = stack[-8];
    v_316 = stack[-5];
    v_315 = stack[-4];
    {
        LispObject fn = basic_elt(env, 31); // form1
        return (*qfn3(fn))(fn, v_317, v_316, v_315);
    }
v_174:
    v_316 = stack[-4];
    v_315 = basic_elt(env, 2); // symbolic
    if (v_316 == v_315) goto v_202;
    else goto v_203;
v_202:
    v_315 = qvalue(basic_elt(env, 15)); // !*rlisp88
    if (v_315 == nil) goto v_208;
    else goto v_207;
v_208:
    v_316 = stack[-3];
    v_315 = basic_elt(env, 16); // structfetch
    v_315 = Leqcar(nil, v_316, v_315);
    env = stack[-8];
v_207:
    goto v_201;
v_203:
    v_315 = nil;
    goto v_201;
    v_315 = nil;
v_201:
    if (v_315 == nil) goto v_199;
    stack[-1] = basic_elt(env, 17); // rsetf
    v_317 = stack[-3];
    v_316 = stack[-5];
    v_315 = stack[-4];
    {   LispObject fn = basic_elt(env, 31); // form1
    v_316 = (*qfn3(fn))(fn, v_317, v_316, v_315);
    }
    v_315 = stack[0];
    {
        LispObject v_327 = stack[-1];
        return list3(v_327, v_316, v_315);
    }
v_199:
    stack[-1] = basic_elt(env, 18); // setk
    v_317 = stack[-3];
    v_316 = stack[-5];
    v_315 = basic_elt(env, 19); // algebraic
    {   LispObject fn = basic_elt(env, 31); // form1
    v_316 = (*qfn3(fn))(fn, v_317, v_316, v_315);
    }
    v_315 = stack[0];
    {
        LispObject v_328 = stack[-1];
        return list3(v_328, v_316, v_315);
    }
    v_315 = nil;
    goto v_40;
v_42:
    v_315 = stack[-3];
    if (symbolp(v_315)) goto v_233;
    v_316 = stack[-3];
    v_315 = basic_elt(env, 7); // "assignment"
    {
        LispObject fn = basic_elt(env, 23); // typerr
        return (*qfn2(fn))(fn, v_316, v_315);
    }
v_233:
    v_316 = stack[-3];
    v_315 = basic_elt(env, 20); // reserved
    v_315 = Lflagp(nil, v_316, v_315);
    env = stack[-8];
    if (v_315 == nil) goto v_243;
    v_316 = stack[-3];
    v_315 = stack[-5];
    v_315 = Latsoc(nil, v_316, v_315);
    v_315 = (v_315 == nil ? lisp_true : nil);
    goto v_241;
v_243:
    v_315 = nil;
    goto v_241;
    v_315 = nil;
v_241:
    if (v_315 == nil) goto v_239;
    v_315 = stack[-3];
    {
        LispObject fn = basic_elt(env, 32); // rsverr
        return (*qfn1(fn))(fn, v_315);
    }
v_239:
    v_315 = stack[-3];
    if (!symbolp(v_315)) v_315 = nil;
    else { v_315 = qfastgets(v_315);
           if (v_315 != nil) { v_315 = elt(v_315, 17); // share
#ifdef RECORD_GET
             if (v_315 == SPID_NOPROP)
                record_get(elt(fastget_names, 17), 0),
                v_315 = nil;
             else record_get(elt(fastget_names, 17), 1),
                v_315 = lisp_true; }
           else record_get(elt(fastget_names, 17), 0); }
#else
             if (v_315 == SPID_NOPROP) v_315 = nil; else v_315 = lisp_true; }}
#endif
    if (v_315 == nil) goto v_257;
    v_316 = stack[-3];
    v_315 = stack[-5];
    {   LispObject fn = basic_elt(env, 33); // symbid
    v_316 = (*qfn2(fn))(fn, v_316, v_315);
    }
    env = stack[-8];
    v_315 = stack[0];
    {
        LispObject fn = basic_elt(env, 34); // mksetshare
        return (*qfn2(fn))(fn, v_316, v_315);
    }
v_257:
    v_316 = stack[-4];
    v_315 = basic_elt(env, 2); // symbolic
    if (v_316 == v_315) goto v_269;
    else goto v_270;
v_269:
    v_315 = lisp_true;
    goto v_268;
v_270:
    v_315 = stack[-7];
    if (v_315 == nil) goto v_278;
    else goto v_277;
v_278:
    v_316 = stack[0];
    v_315 = basic_elt(env, 1); // quote
    v_315 = Leqcar(nil, v_316, v_315);
    env = stack[-8];
v_277:
    goto v_268;
    v_315 = nil;
v_268:
    if (v_315 == nil) goto v_266;
    v_316 = stack[-3];
    v_315 = stack[-5];
    {   LispObject fn = basic_elt(env, 33); // symbid
    v_316 = (*qfn2(fn))(fn, v_316, v_315);
    }
    env = stack[-8];
    v_315 = stack[0];
    {
        LispObject fn = basic_elt(env, 35); // mksetq
        return (*qfn2(fn))(fn, v_316, v_315);
    }
v_266:
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    v_315 = Lsimple_vectorp(nil, v_315);
    env = stack[-8];
    if (v_315 == nil) goto v_290;
    else goto v_288;
v_290:
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) v_316 = carerror(v_315); else
    v_316 = car(v_315);
    v_315 = basic_elt(env, 10); // vecfn
    v_315 = Lflagpcar(nil, v_316, v_315);
    env = stack[-8];
    if (v_315 == nil) goto v_295;
    else goto v_288;
v_295:
    goto v_289;
v_288:
    stack[0] = basic_elt(env, 21); // setv
    v_315 = stack[-3];
    v_316 = Lmkquote(nil, v_315);
    v_315 = stack[-6];
    if (!car_legal(v_315)) v_315 = cdrerror(v_315); else
    v_315 = qcdr(v_315);
    if (!car_legal(v_315)) v_315 = carerror(v_315); else
    v_315 = car(v_315);
    {
        LispObject v_329 = stack[0];
        return list3(v_329, v_316, v_315);
    }
v_289:
    stack[-1] = basic_elt(env, 18); // setk
    v_315 = stack[-3];
    v_316 = Lmkquote(nil, v_315);
    v_315 = stack[0];
    {
        LispObject v_330 = stack[-1];
        return list3(v_330, v_316, v_315);
    }
    v_315 = nil;
v_40:
    return onevalue(v_315);
}



// Code for simp!-prop!-dist

static LispObject CC_simpKpropKdist(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_101, v_102, v_103;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_102 = v_2;
// end of prologue
    v_103 = v_102;
    v_101 = basic_elt(env, 1); // plus
    if (!consp(v_103)) goto v_7;
    v_103 = car(v_103);
    if (v_103 == v_101) goto v_6;
    else goto v_7;
v_6:
    v_101 = v_102;
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    v_102 = v_101;
    goto v_5;
v_7:
    v_101 = v_102;
    v_101 = ncons(v_101);
    env = stack[-4];
    v_102 = v_101;
    goto v_5;
v_5:
    v_101 = v_102;
    stack[-3] = v_101;
    v_101 = stack[-3];
    if (v_101 == nil) goto v_26;
    else goto v_27;
v_26:
    v_101 = nil;
    goto v_21;
v_27:
    v_101 = stack[-3];
    if (!car_legal(v_101)) v_101 = carerror(v_101); else
    v_101 = car(v_101);
    v_103 = v_101;
    v_102 = v_103;
    v_101 = basic_elt(env, 2); // times
    if (!consp(v_102)) goto v_37;
    v_102 = car(v_102);
    if (v_102 == v_101) goto v_36;
    else goto v_37;
v_36:
    v_101 = v_103;
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    goto v_35;
v_37:
    v_101 = v_103;
    v_101 = ncons(v_101);
    env = stack[-4];
    goto v_35;
    v_101 = nil;
v_35:
    v_103 = v_101;
    v_101 = v_103;
    if (!car_legal(v_101)) v_101 = carerror(v_101); else
    v_101 = car(v_101);
    if (is_number(v_101)) goto v_49;
    else goto v_50;
v_49:
    v_101 = v_103;
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    v_103 = v_101;
    goto v_48;
v_50:
v_48:
    v_102 = v_103;
    v_101 = basic_elt(env, 3); // lambda_iff2c8okfzyq1
    {   LispObject fn = basic_elt(env, 5); // sort
    v_101 = (*qfn2(fn))(fn, v_102, v_101);
    }
    env = stack[-4];
    v_101 = ncons(v_101);
    env = stack[-4];
    stack[-1] = v_101;
    stack[-2] = v_101;
v_22:
    v_101 = stack[-3];
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    stack[-3] = v_101;
    v_101 = stack[-3];
    if (v_101 == nil) goto v_62;
    else goto v_63;
v_62:
    v_101 = stack[-2];
    goto v_21;
v_63:
    stack[0] = stack[-1];
    v_101 = stack[-3];
    if (!car_legal(v_101)) v_101 = carerror(v_101); else
    v_101 = car(v_101);
    v_103 = v_101;
    v_102 = v_103;
    v_101 = basic_elt(env, 2); // times
    if (!consp(v_102)) goto v_74;
    v_102 = car(v_102);
    if (v_102 == v_101) goto v_73;
    else goto v_74;
v_73:
    v_101 = v_103;
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    goto v_72;
v_74:
    v_101 = v_103;
    v_101 = ncons(v_101);
    env = stack[-4];
    goto v_72;
    v_101 = nil;
v_72:
    v_103 = v_101;
    v_101 = v_103;
    if (!car_legal(v_101)) v_101 = carerror(v_101); else
    v_101 = car(v_101);
    if (is_number(v_101)) goto v_86;
    else goto v_87;
v_86:
    v_101 = v_103;
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    v_103 = v_101;
    goto v_85;
v_87:
v_85:
    v_102 = v_103;
    v_101 = basic_elt(env, 3); // lambda_iff2c8okfzyq1
    {   LispObject fn = basic_elt(env, 5); // sort
    v_101 = (*qfn2(fn))(fn, v_102, v_101);
    }
    env = stack[-4];
    v_101 = ncons(v_101);
    env = stack[-4];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_101);
    v_101 = stack[-1];
    if (!car_legal(v_101)) v_101 = cdrerror(v_101); else
    v_101 = qcdr(v_101);
    stack[-1] = v_101;
    goto v_22;
v_21:
    v_102 = v_101;
    v_101 = basic_elt(env, 4); // simp!-prop!-order
    {
        LispObject fn = basic_elt(env, 5); // sort
        return (*qfn2(fn))(fn, v_102, v_101);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_3;
    v_13 = v_2;
// end of prologue
    if (!car_legal(v_13)) v_13 = cdrerror(v_13); else
    v_13 = qcdr(v_13);
    if (!car_legal(v_13)) v_13 = carerror(v_13); else
    v_13 = car(v_13);
    if (!car_legal(v_12)) v_12 = cdrerror(v_12); else
    v_12 = qcdr(v_12);
    if (!car_legal(v_12)) v_12 = carerror(v_12); else
    v_12 = car(v_12);
    {
        LispObject fn = basic_elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for lambda_iff2c8okfzyq1

static LispObject CC1_lambda_iff2c8okfzyq1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_12 = v_3;
    v_13 = v_2;
// end of prologue
    if (!car_legal(v_13)) v_13 = cdrerror(v_13); else
    v_13 = qcdr(v_13);
    if (!car_legal(v_13)) v_13 = carerror(v_13); else
    v_13 = car(v_13);
    if (!car_legal(v_12)) v_12 = cdrerror(v_12); else
    v_12 = qcdr(v_12);
    if (!car_legal(v_12)) v_12 = carerror(v_12); else
    v_12 = car(v_12);
    {
        LispObject fn = basic_elt(env, 1); // ordp
        return (*qfn2(fn))(fn, v_13, v_12);
    }
}



// Code for simpquot

static LispObject CC_simpquot(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_151, v_152, v_153;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[-1] = v_2;
// end of prologue
    v_151 = stack[-1];
    {   LispObject fn = basic_elt(env, 7); // simpcar
    stack[0] = (*qfn1(fn))(fn, v_151);
    }
    env = stack[-3];
    v_151 = stack[-1];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    {   LispObject fn = basic_elt(env, 8); // simp
    v_151 = (*qfn1(fn))(fn, v_151);
    }
    env = stack[-3];
    stack[-2] = stack[0];
    stack[0] = v_151;
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    if (v_151 == nil) goto v_14;
    else goto v_15;
v_14:
    v_151 = stack[-2];
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    if (v_151 == nil) goto v_20;
    else goto v_21;
v_20:
    v_153 = basic_elt(env, 1); // alg
    v_152 = (LispObject)304+TAG_FIXNUM; // 19
    v_151 = basic_elt(env, 2); // "0/0 formed"
    {
        LispObject fn = basic_elt(env, 9); // rerror
        return (*qfn3(fn))(fn, v_153, v_152, v_151);
    }
v_21:
    v_153 = basic_elt(env, 1); // alg
    v_152 = (LispObject)320+TAG_FIXNUM; // 20
    v_151 = basic_elt(env, 3); // "Zero divisor"
    {
        LispObject fn = basic_elt(env, 9); // rerror
        return (*qfn3(fn))(fn, v_153, v_152, v_151);
    }
    v_151 = nil;
    goto v_13;
v_15:
    v_152 = qvalue(basic_elt(env, 4)); // dmode!*
    v_151 = basic_elt(env, 5); // (!:rd!: !:cr!:)
    v_151 = Lmemq(nil, v_152, v_151);
    if (v_151 == nil) goto v_35;
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    if (!consp(v_151)) goto v_47;
    else goto v_48;
v_47:
    v_151 = lisp_true;
    goto v_46;
v_48:
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    v_151 = (consp(v_151) ? nil : lisp_true);
    goto v_46;
    v_151 = nil;
v_46:
    if (v_151 == nil) goto v_44;
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    if (!consp(v_151)) goto v_64;
    else goto v_65;
v_64:
    v_151 = lisp_true;
    goto v_63;
v_65:
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    v_151 = (consp(v_151) ? nil : lisp_true);
    goto v_63;
    v_151 = nil;
v_63:
    if (v_151 == nil) goto v_61;
    v_151 = stack[-2];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    if (!consp(v_151)) goto v_81;
    else goto v_82;
v_81:
    v_151 = lisp_true;
    goto v_80;
v_82:
    v_151 = stack[-2];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    v_151 = (consp(v_151) ? nil : lisp_true);
    goto v_80;
    v_151 = nil;
v_80:
    if (v_151 == nil) goto v_78;
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    {   LispObject fn = basic_elt(env, 10); // !:onep
    v_151 = (*qfn1(fn))(fn, v_151);
    }
    env = stack[-3];
    if (v_151 == nil) goto v_94;
    else goto v_95;
v_94:
    v_151 = nil;
    goto v_93;
v_95:
    v_151 = stack[-2];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    {   LispObject fn = basic_elt(env, 10); // !:onep
    v_151 = (*qfn1(fn))(fn, v_151);
    }
    env = stack[-3];
    goto v_93;
    v_151 = nil;
v_93:
    goto v_76;
v_78:
    v_151 = nil;
    goto v_76;
    v_151 = nil;
v_76:
    goto v_59;
v_61:
    v_151 = nil;
    goto v_59;
    v_151 = nil;
v_59:
    goto v_42;
v_44:
    v_151 = nil;
    goto v_42;
    v_151 = nil;
v_42:
    if (v_151 == nil) goto v_35;
    v_151 = stack[-2];
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    if (v_151 == nil) goto v_117;
    else goto v_118;
v_117:
    v_151 = nil;
    v_152 = v_151;
    goto v_116;
v_118:
    v_151 = stack[-2];
    if (!car_legal(v_151)) v_152 = carerror(v_151); else
    v_152 = car(v_151);
    v_151 = stack[0];
    if (!car_legal(v_151)) v_151 = carerror(v_151); else
    v_151 = car(v_151);
    {   LispObject fn = basic_elt(env, 11); // divd
    v_151 = (*qfn2(fn))(fn, v_152, v_151);
    }
    v_152 = v_151;
    goto v_116;
    v_152 = nil;
v_116:
    v_151 = (LispObject)16+TAG_FIXNUM; // 1
    return cons(v_152, v_151);
v_35:
    stack[0] = stack[-2];
    v_151 = stack[-1];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    {   LispObject fn = basic_elt(env, 12); // simprecip
    v_151 = (*qfn1(fn))(fn, v_151);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // multsq
    v_151 = (*qfn2(fn))(fn, stack[0], v_151);
    }
    env = stack[-3];
    stack[-1] = v_151;
    v_151 = qvalue(basic_elt(env, 6)); // !*modular
    if (v_151 == nil) goto v_140;
    v_151 = stack[-1];
    if (!car_legal(v_151)) v_151 = cdrerror(v_151); else
    v_151 = qcdr(v_151);
    if (v_151 == nil) goto v_143;
    else goto v_140;
v_143:
    v_153 = basic_elt(env, 1); // alg
    v_152 = (LispObject)3216+TAG_FIXNUM; // 201
    v_151 = basic_elt(env, 3); // "Zero divisor"
    {   LispObject fn = basic_elt(env, 9); // rerror
    v_151 = (*qfn3(fn))(fn, v_153, v_152, v_151);
    }
    goto v_138;
v_140:
v_138:
    v_151 = stack[-1];
    goto v_13;
    v_151 = nil;
v_13:
    return onevalue(v_151);
}



setup_type const u40_setup[] =
{
    {"redall",                  G0W3,     G1W3,     G2W3,     CC_redall,G4W3},
    {"fd2q",                    G0W1,     CC_fd2q,  G2W1,     G3W1,     G4W1},
    {"oddext",                  G0W1,     CC_oddext,G2W1,     G3W1,     G4W1},
    {"ra_intequiv",             G0W1,     CC_ra_intequiv,G2W1,G3W1,     G4W1},
    {"polynomread",             G0W1,     CC_polynomread,G2W1,G3W1,     G4W1},
    {"mri_2ofsfat",             G0W1,     CC_mri_2ofsfat,G2W1,G3W1,     G4W1},
    {"rl_multsurep",            G0W2,     G1W2,     CC_rl_multsurep,G3W2,G4W2},
    {"make-modular-symmetric",  G0W1,     CC_makeKmodularKsymmetric,G2W1,G3W1,G4W1},
    {"upperlimitrd",            CC_upperlimitrd,G1W0,G2W0,    G3W0,     G4W0},
    {"reduceroots",             G0W2,     G1W2,     CC_reduceroots,G3W2,G4W2},
    {"suspend",                 G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_suspend},
    {"a2bc",                    G0W1,     CC_a2bc,  G2W1,     G3W1,     G4W1},
    {"simpwedge",               G0W1,     CC_simpwedge,G2W1,  G3W1,     G4W1},
    {"rd:difference",           G0W2,     G1W2,     CC_rdTdifference,G3W2,G4W2},
    {"cvitimes2",               G0W2,     G1W2,     CC_cvitimes2,G3W2,  G4W2},
    {"ratnump",                 G0W1,     CC_ratnump,G2W1,    G3W1,     G4W1},
    {"miller-rabin",            G0W2,     G1W2,     CC_millerKrabin,G3W2,G4W2},
    {"pa_list2vect",            G0W2,     G1W2,     CC_pa_list2vect,G3W2,G4W2},
    {"get-current-representation",G0W1,   CC_getKcurrentKrepresentation,G2W1,G3W1,G4W1},
    {"isimp1",                  G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_isimp1},
    {"maxfrom",                 G0W2,     G1W2,     CC_maxfrom,G3W2,    G4W2},
    {"cl_nnf1",                 G0W2,     G1W2,     CC_cl_nnf1,G3W2,    G4W2},
    {"iv_cutcongs2",            G0W2,     G1W2,     CC_iv_cutcongs2,G3W2,G4W2},
    {"intervalrd",              CC_intervalrd,G1W0, G2W0,     G3W0,     G4W0},
    {"compl",                   G0W2,     G1W2,     CC_compl, G3W2,     G4W2},
    {"dipcontevmin",            G0W2,     G1W2,     CC_dipcontevmin,G3W2,G4W2},
    {"mk_binding",              G0W2,     G1W2,     CC_mk_binding,G3W2, G4W2},
    {"equiv-coeffs",            G0W2,     G1W2,     CC_equivKcoeffs,G3W2,G4W2},
    {"lesspcar",                G0W2,     G1W2,     CC_lesspcar,G3W2,   G4W2},
    {"rl_qe",                   G0W2,     G1W2,     CC_rl_qe, G3W2,     G4W2},
    {"mk+mat+plus+mat",         G0W2,     G1W2,     CC_mkLmatLplusLmat,G3W2,G4W2},
    {"repr_ldeg",               G0W1,     CC_repr_ldeg,G2W1,  G3W1,     G4W1},
    {"transposerd",             CC_transposerd,G1W0,G2W0,     G3W0,     G4W0},
    {"prlist",                  G0W1,     CC_prlist,G2W1,     G3W1,     G4W1},
    {"extbrsea",                CC_extbrsea,G1W0,   G2W0,     G3W0,     G4W0},
    {"copy_mat",                G0W1,     CC_copy_mat,G2W1,   G3W1,     G4W1},
    {"exdf0",                   G0W1,     CC_exdf0, G2W1,     G3W1,     G4W1},
    {"gbfdiff",                 G0W2,     G1W2,     CC_gbfdiff,G3W2,    G4W2},
    {"numprintlen",             G0W1,     CC_numprintlen,G2W1,G3W1,     G4W1},
    {"formsetq0",               G0W3,     G1W3,     G2W3,     CC_formsetq0,G4W3},
    {"simp-prop-dist",          G0W1,     CC_simpKpropKdist,G2W1,G3W1,  G4W1},
    {"lambda_iff2c8okfzyq1",    G0W2,     G1W2,     CC_lambda_iff2c8okfzyq1,G3W2,G4W2},
    {"lambda_iff2c8okfzyq1",    G0W2,     G1W2,     CC1_lambda_iff2c8okfzyq1,G3W2,G4W2},
    {"simpquot",                G0W1,     CC_simpquot,G2W1,   G3W1,     G4W1},
    {NULL, (no_args *)"u40", (one_arg *)"102636 124190 1163384",
        NULL, NULL, NULL}
};

// end of generated code
