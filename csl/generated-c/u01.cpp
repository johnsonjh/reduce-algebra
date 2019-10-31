
// $destdir/u01.c        Machine generated C code

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



// Code for smember

static LispObject CC_smember(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_29, v_30;
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
v_1:
    v_30 = stack[-1];
    v_29 = stack[0];
    if (equal(v_30, v_29)) goto v_7;
    else goto v_8;
v_7:
    v_29 = lisp_true;
    goto v_6;
v_8:
    v_29 = stack[0];
    if (!consp(v_29)) goto v_12;
    else goto v_13;
v_12:
    v_29 = nil;
    goto v_6;
v_13:
    v_30 = stack[-1];
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    v_29 = CC_smember(basic_elt(env, 0), v_30, v_29);
    env = stack[-2];
    if (v_29 == nil) goto v_20;
    else goto v_19;
v_20:
    v_30 = stack[-1];
    v_29 = stack[0];
    if (!car_legal(v_29)) v_29 = cdrerror(v_29); else
    v_29 = cdr(v_29);
    stack[-1] = v_30;
    stack[0] = v_29;
    goto v_1;
v_19:
    goto v_6;
    v_29 = nil;
v_6:
    return onevalue(v_29);
}



// Code for !*n2f

static LispObject CC_Hn2f(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
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
    v_15 = v_2;
// end of prologue
    v_14 = v_15;
    v_14 = (LispObject)zerop(v_14);
    v_14 = v_14 ? lisp_true : nil;
    if (v_14 == nil) goto v_7;
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = v_15;
    goto v_5;
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for setdiff

static LispObject CC_setdiff(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_26, v_27;
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
    v_26 = v_2;
// end of prologue
v_7:
    v_27 = stack[0];
    if (v_27 == nil) goto v_10;
    else goto v_11;
v_10:
    goto v_6;
v_11:
    v_27 = v_26;
    if (v_27 == nil) goto v_14;
    else goto v_15;
v_14:
    v_26 = nil;
    goto v_6;
v_15:
    v_27 = stack[0];
    if (!car_legal(v_27)) v_27 = carerror(v_27); else
    v_27 = car(v_27);
    v_26 = Ldelete(nil, v_27, v_26);
    env = stack[-1];
    v_27 = stack[0];
    if (!car_legal(v_27)) v_27 = cdrerror(v_27); else
    v_27 = cdr(v_27);
    stack[0] = v_27;
    goto v_7;
    v_26 = nil;
v_6:
    return onevalue(v_26);
}



// Code for terminalp

static LispObject CC_terminalp(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_13;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_13 = qvalue(basic_elt(env, 1)); // !*int
    if (v_13 == nil) goto v_5;
    else goto v_6;
v_5:
    v_13 = nil;
    goto v_4;
v_6:
    v_13 = qvalue(basic_elt(env, 2)); // ifl!*
    v_13 = (v_13 == nil ? lisp_true : nil);
    goto v_4;
    v_13 = nil;
v_4:
    return onevalue(v_13);
}



// Code for multf

static LispObject CC_multf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_18, v_19, v_20;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19 = v_3;
    v_20 = v_2;
// end of prologue
    v_18 = qvalue(basic_elt(env, 1)); // !*physop!-loaded
    if (v_18 == nil) goto v_8;
    v_18 = v_20;
    {
        LispObject fn = basic_elt(env, 2); // physop!-multf
        return (*qfn2(fn))(fn, v_18, v_19);
    }
v_8:
    v_18 = v_20;
    {
        LispObject fn = basic_elt(env, 3); // poly!-multf
        return (*qfn2(fn))(fn, v_18, v_19);
    }
    v_18 = nil;
    return onevalue(v_18);
}



// Code for monomgetvariabledegree

static LispObject CC_monomgetvariabledegree(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    v_47 = v_2;
// end of prologue
    v_48 = v_47;
    v_47 = (LispObject)16+TAG_FIXNUM; // 1
    v_47 = Lgetv(nil, v_48, v_47);
    env = stack[-2];
    stack[-1] = v_47;
v_13:
    v_47 = stack[-1];
    if (!car_legal(v_47)) v_47 = carerror(v_47); else
    v_47 = car(v_47);
    if (v_47 == nil) goto v_16;
    v_47 = stack[-1];
    if (!car_legal(v_47)) v_48 = carerror(v_47); else
    v_48 = car(v_47);
    v_47 = stack[0];
    v_47 = (LispObject)greaterp2(v_48, v_47);
    v_47 = v_47 ? lisp_true : nil;
    env = stack[-2];
    if (v_47 == nil) goto v_16;
    goto v_17;
v_16:
    goto v_12;
v_17:
    v_47 = stack[-1];
    if (!car_legal(v_47)) v_47 = cdrerror(v_47); else
    v_47 = cdr(v_47);
    stack[-1] = v_47;
    goto v_13;
v_12:
    v_47 = stack[-1];
    if (!car_legal(v_47)) v_47 = carerror(v_47); else
    v_47 = car(v_47);
    if (v_47 == nil) goto v_33;
    v_47 = stack[-1];
    if (!car_legal(v_47)) v_48 = carerror(v_47); else
    v_48 = car(v_47);
    v_47 = stack[0];
    if (equal(v_48, v_47)) goto v_37;
    else goto v_33;
v_37:
    v_47 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_7;
v_33:
    v_47 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_7;
    v_47 = nil;
v_7:
    return onevalue(v_47);
}



// Code for quotelist

static LispObject CC_quotelist(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    v_5 = basic_elt(env, 1); // list
    return onevalue(v_5);
}



// Code for num!-exponents

static LispObject CC_numKexponents(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_48;
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
    v_48 = stack[0];
    if (!consp(v_48)) goto v_10;
    else goto v_11;
v_10:
    v_48 = lisp_true;
    goto v_9;
v_11:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    v_48 = (consp(v_48) ? nil : lisp_true);
    goto v_9;
    v_48 = nil;
v_9:
    if (v_48 == nil) goto v_7;
    v_48 = lisp_true;
    goto v_5;
v_7:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    v_48 = integerp(v_48);
    if (v_48 == nil) goto v_24;
    else goto v_25;
v_24:
    v_48 = nil;
    goto v_23;
v_25:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = carerror(v_48); else
    v_48 = car(v_48);
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    v_48 = CC_numKexponents(basic_elt(env, 0), v_48);
    env = stack[-1];
    if (v_48 == nil) goto v_36;
    else goto v_37;
v_36:
    v_48 = nil;
    goto v_35;
v_37:
    v_48 = stack[0];
    if (!car_legal(v_48)) v_48 = cdrerror(v_48); else
    v_48 = cdr(v_48);
    stack[0] = v_48;
    goto v_1;
    v_48 = nil;
v_35:
    goto v_23;
    v_48 = nil;
v_23:
    goto v_5;
    v_48 = nil;
v_5:
    return onevalue(v_48);
}



// Code for simpcar

static LispObject CC_simpcar(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    if (!car_legal(v_7)) v_7 = carerror(v_7); else
    v_7 = car(v_7);
    {
        LispObject fn = basic_elt(env, 1); // simp
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for wuconstantp

static LispObject CC_wuconstantp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_29, v_30;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_30 = v_2;
// end of prologue
    v_29 = v_30;
    if (!consp(v_29)) goto v_10;
    else goto v_11;
v_10:
    v_29 = lisp_true;
    goto v_9;
v_11:
    v_29 = v_30;
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    v_29 = (consp(v_29) ? nil : lisp_true);
    goto v_9;
    v_29 = nil;
v_9:
    if (v_29 == nil) goto v_7;
    v_29 = lisp_true;
    goto v_5;
v_7:
    v_29 = v_30;
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    if (!car_legal(v_29)) v_29 = carerror(v_29); else
    v_29 = car(v_29);
    v_30 = qvalue(basic_elt(env, 1)); // wuvarlist!*
    v_29 = Lmemq(nil, v_29, v_30);
    v_29 = (v_29 == nil ? lisp_true : nil);
    goto v_5;
    v_29 = nil;
v_5:
    return onevalue(v_29);
}



// Code for mkcopy

static LispObject CC_mkcopy(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_25, v_26;
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
    v_25 = stack[0];
    if (!consp(v_25)) goto v_10;
    else goto v_11;
v_10:
    v_26 = stack[-1];
    v_25 = stack[0];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_26, v_25);
    }
v_11:
    v_25 = stack[0];
    if (!car_legal(v_25)) v_25 = carerror(v_25); else
    v_25 = car(v_25);
    v_26 = CC_mkcopy(basic_elt(env, 0), v_25);
    env = stack[-2];
    v_25 = stack[-1];
    v_25 = cons(v_26, v_25);
    env = stack[-2];
    stack[-1] = v_25;
    v_25 = stack[0];
    if (!car_legal(v_25)) v_25 = cdrerror(v_25); else
    v_25 = cdr(v_25);
    stack[0] = v_25;
    goto v_7;
    v_25 = nil;
    return onevalue(v_25);
}



// Code for mchkopt

static LispObject CC_mchkopt(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_18, v_19, v_20, v_21;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_20 = v_3;
    v_21 = v_2;
// end of prologue
    v_18 = v_20;
    if (!car_legal(v_18)) v_18 = carerror(v_18); else
    v_18 = car(v_18);
    if (!symbolp(v_18)) v_18 = nil;
    else { v_18 = qfastgets(v_18);
           if (v_18 != nil) { v_18 = elt(v_18, 6); // optional
#ifdef RECORD_GET
             if (v_18 != SPID_NOPROP)
                record_get(elt(fastget_names, 6), 1);
             else record_get(elt(fastget_names, 6), 0),
                v_18 = nil; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v_18 == SPID_NOPROP) v_18 = nil; }}
#endif
    v_19 = v_18;
    v_18 = v_19;
    if (v_18 == nil) goto v_12;
    v_18 = v_21;
    {
        LispObject fn = basic_elt(env, 1); // mchkopt1
        return (*qfn3(fn))(fn, v_18, v_20, v_19);
    }
v_12:
    v_18 = nil;
    return onevalue(v_18);
}



// Code for revpr

static LispObject CC_revpr(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_2;
// end of prologue
    v_10 = v_9;
    if (!car_legal(v_10)) v_10 = cdrerror(v_10); else
    v_10 = cdr(v_10);
    if (!car_legal(v_9)) v_9 = carerror(v_9); else
    v_9 = car(v_9);
    return cons(v_10, v_9);
}



// Code for nth

static LispObject CC_nth(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
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
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_9 = v_3;
    v_10 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // pnth
    v_9 = (*qfn2(fn))(fn, v_10, v_9);
    }
    if (!car_legal(v_9)) v_9 = carerror(v_9); else
    v_9 = car(v_9);
    return onevalue(v_9);
}



// Code for talp_getl

static LispObject CC_talp_getl(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_4;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_4 = qvalue(basic_elt(env, 1)); // talp_lang!*
    return onevalue(v_4);
}



// Code for kernels

