#ifdef __TINYC__
#pragma pack(push, 1)
#endif

static const struct {
    struct KernAux_Multiboot2_Header multiboot2_header;

    struct {
        struct KernAux_Multiboot2_HTag_InfoReq tag;
        uint32_t mbi_tag_types[22];
    } tag_info_req;

    struct KernAux_Multiboot2_HTag_Addr tag_addr;

    struct KernAux_Multiboot2_HTag_EntryAddr tag_entry_addr;
    uint8_t _align1[4];

    struct KernAux_Multiboot2_HTag_Flags tag_flags;
    uint8_t _align2[4];

    struct KernAux_Multiboot2_HTag_Framebuffer tag_framebuffer;
    uint8_t _align3[4];

    struct KernAux_Multiboot2_HTag_ModuleAlign tag_module_align;

    struct KernAux_Multiboot2_HTag_EFIBootServices tag_efi_boot_services;

    struct KernAux_Multiboot2_HTag_EFII386EntryAddr tag_efi_i386_entry_addr;
    uint8_t _align4[4];

    struct KernAux_Multiboot2_HTag_EFIAmd64EntryAddr tag_efi_amd64_entry_addr;
    uint8_t _align5[4];

    struct KernAux_Multiboot2_HTag_RelocatableHeader tag_relocatable_header;

    struct KernAux_Multiboot2_HTag_None tag_none;
} multiboot2_header_example2 = {
    .multiboot2_header = {
        .magic = KERNAUX_MULTIBOOT2_HEADER_MAGIC,
        .arch = KERNAUX_MULTIBOOT2_HEADER_ARCH_I386,
        .total_size = sizeof(multiboot2_header_example2),
        .checksum = KERNAUX_MULTIBOOT2_HEADER_CHECKSUM(
            KERNAUX_MULTIBOOT2_HEADER_ARCH_I386,
            sizeof(multiboot2_header_example2)
        ),
    },
    .tag_info_req = {
        .tag = {
            .base = {
                .type = KERNAUX_MULTIBOOT2_HTAG_INFO_REQ,
                .flags = 0,
                .size = sizeof(multiboot2_header_example2.tag_info_req),
            },
        },
        .mbi_tag_types = {
            KERNAUX_MULTIBOOT2_ITAG_NONE,
            KERNAUX_MULTIBOOT2_ITAG_BOOT_CMD_LINE,
            KERNAUX_MULTIBOOT2_ITAG_BOOT_LOADER_NAME,
            KERNAUX_MULTIBOOT2_ITAG_MODULE,
            KERNAUX_MULTIBOOT2_ITAG_BASIC_MEMORY_INFO,
            KERNAUX_MULTIBOOT2_ITAG_BIOS_BOOT_DEVICE,
            KERNAUX_MULTIBOOT2_ITAG_MEMORY_MAP,
            KERNAUX_MULTIBOOT2_ITAG_VBE_INFO,
            KERNAUX_MULTIBOOT2_ITAG_FRAMEBUFFER_INFO,
            KERNAUX_MULTIBOOT2_ITAG_ELF_SYMBOLS,
            KERNAUX_MULTIBOOT2_ITAG_APM_TABLE,
            KERNAUX_MULTIBOOT2_ITAG_EFI_32BIT_SYSTEM_TABLE_PTR,
            KERNAUX_MULTIBOOT2_ITAG_EFI_64BIT_SYSTEM_TABLE_PTR,
            KERNAUX_MULTIBOOT2_ITAG_SMBIOS_TABLES,
            KERNAUX_MULTIBOOT2_ITAG_ACPI_OLD_RSDP,
            KERNAUX_MULTIBOOT2_ITAG_ACPI_NEW_RSDP,
            KERNAUX_MULTIBOOT2_ITAG_NETWORKING_INFO,
            KERNAUX_MULTIBOOT2_ITAG_EFI_MEMORY_MAP,
            KERNAUX_MULTIBOOT2_ITAG_EFI_BOOT_SERVICES_NOT_TERMINATED,
            KERNAUX_MULTIBOOT2_ITAG_EFI_32BIT_IMAGE_HANDLE_PTR,
            KERNAUX_MULTIBOOT2_ITAG_EFI_64BIT_IMAGE_HANDLE_PTR,
            KERNAUX_MULTIBOOT2_ITAG_IMAGE_LOAD_BASE_PHYS_ADDR,
        },
    },
    .tag_addr = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_ADDR,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_addr),
        },
        .header_addr = 0,
        .load_addr = 0,
        .load_end_addr = 0,
        .bss_end_addr = 0,
    },
    .tag_entry_addr = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_ENTRY_ADDR,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_entry_addr),
        },
        .entry_addr = 0,
    },
    .tag_flags = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_FLAGS,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_flags),
        },
        .console_flags = (
            KERNAUX_MULTIBOOT2_HTAG_FLAGS_REQUIRE_CONSOLE |
            KERNAUX_MULTIBOOT2_HTAG_FLAGS_EGA_SUPPORT
        ),
    },
    .tag_framebuffer = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_FRAMEBUFFER,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_framebuffer),
        },
        .width = 0,
        .height = 0,
        .depth = 0,
    },
    .tag_module_align = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_MODULE_ALIGN,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_module_align),
        },
    },
    .tag_efi_boot_services = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_EFI_BOOT_SERVICES,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_efi_boot_services),
        },
    },
    .tag_efi_i386_entry_addr = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_EFI_I386_ENTRY_ADDR,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_efi_i386_entry_addr),
        },
        .entry_addr = 0,
    },
    .tag_efi_amd64_entry_addr = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_EFI_AMD64_ENTRY_ADDR,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_efi_amd64_entry_addr),
        },
        .entry_addr = 0,
    },
    .tag_relocatable_header = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_RELOCATABLE_HEADER,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_relocatable_header),
        },
        .min_addr = 0,
        .max_addr = 0,
        .align = 0,
        .preferences =
            KERNAUX_MULTIBOOT2_HTAG_RELOCATABLE_HEADER_PREFERENCE_LOWEST,
    },
    .tag_none = {
        .base = {
            .type = KERNAUX_MULTIBOOT2_HTAG_NONE,
            .flags = 0,
            .size = sizeof(multiboot2_header_example2.tag_none),
        },
    },
};

#ifdef __TINYC__
#pragma pack(pop)
#endif
