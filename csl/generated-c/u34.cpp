
// $destdir/u34.c        Machine generated C code

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
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <cmath>
#include <cfloat>
#include <cstdint>
#include <cinttypes>
#include <climits>
#include <cstring>
#include <cctype>
#include <cwctype>
#include <ctime>
#include <cstdarg>
#include <csetjmp>
#include <csignal>
#include <cerrno>
#include <iostream>
#include <exception>
#include <cassert>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
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
inline std::int32_t ASR(std::int32_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int32_t)) n=0;
 return a >> n;
}
inline std::int64_t ASR(std::int64_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int64_t)) n=0;
 return a >> n;
}
#else 
inline std::int32_t ASR(std::int32_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int32_t)) n=0;
 std::uint32_t r = ((std::uint32_t)a) >> n;
 std::uint32_t std::signbit = ((std::uint32_t)a) >> (8*sizeof(std::uint32_t)-1);
 if (n != 0) r |= ((-std::signbit) << (8*sizeof(std::uint32_t) - n));
 return (std::int32_t)r;
}
inline std::int64_t ASR(std::int64_t a, int n)
{ if (n<0 || n>=8*(int)sizeof(std::int64_t)) n=0;
 std::uint64_t r = ((std::uint64_t)a) >> n;
 std::uint64_t std::signbit = ((std::uint64_t)a) >> (8*sizeof(std::uint64_t)-1);
 if (n != 0) r |= ((-std::signbit) << (8*sizeof(std::uint64_t) - n));
 return (std::int64_t)r;
}
#endif 
inline std::int32_t ASL(std::int32_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(std::uint32_t)) n = 0;
 return (std::int32_t)(((std::uint32_t)a) << n);
}
inline std::int64_t ASL(std::int64_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(std::uint64_t)) n = 0;
 return (std::int64_t)(((std::uint64_t)a) << n);
}
inline std::uint64_t ASL(std::uint64_t a, int n)
{ if (n < 0 || n>=8*(int)sizeof(std::uint64_t)) n = 0;
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
inline void *aligned_malloc(std::size_t n)
{ void *p = (void *)std::malloc(n + 32);
 if (p == NULL) return p;
 void *r = (void *)((((std::uintptr_t)p + 15) & -(std::uint64_t)16) + 16);
 (void *)((std::uintptr_t)r - 16) = p;
 return r;
}
inline void aligned_free(void *p)
{ if (p == NULL) return;
 std::free(*(void *)((std::uintptr_t)p - 16));
}
#else 
inline void *aligned_malloc(std::size_t n)
{ return (void *)std::malloc(n);
}
inline void aligned_free(void *p)
{ std::free(p);
}
#endif 
#endif 
#ifndef header_fwin_h
#define header_fwin_h 1
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <csignal>
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
extern void fwin_vfprintf(const char *fmt, std::va_list a);
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
extern bool directoryp(char *f, const char *o, std::size_t n);
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
extern int get_current_directory(char *s, std::size_t n);
extern bool file_readable(char *filename, const char *old, std::size_t n);
extern bool file_writeable(char *filename, const char *old, std::size_t n);
extern bool file_executable(char *filename, const char *old, std::size_t n);
extern int rename_file(char *from_name, const char *from_old, std::size_t from_size,
 char *to_name, const char *to_old, std::size_t to_size);
extern int get_home_directory(char *b, std::size_t len);
extern int get_users_home_directory(char *b, std::size_t len);
extern int my_system(const char *s);
extern int truncate_file(std::FILE *f, long int where);
#endif 
#ifndef header_int128_t_h
#define header_int128_t_h 1
#ifdef HAVE_NATIVE_INT128
inline uint128_t uint128(int128_t v)
{ return (uint128_t)v;
}
inline uint128_t uint128(std::uint64_t v)
{ return (uint128_t)v;
}
inline uint128_t uint128(std::int64_t v)
{ return (uint128_t)v;
}
inline int128_t int128(std::int64_t v)
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
{ if (n<0 || n>=(int)sizeof(uint128_t)) n = 0;
 uint128_t r = ((uint128_t)a) >> n;
 uint128_t std::signbit = ((uint128_t)a) >> (8*sizeof(uint128_t)-1);
 if (n != 0) r |= ((-std::signbit) << (8*sizeof(uint128_t) - n));
 return (int128_t)r;
}
#endif 
inline std::int64_t NARROW128(int128_t a)
{ return (std::int64_t)a;
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
inline uint128_t uint128(std::int64_t v)
{ uint128_t r = (std::uint64_t)v;
 return r;
}
inline uint128_t uint128(std::uint64_t v)
{ uint128_t r = v;
 return r;
}
inline int128_t int128(std::int64_t v)
{ int128_t r = (std::uint64_t)v;
 if (v < 0)
 { int128_t w = -(std::uint64_t)1;
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
 if (n < 64) return int128_t(ASR((std::int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else if (n == 64) return int128_t(-(std::int64_t)(a.upper()<0),
 a.upper());
 else if (n < 64) return int128_t(ASR((std::int64_t)a.upper(), n),
 (a.upper()<<(64-n)) | (a.lower()>>n));
 else return int128_t(-(std::int64_t)(a.upper()<0),
 ASR(((std::int64_t)a.upper()), n-64));
}
inline std::int64_t NARROW128(const int128_t & a)
{ return (std::int64_t)a.lower();
}
inline void divrem128(const int128_t & a, const int128_t & b,
 int128_t & q, int128_t & r)
{ if ((std::int64_t)a.upper() < 0)
 { if ((std::int64_t)b.upper() < 0) q = (-a)/(-b);
 else q = -((-a)/b);
 }
 else
 { if ((std::int64_t)b.upper() < 0) q = -(a/(-b));
 else q = a/b;
 }
 r = a - q*b;
}
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
typedef std::intptr_t LispObject;
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
inline constexpr LispObject fixnum_of_int(std::intptr_t x)
{ return (LispObject)((((std::uintptr_t)x)<<4) + TAG_FIXNUM);
}
#define FIXNUM_OF_INT(n) (16*(n)+TAG_FIXNUM)
inline constexpr std::intptr_t int_of_fixnum(LispObject x)
{ return ((std::intptr_t)x & ~(std::intptr_t)15)/16;
}
inline bool valid_as_fixnum(std::int32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(std::int64_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(int128_t x)
{ return int_of_fixnum(fixnum_of_int(NARROW128(x))) == x;
}
inline bool intptr_valid_as_fixnum(std::intptr_t x)
{ return int_of_fixnum(fixnum_of_int(x)) == x;
}
inline bool valid_as_fixnum(std::uint32_t x)
{ if (SIXTY_FOUR_BIT) return true;
 else return x < (((std::uintptr_t)1) << 28);
}
inline bool valid_as_fixnum(std::uint64_t x)
{ return x < (((std::uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
}
inline bool uint128_valid_as_fixnum(uint128_t x)
{ return x < (((std::uintptr_t)1) << (SIXTY_FOUR_BIT ? 60 : 28));
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
typedef std::uintptr_t Header;
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
inline std::size_t length_of_header(Header h)
{ return (((std::size_t)h) >> (Tw+7)) << 2;
}
inline std::size_t length_of_bitheader(Header h)
{ return (((std::size_t)h) >> (Tw+2)) - 31;
}
inline std::size_t length_of_byteheader(Header h)
{ return (((std::size_t)h) >> (Tw+5)) - 3;
}
inline std::size_t length_of_hwordheader(Header h)
{ return (((std::size_t)h) >> (Tw+6)) - 1;
}
inline Header bitvechdr_(std::size_t n)
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
inline std::atomic<LispObject>& basic_elt(LispObject v, std::size_t n)
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
inline char& basic_celt(LispObject v, std::size_t n)
{ return *((char *)(v) + (CELL-TAG_VECTOR) + n);
}
inline unsigned char& basic_ucelt(LispObject v, std::size_t n)
{ return *((unsigned char *)v + (CELL-TAG_VECTOR) + n);
}
inline signed char& basic_scelt(LispObject v, std::size_t n)
{ return *((signed char *)v + (CELL-TAG_VECTOR) + n);
}
#define BPS_DATA_OFFSET (CELL-TAG_VECTOR)
inline unsigned char* data_of_bps(LispObject v)
{ return (unsigned char *)v + BPS_DATA_OFFSET;
}
inline LispObject& vselt(LispObject v, std::size_t n)
{ return *(LispObject *)(((std::intptr_t)v & ~((std::intptr_t)TAG_BITS)) +
 ((1 + n)*sizeof(LispObject)));
}
inline std::int16_t& basic_helt(LispObject v, std::size_t n)
{ return *(std::int16_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(std::int16_t));
}
inline std::intptr_t& basic_ielt(LispObject v, std::size_t n)
{ return *(std::intptr_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(std::intptr_t));
}
inline std::int32_t& basic_ielt32(LispObject v, std::size_t n)
{ return *(std::int32_t *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(std::int32_t));
}
inline float& basic_felt(LispObject v, std::size_t n)
{ return *(float *)((char *)v +
 (CELL-TAG_VECTOR) +
 n*sizeof(float));
}
inline double& basic_delt(LispObject v, std::size_t n)
{ return *(double *)((char *)v +
 (8-TAG_VECTOR) +
 n*sizeof(double));
}
#define LOG2_VECTOR_CHUNK_BYTES (PAGE_BITS-2)
#define VECTOR_CHUNK_BYTES ((size_t)(((size_t)1)<<LOG2_VECTOR_CHUNK_BYTES))
inline bool is_power_of_two(std::uint64_t n)
{ return (n == (n & (-n)));
}
inline int intlog2(std::uint64_t n)
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
inline std::size_t bytes_in_bytevector(LispObject v)
{ if (is_basic_vector(v)) return length_of_byteheader(vechdr(v)) - CELL;
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_byteheader(vechdr(basic_elt(v, n-1))) - CELL;
}
inline std::size_t hwords_in_hwordvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_hwordheader(vechdr(v)) - (CELL/2);
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (VECTOR_CHUNK_BYTES/2)*(n-1) +
 length_of_hwordheader(vechdr(basic_elt(v, n-1))) - (CELL/2);
}
inline std::size_t bits_in_bitvector(LispObject v)
{ if (is_basic_vector(v)) return length_of_bitheader(vechdr(v)) - 8*CELL;
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return (8*VECTOR_CHUNK_BYTES)*(n-1) +
 length_of_bitheader(vechdr(basic_elt(v, n-1))) - 8*CELL;
}
inline std::size_t bytes_in_vector(LispObject v)
{ if (is_basic_vector(v)) return length_of_header(vechdr(v)) - CELL;
 std::size_t n = (length_of_header(vechdr(v))-CELL)/CELL;
 return VECTOR_CHUNK_BYTES*(n-1) +
 length_of_header(vechdr(basic_elt(v, n-1))) - CELL;
}
inline std::size_t cells_in_vector(LispObject v)
{ return bytes_in_vector(v)/CELL;
}
inline bool vector_holds_binary(LispObject v)
{ if (is_basic_vector(v)) return vector_holds_binary(vechdr(v));
 else return vector_holds_binary(vechdr(basic_elt(v, 0)));
}
extern LispObject free_vectors[LOG2_VECTOR_CHUNK_BYTES+1];
inline void discard_basic_vector(LispObject v)
{ std::size_t size = length_of_header(vechdr(v));
 std::size_t n = size/CELL - 1;
 if (is_power_of_two(n)) 
 { int i = intlog2(n); 
 if (i <= LOG2_VECTOR_CHUNK_BYTES)
 { basic_elt(v, 0) = free_vectors[i];
 setvechdr(v,TYPE_SIMPLE_VEC +
 (size << (Tw+5)) +
 TAG_HDR_IMMED);
 v = (v & ~(std::uintptr_t)TAG_BITS) | TAG_VECTOR;
 free_vectors[i] = v;
 }
 }
}
inline void discard_vector(LispObject v)
{ if (is_basic_vector(v)) discard_basic_vector(v);
 else
 { std::size_t n1 = length_of_header(vechdr(v))/CELL - 1;
 for (std::size_t i=0; i<n1; i++)
 discard_basic_vector(basic_elt(v, i));
 discard_basic_vector(v);
 }
}
inline std::atomic<LispObject>& elt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_elt(v, n);
 return basic_elt(basic_elt(v, n/(VECTOR_CHUNK_BYTES/CELL)),
 n%(VECTOR_CHUNK_BYTES/CELL));
}
inline char& celt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_celt(v, n);
 return basic_celt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline unsigned char& ucelt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_ucelt(v, n);
 return basic_ucelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline signed char& scelt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_scelt(v, n);
 return basic_scelt(basic_elt(v, n/VECTOR_CHUNK_BYTES),
 n%VECTOR_CHUNK_BYTES);
}
inline std::int16_t& helt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_helt(v, n);
 return basic_helt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(std::int16_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(std::int16_t)));
}
inline std::intptr_t& ielt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_ielt(v, n);
 return basic_ielt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(std::intptr_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(std::intptr_t)));
}
inline std::int32_t& ielt32(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_ielt32(v, n);
 return basic_ielt32(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(std::int32_t))),
 n%(VECTOR_CHUNK_BYTES/sizeof(std::int32_t)));
}
inline float& felt(LispObject v, std::size_t n)
{ if (is_basic_vector(v)) return basic_felt(v, n);
 return basic_felt(elt(v, n/(VECTOR_CHUNK_BYTES/sizeof(float))),
 n%(VECTOR_CHUNK_BYTES/sizeof(float)));
}
inline double& delt(LispObject v, std::size_t n)
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
{ return ((std::int32_t)n >> (21+4+Tw)) & 0xf;
}
inline int bits_of_char(LispObject n)
{ return 0;
}
inline unsigned int code_of_char(LispObject n)
{ return ((std::uint32_t)(n) >> (4+Tw)) & 0x001fffff;
}
inline LispObject pack_char(int font, unsigned int code)
{ return (LispObject)((((std::uint32_t)(font)) << (21+4+Tw)) |
 (((std::uint32_t)(code)) << (4+Tw)) | TAG_CHAR);
}
#define CHAR_EOF pack_char(0, 0x0010ffff)
typedef std::int32_t junk; 
typedef std::intptr_t junkxx; 
typedef struct Symbol_Head_
{
 Header header; 
 LispObject value; 
 LispObject env; 
 LispObject plist; 
 LispObject fastgets; 
 LispObject package; 
 LispObject pname; 
 std::intptr_t function0; 
 std::intptr_t function1; 
 std::intptr_t function2; 
 std::intptr_t function3; 
 std::intptr_t function4up;
 std::uint64_t count; 
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
 std::uintptr_t count; 
} Symbol_Head;
typedef struct Function_Object_
{ Header header; 
 LispObject env; 
 std::intptr_t function0; 
 std::intptr_t function1; 
 std::intptr_t function2; 
 std::intptr_t function3; 
 std::intptr_t function4up;
 std::uintptr_t count; 
} Function_Object;
typedef struct Bytecoded_Function_Object_
{ Header header; 
 LispObject env; 
 std::intptr_t function0; 
 std::intptr_t function1; 
 std::intptr_t function2; 
 std::intptr_t function3; 
 std::intptr_t function4up;
 std::uintptr_t count; 
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
inline std::intptr_t& ifn0(LispObject p)
{ return *(std::intptr_t *)((char *)p + (7*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn1(LispObject p)
{ return *(std::intptr_t *)((char *)p + (8*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn2(LispObject p)
{ return *(std::intptr_t *)((char *)p + (9*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn3(LispObject p)
{ return *(std::intptr_t *)((char *)p + (10*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifn4up(LispObject p)
{ return *(std::intptr_t *)((char *)p + (11*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifnunused(LispObject p)
{ return *(std::intptr_t *)((char *)p + (12*CELL-TAG_SYMBOL));
}
inline std::intptr_t& ifnn(LispObject p)
{ return *(std::intptr_t *)((char *)p + (13*CELL-TAG_SYMBOL));
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
inline std::atomic<std::uint64_t>& qcount(LispObject p)
{ return *(std::atomic<std::uint64_t> *)((char *)p + (12*CELL-TAG_SYMBOL));
}
#ifndef HAVE_SOFTFLOAT
typedef struct _float32_t
{ std::uint32_t v;
} float32_t;
typedef struct _float64_t
{ std::uint64_t v;
} float64_t;
#endif
typedef union _Float_union
{ float f;
 std::uint32_t i;
 float32_t f32;
} Float_union;
inline LispObject low32(LispObject a)
{ return (LispObject)(std::uint32_t)a;
}
typedef struct Big_Number_
{
 Header h;
 std::uint32_t d[1]; 
} Big_Number;
inline std::size_t bignum_length(LispObject b)
{ return length_of_header(numhdr(b));
}
inline std::uint32_t* bignum_digits(LispObject b)
{ return (std::uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
inline std::uint32_t* vbignum_digits(LispObject b)
{ return (std::uint32_t *)((char *)b + (CELL-TAG_NUMBERS));
}
inline std::int64_t bignum_digits64(LispObject b, std::size_t n)
{ return (std::int64_t)((std::int32_t *)((char *)b+(CELL-TAG_NUMBERS)))[n];
}
inline Header make_bighdr(std::size_t n)
{ return TAG_HDR_IMMED+TYPE_BIGNUM+(n<<(Tw+7));
}
inline Header make_new_bighdr(std::size_t n)
{ return TAG_HDR_IMMED+TYPE_NEW_BIGNUM+(n<<(Tw+8));
}
inline std::uint64_t* new_bignum_digits(LispObject b)
{ return (std::uint64_t *)((char *)b + (8-TAG_NUMBERS));
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
 std::int32_t i;
 } f;
} Single_Float;
inline float& single_float_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f;
}
inline float32_t& float32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.f32;
}
inline std::int32_t& intfloat32_t_val(LispObject v)
{ return ((Single_Float *)((char *)v-TAG_BOXFLOAT))->f.i;
}
typedef union _Double_union
{ double f;
 std::uint32_t i[2];
 std::uint64_t i64;
 float64_t f64;
} Double_union;
#define SIZEOF_DOUBLE_FLOAT 16
inline double *double_float_addr(LispObject v)
{ return (double *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& double_float_pad(LispObject v)
{ return *(std::int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
inline double& double_float_val(LispObject v)
{ return *(double *)((char *)v + (8-TAG_BOXFLOAT));
}
inline float64_t& float64_t_val(LispObject v)
{ return *(float64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int64_t& intfloat64_t_val(LispObject v)
{ return *(std::int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat64_t_val_hi(LispObject v)
{ return *(std::int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat64_t_val_lo(LispObject v)
{ return *(std::int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
#ifdef HAVE_SOFTFLOAT
#define SIZEOF_LONG_FLOAT 24
inline float128_t *long_float_addr(LispObject v)
{ return (float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& long_float_pad(LispObject v)
{ return *(std::int32_t *)((char *)v + (4-TAG_BOXFLOAT));
}
inline float128_t& long_float_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline float128_t& float128_t_val(LispObject v)
{ return *(float128_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int64_t& intfloat128_t_val0(LispObject v)
{ return *(std::int64_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int64_t& intfloat128_t_val1(LispObject v)
{ return *(std::int64_t *)((char *)v + (16-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_0(LispObject v)
{ return *(std::int32_t *)((char *)v + (8-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_1(LispObject v)
{ return *(std::int32_t *)((char *)v + (12-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_2(LispObject v)
{ return *(std::int32_t *)((char *)v + (16-TAG_BOXFLOAT));
}
inline std::int32_t& intfloat128_t_val32_3(LispObject v)
{ return *(std::int32_t *)((char *)v + (20-TAG_BOXFLOAT));
}
#endif 
inline std::uintptr_t word_align_up(std::uintptr_t n)
{ return (LispObject)((n + 3) & (-(std::uintptr_t)4U));
}
inline std::uintptr_t doubleword_align_up(std::uintptr_t n)
{ return (std::uintptr_t)((n + 7) & (-(std::uintptr_t)8U));
}
inline LispObject doubleword_align_up(LispObject n)
{ return (LispObject)(((std::uintptr_t)n + 7) & (-(std::uintptr_t)8U));
}
inline std::uintptr_t doubleword_align_down(std::uintptr_t n)
{ return (std::uintptr_t)((std::intptr_t)n & (-(std::uintptr_t)8U));
}
inline std::uintptr_t object_align_up(std::uintptr_t n)
{ return (std::uintptr_t)((n + sizeof(LispObject) - 1) &
 (-(std::uintptr_t)sizeof(LispObject)));
}
inline std::uintptr_t object_2_align_up(std::uintptr_t n)
{ return (std::uintptr_t)((n + 2*sizeof(LispObject) - 1) &
 (-(std::uintptr_t)2*sizeof(LispObject)));
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
extern std::int32_t mpi_rank,mpi_size;
#endif
extern void **pages, **heap_pages, **vheap_pages;
extern void **new_heap_pages, **new_vheap_pages;
extern void *allocate_page(const char *why);
extern std::size_t pages_count, heap_pages_count, vheap_pages_count;
extern std::size_t new_heap_pages_count, new_vheap_pages_count;
extern LispObject *list_bases[];
extern LispObject *nilsegment, *stacksegment;
extern LispObject *nilsegmentbase, *stacksegmentbase;
extern LispObject *stackbase;
extern std::int32_t stack_segsize; 
extern double max_store_size;
extern bool restartp;
#define IMAGE_FORMAT_VERSION '5'
#define DIRECTORY_SIZE 8 
typedef struct _directory_header
{ char C, S, L, version; 
 unsigned char dirext, 
 
 
 dirsize, 
 dirused, 
 updated; 
 char eof[4]; 
 
} directory_header;
typedef struct _directory_entry
{ char data[44];
} directory_entry;
#define D_newline data[0]
#define D_name data[1]
#define D_space data[12]
#define D_date data[13]
#define D_position data[37]
#define D_size data[41]
#define name_size 12
#define date_size 24
#define DIRNAME_LENGTH 256
#define NEWLINE_CHAR 0x0a
typedef struct directory
{ directory_header h;
 std::FILE *f;
 const char *full_filename; 
 char filename[DIRNAME_LENGTH];
 directory_entry d[1]; 
} directory;
#ifdef COMMON
# define MIDDLE_INITIAL 'C'
#else
# define MIDDLE_INITIAL 'S'
#endif
inline int get_dirused(directory &d)
{ return d.h.dirused + ((d.h.dirext & 0x0f)<<8);
}
inline int get_dirsize(directory &d)
{ return d.h.dirsize + ((d.h.dirext & 0xf0)<<4);
}
#define D_WRITE_OK 1
#define D_UPDATED 2
#define D_COMPACT 4
#define D_PENDING 8
class stringBool
{
public:
 std::string key;
 bool flag;
 stringBool(std::string k, bool f)
 { key = k;
 flag = f;
 }
};
class stringBoolString
{
public:
 std::string key;
 bool flag;
 std::string data;
 stringBoolString(std::string k, bool f, std::string d)
 { key = k;
 flag = f;
 data = d;
 }
};
class faslFileRecord
{
public:
 bool inUse;
 std::string name;
 directory *dir;
 bool isOutput;
 faslFileRecord(std::string n, bool o)
 { inUse = true;
 name = n;
 dir = NULL;
 isOutput = o;
 }
};
extern std::vector<stringBoolString> symbolsToDefine;
extern std::vector<stringBoolString> stringsToDefine;
extern std::vector<faslFileRecord> fasl_files; 
extern char *big_chunk_start, *big_chunk_end;
extern std::uintptr_t *C_stackbase, C_stacklimit;
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
 if ((std::uintptr_t)_p_ < C_stacklimit) aerror("stack overflow"); \
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
 if (!(x)) { debug_show_trail("Assertion failed"); std::exit(7); }
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
extern std::uintptr_t heapstart;
extern std::uintptr_t len;
extern std::uintptr_t xor_chain;
extern std::uintptr_t vheapstart;
extern std::uintptr_t vlen;
extern std::uintptr_t vxor_chain;
extern LispObject *stacklimit;
#else 
extern LispObject *stacklimit;
#endif 
extern volatile std::atomic<std::uintptr_t> event_flag;
extern std::intptr_t nwork;
extern unsigned int exit_count;
extern std::uint64_t gensym_ser;
extern std::intptr_t print_precision, miscflags;
extern std::intptr_t current_modulus, fastget_size, package_bits;
extern std::intptr_t modulus_is_large;
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
extern std::uint64_t hash_equal(LispObject key);
extern char *exit_charvec;
extern std::intptr_t exit_reason;
extern int procstackp;
extern bool garbage_collection_permitted;
extern int csl_argc;
extern const char **csl_argv;
extern bool fasl_output_file;
extern std::size_t output_directory;
extern LispObject *repeat_heap;
extern std::size_t repeat_count;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern std::FILE *binary_read_file;
#endif
extern std::FILE *binary_write_file;
extern std::size_t boffop;
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
extern int errorset_min, errorset_max;
extern bool force_verbos, force_echo, force_backtrace;
extern bool stop_on_error;
extern std::uint64_t force_cons, force_vec;
extern int init_flags;
extern const char *standard_directory;
extern std::int64_t gc_number;
extern std::int64_t reclaim_trap_count;
extern std::uintptr_t reclaim_stack_limit;
extern std::uint64_t reclaim_trigger_count, reclaim_trigger_target;
#ifdef CONSERVATIVE
extern void reclaim(const char *why);
#else
extern LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, std::size_t size);
#endif
extern void use_gchook(LispObject arg);
extern std::uint64_t force_cons, force_vec;
extern bool next_gc_is_hard;
inline bool cons_forced(std::size_t n)
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
inline bool vec_forced(std::size_t n)
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
extern std::FILE *spool_file;
extern char spool_file_name[128];
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
extern bool open_output(const char *s, std::size_t len);
#define IMAGE_CODE ((size_t)(-1000))
#define HELP_CODE ((size_t)(-1001))
#define BANNER_CODE ((size_t)(-1002))
#define IOPEN_OUT 0
#define IOPEN_IN 1
extern bool Iopen(const char *name, std::size_t len, int dirn, char *expanded_name);
extern bool Iopen_from_stdin(), Iopen_to_stdout();
extern bool IopenRoot(char *expanded_name, std::size_t hard, int sixtyfour);
extern bool Iwriterootp(char *expanded);
extern bool Iopen_banner(int code);
extern bool Imodulep1(int i, const char *name, std::size_t len, char *datestamp,
 std::size_t *size, char *expanded_name);
extern bool Imodulep(const char *name, std::size_t len, char *datestamp,
 std::size_t *size, char *expanded_name);
extern char *trim_module_name(char *name, std::size_t *lenp);
extern bool Icopy(const char *name, std::size_t len);
extern bool Idelete(const char *name, std::size_t len);
extern bool IcloseInput();
extern bool IcloseOutput();
extern bool Ifinished();
extern int Igetc();
extern bool Iread(void *buff, std::size_t size);
extern bool Iputc(int ch);
extern bool Iwrite(const void *buff, std::size_t size);
extern bool def_init();
extern bool inf_init();
extern bool def_finish();
extern bool inf_finish();
extern int Zgetc();
extern bool Zread(void *buff, std::size_t size);
extern bool Zputc(int ch);
extern bool Zwrite(const void *buff, std::size_t size);
extern long int Ioutsize();
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, std::size_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init();
extern void CSL_MD5_Update(const unsigned char *data, std::size_t len);
extern void CSL_MD5_Final(unsigned char *md);
extern bool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
extern void ensure_screen();
extern int window_heading;
[[noreturn]] extern void my_exit(int n);
extern std::uint64_t base_time;
extern std::chrono::high_resolution_clock::time_point base_walltime;
extern std::uint64_t gc_time;
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
extern bool isprime(std::uint64_t);
extern void set_up_functions(int restartp);
extern void get_user_files_checksum(unsigned char *);
extern LispObject acons(LispObject a, LispObject b, LispObject c);
extern LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(std::size_t ppc, LispObject lit,
 LispObject *entry_stack);
extern bool complex_stringp(LispObject a);
extern LispObject copy_string(LispObject a, std::size_t n);
extern void freshline_trace();
extern void freshline_debug();
extern LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject acons_no_gc(LispObject a, LispObject b, LispObject c);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject eval(LispObject u, LispObject env);
extern std::uint32_t Crand();
extern LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(std::uint32_t a);
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
extern LispObject get_basic_vector(int tag, int type, std::size_t length);
extern LispObject get_basic_vector_init(std::size_t n, LispObject v);
extern LispObject reduce_basic_vector_size(LispObject v, std::size_t len);
extern LispObject get_vector(int tag, int type, std::size_t length);
extern LispObject get_vector_init(std::size_t n, LispObject v);
extern LispObject reduce_vector_size(LispObject n, std::size_t length);
extern void prepare_for_borrowing();
inline void zero_out(void *p)
{ char *p1 = (char *)doubleword_align_up((std::uintptr_t)p);
 std::memset(p1, 0, CSL_PAGE_SIZE);
}
extern LispObject borrow_basic_vector(int tag, int type, std::size_t length);
extern LispObject borrow_vector(int tag, int type, std::size_t length);
extern std::uint64_t hash_lisp_string(LispObject s);
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
extern LispObject make_nstring(const char *b, std::size_t n);
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
extern std::FILE *open_file(char *filename, const char *original_name,
 std::size_t n, const char *dirn, std::FILE *old_file);
extern LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, std::size_t len);
extern LispObject prin(LispObject u);
extern void debugprint(LispObject a, int depth=10);
extern void debugprint(const char *s, LispObject a);
extern void debugprint(const char *s);
extern const char *get_string_data(LispObject a, const char *why, std::size_t &len);
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
extern void grab_more_memory(std::size_t npages);
extern bool allocate_more_memory();
extern void setup(int restartp, double storesize);
extern void set_up_variables(int restart_flag);
extern void warm_setup();
extern void write_everything();
extern LispObject simplify_string(LispObject s);
extern bool stringp(LispObject a);
extern LispObject times2(LispObject a, LispObject b);
extern std::int32_t thirty_two_bits(LispObject a);
extern std::uint32_t thirty_two_bits_unsigned(LispObject a);
extern std::int64_t sixty_four_bits(LispObject a);
extern std::uint64_t sixty_four_bits_unsigned(LispObject a);
extern std::uint64_t crc64(std::uint64_t crc, const void *buf, std::size_t size);
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
 std::uint32_t c1;
 std::uint32_t c2;
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
extern std::int64_t time_base, space_base, io_base, errors_base;
extern std::int64_t time_now, space_now, io_now, errors_now;
extern std::int64_t time_limit, space_limit, io_limit, errors_limit;
extern bool symbol_protect_flag, warn_about_protected_symbols;
#ifdef HASH_STATISTICS
extern std::uint64_t Nhget, Nhgetp, Nhput1, Nhputp1, Nhput2, Nhputp2, Nhputtmp;
extern std::uint64_t Noget, Nogetp, Noput, Noputp, Noputtmp;
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
 top_bit_set((std::uint32_t)(n) ^ ((std::uint32_t)(n) << 1))
#define ADD32(a, b) ((uint32_t)(a) + (uint32_t)(b))
#define signed29_in_64(n) \
 (((std::int64_t)(((std::uint64_t)(n) & 0x1fffffffU) << 35) / ((std::int64_t)1 << 35)) == \
 (std::int64_t)(n))
#define signed31_in_64(n) \
 (((std::int64_t)(((std::uint64_t)(n) & 0x7fffffffU) << 33) / ((std::int64_t)1 << 33)) == \
 (std::int64_t)(n))
#define signed31_in_ptr(n) \
 (((std::intptr_t)(((std::uintptr_t)(n)&0x7fffffffU) << (8*sizeof(std::intptr_t) - 31)) / \
 ((std::intptr_t)1 << (8*sizeof(std::intptr_t) - 31))) == (std::intptr_t)(n))
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
 do { std::uint64_t r64 = (std::uint64_t)(a) * (std::uint64_t)(b) + \
 (std::uint32_t)(c); \
 (lo) = 0x7fffffffu & (std::uint32_t)r64; \
 (hi) = (std::uint32_t)(r64 >> 31); } while (0)
#define Ddivide(r, q, a, b, c) \
 do { std::uint64_t r64 = (((std::uint64_t)(a)) << 31) | (std::uint64_t)(b); \
 std::uint64_t c64 = (std::uint64_t)(std::uint32_t)(c); \
 q = (std::uint32_t)(r64 / c64); \
 r = (std::uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { std::uint64_t r64 = (((std::uint64_t)(a)) << 31) | (std::uint64_t)(b); \
 std::uint64_t c64 = (std::uint64_t)(std::uint32_t)(c); \
 q = (std::uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { std::uint64_t r64 = (((std::uint64_t)(a)) << 31) | (std::uint64_t)(b); \
 std::uint64_t c64 = (std::uint64_t)(std::uint32_t)(c); \
 r = (std::uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#define fixnum_minusp(a) ((intptr_t)(a) < 0)
#define bignum_minusp(a) \
 ((std::int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
inline double value_of_immediate_float(LispObject a)
{ Float_union aa;
 if (SIXTY_FOUR_BIT) aa.i = (std::int32_t)((std::uint64_t)a>>32);
 else aa.i = (std::int32_t)(a - XTAG_SFLOAT);
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
 return (LispObject)(((std::uint64_t)aa.i) << 32) + XTAG_SFLOAT;
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
 return (LispObject)((std::uint64_t)aa.i << 32) + XTAG_SFLOAT + XTAG_FLOAT32;
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
 return (LispObject)(((std::uint64_t)aa.i) << 32) + XTAG_SFLOAT +
 ((l1 | l2) & XTAG_FLOAT32);
 }
 aa.i &= ~0xf;
 return aa.i + XTAG_SFLOAT;
}
inline bool eq_i64d(std::int64_t a, double b)
{
 if (b != (double)a) return false;
 if (b == (double)((std::uint64_t)1<<63)) return false;
 return a == (std::int64_t)b;
}
inline bool lessp_i64d(std::int64_t a, double b)
{
 if (a <= ((std::int64_t)1<<53) &&
 a >= -((std::int64_t)1<<53)) return (double)a < b;
 if (!(b >= -(double)((std::uint64_t)1<<63))) return false;
 if (!(b < (double)((std::uint64_t)1<<63))) return true;
 return a < (std::int64_t)b;
}
inline bool lessp_di64(double a, std::int64_t b)
{
 if (b <= ((std::int64_t)1<<53) &&
 b >= -((std::int64_t)1<<53)) return a < (double)b;
 if (!(a < (double)((std::uint64_t)1<<63))) return false;
 if (!(a >= -(double)((std::uint64_t)1<<63))) return true;
 return (std::int64_t)a < b;
}
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, std::int32_t n);
extern LispObject quotbn1(LispObject a, std::int32_t n);
#define QUOTBB_QUOTIENT_NEEDED 1
#define QUOTBB_REMAINDER_NEEDED 2
extern LispObject quotbb(LispObject a, LispObject b, int needs);
extern LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, std::size_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, std::int32_t msd);
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
extern LispObject make_fake_bignum(std::intptr_t n);
extern LispObject make_one_word_bignum(std::int32_t n);
extern LispObject make_two_word_bignum(std::int32_t a, std::uint32_t b);
extern LispObject make_three_word_bignum(std::int32_t a, std::uint32_t b, std::uint32_t c);
extern LispObject make_four_word_bignum(std::int32_t a, std::uint32_t b,
 std::uint32_t c, std::uint32_t d);
extern LispObject make_five_word_bignum(std::int32_t a, std::uint32_t b,
 std::uint32_t c, std::uint32_t d, std::uint32_t e);
extern LispObject make_n_word_bignum(std::int32_t a2, std::uint32_t a1,
 std::uint32_t a0, std::size_t n);
extern LispObject make_n4_word_bignum(std::int32_t a3, std::uint32_t a2,
 std::uint32_t a1, std::uint32_t a0, std::size_t n);
extern LispObject make_n5_word_bignum(std::int32_t a4, std::uint32_t a3,
 std::uint32_t a2, std::uint32_t a1,
 std::uint32_t a0, std::size_t n);
extern LispObject make_power_of_two(std::size_t n);
extern LispObject make_lisp_integer32_fn(std::int32_t n);
inline LispObject make_lisp_integer32(std::int32_t n)
{ if (SIXTY_FOUR_BIT || valid_as_fixnum(n)) return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_integer32_fn(n);
}
extern LispObject make_lisp_integer64_fn(std::int64_t n);
inline LispObject make_lisp_integer64(std::int64_t n)
{ if (valid_as_fixnum(n)) return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_integer64_fn(n);
}
extern LispObject make_lisp_unsigned64_fn(std::uint64_t n);
inline LispObject make_lisp_unsigned64(std::uint64_t n)
{ if (n < ((std::uint64_t)1)<<(8*sizeof(std::intptr_t)-5))
 return fixnum_of_int((std::intptr_t)n);
 else return make_lisp_unsigned64_fn(n);
}
extern LispObject make_lisp_integerptr_fn(std::intptr_t n);
inline LispObject make_lisp_integerptr(std::intptr_t n)
{ if (intptr_valid_as_fixnum(n)) return fixnum_of_int(n);
 else return make_lisp_integerptr_fn(n);
}
extern LispObject make_lisp_unsignedptr_fn(std::uintptr_t n);
inline LispObject make_lisp_unsignedptr(std::uintptr_t n)
{ if (n < ((std::uintptr_t)1)<<(8*sizeof(std::intptr_t)-5))
 return fixnum_of_int((std::intptr_t)n);
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
 return fixnum_of_int((std::uint64_t)NARROW128(n));
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
extern std::size_t kparallel, karatsuba_parallel;
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
 return ((std::int64_t)x->v[HIPART]) < 0;
}
inline int f128M_exponent(const float128_t *p)
{ return ((p->v[HIPART] >> 48) & 0x7fff) - 0x3fff;
}
inline void f128M_set_exponent(float128_t *p, int n)
{ p->v[HIPART] = (p->v[HIPART] & INT64_C(0x8000ffffffffffff)) |
 (((std::uint64_t)n + 0x3fff) << 48);
}
inline void f128M_negate(float128_t *x)
{ x->v[HIPART] ^= UINT64_C(0x8000000000000000);
}
inline bool floating_edge_case128(float128_t *r)
{ return f128M_infinite(r) || f128M_nan(r);
}
#endif 
extern int double_to_binary(double d, std::int64_t &m);
#ifdef HAVE_SOFTFLOAT
extern int float128_to_binary(const float128_t *d,
 std::int64_t &mhi, std::uint64_t &mlo);
#endif 
extern std::intptr_t double_to_3_digits(double d,
 std::int32_t &a2, std::uint32_t &a1, std::uint32_t &a0);
#ifdef HAVE_SOFTFLOAT
extern std::intptr_t float128_to_5_digits(float128_t *d,
 std::int32_t &a4, std::uint32_t &a3, std::uint32_t &a2, std::uint32_t &a1, std::uint32_t &a0);
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
extern std::jmp_buf *global_jb;
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
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit) respond_to_stack_event();
}
inline void stackcheck1(LispObject& a1) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1);
 respond_to_stack_event();
 pop(a1);
 }
}
inline void stackcheck2(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1, a2);
 respond_to_stack_event();
 pop(a2, a1);
 }
}
inline void stackcheck3(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1, a2, a3);
 respond_to_stack_event();
 pop(a3, a2, a1);
 }
}
inline void stackcheck4(LispObject& a1, LispObject& a2, LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1, a2, a3, a4);
 respond_to_stack_event();
 pop(a4, a3, a2, a1);
 }
}
inline void stackcheck()
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit) respond_to_stack_event();
}
inline void stackcheck(LispObject& a1) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1);
 respond_to_stack_event();
 pop(a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1, a2);
 respond_to_stack_event();
 pop(a2, a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2, LispObject& a3) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
 { push(a1, a2, a3);
 respond_to_stack_event();
 pop(a3, a2, a1);
 }
}
inline void stackcheck(LispObject& a1, LispObject& a2,
 LispObject& a3, LispObject& a4) 
{ if_check_stack(); 
 if (((std::uintptr_t)stack | event_flag.load()) >=
 (std::uintptr_t)stacklimit)
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
 std::uintptr_t f = event_flag.load();
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
{ const char *b = std::strrchr(a, '/');
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
 std::jmp_buf *jbsave;
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
 std::jmp_buf jb; \
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



// Code for dipprodin

static LispObject CC_dipprodin(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_51, v_52, v_53;
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
v_9:
    v_51 = stack[-1];
    if (v_51 == nil) goto v_18;
    else goto v_19;
v_18:
    v_51 = lisp_true;
    goto v_17;
v_19:
    v_51 = stack[0];
    v_51 = (v_51 == nil ? lisp_true : nil);
    goto v_17;
    v_51 = nil;
v_17:
    if (v_51 == nil) goto v_15;
    goto v_10;
v_15:
    v_51 = stack[-1];
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    if (!car_legal(v_51)) v_53 = carerror(v_51); else
    v_53 = car(v_51);
    v_51 = stack[-1];
    if (!car_legal(v_51)) v_52 = carerror(v_51); else
    v_52 = car(v_51);
    v_51 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // dipprodin1
    v_52 = (*qfn3(fn))(fn, v_53, v_52, v_51);
    }
    env = stack[-3];
    v_51 = stack[-2];
    v_51 = cons(v_52, v_51);
    env = stack[-3];
    stack[-2] = v_51;
    v_51 = stack[-1];
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    stack[-1] = v_51;
    goto v_9;
v_10:
    v_51 = qvalue(basic_elt(env, 1)); // dipzero
    v_52 = v_51;
v_11:
    v_51 = stack[-2];
    if (v_51 == nil) goto v_41;
    else goto v_42;
v_41:
    v_51 = v_52;
    goto v_8;
v_42:
    v_51 = stack[-2];
    v_51 = car(v_51);
    {   LispObject fn = basic_elt(env, 3); // dipsum
    v_51 = (*qfn2(fn))(fn, v_51, v_52);
    }
    env = stack[-3];
    v_52 = v_51;
    v_51 = stack[-2];
    v_51 = cdr(v_51);
    stack[-2] = v_51;
    goto v_11;
v_8:
    return onevalue(v_51);
}



// Code for po!:statep

static LispObject CC_poTstatep(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42, v_43;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_43 = v_2;
// end of prologue
    v_41 = v_43;
    if (symbolp(v_41)) goto v_10;
    v_41 = nil;
    goto v_8;
v_10:
    v_41 = v_43;
    if (!symbolp(v_41)) v_42 = nil;
    else { v_42 = qfastgets(v_41);
           if (v_42 != nil) { v_42 = elt(v_42, 18); // phystype
#ifdef RECORD_GET
             if (v_42 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_42 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_42 == SPID_NOPROP) v_42 = nil; }}
#endif
    v_41 = basic_elt(env, 1); // state
    v_41 = (v_42 == v_41 ? lisp_true : nil);
    goto v_8;
    v_41 = nil;
v_8:
    if (v_41 == nil) goto v_6;
    else goto v_5;
v_6:
    v_41 = v_43;
    if (!consp(v_41)) goto v_22;
    v_41 = v_43;
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = car(v_41);
    if (symbolp(v_41)) goto v_27;
    v_41 = nil;
    goto v_25;
v_27:
    v_41 = v_43;
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = car(v_41);
    if (!symbolp(v_41)) v_41 = nil;
    else { v_41 = qfastgets(v_41);
           if (v_41 != nil) { v_41 = elt(v_41, 18); // phystype
#ifdef RECORD_GET
             if (v_41 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_41 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_41 == SPID_NOPROP) v_41 = nil; }}
#endif
    v_42 = basic_elt(env, 1); // state
    v_41 = (v_41 == v_42 ? lisp_true : nil);
    goto v_25;
    v_41 = nil;
v_25:
    goto v_20;
v_22:
    v_41 = nil;
    goto v_20;
    v_41 = nil;
v_20:
v_5:
    return onevalue(v_41);
}



// Code for color!-strand

static LispObject CC_colorKstrand(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_30, v_31, v_32;
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
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    stack[-3] = nil;
v_9:
    v_30 = stack[-1];
    if (v_30 == nil) goto v_12;
    else goto v_13;
v_12:
    v_30 = stack[-3];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_30);
    }
v_13:
    v_31 = stack[-2];
    v_30 = stack[-1];
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    {   LispObject fn = basic_elt(env, 2); // color!-roads
    v_32 = (*qfn2(fn))(fn, v_31, v_30);
    }
    env = stack[-4];
    v_31 = stack[0];
    v_30 = stack[-3];
    v_30 = acons(v_32, v_31, v_30);
    env = stack[-4];
    stack[-3] = v_30;
    v_30 = stack[-1];
    if (!car_legal(v_30)) v_30 = cdrerror(v_30); else
    v_30 = cdr(v_30);
    stack[-1] = v_30;
    v_30 = stack[0];
    v_30 = add1(v_30);
    env = stack[-4];
    stack[0] = v_30;
    goto v_9;
    v_30 = nil;
    return onevalue(v_30);
}



// Code for greaterpcdr

static LispObject CC_greaterpcdr(LispObject env,
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
    if (!car_legal(v_11)) v_11 = cdrerror(v_11); else
    v_11 = cdr(v_11);
    if (!car_legal(v_10)) v_10 = cdrerror(v_10); else
    v_10 = cdr(v_10);
        return Lgreaterp_2(nil, v_11, v_10);
}



// Code for fs!:prin

static LispObject CC_fsTprin(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_34, v_35;
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
    v_34 = stack[0];
    if (v_34 == nil) goto v_6;
    else goto v_7;
v_6:
    v_34 = basic_elt(env, 1); // " 0 "
    {
        LispObject fn = basic_elt(env, 3); // prin2!*
        return (*qfn1(fn))(fn, v_34);
    }
v_7:
v_15:
    v_34 = stack[0];
    if (v_34 == nil) goto v_18;
    else goto v_19;
v_18:
    v_34 = nil;
    goto v_14;
v_19:
    v_34 = stack[0];
    {   LispObject fn = basic_elt(env, 4); // fs!:prin1
    v_34 = (*qfn1(fn))(fn, v_34);
    }
    env = stack[-1];
    v_35 = stack[0];
    v_34 = (LispObject)48+TAG_FIXNUM; // 3
    v_34 = Lgetv(nil, v_35, v_34);
    env = stack[-1];
    stack[0] = v_34;
    v_34 = stack[0];
    if (v_34 == nil) goto v_30;
    v_34 = basic_elt(env, 2); // " + "
    {   LispObject fn = basic_elt(env, 3); // prin2!*
    v_34 = (*qfn1(fn))(fn, v_34);
    }
    env = stack[-1];
    goto v_28;
v_30:
v_28:
    goto v_15;
v_14:
    goto v_5;
    v_34 = nil;
v_5:
    return onevalue(v_34);
}



// Code for msolve!-poly1

static LispObject CC_msolveKpoly1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_208, v_209, v_210;
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
    stack[-4] = v_3;
    stack[-5] = v_2;
// end of prologue
    v_208 = stack[-5];
    if (!consp(v_208)) goto v_17;
    else goto v_18;
v_17:
    v_208 = lisp_true;
    goto v_16;
v_18:
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    v_208 = (consp(v_208) ? nil : lisp_true);
    goto v_16;
    v_208 = nil;
v_16:
    if (v_208 == nil) goto v_14;
    goto v_12;
v_14:
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    if (!car_legal(v_208)) v_209 = cdrerror(v_208); else
    v_209 = cdr(v_208);
    v_208 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_209 == v_208) goto v_27;
    else goto v_28;
v_27:
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    if (!car_legal(v_208)) v_208 = cdrerror(v_208); else
    v_208 = cdr(v_208);
    {   LispObject fn = basic_elt(env, 4); // safe!-modrecip
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    stack[0] = v_208;
    v_208 = nil;
    setvalue(basic_elt(env, 1), v_208); // erfg!*
    v_208 = stack[0];
    if (v_208 == nil) goto v_41;
    else goto v_42;
v_41:
    goto v_9;
v_42:
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = cdrerror(v_208); else
    v_208 = cdr(v_208);
    {   LispObject fn = basic_elt(env, 5); // negf
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 6); // multf
    v_208 = (*qfn2(fn))(fn, stack[0], v_208);
    }
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 7); // moduntag
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    stack[0] = v_208;
    v_208 = stack[0];
    if (v_208 == nil) goto v_53;
    v_209 = stack[0];
    v_208 = (LispObject)0+TAG_FIXNUM; // 0
    v_208 = (LispObject)lessp2(v_209, v_208);
    v_208 = v_208 ? lisp_true : nil;
    env = stack[-7];
    if (v_208 == nil) goto v_57;
    else goto v_56;
v_57:
    v_209 = stack[0];
    v_208 = qvalue(basic_elt(env, 2)); // current!-modulus
    v_208 = (LispObject)greaterp2(v_209, v_208);
    v_208 = v_208 ? lisp_true : nil;
    env = stack[-7];
    if (v_208 == nil) goto v_61;
    else goto v_56;
v_61:
    goto v_53;
v_56:
    v_208 = stack[0];
    {   LispObject fn = basic_elt(env, 8); // general!-modular!-number
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    stack[0] = v_208;
    goto v_51;
v_53:
v_51:
    v_208 = stack[0];
    v_208 = ncons(v_208);
    env = stack[-7];
    stack[0] = v_208;
    goto v_10;
v_28:
v_12:
v_9:
    v_210 = stack[-5];
    v_209 = stack[-4];
    v_208 = (LispObject)0+TAG_FIXNUM; // 0
    {   LispObject fn = basic_elt(env, 9); // lowestdeg
    v_208 = (*qfn3(fn))(fn, v_210, v_209, v_208);
    }
    env = stack[-7];
    stack[-6] = v_208;
    v_209 = stack[-6];
    v_208 = (LispObject)0+TAG_FIXNUM; // 0
    v_208 = (LispObject)greaterp2(v_209, v_208);
    v_208 = v_208 ? lisp_true : nil;
    env = stack[-7];
    if (v_208 == nil) goto v_76;
    stack[0] = stack[-5];
    v_210 = basic_elt(env, 3); // expt
    v_209 = stack[-4];
    v_208 = stack[-6];
    v_208 = list3(v_210, v_209, v_208);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 10); // simp
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    {   LispObject fn = basic_elt(env, 11); // quotf
    v_208 = (*qfn2(fn))(fn, stack[0], v_208);
    }
    env = stack[-7];
    stack[-5] = v_208;
    goto v_74;
v_76:
v_74:
    v_208 = stack[-5];
    {   LispObject fn = basic_elt(env, 7); // moduntag
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 12); // general!-reduce!-mod!-p
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    stack[-5] = v_208;
    v_208 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_208;
v_96:
    v_208 = qvalue(basic_elt(env, 2)); // current!-modulus
    v_209 = sub1(v_208);
    env = stack[-7];
    v_208 = stack[-3];
    v_208 = difference2(v_209, v_208);
    env = stack[-7];
    v_208 = Lminusp(nil, v_208);
    env = stack[-7];
    if (v_208 == nil) goto v_102;
    v_208 = nil;
    goto v_95;
v_102:
    v_210 = stack[-5];
    v_209 = stack[-4];
    v_208 = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // general!-evaluate!-mod!-p
    v_208 = (*qfn3(fn))(fn, v_210, v_209, v_208);
    }
    env = stack[-7];
    if (v_208 == nil) goto v_111;
    else goto v_112;
v_111:
    v_208 = stack[-3];
    v_208 = ncons(v_208);
    env = stack[-7];
    goto v_110;
v_112:
    v_208 = nil;
v_110:
    stack[-2] = v_208;
    v_208 = stack[-2];
    {   LispObject fn = basic_elt(env, 14); // lastpair
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    stack[-1] = v_208;
    v_208 = stack[-3];
    v_208 = add1(v_208);
    env = stack[-7];
    stack[-3] = v_208;
    v_208 = stack[-1];
    if (!consp(v_208)) goto v_125;
    else goto v_126;
v_125:
    goto v_96;
v_126:
v_97:
    v_208 = qvalue(basic_elt(env, 2)); // current!-modulus
    v_209 = sub1(v_208);
    env = stack[-7];
    v_208 = stack[-3];
    v_208 = difference2(v_209, v_208);
    env = stack[-7];
    v_208 = Lminusp(nil, v_208);
    env = stack[-7];
    if (v_208 == nil) goto v_131;
    v_208 = stack[-2];
    goto v_95;
v_131:
    stack[0] = stack[-1];
    v_210 = stack[-5];
    v_209 = stack[-4];
    v_208 = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // general!-evaluate!-mod!-p
    v_208 = (*qfn3(fn))(fn, v_210, v_209, v_208);
    }
    env = stack[-7];
    if (v_208 == nil) goto v_141;
    else goto v_142;
v_141:
    v_208 = stack[-3];
    v_208 = ncons(v_208);
    env = stack[-7];
    goto v_140;
v_142:
    v_208 = nil;
v_140:
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_208);
    v_208 = stack[-1];
    {   LispObject fn = basic_elt(env, 14); // lastpair
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    stack[-1] = v_208;
    v_208 = stack[-3];
    v_208 = add1(v_208);
    env = stack[-7];
    stack[-3] = v_208;
    goto v_97;
v_95:
    stack[0] = v_208;
    v_209 = stack[-6];
    v_208 = (LispObject)0+TAG_FIXNUM; // 0
    v_208 = (LispObject)greaterp2(v_209, v_208);
    v_208 = v_208 ? lisp_true : nil;
    env = stack[-7];
    if (v_208 == nil) goto v_157;
    v_208 = nil;
    v_208 = ncons(v_208);
    env = stack[-7];
    v_208 = Lappend_2(nil, stack[0], v_208);
    env = stack[-7];
    stack[0] = v_208;
    goto v_155;
v_157:
v_155:
v_10:
    v_208 = stack[0];
    stack[-5] = v_208;
    v_208 = stack[-5];
    if (v_208 == nil) goto v_174;
    else goto v_175;
v_174:
    v_208 = nil;
    goto v_169;
v_175:
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    stack[0] = stack[-4];
    {   LispObject fn = basic_elt(env, 15); // prepf
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    v_208 = cons(stack[0], v_208);
    env = stack[-7];
    v_208 = ncons(v_208);
    env = stack[-7];
    v_208 = ncons(v_208);
    env = stack[-7];
    stack[-2] = v_208;
    stack[-3] = v_208;
v_170:
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = cdrerror(v_208); else
    v_208 = cdr(v_208);
    stack[-5] = v_208;
    v_208 = stack[-5];
    if (v_208 == nil) goto v_191;
    else goto v_192;
v_191:
    v_208 = stack[-3];
    goto v_169;
v_192:
    stack[-1] = stack[-2];
    v_208 = stack[-5];
    if (!car_legal(v_208)) v_208 = carerror(v_208); else
    v_208 = car(v_208);
    stack[0] = stack[-4];
    {   LispObject fn = basic_elt(env, 15); // prepf
    v_208 = (*qfn1(fn))(fn, v_208);
    }
    env = stack[-7];
    v_208 = cons(stack[0], v_208);
    env = stack[-7];
    v_208 = ncons(v_208);
    env = stack[-7];
    v_208 = ncons(v_208);
    env = stack[-7];
    if (!car_legal(stack[-1])) rplacd_fails(stack[-1]);
    setcdr(stack[-1], v_208);
    v_208 = stack[-2];
    if (!car_legal(v_208)) v_208 = cdrerror(v_208); else
    v_208 = cdr(v_208);
    stack[-2] = v_208;
    goto v_170;
v_169:
    return onevalue(v_208);
}



// Code for cde_replace_nth

static LispObject CC_cde_replace_nth(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42;
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
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    stack[-3] = nil;
v_9:
    v_41 = stack[-2];
    if (v_41 == nil) goto v_13;
    v_42 = stack[-1];
    v_41 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_42 == v_41) goto v_17;
    else goto v_18;
v_17:
    stack[-1] = stack[-3];
    v_42 = stack[0];
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = cdr(v_41);
    v_41 = cons(v_42, v_41);
    env = stack[-4];
    {
        LispObject v_47 = stack[-1];
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_47, v_41);
    }
v_18:
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_42 = carerror(v_41); else
    v_42 = car(v_41);
    v_41 = stack[-3];
    v_41 = cons(v_42, v_41);
    env = stack[-4];
    stack[-3] = v_41;
    v_41 = stack[-2];
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = cdr(v_41);
    stack[-2] = v_41;
    v_41 = stack[-1];
    v_41 = sub1(v_41);
    env = stack[-4];
    stack[-1] = v_41;
    goto v_9;
    goto v_11;
v_13:
    v_41 = stack[-3];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_41);
    }
v_11:
    v_41 = nil;
    return onevalue(v_41);
}



// Code for gcd!-with!-number

static LispObject CC_gcdKwithKnumber(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_70, v_71, v_72;
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
    v_71 = v_2;
// end of prologue
v_7:
    v_72 = v_71;
    v_70 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_72 == v_70) goto v_14;
    else goto v_15;
v_14:
    v_70 = lisp_true;
    goto v_13;
v_15:
    v_70 = v_71;
    if (!consp(v_70)) goto v_24;
    v_70 = lisp_true;
    goto v_22;
v_24:
    v_70 = qvalue(basic_elt(env, 1)); // dmode!*
    if (!symbolp(v_70)) v_70 = nil;
    else { v_70 = qfastgets(v_70);
           if (v_70 != nil) { v_70 = elt(v_70, 3); // field
#ifdef RECORD_GET
             if (v_70 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_70 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_70 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_70 == SPID_NOPROP) v_70 = nil; else v_70 = lisp_true; }}
#endif
    goto v_22;
    v_70 = nil;
v_22:
    goto v_13;
    v_70 = nil;
v_13:
    if (v_70 == nil) goto v_11;
    v_70 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6;
v_11:
    v_70 = stack[0];
    if (!consp(v_70)) goto v_36;
    else goto v_37;
v_36:
    v_70 = lisp_true;
    goto v_35;
v_37:
    v_70 = stack[0];
    if (!car_legal(v_70)) v_70 = carerror(v_70); else
    v_70 = car(v_70);
    v_70 = (consp(v_70) ? nil : lisp_true);
    goto v_35;
    v_70 = nil;
v_35:
    if (v_70 == nil) goto v_33;
    v_70 = stack[0];
    if (v_70 == nil) goto v_47;
    else goto v_48;
v_47:
    v_70 = v_71;
        return Labsval(nil, v_70);
v_48:
    v_70 = stack[0];
    if (!consp(v_70)) goto v_53;
    v_70 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6;
v_53:
    v_70 = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // gcddd
        return (*qfn2(fn))(fn, v_71, v_70);
    }
    goto v_9;
v_33:
    v_70 = stack[0];
    if (!car_legal(v_70)) v_70 = carerror(v_70); else
    v_70 = car(v_70);
    if (!car_legal(v_70)) v_70 = cdrerror(v_70); else
    v_70 = cdr(v_70);
    v_70 = CC_gcdKwithKnumber(basic_elt(env, 0), v_71, v_70);
    env = stack[-1];
    v_71 = v_70;
    v_70 = stack[0];
    if (!car_legal(v_70)) v_70 = cdrerror(v_70); else
    v_70 = cdr(v_70);
    stack[0] = v_70;
    goto v_7;
v_9:
    v_70 = nil;
v_6:
    return onevalue(v_70);
}



// Code for polynomwrite

static LispObject CC_polynomwrite(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_35, v_36;
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
    stack[-1] = nil;
v_7:
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = car(v_35);
    if (v_35 == nil) goto v_10;
    else goto v_11;
v_10:
    v_35 = stack[-1];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_35);
    }
v_11:
    v_35 = stack[0];
    if (!car_legal(v_35)) v_36 = carerror(v_35); else
    v_36 = car(v_35);
    v_35 = (LispObject)0+TAG_FIXNUM; // 0
    v_36 = Lgetv(nil, v_36, v_35);
    env = stack[-2];
    v_35 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_36 == v_35) goto v_16;
    else goto v_17;
v_16:
    v_36 = stack[-1];
    v_35 = (LispObject)16+TAG_FIXNUM; // 1
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_36, v_35);
    }
v_17:
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = car(v_35);
    {   LispObject fn = basic_elt(env, 2); // monomwrite
    v_36 = (*qfn1(fn))(fn, v_35);
    }
    env = stack[-2];
    v_35 = stack[-1];
    v_35 = cons(v_36, v_35);
    env = stack[-2];
    stack[-1] = v_35;
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = cdr(v_35);
    stack[0] = v_35;
    goto v_7;
    v_35 = nil;
    return onevalue(v_35);
}



// Code for gen!+can!+bas

static LispObject CC_genLcanLbas(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_157, v_158;
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-9] = v_2;
// end of prologue
    v_158 = (LispObject)16+TAG_FIXNUM; // 1
    v_157 = (LispObject)16+TAG_FIXNUM; // 1
    v_157 = cons(v_158, v_157);
    env = stack[-11];
    stack[-10] = v_157;
    v_158 = nil;
    v_157 = (LispObject)16+TAG_FIXNUM; // 1
    v_157 = cons(v_158, v_157);
    env = stack[-11];
    stack[-8] = v_157;
    v_157 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-7] = v_157;
    v_158 = stack[-9];
    v_157 = stack[-7];
    v_157 = difference2(v_158, v_157);
    env = stack[-11];
    v_157 = Lminusp(nil, v_157);
    env = stack[-11];
    if (v_157 == nil) goto v_27;
    v_157 = nil;
    goto v_21;
v_27:
    v_157 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_157;
    v_158 = stack[-9];
    v_157 = stack[-3];
    v_157 = difference2(v_158, v_157);
    env = stack[-11];
    v_157 = Lminusp(nil, v_157);
    env = stack[-11];
    if (v_157 == nil) goto v_44;
    v_157 = nil;
    goto v_38;
v_44:
    v_158 = stack[-7];
    v_157 = stack[-3];
    if (equal(v_158, v_157)) goto v_53;
    else goto v_54;
v_53:
    v_157 = stack[-10];
    goto v_52;
v_54:
    v_157 = stack[-8];
    goto v_52;
    v_157 = nil;
v_52:
    v_157 = ncons(v_157);
    env = stack[-11];
    stack[-1] = v_157;
    stack[-2] = v_157;
v_39:
    v_157 = stack[-3];
    v_157 = add1(v_157);
    env = stack[-11];
    stack[-3] = v_157;
    v_158 = stack[-9];
    v_157 = stack[-3];
    v_157 = difference2(v_158, v_157);
    env = stack[-11];
    v_157 = Lminusp(nil, v_157);
    env = stack[-11];
    if (v_157 == nil) goto v_66;
    v_157 = stack[-2];
    goto v_38;
v_66:
    stack[0] = stack[-1];
    v_158 = stack[-7];
    v_157 = stack[-3];
    if (equal(v_158, v_157)) goto v_76;
    else goto v_77;
v_76:
    v_157 = stack[-10];
    goto v_75;
v_77:
    v_157 = stack[-8];
    goto v_75;
    v_157 = nil;
v_75:
    v_157 = ncons(v_157);
    env = stack[-11];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_157);
    v_157 = stack[-1];
    if (!car_legal(v_157)) v_157 = cdrerror(v_157); else
    v_157 = cdr(v_157);
    stack[-1] = v_157;
    goto v_39;
v_38:
    v_157 = ncons(v_157);
    env = stack[-11];
    stack[-5] = v_157;
    stack[-6] = v_157;
v_22:
    v_157 = stack[-7];
    v_157 = add1(v_157);
    env = stack[-11];
    stack[-7] = v_157;
    v_158 = stack[-9];
    v_157 = stack[-7];
    v_157 = difference2(v_158, v_157);
    env = stack[-11];
    v_157 = Lminusp(nil, v_157);
    env = stack[-11];
    if (v_157 == nil) goto v_92;
    v_157 = stack[-6];
    goto v_21;
v_92:
    stack[-4] = stack[-5];
    v_157 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_157;
    v_158 = stack[-9];
    v_157 = stack[-3];
    v_157 = difference2(v_158, v_157);
    env = stack[-11];
    v_157 = Lminusp(nil, v_157);
    env = stack[-11];
    if (v_157 == nil) goto v_110;
    v_157 = nil;
    goto v_104;
v_110:
    v_158 = stack[-7];
    v_157 = stack[-3];
    if (equal(v_158, v_157)) goto v_119;
    else goto v_120;
v_119:
    v_157 = stack[-10];
    goto v_118;
v_120:
    v_157 = stack[-8];
    goto v_118;
    v_157 = nil;
v_118:
    v_157 = ncons(v_157);
    env = stack[-11];
    stack[-1] = v_157;
    stack[-2] = v_157;
v_105:
    v_157 = stack[-3];
    v_157 = add1(v_157);
    env = stack[-11];
    stack[-3] = v_157;
    v_158 = stack[-9];
    v_157 = stack[-3];
    v_157 = difference2(v_158, v_157);
    env = stack[-11];
    v_157 = Lminusp(nil, v_157);
    env = stack[-11];
    if (v_157 == nil) goto v_132;
    v_157 = stack[-2];
    goto v_104;
v_132:
    stack[0] = stack[-1];
    v_158 = stack[-7];
    v_157 = stack[-3];
    if (equal(v_158, v_157)) goto v_142;
    else goto v_143;
v_142:
    v_157 = stack[-10];
    goto v_141;
v_143:
    v_157 = stack[-8];
    goto v_141;
    v_157 = nil;
v_141:
    v_157 = ncons(v_157);
    env = stack[-11];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_157);
    v_157 = stack[-1];
    if (!car_legal(v_157)) v_157 = cdrerror(v_157); else
    v_157 = cdr(v_157);
    stack[-1] = v_157;
    goto v_105;
v_104:
    v_157 = ncons(v_157);
    env = stack[-11];
    if (!car_legal(stack[-4])) rplacd_fails(stack[-4]);
    setcdr(stack[-4], v_157);
    v_157 = stack[-5];
    if (!car_legal(v_157)) v_157 = cdrerror(v_157); else
    v_157 = cdr(v_157);
    stack[-5] = v_157;
    goto v_22;
v_21:
    return onevalue(v_157);
}



// Code for cl_bvarl1

static LispObject CC_cl_bvarl1(LispObject env,
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
    {   LispObject fn = basic_elt(env, 1); // cl_varl1
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    if (!car_legal(v_7)) v_7 = cdrerror(v_7); else
    v_7 = cdr(v_7);
    return onevalue(v_7);
}



// Code for qqe_ofsf_varlat

static LispObject CC_qqe_ofsf_varlat(LispObject env,
                         LispObject v_2)
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
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_16 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // qqe_ofsf_prepat
    v_16 = (*qfn1(fn))(fn, v_16);
    }
    env = stack[-2];
    stack[-1] = v_16;
    v_16 = stack[-1];
    {   LispObject fn = basic_elt(env, 2); // qqe_arg2l
    v_17 = (*qfn1(fn))(fn, v_16);
    }
    env = stack[-2];
    v_16 = nil;
    {   LispObject fn = basic_elt(env, 3); // qqe_ofsf_varlterm
    stack[0] = (*qfn2(fn))(fn, v_17, v_16);
    }
    env = stack[-2];
    v_16 = stack[-1];
    {   LispObject fn = basic_elt(env, 4); // qqe_arg2r
    v_17 = (*qfn1(fn))(fn, v_16);
    }
    env = stack[-2];
    v_16 = nil;
    {   LispObject fn = basic_elt(env, 3); // qqe_ofsf_varlterm
    v_16 = (*qfn2(fn))(fn, v_17, v_16);
    }
    env = stack[-2];
    {
        LispObject v_20 = stack[0];
        LispObject fn = basic_elt(env, 5); // union
        return (*qfn2(fn))(fn, v_20, v_16);
    }
}



// Code for pasf_zcong

static LispObject CC_pasf_zcong(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_166, v_167, v_168;
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
    v_167 = v_2;
// end of prologue
    v_166 = v_167;
    v_166 = Lconsp(nil, v_166);
    env = stack[0];
    if (v_166 == nil) goto v_7;
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_166 = Lconsp(nil, v_166);
    env = stack[0];
    if (v_166 == nil) goto v_7;
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (!car_legal(v_166)) v_168 = carerror(v_166); else
    v_168 = car(v_166);
    v_166 = basic_elt(env, 1); // (cong ncong)
    v_166 = Lmemq(nil, v_168, v_166);
    if (v_166 == nil) goto v_7;
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (!car_legal(v_166)) v_166 = cdrerror(v_166); else
    v_166 = cdr(v_166);
    if (v_166 == nil) goto v_24;
    else goto v_25;
v_24:
    v_168 = v_167;
    v_166 = basic_elt(env, 2); // true
    if (v_168 == v_166) goto v_40;
    else goto v_41;
v_40:
    v_166 = lisp_true;
    goto v_39;
v_41:
    v_168 = v_167;
    v_166 = basic_elt(env, 3); // false
    v_166 = (v_168 == v_166 ? lisp_true : nil);
    goto v_39;
    v_166 = nil;
v_39:
    if (v_166 == nil) goto v_37;
    v_166 = v_167;
    v_168 = v_166;
    goto v_35;
v_37:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_166 = Lconsp(nil, v_166);
    env = stack[0];
    if (v_166 == nil) goto v_52;
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_168 = v_166;
    goto v_35;
v_52:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_168 = v_166;
    goto v_35;
    v_168 = nil;
v_35:
    v_166 = basic_elt(env, 4); // cong
    if (v_168 == v_166) goto v_32;
    else goto v_33;
v_32:
    v_166 = basic_elt(env, 5); // equal
    v_168 = v_166;
    goto v_31;
v_33:
    v_166 = basic_elt(env, 6); // neq
    v_168 = v_166;
    goto v_31;
    v_168 = nil;
v_31:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = cdrerror(v_166); else
    v_166 = cdr(v_166);
    if (!car_legal(v_166)) v_167 = carerror(v_166); else
    v_167 = car(v_166);
    v_166 = nil;
    return list3(v_168, v_167, v_166);
v_25:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = cdrerror(v_166); else
    v_166 = cdr(v_166);
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (v_166 == nil) goto v_76;
    else goto v_77;
v_76:
    v_168 = v_167;
    v_166 = basic_elt(env, 2); // true
    if (v_168 == v_166) goto v_87;
    else goto v_88;
v_87:
    v_166 = lisp_true;
    goto v_86;
v_88:
    v_168 = v_167;
    v_166 = basic_elt(env, 3); // false
    v_166 = (v_168 == v_166 ? lisp_true : nil);
    goto v_86;
    v_166 = nil;
v_86:
    if (v_166 == nil) goto v_84;
    v_166 = v_167;
    v_168 = v_166;
    goto v_82;
v_84:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_166 = Lconsp(nil, v_166);
    env = stack[0];
    if (v_166 == nil) goto v_99;
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_168 = v_166;
    goto v_82;
v_99:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_168 = v_166;
    goto v_82;
    v_168 = nil;
v_82:
    v_166 = basic_elt(env, 4); // cong
    v_166 = (v_168 == v_166 ? lisp_true : nil);
    goto v_75;
v_77:
    v_166 = nil;
    goto v_75;
    v_166 = nil;
v_75:
    if (v_166 == nil) goto v_73;
    v_166 = basic_elt(env, 2); // true
    goto v_23;
v_73:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = cdrerror(v_166); else
    v_166 = cdr(v_166);
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (v_166 == nil) goto v_120;
    else goto v_121;
v_120:
    v_168 = v_167;
    v_166 = basic_elt(env, 2); // true
    if (v_168 == v_166) goto v_131;
    else goto v_132;
v_131:
    v_166 = lisp_true;
    goto v_130;
v_132:
    v_168 = v_167;
    v_166 = basic_elt(env, 3); // false
    v_166 = (v_168 == v_166 ? lisp_true : nil);
    goto v_130;
    v_166 = nil;
v_130:
    if (v_166 == nil) goto v_128;
    v_166 = v_167;
    v_168 = v_166;
    goto v_126;
v_128:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_166 = Lconsp(nil, v_166);
    env = stack[0];
    if (v_166 == nil) goto v_143;
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_168 = v_166;
    goto v_126;
v_143:
    v_166 = v_167;
    if (!car_legal(v_166)) v_166 = carerror(v_166); else
    v_166 = car(v_166);
    v_168 = v_166;
    goto v_126;
    v_168 = nil;
v_126:
    v_166 = basic_elt(env, 7); // ncong
    v_166 = (v_168 == v_166 ? lisp_true : nil);
    goto v_119;
v_121:
    v_166 = nil;
    goto v_119;
    v_166 = nil;
v_119:
    if (v_166 == nil) goto v_117;
    v_166 = basic_elt(env, 3); // false
    goto v_23;
v_117:
    v_166 = v_167;
    goto v_23;
    v_166 = nil;
v_23:
    goto v_5;
v_7:
    v_166 = v_167;
    goto v_5;
    v_166 = nil;
v_5:
    return onevalue(v_166);
}



// Code for ev_dif

static LispObject CC_ev_dif(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_30, v_31, v_32;
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
    v_32 = nil;
v_10:
    v_30 = stack[-1];
    if (v_30 == nil) goto v_13;
    else goto v_14;
v_13:
    goto v_9;
v_14:
    v_30 = stack[-1];
    if (!car_legal(v_30)) v_31 = carerror(v_30); else
    v_31 = car(v_30);
    v_30 = stack[0];
    if (!car_legal(v_30)) v_30 = carerror(v_30); else
    v_30 = car(v_30);
    v_30 = (LispObject)(std::intptr_t)((std::intptr_t)v_31 - (std::intptr_t)v_30 + TAG_FIXNUM);
    v_31 = v_32;
    v_30 = cons(v_30, v_31);
    env = stack[-2];
    v_32 = v_30;
    v_30 = stack[-1];
    if (!car_legal(v_30)) v_30 = cdrerror(v_30); else
    v_30 = cdr(v_30);
    stack[-1] = v_30;
    v_30 = stack[0];
    if (!car_legal(v_30)) v_30 = cdrerror(v_30); else
    v_30 = cdr(v_30);
    stack[0] = v_30;
    goto v_10;
v_9:
    v_30 = v_32;
        return Lnreverse(nil, v_30);
    return onevalue(v_30);
}



// Code for bc_mkat

static LispObject CC_bc_mkat(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11, v_12;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    v_12 = v_11;
    if (!car_legal(v_10)) v_11 = carerror(v_10); else
    v_11 = car(v_10);
    v_10 = nil;
    return list3(v_12, v_11, v_10);
}



// Code for vectorml

static LispObject CC_vectorml(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21, v_22;
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
    v_21 = basic_elt(env, 1); // "<vector"
    {   LispObject fn = basic_elt(env, 4); // printout
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-1];
    v_21 = stack[0];
    if (!car_legal(v_21)) v_22 = carerror(v_21); else
    v_22 = car(v_21);
    v_21 = basic_elt(env, 2); // ""
    {   LispObject fn = basic_elt(env, 5); // attributesml
    v_21 = (*qfn2(fn))(fn, v_22, v_21);
    }
    env = stack[-1];
    v_21 = lisp_true;
    {   LispObject fn = basic_elt(env, 6); // indent!*
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-1];
    v_21 = stack[0];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    {   LispObject fn = basic_elt(env, 7); // multi_elem
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-1];
    v_21 = nil;
    {   LispObject fn = basic_elt(env, 6); // indent!*
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-1];
    v_21 = basic_elt(env, 3); // "</vector>"
    {   LispObject fn = basic_elt(env, 4); // printout
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    v_21 = nil;
    return onevalue(v_21);
}



// Code for delyzz

static LispObject CC_delyzz(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    v_31 = nil;
v_8:
    v_30 = stack[-1];
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    if (equal(v_30, v_29)) goto v_11;
    else goto v_12;
v_11:
    v_30 = v_31;
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = cdr(v_29);
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_30, v_29);
    }
v_12:
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    v_30 = v_31;
    v_29 = cons(v_29, v_30);
    env = stack[-2];
    v_31 = v_29;
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = cdr(v_29);
    stack[0] = v_29;
    goto v_8;
    v_29 = nil;
    return onevalue(v_29);
}



// Code for make!-unique!-freevars

static LispObject CC_makeKuniqueKfreevars(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_82, v_83, v_84;
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
    v_83 = v_2;
// end of prologue
    v_82 = v_83;
    if (!consp(v_82)) goto v_6;
    else goto v_7;
v_6:
    v_84 = v_83;
    v_82 = basic_elt(env, 1); // gen
    v_82 = get(v_84, v_82);
    env = stack[-4];
    if (v_82 == nil) goto v_12;
    v_84 = v_83;
    v_82 = qvalue(basic_elt(env, 2)); // freevarlist!*
    v_82 = Latsoc(nil, v_84, v_82);
    stack[0] = v_82;
    v_82 = stack[0];
    if (v_82 == nil) goto v_24;
    else goto v_25;
v_24:
    stack[0] = v_83;
    {   LispObject fn = basic_elt(env, 3); // pm!:gensym
    v_82 = (*qfn0(fn))(fn);
    }
    env = stack[-4];
    v_82 = cons(stack[0], v_82);
    env = stack[-4];
    stack[0] = v_82;
    v_82 = stack[0];
    if (!car_legal(v_82)) v_84 = cdrerror(v_82); else
    v_84 = cdr(v_82);
    v_83 = basic_elt(env, 1); // gen
    v_82 = lisp_true;
    v_82 = Lputprop(nil, v_84, v_83, v_82);
    env = stack[-4];
    v_83 = stack[0];
    v_82 = qvalue(basic_elt(env, 2)); // freevarlist!*
    v_82 = cons(v_83, v_82);
    env = stack[-4];
    setvalue(basic_elt(env, 2), v_82); // freevarlist!*
    goto v_23;
v_25:
v_23:
    v_82 = stack[0];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = cdr(v_82);
    goto v_10;
v_12:
    v_82 = v_83;
    goto v_10;
    v_82 = nil;
v_10:
    goto v_5;
v_7:
    v_82 = v_83;
    stack[-3] = v_82;
    v_82 = stack[-3];
    if (v_82 == nil) goto v_54;
    else goto v_55;
v_54:
    v_82 = nil;
    goto v_49;
v_55:
    v_82 = stack[-3];
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = car(v_82);
    v_82 = CC_makeKuniqueKfreevars(basic_elt(env, 0), v_82);
    env = stack[-4];
    v_82 = ncons(v_82);
    env = stack[-4];
    stack[-1] = v_82;
    stack[-2] = v_82;
v_50:
    v_82 = stack[-3];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = cdr(v_82);
    stack[-3] = v_82;
    v_82 = stack[-3];
    if (v_82 == nil) goto v_68;
    else goto v_69;
v_68:
    v_82 = stack[-2];
    goto v_49;
v_69:
    stack[0] = stack[-1];
    v_82 = stack[-3];
    if (!car_legal(v_82)) v_82 = carerror(v_82); else
    v_82 = car(v_82);
    v_82 = CC_makeKuniqueKfreevars(basic_elt(env, 0), v_82);
    env = stack[-4];
    v_82 = ncons(v_82);
    env = stack[-4];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_82);
    v_82 = stack[-1];
    if (!car_legal(v_82)) v_82 = cdrerror(v_82); else
    v_82 = cdr(v_82);
    stack[-1] = v_82;
    goto v_50;
v_49:
    goto v_5;
    v_82 = nil;
v_5:
    return onevalue(v_82);
}



// Code for fieldp

static LispObject CC_fieldp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_16 = v_15;
    if (!consp(v_16)) goto v_7;
    if (!car_legal(v_15)) v_15 = carerror(v_15); else
    v_15 = car(v_15);
    if (!symbolp(v_15)) v_15 = nil;
    else { v_15 = qfastgets(v_15);
           if (v_15 != nil) { v_15 = elt(v_15, 3); // field
#ifdef RECORD_GET
             if (v_15 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v_15 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v_15 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v_15 == SPID_NOPROP) v_15 = nil; else v_15 = lisp_true; }}
#endif
    goto v_5;
v_7:
    v_15 = nil;
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for noncomexpf

static LispObject CC_noncomexpf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_40;
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
v_1:
    v_40 = stack[0];
    if (!consp(v_40)) goto v_10;
    else goto v_11;
v_10:
    v_40 = lisp_true;
    goto v_9;
v_11:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    v_40 = (consp(v_40) ? nil : lisp_true);
    goto v_9;
    v_40 = nil;
v_9:
    if (v_40 == nil) goto v_6;
    else goto v_7;
v_6:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    {   LispObject fn = basic_elt(env, 1); // noncomp
    v_40 = (*qfn1(fn))(fn, v_40);
    }
    env = stack[-1];
    if (v_40 == nil) goto v_21;
    else goto v_20;
v_21:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = cdr(v_40);
    v_40 = CC_noncomexpf(basic_elt(env, 0), v_40);
    env = stack[-1];
    if (v_40 == nil) goto v_29;
    else goto v_28;
v_29:
    v_40 = stack[0];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = cdr(v_40);
    stack[0] = v_40;
    goto v_1;
v_28:
v_20:
    goto v_5;
v_7:
    v_40 = nil;
    goto v_5;
    v_40 = nil;
v_5:
    return onevalue(v_40);
}



// Code for dipsimpcont

static LispObject CC_dipsimpcont(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_18, v_19;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19 = v_2;
// end of prologue
    v_18 = qvalue(basic_elt(env, 1)); // !*vdpinteger
    if (v_18 == nil) goto v_8;
    else goto v_6;
v_8:
    v_18 = qvalue(basic_elt(env, 2)); // !*groebdivide
    if (v_18 == nil) goto v_6;
    goto v_7;
v_6:
    v_18 = v_19;
    {
        LispObject fn = basic_elt(env, 3); // dipsimpconti
        return (*qfn1(fn))(fn, v_18);
    }
v_7:
    v_18 = v_19;
    {
        LispObject fn = basic_elt(env, 4); // dipsimpcontr
        return (*qfn1(fn))(fn, v_18);
    }
    v_18 = nil;
    return onevalue(v_18);
}



// Code for calc_coeff

static LispObject CC_calc_coeff(LispObject env,
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
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_35 = stack[-1];
    if (v_35 == nil) goto v_7;
    else goto v_8;
v_7:
    v_35 = (LispObject)16+TAG_FIXNUM; // 1
    return ncons(v_35);
v_8:
    v_35 = stack[-1];
    if (!car_legal(v_35)) v_36 = carerror(v_35); else
    v_36 = car(v_35);
    v_35 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // calc_world
    v_35 = (*qfn2(fn))(fn, v_36, v_35);
    }
    env = stack[-3];
    v_37 = v_35;
    v_36 = v_37;
    v_35 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_36 == v_35) goto v_21;
    else goto v_22;
v_21:
    v_35 = (LispObject)0+TAG_FIXNUM; // 0
    return ncons(v_35);
v_22:
    stack[-2] = v_37;
    v_35 = stack[-1];
    if (!car_legal(v_35)) v_36 = cdrerror(v_35); else
    v_36 = cdr(v_35);
    v_35 = stack[0];
    v_35 = CC_calc_coeff(basic_elt(env, 0), v_36, v_35);
    {
        LispObject v_41 = stack[-2];
        return cons(v_41, v_35);
    }
    v_35 = nil;
    goto v_6;
    v_35 = nil;
v_6:
    return onevalue(v_35);
}



// Code for log_freevars_list

static LispObject CC_log_freevars_list(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
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
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
v_8:
    v_36 = stack[-1];
    if (!consp(v_36)) goto v_11;
    else goto v_12;
v_11:
    v_36 = nil;
    goto v_7;
v_12:
    v_36 = stack[0];
    if (v_36 == nil) goto v_16;
    v_36 = stack[-1];
    if (!car_legal(v_36)) v_36 = carerror(v_36); else
    v_36 = car(v_36);
    if (!consp(v_36)) goto v_19;
    else goto v_16;
v_19:
    v_36 = stack[-1];
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = cdr(v_36);
    stack[-1] = v_36;
    v_36 = lisp_true;
    stack[0] = v_36;
    goto v_8;
v_16:
    v_37 = stack[-2];
    v_36 = stack[-1];
    if (!car_legal(v_36)) v_36 = carerror(v_36); else
    v_36 = car(v_36);
    {   LispObject fn = basic_elt(env, 1); // log_freevars
    v_36 = (*qfn2(fn))(fn, v_37, v_36);
    }
    env = stack[-3];
    if (v_36 == nil) goto v_26;
    v_36 = lisp_true;
    goto v_7;
v_26:
    v_36 = stack[-1];
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = cdr(v_36);
    stack[-1] = v_36;
    goto v_8;
    v_36 = nil;
v_7:
    return onevalue(v_36);
}



// Code for ratfunpri1

static LispObject CC_ratfunpri1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_226, v_227, v_228;
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
    push3(nil, nil, nil);
    stack_popper stack_popper_var(9);
// copy arguments values to proper place
    stack[0] = v_2;
// end of prologue
    v_227 = qvalue(basic_elt(env, 1)); // spare!*
    v_226 = (LispObject)32+TAG_FIXNUM; // 2
    v_226 = plus2(v_227, v_226);
    env = stack[-8];
    setvalue(basic_elt(env, 1), v_226); // spare!*
    v_226 = stack[0];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_228 = carerror(v_226); else
    v_228 = car(v_226);
    v_227 = (LispObject)0+TAG_FIXNUM; // 0
    v_226 = nil;
    {   LispObject fn = basic_elt(env, 13); // layout!-formula
    v_226 = (*qfn3(fn))(fn, v_228, v_227, v_226);
    }
    env = stack[-8];
    stack[-7] = v_226;
    if (v_226 == nil) goto v_29;
    v_226 = stack[0];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_228 = carerror(v_226); else
    v_228 = car(v_226);
    v_227 = (LispObject)0+TAG_FIXNUM; // 0
    v_226 = nil;
    {   LispObject fn = basic_elt(env, 13); // layout!-formula
    v_226 = (*qfn3(fn))(fn, v_228, v_227, v_226);
    }
    env = stack[-8];
    stack[-6] = v_226;
    if (v_226 == nil) goto v_29;
    v_227 = qvalue(basic_elt(env, 1)); // spare!*
    v_226 = (LispObject)32+TAG_FIXNUM; // 2
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    setvalue(basic_elt(env, 1), v_226); // spare!*
    stack[0] = (LispObject)32+TAG_FIXNUM; // 2
    v_226 = stack[-7];
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    if (!car_legal(v_226)) v_227 = cdrerror(v_226); else
    v_227 = cdr(v_226);
    v_226 = stack[-6];
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    {   LispObject fn = basic_elt(env, 14); // max
    v_226 = (*qfn2(fn))(fn, v_227, v_226);
    }
    env = stack[-8];
    v_226 = plus2(stack[0], v_226);
    env = stack[-8];
    stack[-2] = v_226;
    stack[0] = stack[-2];
    v_226 = nil;
    v_227 = Llinelength(nil, v_226);
    env = stack[-8];
    v_226 = qvalue(basic_elt(env, 1)); // spare!*
    v_227 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = qvalue(basic_elt(env, 2)); // posn!*
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = (LispObject)greaterp2(stack[0], v_226);
    v_226 = v_226 ? lisp_true : nil;
    env = stack[-8];
    if (v_226 == nil) goto v_60;
    v_226 = lisp_true;
    {   LispObject fn = basic_elt(env, 15); // terpri!*
    v_226 = (*qfn1(fn))(fn, v_226);
    }
    env = stack[-8];
    goto v_58;
v_60:
v_58:
    v_226 = stack[-7];
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    if (!car_legal(v_226)) v_227 = cdrerror(v_226); else
    v_227 = cdr(v_226);
    v_226 = stack[-6];
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    stack[-1] = v_226;
    v_227 = stack[-1];
    v_226 = (LispObject)0+TAG_FIXNUM; // 0
    v_226 = (LispObject)greaterp2(v_227, v_226);
    v_226 = v_226 ? lisp_true : nil;
    env = stack[-8];
    if (v_226 == nil) goto v_81;
    v_226 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_226;
    v_227 = stack[-1];
    v_226 = (LispObject)32+TAG_FIXNUM; // 2
    v_226 = quot2(v_227, v_226);
    env = stack[-8];
    stack[-3] = v_226;
    goto v_79;
v_81:
    v_226 = stack[-1];
    v_227 = negate(v_226);
    env = stack[-8];
    v_226 = (LispObject)32+TAG_FIXNUM; // 2
    v_226 = quot2(v_227, v_226);
    env = stack[-8];
    stack[0] = v_226;
    v_226 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_226;
    goto v_79;
v_79:
    v_226 = stack[-7];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_227 = cdrerror(v_226); else
    v_227 = cdr(v_226);
    v_226 = stack[-7];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = add1(v_226);
    env = stack[-8];
    stack[-5] = v_226;
    v_226 = stack[-6];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_227 = cdrerror(v_226); else
    v_227 = cdr(v_226);
    v_226 = stack[-6];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = add1(v_226);
    env = stack[-8];
    stack[-4] = v_226;
    stack[-1] = stack[0];
    stack[0] = qvalue(basic_elt(env, 2)); // posn!*
    v_227 = (LispObject)16+TAG_FIXNUM; // 1
    v_226 = qvalue(basic_elt(env, 3)); // orig!*
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = plus2(stack[0], v_226);
    env = stack[-8];
    stack[0] = plus2(stack[-1], v_226);
    env = stack[-8];
    v_227 = (LispObject)16+TAG_FIXNUM; // 1
    v_226 = stack[-7];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    v_227 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = qvalue(basic_elt(env, 4)); // ycoord!*
    v_227 = plus2(v_227, v_226);
    env = stack[-8];
    v_226 = stack[-7];
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    {   LispObject fn = basic_elt(env, 16); // update!-pline
    stack[-1] = (*qfn3(fn))(fn, stack[0], v_227, v_226);
    }
    env = stack[-8];
    stack[0] = qvalue(basic_elt(env, 2)); // posn!*
    v_227 = (LispObject)16+TAG_FIXNUM; // 1
    v_226 = qvalue(basic_elt(env, 3)); // orig!*
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = plus2(stack[0], v_226);
    env = stack[-8];
    stack[0] = plus2(stack[-3], v_226);
    env = stack[-8];
    v_227 = qvalue(basic_elt(env, 4)); // ycoord!*
    v_226 = stack[-6];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_227 = sub1(v_226);
    env = stack[-8];
    v_226 = stack[-6];
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    {   LispObject fn = basic_elt(env, 16); // update!-pline
    v_227 = (*qfn3(fn))(fn, stack[0], v_227, v_226);
    }
    env = stack[-8];
    v_226 = qvalue(basic_elt(env, 5)); // pline!*
    v_226 = Lappend_2(nil, v_227, v_226);
    env = stack[-8];
    v_226 = Lappend_2(nil, stack[-1], v_226);
    env = stack[-8];
    setvalue(basic_elt(env, 5), v_226); // pline!*
    stack[0] = qvalue(basic_elt(env, 6)); // ymin!*
    v_227 = qvalue(basic_elt(env, 4)); // ycoord!*
    v_226 = stack[-4];
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 17); // min
    v_226 = (*qfn2(fn))(fn, stack[0], v_226);
    }
    env = stack[-8];
    setvalue(basic_elt(env, 6), v_226); // ymin!*
    stack[0] = qvalue(basic_elt(env, 7)); // ymax!*
    v_227 = qvalue(basic_elt(env, 4)); // ycoord!*
    v_226 = stack[-5];
    v_226 = plus2(v_227, v_226);
    env = stack[-8];
    {   LispObject fn = basic_elt(env, 14); // max
    v_226 = (*qfn2(fn))(fn, stack[0], v_226);
    }
    env = stack[-8];
    setvalue(basic_elt(env, 7), v_226); // ymax!*
    v_226 = basic_elt(env, 8); // bar
    {   LispObject fn = basic_elt(env, 18); // symbol
    v_226 = (*qfn1(fn))(fn, v_226);
    }
    env = stack[-8];
    stack[-1] = v_226;
    v_226 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_226;
v_165:
    v_227 = stack[-2];
    v_226 = stack[0];
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    v_226 = Lminusp(nil, v_226);
    env = stack[-8];
    if (v_226 == nil) goto v_170;
    goto v_164;
v_170:
    v_226 = stack[-1];
    {   LispObject fn = basic_elt(env, 19); // prin2!*
    v_226 = (*qfn1(fn))(fn, v_226);
    }
    env = stack[-8];
    v_226 = stack[0];
    v_226 = add1(v_226);
    env = stack[-8];
    stack[0] = v_226;
    goto v_165;
v_164:
    goto v_27;
v_29:
    v_227 = qvalue(basic_elt(env, 1)); // spare!*
    v_226 = (LispObject)32+TAG_FIXNUM; // 2
    v_226 = difference2(v_227, v_226);
    env = stack[-8];
    setvalue(basic_elt(env, 1), v_226); // spare!*
    v_226 = stack[0];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    stack[0] = v_226;
    v_226 = basic_elt(env, 9); // quotient
    if (!symbolp(v_226)) v_226 = nil;
    else { v_226 = qfastgets(v_226);
           if (v_226 != nil) { v_226 = elt(v_226, 23); // infix
#ifdef RECORD_GET
             if (v_226 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v_226 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v_226 == SPID_NOPROP) v_226 = nil; }}
#endif
    stack[-2] = v_226;
    v_226 = qvalue(basic_elt(env, 10)); // p!*!*
    if (v_226 == nil) goto v_192;
    v_227 = qvalue(basic_elt(env, 10)); // p!*!*
    v_226 = stack[-2];
    v_226 = (LispObject)greaterp2(v_227, v_226);
    v_226 = v_226 ? lisp_true : nil;
    env = stack[-8];
    stack[-1] = v_226;
    goto v_190;
v_192:
    v_226 = nil;
    stack[-1] = v_226;
    goto v_190;
v_190:
    v_226 = stack[-1];
    if (v_226 == nil) goto v_203;
    v_226 = basic_elt(env, 11); // "("
    {   LispObject fn = basic_elt(env, 19); // prin2!*
    v_226 = (*qfn1(fn))(fn, v_226);
    }
    env = stack[-8];
    goto v_201;
v_203:
v_201:
    v_226 = stack[0];
    if (!car_legal(v_226)) v_227 = carerror(v_226); else
    v_227 = car(v_226);
    v_226 = stack[-2];
    {   LispObject fn = basic_elt(env, 20); // maprint
    v_226 = (*qfn2(fn))(fn, v_227, v_226);
    }
    env = stack[-8];
    v_226 = basic_elt(env, 9); // quotient
    {   LispObject fn = basic_elt(env, 21); // oprin
    v_226 = (*qfn1(fn))(fn, v_226);
    }
    env = stack[-8];
    v_226 = stack[0];
    if (!car_legal(v_226)) v_226 = cdrerror(v_226); else
    v_226 = cdr(v_226);
    if (!car_legal(v_226)) v_226 = carerror(v_226); else
    v_226 = car(v_226);
    {   LispObject fn = basic_elt(env, 22); // negnumberchk
    v_227 = (*qfn1(fn))(fn, v_226);
    }
    env = stack[-8];
    v_226 = stack[-2];
    {   LispObject fn = basic_elt(env, 20); // maprint
    v_226 = (*qfn2(fn))(fn, v_227, v_226);
    }
    env = stack[-8];
    v_226 = stack[-1];
    if (v_226 == nil) goto v_222;
    v_226 = basic_elt(env, 12); // ")"
    {   LispObject fn = basic_elt(env, 19); // prin2!*
    v_226 = (*qfn1(fn))(fn, v_226);
    }
    goto v_220;
v_222:
v_220:
    goto v_27;
v_27:
    v_226 = nil;
    return onevalue(v_226);
}



// Code for dp_neworder

static LispObject CC_dp_neworder(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_51, v_52;
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
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    v_51 = v_2;
// end of prologue
    stack[-4] = v_51;
    v_51 = stack[-4];
    if (v_51 == nil) goto v_14;
    else goto v_15;
v_14:
    v_51 = nil;
    v_52 = v_51;
    goto v_9;
v_15:
    v_51 = stack[-4];
    if (!car_legal(v_51)) v_51 = carerror(v_51); else
    v_51 = car(v_51);
    stack[0] = v_51;
    v_51 = stack[0];
    if (!car_legal(v_51)) v_51 = carerror(v_51); else
    v_51 = car(v_51);
    {   LispObject fn = basic_elt(env, 2); // mo_neworder
    v_52 = (*qfn1(fn))(fn, v_51);
    }
    env = stack[-5];
    v_51 = stack[0];
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    v_51 = cons(v_52, v_51);
    env = stack[-5];
    v_51 = ncons(v_51);
    env = stack[-5];
    stack[-2] = v_51;
    stack[-3] = v_51;
v_10:
    v_51 = stack[-4];
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    stack[-4] = v_51;
    v_51 = stack[-4];
    if (v_51 == nil) goto v_32;
    else goto v_33;
v_32:
    v_51 = stack[-3];
    v_52 = v_51;
    goto v_9;
v_33:
    stack[-1] = stack[-2];
    v_51 = stack[-4];
    if (!car_legal(v_51)) v_51 = carerror(v_51); else
    v_51 = car(v_51);
    stack[0] = v_51;
    v_51 = stack[0];
    if (!car_legal(v_51)) v_51 = carerror(v_51); else
    v_51 = car(v_51);
    {   LispObject fn = basic_elt(env, 2); // mo_neworder
    v_52 = (*qfn1(fn))(fn, v_51);
    }
    env = stack[-5];
    v_51 = stack[0];
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    v_51 = cons(v_52, v_51);
    env = stack[-5];
    v_51 = ncons(v_51);
    env = stack[-5];
    if (!car_legal(stack[-1])) rplacd_fails(stack[-1]);
    setcdr(stack[-1], v_51);
    v_51 = stack[-2];
    if (!car_legal(v_51)) v_51 = cdrerror(v_51); else
    v_51 = cdr(v_51);
    stack[-2] = v_51;
    goto v_10;
v_9:
    v_51 = basic_elt(env, 1); // dp!=mocompare
    {
        LispObject fn = basic_elt(env, 3); // sort
        return (*qfn2(fn))(fn, v_52, v_51);
    }
}



// Code for !*f2di

static LispObject CC_Hf2di(LispObject env,
                         LispObject v_3, LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_173, v_174;
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_173 = v_4;
    stack[-5] = v_3;
// end of prologue
// Binding varlist!*
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=6
{   bind_fluid_stack bind_fluid_var(-7, 1, -6);
    setvalue(basic_elt(env, 1), v_173); // varlist!*
    v_173 = stack[-5];
    if (v_173 == nil) goto v_13;
    else goto v_14;
v_13:
    v_173 = nil;
    goto v_12;
v_14:
    v_173 = stack[-5];
    if (!consp(v_173)) goto v_21;
    else goto v_22;
v_21:
    v_173 = lisp_true;
    goto v_20;
v_22:
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    v_173 = (consp(v_173) ? nil : lisp_true);
    goto v_20;
    v_173 = nil;
v_20:
    if (v_173 == nil) goto v_18;
    v_173 = qvalue(basic_elt(env, 1)); // varlist!*
    stack[-3] = v_173;
    v_173 = stack[-3];
    if (v_173 == nil) goto v_42;
    else goto v_43;
v_42:
    v_173 = nil;
    goto v_37;
v_43:
    v_173 = (LispObject)0+TAG_FIXNUM; // 0
    v_173 = ncons(v_173);
    env = stack[-7];
    stack[-1] = v_173;
    stack[-2] = v_173;
v_38:
    v_173 = stack[-3];
    if (!car_legal(v_173)) v_173 = cdrerror(v_173); else
    v_173 = cdr(v_173);
    stack[-3] = v_173;
    v_173 = stack[-3];
    if (v_173 == nil) goto v_55;
    else goto v_56;
v_55:
    v_173 = stack[-2];
    goto v_37;
v_56:
    stack[0] = stack[-1];
    v_173 = (LispObject)0+TAG_FIXNUM; // 0
    v_173 = ncons(v_173);
    env = stack[-7];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_173);
    v_173 = stack[-1];
    if (!car_legal(v_173)) v_173 = cdrerror(v_173); else
    v_173 = cdr(v_173);
    stack[-1] = v_173;
    goto v_38;
v_37:
    {   LispObject fn = basic_elt(env, 2); // addgt
    v_174 = (*qfn1(fn))(fn, v_173);
    }
    env = stack[-7];
    v_173 = stack[-5];
    v_173 = cons(v_174, v_173);
    env = stack[-7];
    v_173 = ncons(v_173);
    goto v_12;
v_18:
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_174 = carerror(v_173); else
    v_174 = car(v_173);
    v_173 = qvalue(basic_elt(env, 1)); // varlist!*
    v_173 = Lmember(nil, v_174, v_173);
    if (v_173 == nil) goto v_75;
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_174 = cdrerror(v_173); else
    v_174 = cdr(v_173);
    v_173 = qvalue(basic_elt(env, 1)); // varlist!*
    stack[-4] = CC_Hf2di(basic_elt(env, 0), v_174, v_173);
    env = stack[-7];
    v_173 = qvalue(basic_elt(env, 1)); // varlist!*
    stack[-3] = v_173;
    v_173 = stack[-3];
    if (v_173 == nil) goto v_98;
    else goto v_99;
v_98:
    v_173 = nil;
    goto v_93;
v_99:
    v_173 = stack[-3];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    v_174 = v_173;
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (equal(v_174, v_173)) goto v_108;
    else goto v_109;
v_108:
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = cdrerror(v_173); else
    v_173 = cdr(v_173);
    goto v_107;
v_109:
    v_173 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_107;
    v_173 = nil;
v_107:
    v_173 = ncons(v_173);
    env = stack[-7];
    stack[-1] = v_173;
    stack[-2] = v_173;
v_94:
    v_173 = stack[-3];
    if (!car_legal(v_173)) v_173 = cdrerror(v_173); else
    v_173 = cdr(v_173);
    stack[-3] = v_173;
    v_173 = stack[-3];
    if (v_173 == nil) goto v_126;
    else goto v_127;
v_126:
    v_173 = stack[-2];
    goto v_93;
v_127:
    stack[0] = stack[-1];
    v_173 = stack[-3];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    v_174 = v_173;
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (equal(v_174, v_173)) goto v_137;
    else goto v_138;
v_137:
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_173 = cdrerror(v_173); else
    v_173 = cdr(v_173);
    goto v_136;
v_138:
    v_173 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_136;
    v_173 = nil;
v_136:
    v_173 = ncons(v_173);
    env = stack[-7];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_173);
    v_173 = stack[-1];
    if (!car_legal(v_173)) v_173 = cdrerror(v_173); else
    v_173 = cdr(v_173);
    stack[-1] = v_173;
    goto v_94;
v_93:
    {   LispObject fn = basic_elt(env, 2); // addgt
    v_173 = (*qfn1(fn))(fn, v_173);
    }
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 3); // pdmult
    v_173 = (*qfn2(fn))(fn, stack[-4], v_173);
    }
    env = stack[-7];
    stack[0] = v_173;
    goto v_73;
v_75:
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_174 = cdrerror(v_173); else
    v_174 = cdr(v_173);
    v_173 = qvalue(basic_elt(env, 1)); // varlist!*
    stack[0] = CC_Hf2di(basic_elt(env, 0), v_174, v_173);
    env = stack[-7];
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_173 = carerror(v_173); else
    v_173 = car(v_173);
    if (!car_legal(v_173)) v_174 = carerror(v_173); else
    v_174 = car(v_173);
    v_173 = (LispObject)16+TAG_FIXNUM; // 1
    v_173 = cons(v_174, v_173);
    env = stack[-7];
    v_173 = ncons(v_173);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 4); // pcmult
    v_173 = (*qfn2(fn))(fn, stack[0], v_173);
    }
    env = stack[-7];
    stack[0] = v_173;
    goto v_73;
    stack[0] = nil;
v_73:
    v_173 = stack[-5];
    if (!car_legal(v_173)) v_174 = cdrerror(v_173); else
    v_174 = cdr(v_173);
    v_173 = qvalue(basic_elt(env, 1)); // varlist!*
    v_173 = CC_Hf2di(basic_elt(env, 0), v_174, v_173);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 5); // psum
    v_173 = (*qfn2(fn))(fn, stack[0], v_173);
    }
    goto v_12;
    v_173 = nil;
v_12:
    ;}  // end of a binding scope
    return onevalue(v_173);
}