static LispObject CC_kernels(LispObject env,
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
    v_8 = v_7;
    v_7 = nil;
    {
        LispObject fn = basic_elt(env, 1); // kernels1
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for qqe_rqopp

static LispObject CC_qqe_rqopp(LispObject env,
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
    v_8 = basic_elt(env, 1); // (qequal qneq)
    v_7 = Lmemq(nil, v_7, v_8);
    return onevalue(v_7);
}



// Code for lto_hashid

static LispObject CC_lto_hashid(LispObject env,
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
    {   LispObject fn = basic_elt(env, 1); // string2list
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    if (!car_legal(v_7)) v_7 = carerror(v_7); else
    v_7 = car(v_7);
    return onevalue(v_7);
}



// Code for noncomfp

static LispObject CC_noncomfp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // !*ncmp
    if (v_14 == nil) goto v_6;
    else goto v_7;
v_6:
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        LispObject fn = basic_elt(env, 2); // noncomfp1
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for delall

static LispObject CC_delall(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    v_31 = stack[0];
    if (v_31 == nil) goto v_10;
    else goto v_11;
v_10:
    v_31 = nil;
    goto v_6;
v_11:
    v_32 = stack[-1];
    v_31 = stack[0];
    if (!car_legal(v_31)) v_31 = carerror(v_31); else
    v_31 = car(v_31);
    if (equal(v_32, v_31)) goto v_14;
    else goto v_15;
v_14:
    v_31 = stack[0];
    if (!car_legal(v_31)) v_31 = cdrerror(v_31); else
    v_31 = cdr(v_31);
    stack[0] = v_31;
    goto v_7;
v_15:
    v_31 = stack[0];
    if (!car_legal(v_31)) v_31 = carerror(v_31); else
    v_31 = car(v_31);
    stack[-2] = ncons(v_31);
    env = stack[-3];
    v_32 = stack[-1];
    v_31 = stack[0];
    if (!car_legal(v_31)) v_31 = cdrerror(v_31); else
    v_31 = cdr(v_31);
    v_31 = CC_delall(basic_elt(env, 0), v_32, v_31);
    {
        LispObject v_36 = stack[-2];
        return Lappend_2(nil, v_36, v_31);
    }
    v_31 = nil;
v_6:
    return onevalue(v_31);
}



// Code for ordop

static LispObject CC_ordop(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_42, v_43, v_44, v_45, v_46;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_45 = v_3;
    v_46 = v_2;
// end of prologue
    v_42 = qvalue(basic_elt(env, 1)); // !*physop!-loaded
    if (v_42 == nil) goto v_8;
    v_42 = v_46;
    v_43 = v_45;
    {
        LispObject fn = basic_elt(env, 3); // physop!-ordop
        return (*qfn2(fn))(fn, v_42, v_43);
    }
v_8:
    v_42 = qvalue(basic_elt(env, 2)); // kord!*
    v_44 = v_42;
v_18:
    v_42 = v_44;
    if (v_42 == nil) goto v_22;
    else goto v_23;
v_22:
    v_42 = v_46;
    v_43 = v_45;
    {
        LispObject fn = basic_elt(env, 4); // ordp
        return (*qfn2(fn))(fn, v_42, v_43);
    }
v_23:
    v_43 = v_46;
    v_42 = v_44;
    if (!car_legal(v_42)) v_42 = carerror(v_42); else
    v_42 = car(v_42);
    if (v_43 == v_42) goto v_28;
    else goto v_29;
v_28:
    v_42 = lisp_true;
    goto v_17;
v_29:
    v_43 = v_45;
    v_42 = v_44;
    if (!car_legal(v_42)) v_42 = carerror(v_42); else
    v_42 = car(v_42);
    if (v_43 == v_42) goto v_34;
    else goto v_35;
v_34:
    v_42 = nil;
    goto v_17;
v_35:
    v_42 = v_44;
    if (!car_legal(v_42)) v_42 = cdrerror(v_42); else
    v_42 = cdr(v_42);
    v_44 = v_42;
    goto v_18;
v_17:
    goto v_6;
    v_42 = nil;
v_6:
    return onevalue(v_42);
}



// Code for prepf

static LispObject CC_prepf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
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
    v_8 = v_2;
// end of prologue
    v_9 = v_8;
    v_8 = nil;
    {   LispObject fn = basic_elt(env, 1); // prepf1a
    v_8 = (*qfn2(fn))(fn, v_9, v_8);
    }
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // replus1
        return (*qfn1(fn))(fn, v_8);
    }
}



// Code for c!:ordxp

static LispObject CC_cTordxp(LispObject env,
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
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_35 = v_3;
    v_36 = v_2;
// end of prologue
    v_37 = v_36;
    v_37 = Lconsp(nil, v_37);
    env = stack[0];
    if (v_37 == nil) goto v_8;
    v_37 = v_35;
    v_37 = Lconsp(nil, v_37);
    if (v_37 == nil) goto v_14;
    if (!car_legal(v_36)) v_36 = cdrerror(v_36); else
    v_36 = cdr(v_36);
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = cdr(v_35);
        return Llessp_2(nil, v_36, v_35);
v_14:
    v_35 = nil;
    goto v_12;
    v_35 = nil;
v_12:
    goto v_6;
v_8:
    v_37 = v_35;
    v_37 = Lconsp(nil, v_37);
    if (v_37 == nil) goto v_26;
    v_35 = lisp_true;
    goto v_6;
v_26:
        return Llessp_2(nil, v_36, v_35);
    v_35 = nil;
v_6:
    return onevalue(v_35);
}



// Code for zero2nil

static LispObject CC_zero2nil(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14;
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
    v_14 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // !:zerop
    v_14 = (*qfn1(fn))(fn, v_14);
    }
    if (v_14 == nil) goto v_7;
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = stack[0];
    goto v_5;
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for ordad

static LispObject CC_ordad(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_49, v_50;
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
v_10:
    v_49 = stack[0];
    if (v_49 == nil) goto v_13;
    v_50 = stack[-1];
    v_49 = stack[0];
    if (!car_legal(v_49)) v_49 = carerror(v_49); else
    v_49 = car(v_49);
    {   LispObject fn = basic_elt(env, 1); // ordp
    v_49 = (*qfn2(fn))(fn, v_50, v_49);
    }
    env = stack[-3];
    if (v_49 == nil) goto v_17;
    else goto v_13;
v_17:
    goto v_14;
v_13:
    goto v_9;
v_14:
    v_49 = stack[0];
    if (!car_legal(v_49)) v_50 = carerror(v_49); else
    v_50 = car(v_49);
    v_49 = stack[-2];
    v_49 = cons(v_50, v_49);
    env = stack[-3];
    stack[-2] = v_49;
    v_49 = stack[0];
    if (!car_legal(v_49)) v_49 = cdrerror(v_49); else
    v_49 = cdr(v_49);
    stack[0] = v_49;
    goto v_10;
v_9:
    v_50 = stack[-1];
    v_49 = stack[0];
    v_49 = cons(v_50, v_49);
    stack[0] = v_49;
v_34:
    v_49 = stack[-2];
    if (v_49 == nil) goto v_37;
    else goto v_38;
v_37:
    goto v_33;
v_38:
    v_49 = stack[-2];
    if (!car_legal(v_49)) v_49 = cdrerror(v_49); else
    v_49 = cdr(v_49);
    stack[-1] = v_49;
    v_50 = stack[-2];
    v_49 = stack[0];
    if (!car_legal(v_50)) rplacd_fails(v_50);
    setcdr(v_50, v_49);
    v_49 = stack[-2];
    stack[0] = v_49;
    v_49 = stack[-1];
    stack[-2] = v_49;
    goto v_34;
v_33:
    v_49 = stack[0];
    return onevalue(v_49);
}



// Code for mval

static LispObject CC_mval(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    return onevalue(v_5);
}



// Code for reval

static LispObject CC_reval(LispObject env,
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
    v_8 = v_7;
    v_7 = lisp_true;
    {
        LispObject fn = basic_elt(env, 1); // reval1
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for evcomp

static LispObject CC_evcomp(LispObject env,
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
    stack[0] = qvalue(basic_elt(env, 1)); // dipsortevcomp!*
    v_10 = list2(v_11, v_10);
    env = stack[-1];
    {
        LispObject v_13 = stack[0];
        LispObject fn = basic_elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_13, v_10);
    }
}



// Code for evmatrixcomp2

static LispObject CC_evmatrixcomp2(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_61, v_62, v_63, v_64;
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
v_1:
    v_61 = stack[-2];
    if (v_61 == nil) goto v_12;
    else goto v_13;
v_12:
    v_61 = lisp_true;
    goto v_11;
v_13:
    v_61 = stack[-1];
    v_61 = (v_61 == nil ? lisp_true : nil);
    goto v_11;
    v_61 = nil;
v_11:
    if (v_61 == nil) goto v_9;
    v_61 = stack[0];
    goto v_7;
v_9:
    v_61 = stack[-1];
    if (!car_legal(v_61)) v_61 = carerror(v_61); else
    v_61 = car(v_61);
    stack[-3] = v_61;
    v_62 = stack[-3];
    v_61 = (LispObject)0+TAG_FIXNUM; // 0
    {   LispObject fn = basic_elt(env, 1); // iequal
    v_61 = (*qfn2(fn))(fn, v_62, v_61);
    }
    env = stack[-4];
    if (v_61 == nil) goto v_29;
    v_61 = stack[-2];
    if (!car_legal(v_61)) v_63 = cdrerror(v_61); else
    v_63 = cdr(v_61);
    v_61 = stack[-1];
    if (!car_legal(v_61)) v_62 = cdrerror(v_61); else
    v_62 = cdr(v_61);
    v_61 = stack[0];
    stack[-2] = v_63;
    stack[-1] = v_62;
    stack[0] = v_61;
    goto v_1;
v_29:
    v_62 = stack[-3];
    v_61 = (LispObject)16+TAG_FIXNUM; // 1
    {   LispObject fn = basic_elt(env, 1); // iequal
    v_61 = (*qfn2(fn))(fn, v_62, v_61);
    }
    env = stack[-4];
    if (v_61 == nil) goto v_40;
    v_61 = stack[-2];
    if (!car_legal(v_61)) v_64 = cdrerror(v_61); else
    v_64 = cdr(v_61);
    v_61 = stack[-1];
    if (!car_legal(v_61)) v_63 = cdrerror(v_61); else
    v_63 = cdr(v_61);
    v_62 = stack[0];
    v_61 = stack[-2];
    if (!car_legal(v_61)) v_61 = carerror(v_61); else
    v_61 = car(v_61);
    v_61 = (LispObject)(std::intptr_t)((std::intptr_t)v_62 + (std::intptr_t)v_61 - TAG_FIXNUM);
    stack[-2] = v_64;
    stack[-1] = v_63;
    stack[0] = v_61;
    goto v_1;
v_40:
    v_61 = stack[0];
    v_61 = ncons(v_61);
    env = stack[-4];
    {
        LispObject v_69 = stack[-2];
        LispObject v_70 = stack[-3];
        LispObject v_71 = stack[-1];
        LispObject fn = basic_elt(env, 2); // evmatrixcomp3
        return (*qfn4up(fn))(fn, v_69, v_70, v_71, v_61);
    }
    v_61 = nil;
    goto v_7;
    v_61 = nil;
v_7:
    return onevalue(v_61);
}



// Code for xval

static LispObject CC_xval(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    if (!car_legal(v_8)) v_8 = carerror(v_8); else
    v_8 = car(v_8);
    if (!car_legal(v_8)) v_8 = carerror(v_8); else
    v_8 = car(v_8);
    {
        LispObject fn = basic_elt(env, 1); // wedgefax
        return (*qfn1(fn))(fn, v_8);
    }
}



// Code for times!:

static LispObject CC_timesT(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    stack[-3] = basic_elt(env, 1); // !:rd!:
    v_21 = stack[-2];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    if (!car_legal(v_21)) v_22 = carerror(v_21); else
    v_22 = car(v_21);
    v_21 = stack[-1];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    if (!car_legal(v_21)) v_21 = carerror(v_21); else
    v_21 = car(v_21);
    stack[0] = times2(v_22, v_21);
    env = stack[-4];
    v_21 = stack[-2];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    if (!car_legal(v_21)) v_22 = cdrerror(v_21); else
    v_22 = cdr(v_21);
    v_21 = stack[-1];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    v_21 = plus2(v_22, v_21);
    {
        LispObject v_27 = stack[-3];
        LispObject v_28 = stack[0];
        return list2star(v_27, v_28, v_21);
    }
}



// Code for convprec

static LispObject CC_convprec(LispObject env,
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
    {   LispObject fn = basic_elt(env, 1); // round!*
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // convchk
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for mkvar

static LispObject CC_mkvar(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_6, v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6 = v_3;
    v_7 = v_2;
// end of prologue
    v_6 = v_7;
    return onevalue(v_6);
}



// Code for physopp

static LispObject CC_physopp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_37, v_38;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_38 = v_2;
// end of prologue
    v_37 = v_38;
    if (!consp(v_37)) goto v_6;
    else goto v_7;
v_6:
    v_37 = v_38;
    if (symbolp(v_37)) goto v_12;
    v_37 = nil;
    goto v_10;
v_12:
    v_37 = v_38;
    if (!symbolp(v_37)) v_37 = nil;
    else { v_37 = qfastgets(v_37);
           if (v_37 != nil) { v_37 = elt(v_37, 2); // rtype
#ifdef RECORD_GET
             if (v_37 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_37 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_37 == SPID_NOPROP) v_37 = nil; }}
#endif
    v_38 = basic_elt(env, 1); // physop
    v_37 = (v_37 == v_38 ? lisp_true : nil);
    goto v_10;
    v_37 = nil;
v_10:
    goto v_5;
v_7:
    v_37 = v_38;
    if (!car_legal(v_37)) v_37 = carerror(v_37); else
    v_37 = car(v_37);
    if (symbolp(v_37)) goto v_26;
    v_37 = nil;
    goto v_24;
v_26:
    v_37 = v_38;
    if (!car_legal(v_37)) v_37 = carerror(v_37); else
    v_37 = car(v_37);
    if (!symbolp(v_37)) v_37 = nil;
    else { v_37 = qfastgets(v_37);
           if (v_37 != nil) { v_37 = elt(v_37, 2); // rtype
#ifdef RECORD_GET
             if (v_37 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_37 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_37 == SPID_NOPROP) v_37 = nil; }}
#endif
    v_38 = basic_elt(env, 1); // physop
    v_37 = (v_37 == v_38 ? lisp_true : nil);
    goto v_24;
    v_37 = nil;
v_24:
    goto v_5;
    v_37 = nil;
v_5:
    return onevalue(v_37);
}



// Code for memq_edgelist

static LispObject CC_memq_edgelist(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_3;
    v_10 = v_2;
// end of prologue
    if (!car_legal(v_10)) v_10 = carerror(v_10); else
    v_10 = car(v_10);
    v_9 = Lassoc(nil, v_10, v_9);
    return onevalue(v_9);
}



// Code for mo_comp

static LispObject CC_mo_comp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_16, v_17;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_16 = v_2;
// end of prologue
    v_17 = v_16;
    if (!car_legal(v_17)) v_17 = carerror(v_17); else
    v_17 = car(v_17);
    if (v_17 == nil) goto v_6;
    else goto v_7;
v_6:
    v_16 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_5;
v_7:
    if (!car_legal(v_16)) v_16 = carerror(v_16); else
    v_16 = car(v_16);
    if (!car_legal(v_16)) v_16 = carerror(v_16); else
    v_16 = car(v_16);
    goto v_5;
    v_16 = nil;
v_5:
    return onevalue(v_16);
}



// Code for c_zero

static LispObject CC_c_zero(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_4;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_4 = nil;
    return onevalue(v_4);
}



// Code for sieve_pv0

static LispObject CC_sieve_pv0(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
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
    v_56 = stack[-2];
    if (v_56 == nil) goto v_8;
    else goto v_9;
v_8:
    v_56 = nil;
    goto v_7;
v_9:
v_16:
    v_56 = stack[-1];
    if (v_56 == nil) goto v_19;
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = car(v_56);
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = car(v_56);
    if (!car_legal(v_56)) v_57 = cdrerror(v_56); else
    v_57 = cdr(v_56);
    v_56 = stack[-2];
    if (!car_legal(v_56)) v_56 = carerror(v_56); else
    v_56 = car(v_56);
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = cdr(v_56);
    v_56 = (LispObject)greaterp2(v_57, v_56);
    v_56 = v_56 ? lisp_true : nil;
    env = stack[-3];
    if (v_56 == nil) goto v_19;
    goto v_20;
v_19:
    goto v_15;
v_20:
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = cdr(v_56);
    stack[-1] = v_56;
    goto v_16;
v_15:
v_37:
    v_56 = stack[-2];
    if (v_56 == nil) goto v_40;
    v_56 = stack[-1];
    if (v_56 == nil) goto v_40;
    goto v_41;
v_40:
    goto v_36;
v_41:
    v_58 = stack[-2];
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_57 = carerror(v_56); else
    v_57 = car(v_56);
    v_56 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // reduce_pv0
    v_56 = (*qfn3(fn))(fn, v_58, v_57, v_56);
    }
    env = stack[-3];
    stack[-2] = v_56;
    v_56 = stack[-1];
    if (!car_legal(v_56)) v_56 = cdrerror(v_56); else
    v_56 = cdr(v_56);
    stack[-1] = v_56;
    goto v_37;
v_36:
    v_56 = stack[-2];
    goto v_7;
    v_56 = nil;
v_7:
    return onevalue(v_56);
}



// Code for listp

static LispObject CC_listp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_23, v_24;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_23 = v_2;
// end of prologue
v_1:
    v_24 = v_23;
    if (v_24 == nil) goto v_6;
    else goto v_7;
v_6:
    v_23 = lisp_true;
    goto v_5;
v_7:
    v_24 = v_23;
    if (!consp(v_24)) goto v_15;
    if (!car_legal(v_23)) v_23 = cdrerror(v_23); else
    v_23 = cdr(v_23);
    goto v_1;
v_15:
    v_23 = nil;
    goto v_13;
    v_23 = nil;
v_13:
    goto v_5;
    v_23 = nil;
v_5:
    return onevalue(v_23);
}



// Code for modzerop!:

static LispObject CC_modzeropT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    if (!car_legal(v_8)) v_9 = cdrerror(v_8); else
    v_9 = cdr(v_8);
    v_8 = (LispObject)0+TAG_FIXNUM; // 0
    v_8 = (v_9 == v_8 ? lisp_true : nil);
    return onevalue(v_8);
}



// Code for getrtypeor

static LispObject CC_getrtypeor(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21;
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
    v_21 = stack[0];
    if (v_21 == nil) goto v_6;
    else goto v_7;
v_6:
    v_21 = nil;
    goto v_5;
v_7:
    v_21 = stack[0];
    if (!car_legal(v_21)) v_21 = carerror(v_21); else
    v_21 = car(v_21);
    {   LispObject fn = basic_elt(env, 1); // getrtype
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-1];
    if (v_21 == nil) goto v_14;
    else goto v_13;
v_14:
    v_21 = stack[0];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    stack[0] = v_21;
    goto v_1;
v_13:
    goto v_5;
    v_21 = nil;
v_5:
    return onevalue(v_21);
}



// Code for lalr_productions

static LispObject CC_lalr_productions(LispObject env,
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
    v_8 = basic_elt(env, 1); // lalr_produces
    return get(v_7, v_8);
}



// Code for random_new_seed

static LispObject CC_random_new_seed(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_137, v_138, v_139;
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
    stack[0] = v_2;
// end of prologue
    v_137 = stack[0];
    v_137 = integerp(v_137);
    if (v_137 == nil) goto v_16;
    else goto v_17;
v_16:
    v_137 = lisp_true;
    goto v_15;
v_17:
    v_138 = stack[0];
    v_137 = (LispObject)0+TAG_FIXNUM; // 0
    v_137 = (LispObject)lesseq2(v_138, v_137);
    v_137 = v_137 ? lisp_true : nil;
    env = stack[-4];
    goto v_15;
    v_137 = nil;
v_15:
    if (v_137 == nil) goto v_13;
    v_138 = stack[0];
    v_137 = basic_elt(env, 1); // "positive integer"
    {   LispObject fn = basic_elt(env, 6); // typerr
    v_137 = (*qfn2(fn))(fn, v_138, v_137);
    }
    env = stack[-4];
    goto v_11;
v_13:
v_11:
    v_138 = stack[0];
    v_137 = qvalue(basic_elt(env, 2)); // randommodulus!*
    v_137 = Cremainder(v_138, v_137);
    env = stack[-4];
    stack[-3] = v_137;
    v_139 = qvalue(basic_elt(env, 3)); // unidev_vec!*
    v_138 = (LispObject)864+TAG_FIXNUM; // 54
    v_137 = stack[-3];
    v_137 = Lputv(nil, v_139, v_138, v_137);
    env = stack[-4];
    v_137 = stack[-3];
    v_137 = add1(v_137);
    env = stack[-4];
    stack[-2] = v_137;
    v_137 = (LispObject)16+TAG_FIXNUM; // 1
    stack[0] = v_137;
v_41:
    v_138 = (LispObject)864+TAG_FIXNUM; // 54
    v_137 = stack[0];
    v_137 = difference2(v_138, v_137);
    env = stack[-4];
    v_137 = Lminusp(nil, v_137);
    env = stack[-4];
    if (v_137 == nil) goto v_46;
    goto v_40;
v_46:
    v_138 = stack[-2];
    v_137 = stack[-3];
    v_137 = (LispObject)(std::intptr_t)((std::intptr_t)v_138 - (std::intptr_t)v_137 + TAG_FIXNUM);
    stack[-1] = v_137;
    v_137 = stack[-1];
    v_137 = ((std::intptr_t)(v_137) < 0 ? lisp_true : nil);
    if (v_137 == nil) goto v_58;
    v_138 = stack[-1];
    v_137 = qvalue(basic_elt(env, 2)); // randommodulus!*
    v_137 = (LispObject)(std::intptr_t)((std::intptr_t)v_138 + (std::intptr_t)v_137 - TAG_FIXNUM);
    stack[-1] = v_137;
    goto v_56;
v_58:
v_56:
    v_138 = (LispObject)336+TAG_FIXNUM; // 21
    v_137 = stack[0];
    v_138 = times2(v_138, v_137);
    env = stack[-4];
    v_137 = (LispObject)880+TAG_FIXNUM; // 55
    v_137 = Cremainder(v_138, v_137);
    env = stack[-4];
    v_139 = qvalue(basic_elt(env, 3)); // unidev_vec!*
    v_138 = (LispObject)((std::intptr_t)(v_137) - 0x10);
    v_137 = stack[-1];
    v_137 = Lputv(nil, v_139, v_138, v_137);
    env = stack[-4];
    v_137 = stack[-3];
    stack[-2] = v_137;
    v_137 = stack[-1];
    stack[-3] = v_137;
    v_137 = stack[0];
    v_137 = add1(v_137);
    env = stack[-4];
    stack[0] = v_137;
    goto v_41;
v_40:
    v_137 = (LispObject)16+TAG_FIXNUM; // 1
    stack[-3] = v_137;
v_81:
    v_138 = (LispObject)64+TAG_FIXNUM; // 4
    v_137 = stack[-3];
    v_137 = difference2(v_138, v_137);
    env = stack[-4];
    v_137 = Lminusp(nil, v_137);
    env = stack[-4];
    if (v_137 == nil) goto v_86;
    goto v_80;
v_86:
    v_137 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-2] = v_137;
v_95:
    v_138 = (LispObject)864+TAG_FIXNUM; // 54
    v_137 = stack[-2];
    v_137 = difference2(v_138, v_137);
    env = stack[-4];
    v_137 = Lminusp(nil, v_137);
    env = stack[-4];
    if (v_137 == nil) goto v_100;
    goto v_94;
v_100:
    v_138 = qvalue(basic_elt(env, 3)); // unidev_vec!*
    v_137 = stack[-2];
    stack[-1] = Lgetv(nil, v_138, v_137);
    env = stack[-4];
    stack[0] = qvalue(basic_elt(env, 3)); // unidev_vec!*
    v_138 = stack[-2];
    v_137 = (LispObject)496+TAG_FIXNUM; // 31
    v_138 = (LispObject)(std::intptr_t)((std::intptr_t)v_138 + (std::intptr_t)v_137 - TAG_FIXNUM);
    v_137 = (LispObject)880+TAG_FIXNUM; // 55
    v_137 = Cremainder(v_138, v_137);
    env = stack[-4];
    v_137 = Lgetv(nil, stack[0], v_137);
    env = stack[-4];
    v_137 = (LispObject)(std::intptr_t)((std::intptr_t)stack[-1] - (std::intptr_t)v_137 + TAG_FIXNUM);
    stack[-1] = v_137;
    v_137 = stack[-1];
    v_137 = ((std::intptr_t)(v_137) < 0 ? lisp_true : nil);
    if (v_137 == nil) goto v_120;
    v_138 = stack[-1];
    v_137 = qvalue(basic_elt(env, 2)); // randommodulus!*
    v_137 = (LispObject)(std::intptr_t)((std::intptr_t)v_138 + (std::intptr_t)v_137 - TAG_FIXNUM);
    stack[-1] = v_137;
    goto v_118;
