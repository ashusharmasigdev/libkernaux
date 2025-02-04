##################
# Required files #
##################

nobase_include_HEADERS = \
	kernaux.h \
	kernaux/arch/i386.h \
	kernaux/arch/riscv64.h \
	kernaux/arch/x86_64.h \
	kernaux/assert.h \
	kernaux/macro.h \
	kernaux/version.h \
	kernaux/generic/malloc.h \
	kernaux/generic/mutex.h

#######
# ASM #
#######

if ASM_I386
nobase_include_HEADERS += kernaux/asm/i386.h
endif
if ASM_RISCV64
nobase_include_HEADERS += kernaux/asm/riscv64.h
endif
if ASM_X86_64
nobase_include_HEADERS += kernaux/asm/x86_64.h
endif

###########
# Drivers #
###########

if WITH_DRIVERS
nobase_include_HEADERS += \
	kernaux/drivers/console.h \
	kernaux/drivers/framebuffer.h \
	kernaux/drivers/intel_8259_pic.h
endif

####################
# Default packages #
####################

if WITH_CMDLINE
nobase_include_HEADERS += kernaux/cmdline.h
endif
if WITH_ELF
nobase_include_HEADERS += kernaux/elf.h
endif
if WITH_FREE_LIST
nobase_include_HEADERS += kernaux/free_list.h
endif
if WITH_IO
nobase_include_HEADERS += kernaux/io.h
endif
if WITH_MBR
nobase_include_HEADERS += kernaux/mbr.h
endif
if WITH_MEMMAP
nobase_include_HEADERS += kernaux/memmap.h
endif
if WITH_MULTIBOOT2
nobase_include_HEADERS += kernaux/multiboot2.h
endif
if WITH_NTOA
nobase_include_HEADERS += kernaux/ntoa.h
endif
if WITH_PFA
nobase_include_HEADERS += kernaux/pfa.h
endif
if WITH_PRINTF
nobase_include_HEADERS += kernaux/printf.h
endif
if WITH_PRINTF_FMT
nobase_include_HEADERS += kernaux/printf_fmt.h
endif
if WITH_UNITS
nobase_include_HEADERS += kernaux/units.h
endif