// Code for dfprintfn

static LispObject CC_dfprintfn(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_45, v_46, v_47;
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
    v_45 = v_2;
// end of prologue
    v_46 = qvalue(basic_elt(env, 1)); // !*nat
    if (v_46 == nil) goto v_10;
    else goto v_11;
v_10:
    v_46 = lisp_true;
    goto v_9;
v_11:
    v_46 = qvalue(basic_elt(env, 2)); // !*fort
    if (v_46 == nil) goto v_18;
    else goto v_17;
v_18:
    v_46 = qvalue(basic_elt(env, 3)); // !*dfprint
    v_46 = (v_46 == nil ? lisp_true : nil);
v_17:
    goto v_9;
    v_46 = nil;
v_9:
    if (v_46 == nil) goto v_7;
    v_45 = basic_elt(env, 4); // failed
    goto v_5;
v_7:
    v_46 = basic_elt(env, 5); // !!df!!
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = cdr(v_45);
    v_47 = cons(v_46, v_45);
    env = stack[0];
    v_46 = (LispObject)0+TAG_FIXNUM; // 0
    v_45 = nil;
    {   LispObject fn = basic_elt(env, 6); // layout!-formula
    v_45 = (*qfn3(fn))(fn, v_47, v_46, v_45);
    }
    env = stack[0];
    v_46 = v_45;
    v_45 = v_46;
    if (v_45 == nil) goto v_37;
    else goto v_38;
v_37:
    v_45 = basic_elt(env, 4); // failed
    goto v_27;
v_38:
    v_45 = v_46;
    {   LispObject fn = basic_elt(env, 7); // putpline
    v_45 = (*qfn1(fn))(fn, v_45);
    }
    goto v_36;
v_36:
    v_45 = nil;
v_27:
    goto v_5;
    v_45 = nil;
v_5:
    return onevalue(v_45);
}