v_120:
v_118:
    v_139 = qvalue(basic_elt(env, 3)); // unidev_vec!*
    v_138 = stack[-2];
    v_137 = stack[-1];
    v_137 = Lputv(nil, v_139, v_138, v_137);
    env = stack[-4];
    v_137 = stack[-2];
    v_137 = add1(v_137);
    env = stack[-4];
    stack[-2] = v_137;
    goto v_95;
v_94:
    v_137 = stack[-3];
    v_137 = add1(v_137);
    env = stack[-4];
    stack[-3] = v_137;
    goto v_81;
v_80:
    v_137 = (LispObject)0+TAG_FIXNUM; // 0
    setvalue(basic_elt(env, 4), v_137); // unidev_next!*
    v_137 = (LispObject)496+TAG_FIXNUM; // 31
    setvalue(basic_elt(env, 5), v_137); // unidev_nextp!*
    v_137 = nil;
    return onevalue(v_137);
}



// Code for monomcompare

static LispObject CC_monomcompare(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_31, v_32, v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33 = v_3;
    v_34 = v_2;
// end of prologue
    v_32 = qvalue(basic_elt(env, 1)); // fluidbibasismonomialorder
    v_31 = basic_elt(env, 2); // lex
    if (v_32 == v_31) goto v_9;
    else goto v_10;
v_9:
    v_31 = v_34;
    v_32 = v_33;
    {
        LispObject fn = basic_elt(env, 4); // monomcomparelex
        return (*qfn2(fn))(fn, v_31, v_32);
    }
v_10:
    v_32 = qvalue(basic_elt(env, 1)); // fluidbibasismonomialorder
    v_31 = basic_elt(env, 3); // deglex
    if (v_32 == v_31) goto v_17;
    else goto v_18;
v_17:
    v_31 = v_34;
    v_32 = v_33;
    {
        LispObject fn = basic_elt(env, 5); // monomcomparedeglex
        return (*qfn2(fn))(fn, v_31, v_32);
    }
v_18:
    v_31 = v_34;
    v_32 = v_33;
    {
        LispObject fn = basic_elt(env, 6); // monomcomparedegrevlex
        return (*qfn2(fn))(fn, v_31, v_32);
    }
    v_31 = nil;
    return onevalue(v_31);
}



// Code for makelist

static LispObject CC_makelist(LispObject env,
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
    v_8 = basic_elt(env, 1); // list
    return cons(v_8, v_7);
}



// Code for quotf

static LispObject CC_quotf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_12, v_13, v_14;
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
    v_13 = v_3;
    v_14 = v_2;
// end of prologue
    v_12 = lisp_true;
// Binding !*exp
// FLUIDBIND: reloadenv=1 litvec-offset=1 saveloc=0
{   bind_fluid_stack bind_fluid_var(-1, 1, 0);
    setvalue(basic_elt(env, 1), v_12); // !*exp
    v_12 = v_14;
    {   LispObject fn = basic_elt(env, 2); // quotf1
    v_12 = (*qfn2(fn))(fn, v_12, v_13);
    }
    ;}  // end of a binding scope
    return onevalue(v_12);
}



// Code for mchk!*

static LispObject CC_mchkH(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    v_36 = stack[-1];
    v_35 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // mchk
    v_35 = (*qfn2(fn))(fn, v_36, v_35);
    }
    env = stack[-2];
    v_36 = v_35;
    if (v_35 == nil) goto v_11;
    v_35 = v_36;
    goto v_7;
v_11:
    v_35 = qvalue(basic_elt(env, 1)); // !*mcd
    if (v_35 == nil) goto v_18;
    else goto v_16;
v_18:
    v_35 = stack[-1];
    {   LispObject fn = basic_elt(env, 3); // sfp
    v_35 = (*qfn1(fn))(fn, v_35);
    }
    env = stack[-2];
    if (v_35 == nil) goto v_16;
    v_35 = stack[0];
    {   LispObject fn = basic_elt(env, 3); // sfp
    v_35 = (*qfn1(fn))(fn, v_35);
    }
    env = stack[-2];
    if (v_35 == nil) goto v_16;
    goto v_17;
v_16:
    v_35 = nil;
    goto v_7;
v_17:
    v_35 = stack[-1];
    {   LispObject fn = basic_elt(env, 4); // prepf
    stack[-1] = (*qfn1(fn))(fn, v_35);
    }
    env = stack[-2];
    v_35 = stack[0];
    {   LispObject fn = basic_elt(env, 4); // prepf
    v_35 = (*qfn1(fn))(fn, v_35);
    }
    env = stack[-2];
    {
        LispObject v_39 = stack[-1];
        LispObject fn = basic_elt(env, 2); // mchk
        return (*qfn2(fn))(fn, v_39, v_35);
    }
    v_35 = nil;
v_7:
    return onevalue(v_35);
}



// Code for get!+mat!+entry

static LispObject CC_getLmatLentry(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
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
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    stack[0] = v_4;
    v_13 = v_3;
    v_14 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // nth
    v_14 = (*qfn2(fn))(fn, v_14, v_13);
    }
    env = stack[-1];
    v_13 = stack[0];
    {
        LispObject fn = basic_elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_14, v_13);
    }
    return onevalue(v_13);
}



// Code for talp_getextl

static LispObject CC_talp_getextl(LispObject env)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_4;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v_4 = qvalue(basic_elt(env, 1)); // talp_extlang!*
    return onevalue(v_4);
}



// Code for powers

static LispObject CC_powers(LispObject env,
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
    v_8 = v_7;
    v_7 = nil;
    {
        LispObject fn = basic_elt(env, 1); // powers0
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for ibalp_clmember

static LispObject CC_ibalp_clmember(LispObject env,
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
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
v_1:
    v_24 = stack[0];
    if (v_24 == nil) goto v_7;
    else goto v_8;
v_7:
    v_24 = nil;
    goto v_6;
v_8:
    v_25 = stack[-1];
    v_24 = stack[0];
    if (!car_legal(v_24)) v_24 = carerror(v_24); else
    v_24 = car(v_24);
    {   LispObject fn = basic_elt(env, 1); // ibalp_cequal
    v_24 = (*qfn2(fn))(fn, v_25, v_24);
    }
    env = stack[-2];
    if (v_24 == nil) goto v_15;
    else goto v_14;
v_15:
    v_25 = stack[-1];
    v_24 = stack[0];
    if (!car_legal(v_24)) v_24 = cdrerror(v_24); else
    v_24 = cdr(v_24);
    stack[-1] = v_25;
    stack[0] = v_24;
    goto v_1;
v_14:
    goto v_6;
    v_24 = nil;
v_6:
    return onevalue(v_24);
}



// Code for find2

static LispObject CC_find2(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_32, v_33, v_34, v_35;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33 = v_3;
    v_34 = v_2;
// end of prologue
v_1:
    v_35 = v_33;
    v_32 = nil;
    if (v_35 == v_32) goto v_9;
    else goto v_10;
v_9:
    v_32 = v_34;
    if (v_32 == nil) goto v_16;
    v_32 = v_34;
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    goto v_14;
v_16:
    v_32 = basic_elt(env, 1); // (stop)
    goto v_14;
    v_32 = nil;
v_14:
    goto v_8;
v_10:
    v_32 = v_33;
    if (!car_legal(v_32)) v_32 = carerror(v_32); else
    v_32 = car(v_32);
    v_34 = Lmember(nil, v_32, v_34);
    v_32 = v_33;
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    v_33 = v_32;
    goto v_1;
    v_32 = nil;
v_8:
    return onevalue(v_32);
}



// Code for noncomp

static LispObject CC_noncomp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // !*ncmp
    if (v_14 == nil) goto v_6;
    else goto v_7;
v_6:
    v_14 = nil;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        LispObject fn = basic_elt(env, 2); // noncomp1
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for prepf1a

static LispObject CC_prepf1a(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_10, v_11, v_12;
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
    stack_popper stack_popper_var(1);
// copy arguments values to proper place
    v_10 = v_3;
    v_11 = v_2;
// end of prologue
    v_12 = v_11;
    v_11 = v_10;
    v_10 = nil;
    {   LispObject fn = basic_elt(env, 1); // prepf1a_reversed
    v_10 = (*qfn3(fn))(fn, v_12, v_11, v_10);
    }
        return Lnreverse(nil, v_10);
}



// Code for subs3f

static LispObject CC_subs3f(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    v_10 = v_8;
    v_9 = qvalue(basic_elt(env, 1)); // !*match
    v_8 = lisp_true;
    {
        LispObject fn = basic_elt(env, 2); // subs3f1
        return (*qfn3(fn))(fn, v_10, v_9, v_8);
    }
}



// Code for pm!:free

static LispObject CC_pmTfree(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
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
    v_8 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 2); // binding
    v_8 = (*qfn1(fn))(fn, v_8);
    }
    env = stack[0];
    v_9 = basic_elt(env, 1); // unbound
    v_8 = (v_8 == v_9 ? lisp_true : nil);
    return onevalue(v_8);
}



// Code for vbcsize

static LispObject CC_vbcsize(LispObject env,
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
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_36 = v_3;
    stack[0] = v_2;
// end of prologue
v_1:
    v_37 = v_36;
    v_35 = (LispObject)-16+TAG_FIXNUM; // -1
    if (((std::intptr_t)(v_37)) > ((std::intptr_t)(v_35))) goto v_7;
    else goto v_8;
v_7:
    v_35 = nil;
    goto v_6;
v_8:
    v_35 = stack[0];
    if (!consp(v_35)) goto v_12;
    else goto v_13;
v_12:
    v_35 = v_36;
    goto v_6;
v_13:
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = car(v_35);
    v_36 = (LispObject)((std::intptr_t)(v_36) + 0x10);
    v_35 = CC_vbcsize(basic_elt(env, 0), v_35, v_36);
    env = stack[-1];
    v_36 = v_35;
    v_35 = v_36;
    if (v_35 == nil) goto v_27;
    else goto v_28;
v_27:
    v_35 = nil;
    goto v_19;
v_28:
    v_35 = stack[0];
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = cdr(v_35);
    stack[0] = v_35;
    goto v_1;
v_19:
    goto v_6;
    v_35 = nil;
v_6:
    return onevalue(v_35);
}



// Code for pnth

static LispObject CC_pnth(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_28, v_29, v_30;
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
    v_29 = v_3;
    stack[0] = v_2;
// end of prologue
v_7:
    v_28 = stack[0];
    if (v_28 == nil) goto v_10;
    else goto v_11;
v_10:
    v_30 = basic_elt(env, 1); // alg
    v_29 = (LispObject)96+TAG_FIXNUM; // 6
    v_28 = basic_elt(env, 2); // "Index out of range"
    {
        LispObject fn = basic_elt(env, 3); // rerror
        return (*qfn3(fn))(fn, v_30, v_29, v_28);
    }
v_11:
    v_30 = v_29;
    v_28 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_30 == v_28) goto v_17;
    else goto v_18;
v_17:
    v_28 = stack[0];
    goto v_6;
v_18:
    v_28 = stack[0];
    if (!car_legal(v_28)) v_28 = cdrerror(v_28); else
    v_28 = cdr(v_28);
    stack[0] = v_28;
    v_28 = v_29;
    v_28 = sub1(v_28);
    env = stack[-1];
    v_29 = v_28;
    goto v_7;
    v_28 = nil;
v_6:
    return onevalue(v_28);
}



// Code for wedgefax

static LispObject CC_wedgefax(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_17, v_18, v_19;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_18 = v_2;
// end of prologue
    v_17 = v_18;
    v_19 = basic_elt(env, 1); // wedge
    if (!consp(v_17)) goto v_7;
    v_17 = car(v_17);
    if (v_17 == v_19) goto v_6;
    else goto v_7;
v_6:
    v_17 = v_18;
    if (!car_legal(v_17)) v_17 = cdrerror(v_17); else
    v_17 = cdr(v_17);
    goto v_5;
v_7:
    v_17 = v_18;
    return ncons(v_17);
    v_17 = nil;
v_5:
    return onevalue(v_17);
}



// Code for !*physopp

static LispObject CC_Hphysopp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33 = v_2;
// end of prologue
    v_34 = v_33;
    if (!consp(v_34)) goto v_6;
    else goto v_7;
v_6:
    v_34 = v_33;
    if (symbolp(v_34)) goto v_12;
    v_33 = nil;
    goto v_10;
v_12:
    if (!symbolp(v_33)) v_33 = nil;
    else { v_33 = qfastgets(v_33);
           if (v_33 != nil) { v_33 = elt(v_33, 18); // phystype
#ifdef RECORD_GET
             if (v_33 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_33 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_33 == SPID_NOPROP) v_33 = nil; }}
#endif
    goto v_10;
    v_33 = nil;
v_10:
    goto v_5;
v_7:
    v_34 = v_33;
    if (!car_legal(v_34)) v_34 = carerror(v_34); else
    v_34 = car(v_34);
    if (symbolp(v_34)) goto v_24;
    v_33 = nil;
    goto v_22;
v_24:
    if (!car_legal(v_33)) v_33 = carerror(v_33); else
    v_33 = car(v_33);
    if (!symbolp(v_33)) v_33 = nil;
    else { v_33 = qfastgets(v_33);
           if (v_33 != nil) { v_33 = elt(v_33, 18); // phystype
#ifdef RECORD_GET
             if (v_33 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v_33 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v_33 == SPID_NOPROP) v_33 = nil; }}
#endif
    goto v_22;
    v_33 = nil;
v_22:
    goto v_5;
    v_33 = nil;
v_5:
    return onevalue(v_33);
}



// Code for argsofopr

static LispObject CC_argsofopr(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_6;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_6 = v_2;
// end of prologue
    if (!symbolp(v_6)) v_6 = nil;
    else { v_6 = qfastgets(v_6);
           if (v_6 != nil) { v_6 = elt(v_6, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v_6 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v_6 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v_6 == SPID_NOPROP) v_6 = nil; }}
#endif
    return onevalue(v_6);
}



// Code for wideid2list

static LispObject CC_wideid2list(LispObject env,
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
    {   LispObject fn = basic_elt(env, 1); // id2string
    v_7 = (*qfn1(fn))(fn, v_7);
    }
    env = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // widestring2list
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for termsf

static LispObject CC_termsf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_45, v_46;
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
    v_45 = (LispObject)0+TAG_FIXNUM; // 0
    v_46 = v_45;
v_10:
    v_45 = stack[0];
    if (!consp(v_45)) goto v_17;
    else goto v_18;
v_17:
    v_45 = lisp_true;
    goto v_16;
v_18:
    v_45 = stack[0];
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = car(v_45);
    v_45 = (consp(v_45) ? nil : lisp_true);
    goto v_16;
    v_45 = nil;
v_16:
    if (v_45 == nil) goto v_14;
    goto v_9;
v_14:
    stack[-1] = v_46;
    v_45 = stack[0];
    if (!car_legal(v_45)) v_45 = carerror(v_45); else
    v_45 = car(v_45);
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = cdr(v_45);
    v_45 = CC_termsf(basic_elt(env, 0), v_45);
    env = stack[-2];
    v_45 = plus2(stack[-1], v_45);
    env = stack[-2];
    v_46 = v_45;
    v_45 = stack[0];
    if (!car_legal(v_45)) v_45 = cdrerror(v_45); else
    v_45 = cdr(v_45);
    stack[0] = v_45;
    goto v_10;
v_9:
    v_45 = stack[0];
    if (v_45 == nil) goto v_37;
    else goto v_38;
v_37:
    v_45 = v_46;
    goto v_36;
v_38:
    v_45 = v_46;
    return add1(v_45);
    v_45 = nil;
v_36:
    return onevalue(v_45);
}



// Code for mkspm

static LispObject CC_mkspm(LispObject env,
                         LispObject v_2, LispObject v_3)
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
    v_40 = stack[0];
    v_39 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_40 == v_39) goto v_7;
    else goto v_8;
v_7:
    v_39 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6;
v_8:
    v_39 = qvalue(basic_elt(env, 1)); // subfg!*
    if (v_39 == nil) goto v_20;
    v_40 = stack[-1];
    v_39 = qvalue(basic_elt(env, 2)); // asymplis!*
    v_39 = Latsoc(nil, v_40, v_39);
    v_40 = v_39;
    if (v_39 == nil) goto v_20;
    v_39 = v_40;
    if (!car_legal(v_39)) v_40 = cdrerror(v_39); else
    v_40 = cdr(v_39);
    v_39 = stack[0];
    v_39 = (LispObject)lesseq2(v_40, v_39);
    v_39 = v_39 ? lisp_true : nil;
    env = stack[-2];
    if (v_39 == nil) goto v_20;
    v_39 = nil;
    goto v_16;
v_20:
    v_39 = stack[-1];
    {   LispObject fn = basic_elt(env, 3); // sub2chk
    v_39 = (*qfn1(fn))(fn, v_39);
    }
    env = stack[-2];
    v_40 = stack[-1];
    v_39 = stack[0];
    {
        LispObject fn = basic_elt(env, 4); // to
        return (*qfn2(fn))(fn, v_40, v_39);
    }
v_16:
    goto v_6;
    v_39 = nil;
v_6:
    return onevalue(v_39);
}



// Code for dssoc

