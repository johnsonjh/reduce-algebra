// allocate.cpp                            Copyright (C) 1989-2019 Codemist

//
// Code to deal with storage allocation, both grabbing memory at the start
// or a run and significant aspects of garbage collection.
//

/**************************************************************************
 * Copyright (C) 2019, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$

/*!!! csl
*/

#include "headers.h"

#ifdef WIN32
#include <windows.h>
#else // !WIN32
#include <unistd.h>
#include <sys/mman.h>
#endif // !WIN32

LispObject fringe, heaplimit;
LispObject vfringe, vheaplimit;
uintptr_t *C_stackbase;


void garbage_collect()
{   term_printf("\nGarbage collect here. Not yet implemented\n");
    my_abort();
}

char *big_chunk_start, *big_chunk_end;

// the "pages" considered here are of size CSL_PAGE_SIZE

void **pages,
     **heap_pages,
     **vheap_pages;
void **new_heap_pages,
     **new_vheap_pages;

size_t pages_count,
       heap_pages_count,
       vheap_pages_count,
       new_heap_pages_count,
       new_vheap_pages_count;

void *allocate_page(const char *why)
{   if (pages_count == 0) fatal_error(err_no_store);
    return pages[--pages_count];
}

void init_heap_segments(double store_size)
//
// This function just makes nil and the pool of page-frames available.
// The store-size is passed in units of Kilobyte, and as a double not
// an integer so that overflow is not an issue.
//
{   pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    new_heap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    new_vheap_pages = (void **)malloc(MAX_PAGES*sizeof(void *));
    if (pages == NULL ||
        new_heap_pages == NULL ||
        new_vheap_pages == NULL ||
        heap_pages == NULL ||
        vheap_pages == NULL)
    {   fatal_error(err_no_store);
    }

    {   size_t free_space = SIXTY_FOUR_BIT ? 128000000 : 32000000;
        size_t request = (size_t)store_size;
// By doing this in size_t I should avoid overflow
        if (request != 0) free_space = 1024*request;
        free_space = free_space/(CSL_PAGE_SIZE+4);
        if (free_space > MAX_PAGES) free_space = MAX_PAGES;
        pages_count = heap_pages_count = vheap_pages_count = 0;
        nilsegment = NULL;
        {   size_t n = (size_t)(NIL_SEGMENT_SIZE+free_space*CSL_PAGE_SIZE);
//
// I try to get the whole of the initial hunk of memory that I need in
// one gulp since that (maybe) gives me the best chance to obtain all
// the memory in just one half of my address space.
//
            char *pool = (char *)malloc(n);
            if (pool != NULL)
            {   big_chunk_start = (char *)pool;
                big_chunk_end = big_chunk_start + (n-1);
                nilsegment = (LispObject *)pool;
                pool = pool + NIL_SEGMENT_SIZE;
#ifdef COMMON
// NB here that NIL is tagged as a CONS not as a symbol
                nil = (LispObject)((uintptr_t)nilsegment + TAG_CONS + 8);
#else
                nil = (LispObject)((uintptr_t)nilsegment + TAG_SYMBOL);
#endif
// If at the end of the run I am going to free some space I had better not
// free these pages. When I free the nilsegment they all get discarded at
// once.
                while (pages_count < free_space)
                {   void *page =
// Ha Ha - for some long while I had a bug whereby I missed out the cast
// to size_t here and as a result if you asked for over 4G of memory
// there was an integer overflow in the subscript calculation leading to
// reasonably obscure disaster.
                        (void *)&pool[pages_count*
                                      (size_t)CSL_PAGE_SIZE];
                    pages[pages_count++] = page;
                }
            }
        }
    }

// If the user had asked for an oversize stack it has to be allocated
// independently here anyway.
    if (nilsegment != NULL && pages_count > 0)
    {   if (stack_segsize != 1)
        {   stacksegment =
                (LispObject *)aligned_malloc(stack_segsize*CSL_PAGE_SIZE);
            if (stacksegment == NULL) fatal_error(err_no_store);
        }
        else stacksegment = (LispObject *)pages[--pages_count];
    }
    else
    {   printf("pages_count <= 0 = %d\n", (int)pages_count);
        fatal_error(err_no_store);
    }
    stackbase = (LispObject *)stacksegment;
}

inline bool is_in_big_chunk(void *p)
{   return ((char *)p >= big_chunk_start &&
            (char *)p <= big_chunk_end);
}