// Code for msolve!-polyn

static LispObject CC_msolveKpolyn(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_163, v_164, v_165;
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
    push(nil);
    stack_popper stack_popper_var(12);
// copy arguments values to proper place
    stack[-8] = v_3;
    stack[-9] = v_2;
// end of prologue
    v_163 = stack[-8];
    if (!car_legal(v_163)) v_163 = carerror(v_163); else
    v_163 = car(v_163);
    stack[-10] = v_163;
    v_163 = stack[-8];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    if (v_163 == nil) goto v_10;
    else goto v_11;
v_10:
    v_164 = stack[-9];
    v_163 = stack[-8];
    if (!car_legal(v_163)) v_163 = carerror(v_163); else
    v_163 = car(v_163);
    {
        LispObject fn = basic_elt(env, 2); // msolve!-poly1
        return (*qfn2(fn))(fn, v_164, v_163);
    }
v_11:
    v_163 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-7] = v_163;
v_25:
    v_163 = qvalue(basic_elt(env, 1)); // current!-modulus
    v_164 = sub1(v_163);
    env = stack[-11];
    v_163 = stack[-7];
    v_163 = difference2(v_164, v_163);
    env = stack[-11];
    v_163 = Lminusp(nil, v_163);
    env = stack[-11];
    if (v_163 == nil) goto v_31;
    v_163 = nil;
    goto v_24;