static LispObject CC_dssoc(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_26, v_27, v_28, v_29;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_27 = v_3;
    v_28 = v_2;
// end of prologue
v_7:
    v_26 = v_27;
    if (v_26 == nil) goto v_10;
    else goto v_11;
v_10:
    v_26 = nil;
    goto v_6;
v_11:
    v_29 = v_28;
    v_26 = v_27;
    if (!car_legal(v_26)) v_26 = carerror(v_26); else
    v_26 = car(v_26);
    if (!car_legal(v_26)) v_26 = cdrerror(v_26); else
    v_26 = cdr(v_26);
    if (equal(v_29, v_26)) goto v_14;
    else goto v_15;
v_14:
    v_26 = v_27;
    if (!car_legal(v_26)) v_26 = carerror(v_26); else
    v_26 = car(v_26);
    goto v_6;
v_15:
    v_26 = v_27;
    if (!car_legal(v_26)) v_26 = cdrerror(v_26); else
    v_26 = cdr(v_26);
    v_27 = v_26;
    goto v_7;
    v_26 = nil;
v_6:
    return onevalue(v_26);
}



// Code for noncomlistp

static LispObject CC_noncomlistp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_22;
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
    v_22 = stack[0];
    v_22 = Lconsp(nil, v_22);
    env = stack[-1];
    if (v_22 == nil) goto v_6;
    else goto v_7;
v_6:
    v_22 = nil;
    goto v_5;
v_7:
    v_22 = stack[0];
    if (!car_legal(v_22)) v_22 = carerror(v_22); else
    v_22 = car(v_22);
    {   LispObject fn = basic_elt(env, 1); // noncomp1
    v_22 = (*qfn1(fn))(fn, v_22);
    }
    env = stack[-1];
    if (v_22 == nil) goto v_15;
    else goto v_14;
v_15:
    v_22 = stack[0];
    if (!car_legal(v_22)) v_22 = cdrerror(v_22); else
    v_22 = cdr(v_22);
    stack[0] = v_22;
    goto v_1;
v_14:
    goto v_5;
    v_22 = nil;
v_5:
    return onevalue(v_22);
}



// Code for rnzerop!:

static LispObject CC_rnzeropT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_2;
// end of prologue
    if (!car_legal(v_9)) v_9 = cdrerror(v_9); else
    v_9 = cdr(v_9);
    if (!car_legal(v_9)) v_10 = carerror(v_9); else
    v_10 = car(v_9);
    v_9 = (LispObject)0+TAG_FIXNUM; // 0
    v_9 = (v_10 == v_9 ? lisp_true : nil);
    return onevalue(v_9);
}



// Code for mksp

static LispObject CC_mksp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_9, v_10;
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
    v_9 = v_2;
// end of prologue
    {   LispObject fn = basic_elt(env, 1); // fkern
    v_10 = (*qfn1(fn))(fn, v_9);
    }
    env = stack[-1];
    v_9 = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // getpower
        return (*qfn2(fn))(fn, v_10, v_9);
    }
}



// Code for aeval

static LispObject CC_aeval(LispObject env,
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
    v_8 = v_7;
    v_7 = nil;
    {
        LispObject fn = basic_elt(env, 1); // reval1
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for lalr_first

static LispObject CC_lalr_first(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_64, v_65, v_66;
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
    stack[0] = nil;
v_10:
    v_64 = stack[-1];
    if (v_64 == nil) goto v_13;
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    if (is_number(v_64)) goto v_21;
    v_66 = nil;
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_65 = carerror(v_64); else
    v_65 = car(v_64);
    v_64 = basic_elt(env, 0); // lalr_first
    v_64 = get(v_65, v_64);
    env = stack[-3];
    stack[0] = v_64;
    v_64 = Lmember(nil, v_66, v_64);
    goto v_19;
v_21:
    v_64 = nil;
    goto v_19;
    v_64 = nil;
v_19:
    if (v_64 == nil) goto v_13;
    goto v_14;
v_13:
    goto v_9;
v_14:
    v_65 = nil;
    v_64 = stack[0];
    v_65 = Ldeleq(nil, v_65, v_64);
    env = stack[-3];
    v_64 = stack[-2];
    {   LispObject fn = basic_elt(env, 1); // union
    v_64 = (*qfn2(fn))(fn, v_65, v_64);
    }
    env = stack[-3];
    stack[-2] = v_64;
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = cdrerror(v_64); else
    v_64 = cdr(v_64);
    stack[-1] = v_64;
    goto v_10;
v_9:
    v_64 = stack[-1];
    if (v_64 == nil) goto v_43;
    else goto v_44;
v_43:
    v_65 = nil;
    v_64 = stack[-2];
    v_64 = cons(v_65, v_64);
    stack[-2] = v_64;
    goto v_42;
v_44:
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    if (is_number(v_64)) goto v_49;
    else goto v_50;
v_49:
    v_64 = stack[-1];
    if (!car_legal(v_64)) v_64 = carerror(v_64); else
    v_64 = car(v_64);
    v_65 = ncons(v_64);
    env = stack[-3];
    v_64 = stack[-2];
    {   LispObject fn = basic_elt(env, 1); // union
    v_64 = (*qfn2(fn))(fn, v_65, v_64);
    }
    stack[-2] = v_64;
    goto v_42;
v_50:
    v_65 = stack[0];
    v_64 = stack[-2];
    {   LispObject fn = basic_elt(env, 1); // union
    v_64 = (*qfn2(fn))(fn, v_65, v_64);
    }
    stack[-2] = v_64;
    goto v_42;
v_42:
    v_64 = stack[-2];
    return onevalue(v_64);
}



// Code for aex_ex

static LispObject CC_aex_ex(LispObject env,
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
    v_8 = v_7;
    v_7 = (LispObject)32+TAG_FIXNUM; // 2
    {
        LispObject fn = basic_elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for addcomment

static LispObject CC_addcomment(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_5;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_5 = v_2;
// end of prologue
    setvalue(basic_elt(env, 1), v_5); // cursym!*
    return onevalue(v_5);
}



// Code for arrayp

static LispObject CC_arrayp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    if (!symbolp(v_8)) v_8 = nil;
    else { v_8 = qfastgets(v_8);
           if (v_8 != nil) { v_8 = elt(v_8, 2); // rtype
#ifdef RECORD_GET
             if (v_8 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v_8 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v_8 == SPID_NOPROP) v_8 = nil; }}
#endif
    v_9 = basic_elt(env, 1); // array
    v_8 = (v_8 == v_9 ? lisp_true : nil);
    return onevalue(v_8);
}



// Code for cl_cflip

static LispObject CC_cl_cflip(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15, v_16;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_3;
    v_16 = v_2;
// end of prologue
    if (v_15 == nil) goto v_8;
    v_15 = v_16;
    goto v_6;
v_8:
    v_15 = v_16;
    {
        LispObject fn = basic_elt(env, 1); // cl_flip
        return (*qfn1(fn))(fn, v_15);
    }
    v_15 = nil;
v_6:
    return onevalue(v_15);
}



// Code for kernlp

static LispObject CC_kernlp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_33, v_34;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_33 = v_2;
// end of prologue
v_6:
    v_34 = v_33;
    if (!consp(v_34)) goto v_13;
    else goto v_14;
v_13:
    v_34 = lisp_true;
    goto v_12;
v_14:
    v_34 = v_33;
    if (!car_legal(v_34)) v_34 = carerror(v_34); else
    v_34 = car(v_34);
    v_34 = (consp(v_34) ? nil : lisp_true);
    goto v_12;
    v_34 = nil;
v_12:
    if (v_34 == nil) goto v_10;
    goto v_5;
v_10:
    v_34 = v_33;
    if (!car_legal(v_34)) v_34 = cdrerror(v_34); else
    v_34 = cdr(v_34);
    if (v_34 == nil) goto v_23;
    else goto v_24;
v_23:
    if (!car_legal(v_33)) v_33 = carerror(v_33); else
    v_33 = car(v_33);
    if (!car_legal(v_33)) v_33 = cdrerror(v_33); else
    v_33 = cdr(v_33);
    goto v_6;
v_24:
    v_33 = nil;
    goto v_5;
    v_33 = nil;
v_5:
    return onevalue(v_33);
}



// Code for talp_invp

static LispObject CC_talp_invp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_28;
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
    v_28 = stack[0];
    v_28 = Lconsp(nil, v_28);
    env = stack[-2];
    if (v_28 == nil) goto v_6;
    else goto v_7;
v_6:
    v_28 = nil;
    goto v_5;
v_7:
    v_28 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // talp_op
    stack[-1] = (*qfn1(fn))(fn, v_28);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 2); // talp_getl
    v_28 = (*qfn0(fn))(fn);
    }
    env = stack[-2];
    v_28 = Latsoc(nil, stack[-1], v_28);
    if (v_28 == nil) goto v_15;
    else goto v_16;
v_15:
    v_28 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // talp_op
    stack[0] = (*qfn1(fn))(fn, v_28);
    }
    env = stack[-2];
    {   LispObject fn = basic_elt(env, 3); // talp_getextl
    v_28 = (*qfn0(fn))(fn);
    }
    v_28 = Latsoc(nil, stack[0], v_28);
    goto v_14;
v_16:
    v_28 = nil;
    goto v_14;
    v_28 = nil;
v_14:
    goto v_5;
    v_28 = nil;
v_5:
    return onevalue(v_28);
}



// Code for qqe_rbopp

static LispObject CC_qqe_rbopp(LispObject env,
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
    v_8 = basic_elt(env, 1); // (equal neq lessp leq geq greaterp)
    v_7 = Lmemq(nil, v_7, v_8);
    return onevalue(v_7);
}



// Code for lto_hashequalq

static LispObject CC_lto_hashequalq(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_60, v_61;
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
    stack_popper stack_popper_var(6);
// copy arguments values to proper place
    stack[-2] = v_3;
    stack[-3] = v_2;
// end of prologue
    v_60 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-1] = v_60;
    v_60 = (LispObject)0+TAG_FIXNUM; // 0
    stack[0] = v_60;
v_15:
    v_60 = stack[-3];
    if (v_60 == nil) goto v_18;
    v_60 = stack[-2];
    if (v_60 == nil) goto v_18;
    goto v_19;
v_18:
    goto v_14;
v_19:
    v_60 = stack[-3];
    if (!car_legal(v_60)) v_60 = carerror(v_60); else
    v_60 = car(v_60);
    v_61 = v_60;
    v_60 = stack[-2];
    if (!car_legal(v_60)) v_60 = carerror(v_60); else
    v_60 = car(v_60);
    stack[-4] = v_60;
    v_60 = stack[-3];
    if (!car_legal(v_60)) v_60 = cdrerror(v_60); else
    v_60 = cdr(v_60);
    stack[-3] = v_60;
    v_60 = stack[-2];
    if (!car_legal(v_60)) v_60 = cdrerror(v_60); else
    v_60 = cdr(v_60);
    stack[-2] = v_60;
    v_60 = v_61;
    {   LispObject fn = basic_elt(env, 1); // lto_hashid
    v_60 = (*qfn1(fn))(fn, v_60);
    }
    env = stack[-5];
    v_60 = (LispObject)(std::intptr_t)((std::intptr_t)stack[-1] + (std::intptr_t)v_60 - TAG_FIXNUM);
    stack[-1] = v_60;
    v_60 = stack[-4];
    {   LispObject fn = basic_elt(env, 1); // lto_hashid
    v_60 = (*qfn1(fn))(fn, v_60);
    }
    env = stack[-5];
    v_60 = (LispObject)(std::intptr_t)((std::intptr_t)stack[0] + (std::intptr_t)v_60 - TAG_FIXNUM);
    stack[0] = v_60;
    goto v_15;
v_14:
    v_60 = stack[-3];
    if (v_60 == nil) goto v_43;
    else goto v_44;
v_43:
    v_60 = stack[-2];
    if (v_60 == nil) goto v_48;
    else goto v_49;
v_48:
    v_61 = stack[-1];
    v_60 = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // iequal
        return (*qfn2(fn))(fn, v_61, v_60);
    }
v_49:
    v_60 = nil;
    goto v_47;
    v_60 = nil;
v_47:
    goto v_42;
v_44:
    v_60 = nil;
    goto v_42;
    v_60 = nil;
v_42:
    return onevalue(v_60);
}



// Code for sub2chk

static LispObject CC_sub2chk(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_29, v_30, v_31;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_31 = v_2;
// end of prologue
    v_29 = qvalue(basic_elt(env, 1)); // subfg!*
    if (v_29 == nil) goto v_7;
    v_30 = v_31;
    v_29 = qvalue(basic_elt(env, 2)); // powlis!*
    v_29 = Latsoc(nil, v_30, v_29);
    if (v_29 == nil) goto v_11;
    else goto v_10;
v_11:
    v_29 = v_31;
    if (!consp(v_29)) goto v_19;
    v_29 = v_31;
    if (!car_legal(v_29)) v_30 = carerror(v_29); else
    v_30 = car(v_29);
    v_29 = basic_elt(env, 3); // (expt sqrt)
    v_29 = Lmemq(nil, v_30, v_29);
    goto v_17;
v_19:
    v_29 = nil;
    goto v_17;
    v_29 = nil;
v_17:
    if (v_29 == nil) goto v_15;
    else goto v_10;
v_15:
    goto v_7;
v_10:
    v_29 = lisp_true;
    setvalue(basic_elt(env, 4), v_29); // !*sub2
    goto v_5;
v_7:
    v_29 = nil;
v_5:
    return onevalue(v_29);
}



// Code for butes

static LispObject CC_butes(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_35, v_36, v_37, v_38;
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
    v_38 = v_2;
// end of prologue
    v_35 = v_38;
    if (!car_legal(v_35)) v_35 = carerror(v_35); else
    v_35 = car(v_35);
    v_37 = v_35;
    v_36 = v_37;
    v_35 = basic_elt(env, 1); // ! 
    if (v_36 == v_35) goto v_15;
    else goto v_16;
v_15:
    v_35 = lisp_true;
    goto v_14;
v_16:
    v_36 = v_37;
    v_35 = basic_elt(env, 2); // !$
    v_35 = (v_36 == v_35 ? lisp_true : nil);
    goto v_14;
    v_35 = nil;
v_14:
    if (v_35 == nil) goto v_12;
    v_35 = nil;
    goto v_10;
v_12:
    v_35 = v_38;
    if (!car_legal(v_35)) stack[0] = carerror(v_35); else
    stack[0] = car(v_35);
    v_35 = v_38;
    if (!car_legal(v_35)) v_35 = cdrerror(v_35); else
    v_35 = cdr(v_35);
    v_35 = CC_butes(basic_elt(env, 0), v_35);
    {
        LispObject v_40 = stack[0];
        return cons(v_40, v_35);
    }
    v_35 = nil;
v_10:
    return onevalue(v_35);
}



// Code for exchk

static LispObject CC_exchk(LispObject env,
                         LispObject v_2)
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
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
    stack_popper stack_popper_var(4);
// copy arguments values to proper place
    v_10 = v_2;
// end of prologue
    stack[-2] = v_10;
    stack[-1] = nil;
    stack[0] = nil;
    v_10 = nil;
    v_10 = ncons(v_10);
    env = stack[-3];
    {
        LispObject v_14 = stack[-2];
        LispObject v_15 = stack[-1];
        LispObject v_16 = stack[0];
        LispObject fn = basic_elt(env, 1); // exchk1
        return (*qfn4up(fn))(fn, v_14, v_15, v_16, v_10);
    }
}



// Code for expchk

static LispObject CC_expchk(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_15 = v_2;
// end of prologue
    v_14 = qvalue(basic_elt(env, 1)); // !*exp
    if (v_14 == nil) goto v_7;
    v_14 = v_15;
    goto v_5;
v_7:
    v_14 = v_15;
    {
        LispObject fn = basic_elt(env, 2); // offexpchk
        return (*qfn1(fn))(fn, v_14);
    }
    v_14 = nil;
v_5:
    return onevalue(v_14);
}



// Code for dm!-abs

static LispObject CC_dmKabs(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_15;
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
    v_15 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // !:minusp
    v_15 = (*qfn1(fn))(fn, v_15);
    }
    env = stack[-1];
    if (v_15 == nil) goto v_7;
    v_15 = stack[0];
    {
        LispObject fn = basic_elt(env, 2); // dm!-minus
        return (*qfn1(fn))(fn, v_15);
    }
v_7:
    v_15 = stack[0];
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for binding

static LispObject CC_binding(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_14, v_15;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_14 = v_2;
// end of prologue
    if (!symbolp(v_14)) v_14 = nil;
    else { v_14 = qfastgets(v_14);
           if (v_14 != nil) { v_14 = elt(v_14, 13); // binding
#ifdef RECORD_GET
             if (v_14 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v_14 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v_14 == SPID_NOPROP) v_14 = nil; }}
#endif
    v_15 = v_14;
    v_14 = v_15;
    if (v_14 == nil) goto v_10;
    v_14 = v_15;
    if (!car_legal(v_14)) v_14 = carerror(v_14); else
    v_14 = car(v_14);
    goto v_8;
v_10:
    v_14 = nil;
v_8:
    return onevalue(v_14);
}



// Code for evlexcomp

static LispObject CC_evlexcomp(LispObject env,
                         LispObject v_2, LispObject v_3)
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
v_7:
    v_39 = stack[-1];
    if (v_39 == nil) goto v_10;
    else goto v_11;
v_10:
    v_39 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6;
v_11:
    v_39 = stack[0];
    if (v_39 == nil) goto v_14;
    else goto v_15;
v_14:
    v_39 = basic_elt(env, 1); // (0)
    stack[0] = v_39;
    goto v_7;
v_15:
    v_39 = stack[-1];
    if (!car_legal(v_39)) v_40 = carerror(v_39); else
    v_40 = car(v_39);
    v_39 = stack[0];
    if (!car_legal(v_39)) v_39 = carerror(v_39); else
    v_39 = car(v_39);
    {   LispObject fn = basic_elt(env, 2); // iequal
    v_39 = (*qfn2(fn))(fn, v_40, v_39);
    }
    env = stack[-2];
    if (v_39 == nil) goto v_19;
    v_39 = stack[-1];
    if (!car_legal(v_39)) v_39 = cdrerror(v_39); else
    v_39 = cdr(v_39);
    stack[-1] = v_39;
    v_39 = stack[0];
    if (!car_legal(v_39)) v_39 = cdrerror(v_39); else
    v_39 = cdr(v_39);
    stack[0] = v_39;
    goto v_7;
