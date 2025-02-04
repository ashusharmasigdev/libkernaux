include $(top_srcdir)/shared.am

ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = autogen.sh CONTRIBUTING.md sha256sums.txt

SUBDIRS = include

if WITH_LIBC
# FIXME: after "make clean" libc is not rebuiling
SUBDIRS += libc
endif

SUBDIRS += .

if ENABLE_TESTS
SUBDIRS += examples tests
endif

libc/libc.la:
	$(MAKE) $(AM_MAKEFLAGS) -C $(top_builddir)/libc libc.la

AM_CFLAGS += -DKERNAUX_ACCESS_PRIVATE

lib_LTLIBRARIES = libkernaux.la

##################
# Required files #
##################

libkernaux_la_LIBADD =
libkernaux_la_SOURCES = \
	src/assert.c \
	src/libc.h \
	src/generic/malloc.c \
	src/generic/mutex.c

########
# libc #
########

if WITH_LIBC
libkernaux_la_LIBADD += libc/libc.la
endif

#######
# ASM #
#######

if ASM_I386
libkernaux_la_SOURCES += src/asm/i386.S
endif
if ASM_RISCV64
libkernaux_la_SOURCES += src/asm/riscv64.S
endif
if ASM_X86_64
libkernaux_la_SOURCES += src/asm/x86_64.S
endif

###########
# Drivers #
###########

if WITH_DRIVERS
libkernaux_la_SOURCES += \
	src/drivers/console.c \
	src/drivers/framebuffer.c \
	src/drivers/intel_8259_pic.c
endif

####################
# Default packages #
####################

if WITH_CMDLINE
libkernaux_la_SOURCES += src/cmdline.c
endif
if WITH_ELF
libkernaux_la_SOURCES += src/elf.c
endif
if WITH_FREE_LIST
libkernaux_la_SOURCES += src/free_list.c
endif
if WITH_IO
libkernaux_la_SOURCES += src/io.c
endif
if WITH_MBR
libkernaux_la_SOURCES += src/mbr.c
endif
if WITH_MEMMAP
libkernaux_la_SOURCES += src/memmap.c
endif
if WITH_MULTIBOOT2
libkernaux_la_SOURCES += \
	src/multiboot2/enums_to_str.c \
	src/multiboot2/header_helpers.c \
	src/multiboot2/header_is_valid.c \
	src/multiboot2/header_print.c \
	src/multiboot2/info_convert.c \
	src/multiboot2/info_helpers.c \
	src/multiboot2/info_is_valid.c \
	src/multiboot2/info_print.c
endif
if WITH_NTOA
libkernaux_la_SOURCES += src/ntoa.c
endif
if WITH_PFA
libkernaux_la_SOURCES += src/pfa.c
endif
if WITH_PRINTF
libkernaux_la_SOURCES += src/printf.c
endif
if WITH_PRINTF_FMT
libkernaux_la_SOURCES += src/printf_fmt.c
endif
if WITH_UNITS
libkernaux_la_SOURCES += src/units.c
endif
