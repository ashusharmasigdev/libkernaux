#ifndef KERNAUX_INCLUDED_NTOA
#define KERNAUX_INCLUDED_NTOA

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

// TODO: define
#define KERNAUX_UTOA_BUFFER_SIZE (0/0)

// TODO: define
#define KERNAUX_ITOA_BUFFER_SIZE (0/0)

// "18446744073709551615"
#define KERNAUX_UTOA10_BUFFER_SIZE 21

// "9223372036854775807"
// "-9223372036854775808"
#define KERNAUX_ITOA10_BUFFER_SIZE 21

// "ffffffffffffffff"
#define KERNAUX_UTOA16_BUFFER_SIZE 17

// "7fffffffffffffff"
// "-8000000000000000"
#define KERNAUX_ITOA16_BUFFER_SIZE 18

// TODO: add tests for assertion
char *kernaux_utoa(uint64_t value, char *buffer, int base);
char *kernaux_itoa(int64_t  value, char *buffer, int base);

void kernaux_utoa10(uint64_t value, char *buffer);
void kernaux_itoa10(int64_t  value, char *buffer);

void kernaux_utoa16(uint64_t value, char *buffer);
void kernaux_itoa16(int64_t  value, char *buffer);

#ifdef __cplusplus
}
#endif

#endif
