#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to consecutive write and strided read
// Unroll the inner loop partially and reorganize memory accesses for spatial locality

OPJ_INT32 temp[4];
for (; i < win_l_x1; i++) {
    OPJ_UINT32 dest_base = (OPJ_UINT32)(i) * 8; // Stride of 8 per i
    OPJ_INT32 idx_curr = (i >= dn) ? (dn - 1) : (i < 0 ? 0 : i);
    OPJ_INT32 idx_prev = (i - 1 < 0) ? 0 : ((i - 1 >= dn) ? (dn - 1) : i - 1);
    OPJ_UINT32 src_base_curr = (1 + (OPJ_UINT32)(idx_curr) * 2) * 4;
    OPJ_UINT32 src_base_prev = (1 + (OPJ_UINT32)(idx_prev) * 2) * 4;

    // Pre-load values from source locations with unit stride for better cache behavior
    for (off = 0; off < 4; off++) {
        temp[off] = (a[src_base_prev + off] + a[src_base_curr + off] + 2) >> 2;
    }

    // Store updates consecutively in destination
    for (off = 0; off < 4; off++) {
        a[dest_base + off] -= temp[off];
    }
}
}
