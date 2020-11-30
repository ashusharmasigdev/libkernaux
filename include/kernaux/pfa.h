#ifndef KERNAUX_INCLUDED_PFA
#define KERNAUX_INCLUDED_PFA 1

#include <kernaux/stdlib.h>

#define KERNAUX_PFA_PAGE_SIZE (4 * 1024)
#define KERNAUX_PFA_PAGES_COUNT_MAX (1024 * 1024)

#ifdef __cplusplus
extern "C" {
#endif

struct KernAux_PFA {
    kernaux_bool pages[KERNAUX_PFA_PAGES_COUNT_MAX];
};

void KernAux_PFA_initialize(
    struct KernAux_PFA *pfa
)
__attribute__((nonnull));

void KernAux_PFA_mark_available(
    struct KernAux_PFA *pfa,
    unsigned int start,
    unsigned int end
)
__attribute__((nonnull));

#ifdef __cplusplus
}
#endif

#endif
