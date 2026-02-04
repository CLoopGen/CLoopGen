#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *restrict datap;
OPJ_UINT32 i;
OPJ_UINT32 cblk_size;

void init_vars() {
    cblk_size = 64 * 1024 * 1024; // 64M elements, ~256MB of data
    datap = (OPJ_INT32*)aligned_alloc(32, cblk_size * sizeof(OPJ_INT32));
    for (OPJ_UINT32 idx = 0; idx < cblk_size; ++idx) {
        datap[idx] = rand() % 1000 - 500; // Random values between -500 and 499
    }
}