v_19:
    v_39 = stack[-1];
    if (!car_legal(v_39)) v_40 = carerror(v_39); else
    v_40 = car(v_39);
    v_39 = stack[0];
    if (!car_legal(v_39)) v_39 = carerror(v_39); else
    v_39 = car(v_39);
    if (((std::intptr_t)(v_40)) > ((std::intptr_t)(v_39))) goto v_29;
    else goto v_30;
v_29:
    v_39 = (LispObject)16+TAG_FIXNUM; // 1
    goto v_6;
v_30:
    v_39 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_6;
    v_39 = nil;
v_6:
    return onevalue(v_39);
}



// Code for sc_getmat

static LispObject CC_sc_getmat(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
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
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_4;
    v_13 = v_3;
    v_14 = v_2;
// end of prologue
    stack[-1] = v_14;
    v_13 = sub1(v_13);
    env = stack[-2];
    stack[-1] = Lgetv(nil, stack[-1], v_13);
    env = stack[-2];
    v_13 = stack[0];
    v_13 = sub1(v_13);
    {
        LispObject v_17 = stack[-1];
        return Lgetv(nil, v_17, v_13);
    }
}



// Code for getrtypecar

static LispObject CC_getrtypecar(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_7;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_7 = v_2;
// end of prologue
    if (!car_legal(v_7)) v_7 = carerror(v_7); else
    v_7 = car(v_7);
    {
        LispObject fn = basic_elt(env, 1); // getrtype
        return (*qfn1(fn))(fn, v_7);
    }
}



// Code for round!*

static LispObject CC_roundH(LispObject env,
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
    if (!car_legal(v_16)) v_16 = cdrerror(v_16); else
    v_16 = cdr(v_16);
    if (!consp(v_16)) goto v_6;
    else goto v_7;
v_6:
    if (!car_legal(v_15)) v_15 = cdrerror(v_15); else
    v_15 = cdr(v_15);
    goto v_5;
v_7:
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for isanindex

static LispObject CC_isanindex(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_39, v_40, v_41;
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
    v_41 = v_2;
// end of prologue
    v_39 = v_41;
    if (symbolp(v_39)) goto v_7;
    v_39 = nil;
    goto v_5;
v_7:
    v_40 = v_41;
    v_39 = qvalue(basic_elt(env, 1)); // physopindices!*
    v_39 = Lmemq(nil, v_40, v_39);
    if (v_39 == nil) goto v_14;
    else goto v_13;
v_14:
    v_40 = v_41;
    v_39 = qvalue(basic_elt(env, 2)); // physopvarind!*
    v_39 = Lmember(nil, v_40, v_39);
    if (v_39 == nil) goto v_20;
    else goto v_19;
v_20:
    v_40 = v_41;
    v_39 = qvalue(basic_elt(env, 3)); // frlis!*
    v_39 = Lmemq(nil, v_40, v_39);
    if (v_39 == nil) goto v_26;
    else goto v_27;
v_26:
    v_39 = nil;
    goto v_25;
v_27:
    v_40 = v_41;
    v_39 = qvalue(basic_elt(env, 4)); // frasc!*
    {   LispObject fn = basic_elt(env, 5); // revassoc
    v_39 = (*qfn2(fn))(fn, v_40, v_39);
    }
    env = stack[0];
    v_40 = qvalue(basic_elt(env, 1)); // physopindices!*
    v_39 = Lmember(nil, v_39, v_40);
    goto v_25;
    v_39 = nil;
v_25:
v_19:
v_13:
    goto v_5;
    v_39 = nil;
v_5:
    return onevalue(v_39);
}



// Code for poly!-multf

static LispObject CC_polyKmultf(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_266, v_267, v_268;
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
    stack[-3] = nil;
v_9:
    v_266 = stack[-2];
    if (v_266 == nil) goto v_16;
    else goto v_17;
v_16:
    v_266 = lisp_true;
    goto v_15;
v_17:
    v_266 = stack[-1];
    v_266 = (v_266 == nil ? lisp_true : nil);
    goto v_15;
    v_266 = nil;
v_15:
    if (v_266 == nil) goto v_13;
    v_266 = nil;
    goto v_8;
v_13:
    v_267 = stack[-2];
    v_266 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_267 == v_266) goto v_25;
    else goto v_26;
v_25:
    v_266 = stack[-1];
    goto v_8;
v_26:
    v_267 = stack[-1];
    v_266 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_267 == v_266) goto v_30;
    else goto v_31;
v_30:
    v_266 = stack[-2];
    goto v_8;
v_31:
    v_266 = stack[-2];
    if (!consp(v_266)) goto v_39;
    else goto v_40;
v_39:
    v_266 = lisp_true;
    goto v_38;
v_40:
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    v_266 = (consp(v_266) ? nil : lisp_true);
    goto v_38;
    v_266 = nil;
v_38:
    if (v_266 == nil) goto v_36;
    v_267 = stack[-2];
    v_266 = stack[-1];
    {
        LispObject fn = basic_elt(env, 8); // multd
        return (*qfn2(fn))(fn, v_267, v_266);
    }
v_36:
    v_266 = stack[-1];
    if (!consp(v_266)) goto v_55;
    else goto v_56;
v_55:
    v_266 = lisp_true;
    goto v_54;
v_56:
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    v_266 = (consp(v_266) ? nil : lisp_true);
    goto v_54;
    v_266 = nil;
v_54:
    if (v_266 == nil) goto v_52;
    v_267 = stack[-1];
    v_266 = stack[-2];
    {
        LispObject fn = basic_elt(env, 8); // multd
        return (*qfn2(fn))(fn, v_267, v_266);
    }
v_52:
    v_266 = qvalue(basic_elt(env, 1)); // !*exp
    if (v_266 == nil) goto v_69;
    else goto v_68;
v_69:
    v_266 = qvalue(basic_elt(env, 2)); // ncmp!*
    if (v_266 == nil) goto v_72;
    else goto v_68;
v_72:
    v_266 = qvalue(basic_elt(env, 3)); // wtl!*
    if (v_266 == nil) goto v_75;
    else goto v_68;
v_75:
    v_266 = stack[-3];
    if (v_266 == nil) goto v_77;
    else goto v_68;
v_77:
    v_266 = stack[-2];
    {   LispObject fn = basic_elt(env, 9); // mkprod
    v_266 = (*qfn1(fn))(fn, v_266);
    }
    env = stack[-4];
    stack[-2] = v_266;
    v_266 = stack[-1];
    {   LispObject fn = basic_elt(env, 9); // mkprod
    v_266 = (*qfn1(fn))(fn, v_266);
    }
    env = stack[-4];
    stack[-1] = v_266;
    v_266 = lisp_true;
    stack[-3] = v_266;
    goto v_9;
v_68:
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    stack[-3] = v_266;
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    stack[0] = v_266;
    v_266 = stack[-1];
    {   LispObject fn = basic_elt(env, 10); // noncomfp
    v_266 = (*qfn1(fn))(fn, v_266);
    }
    env = stack[-4];
    if (v_266 == nil) goto v_95;
    v_266 = stack[-3];
    {   LispObject fn = basic_elt(env, 11); // noncomp
    v_266 = (*qfn1(fn))(fn, v_266);
    }
    env = stack[-4];
    if (v_266 == nil) goto v_100;
    else goto v_99;
v_100:
    v_266 = qvalue(basic_elt(env, 4)); // !*!*processed
    if (v_266 == nil) goto v_99;
    goto v_95;
v_99:
    v_267 = stack[-2];
    v_266 = stack[-1];
    {
        LispObject fn = basic_elt(env, 12); // poly!-multfnc
        return (*qfn2(fn))(fn, v_267, v_266);
    }
v_95:
    v_267 = stack[-3];
    v_266 = stack[0];
    if (v_267 == v_266) goto v_108;
    else goto v_109;
v_108:
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = integerp(v_266);
    if (v_266 == nil) goto v_118;
    else goto v_119;
v_118:
    v_266 = lisp_true;
    goto v_117;
v_119:
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = integerp(v_266);
    v_266 = (v_266 == nil ? lisp_true : nil);
    goto v_117;
    v_266 = nil;
v_117:
    if (v_266 == nil) goto v_115;
    stack[0] = stack[-3];
    v_268 = basic_elt(env, 5); // plus
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_267 = cdrerror(v_266); else
    v_267 = cdr(v_266);
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = list3(v_268, v_267, v_266);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 13); // reval
    v_266 = (*qfn1(fn))(fn, v_266);
    }
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 14); // to
    v_266 = (*qfn2(fn))(fn, stack[0], v_266);
    }
    env = stack[-4];
    stack[-3] = v_266;
    goto v_113;
v_115:
    stack[0] = stack[-3];
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_267 = cdrerror(v_266); else
    v_267 = cdr(v_266);
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = plus2(v_267, v_266);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 15); // mkspm
    v_266 = (*qfn2(fn))(fn, stack[0], v_266);
    }
    env = stack[-4];
    stack[-3] = v_266;
    goto v_113;
v_113:
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_267 = cdrerror(v_266); else
    v_267 = cdr(v_266);
    v_266 = stack[-1];
    stack[0] = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    env = stack[-4];
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    v_267 = ncons(v_266);
    env = stack[-4];
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 16); // addf
    v_266 = (*qfn2(fn))(fn, stack[0], v_266);
    }
    env = stack[-4];
    stack[0] = v_266;
    v_266 = stack[-3];
    if (v_266 == nil) goto v_177;
    else goto v_178;
v_177:
    v_266 = lisp_true;
    goto v_176;
v_178:
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_267 = cdrerror(v_266); else
    v_267 = cdr(v_266);
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    env = stack[-4];
    stack[-2] = v_266;
    v_266 = (v_266 == nil ? lisp_true : nil);
    goto v_176;
    v_266 = nil;
v_176:
    if (v_266 == nil) goto v_174;
    v_266 = lisp_true;
    setvalue(basic_elt(env, 6), v_266); // !*asymp!*
    v_266 = stack[0];
    goto v_172;
v_174:
    v_267 = stack[-3];
    v_266 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_267 == v_266) goto v_193;
    else goto v_194;
v_193:
    v_267 = stack[-2];
    v_266 = stack[0];
    {
        LispObject fn = basic_elt(env, 16); // addf
        return (*qfn2(fn))(fn, v_267, v_266);
    }
v_194:
    v_266 = qvalue(basic_elt(env, 7)); // !*mcd
    if (v_266 == nil) goto v_200;
    else goto v_201;
v_200:
    v_267 = stack[-3];
    v_266 = stack[-2];
    v_266 = cons(v_267, v_266);
    env = stack[-4];
    v_267 = ncons(v_266);
    env = stack[-4];
    v_266 = stack[0];
    {
        LispObject fn = basic_elt(env, 16); // addf
        return (*qfn2(fn))(fn, v_267, v_266);
    }
v_201:
    v_268 = stack[-3];
    v_267 = stack[-2];
    v_266 = stack[0];
    return acons(v_268, v_267, v_266);
    v_266 = nil;
v_172:
    goto v_8;
v_109:
    v_267 = stack[-3];
    v_266 = stack[0];
    {   LispObject fn = basic_elt(env, 17); // ordop
    v_266 = (*qfn2(fn))(fn, v_267, v_266);
    }
    env = stack[-4];
    if (v_266 == nil) goto v_216;
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_267 = cdrerror(v_266); else
    v_267 = cdr(v_266);
    v_266 = stack[-1];
    v_266 = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    env = stack[-4];
    stack[-3] = v_266;
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_267 = cdrerror(v_266); else
    v_267 = cdr(v_266);
    v_266 = stack[-1];
    v_266 = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    stack[0] = v_266;
    v_266 = stack[-3];
    if (v_266 == nil) goto v_231;
    else goto v_232;
v_231:
    v_266 = stack[0];
    goto v_230;
v_232:
    v_266 = stack[-2];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_268 = carerror(v_266); else
    v_268 = car(v_266);
    v_267 = stack[-3];
    v_266 = stack[0];
    return acons(v_268, v_267, v_266);
    v_266 = nil;
v_230:
    goto v_8;
v_216:
    v_267 = stack[-2];
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    env = stack[-4];
    stack[-3] = v_266;
    v_267 = stack[-2];
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = cdrerror(v_266); else
    v_266 = cdr(v_266);
    v_266 = CC_polyKmultf(basic_elt(env, 0), v_267, v_266);
    stack[0] = v_266;
    v_266 = stack[-3];
    if (v_266 == nil) goto v_254;
    else goto v_255;
v_254:
    v_266 = stack[0];
    goto v_253;
v_255:
    v_266 = stack[-1];
    if (!car_legal(v_266)) v_266 = carerror(v_266); else
    v_266 = car(v_266);
    if (!car_legal(v_266)) v_268 = carerror(v_266); else
    v_268 = car(v_266);
    v_267 = stack[-3];
    v_266 = stack[0];
    return acons(v_268, v_267, v_266);
    v_266 = nil;
v_253:
v_8:
    return onevalue(v_266);
}



// Code for mo_divides!?

static LispObject CC_mo_dividesW(LispObject env,
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
    {
        LispObject fn = basic_elt(env, 1); // mo!=modiv1
        return (*qfn2(fn))(fn, v_11, v_10);
    }
}



// Code for dlesslex

static LispObject CC_dlesslex(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_34, v_35, v_36, v_37;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_35 = v_3;
    v_36 = v_2;
// end of prologue
v_7:
    v_34 = v_36;
    if (v_34 == nil) goto v_10;
    else goto v_11;
v_10:
    v_34 = nil;
    goto v_6;
v_11:
    v_34 = v_36;
    if (!car_legal(v_34)) v_37 = carerror(v_34); else
    v_37 = car(v_34);
    v_34 = v_35;
    if (!car_legal(v_34)) v_34 = carerror(v_34); else
    v_34 = car(v_34);
    if (((std::intptr_t)(v_37)) > ((std::intptr_t)(v_34))) goto v_14;
    else goto v_15;
v_14:
    v_34 = nil;
    goto v_6;
v_15:
    v_34 = v_36;
    if (!car_legal(v_34)) v_37 = carerror(v_34); else
    v_37 = car(v_34);
    v_34 = v_35;
    if (!car_legal(v_34)) v_34 = carerror(v_34); else
    v_34 = car(v_34);
    if (((std::intptr_t)(v_37)) < ((std::intptr_t)(v_34))) goto v_21;
    else goto v_22;
v_21:
    v_34 = lisp_true;
    goto v_6;
v_22:
    v_34 = v_36;
    if (!car_legal(v_34)) v_34 = cdrerror(v_34); else
    v_34 = cdr(v_34);
    v_36 = v_34;
    v_34 = v_35;
    if (!car_legal(v_34)) v_34 = cdrerror(v_34); else
    v_34 = cdr(v_34);
    v_35 = v_34;
    goto v_7;
    v_34 = nil;
v_6:
    return onevalue(v_34);
}



// Code for hasonevector

static LispObject CC_hasonevector(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_21;
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
    v_21 = stack[0];
    if (v_21 == nil) goto v_6;
    else goto v_7;
v_6:
    v_21 = nil;
    goto v_5;
v_7:
    v_21 = stack[0];
    if (!car_legal(v_21)) v_21 = carerror(v_21); else
    v_21 = car(v_21);
    {   LispObject fn = basic_elt(env, 1); // vecp
    v_21 = (*qfn1(fn))(fn, v_21);
    }
    env = stack[-1];
    if (v_21 == nil) goto v_14;
    else goto v_13;
v_14:
    v_21 = stack[0];
    if (!car_legal(v_21)) v_21 = cdrerror(v_21); else
    v_21 = cdr(v_21);
    stack[0] = v_21;
    goto v_1;
v_13:
    goto v_5;
    v_21 = nil;
v_5:
    return onevalue(v_21);
}



// Code for reduce_pv0

static LispObject CC_reduce_pv0(LispObject env,
                         LispObject v_2, LispObject v_3,
                         LispObject v_4)
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
        push(v_2,v_3,v_4);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
    stack_popper stack_popper_var(7);
// copy arguments values to proper place
    stack[-3] = v_4;
    stack[-4] = v_3;
    stack[0] = v_2;
// end of prologue
    v_102 = stack[-4];
    if (v_102 == nil) goto v_8;
    else goto v_9;
v_8:
    v_102 = stack[0];
    goto v_7;
v_9:
    v_102 = stack[0];
    if (v_102 == nil) goto v_12;
    else goto v_13;
v_12:
    v_102 = nil;
    goto v_7;
v_13:
    v_102 = stack[0];
    stack[-5] = v_102;
v_25:
    v_102 = stack[-5];
    if (v_102 == nil) goto v_28;
    v_102 = stack[-4];
    if (v_102 == nil) goto v_28;
    v_102 = stack[-5];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_103 = cdrerror(v_102); else
    v_103 = cdr(v_102);
    v_102 = stack[-4];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_102 = cdrerror(v_102); else
    v_102 = cdr(v_102);
    v_102 = (LispObject)greaterp2(v_103, v_102);
    v_102 = v_102 ? lisp_true : nil;
    env = stack[-6];
    if (v_102 == nil) goto v_28;
    goto v_29;
v_28:
    goto v_24;
v_29:
    v_102 = stack[-5];
    if (!car_legal(v_102)) v_102 = cdrerror(v_102); else
    v_102 = cdr(v_102);
    stack[-5] = v_102;
    goto v_25;
v_24:
    v_102 = stack[-5];
    if (v_102 == nil) goto v_49;
    v_102 = stack[-4];
    if (v_102 == nil) goto v_49;
    v_102 = stack[-4];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_103 = cdrerror(v_102); else
    v_103 = cdr(v_102);
    v_102 = stack[-5];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_102 = cdrerror(v_102); else
    v_102 = cdr(v_102);
    if (equal(v_103, v_102)) goto v_55;
    else goto v_49;