v_31:
    stack[0] = stack[-9];
    v_164 = stack[-10];
    v_163 = stack[-7];
    v_163 = cons(v_164, v_163);
    env = stack[-11];
    v_163 = ncons(v_163);
    env = stack[-11];
    {   LispObject fn = basic_elt(env, 3); // subf
    v_163 = (*qfn2(fn))(fn, stack[0], v_163);
    }
    env = stack[-11];
    if (!car_legal(v_163)) v_164 = carerror(v_163); else
    v_164 = car(v_163);
    v_163 = stack[-8];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    v_163 = CC_msolveKpolyn(basic_elt(env, 0), v_164, v_163);
    env = stack[-11];
    stack[-3] = v_163;
    v_163 = stack[-3];
    if (v_163 == nil) goto v_56;
    else goto v_57;
v_56:
    v_163 = nil;
    goto v_42;
v_57:
    v_163 = stack[-3];
    if (!car_legal(v_163)) v_163 = carerror(v_163); else
    v_163 = car(v_163);
    v_165 = stack[-10];
    v_164 = stack[-7];
    v_163 = acons(v_165, v_164, v_163);
    env = stack[-11];
    v_163 = ncons(v_163);
    env = stack[-11];
    stack[-1] = v_163;
    stack[-2] = v_163;