static void abandon(void *p[], int32_t n)
{   while (n != 0)
    {   void *w = p[--n];
// The test here that avoids calling free on a NULL pointer is
// certainly not needed with an ANSI compliant library - but
// rumour has it that many Unix libraries are unkind in this
// respect, and the test is pretty cheap... Also pages within the
// "big chunk" should not be released this way because they will
// all be recycled in one go when the whole chunk is freed. Note that
// the whole of the "big chunk" tends to get allocated as part of the
// segment that contans nil.
        if (w != NULL && !is_in_big_chunk(w)) aligned_free(w);
    }
}

void drop_heap_segments(void)
{   abandon(pages,           pages_count);
    abandon(heap_pages,      heap_pages_count);
    abandon(vheap_pages,     vheap_pages_count);
    if (!is_in_big_chunk(stacksegment)) free(stacksegmentbase);
    free(nilsegmentbase);
}

// This allocates another page of memory if that is allowed and if it is
// possible. It returns true on success.

bool allocate_more_memory()
{   if ((init_flags & INIT_EXPANDABLE) == 0) return false;
    void *page = (void *)malloc((size_t)CSL_PAGE_SIZE);
    if (page == NULL)
    {   init_flags &= ~INIT_EXPANDABLE;
        return false;
    }
    else
    {   pages[pages_count++] = page;
        return true;
    }
}

void grab_more_memory(size_t npages)
{
// Here I grab more memory (if I am allowed to).
// An initial version here, and one still suitable on machines that will
// have plenty of real memory, will be to defined ok_to_grab_memory(n) as
// 3*n + 2. This expands until the proportion of the heap active at the
// end of garbage collection is less than 1/4.
// If the attempt to grab more memory fails I clear the bit in init_flags
// that allows me to try to expand, so I will not waste time again.  If
// HOLD_BACK_MEMORY was asserted (for machines where grabbing all seemingly
// available memory may cause a crash) I do not try this operation.  The
// aim of keeping the heap less than half full is an heuristic and could be
// adjusted on the basis of experience with this code.
// On systems where it is possible to measure the amount of available
// real memory more sophisticated calculations may be possible.
    if (init_flags & INIT_EXPANDABLE)
    {   size_t ideal = ok_to_grab_memory(heap_pages_count + vheap_pages_count);
        size_t more;
        if (ideal > MAX_PAGES) ideal = MAX_PAGES;
        if (max_store_size != 0.0)
        {   double page_limit = max_store_size*1024*1024/(double)CSL_PAGE_SIZE;
// Limit memory to (about) the amount the user indicated with --max-mem
            size_t plim = (size_t)page_limit;
            if (ideal > plim) ideal = plim;
        }
        if (ideal > pages_count)
        {   more = ideal - pages_count;
            while (more > 0)
            {   if (!allocate_more_memory()) break;
                more--;
            }
        }
    }
}


/*****************************************************************************/
//      Storage allocation.
/*****************************************************************************/

// gc-forcer(a, b) should arrange that a garbage collection is triggered
// when at most A cons-sized units of consing happens or when at most
// B units of space is used for vectors (where vectors include bignums and
// boxed floats). This is intended to be used to trigger garbage collection
// with rather fine control over when it happens to help with debugging
// storage management issues.

bool next_gc_is_hard = false;
uint64_t force_cons=0, force_vec = 0;

LispObject Lgc_forcer(LispObject env, LispObject a, LispObject b)
{   if (force_cons != 0 || force_vec != 0)
        trace_printf("Remaining CONS : %" PRIu64 " VEC : %" PRIu64 "\n",
            force_cons, force_vec);
// If you pass a non-fixnum then that leaves the trigger-point unchanged.
    if (is_fixnum(a)) force_cons = (uint64_t)sixty_four_bits(a);
    if (is_fixnum(b)) force_vec = (uint64_t)sixty_four_bits(b);
    return onevalue(nil);
}

LispObject Lgc_forcer1(LispObject env, LispObject a)
{   return Lgc_forcer(env, a, a);
}

LispObject cons(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal cons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject cons_no_gc(LispObject a, LispObject b)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

// cons_gc_test() MUST be called after any sequence of cons_no_gc() calls.

LispObject cons_gc_test(LispObject p)
{   if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)fringe <= (char *)heaplimit)
        return reclaim(p, "cons gc test", GC_CONS, 0);
    else return p;
}

