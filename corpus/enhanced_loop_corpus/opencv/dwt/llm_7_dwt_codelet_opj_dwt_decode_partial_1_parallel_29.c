#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;
extern OPJ_INT32 i_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < i_max; i++) {
        OPJ_INT32 base_idx_curr = (OPJ_INT32)((OPJ_UINT32)(i) * 2 * 4);
        OPJ_INT32 base_idx_prev = (OPJ_INT32)((1 + (OPJ_UINT32)(i - 1) * 2) * 4);
        OPJ_INT32 base_idx_curr_shifted = (OPJ_INT32)((1 + (OPJ_UINT32)(i) * 2) * 4);
        for (off = 0; off < 4; off++) {
            OPJ_INT32 update_val = (a[base_idx_prev + off] + a[base_idx_curr_shifted + off] + 2) >> 2;
            a[base_idx_curr + off] -= update_val;
        }
    }
}
