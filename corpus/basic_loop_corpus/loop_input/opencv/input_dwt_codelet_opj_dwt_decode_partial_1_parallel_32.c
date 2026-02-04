#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef int32_t OPJ_INT32;
typedef uint32_t OPJ_UINT32;

OPJ_INT32 *a;
OPJ_INT32 sn;
OPJ_INT32 win_h_x1;
OPJ_INT32 i;
OPJ_UINT32 off;

void init_vars() {
    // Set parameters to ensure memory safety and reasonable runtime (~0.01 sec)
    sn = 65536;  // ~1MB of data: each element is 8 bytes (2*4), total array size ~524288 bytes
    win_h_x1 = sn - 1;  // ensures i+1 < sn inside loop
    i = 0;

    // Allocate array with padding: we access indices up to (i+1)*2*4 + off, where i < win_h_x1
    // Maximum index: (win_h_x1) * 2 * 4 + 3 = (sn-2)*8 + 3 -> need at least (sn-1)*8 elements
    size_t array_size = (size_t)(sn) * 8;  // Ensure sufficient space
    a = (OPJ_INT32*)calloc(array_size, sizeof(OPJ_INT32));
    if (!a) {
        exit(1);
    }

    // Initialize the array with non-zero values for meaningful computation
    for (size_t idx = 0; idx < array_size; idx++) {
        a[idx] = (OPJ_INT32)(idx % 256);
    }
}