LispObject ncons(LispObject a)
{   LispObject r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal ncons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2(LispObject a, LispObject b)
{
// Note that building two cons cells at once saves some overhead here
    LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2star(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list2starrev(LispObject c, LispObject b, LispObject a)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) = c;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list2*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3star(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = d;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3*", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list4(LispObject a, LispObject b, LispObject c, LispObject d)
{   LispObject r = (LispObject)((char *)fringe - 4*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 3*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r +3*sizeof(Cons_Cell)) = d;
    qcdr((char *)r + 3*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(4))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list4", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}



LispObject acons(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(2))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal acons", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject acons_no_gc(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 2*sizeof(Cons_Cell));
    qcar(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcdr(r) = c;
    qcar((char *)r+sizeof(Cons_Cell)) = a;
    qcdr((char *)r+sizeof(Cons_Cell)) = b;
    fringe = r;
    return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3(LispObject a, LispObject b, LispObject c)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject list3rev(LispObject c, LispObject b, LispObject a)
{   LispObject r = (LispObject)((char *)fringe - 3*sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = (LispObject)((char *)r + sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+sizeof(Cons_Cell)) = b;
    qcdr((char *)r+sizeof(Cons_Cell)) =
        (LispObject)((char *)r + 2*sizeof(Cons_Cell) + TAG_CONS);
    qcar((char *)r+2*sizeof(Cons_Cell)) = c;
    qcdr((char *)r+2*sizeof(Cons_Cell)) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(3))
        return reclaim((LispObject)((char *)r + TAG_CONS),
                       "internal list3", GC_CONS, 0);
    else return (LispObject)((char *)r + TAG_CONS);
}

LispObject Lcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = b;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "cons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lxcons(LispObject, LispObject a, LispObject b)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = b;
    qcdr(r) = a;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "xcons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject Lnilfn(LispObject)
{   return onevalue(nil);
}

LispObject Lncons(LispObject env, LispObject a)
{   LispObject r;
    r = (LispObject)((char *)fringe - sizeof(Cons_Cell));
    qcar(r) = a;
    qcdr(r) = nil;
    fringe = r;
    if (++reclaim_trigger_count == reclaim_trigger_target ||
        (char *)r <= (char *)heaplimit || cons_forced(1))
        return onevalue(reclaim((LispObject)((char *)r + TAG_CONS),
                                "ncons", GC_CONS, 0));
    else return onevalue((LispObject)((char *)r + TAG_CONS));
}

LispObject get_symbol(bool gensymp)
{   return get_basic_vector(TAG_SYMBOL, TYPE_SYMBOL, symhdr_length);
}

LispObject get_basic_vector(int tag, int type, size_t size)
{
// tag is the value (e.g. TAG_VECTOR) that will go in the low order
// 3 bits of the pointer result.
// type is the code (e.g. TYPE_STRING) that gets packed, together with
// the size, into a header word.
// size is measured in bytes and must allow space for the header word.
// [Note that this last issue - size including the header - was probably
// a mistake since the header size depends on whether I am using a
// 32-bit or 64-bit representation. However it would be hard to unwind
// that now!]
//
    for (;;)
    {   char *r = (char *)vfringe;
        size_t free = (size_t)((char *)vheaplimit - r);
        size_t alloc_size = (size_t)doubleword_align_up(size);
// Basic vectors must be smaller then the CSL page size.
        if (alloc_size > (CSL_PAGE_SIZE - 32))
            aerror1("request for basic vector too big",
                    fixnum_of_int(alloc_size/CELL-1));
        if (++reclaim_trigger_count == reclaim_trigger_target ||
            alloc_size > free || vec_forced(alloc_size/CELL))
        {   char msg[40];
//
// I go to a whole load of trouble here to tell the user what sort of
// vector request provoked this garbage collection.  I wonder if the user
// really cares - but I do very much when I am chasing after GC bugs!
//
            switch (tag)
            {   case TAG_SYMBOL:
                    sprintf(msg, "symbol header");
                    break;
                case TAG_NUMBERS:
                    switch (type)
                    {   case TYPE_BIGNUM:
                            sprintf(msg, "bignum(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "numbers(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_VECTOR:
                    switch (type)
                    {
                        case TYPE_STRING_1:
                        case TYPE_STRING_2:
                        case TYPE_STRING_3:
                        case TYPE_STRING_4:
                            sprintf(msg, "string(%ld)", (long)size);
                            break;
                        case TYPE_BPS_1:
                        case TYPE_BPS_2:
                        case TYPE_BPS_3:
                        case TYPE_BPS_4:
                            sprintf(msg, "BPS(%ld)", (long)size);
                            break;
                        case TYPE_SIMPLE_VEC:
                            sprintf(msg, "simple vector(%ld)", (long)size);
                            break;
                        case TYPE_HASH:
                            sprintf(msg, "hash table(%ld)", (long)size);
                            break;
                        default:
                            sprintf(msg, "vector(%lx,%ld)", (long)type, (long)size);
                            break;
                    }
                    break;
                case TAG_BOXFLOAT:
                    sprintf(msg, "float(%ld)", (long)size);
                    break;
                default:
                    sprintf(msg, "get_basic_vector(%lx,%ld)", (long)tag, (long)size);
                    break;
            }
            reclaim(nil, msg, GC_VEC, alloc_size);
// Note the CONTINUE here so that I go and repeat the test. Consider the
// case where I have a page almost full but then garbage collection recovers
// a lof of space but still leaves the final used page almost full... I
// need the garbage collector to take care with its final argument to be
// certain that the loop here terminates!
            continue;
        }
        vfringe = (LispObject)(r + alloc_size);
        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
//
// DANGER: the vector allocated here is left uninitialised at this stage.
// This is OK if the vector will contain binary information, but if it
// will hold any LispObjects it needs safe values put in PDQ.
//
// All vectors are allocated so as to be 8-byte aligned. On a 64-bit system
// a vector that will not end up being a multipe of 8 bytes long naturally
// gets padded out. Here I arrange to zero out any such padder word. This
// should not be very important since nobody should ever try to use that
// word. When the garbage collector copies material around it transcribes
// the whole vector (including the padder), but it should never try to trace
// through it. By tidying this up here can feel that I do not have any
// need to worry about it elsewhere.
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *(LispObject *)(vfringe-CELL) = 0;
        return (LispObject)(r + tag);
    }
}

// This takes a vector (which can be one represented using an INDEXVEC)
// and reduces its size to a total value len. It returns the shorter
// vector. Only used on simple vectors.

LispObject reduce_basic_vector_size(LispObject v, size_t len)
{   vechdr(v) = TYPE_SIMPLE_VEC + (len << (Tw+5)) + TAG_HDR_IMMED;
    return v;
}

// The next functions (eg borrow_vector) are called just like the
// functions that allocate new vectors, but they use space in the part
// of memory space not at present in use by the garbage collector. If a
// copying garbage collection triggered "right now" were to be able to
// succeed there must be enough reserved space to make this possible provided
// I only borrow space sufficient to make copies of existing live data.
// One must NEVER garbage collect while space has been borrowed in this
// way. At present this scheme is only ever used while rehashing hash
// tables.

static size_t borrowed_pages_count;
static LispObject borrowed_vfringe, borrowed_vheaplimit;

static void get_borrowed_page()
{   if (borrowed_pages_count == 0)
    {   trace_printf("\nRun out of memory (for rehashing)\n");
#ifdef DEBUG
        my_abort();
#endif
        Lstop1(nil, fixnum_of_int(1));
    }
    void *p = pages[--borrowed_pages_count];
    zero_out(p);
    borrowed_vfringe =
        (LispObject)((char *)doubleword_align_up((intptr_t)p) + 8);
    borrowed_vheaplimit =
        (LispObject)((char *)borrowed_vfringe + (CSL_PAGE_SIZE-16));
}

void prepare_for_borrowing()
{   borrowed_pages_count = pages_count;
    get_borrowed_page();
}

LispObject borrow_basic_vector(int tag, int type, size_t size)
{   for (;;)
    {   char *r = (char *)borrowed_vfringe;
        size_t free = (size_t)((char *)borrowed_vheaplimit - r);
        size_t alloc_size = (size_t)doubleword_align_up(size);
        if (alloc_size > free)
        {   get_borrowed_page();
            continue;
        }
        borrowed_vfringe = (LispObject)(r + alloc_size);
        *((Header *)r) = type + (size << (Tw+5)) + TAG_HDR_IMMED;
        if (!SIXTY_FOUR_BIT && alloc_size != size)
            *(LispObject *)(borrowed_vfringe-CELL) = 0;
        return (LispObject)(r + tag);
    }
}

LispObject borrow_vector(int tag, int type, size_t n)
{   LispObject v;
    if (n-CELL > VECTOR_CHUNK_BYTES)
    {   size_t chunks = (n - CELL + VECTOR_CHUNK_BYTES - 1)/VECTOR_CHUNK_BYTES;
        size_t i;
        size_t last_size = (n - CELL) % VECTOR_CHUNK_BYTES;
        if (last_size == 0) last_size = VECTOR_CHUNK_BYTES;
        v = borrow_basic_vector(TAG_VECTOR, TYPE_INDEXVEC, CELL*(chunks+1));
        for (i=0; i<chunks; i++)
            basic_elt(v, i) = nil;
        for (i=0; i<chunks; i++)
        {   LispObject v1;
            int k = i==chunks-1 ? last_size : VECTOR_CHUNK_BYTES;
            push(v);
            v1 = borrow_basic_vector(tag, type, k+CELL);
            pop(v);
            size_t k1 = k/CELL;
            for (size_t j=0; j<k1; j++)
                basic_elt(v1, j) = nil;
            basic_elt(v, i) = v1;
        }
    }
    else v = borrow_basic_vector(tag, type, n);
    return v;
}


// end of allocate.cpp
