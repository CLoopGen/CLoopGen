#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef size_t OPJ_SIZE_T;

OPJ_INT32 *restrict c0;
OPJ_INT32 *restrict c1;
OPJ_INT32 *restrict c2;
OPJ_SIZE_T i;
OPJ_SIZE_T len;

void init_vars() {
    len = 64 * 1024 * 1024 / sizeof(OPJ_INT32); // ~64M elements for ~256MB total data
    i = 0;

    c0 = (OPJ_INT32*)aligned_alloc(32, len * sizeof(OPJ_INT32));
    c1 = (OPJ_INT32*)aligned_alloc(32, len * sizeof(OPJ_INT32));
    c2 = (OPJ_INT32*)aligned_alloc(32, len * sizeof(OPJ_INT32));

    for (OPJ_SIZE_T idx = 0; idx < len; ++idx) {
        c0[idx] = (OPJ_INT32)(idx % 256);
        c1[idx] = (OPJ_INT32)((idx + 64) % 256);
        c2[idx] = (OPJ_INT32)((idx + 128) % 256);
    }
}