v_55:
    v_102 = stack[-5];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_103 = carerror(v_102); else
    v_103 = car(v_102);
    v_102 = stack[-4];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    {   LispObject fn = basic_elt(env, 2); // lcm
    v_102 = (*qfn2(fn))(fn, v_103, v_102);
    }
    env = stack[-6];
    stack[-2] = v_102;
    v_103 = stack[-2];
    v_102 = stack[-5];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    v_102 = quot2(v_103, v_102);
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 3); // pv_multc
    stack[-1] = (*qfn2(fn))(fn, stack[0], v_102);
    }
    env = stack[-6];
    stack[0] = stack[-4];
    v_103 = stack[-2];
    v_102 = stack[-4];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    v_102 = quot2(v_103, v_102);
    env = stack[-6];
    v_102 = negate(v_102);
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 3); // pv_multc
    v_102 = (*qfn2(fn))(fn, stack[0], v_102);
    }
    env = stack[-6];
    {   LispObject fn = basic_elt(env, 4); // pv_add
    v_102 = (*qfn2(fn))(fn, stack[-1], v_102);
    }
    env = stack[-6];
    stack[0] = v_102;
    v_102 = stack[-3];
    if (v_102 == nil) goto v_87;
    else goto v_88;
v_87:
    stack[-1] = qvalue(basic_elt(env, 1)); // pv_den
    v_103 = stack[-2];
    v_102 = stack[-5];
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    if (!car_legal(v_102)) v_102 = carerror(v_102); else
    v_102 = car(v_102);
    v_102 = quot2(v_103, v_102);
    env = stack[-6];
    v_102 = times2(stack[-1], v_102);
    env = stack[-6];
    setvalue(basic_elt(env, 1), v_102); // pv_den
    goto v_86;
v_88:
    v_102 = (LispObject)16+TAG_FIXNUM; // 1
    setvalue(basic_elt(env, 1), v_102); // pv_den
    goto v_86;
v_86:
    goto v_47;
v_49:
v_47:
    v_102 = stack[0];
    goto v_7;
    v_102 = nil;
v_7:
    return onevalue(v_102);
}



// Code for modonep!:

static LispObject CC_modonepT(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
    if (!car_legal(v_8)) v_9 = cdrerror(v_8); else
    v_9 = cdr(v_8);
    v_8 = (LispObject)16+TAG_FIXNUM; // 1
    v_8 = (v_9 == v_8 ? lisp_true : nil);
    return onevalue(v_8);
}



// Code for remainder!-in!-vector

static LispObject CC_remainderKinKvector(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_109, v_110, v_111;
    LispObject v_5;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3,v_4,v_5);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5,v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
    stack_popper stack_popper_var(13);
// copy arguments values to proper place
    stack[-7] = v_5;
    stack[-8] = v_4;
    stack[-9] = v_3;
    stack[-10] = v_2;
// end of prologue
    v_110 = stack[-7];
    v_109 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_110 == v_109) goto v_15;
    else goto v_16;
v_15:
    v_109 = (LispObject)-16+TAG_FIXNUM; // -1
    goto v_12;
v_16:
    v_110 = stack[-7];
    v_109 = (LispObject)-16+TAG_FIXNUM; // -1
    if (v_110 == v_109) goto v_20;
    else goto v_21;
v_20:
    v_109 = basic_elt(env, 1); // "Attempt to divide by zero"
    {   LispObject fn = basic_elt(env, 2); // errorf
    v_109 = (*qfn1(fn))(fn, v_109);
    }
    env = stack[-12];
    goto v_14;
v_21:
v_14:
    v_110 = stack[-8];
    v_109 = stack[-7];
    v_109 = Lgetv(nil, v_110, v_109);
    env = stack[-12];
    v_109 = Lmodular_reciprocal(nil, v_109);
    env = stack[-12];
    {   std::intptr_t w = int_of_fixnum(v_109);
        if (w != 0) w = current_modulus - w;
        v_109 = fixnum_of_int(w);
    }
    stack[-5] = v_109;
    v_109 = stack[-7];
    v_109 = (LispObject)((std::intptr_t)(v_109) - 0x10);
    stack[-6] = v_109;
v_35:
    v_110 = stack[-9];
    v_109 = stack[-7];
    v_110 = (LispObject)(std::intptr_t)((std::intptr_t)v_110 - (std::intptr_t)v_109 + TAG_FIXNUM);
    stack[-11] = v_110;
    v_109 = (LispObject)0+TAG_FIXNUM; // 0
    if (((std::intptr_t)(v_110)) < ((std::intptr_t)(v_109))) goto v_38;
    else goto v_39;
v_38:
    goto v_34;
v_39:
    stack[0] = stack[-5];
    v_110 = stack[-10];
    v_109 = stack[-9];
    v_109 = Lgetv(nil, v_110, v_109);
    env = stack[-12];
    v_109 = Lmodular_times(nil, stack[0], v_109);
    env = stack[-12];
    stack[-4] = v_109;
    v_109 = (LispObject)0+TAG_FIXNUM; // 0
    stack[-3] = v_109;
v_53:
    v_110 = stack[-6];
    v_109 = stack[-3];
    v_109 = (LispObject)(std::intptr_t)((std::intptr_t)v_110 - (std::intptr_t)v_109 + TAG_FIXNUM);
    v_109 = ((std::intptr_t)(v_109) < 0 ? lisp_true : nil);
    if (v_109 == nil) goto v_58;
    goto v_52;
v_58:
    stack[-2] = stack[-10];
    v_110 = stack[-3];
    v_109 = stack[-11];
    stack[-1] = (LispObject)(std::intptr_t)((std::intptr_t)v_110 + (std::intptr_t)v_109 - TAG_FIXNUM);
    v_111 = stack[-10];
    v_110 = stack[-3];
    v_109 = stack[-11];
    v_109 = (LispObject)(std::intptr_t)((std::intptr_t)v_110 + (std::intptr_t)v_109 - TAG_FIXNUM);
    stack[0] = Lgetv(nil, v_111, v_109);
    env = stack[-12];
    v_110 = stack[-8];
    v_109 = stack[-3];
    v_110 = Lgetv(nil, v_110, v_109);
    env = stack[-12];
    v_109 = stack[-4];
    v_109 = Lmodular_times(nil, v_110, v_109);
    env = stack[-12];
    {   std::intptr_t w = int_of_fixnum(stack[0]) + int_of_fixnum(v_109);
        if (w >= current_modulus) w -= current_modulus;
        v_109 = fixnum_of_int(w);
    }
    v_109 = Lputv(nil, stack[-2], stack[-1], v_109);
    env = stack[-12];
    v_109 = stack[-3];
    v_109 = (LispObject)((std::intptr_t)(v_109) + 0x10);
    stack[-3] = v_109;
    goto v_53;
v_52:
    v_109 = stack[-9];
    v_109 = (LispObject)((std::intptr_t)(v_109) - 0x10);
    stack[-9] = v_109;
v_86:
    v_110 = stack[-9];
    v_109 = (LispObject)0+TAG_FIXNUM; // 0
    if (((std::intptr_t)(v_110)) < ((std::intptr_t)(v_109))) goto v_94;
    v_110 = stack[-10];
    v_109 = stack[-9];
    v_110 = Lgetv(nil, v_110, v_109);
    env = stack[-12];
    v_109 = (LispObject)0+TAG_FIXNUM; // 0
    v_109 = (v_110 == v_109 ? lisp_true : nil);
    goto v_92;
v_94:
    v_109 = nil;
    goto v_92;
    v_109 = nil;
v_92:
    if (v_109 == nil) goto v_89;
    else goto v_90;
v_89:
    goto v_85;
v_90:
    v_109 = stack[-9];
    v_109 = (LispObject)((std::intptr_t)(v_109) - 0x10);
    stack[-9] = v_109;
    goto v_86;
v_85:
    goto v_35;
v_34:
    v_109 = stack[-9];
v_12:
    return onevalue(v_109);
}



// Code for smemql

static LispObject CC_smemql(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_32, v_33;
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
    v_32 = stack[-1];
    if (v_32 == nil) goto v_11;
    else goto v_12;
v_11:
    v_32 = stack[-2];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_32);
    }
v_12:
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_33 = carerror(v_32); else
    v_33 = car(v_32);
    v_32 = stack[0];
    v_32 = Lsmemq(nil, v_33, v_32);
    env = stack[-3];
    if (v_32 == nil) goto v_17;
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_33 = carerror(v_32); else
    v_33 = car(v_32);
    v_32 = stack[-2];
    v_32 = cons(v_33, v_32);
    env = stack[-3];
    stack[-2] = v_32;
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    stack[-1] = v_32;
    goto v_8;
v_17:
    v_32 = stack[-1];
    if (!car_legal(v_32)) v_32 = cdrerror(v_32); else
    v_32 = cdr(v_32);
    stack[-1] = v_32;
    goto v_8;
    v_32 = nil;
    return onevalue(v_32);
}



// Code for multd

static LispObject CC_multd(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_55, v_56;
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
    stack[-3] = nil;
v_8:
    v_55 = stack[-1];
    if (v_55 == nil) goto v_11;
    else goto v_12;
v_11:
    v_55 = stack[-3];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn1(fn))(fn, v_55);
    }
v_12:
    v_56 = stack[-1];
    v_55 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_56 == v_55) goto v_16;
    else goto v_17;
v_16:
    v_56 = stack[-3];
    v_55 = stack[-2];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_56, v_55);
    }
v_17:
    v_55 = stack[-1];
    if (!consp(v_55)) goto v_27;
    else goto v_28;
v_27:
    v_55 = lisp_true;
    goto v_26;
v_28:
    v_55 = stack[-1];
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    v_55 = (consp(v_55) ? nil : lisp_true);
    goto v_26;
    v_55 = nil;
v_26:
    if (v_55 == nil) goto v_24;
    stack[0] = stack[-3];
    v_56 = stack[-2];
    v_55 = stack[-1];
    {   LispObject fn = basic_elt(env, 2); // multdm
    v_55 = (*qfn2(fn))(fn, v_56, v_55);
    }
    env = stack[-4];
    {
        LispObject v_61 = stack[0];
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_61, v_55);
    }
v_24:
    v_55 = stack[-1];
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    if (!car_legal(v_55)) stack[0] = carerror(v_55); else
    stack[0] = car(v_55);
    v_56 = stack[-2];
    v_55 = stack[-1];
    if (!car_legal(v_55)) v_55 = carerror(v_55); else
    v_55 = car(v_55);
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    v_56 = CC_multd(basic_elt(env, 0), v_56, v_55);
    env = stack[-4];
    v_55 = stack[-3];
    v_55 = acons(stack[0], v_56, v_55);
    env = stack[-4];
    stack[-3] = v_55;
    v_55 = stack[-1];
    if (!car_legal(v_55)) v_55 = cdrerror(v_55); else
    v_55 = cdr(v_55);
    stack[-1] = v_55;
    goto v_8;
    v_55 = nil;
    return onevalue(v_55);
}



// Code for lalr_add_lookahead

static LispObject CC_lalr_add_lookahead(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_22, v_23, v_24;
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
    v_23 = v_3;
    v_24 = v_2;
// end of prologue
    v_22 = v_24;
    if (v_22 == nil) goto v_8;
    stack[0] = v_24;
    v_22 = v_23;
    v_23 = v_24;
    if (!car_legal(v_23)) v_23 = cdrerror(v_23); else
    v_23 = cdr(v_23);
    v_22 = cons(v_22, v_23);
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_22);
    v_22 = stack[0];
    goto v_6;
v_8:
    stack[0] = v_24;
    v_22 = v_23;
    v_22 = ncons(v_22);
    if (!car_legal(stack[0])) rplacd_fails(stack[0]);
    setcdr(stack[0], v_22);
    v_22 = stack[0];
    goto v_6;
    v_22 = nil;
v_6:
    return onevalue(v_22);
}



// Code for setkorder

static LispObject CC_setkorder(LispObject env,
                         LispObject v_2)
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
        push(v_2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
    stack_popper stack_popper_var(2);
// copy arguments values to proper place
    v_21 = v_2;
// end of prologue
    v_19 = qvalue(basic_elt(env, 1)); // kord!*
    stack[0] = v_19;
    v_20 = v_21;
    v_19 = stack[0];
    if (equal(v_20, v_19)) goto v_10;
    else goto v_11;
v_10:
    v_19 = stack[0];
    goto v_6;
v_11:
    v_19 = v_21;
    setvalue(basic_elt(env, 1), v_19); // kord!*
    v_19 = nil;
    v_19 = ncons(v_19);
    env = stack[-1];
    setvalue(basic_elt(env, 2), v_19); // alglist!*
    v_19 = stack[0];
v_6:
    return onevalue(v_19);
}



// Code for minusf

static LispObject CC_minusf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_46, v_47;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_46 = v_2;
// end of prologue
v_6:
    v_47 = v_46;
    if (v_47 == nil) goto v_9;
    else goto v_10;
v_9:
    v_46 = nil;
    goto v_5;
v_10:
    v_47 = v_46;
    if (!consp(v_47)) goto v_17;
    else goto v_18;
v_17:
    v_47 = lisp_true;
    goto v_16;
v_18:
    v_47 = v_46;
    if (!car_legal(v_47)) v_47 = carerror(v_47); else
    v_47 = car(v_47);
    v_47 = (consp(v_47) ? nil : lisp_true);
    goto v_16;
    v_47 = nil;
v_16:
    if (v_47 == nil) goto v_14;
    v_47 = v_46;
    if (!consp(v_47)) goto v_28;
    else goto v_29;
v_28:
    v_47 = v_46;
    v_46 = (LispObject)0+TAG_FIXNUM; // 0
        return Llessp_2(nil, v_47, v_46);
v_29:
    v_47 = v_46;
    if (!car_legal(v_47)) v_47 = carerror(v_47); else
    v_47 = car(v_47);
    if (!symbolp(v_47)) v_47 = nil;
    else { v_47 = qfastgets(v_47);
           if (v_47 != nil) { v_47 = elt(v_47, 30); // minusp
#ifdef RECORD_GET
             if (v_47 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_47 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_47 == SPID_NOPROP) v_47 = nil; }}
#endif
        return Lapply1(nil, v_47, v_46);
    goto v_8;
v_14:
    if (!car_legal(v_46)) v_46 = carerror(v_46); else
    v_46 = car(v_46);
    if (!car_legal(v_46)) v_46 = cdrerror(v_46); else
    v_46 = cdr(v_46);
    goto v_6;
v_8:
    v_46 = nil;
v_5:
    return onevalue(v_46);
}



// Code for mtchp1

static LispObject CC_mtchp1(LispObject env, LispObject v_2,
                         LispObject v_3, LispObject v_4, LispObject _a4up_)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_125, v_126, v_127;
    LispObject v_5;
    if (_a4up_ == nil)
        aerror1("not enough arguments provided", basic_elt(env, 0));
    v_5 = car(_a4up_); _a4up_ = cdr(_a4up_);
    if (_a4up_ != nil)
        aerror1("too many arguments provided", basic_elt(env, 0));
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        stack >= stacklimit)
    {
        push(v_2,v_3,v_4,v_5);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v_5,v_4,v_3,v_2);
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
    stack_popper stack_popper_var(5);
// copy arguments values to proper place
    v_125 = v_5;
    stack[0] = v_4;
    stack[-1] = v_3;
    stack[-2] = v_2;
// end of prologue
    v_126 = stack[-2];
    v_125 = stack[-1];
    if (equal(v_126, v_125)) goto v_12;
    else goto v_13;
v_12:
    v_125 = nil;
    return ncons(v_125);
v_13:
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_126 = carerror(v_125); else
    v_126 = car(v_125);
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = carerror(v_125); else
    v_125 = car(v_125);
    {   LispObject fn = basic_elt(env, 3); // mchk!*
    v_125 = (*qfn2(fn))(fn, v_126, v_125);
    }
    env = stack[-4];
    stack[-3] = v_125;
    if (v_125 == nil) goto v_18;
    else goto v_19;
v_18:
    v_125 = nil;
    goto v_9;
v_19:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_126 = cdrerror(v_125); else
    v_126 = cdr(v_125);
    v_125 = qvalue(basic_elt(env, 1)); // frlis!*
    v_125 = Lmemq(nil, v_126, v_125);
    if (v_125 == nil) goto v_27;
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_126 = cdrerror(v_125); else
    v_126 = cdr(v_125);
    v_125 = (LispObject)16+TAG_FIXNUM; // 1
    if (v_126 == v_125) goto v_38;
    else goto v_39;
v_38:
    v_125 = lisp_true;
    goto v_37;
v_39:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_127 = cdrerror(v_125); else
    v_127 = cdr(v_125);
    v_126 = stack[-3];
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    {   LispObject fn = basic_elt(env, 4); // powmtch
    v_125 = (*qfn3(fn))(fn, v_127, v_126, v_125);
    }
    env = stack[-4];
    stack[-3] = v_125;
    v_125 = (v_125 == nil ? lisp_true : nil);
    goto v_37;
    v_125 = nil;
v_37:
    if (v_125 == nil) goto v_35;
    v_125 = nil;
    goto v_9;
v_35:
    stack[0] = stack[-3];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_126 = cdrerror(v_125); else
    v_126 = cdr(v_125);
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    v_125 = cons(v_126, v_125);
    env = stack[-4];
    {
        LispObject v_132 = stack[0];
        LispObject fn = basic_elt(env, 5); // mapcons
        return (*qfn2(fn))(fn, v_132, v_125);
    }
    goto v_11;
v_27:
    v_125 = stack[0];
    if (v_125 == nil) goto v_65;
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_126 = cdrerror(v_125); else
    v_126 = cdr(v_125);
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (equal(v_126, v_125)) goto v_65;
    goto v_63;
v_65:
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (is_number(v_125)) goto v_77;
    v_125 = lisp_true;
    goto v_75;
v_77:
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    if (is_number(v_125)) goto v_86;
    v_125 = lisp_true;
    goto v_84;
