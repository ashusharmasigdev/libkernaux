#include <kernaux/multiboot2.h>

// TODO: add more tags
__attribute__((section(".multiboot2"), used))
__attribute__((aligned(KERNAUX_MULTIBOOT2_HEADER_ALIGN)))
const struct {
    struct KernAux_Multiboot2_Header multiboot2_header;
    struct KernAux_Multiboot2_HTag_None tag_none;
}
__attribute__((packed))
multiboot2_header = {
    .multiboot2_header = {
        .magic = KERNAUX_MULTIBOOT2_HEADER_MAGIC,
        .arch = KERNAUX_MULTIBOOT2_HEADER_ARCH_I386,
        .total_size = sizeof(multiboot2_header),
        .checksum = KERNAUX_MULTIBOOT2_HEADER_CHECKSUM(
            KERNAUX_MULTIBOOT2_HEADER_ARCH_I386,
            sizeof(multiboot2_header)
        ),
    },
    .tag_none = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_NONE,
            .flags = 0,
            .size = sizeof(multiboot2_header.tag_none),
        },
    },
};