v_43:
    v_163 = stack[-3];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    stack[-3] = v_163;
    v_163 = stack[-3];
    if (v_163 == nil) goto v_72;
    else goto v_73;
v_72:
    v_163 = stack[-2];
    goto v_42;
v_73:
    stack[0] = stack[-1];
    v_163 = stack[-3];
    if (!car_legal(v_163)) v_163 = carerror(v_163); else
    v_163 = car(v_163);
    v_165 = stack[-10];
    v_164 = stack[-7];
    v_163 = acons(v_165, v_164, v_163);
    env = stack[-11];
    v_163 = ncons(v_163);
    env = stack[-11];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_163);
    v_163 = stack[-1];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    stack[-1] = v_163;
    goto v_43;
v_42:
    stack[-6] = v_163;
    v_163 = stack[-6];
    {   LispObject fn = basic_elt(env, 4); // lastpair
    v_163 = (*qfn1(fn))(fn, v_163);
    }
    env = stack[-11];
    stack[-5] = v_163;
    v_163 = stack[-7];
    v_163 = add1(v_163);
    env = stack[-11];
    stack[-7] = v_163;
    v_163 = stack[-5];
    if (!consp(v_163)) goto v_94;
    else goto v_95;
v_94:
    goto v_25;
v_95:
v_26:
    v_163 = qvalue(basic_elt(env, 1)); // current!-modulus
    v_164 = sub1(v_163);
    env = stack[-11];
    v_163 = stack[-7];
    v_163 = difference2(v_164, v_163);
    env = stack[-11];
    v_163 = Lminusp(nil, v_163);
    env = stack[-11];
    if (v_163 == nil) goto v_100;
    v_163 = stack[-6];
    goto v_24;