v_86:
    v_125 = qvalue(basic_elt(env, 2)); // !*mcd
    if (v_125 == nil) goto v_95;
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_126 = cdrerror(v_125); else
    v_126 = cdr(v_125);
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    v_125 = (LispObject)lessp2(v_126, v_125);
    v_125 = v_125 ? lisp_true : nil;
    goto v_93;
v_95:
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_126 = cdrerror(v_125); else
    v_126 = cdr(v_125);
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    v_126 = times2(v_126, v_125);
    env = stack[-4];
    v_125 = (LispObject)0+TAG_FIXNUM; // 0
    v_125 = (LispObject)lessp2(v_126, v_125);
    v_125 = v_125 ? lisp_true : nil;
    env = stack[-4];
    if (v_125 == nil) goto v_106;
    else goto v_105;
v_106:
    v_125 = stack[-2];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    stack[0] = Labsval(nil, v_125);
    env = stack[-4];
    v_125 = stack[-1];
    if (!car_legal(v_125)) v_125 = cdrerror(v_125); else
    v_125 = cdr(v_125);
    v_125 = Labsval(nil, v_125);
    env = stack[-4];
    v_125 = (LispObject)lessp2(stack[0], v_125);
    v_125 = v_125 ? lisp_true : nil;
v_105:
    goto v_93;
    v_125 = nil;
v_93:
    goto v_84;
    v_125 = nil;
v_84:
    goto v_75;
    v_125 = nil;
v_75:
    if (v_125 == nil) goto v_73;
    else goto v_63;
v_73:
    goto v_64;
v_63:
    v_125 = nil;
    goto v_9;
v_64:
    v_125 = stack[-3];
    goto v_9;
v_11:
    v_125 = nil;
v_9:
    return onevalue(v_125);
}



// Code for tayexp!-greaterp

static LispObject CC_tayexpKgreaterp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_9 = v_3;
    v_8 = v_2;
// end of prologue
    {
        LispObject fn = basic_elt(env, 1); // tayexp!-lessp
        return (*qfn2(fn))(fn, v_9, v_8);
    }
}



// Code for get!+row!+nr

static LispObject CC_getLrowLnr(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_8 = v_2;
// end of prologue
        return Llength(nil, v_8);
    return onevalue(v_8);
}



// Code for rl_negateat

static LispObject CC_rl_negateat(LispObject env,
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
    stack[0] = qvalue(basic_elt(env, 1)); // rl_negateat!*
    v_8 = ncons(v_8);
    env = stack[-1];
    {
        LispObject v_10 = stack[0];
        LispObject fn = basic_elt(env, 2); // apply
        return (*qfn2(fn))(fn, v_10, v_8);
    }
}



// Code for kernels1

static LispObject CC_kernels1(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_49, v_50, v_51, v_52;
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
    v_51 = v_3;
    v_49 = v_2;
// end of prologue
v_1:
    v_50 = v_49;
    if (!consp(v_50)) goto v_11;
    else goto v_12;
v_11:
    v_50 = lisp_true;
    goto v_10;
v_12:
    v_50 = v_49;
    if (!car_legal(v_50)) v_50 = carerror(v_50); else
    v_50 = car(v_50);
    v_50 = (consp(v_50) ? nil : lisp_true);
    goto v_10;
    v_50 = nil;
v_10:
    if (v_50 == nil) goto v_8;
    v_49 = v_51;
    goto v_6;
v_8:
    v_50 = v_49;
    if (!car_legal(v_50)) v_50 = carerror(v_50); else
    v_50 = car(v_50);
    if (!car_legal(v_50)) v_50 = carerror(v_50); else
    v_50 = car(v_50);
    if (!car_legal(v_50)) v_50 = carerror(v_50); else
    v_50 = car(v_50);
    v_52 = v_50;
    v_50 = v_49;
    if (!car_legal(v_50)) v_50 = carerror(v_50); else
    v_50 = car(v_50);
    if (!car_legal(v_50)) stack[-2] = cdrerror(v_50); else
    stack[-2] = cdr(v_50);
    if (!car_legal(v_49)) stack[-1] = cdrerror(v_49); else
    stack[-1] = cdr(v_49);
    v_50 = v_52;
    v_49 = v_51;
    v_49 = Lmemq(nil, v_50, v_49);
    if (v_49 == nil) goto v_38;
    v_49 = v_51;
    goto v_36;
v_38:
    stack[0] = v_51;
    v_49 = v_52;
    v_49 = ncons(v_49);
    env = stack[-3];
    v_49 = Lappend_2(nil, stack[0], v_49);
    env = stack[-3];
    goto v_36;
    v_49 = nil;
v_36:
    v_50 = CC_kernels1(basic_elt(env, 0), stack[-1], v_49);
    env = stack[-3];
    v_49 = stack[-2];
    v_51 = v_50;
    goto v_1;
    v_49 = nil;
v_6:
    return onevalue(v_49);
}



// Code for addd

static LispObject CC_addd(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_43, v_44;
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
    v_44 = nil;
v_8:
    v_43 = stack[0];
    if (v_43 == nil) goto v_11;
    else goto v_12;
v_11:
    v_43 = stack[-1];
    {
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_44, v_43);
    }
v_12:
    v_43 = stack[0];
    if (!consp(v_43)) goto v_21;
    else goto v_22;
v_21:
    v_43 = lisp_true;
    goto v_20;
v_22:
    v_43 = stack[0];
    if (!car_legal(v_43)) v_43 = carerror(v_43); else
    v_43 = car(v_43);
    v_43 = (consp(v_43) ? nil : lisp_true);
    goto v_20;
    v_43 = nil;
v_20:
    if (v_43 == nil) goto v_18;
    stack[-2] = v_44;
    v_44 = stack[-1];
    v_43 = stack[0];
    {   LispObject fn = basic_elt(env, 2); // adddm
    v_43 = (*qfn2(fn))(fn, v_44, v_43);
    }
    env = stack[-3];
    {
        LispObject v_48 = stack[-2];
        LispObject fn = basic_elt(env, 1); // nreverse
        return (*qfn2(fn))(fn, v_48, v_43);
    }
v_18:
    v_43 = stack[0];
    if (!car_legal(v_43)) v_43 = carerror(v_43); else
    v_43 = car(v_43);
    v_43 = cons(v_43, v_44);
    env = stack[-3];
    v_44 = v_43;
    v_43 = stack[0];
    if (!car_legal(v_43)) v_43 = cdrerror(v_43); else
    v_43 = cdr(v_43);
    stack[0] = v_43;
    goto v_8;
    v_43 = nil;
    return onevalue(v_43);
}



// Code for compress!*

static LispObject CC_compressH(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_79, v_80, v_81, v_82;
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
    v_79 = v_2;
// end of prologue
    v_82 = nil;
    v_80 = v_79;
    if (!car_legal(v_80)) v_80 = carerror(v_80); else
    v_80 = car(v_80);
    v_80 = Ldigitp(nil, v_80);
    env = stack[-1];
    if (v_80 == nil) goto v_10;
        return Lcompress(nil, v_79);
v_10:
    stack[0] = v_79;
v_19:
    v_79 = stack[0];
    if (v_79 == nil) goto v_23;
    else goto v_24;
v_23:
    goto v_18;
v_24:
    v_79 = stack[0];
    if (!car_legal(v_79)) v_79 = carerror(v_79); else
    v_79 = car(v_79);
    v_81 = v_79;
    v_80 = v_81;
    v_79 = basic_elt(env, 1); // !/
    if (v_80 == v_79) goto v_36;
    else goto v_37;
v_36:
    v_79 = lisp_true;
    goto v_35;
v_37:
    v_80 = v_81;
    v_79 = basic_elt(env, 2); // !-
    if (v_80 == v_79) goto v_45;
    else goto v_46;
v_45:
    v_79 = lisp_true;
    goto v_44;
v_46:
    v_80 = v_81;
    v_79 = basic_elt(env, 3); // !;
    if (v_80 == v_79) goto v_54;
    else goto v_55;
v_54:
    v_79 = lisp_true;
    goto v_53;
v_55:
    v_80 = v_81;
    v_79 = basic_elt(env, 4); // !.
    v_79 = (v_80 == v_79 ? lisp_true : nil);
    goto v_53;
    v_79 = nil;
v_53:
    goto v_44;
    v_79 = nil;
v_44:
    goto v_35;
    v_79 = nil;
v_35:
    if (v_79 == nil) goto v_33;
    v_80 = v_81;
    v_79 = basic_elt(env, 5); // !!
    v_81 = v_82;
    v_79 = list2star(v_80, v_79, v_81);
    env = stack[-1];
    v_82 = v_79;
    goto v_31;
v_33:
    v_79 = v_81;
    v_80 = v_82;
    v_79 = cons(v_79, v_80);
    env = stack[-1];
    v_82 = v_79;
    goto v_31;
v_31:
    v_79 = stack[0];
    if (!car_legal(v_79)) v_79 = cdrerror(v_79); else
    v_79 = cdr(v_79);
    stack[0] = v_79;
    goto v_19;
v_18:
    v_79 = v_82;
    v_79 = Lnreverse(nil, v_79);
    env = stack[-1];
    v_79 = Lcompress(nil, v_79);
        return Lintern(nil, v_79);
    return onevalue(v_79);
}



// Code for noncomfp1

static LispObject CC_noncomfp1(LispObject env,
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
    v_40 = CC_noncomfp1(basic_elt(env, 0), v_40);
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



// Code for ldepends

static LispObject CC_ldepends(LispObject env,
                         LispObject v_2, LispObject v_3)
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
v_1:
    v_30 = stack[-1];
    if (v_30 == nil) goto v_7;
    else goto v_8;
v_7:
    v_30 = nil;
    goto v_6;
v_8:
    v_30 = stack[-1];
    if (!consp(v_30)) goto v_11;
    else goto v_12;
v_11:
    v_31 = stack[-1];
    v_30 = stack[0];
    {
        LispObject fn = basic_elt(env, 1); // depends
        return (*qfn2(fn))(fn, v_31, v_30);
    }
v_12:
    v_30 = stack[-1];
    if (!car_legal(v_30)) v_31 = carerror(v_30); else
    v_31 = car(v_30);
    v_30 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // depends
    v_30 = (*qfn2(fn))(fn, v_31, v_30);
    }
    env = stack[-2];
    if (v_30 == nil) goto v_21;
    else goto v_20;
v_21:
    v_30 = stack[-1];
    if (!car_legal(v_30)) v_31 = cdrerror(v_30); else
    v_31 = cdr(v_30);
    v_30 = stack[0];
    stack[-1] = v_31;
    stack[0] = v_30;
    goto v_1;
v_20:
    goto v_6;
    v_30 = nil;
v_6:
    return onevalue(v_30);
}



// Code for numlis

static LispObject CC_numlis(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_24, v_25;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_24 = v_2;
// end of prologue
v_1:
    v_25 = v_24;
    if (v_25 == nil) goto v_6;
    else goto v_7;
v_6:
    v_24 = lisp_true;
    goto v_5;
v_7:
    v_25 = v_24;
    if (!car_legal(v_25)) v_25 = carerror(v_25); else
    v_25 = car(v_25);
    if (is_number(v_25)) goto v_15;
    v_24 = nil;
    goto v_13;
v_15:
    if (!car_legal(v_24)) v_24 = cdrerror(v_24); else
    v_24 = cdr(v_24);
    goto v_1;
    v_24 = nil;
v_13:
    goto v_5;
    v_24 = nil;
v_5:
    return onevalue(v_24);
}



// Code for !:minusp

static LispObject CC_Tminusp(LispObject env,
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
    v_18 = v_2;
// end of prologue
    v_19 = v_18;
    if (!consp(v_19)) goto v_6;
    else goto v_7;
v_6:
        return Lminusp(nil, v_18);
v_7:
    v_19 = v_18;
    if (!car_legal(v_19)) v_19 = carerror(v_19); else
    v_19 = car(v_19);
    if (!symbolp(v_19)) v_19 = nil;
    else { v_19 = qfastgets(v_19);
           if (v_19 != nil) { v_19 = elt(v_19, 30); // minusp
#ifdef RECORD_GET
             if (v_19 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v_19 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v_19 == SPID_NOPROP) v_19 = nil; }}
#endif
        return Lapply1(nil, v_19, v_18);
    v_18 = nil;
    return onevalue(v_18);
}



// Code for evzero!?

static LispObject CC_evzeroW(LispObject env,
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



// Code for ordpp

static LispObject CC_ordpp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_49, v_50, v_51, v_52, v_53;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_51 = v_3;
    v_52 = v_2;
// end of prologue
    v_49 = v_52;
    if (!car_legal(v_49)) v_50 = carerror(v_49); else
    v_50 = car(v_49);
    v_49 = v_51;
    if (!car_legal(v_49)) v_49 = carerror(v_49); else
    v_49 = car(v_49);
    if (v_50 == v_49) goto v_11;
    else goto v_12;
v_11:
    v_49 = v_52;
    if (!car_legal(v_49)) v_49 = cdrerror(v_49); else
    v_49 = cdr(v_49);
    v_50 = v_51;
    if (!car_legal(v_50)) v_50 = cdrerror(v_50); else
    v_50 = cdr(v_50);
        return Lgreaterp_2(nil, v_49, v_50);
v_12:
    v_49 = qvalue(basic_elt(env, 1)); // kord!*
    v_53 = v_49;
    v_49 = v_52;
    if (!car_legal(v_49)) v_49 = carerror(v_49); else
    v_49 = car(v_49);
    v_52 = v_49;
    v_49 = v_51;
    if (!car_legal(v_49)) v_49 = carerror(v_49); else
    v_49 = car(v_49);
    v_51 = v_49;
v_8:
    v_49 = v_53;
    if (v_49 == nil) goto v_29;
    else goto v_30;
v_29:
    v_49 = v_52;
    v_50 = v_51;
    {
        LispObject fn = basic_elt(env, 2); // ordpa
        return (*qfn2(fn))(fn, v_49, v_50);
    }
v_30:
    v_50 = v_52;
    v_49 = v_53;
    if (!car_legal(v_49)) v_49 = carerror(v_49); else
    v_49 = car(v_49);
    if (v_50 == v_49) goto v_35;
    else goto v_36;
v_35:
    v_49 = lisp_true;
    goto v_7;
v_36:
    v_50 = v_51;
    v_49 = v_53;
    if (!car_legal(v_49)) v_49 = carerror(v_49); else
    v_49 = car(v_49);
    if (v_50 == v_49) goto v_41;
    else goto v_42;
v_41:
    v_49 = nil;
    goto v_7;
v_42:
    v_49 = v_53;
    if (!car_legal(v_49)) v_49 = cdrerror(v_49); else
    v_49 = cdr(v_49);
    v_53 = v_49;
    goto v_8;
v_7:
    return onevalue(v_49);
}



// Code for factorordp

static LispObject CC_factorordp(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_17, v_18, v_19, v_20;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_19 = v_3;
    v_20 = v_2;
// end of prologue
    v_18 = v_20;
    v_17 = v_19;
    if (v_18 == v_17) goto v_7;
    else goto v_8;
v_7:
    v_17 = nil;
    goto v_6;
v_8:
    v_17 = v_20;
    v_18 = v_19;
    {
        LispObject fn = basic_elt(env, 1); // worderp
        return (*qfn2(fn))(fn, v_17, v_18);
    }
    v_17 = nil;
v_6:
    return onevalue(v_17);
}



// Code for csl_normbf

static LispObject CC_csl_normbf(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_52, v_53, v_54;
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
    stack[-2] = v_2;
// end of prologue
    stack[-3] = nil;
    v_52 = stack[-2];
    if (!car_legal(v_52)) v_52 = cdrerror(v_52); else
    v_52 = cdr(v_52);
    if (!car_legal(v_52)) v_53 = carerror(v_52); else
    v_53 = car(v_52);
    stack[0] = v_53;
    v_52 = (LispObject)0+TAG_FIXNUM; // 0
    if (v_53 == v_52) goto v_12;
    else goto v_13;
v_12:
    v_52 = basic_elt(env, 1); // (!:rd!: 0 . 0)
    goto v_8;
v_13:
    v_53 = stack[0];
    v_52 = (LispObject)0+TAG_FIXNUM; // 0
    v_52 = (LispObject)lessp2(v_53, v_52);
    v_52 = v_52 ? lisp_true : nil;
    env = stack[-4];
    if (v_52 == nil) goto v_22;
    v_52 = stack[0];
    v_52 = negate(v_52);
    env = stack[-4];
    stack[0] = v_52;
    v_52 = lisp_true;
    stack[-3] = v_52;
    goto v_20;
v_22:
v_20:
    v_52 = stack[0];
    {   LispObject fn = basic_elt(env, 3); // lsd
    v_52 = (*qfn1(fn))(fn, v_52);
    }
    env = stack[-4];
    v_52 = sub1(v_52);
    env = stack[-4];
    stack[-1] = v_52;
    v_52 = stack[-1];
    v_52 = negate(v_52);
    env = stack[-4];
    {   LispObject fn = basic_elt(env, 4); // lshift
    v_52 = (*qfn2(fn))(fn, stack[0], v_52);
    }
    env = stack[-4];
    stack[0] = v_52;
    v_52 = stack[-3];
    if (v_52 == nil) goto v_39;
    v_52 = stack[0];
    v_52 = negate(v_52);
    env = stack[-4];
    stack[0] = v_52;
    goto v_37;
v_39:
v_37:
    v_53 = stack[-1];
    v_52 = stack[-2];
    if (!car_legal(v_52)) v_52 = cdrerror(v_52); else
    v_52 = cdr(v_52);
    if (!car_legal(v_52)) v_52 = cdrerror(v_52); else
    v_52 = cdr(v_52);
    v_52 = plus2(v_53, v_52);
    env = stack[-4];
    stack[-1] = v_52;
    v_54 = basic_elt(env, 2); // !:rd!:
    v_53 = stack[0];
    v_52 = stack[-1];
    return list2star(v_54, v_53, v_52);
v_8:
    return onevalue(v_52);
}



// Code for degr

