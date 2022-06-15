#ifndef KERNAUX_INCLUDED_MEMMAP
#define KERNAUX_INCLUDED_MEMMAP

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

#define KERNAUX_MEMMAP_ENTRIES_MAX 100

#define KERNAUX_MEMMAP_ENTRY_TAG_SLEN_MAX 24
#define KERNAUX_MEMMAP_ENTRY_TAG_SIZE_MAX (KERNAUX_MEMMAP_ENTRY_TAG_SLEN_MAX + 1)

typedef struct KernAux_MemMap_Entry {
    bool is_available;
    char tag[KERNAUX_MEMMAP_ENTRY_TAG_SIZE_MAX];
    size_t start, size, end, limit;
} KernAux_MemMap_Entry[1];

typedef struct KernAux_MemMap {
    bool is_finished;
    size_t memory_size;
    size_t entries_count;
    KernAux_MemMap_Entry entries[KERNAUX_MEMMAP_ENTRIES_MAX];
} KernAux_MemMap[1];

void KernAux_MemMap_init(KernAux_MemMap memmap, size_t memory_size);

#ifdef __cplusplus
}
#endif

#endif
