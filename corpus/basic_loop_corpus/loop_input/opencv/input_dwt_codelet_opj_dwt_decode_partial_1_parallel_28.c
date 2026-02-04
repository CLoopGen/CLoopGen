#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *a;
OPJ_INT32 dn;
OPJ_INT32 i;
OPJ_UINT32 off;

void init_vars() {
    dn = 1024;
    i = 512;

    size_t total_size = (size_t)(1 + 2 * dn) * 4;
    a = (OPJ_INT32*)calloc(total_size, sizeof(OPJ_INT32));
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < total_size; ++idx) {
        a[idx] = (OPJ_INT32)(idx % 256);
    }
}