v_100:
    stack[-4] = stack[-5];
    stack[0] = stack[-9];
    v_164 = stack[-10];
    v_163 = stack[-7];
    v_163 = cons(v_164, v_163);
    env = stack[-11];
    v_163 = ncons(v_163);
    env = stack[-11];
    {   LispObject fn = basic_elt(env, 3); // subf
    v_163 = (*qfn2(fn))(fn, stack[0], v_163);
    }
    env = stack[-11];
    if (!car_legal(v_163)) v_164 = carerror(v_163); else
    v_164 = car(v_163);
    v_163 = stack[-8];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    v_163 = CC_msolveKpolyn(basic_elt(env, 0), v_164, v_163);
    env = stack[-11];
    stack[-3] = v_163;
    v_163 = stack[-3];
    if (v_163 == nil) goto v_126;
    else goto v_127;
v_126:
    v_163 = nil;
    goto v_112;
v_127:
    v_163 = stack[-3];
    if (!car_legal(v_163)) v_163 = carerror(v_163); else
    v_163 = car(v_163);
    v_165 = stack[-10];
    v_164 = stack[-7];
    v_163 = acons(v_165, v_164, v_163);
    env = stack[-11];
    v_163 = ncons(v_163);
    env = stack[-11];
    stack[-1] = v_163;
    stack[-2] = v_163;
v_113:
    v_163 = stack[-3];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    stack[-3] = v_163;
    v_163 = stack[-3];
    if (v_163 == nil) goto v_142;
    else goto v_143;
v_142:
    v_163 = stack[-2];
    goto v_112;
v_143:
    stack[0] = stack[-1];
    v_163 = stack[-3];
    if (!car_legal(v_163)) v_163 = carerror(v_163); else
    v_163 = car(v_163);
    v_165 = stack[-10];
    v_164 = stack[-7];
    v_163 = acons(v_165, v_164, v_163);
    env = stack[-11];
    v_163 = ncons(v_163);
    env = stack[-11];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_163);
    v_163 = stack[-1];
    if (!car_legal(v_163)) v_163 = cdrerror(v_163); else
    v_163 = cdr(v_163);
    stack[-1] = v_163;
    goto v_113;
v_112:
    if (!car_legal(stack[-4])) rplacd_fails(stack[-4]);
    setcdr(stack[-4], v_163);
    v_163 = stack[-5];
    {   LispObject fn = basic_elt(env, 4); // lastpair
    v_163 = (*qfn1(fn))(fn, v_163);
    }
    env = stack[-11];
    stack[-5] = v_163;
    v_163 = stack[-7];
    v_163 = add1(v_163);
    env = stack[-11];
    stack[-7] = v_163;
    goto v_26;
v_24:
    goto v_9;
    v_163 = nil;
v_9:
    return onevalue(v_163);
}



// Code for reduce!-mod!-eigf

static LispObject CC_reduceKmodKeigf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_24, v_25;
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
    stack[-1] = v_3;
    v_24 = v_2;
// end of prologue
    v_25 = qvalue(basic_elt(env, 1)); // !*sub2
// Binding !*sub2
// FLUIDBIND: reloadenv=3 litvec-offset=1 saveloc=2
{   bind_fluid_stack bind_fluid_var(-3, 1, -2);
    setvalue(basic_elt(env, 1), v_25); // !*sub2
    v_25 = v_24;
    if (!car_legal(v_25)) v_25 = carerror(v_25); else
    v_25 = car(v_25);
    if (!car_legal(v_25)) stack[0] = carerror(v_25); else
    stack[0] = car(v_25);
    v_25 = v_24;
    if (!car_legal(v_25)) v_25 = cdrerror(v_25); else
    v_25 = cdr(v_25);
    if (!car_legal(v_24)) v_24 = carerror(v_24); else
    v_24 = car(v_24);
    if (!car_legal(v_24)) v_24 = cdrerror(v_24); else
    v_24 = cdr(v_24);
    v_24 = cons(v_25, v_24);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 2); // cancel
    v_24 = (*qfn1(fn))(fn, v_24);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 3); // negsq
    v_24 = (*qfn1(fn))(fn, v_24);
    }
    env = stack[-3];
    v_25 = cons(stack[0], v_24);
    env = stack[-3];
    v_24 = stack[-1];
    {   LispObject fn = basic_elt(env, 4); // reduce!-eival!-powers
    v_24 = (*qfn2(fn))(fn, v_25, v_24);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 5); // subs2
    v_24 = (*qfn1(fn))(fn, v_24);
    }
    ;}  // end of a binding scope
    return onevalue(v_24);
}



// Code for cl_apply2ats1

static LispObject CC_cl_apply2ats1(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_203, v_204, v_205;
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
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-4] = v_4;
    stack[-5] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_203 = stack[-1];
    if (!consp(v_203)) goto v_11;
    else goto v_12;
v_11:
    v_203 = stack[-1];
    goto v_10;
v_12:
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = carerror(v_203); else
    v_203 = car(v_203);
    goto v_10;
    v_203 = nil;
v_10:
    v_205 = v_203;
    v_204 = v_205;
    v_203 = basic_elt(env, 1); // true
    if (v_204 == v_203) goto v_25;
    else goto v_26;
v_25:
    v_203 = lisp_true;
    goto v_24;
v_26:
    v_204 = v_205;
    v_203 = basic_elt(env, 2); // false
    v_203 = (v_204 == v_203 ? lisp_true : nil);
    goto v_24;
    v_203 = nil;
v_24:
    if (v_203 == nil) goto v_22;
    v_203 = stack[-1];
    goto v_8;
v_22:
    v_204 = v_205;
    v_203 = basic_elt(env, 3); // ex
    if (v_204 == v_203) goto v_42;
    else goto v_43;
v_42:
    v_203 = lisp_true;
    goto v_41;
v_43:
    v_204 = v_205;
    v_203 = basic_elt(env, 4); // all
    v_203 = (v_204 == v_203 ? lisp_true : nil);
    goto v_41;
    v_203 = nil;
v_41:
    if (v_203 == nil) goto v_39;
    stack[-2] = v_205;
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) stack[0] = carerror(v_203); else
    stack[0] = car(v_203);
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_205 = carerror(v_203); else
    v_205 = car(v_203);
    v_204 = stack[-5];
    v_203 = stack[-4];
    v_203 = CC_cl_apply2ats1(basic_elt(env, 0), v_205, v_204, v_203);
    {
        LispObject v_213 = stack[-2];
        LispObject v_214 = stack[0];
        return list3(v_213, v_214, v_203);
    }
v_39:
    v_204 = v_205;
    v_203 = basic_elt(env, 5); // bex
    if (v_204 == v_203) goto v_70;
    else goto v_71;
v_70:
    v_203 = lisp_true;
    goto v_69;
v_71:
    v_204 = v_205;
    v_203 = basic_elt(env, 6); // ball
    v_203 = (v_204 == v_203 ? lisp_true : nil);
    goto v_69;
    v_203 = nil;
v_69:
    if (v_203 == nil) goto v_67;
    stack[-3] = v_205;
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) stack[-2] = carerror(v_203); else
    stack[-2] = car(v_203);
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_205 = carerror(v_203); else
    v_205 = car(v_203);
    v_204 = stack[-5];
    v_203 = stack[-4];
    stack[0] = CC_cl_apply2ats1(basic_elt(env, 0), v_205, v_204, v_203);
    env = stack[-7];
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    if (!car_legal(v_203)) v_205 = carerror(v_203); else
    v_205 = car(v_203);
    v_204 = stack[-5];
    v_203 = stack[-4];
    v_203 = CC_cl_apply2ats1(basic_elt(env, 0), v_205, v_204, v_203);
    {
        LispObject v_215 = stack[-3];
        LispObject v_216 = stack[-2];
        LispObject v_217 = stack[0];
        return list4(v_215, v_216, v_217, v_203);
    }
v_67:
    v_204 = v_205;
    v_203 = basic_elt(env, 7); // or
    if (v_204 == v_203) goto v_114;
    else goto v_115;
v_114:
    v_203 = lisp_true;
    goto v_113;
v_115:
    v_204 = v_205;
    v_203 = basic_elt(env, 8); // and
    v_203 = (v_204 == v_203 ? lisp_true : nil);
    goto v_113;
    v_203 = nil;
v_113:
    if (v_203 == nil) goto v_111;
    v_203 = lisp_true;
    goto v_109;
v_111:
    v_204 = v_205;
    v_203 = basic_elt(env, 9); // not
    v_203 = (v_204 == v_203 ? lisp_true : nil);
    goto v_109;
    v_203 = nil;
v_109:
    if (v_203 == nil) goto v_107;
    v_203 = lisp_true;
    goto v_105;
v_107:
    v_204 = v_205;
    v_203 = basic_elt(env, 10); // impl
    if (v_204 == v_203) goto v_135;
    else goto v_136;
v_135:
    v_203 = lisp_true;
    goto v_134;
v_136:
    v_204 = v_205;
    v_203 = basic_elt(env, 11); // repl
    if (v_204 == v_203) goto v_144;
    else goto v_145;
v_144:
    v_203 = lisp_true;
    goto v_143;
v_145:
    v_204 = v_205;
    v_203 = basic_elt(env, 12); // equiv
    v_203 = (v_204 == v_203 ? lisp_true : nil);
    goto v_143;
    v_203 = nil;
v_143:
    goto v_134;
    v_203 = nil;
v_134:
    goto v_105;
    v_203 = nil;
v_105:
    if (v_203 == nil) goto v_103;
    stack[-6] = v_205;
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    stack[-3] = v_203;
    v_203 = stack[-3];
    if (v_203 == nil) goto v_166;
    else goto v_167;
v_166:
    v_203 = nil;
    goto v_160;
v_167:
    v_203 = stack[-3];
    if (!car_legal(v_203)) v_203 = carerror(v_203); else
    v_203 = car(v_203);
    v_205 = v_203;
    v_204 = stack[-5];
    v_203 = stack[-4];
    v_203 = CC_cl_apply2ats1(basic_elt(env, 0), v_205, v_204, v_203);
    env = stack[-7];
    v_203 = ncons(v_203);
    env = stack[-7];
    stack[-1] = v_203;
    stack[-2] = v_203;
v_161:
    v_203 = stack[-3];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    stack[-3] = v_203;
    v_203 = stack[-3];
    if (v_203 == nil) goto v_182;
    else goto v_183;
v_182:
    v_203 = stack[-2];
    goto v_160;
v_183:
    stack[0] = stack[-1];
    v_203 = stack[-3];
    if (!car_legal(v_203)) v_203 = carerror(v_203); else
    v_203 = car(v_203);
    v_205 = v_203;
    v_204 = stack[-5];
    v_203 = stack[-4];
    v_203 = CC_cl_apply2ats1(basic_elt(env, 0), v_205, v_204, v_203);
    env = stack[-7];
    v_203 = ncons(v_203);
    env = stack[-7];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_203);
    v_203 = stack[-1];
    if (!car_legal(v_203)) v_203 = cdrerror(v_203); else
    v_203 = cdr(v_203);
    stack[-1] = v_203;
    goto v_161;
v_160:
    {
        LispObject v_218 = stack[-6];
        return cons(v_218, v_203);
    }
v_103:
    stack[0] = stack[-5];
    v_204 = stack[-1];
    v_203 = stack[-4];
    v_203 = cons(v_204, v_203);
    env = stack[-7];
    {
        LispObject v_219 = stack[0];
        LispObject fn = basic_elt(env, 13); // apply
        return (*qfn2(fn))(fn, v_219, v_203);
    }
v_8:
    return onevalue(v_203);
}



// Code for cl_susicpknowl

static LispObject CC_cl_susicpknowl(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_47, v_48;
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
    v_47 = v_2;
// end of prologue
    stack[-3] = v_47;
    v_47 = stack[-3];
    if (v_47 == nil) goto v_13;
    else goto v_14;
v_13:
    v_47 = nil;
    goto v_8;
v_14:
    v_47 = stack[-3];
    if (!car_legal(v_47)) v_47 = carerror(v_47); else
    v_47 = car(v_47);
    v_48 = v_47;
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_47)) v_47 = cdrerror(v_47); else
    v_47 = cdr(v_47);
    v_47 = cons(v_48, v_47);
    env = stack[-4];
    v_47 = ncons(v_47);
    env = stack[-4];
    stack[-1] = v_47;
    stack[-2] = v_47;
v_9:
    v_47 = stack[-3];
    if (!car_legal(v_47)) v_47 = cdrerror(v_47); else
    v_47 = cdr(v_47);
    stack[-3] = v_47;
    v_47 = stack[-3];
    if (v_47 == nil) goto v_30;
    else goto v_31;
v_30:
    v_47 = stack[-2];
    goto v_8;
v_31:
    stack[0] = stack[-1];
    v_47 = stack[-3];
    if (!car_legal(v_47)) v_47 = carerror(v_47); else
    v_47 = car(v_47);
    v_48 = v_47;
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_47)) v_47 = cdrerror(v_47); else
    v_47 = cdr(v_47);
    v_47 = cons(v_48, v_47);
    env = stack[-4];
    v_47 = ncons(v_47);
    env = stack[-4];
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_47);
    v_47 = stack[-1];
    if (!car_legal(v_47)) v_47 = cdrerror(v_47); else
    v_47 = cdr(v_47);
    stack[-1] = v_47;
    goto v_9;
v_8:
    return onevalue(v_47);
}



// Code for vdp_putprop

static LispObject CC_vdp_putprop(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_37, v_38, v_39, v_40, v_41;
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
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    v_39 = v_4;
    v_40 = v_3;
    stack[0] = v_2;
// end of prologue
    v_37 = stack[0];
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = cdr(v_37);
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = cdr(v_37);
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = cdr(v_37);
    if (!car_legal(v_37)) v_37 = cdrerror(v_37); else
    v_37 = cdr(v_37);
    v_38 = v_37;
    v_41 = v_40;
    v_37 = v_38;
    if (!car_legal(v_37)) v_37 = carerror(v_37); else
    v_37 = car(v_37);
    v_37 = Latsoc(nil, v_41, v_37);
    v_41 = v_37;
    v_37 = v_41;
    if (v_37 == nil) goto v_22;
    v_37 = v_41;
    v_38 = v_39;
    if (!car_legal(v_37)) rplacd_fails(v_37);
    setcdr(v_37, v_38);
    goto v_20;
v_22:
    stack[-1] = v_38;
    v_37 = v_40;
    if (!car_legal(v_38)) v_38 = carerror(v_38); else
    v_38 = car(v_38);
    v_37 = acons(v_37, v_39, v_38);
    if (!car_legal(stack[-1])) rplaca_fails(stack[-1]);
    setcar(stack[-1], v_37);
    goto v_20;
v_20:
    v_37 = stack[0];
    return onevalue(v_37);
}



// Code for listrd

static LispObject CC_listrd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_13, v_14;
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
    v_14 = qvalue(basic_elt(env, 1)); // atts
    v_13 = basic_elt(env, 2); // (order)
    {   LispObject fn = basic_elt(env, 4); // retattributes
    v_13 = (*qfn2(fn))(fn, v_14, v_13);
    }
    env = stack[-2];
    stack[-1] = basic_elt(env, 3); // list
    stack[0] = v_13;
    {   LispObject fn = basic_elt(env, 5); // stats_getargs
    v_13 = (*qfn0(fn))(fn);
    }
    {
        LispObject v_17 = stack[-1];
        LispObject v_18 = stack[0];
        return list2star(v_17, v_18, v_13);
    }
    return onevalue(v_13);
}



