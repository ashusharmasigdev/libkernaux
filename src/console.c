#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef ASM_I386
#include <kernaux/asm/i386.h>
#endif

#include <kernaux/console.h>
#include <kernaux/libc.h>
#include <kernaux/printf.h>

void kernaux_console_putc(const char c __attribute__((unused)))
{
#ifdef ASM_I386
    kernaux_asm_i386_outportb(0x3F8, c);
#endif
}

void kernaux_console_print(const char *const s)
{
    for (const char *c = s; *c; ++c) {
        kernaux_console_putc(*c);
    }
}

void kernaux_console_printf(const char *format, ...)
{
    va_list va;
    va_start(va, format);
    kernaux_printf_va(kernaux_console_putc, format, va);
    va_end(va);
}

void kernaux_console_puts(const char *const s)
{
    kernaux_console_print(s);
    kernaux_console_putc('\n');
}

void kernaux_console_write(const char *const data, const size_t size)
{
    for (size_t i = 0; i < size; i++) {
        kernaux_console_putc(data[i]);
    }
}
