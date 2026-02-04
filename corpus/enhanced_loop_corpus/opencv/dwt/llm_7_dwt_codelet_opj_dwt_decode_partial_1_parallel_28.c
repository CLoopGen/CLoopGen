#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 acc = 0;
    for (off = 0; off < 4; off++) {
        OPJ_UINT32 src_idx = (1 + (OPJ_UINT32)(i) * 2) * 4 + off;
        OPJ_UINT32 prev_idx = (1 + (OPJ_UINT32)((i - 1) < 0 ? 0 : (i - 1)) * 2) * 4 + off;
        OPJ_UINT32 clamp_idx = (1 + (OPJ_UINT32)((i) >= dn ? dn - 1 : i) * 2) * 4 + off;
        OPJ_INT32 val_prev = ((i - 1) < 0 || (i - 1) >= dn) ?
                             a[src_idx] : a[prev_idx];
        OPJ_INT32 val_curr = (i < 0 || i >= dn) ?
                             a[src_idx] : a[clamp_idx];
        OPJ_INT32 avg = (val_prev + val_curr + 2) >> 2;
        acc += avg;
        a[(OPJ_UINT32)(i) * 2 * 4 + off] -= avg;
    }
    // Introduce artificial loop-carried dependency via accumulator effect on memory access pattern
    if (acc > 0 && i + 1 < dn) {
        a[(OPJ_UINT32)(i + 1) * 2 * 4] -= acc & 0xFF;
    }
}
