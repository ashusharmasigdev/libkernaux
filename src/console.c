#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <kernaux/assert.h>
#include <kernaux/console.h>

#include "libc.h"

#ifdef ASM_I386
#include <kernaux/asm/i386.h>
#endif
#ifdef ASM_X86_64
#include <kernaux/asm/x86_64.h>
#endif
#ifdef WITH_PRINTF
#include <kernaux/printf.h>
#endif

#include <stddef.h>

#ifdef WITH_PRINTF
static void kernaux_console_printf_putc(
    const char c,
    void *const arg __attribute__((unused))
) {
    kernaux_console_putc(c);
}
#endif

void kernaux_console_putc(const char c __attribute__((unused)))
{
#ifdef ASM_I386
    kernaux_asm_i386_outportb(0x3f8, c);
#endif
#ifdef ASM_X86_64
    kernaux_asm_x86_64_outportb(0x3f8, c);
#endif
}

void kernaux_console_print(const char *const s)
{
    KERNAUX_NOTNULL_RETURN(s);

    for (const char *c = s; *c; ++c) {
        kernaux_console_putc(*c);
    }
}

#ifdef WITH_PRINTF
void kernaux_console_printf(const char *format, ...)
{
    KERNAUX_NOTNULL_RETURN(format);

    va_list va;
    va_start(va, format);
    kernaux_vfprintf(kernaux_console_printf_putc, NULL, format, va);
    va_end(va);
}
#endif

void kernaux_console_puts(const char *const s)
{
    KERNAUX_NOTNULL_RETURN(s);

    kernaux_console_print(s);
    kernaux_console_putc('\n');
}

void kernaux_console_write(const char *const data, const size_t size)
{
    KERNAUX_NOTNULL_RETURN(data);

    for (size_t i = 0; i < size; i++) {
        kernaux_console_putc(data[i]);
    }
}
