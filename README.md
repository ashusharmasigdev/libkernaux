libkernaux
==========

[![Build status](https://github.com/tailix/libkernaux/actions/workflows/main.yml/badge.svg)](https://github.com/tailix/libkernaux/actions/workflows/main.yml)
[![Build status (FreeBSD)](https://api.cirrus-ci.com/github/tailix/libkernaux.svg?task=Main%20(FreeBSD))](https://cirrus-ci.com/github/tailix/libkernaux)

Auxiliary library for kernel development.

[Topic on OSDev.org forum](https://forum.osdev.org/viewtopic.php?f=1&t=37958).



Table of contents
-----------------

* [Overview](#libkernaux)
* [Table of contents](#table-of-contents)
* [API](#api)
* [Configuration](#configuration)
  * [Non-default options](#non-default-options)
  * [Default options](#default-options)
* [Tips](#tips)
  * [Installation](#installation)
  * [Development](#development)
  * [Cross](#cross)
* [Architectures](#architectures)



API
---

We use [semantic versioning](https://semver.org) for stable APIs. Stable APIs
can only change when major version number is increased (or minor while major is
zero). Work-in-progress APIs can change at any time.

* Runtime environment
  * Architecture-specific code (*work in progress*)
    * [Declarations](/include/kernaux/arch/)
    * [Functions](/include/kernaux/asm/)
  * [Assertions](/include/kernaux/assert.h) (*stable since* **0.1.0**, *non-breaking since* **0.2.0**)
    * [Assert: simple](/examples/assert_simple.c)
    * [Assert: guards](/examples/assert_guards.c)
    * [Panic: simple](/examples/panic_simple.c)
    * [Panic: guards](/examples/panic_guards.c)
  * Stack trace *(planned)*
* Device drivers (for debugging only)
  * [Serial console](/include/kernaux/console.h) (*work in progress*)
  * [Framebuffer](/include/kernaux/framebuffer.h) (*planned*)
  * USB (*planned*)
* Algorithms
  * [Simple command line parser](/include/kernaux/cmdline.h) (*stable since* **0.2.0**)
    * [Example](/examples/cmdline.c)
  * [Page Frame Allocator](/include/kernaux/pfa.h) (*work in progress*)
    * [Example](/examples/pfa.c)
* Data formats
  * [ELF](/include/kernaux/elf.h) (*work in progress*)
  * [Master Boot Record](/include/kernaux/mbr.h) (*work in progress*)
  * [Multiboot 2 (GRUB 2)](/include/kernaux/multiboot2.h) (*work in progress*)
  * Stivale 2 (Limine) (*planned*)
* Utilities
  * [Measurement units utils](/include/kernaux/units.h) (*work in progress*)
    * [To human](/examples/units_human.c)
* Usual functions
  * [libc replacement](/include/kernaux/libc.h) (*stable since* **0.1.0**)
  * [itoa/ftoa replacement](/include/kernaux/ntoa.h) (*stable since* **0.1.0**)
  * [printf replacement](/include/kernaux/printf.h) (*stable since* **0.1.0**)
    * Code from [https://github.com/mpaland/printf](https://github.com/mpaland/printf). Thank you!
    * [printf](/examples/printf.c)
    * [vprintf](/examples/printf_va.c)
    * [snprintf](/examples/snprintf.c)
    * [vsnprintf](/examples/snprintf_va.c)



Configuration
-------------

Because this library has no external dependencies, we use **autoconf** features
to control behavior of the library, and packages to choose it's components.
Configuration options also follow the [semantic versioning](https://semver.org)
scheme and are split into stable and work-in-progress ones. Here we cover only
stable options.

### Non-default options

#### Packages

* `--with-libc` - provides the replacement for some standard C functions. Useful
  in freestanding environment, where no libc is present. You can also separately
  include or exclude components:
  * `--with[out]-libc-atoi`
  * `--with[out]-libc-isdigit`
  * `--with[out]-libc-isspace`
  * `--with[out]-libc-memset`
  * `--with[out]-libc-strcpy`
  * `--with[out]-libc-strlen`
  * `--with[out]-libc-strnlen`

### Default options

#### Features

* `--enable-bloat`, disable with `--disable-bloat`
* `--enable-float`, disable with `--disable-float`

#### Packages

All packages all included by default. To exclude all packages except those
explicitly included, use `--without-all`.

* `--with[out]-ntoa`
* `--with[out]-printf`



Tips
----

### Installation

```
./autogen.sh
./configure CFLAGS='-fPIC'
make
sudo make install
```

This is just a usual library. You can use most of it's APIs in hosted
environment.

### Development

```
./autogen.sh
./configure --enable-tests CFLAGS='-fPIC'
make
```

You can test with `make check`.

### Cross

Create configuration script with `./autogen.sh`.

Let's assume that your target triplet is `i386-elf`. Configure with
[cross-compiler](https://wiki.osdev.org/GCC_Cross-Compiler) in `$PATH` to make
without it in `$PATH`:

```
./configure \
  --host='i386-elf' \
  --with-libc \
  AR="$(which i386-elf-ar)" \
  CC="$(which i386-elf-gcc)" \
  RANLIB="$(which i386-elf-ranlib)" \
  CFLAGS='-ffreestanding -nostdlib -fno-builtin -fno-stack-protector'
```

You can see the following messages. It's
[a bug](https://savannah.gnu.org/support/index.php?110393) in **autoconf**, just
ignore it.

```
checking for _Bool... no
checking stdarg.h usability... no
checking stdarg.h presence... yes
configure: WARNING: stdarg.h: present but cannot be compiled
configure: WARNING: stdarg.h:     check for missing prerequisite headers?
configure: WARNING: stdarg.h: see the Autoconf documentation
configure: WARNING: stdarg.h:     section "Present But Cannot Be Compiled"
configure: WARNING: stdarg.h: proceeding with the compiler's result
configure: WARNING:     ## ---------------------------------------------------------- ##
configure: WARNING:     ## Report this to https://github.com/tailix/libkernaux/issues ##
configure: WARNING:     ## ---------------------------------------------------------- ##
checking for stdarg.h... no
checking stddef.h usability... no
checking stddef.h presence... yes
configure: WARNING: stddef.h: present but cannot be compiled
configure: WARNING: stddef.h:     check for missing prerequisite headers?
configure: WARNING: stddef.h: see the Autoconf documentation
configure: WARNING: stddef.h:     section "Present But Cannot Be Compiled"
configure: WARNING: stddef.h: proceeding with the compiler's result
configure: WARNING:     ## ---------------------------------------------------------- ##
configure: WARNING:     ## Report this to https://github.com/tailix/libkernaux/issues ##
configure: WARNING:     ## ---------------------------------------------------------- ##
checking for stddef.h... no
```

To install into specific directory use full path: `DESTDIR="$(pwd)/dest" make
install` instead of `DESTDIR=dest make install`.

Check if compilation targets i386: `objdump -d src/asm/i386.o`. It should output
something like this:

```
src/asm/i386.o:     file format elf32-i386


Disassembly of section .text:

00000000 <kernaux_asm_i386_read_cr0>:
   0:   0f 20 c0              mov    %cr0,%eax
   3:   c3                    ret

00000004 <kernaux_asm_i386_read_cr4>:
   4:   0f 20 e0              mov    %cr4,%eax
   7:   c3                    ret

00000008 <kernaux_asm_i386_write_cr0>:
   8:   8b 44 24 04           mov    0x4(%esp),%eax
   c:   0f 22 c0              mov    %eax,%cr0
   f:   c3                    ret

00000010 <kernaux_asm_i386_write_cr3>:
  10:   8b 44 24 04           mov    0x4(%esp),%eax
  14:   0f 22 d8              mov    %eax,%cr3
  17:   c3                    ret

00000018 <kernaux_asm_i386_write_cr4>:
  18:   8b 44 24 04           mov    0x4(%esp),%eax
  1c:   0f 22 e0              mov    %eax,%cr4
  1f:   c3                    ret
```



Architectures
-------------

Architectures should be properly identified. We use the following scheme, but it
may change in future:

* `x86`
  * `i386`
  * `x86_64`
* `riscv`
  * `riscv64`
* `arm` - we need more info, now similar to [Debian](https://www.debian.org/ports/arm/)
  * `armel`
  * `armhf`
  * `arm64`
