#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of random access via index transformation, we precompute valid neighbor values
    // and use a sliding window approach with consecutive accesses to improve cache locality.
    OPJ_INT32 prev_val, curr_val;
    if (i < win_l_x1) {
        // Initialize first neighbor values
        OPJ_INT32 idx_i0 = (i >= dn) ? dn - 1 : (i < 0) ? 0 : i;
        curr_val = a[1 + idx_i0 * 2];
        for (; i < win_l_x1; i++) {
            prev_val = curr_val;
            OPJ_INT32 next_idx = i + 1;
            OPJ_INT32 bounded_next = (next_idx >= dn) ? dn - 1 : (next_idx < 0) ? 0 : next_idx;
            curr_val = a[1 + bounded_next * 2];

            a[i * 2] -= (prev_val + curr_val + 2) >> 2;
        }
    }
}
