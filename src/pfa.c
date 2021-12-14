#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <kernaux/pfa.h>
#include <kernaux/stdlib.h>

static void KernAux_PFA_mark(
    KernAux_PFA pfa,
    bool status,
    size_t start,
    size_t end
)
__attribute__((nonnull));

void KernAux_PFA_initialize(const KernAux_PFA pfa)
{
    kernaux_memset(pfa->pages, false, sizeof(pfa->pages));
}

bool KernAux_PFA_is_available(const KernAux_PFA pfa, const size_t page_addr)
{
    if (page_addr % KERNAUX_PFA_PAGE_SIZE != 0) return false;

    return pfa->pages[page_addr / KERNAUX_PFA_PAGE_SIZE];
}

void KernAux_PFA_mark_available(
    const KernAux_PFA pfa,
    const size_t start,
    const size_t end
) {
    KernAux_PFA_mark(pfa, true, start, end);
}

void KernAux_PFA_mark_unavailable(
    const KernAux_PFA pfa,
    const size_t start,
    const size_t end
) {
    KernAux_PFA_mark(pfa, false, start, end);
}

void KernAux_PFA_mark(
    const KernAux_PFA pfa,
    const bool status,
    size_t start,
    size_t end
) {
    if (start >= end) return;

    const size_t start_rem = start % KERNAUX_PFA_PAGE_SIZE;
    const size_t end_rem = (end + 1) % KERNAUX_PFA_PAGE_SIZE;

    if (start_rem != 0) {
        start = start - start_rem + KERNAUX_PFA_PAGE_SIZE;
    }

    if (end_rem != 0) {
        end = end - end_rem;
    }

    const size_t start_index = start / KERNAUX_PFA_PAGE_SIZE;
    const size_t end_index   = end   / KERNAUX_PFA_PAGE_SIZE;

    for (size_t index = start_index; index <= end_index; ++index) {
        pfa->pages[index] = status;
    }
}

size_t KernAux_PFA_alloc_pages(const KernAux_PFA pfa, size_t mem_size)
{
    const size_t mem_rem = mem_size % KERNAUX_PFA_PAGE_SIZE;

    if (mem_rem != 0) {
        mem_size = mem_size - mem_rem + KERNAUX_PFA_PAGE_SIZE;
    }

    const size_t pages_count = mem_size / KERNAUX_PFA_PAGE_SIZE;

    // We start from 1 because 0 indicates failure.
    // It is not very useful to alloc page at address 0;
    for (size_t index = 1, start = 0;
            index < KERNAUX_PFA_PAGES_COUNT_MAX;
            ++index)
    {
        if (!pfa->pages[index]) {
            start = 0;
            continue;
        }

        if (start == 0) start = index;

        if (index - start + 1 == pages_count) {
            for (; index >= start; --index) {
                pfa->pages[index] = false;
            }
            return start * KERNAUX_PFA_PAGE_SIZE;
        }
    }

    return 0;
}

void KernAux_PFA_free_pages(
    const KernAux_PFA pfa,
    const size_t page_addr,
    size_t mem_size
) {
    if (page_addr % KERNAUX_PFA_PAGE_SIZE != 0) return;

    const size_t mem_rem = mem_size % KERNAUX_PFA_PAGE_SIZE;

    if (mem_rem != 0) {
        mem_size = mem_size - mem_rem + KERNAUX_PFA_PAGE_SIZE;
    }

    const size_t start_index = page_addr / KERNAUX_PFA_PAGE_SIZE;
    const size_t pages_count = mem_size  / KERNAUX_PFA_PAGE_SIZE;

    for (size_t index = 0; index < pages_count; ++index) {
        pfa->pages[start_index + index] = true;
    }
}
