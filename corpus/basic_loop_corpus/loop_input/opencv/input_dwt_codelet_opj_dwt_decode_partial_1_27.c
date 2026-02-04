#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;

OPJ_INT32 *a;
OPJ_INT32 sn;
OPJ_INT32 win_h_x1;
OPJ_INT32 i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB of input data (64M int32 elements)
    a = (OPJ_INT32*)aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }

    sn = (OPJ_INT32)(data_size / sizeof(OPJ_INT32)) / 2;
    win_h_x1 = sn / 2;
    i = 0;

    for (size_t idx = 0; idx < data_size / sizeof(OPJ_INT32); ++idx) {
        a[idx] = (OPJ_INT32)(idx % 1000);
    }
}