// Code for resume

static LispObject CC_resume(LispObject env,
                         LispObject v_2, LispObject v_3)
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
        push(v_2,v_3);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_30 = v_3;
    v_31 = v_2;
// end of prologue
    v_29 = v_30;
    if (v_29 == nil) goto v_8;
    v_29 = v_30;
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    if (!car_legal(v_29)) stack[-2] = carerror(v_29); else
    stack[-2] = car(v_29);
    v_29 = v_30;
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = cdr(v_29);
    if (!car_legal(v_29)) stack[-1] = carerror(v_29); else
    stack[-1] = car(v_29);
    stack[0] = v_31;
    v_29 = v_30;
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = cdr(v_29);
    v_29 = ncons(v_29);
    env = stack[-3];
    {
        LispObject v_35 = stack[-2];
        LispObject v_36 = stack[-1];
        LispObject v_37 = stack[0];
        LispObject fn = basic_elt(env, 2); // amatch
        return (*qfn4up(fn))(fn, v_35, v_36, v_37, v_29);
    }
v_8:
    v_29 = v_31;
    {   LispObject fn = basic_elt(env, 3); // chk
    v_30 = (*qfn1(fn))(fn, v_29);
    }
    env = stack[-3];
    v_29 = lisp_true;
    if (v_30 == v_29) goto v_22;
    else goto v_23;
v_22:
    v_29 = qvalue(basic_elt(env, 1)); // substitution
    {
        LispObject fn = basic_elt(env, 4); // bsubs
        return (*qfn1(fn))(fn, v_29);
    }
v_23:
    v_29 = nil;
    return onevalue(v_29);
}



// Code for evinvlexcomp

static LispObject CC_evinvlexcomp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_65, v_66;
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
v_7:
    v_65 = stack[-1];
    if (v_65 == nil) goto v_10;
    else goto v_11;
v_10:
    v_65 = stack[0];
    if (v_65 == nil) goto v_15;
    else goto v_16;
v_15:
    v_65 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6;
v_16:
    v_65 = basic_elt(env, 1); // (0)
    stack[-1] = v_65;
    goto v_7;
    goto v_9;
v_11:
    v_65 = stack[0];
    if (v_65 == nil) goto v_22;
    else goto v_23;
v_22:
    v_66 = stack[-1];
    v_65 = basic_elt(env, 1); // (0)
    {
        LispObject fn = basic_elt(env, 2); // evlexcomp
        return (*qfn2(fn))(fn, v_66, v_65);
    }
v_23:
    v_65 = stack[-1];
    if (!car_legal(v_65)) v_66 = carerror(v_65); else
    v_66 = car(v_65);
    v_65 = stack[0];
    if (!car_legal(v_65)) v_65 = carerror(v_65); else
    v_65 = car(v_65);
    {   LispObject fn = basic_elt(env, 3); // iequal
    v_65 = (*qfn2(fn))(fn, v_66, v_65);
    }
    env = stack[-3];
    if (v_65 == nil) goto v_29;
    v_65 = stack[-1];
    if (!car_legal(v_65)) v_65 = cdrerror(v_65); else
    v_65 = cdr(v_65);
    stack[-1] = v_65;
    v_65 = stack[0];
    if (!car_legal(v_65)) v_65 = cdrerror(v_65); else
    v_65 = cdr(v_65);
    stack[0] = v_65;
    goto v_7;
v_29:
    v_65 = stack[-1];
    if (!car_legal(v_65)) v_66 = cdrerror(v_65); else
    v_66 = cdr(v_65);
    v_65 = stack[0];
    if (!car_legal(v_65)) v_65 = cdrerror(v_65); else
    v_65 = cdr(v_65);
    v_65 = CC_evinvlexcomp(basic_elt(env, 0), v_66, v_65);
    env = stack[-3];
    stack[-2] = v_65;
    v_66 = stack[-2];
    v_65 = (LispObject)0+TAG_FIXNUM; // 0
    {   LispObject fn = basic_elt(env, 3); // iequal
    v_65 = (*qfn2(fn))(fn, v_66, v_65);
    }
    if (v_65 == nil) goto v_49;
    else goto v_50;
v_49:
    v_65 = stack[-2];
    goto v_48;
v_50:
    v_65 = stack[0];
    if (!car_legal(v_65)) v_66 = carerror(v_65); else
    v_66 = car(v_65);
    v_65 = stack[-1];
    if (!car_legal(v_65)) v_65 = carerror(v_65); else
    v_65 = car(v_65);
    if (((std::intptr_t)(v_66)) > ((std::intptr_t)(v_65))) goto v_55;
    else goto v_56;
v_55:
    v_65 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_48;
v_56:
    v_65 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_48;
    v_65 = nil;
v_48:
    goto v_6;
v_9:
    v_65 = nil;
v_6:
    return onevalue(v_65);
}



// Code for vdpilcomb1

static LispObject CC_vdpilcomb1(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48, v_49, v_50;
    LispObject v_5, v_6, v_7;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_6 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_7 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3,v_4,v_5,v_6,v_7);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_7,v_6,v_5,v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    stack[-2] = v_7;
    v_49 = v_6;
    stack[-3] = v_5;
    stack[-4] = v_4;
    v_50 = v_3;
    stack[-5] = v_2;
// end of prologue
    v_48 = stack[-5];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    if (!car_legal(v_48)) stack[-6] = carerror(v_48); else
    stack[-6] = car(v_48);
    stack[-1] = v_50;
    stack[0] = stack[-4];
    v_48 = stack[-3];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    if (!car_legal(v_48)) v_50 = carerror(v_48); else
    v_50 = car(v_48);
    v_48 = stack[-2];
    v_48 = list3(v_50, v_49, v_48);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 2); // dipilcomb1
    v_48 = (*qfn4up(fn))(fn, stack[-6], stack[-1], stack[0], v_48);
    }
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 3); // dip2vdp
    v_48 = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-7];
    stack[-1] = v_48;
    v_48 = qvalue(basic_elt(env, 1)); // !*gsugar
    if (v_48 == nil) goto v_32;
    stack[0] = stack[-1];
    v_48 = stack[-5];
    {   LispObject fn = basic_elt(env, 4); // gsugar
    stack[-5] = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-7];
    v_48 = stack[-4];
    {   LispObject fn = basic_elt(env, 5); // vevtdeg
    v_48 = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-7];
    stack[-4] = plus2(stack[-5], v_48);
    env = stack[-7];
    v_48 = stack[-3];
    {   LispObject fn = basic_elt(env, 4); // gsugar
    stack[-3] = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-7];
    v_48 = stack[-2];
    {   LispObject fn = basic_elt(env, 5); // vevtdeg
    v_48 = (*qfn1(fn))(fn, v_48);
    }
    env = stack[-7];
    v_48 = plus2(stack[-3], v_48);
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 6); // max
    v_48 = (*qfn2(fn))(fn, stack[-4], v_48);
    }
    env = stack[-7];
    {   LispObject fn = basic_elt(env, 7); // gsetsugar
    v_48 = (*qfn2(fn))(fn, stack[0], v_48);
    }
    goto v_30;
v_32:
v_30:
    v_48 = stack[-1];
    return onevalue(v_48);
}



// Code for unplus

static LispObject CC_unplus(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_56, v_57, v_58;
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
    v_58 = nil;
v_7:
    v_56 = stack[-1];
    if (!consp(v_56)) goto v_10;
    else goto v_11;
v_10:
    v_57 = v_58;
    v_56 = stack[-1];
    {
        LispObject fn = basic_elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_57, v_56);
    }
v_11:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_57 = carerror(v_56); else
    v_57 = car(v_56);
    v_56 = basic_elt(env, 1); // plus
    if (v_57 == v_56) goto v_16;
    else goto v_17;
v_16:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = cdr(v_56);
    stack[-1] = v_56;
    goto v_7;
v_17:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = car(v_56);
    if (!consp(v_56)) goto v_27;
    else goto v_28;
v_27:
    v_56 = lisp_true;
    goto v_26;
v_28:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_57 = carerror(v_56); else
    v_57 = car(v_56);
    v_56 = basic_elt(env, 1); // plus
    v_56 = Leqcar(nil, v_57, v_56);
    env = stack[-3];
    v_56 = (v_56 == nil ? lisp_true : nil);
    goto v_26;
    v_56 = nil;
v_26:
    if (v_56 == nil) goto v_24;
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = car(v_56);
    v_57 = v_58;
    v_56 = cons(v_56, v_57);
    env = stack[-3];
    v_58 = v_56;
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = cdr(v_56);
    stack[-1] = v_56;
    goto v_7;
v_24:
    stack[-2] = v_58;
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = car(v_56);
    if (!car_legal(v_56)) stack[0] = cdrerror(v_56); else
    stack[0] = cdr(v_56);
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = cdr(v_56);
    v_56 = CC_unplus(basic_elt(env, 0), v_56);
    env = stack[-3];
    v_56 = Lappend_2(nil, stack[0], v_56);
    env = stack[-3];
    {
        LispObject v_62 = stack[-2];
        LispObject fn = basic_elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_62, v_56);
    }
    v_56 = nil;
    return onevalue(v_56);
}



// Code for evaluate!-horner

static LispObject CC_evaluateKhorner(LispObject env,
                         LispObject v_2)
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
    v_33 = stack[-1];
    v_32 = qvalue(basic_elt(env, 1)); // horner!-cache!*
    v_32 = Lassoc(nil, v_33, v_32);
    stack[-2] = v_32;
    v_32 = stack[-2];
    if (v_32 == nil) goto v_11;
    v_32 = stack[-2];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    goto v_9;
v_11:
    v_32 = stack[-1];
    {   LispObject fn = basic_elt(env, 2); // simp!*
    v_32 = (*qfn1(fn))(fn, v_32);
    }
    env = stack[-3];
    stack[-2] = v_32;
    v_32 = stack[-2];
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = car(v_32);
    {   LispObject fn = basic_elt(env, 3); // hornerf
    stack[0] = (*qfn1(fn))(fn, v_32);
    }
    env = stack[-3];
    v_32 = stack[-2];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    {   LispObject fn = basic_elt(env, 3); // hornerf
    v_32 = (*qfn1(fn))(fn, v_32);
    }
    env = stack[-3];
    v_32 = cons(stack[0], v_32);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 4); // prepsq
    v_32 = (*qfn1(fn))(fn, v_32);
    }
    env = stack[-3];
    stack[-2] = v_32;
    v_34 = stack[-1];
    v_33 = stack[-2];
    v_32 = qvalue(basic_elt(env, 1)); // horner!-cache!*
    v_32 = acons(v_34, v_33, v_32);
    env = stack[-3];
    setvalue(basic_elt(env, 1), v_32); // horner!-cache!*
    v_32 = stack[-2];
    goto v_9;
    v_32 = nil;
v_9:
    return onevalue(v_32);
}



// Code for !*!*a2i

static LispObject CC_HHa2i(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_18, v_19;
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
    v_18 = v_3;
    stack[0] = v_2;
// end of prologue
    v_19 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // intexprnp
    v_18 = (*qfn2(fn))(fn, v_19, v_18);
    }
    env = stack[-1];
    if (v_18 == nil) goto v_8;
    v_18 = stack[0];
    goto v_6;
v_8:
    v_19 = basic_elt(env, 1); // ieval
    v_18 = stack[0];
    return list2(v_19, v_18);
    v_18 = nil;
v_6:
    return onevalue(v_18);
}



// Code for mo!=zero

static LispObject CC_moMzero(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_25, v_26, v_27;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_26 = v_2;
// end of prologue
v_1:
    v_25 = v_26;
    if (v_25 == nil) goto v_6;
    else goto v_7;
v_6:
    v_25 = lisp_true;
    goto v_5;
v_7:
    v_25 = v_26;
    if (!car_legal(v_25)) v_27 = carerror(v_25); else
    v_27 = car(v_25);
    v_25 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_27 == v_25) goto v_14;
    else goto v_15;
v_14:
    v_25 = v_26;
    if (!car_legal(v_25)) v_25 = cdrerror(v_25); else
    v_25 = cdr(v_25);
    v_26 = v_25;
    goto v_1;
v_15:
    v_25 = nil;
    goto v_13;
    v_25 = nil;
v_13:
    goto v_5;
    v_25 = nil;
v_5:
    return onevalue(v_25);
}



// Code for dv_ind2var

static LispObject CC_dv_ind2var(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21, v_22;
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
    stack[-1] = stack[0];
    v_21 = qvalue(basic_elt(env, 1)); // g_dvnames
    {   LispObject fn = basic_elt(env, 3); // upbve
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-2];
    v_21 = (LispObject)lesseq2(stack[-1], v_21);
    v_21 = v_21 ? lisp_true : nil;
    env = stack[-2];
    if (v_21 == nil) goto v_7;
    stack[-1] = qvalue(basic_elt(env, 1)); // g_dvnames
    v_21 = stack[0];
    v_21 = sub1(v_21);
    {
        LispObject v_25 = stack[-1];
        return Lgetv(nil, v_25, v_21);
    }
v_7:
    v_22 = qvalue(basic_elt(env, 2)); // g_dvbase
    v_21 = stack[0];
    {
        LispObject fn = basic_elt(env, 4); // mkid
        return (*qfn2(fn))(fn, v_22, v_21);
    }
    v_21 = nil;
    return onevalue(v_21);
}



// Code for outer!-simpsqrt

static LispObject CC_outerKsimpsqrt(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16 = v_2;
// end of prologue
    v_15 = qvalue(basic_elt(env, 1)); // !*inside!-int!*
    if (v_15 == nil) goto v_7;
    v_15 = v_16;
    {
        LispObject fn = basic_elt(env, 2); // proper!-simpsqrt
        return (*qfn1(fn))(fn, v_15);
    }
v_7:
    v_15 = v_16;
    {
        LispObject fn = basic_elt(env, 3); // simpsqrt
        return (*qfn1(fn))(fn, v_15);
    }
    v_15 = nil;
    return onevalue(v_15);
}



// Code for lalr_warn_shift_reduce_conflict

static LispObject CC_lalr_warn_shift_reduce_conflict(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_44;
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
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_44 = Lposn(nil);
    env = stack[-3];
    v_44 = (LispObject)zerop(v_44);
    v_44 = v_44 ? lisp_true : nil;
    env = stack[-3];
    if (v_44 == nil) goto v_8;
    else goto v_9;
v_8:
    v_44 = Lterpri(nil);
    env = stack[-3];
    goto v_7;
v_9:
v_7:
    v_44 = basic_elt(env, 1); // "+++ Shift/reduce conflict in itemset #"
    v_44 = Lprinc(nil, v_44);
    env = stack[-3];
    v_44 = stack[0];
    v_44 = Lprin(nil, v_44);
    env = stack[-3];
    v_44 = basic_elt(env, 2); // " on lookahead "
    v_44 = Lprinc(nil, v_44);
    env = stack[-3];
    v_44 = stack[-2];
    if (!car_legal(v_44)) v_44 = carerror(v_44); else
    v_44 = car(v_44);
    {   LispObject fn = basic_elt(env, 6); // lalr_prin_symbol
    v_44 = (*qfn1(fn))(fn, v_44);
    }
    env = stack[-3];
    v_44 = Lterpri(nil);
    env = stack[-3];
    v_44 = basic_elt(env, 3); // "Reduce: "
    v_44 = Lprinc(nil, v_44);
    env = stack[-3];
    v_44 = stack[-1];
    if (!car_legal(v_44)) v_44 = cdrerror(v_44); else
    v_44 = cdr(v_44);
    if (!car_legal(v_44)) v_44 = carerror(v_44); else
    v_44 = car(v_44);
    if (!car_legal(v_44)) v_44 = cdrerror(v_44); else
    v_44 = cdr(v_44);
    if (!car_legal(v_44)) v_44 = carerror(v_44); else
    v_44 = car(v_44);
    {   LispObject fn = basic_elt(env, 7); // lalr_prin_production
    v_44 = (*qfn1(fn))(fn, v_44);
    }
    env = stack[-3];
    v_44 = Lterpri(nil);
    env = stack[-3];
    v_44 = basic_elt(env, 4); // "Shift: to state #"
    v_44 = Lprinc(nil, v_44);
    env = stack[-3];
    v_44 = stack[-2];
    if (!car_legal(v_44)) v_44 = cdrerror(v_44); else
    v_44 = cdr(v_44);
    if (!car_legal(v_44)) v_44 = carerror(v_44); else
    v_44 = car(v_44);
    if (!car_legal(v_44)) v_44 = cdrerror(v_44); else
    v_44 = cdr(v_44);
    if (!car_legal(v_44)) v_44 = carerror(v_44); else
    v_44 = car(v_44);
    v_44 = Lprin(nil, v_44);
    env = stack[-3];
    v_44 = Lterpri(nil);
    env = stack[-3];
    v_44 = basic_elt(env, 5); // "Resolved in favour of the shift operation"
    v_44 = Lprintc(nil, v_44);
        return Lterpri(nil);
}



// Code for plusdf

static LispObject CC_plusdf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_85, v_86, v_87;
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
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    stack[0] = nil;
v_8:
    v_85 = stack[-2];
    if (v_85 == nil) goto v_11;
    else goto v_12;
v_11:
    v_86 = stack[0];
    v_85 = stack[-1];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_86, v_85);
    }
v_12:
    v_85 = stack[-1];
    if (v_85 == nil) goto v_17;
    else goto v_18;
v_17:
    v_86 = stack[0];
    v_85 = stack[-2];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_86, v_85);
    }
v_18:
    v_85 = stack[-2];
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (!car_legal(v_85)) v_86 = carerror(v_85); else
    v_86 = car(v_85);
    v_85 = stack[-1];
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (equal(v_86, v_85)) goto v_23;
    else goto v_24;
v_23:
    stack[-3] = stack[0];
    v_85 = stack[-2];
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (!car_legal(v_85)) v_86 = cdrerror(v_85); else
    v_86 = cdr(v_85);
    v_85 = stack[-1];
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (!car_legal(v_85)) v_85 = cdrerror(v_85); else
    v_85 = cdr(v_85);
    {   LispObject fn = basic_elt(env, 2); // !*addsq
    stack[0] = (*qfn2(fn))(fn, v_86, v_85);
    }
    env = stack[-4];
    v_85 = stack[-2];
    if (!car_legal(v_85)) v_86 = cdrerror(v_85); else
    v_86 = cdr(v_85);
    v_85 = stack[-1];
    if (!car_legal(v_85)) v_85 = cdrerror(v_85); else
    v_85 = cdr(v_85);
    v_85 = CC_plusdf(basic_elt(env, 0), v_86, v_85);
    env = stack[-4];
    v_86 = stack[0];
    v_87 = v_86;
    if (!car_legal(v_87)) v_87 = carerror(v_87); else
    v_87 = car(v_87);
    if (v_87 == nil) goto v_49;
    else goto v_50;
v_49:
    goto v_48;
v_50:
    v_87 = stack[-2];
    if (!car_legal(v_87)) v_87 = carerror(v_87); else
    v_87 = car(v_87);
    if (!car_legal(v_87)) v_87 = carerror(v_87); else
    v_87 = car(v_87);
    v_85 = acons(v_87, v_86, v_85);
    env = stack[-4];
    goto v_48;
    v_85 = nil;
v_48:
    {
        LispObject v_92 = stack[-3];
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_92, v_85);
    }
v_24:
    v_85 = stack[-2];
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (!car_legal(v_85)) v_86 = carerror(v_85); else
    v_86 = car(v_85);
    v_85 = stack[-1];
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    if (!car_legal(v_85)) v_85 = carerror(v_85); else
    v_85 = car(v_85);
    {   LispObject fn = basic_elt(env, 3); // orddf
    v_85 = (*qfn2(fn))(fn, v_86, v_85);
    }
    env = stack[-4];
    if (v_85 == nil) goto v_63;
    v_85 = stack[-2];
    if (!car_legal(v_85)) v_86 = carerror(v_85); else
    v_86 = car(v_85);
    v_85 = stack[0];
    v_85 = cons(v_86, v_85);
    env = stack[-4];
    stack[0] = v_85;
    v_85 = stack[-2];
    if (!car_legal(v_85)) v_85 = cdrerror(v_85); else
    v_85 = cdr(v_85);
    stack[-2] = v_85;
    goto v_8;
v_63:
    v_85 = stack[-1];
    if (!car_legal(v_85)) v_86 = carerror(v_85); else
    v_86 = car(v_85);
    v_85 = stack[0];
    v_85 = cons(v_86, v_85);
    env = stack[-4];
    stack[0] = v_85;
    v_85 = stack[-1];
    if (!car_legal(v_85)) v_85 = cdrerror(v_85); else
    v_85 = cdr(v_85);
    stack[-1] = v_85;
    goto v_8;
    v_85 = nil;
    return onevalue(v_85);
}



