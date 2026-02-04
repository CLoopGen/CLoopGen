#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *a;
OPJ_INT32 dn;
OPJ_INT32 win_l_x1;
OPJ_INT32 i;
OPJ_UINT32 off;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime
    a = (OPJ_INT32*)aligned_alloc(16, data_size);
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize array with predictable values
    for (size_t idx = 0; idx < data_size / sizeof(OPJ_INT32); idx++) {
        a[idx] = (OPJ_INT32)(idx % 1000);
    }

    // Set dn to control boundary conditions: choose reasonable size
    dn = 8192;

    // Ensure win_l_x1 is within safe bounds so that i < win_l_x1 and memory accesses are valid
    // Maximum index used: (i)*2*4 + off where i < win_l_x1 -> max index ~ win_l_x1 * 8 + 3
    // Also: access via (1 + (i-1)*2)*4+off => max coefficient: (1 + (win_l_x1-1)*2)*4+off
    // So maximum offset is roughly (1 + (win_l_x1-1)*2)*4+3
    // We require: (1 + (win_l_x1-1)*2)*4+3 < allocated_size/sizeof(OPJ_INT32)
    // Solve: (1 + (w-1)*2)*4+3 = 8*w - 1 < size => w < (size + 1)/8
    size_t max_safe_win = (data_size / sizeof(OPJ_INT32) + 1) / 8;
    win_l_x1 = (max_safe_win < 8192) ? (OPJ_INT32)max_safe_win : 8192;

    i = 0;
    off = 0;
}