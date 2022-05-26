#ifndef KERNAUX_INCLUDED_PRINTF_FMT
#define KERNAUX_INCLUDED_PRINTF_FMT

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#define KERNAUX_PRINTF_FMT_FLAGS_ZEROPAD   (1u <<  0u)
#define KERNAUX_PRINTF_FMT_FLAGS_LEFT      (1u <<  1u)
#define KERNAUX_PRINTF_FMT_FLAGS_PLUS      (1u <<  2u)
#define KERNAUX_PRINTF_FMT_FLAGS_SPACE     (1u <<  3u)
#define KERNAUX_PRINTF_FMT_FLAGS_HASH      (1u <<  4u)
#define KERNAUX_PRINTF_FMT_FLAGS_UPPERCASE (1u <<  5u)
#define KERNAUX_PRINTF_FMT_FLAGS_CHAR      (1u <<  6u)
#define KERNAUX_PRINTF_FMT_FLAGS_SHORT     (1u <<  7u)
#define KERNAUX_PRINTF_FMT_FLAGS_LONG      (1u <<  8u)
#define KERNAUX_PRINTF_FMT_FLAGS_LONG_LONG (1u <<  9u)
#define KERNAUX_PRINTF_FMT_FLAGS_PRECISION (1u << 10u)
#define KERNAUX_PRINTF_FMT_FLAGS_ADAPT_EXP (1u << 11u)
#define KERNAUX_PRINTF_FMT_FLAGS_CUSTOM    (1u << 12u)

enum KernAux_PrintfFmt_Type {
    KERNAUX_PRINTF_FMT_TYPE_NONE,
    KERNAUX_PRINTF_FMT_TYPE_INT,
    KERNAUX_PRINTF_FMT_TYPE_UINT,
    KERNAUX_PRINTF_FMT_TYPE_FLOAT,
    KERNAUX_PRINTF_FMT_TYPE_EXP,
    KERNAUX_PRINTF_FMT_TYPE_CHAR,
    KERNAUX_PRINTF_FMT_TYPE_STR,
    KERNAUX_PRINTF_FMT_TYPE_CUSTOM,
    KERNAUX_PRINTF_FMT_TYPE_PTR,
    KERNAUX_PRINTF_FMT_TYPE_PERCENT,
};

struct KernAux_PrintfFmt_Spec {
    unsigned int flags;
    unsigned int width;
    unsigned int precision;
    enum KernAux_PrintfFmt_Type type;

    unsigned int base;
};

struct KernAux_PrintfFmt_Spec KernAux_PrintfFmt_Spec_create();
void KernAux_PrintfFmt_Spec_init(struct KernAux_PrintfFmt_Spec *spec);

void KernAux_PrintfFmt_Spec_eval_flags(struct KernAux_PrintfFmt_Spec *spec, const char **format);
bool KernAux_PrintfFmt_Spec_eval_width1(struct KernAux_PrintfFmt_Spec *spec, const char **format);
void KernAux_PrintfFmt_Spec_eval_width2(struct KernAux_PrintfFmt_Spec *spec, const char **format, int width);
bool KernAux_PrintfFmt_Spec_eval_precision1(struct KernAux_PrintfFmt_Spec *spec, const char **format);
void KernAux_PrintfFmt_Spec_eval_precision2(struct KernAux_PrintfFmt_Spec *spec, const char **format, int precision);
void KernAux_PrintfFmt_Spec_eval_length(struct KernAux_PrintfFmt_Spec *spec, const char **format);
void KernAux_PrintfFmt_Spec_eval_type(struct KernAux_PrintfFmt_Spec *spec, const char **format);

#ifdef __cplusplus
}
#endif

#endif