// Code for get!*inverse

static LispObject CC_getHinverse(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_19, v_20, v_21;
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
    v_20 = v_3;
    v_19 = v_2;
// end of prologue
    v_21 = v_19;
    v_19 = basic_elt(env, 1); // inverse
    v_19 = get(v_21, v_19);
    env = stack[-1];
    v_21 = v_19;
    v_19 = v_21;
    if (!car_legal(v_19)) v_19 = cdrerror(v_19); else
    v_19 = cdr(v_19);
    if (!car_legal(v_19)) stack[0] = carerror(v_19); else
    stack[0] = car(v_19);
    v_19 = v_20;
    v_20 = v_21;
    if (!car_legal(v_20)) v_20 = carerror(v_20); else
    v_20 = car(v_20);
    {   LispObject fn = basic_elt(env, 2); // give!*position
    v_19 = (*qfn2(fn))(fn, v_19, v_20);
    }
    env = stack[-1];
    {
        LispObject v_23 = stack[0];
        LispObject fn = basic_elt(env, 3); // nth
        return (*qfn2(fn))(fn, v_23, v_19);
    }
    return onevalue(v_19);
}



// Code for pasf_anegrel

static LispObject CC_pasf_anegrel(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16, v_17;
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
    v_17 = v_2;
// end of prologue
    v_16 = v_17;
    v_15 = basic_elt(env, 1); // ((equal . equal) (neq . neq) (leq . geq) (geq . leq) (lessp . greaterp) (greaterp . lessp) (cong . cong) (ncong . ncong))
    v_15 = Latsoc(nil, v_16, v_15);
    if (!car_legal(v_15)) v_15 = cdrerror(v_15); else
    v_15 = cdr(v_15);
    if (v_15 == nil) goto v_6;
    else goto v_5;
v_6:
    v_15 = basic_elt(env, 2); // "pasf_anegrel: unknown operator "
    v_16 = v_17;
    v_15 = list2(v_15, v_16);
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 3); // rederr
        return (*qfn1(fn))(fn, v_15);
    }
v_5:
    return onevalue(v_15);
}



// Code for cgp_lbc

static LispObject CC_cgp_lbc(LispObject env,
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
    {   LispObject fn = basic_elt(env, 1); // cgp_rp
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // dip_lbc
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for getargsrd

static LispObject CC_getargsrd(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_17, v_18;
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
    v_18 = qvalue(basic_elt(env, 1)); // char
    v_17 = basic_elt(env, 2); // (b v a r)
    if (equal(v_18, v_17)) goto v_8;
    else goto v_9;
v_8:
    {   LispObject fn = basic_elt(env, 3); // bvarrd
    v_17 = (*qfn0(fn))(fn);
    }
    env = stack[-1];
    stack[0] = v_17;
    {   LispObject fn = basic_elt(env, 4); // lex
    v_17 = (*qfn0(fn))(fn);
    }
    env = stack[-1];
    v_17 = CC_getargsrd(basic_elt(env, 0));
    {
        LispObject v_20 = stack[0];
        return cons(v_20, v_17);
    }
v_9:
    v_17 = nil;
    return onevalue(v_17);
}



// Code for mconv1

static LispObject CC_mconv1(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_40, v_41;
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
    stack[-2] = nil;
v_7:
    v_40 = stack[-1];
    if (!consp(v_40)) goto v_14;
    else goto v_15;
v_14:
    v_40 = lisp_true;
    goto v_13;
v_15:
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    v_40 = (consp(v_40) ? nil : lisp_true);
    goto v_13;
    v_40 = nil;
v_13:
    if (v_40 == nil) goto v_11;
    stack[0] = stack[-2];
    v_40 = stack[-1];
    {   LispObject fn = basic_elt(env, 1); // drnconv
    v_40 = (*qfn1(fn))(fn, v_40);
    }
    env = stack[-3];
    {
        LispObject v_45 = stack[0];
        LispObject fn = basic_elt(env, 2); // nreverse
        return (*qfn2(fn))(fn, v_45, v_40);
    }
v_11:
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    if (!car_legal(v_40)) stack[0] = carerror(v_40); else
    stack[0] = car(v_40);
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_40 = carerror(v_40); else
    v_40 = car(v_40);
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = cdr(v_40);
    v_41 = CC_mconv1(basic_elt(env, 0), v_40);
    env = stack[-3];
    v_40 = stack[-2];
    v_40 = acons(stack[0], v_41, v_40);
    env = stack[-3];
    stack[-2] = v_40;
    v_40 = stack[-1];
    if (!car_legal(v_40)) v_40 = cdrerror(v_40); else
    v_40 = cdr(v_40);
    stack[-1] = v_40;
    goto v_7;
    v_40 = nil;
    return onevalue(v_40);
}



// Code for evaluate

static LispObject CC_evaluate(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_46, v_47, v_48;
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
    push2(nil, nil);
    stack_popper stack_popper_var(8);
// copy arguments values to proper place
    v_47 = v_4;
    v_48 = v_3;
    stack[-5] = v_2;
// end of prologue
// Binding !*evaluateerror
// FLUIDBIND: reloadenv=7 litvec-offset=1 saveloc=4
{   bind_fluid_stack bind_fluid_var(-7, 1, -4);
    setvalue(basic_elt(env, 1), nil); // !*evaluateerror
    v_46 = qvalue(basic_elt(env, 2)); // !*protfg
    v_46 = (v_46 == nil ? lisp_true : nil);
    stack[-3] = v_46;
    v_46 = v_48;
    {   LispObject fn = basic_elt(env, 6); // pair
    v_46 = (*qfn2(fn))(fn, v_46, v_47);
    }
    env = stack[-7];
    stack[-6] = v_46;
    v_47 = nil;
    v_46 = lisp_true;
// Binding !*msg
// FLUIDBIND: reloadenv=7 litvec-offset=3 saveloc=2
{   bind_fluid_stack bind_fluid_var(-7, 3, -2);
    setvalue(basic_elt(env, 3), v_47); // !*msg
// Binding !*protfg
// FLUIDBIND: reloadenv=7 litvec-offset=2 saveloc=1
{   bind_fluid_stack bind_fluid_var(-7, 2, -1);
    setvalue(basic_elt(env, 2), v_46); // !*protfg
    stack[0] = basic_elt(env, 4); // evaluate0
    v_46 = stack[-5];
    stack[-5] = Lmkquote(nil, v_46);
    env = stack[-7];
    v_46 = stack[-6];
    v_46 = Lmkquote(nil, v_46);
    env = stack[-7];
    v_48 = list3(stack[0], stack[-5], v_46);
    env = stack[-7];
    v_47 = stack[-3];
    v_46 = nil;
    {   LispObject fn = basic_elt(env, 7); // errorset
    v_46 = (*qfn3(fn))(fn, v_48, v_47, v_46);
    }
    env = stack[-7];
    stack[0] = v_46;
    ;}  // end of a binding scope
    ;}  // end of a binding scope
    v_46 = stack[0];
    {   LispObject fn = basic_elt(env, 8); // errorp
    v_46 = (*qfn1(fn))(fn, v_46);
    }
    env = stack[-7];
    if (v_46 == nil) goto v_38;
    v_46 = basic_elt(env, 5); // "error during function evaluation (e.g. singularity)"
    {   LispObject fn = basic_elt(env, 9); // rederr
    v_46 = (*qfn1(fn))(fn, v_46);
    }
    goto v_36;
v_38:
v_36:
    v_46 = stack[0];
    if (!car_legal(v_46)) v_46 = carerror(v_46); else
    v_46 = car(v_46);
    ;}  // end of a binding scope
    return onevalue(v_46);
}



// Code for assert_procstat!-argl

static LispObject CC_assert_procstatKargl(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_110, v_111, v_112;
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
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// end of prologue
    stack[0] = nil;
v_11:
    v_111 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = basic_elt(env, 2); // !*rpar!*
    if (v_111 == v_110) goto v_14;
    else goto v_15;
v_14:
    goto v_10;
v_15:
    {   LispObject fn = basic_elt(env, 12); // eolcheck
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    if (symbolp(v_110)) goto v_23;
    v_111 = basic_elt(env, 3); // "Expecting identifier but found"
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = list2(v_111, v_110);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // assert_rederr
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-3];
    goto v_21;
v_23:
v_21:
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    stack[-2] = v_110;
    {   LispObject fn = basic_elt(env, 14); // scan
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    v_111 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = basic_elt(env, 4); // !*colon!*
    if (v_111 == v_110) goto v_33;
    else goto v_34;
v_33:
    {   LispObject fn = basic_elt(env, 14); // scan
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    {   LispObject fn = basic_elt(env, 15); // assert_typesyntaxp
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-3];
    if (v_110 == nil) goto v_40;
    else goto v_41;
v_40:
    v_111 = basic_elt(env, 5); // "Expecting type but found"
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = list2(v_111, v_110);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // assert_rederr
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-3];
    goto v_39;
v_41:
v_39:
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    stack[-1] = v_110;
    {   LispObject fn = basic_elt(env, 14); // scan
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    v_110 = stack[-1];
    goto v_32;
v_34:
    v_110 = nil;
v_32:
    v_112 = stack[-2];
    v_111 = v_110;
    v_110 = stack[0];
    v_110 = acons(v_112, v_111, v_110);
    env = stack[-3];
    stack[0] = v_110;
    v_111 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = basic_elt(env, 6); // (!*comma!* !*rpar!*)
    v_110 = Lmemq(nil, v_111, v_110);
    if (v_110 == nil) goto v_57;
    else goto v_58;
v_57:
    v_111 = basic_elt(env, 7); // "Expecting ',' or ')' but found"
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = list2(v_111, v_110);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // assert_rederr
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-3];
    goto v_56;
v_58:
v_56:
    v_111 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = basic_elt(env, 8); // !*comma!*
    if (v_111 == v_110) goto v_68;
    else goto v_69;
v_68:
    {   LispObject fn = basic_elt(env, 14); // scan
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    goto v_67;
v_69:
v_67:
    goto v_11;
v_10:
    v_111 = qvalue(basic_elt(env, 9)); // nxtsym!*
    v_110 = basic_elt(env, 4); // !*colon!*
    if (v_111 == v_110) goto v_80;
    else goto v_81;
v_80:
    v_110 = lisp_true;
    goto v_79;
v_81:
    v_111 = qvalue(basic_elt(env, 9)); // nxtsym!*
    v_110 = basic_elt(env, 10); // !:
    v_110 = (v_111 == v_110 ? lisp_true : nil);
    goto v_79;
    v_110 = nil;
v_79:
    if (v_110 == nil) goto v_77;
    {   LispObject fn = basic_elt(env, 14); // scan
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 14); // scan
    v_110 = (*qfn0(fn))(fn);
    }
    env = stack[-3];
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    {   LispObject fn = basic_elt(env, 15); // assert_typesyntaxp
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-3];
    if (v_110 == nil) goto v_94;
    else goto v_95;
v_94:
    v_111 = basic_elt(env, 5); // "Expecting type but found"
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    v_110 = list2(v_111, v_110);
    env = stack[-3];
    {   LispObject fn = basic_elt(env, 13); // assert_rederr
    v_110 = (*qfn1(fn))(fn, v_110);
    }
    env = stack[-3];
    goto v_93;
v_95:
v_93:
    v_110 = qvalue(basic_elt(env, 1)); // cursym!*
    goto v_75;
v_77:
    v_110 = nil;
v_75:
    v_112 = basic_elt(env, 11); // returnvalue
    v_111 = v_110;
    v_110 = stack[0];
    v_110 = acons(v_112, v_111, v_110);
    stack[0] = v_110;
    v_110 = stack[0];
        return Lnreverse(nil, v_110);
    return onevalue(v_110);
}



// Code for subeval1

static LispObject CC_subeval1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_69, v_70, v_71;
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
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
v_11:
    v_69 = stack[-2];
    if (v_69 == nil) goto v_14;
    v_69 = stack[-2];
    if (!car_legal(v_69)) v_69 = carerror(v_69); else
    v_69 = car(v_69);
    if (!car_legal(v_69)) v_70 = carerror(v_69); else
    v_70 = car(v_69);
    v_69 = stack[-2];
    if (!car_legal(v_69)) v_69 = carerror(v_69); else
    v_69 = car(v_69);
    if (!car_legal(v_69)) v_69 = cdrerror(v_69); else
    v_69 = cdr(v_69);
    if (equal(v_70, v_69)) goto v_18;
    else goto v_14;
v_18:
    goto v_15;
v_14:
    goto v_10;
v_15:
    v_69 = stack[-2];
    if (!car_legal(v_69)) v_69 = cdrerror(v_69); else
    v_69 = cdr(v_69);
    stack[-2] = v_69;
    goto v_11;
v_10:
    v_69 = stack[-2];
    if (v_69 == nil) goto v_30;
    else goto v_31;
v_30:
    v_69 = stack[-1];
    goto v_8;
v_31:
    v_69 = stack[-1];
    {   LispObject fn = basic_elt(env, 5); // getrtype
    v_69 = (*qfn1(fn))(fn, v_69);
    }
    env = stack[-4];
    v_71 = v_69;
    if (v_69 == nil) goto v_35;
    v_70 = v_71;
    v_69 = basic_elt(env, 1); // subfn
    v_69 = get(v_70, v_69);
    env = stack[-4];
    v_70 = v_69;
    if (v_69 == nil) goto v_41;
    v_71 = v_70;
    v_70 = stack[-2];
    v_69 = stack[-1];
        return Lapply2(nil, v_71, v_70, v_69);
v_41:
    stack[-3] = basic_elt(env, 2); // alg
    stack[0] = (LispObject)368+TAG_FIXNUM; // 23
    v_69 = basic_elt(env, 3); // "No substitution defined for type"
    v_70 = v_71;
    v_69 = list2(v_69, v_70);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 6); // rerror
    v_69 = (*qfn3(fn))(fn, stack[-3], stack[0], v_69);
    }
    env = stack[-4];
    goto v_39;
v_39:
    goto v_29;
v_35:
v_29:
    v_69 = stack[-1];
    {   LispObject fn = basic_elt(env, 7); // simp
    v_70 = (*qfn1(fn))(fn, v_69);
    }
    env = stack[-4];
    v_69 = stack[-2];
    {   LispObject fn = basic_elt(env, 8); // subsq
    v_69 = (*qfn2(fn))(fn, v_70, v_69);
    }
    env = stack[-4];
    stack[-2] = v_69;
    v_69 = lisp_true;
// Binding !*sub2
// FLUIDBIND: reloadenv=4 litvec-offset=4 saveloc=0
{   bind_fluid_stack bind_fluid_var(-4, 4, 0);
    setvalue(basic_elt(env, 4), v_69); // !*sub2
    v_69 = stack[-2];
    {   LispObject fn = basic_elt(env, 9); // subs2
    v_69 = (*qfn1(fn))(fn, v_69);
    }
    env = stack[-4];
    stack[-2] = v_69;
    ;}  // end of a binding scope
    v_69 = stack[-2];
    {
        LispObject fn = basic_elt(env, 10); // mk!*sq
        return (*qfn1(fn))(fn, v_69);
    }
v_8:
    return onevalue(v_69);
}



setup_type const u34_setup[] =
{
    {"dipprodin",               G0W2,     G1W2,     CC_dipprodin,G3W2,  G4W2},
    {"po:statep",               G0W1,     CC_poTstatep,G2W1,  G3W1,     G4W1},
    {"color-strand",            G0W3,     G1W3,     G2W3,     CC_colorKstrand,G4W3},
    {"greaterpcdr",             G0W2,     G1W2,     CC_greaterpcdr,G3W2,G4W2},
    {"fs:prin",                 G0W1,     CC_fsTprin,G2W1,    G3W1,     G4W1},
    {"msolve-poly1",            G0W2,     G1W2,     CC_msolveKpoly1,G3W2,G4W2},
    {"cde_replace_nth",         G0W3,     G1W3,     G2W3,     CC_cde_replace_nth,G4W3},
    {"gcd-with-number",         G0W2,     G1W2,     CC_gcdKwithKnumber,G3W2,G4W2},
    {"polynomwrite",            G0W1,     CC_polynomwrite,G2W1,G3W1,    G4W1},
    {"gen+can+bas",             G0W1,     CC_genLcanLbas,G2W1,G3W1,     G4W1},
    {"cl_bvarl1",               G0W1,     CC_cl_bvarl1,G2W1,  G3W1,     G4W1},
    {"qqe_ofsf_varlat",         G0W1,     CC_qqe_ofsf_varlat,G2W1,G3W1, G4W1},
    {"pasf_zcong",              G0W1,     CC_pasf_zcong,G2W1, G3W1,     G4W1},
    {"ev_dif",                  G0W2,     G1W2,     CC_ev_dif,G3W2,     G4W2},
    {"bc_mkat",                 G0W2,     G1W2,     CC_bc_mkat,G3W2,    G4W2},
    {"vectorml",                G0W1,     CC_vectorml,G2W1,   G3W1,     G4W1},
    {"delyzz",                  G0W2,     G1W2,     CC_delyzz,G3W2,     G4W2},
    {"make-unique-freevars",    G0W1,     CC_makeKuniqueKfreevars,G2W1,G3W1,G4W1},
    {"fieldp",                  G0W1,     CC_fieldp,G2W1,     G3W1,     G4W1},
    {"noncomexpf",              G0W1,     CC_noncomexpf,G2W1, G3W1,     G4W1},
    {"dipsimpcont",             G0W1,     CC_dipsimpcont,G2W1,G3W1,     G4W1},
    {"calc_coeff",              G0W2,     G1W2,     CC_calc_coeff,G3W2, G4W2},
    {"log_freevars_list",       G0W3,     G1W3,     G2W3,     CC_log_freevars_list,G4W3},
    {"ratfunpri1",              G0W1,     CC_ratfunpri1,G2W1, G3W1,     G4W1},
    {"dp_neworder",             G0W1,     CC_dp_neworder,G2W1,G3W1,     G4W1},
    {"*f2di",                   G0W2,     G1W2,     CC_Hf2di, G3W2,     G4W2},
    {"dfprintfn",               G0W1,     CC_dfprintfn,G2W1,  G3W1,     G4W1},
    {"msolve-polyn",            G0W2,     G1W2,     CC_msolveKpolyn,G3W2,G4W2},
    {"reduce-mod-eigf",         G0W2,     G1W2,     CC_reduceKmodKeigf,G3W2,G4W2},
    {"cl_apply2ats1",           G0W3,     G1W3,     G2W3,     CC_cl_apply2ats1,G4W3},
    {"cl_susicpknowl",          G0W1,     CC_cl_susicpknowl,G2W1,G3W1,  G4W1},
    {"vdp_putprop",             G0W3,     G1W3,     G2W3,     CC_vdp_putprop,G4W3},
    {"listrd",                  CC_listrd,G1W0,     G2W0,     G3W0,     G4W0},
    {"resume",                  G0W2,     G1W2,     CC_resume,G3W2,     G4W2},
    {"evinvlexcomp",            G0W2,     G1W2,     CC_evinvlexcomp,G3W2,G4W2},
    {"vdpilcomb1",              G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_vdpilcomb1},
    {"unplus",                  G0W1,     CC_unplus,G2W1,     G3W1,     G4W1},
    {"evaluate-horner",         G0W1,     CC_evaluateKhorner,G2W1,G3W1, G4W1},
    {"**a2i",                   G0W2,     G1W2,     CC_HHa2i, G3W2,     G4W2},
    {"mo=zero",                 G0W1,     CC_moMzero,G2W1,    G3W1,     G4W1},
    {"dv_ind2var",              G0W1,     CC_dv_ind2var,G2W1, G3W1,     G4W1},
    {"outer-simpsqrt",          G0W1,     CC_outerKsimpsqrt,G2W1,G3W1,  G4W1},
    {"lalr_warn_shift_reduce_conflict",G0W3,G1W3,   G2W3,     CC_lalr_warn_shift_reduce_conflict,G4W3},
    {"plusdf",                  G0W2,     G1W2,     CC_plusdf,G3W2,     G4W2},
    {"get*inverse",             G0W2,     G1W2,     CC_getHinverse,G3W2,G4W2},
    {"pasf_anegrel",            G0W1,     CC_pasf_anegrel,G2W1,G3W1,    G4W1},
    {"cgp_lbc",                 G0W1,     CC_cgp_lbc,G2W1,    G3W1,     G4W1},
    {"getargsrd",               CC_getargsrd,G1W0,  G2W0,     G3W0,     G4W0},
    {"mconv1",                  G0W1,     CC_mconv1,G2W1,     G3W1,     G4W1},
    {"evaluate",                G0W3,     G1W3,     G2W3,     CC_evaluate,G4W3},
    {"assert_procstat-argl",    CC_assert_procstatKargl,G1W0,G2W0,G3W0, G4W0},
    {"subeval1",                G0W2,     G1W2,     CC_subeval1,G3W2,   G4W2},
    {NULL, (no_args *)"u34", (one_arg *)"132947 4063760 6425216",
        NULL, NULL, NULL}
};

// end of generated code