static LispObject CC_degr(LispObject env,
                         LispObject v_2, LispObject v_3)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_41, v_42, v_43;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_41 = v_3;
    v_42 = v_2;
// end of prologue
    v_43 = v_42;
    if (!consp(v_43)) goto v_15;
    else goto v_16;
v_15:
    v_43 = lisp_true;
    goto v_14;
v_16:
    v_43 = v_42;
    if (!car_legal(v_43)) v_43 = carerror(v_43); else
    v_43 = car(v_43);
    v_43 = (consp(v_43) ? nil : lisp_true);
    goto v_14;
    v_43 = nil;
v_14:
    if (v_43 == nil) goto v_12;
    v_41 = lisp_true;
    goto v_10;
v_12:
    v_43 = v_42;
    if (!car_legal(v_43)) v_43 = carerror(v_43); else
    v_43 = car(v_43);
    if (!car_legal(v_43)) v_43 = carerror(v_43); else
    v_43 = car(v_43);
    if (!car_legal(v_43)) v_43 = carerror(v_43); else
    v_43 = car(v_43);
    v_41 = (v_43 == v_41 ? lisp_true : nil);
    v_41 = (v_41 == nil ? lisp_true : nil);
    goto v_10;
    v_41 = nil;
v_10:
    if (v_41 == nil) goto v_8;
    v_41 = (LispObject)0+TAG_FIXNUM; // 0
    goto v_6;
v_8:
    v_41 = v_42;
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = car(v_41);
    if (!car_legal(v_41)) v_41 = carerror(v_41); else
    v_41 = car(v_41);
    if (!car_legal(v_41)) v_41 = cdrerror(v_41); else
    v_41 = cdr(v_41);
    goto v_6;
    v_41 = nil;
v_6:
    return onevalue(v_41);
}



// Code for mkround

static LispObject CC_mkround(LispObject env,
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
    v_15 = v_16;
    if (!consp(v_15)) goto v_6;
    else goto v_7;
v_6:
    v_15 = basic_elt(env, 1); // !:rd!:
    return cons(v_15, v_16);
v_7:
    v_15 = v_16;
    goto v_5;
    v_15 = nil;
v_5:
    return onevalue(v_15);
}



// Code for collectindices

static LispObject CC_collectindices(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_8, v_9;
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
    v_8 = v_2;
// end of prologue
    v_9 = v_8;
    v_8 = nil;
    {   LispObject fn = basic_elt(env, 1); // collectindices_reversed
    v_8 = (*qfn2(fn))(fn, v_9, v_8);
    }
        return Lnreverse(nil, v_8);
}



// Code for union_edge

static LispObject CC_union_edge(LispObject env,
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
    push2(nil, nil);
    stack_popper stack_popper_var(3);
// copy arguments values to proper place
    stack[0] = v_3;
    stack[-1] = v_2;
// end of prologue
    v_19 = stack[-1];
    v_18 = stack[0];
    {   LispObject fn = basic_elt(env, 1); // memq_edgelist
    v_18 = (*qfn2(fn))(fn, v_19, v_18);
    }
    if (v_18 == nil) goto v_8;
    v_18 = stack[0];
    goto v_6;
v_8:
    v_19 = stack[-1];
    v_18 = stack[0];
    return cons(v_19, v_18);
    v_18 = nil;
v_6:
    return onevalue(v_18);
}



// Code for ring_ecart

static LispObject CC_ring_ecart(LispObject env,
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
    v_8 = v_7;
    v_7 = (LispObject)80+TAG_FIXNUM; // 5
    {
        LispObject fn = basic_elt(env, 1); // nth
        return (*qfn2(fn))(fn, v_8, v_7);
    }
}



// Code for mtp

static LispObject CC_mtp(LispObject env,
                         LispObject v_2)
{
    env = qenv(env);
#if 0 // Start of trace output
#endif // End of trace output
    LispObject v_38, v_39, v_40;
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v_39 = v_2;
// end of prologue
v_1:
    v_38 = v_39;
    if (v_38 == nil) goto v_6;
    else goto v_7;
v_6:
    v_38 = lisp_true;
    goto v_5;
v_7:
    v_38 = v_39;
    if (!car_legal(v_38)) v_40 = carerror(v_38); else
    v_40 = car(v_38);
    v_38 = qvalue(basic_elt(env, 1)); // frlis!*
    v_38 = Lmemq(nil, v_40, v_38);
    if (v_38 == nil) goto v_14;
    else goto v_15;
v_14:
    v_38 = nil;
    goto v_13;
v_15:
    v_38 = v_39;
    if (!car_legal(v_38)) v_40 = carerror(v_38); else
    v_40 = car(v_38);
    v_38 = v_39;
    if (!car_legal(v_38)) v_38 = cdrerror(v_38); else
    v_38 = cdr(v_38);
    v_38 = Lmember(nil, v_40, v_38);
    if (v_38 == nil) goto v_25;
    else goto v_26;
v_25:
    v_38 = v_39;
    if (!car_legal(v_38)) v_38 = cdrerror(v_38); else
    v_38 = cdr(v_38);
    v_39 = v_38;
    goto v_1;
v_26:
    v_38 = nil;
    goto v_24;
    v_38 = nil;
v_24:
    goto v_13;
    v_38 = nil;
v_13:
    goto v_5;
    v_38 = nil;
v_5:
    return onevalue(v_38);
}



setup_type const u01_setup[] =
{
    {"smember",                 G0W2,     G1W2,     CC_smember,G3W2,    G4W2},
    {"*n2f",                    G0W1,     CC_Hn2f,  G2W1,     G3W1,     G4W1},
    {"setdiff",                 G0W2,     G1W2,     CC_setdiff,G3W2,    G4W2},
    {"terminalp",               CC_terminalp,G1W0,  G2W0,     G3W0,     G4W0},
    {"multf",                   G0W2,     G1W2,     CC_multf, G3W2,     G4W2},
    {"monomgetvariabledegree",  G0W2,     G1W2,     CC_monomgetvariabledegree,G3W2,G4W2},
    {"quotelist",               G0W1,     CC_quotelist,G2W1,  G3W1,     G4W1},
    {"num-exponents",           G0W1,     CC_numKexponents,G2W1,G3W1,   G4W1},
    {"simpcar",                 G0W1,     CC_simpcar,G2W1,    G3W1,     G4W1},
    {"wuconstantp",             G0W1,     CC_wuconstantp,G2W1,G3W1,     G4W1},
    {"mkcopy",                  G0W1,     CC_mkcopy,G2W1,     G3W1,     G4W1},
    {"mchkopt",                 G0W2,     G1W2,     CC_mchkopt,G3W2,    G4W2},
    {"revpr",                   G0W1,     CC_revpr, G2W1,     G3W1,     G4W1},
    {"nth",                     G0W2,     G1W2,     CC_nth,   G3W2,     G4W2},
    {"talp_getl",               CC_talp_getl,G1W0,  G2W0,     G3W0,     G4W0},
    {"kernels",                 G0W1,     CC_kernels,G2W1,    G3W1,     G4W1},
    {"qqe_rqopp",               G0W1,     CC_qqe_rqopp,G2W1,  G3W1,     G4W1},
    {"lto_hashid",              G0W1,     CC_lto_hashid,G2W1, G3W1,     G4W1},
    {"noncomfp",                G0W1,     CC_noncomfp,G2W1,   G3W1,     G4W1},
    {"delall",                  G0W2,     G1W2,     CC_delall,G3W2,     G4W2},
    {"ordop",                   G0W2,     G1W2,     CC_ordop, G3W2,     G4W2},
    {"prepf",                   G0W1,     CC_prepf, G2W1,     G3W1,     G4W1},
    {"c:ordxp",                 G0W2,     G1W2,     CC_cTordxp,G3W2,    G4W2},
    {"zero2nil",                G0W1,     CC_zero2nil,G2W1,   G3W1,     G4W1},
    {"ordad",                   G0W2,     G1W2,     CC_ordad, G3W2,     G4W2},
    {"mval",                    G0W1,     CC_mval,  G2W1,     G3W1,     G4W1},
    {"reval",                   G0W1,     CC_reval, G2W1,     G3W1,     G4W1},
    {"evcomp",                  G0W2,     G1W2,     CC_evcomp,G3W2,     G4W2},
    {"evmatrixcomp2",           G0W3,     G1W3,     G2W3,     CC_evmatrixcomp2,G4W3},
    {"xval",                    G0W1,     CC_xval,  G2W1,     G3W1,     G4W1},
    {"times:",                  G0W2,     G1W2,     CC_timesT,G3W2,     G4W2},
    {"convprec",                G0W1,     CC_convprec,G2W1,   G3W1,     G4W1},
    {"mkvar",                   G0W2,     G1W2,     CC_mkvar, G3W2,     G4W2},
    {"physopp",                 G0W1,     CC_physopp,G2W1,    G3W1,     G4W1},
    {"memq_edgelist",           G0W2,     G1W2,     CC_memq_edgelist,G3W2,G4W2},
    {"mo_comp",                 G0W1,     CC_mo_comp,G2W1,    G3W1,     G4W1},
    {"c_zero",                  CC_c_zero,G1W0,     G2W0,     G3W0,     G4W0},
    {"sieve_pv0",               G0W3,     G1W3,     G2W3,     CC_sieve_pv0,G4W3},
    {"listp",                   G0W1,     CC_listp, G2W1,     G3W1,     G4W1},
    {"modzerop:",               G0W1,     CC_modzeropT,G2W1,  G3W1,     G4W1},
    {"getrtypeor",              G0W1,     CC_getrtypeor,G2W1, G3W1,     G4W1},
    {"lalr_productions",        G0W1,     CC_lalr_productions,G2W1,G3W1,G4W1},
    {"random_new_seed",         G0W1,     CC_random_new_seed,G2W1,G3W1, G4W1},
    {"monomcompare",            G0W2,     G1W2,     CC_monomcompare,G3W2,G4W2},
    {"makelist",                G0W1,     CC_makelist,G2W1,   G3W1,     G4W1},
    {"quotf",                   G0W2,     G1W2,     CC_quotf, G3W2,     G4W2},
    {"mchk*",                   G0W2,     G1W2,     CC_mchkH, G3W2,     G4W2},
    {"get+mat+entry",           G0W3,     G1W3,     G2W3,     CC_getLmatLentry,G4W3},
    {"talp_getextl",            CC_talp_getextl,G1W0,G2W0,    G3W0,     G4W0},
    {"powers",                  G0W1,     CC_powers,G2W1,     G3W1,     G4W1},
    {"ibalp_clmember",          G0W2,     G1W2,     CC_ibalp_clmember,G3W2,G4W2},
    {"find2",                   G0W2,     G1W2,     CC_find2, G3W2,     G4W2},
    {"noncomp",                 G0W1,     CC_noncomp,G2W1,    G3W1,     G4W1},
    {"prepf1a",                 G0W2,     G1W2,     CC_prepf1a,G3W2,    G4W2},
    {"subs3f",                  G0W1,     CC_subs3f,G2W1,     G3W1,     G4W1},
    {"pm:free",                 G0W1,     CC_pmTfree,G2W1,    G3W1,     G4W1},
    {"vbcsize",                 G0W2,     G1W2,     CC_vbcsize,G3W2,    G4W2},
    {"pnth",                    G0W2,     G1W2,     CC_pnth,  G3W2,     G4W2},
    {"wedgefax",                G0W1,     CC_wedgefax,G2W1,   G3W1,     G4W1},
    {"*physopp",                G0W1,     CC_Hphysopp,G2W1,   G3W1,     G4W1},
    {"argsofopr",               G0W1,     CC_argsofopr,G2W1,  G3W1,     G4W1},
    {"wideid2list",             G0W1,     CC_wideid2list,G2W1,G3W1,     G4W1},
    {"termsf",                  G0W1,     CC_termsf,G2W1,     G3W1,     G4W1},
    {"mkspm",                   G0W2,     G1W2,     CC_mkspm, G3W2,     G4W2},
    {"dssoc",                   G0W2,     G1W2,     CC_dssoc, G3W2,     G4W2},
    {"noncomlistp",             G0W1,     CC_noncomlistp,G2W1,G3W1,     G4W1},
    {"rnzerop:",                G0W1,     CC_rnzeropT,G2W1,   G3W1,     G4W1},
    {"mksp",                    G0W2,     G1W2,     CC_mksp,  G3W2,     G4W2},
    {"aeval",                   G0W1,     CC_aeval, G2W1,     G3W1,     G4W1},
    {"lalr_first",              G0W1,     CC_lalr_first,G2W1, G3W1,     G4W1},
    {"aex_ex",                  G0W1,     CC_aex_ex,G2W1,     G3W1,     G4W1},
    {"addcomment",              G0W1,     CC_addcomment,G2W1, G3W1,     G4W1},
    {"arrayp",                  G0W1,     CC_arrayp,G2W1,     G3W1,     G4W1},
    {"cl_cflip",                G0W2,     G1W2,     CC_cl_cflip,G3W2,   G4W2},
    {"kernlp",                  G0W1,     CC_kernlp,G2W1,     G3W1,     G4W1},
    {"talp_invp",               G0W1,     CC_talp_invp,G2W1,  G3W1,     G4W1},
    {"qqe_rbopp",               G0W1,     CC_qqe_rbopp,G2W1,  G3W1,     G4W1},
    {"lto_hashequalq",          G0W2,     G1W2,     CC_lto_hashequalq,G3W2,G4W2},
    {"sub2chk",                 G0W1,     CC_sub2chk,G2W1,    G3W1,     G4W1},
    {"butes",                   G0W1,     CC_butes, G2W1,     G3W1,     G4W1},
    {"exchk",                   G0W1,     CC_exchk, G2W1,     G3W1,     G4W1},
    {"expchk",                  G0W1,     CC_expchk,G2W1,     G3W1,     G4W1},
    {"dm-abs",                  G0W1,     CC_dmKabs,G2W1,     G3W1,     G4W1},
    {"binding",                 G0W1,     CC_binding,G2W1,    G3W1,     G4W1},
    {"evlexcomp",               G0W2,     G1W2,     CC_evlexcomp,G3W2,  G4W2},
    {"sc_getmat",               G0W3,     G1W3,     G2W3,     CC_sc_getmat,G4W3},
    {"getrtypecar",             G0W1,     CC_getrtypecar,G2W1,G3W1,     G4W1},
    {"round*",                  G0W1,     CC_roundH,G2W1,     G3W1,     G4W1},
    {"isanindex",               G0W1,     CC_isanindex,G2W1,  G3W1,     G4W1},
    {"poly-multf",              G0W2,     G1W2,     CC_polyKmultf,G3W2, G4W2},
    {"mo_divides?",             G0W2,     G1W2,     CC_mo_dividesW,G3W2,G4W2},
    {"dlesslex",                G0W2,     G1W2,     CC_dlesslex,G3W2,   G4W2},
    {"hasonevector",            G0W1,     CC_hasonevector,G2W1,G3W1,    G4W1},
    {"reduce_pv0",              G0W3,     G1W3,     G2W3,     CC_reduce_pv0,G4W3},
    {"modonep:",                G0W1,     CC_modonepT,G2W1,   G3W1,     G4W1},
    {"remainder-in-vector",     G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_remainderKinKvector},
    {"smemql",                  G0W2,     G1W2,     CC_smemql,G3W2,     G4W2},
    {"multd",                   G0W2,     G1W2,     CC_multd, G3W2,     G4W2},
    {"lalr_add_lookahead",      G0W2,     G1W2,     CC_lalr_add_lookahead,G3W2,G4W2},
    {"setkorder",               G0W1,     CC_setkorder,G2W1,  G3W1,     G4W1},
    {"minusf",                  G0W1,     CC_minusf,G2W1,     G3W1,     G4W1},
    {"mtchp1",                  G0W4up,   G1W4up,   G2W4up,   G3W4up,   CC_mtchp1},
    {"tayexp-greaterp",         G0W2,     G1W2,     CC_tayexpKgreaterp,G3W2,G4W2},
    {"get+row+nr",              G0W1,     CC_getLrowLnr,G2W1, G3W1,     G4W1},
    {"rl_negateat",             G0W1,     CC_rl_negateat,G2W1,G3W1,     G4W1},
    {"kernels1",                G0W2,     G1W2,     CC_kernels1,G3W2,   G4W2},
    {"addd",                    G0W2,     G1W2,     CC_addd,  G3W2,     G4W2},
    {"compress*",               G0W1,     CC_compressH,G2W1,  G3W1,     G4W1},
    {"noncomfp1",               G0W1,     CC_noncomfp1,G2W1,  G3W1,     G4W1},
    {"ldepends",                G0W2,     G1W2,     CC_ldepends,G3W2,   G4W2},
    {"numlis",                  G0W1,     CC_numlis,G2W1,     G3W1,     G4W1},
    {":minusp",                 G0W1,     CC_Tminusp,G2W1,    G3W1,     G4W1},
    {"evzero?",                 G0W1,     CC_evzeroW,G2W1,    G3W1,     G4W1},
    {"ordpp",                   G0W2,     G1W2,     CC_ordpp, G3W2,     G4W2},
    {"factorordp",              G0W2,     G1W2,     CC_factorordp,G3W2, G4W2},
    {"csl_normbf",              G0W1,     CC_csl_normbf,G2W1, G3W1,     G4W1},
    {"degr",                    G0W2,     G1W2,     CC_degr,  G3W2,     G4W2},
    {"mkround",                 G0W1,     CC_mkround,G2W1,    G3W1,     G4W1},
    {"collectindices",          G0W1,     CC_collectindices,G2W1,G3W1,  G4W1},
    {"union_edge",              G0W2,     G1W2,     CC_union_edge,G3W2, G4W2},
    {"ring_ecart",              G0W1,     CC_ring_ecart,G2W1, G3W1,     G4W1},
    {"mtp",                     G0W1,     CC_mtp,   G2W1,     G3W1,     G4W1},
    {NULL, (no_args *)"u01", (one_arg *)"86207 7675160 3879041",
        NULL, NULL, NULL}
};

// end of generated code
