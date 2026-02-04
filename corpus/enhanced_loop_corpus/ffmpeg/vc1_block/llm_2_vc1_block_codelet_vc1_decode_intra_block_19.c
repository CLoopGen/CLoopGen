#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int32_t ff_vc1_dqscale[63];
extern int16_t *ac_val2;
extern int q1;
extern int q2;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride simulation
    // Instead of accessing ac_val2[k + 8], we precompute the base pointer and access consecutively
    int16_t *base = &ac_val2[9]; // Start at k=1 => index 9
    for (int k_idx = 0; k_idx < 7; k_idx++) {
        base[k_idx] = (int)(base[k_idx] * (unsigned int)q2 * ff_vc1_dqscale[q1 - 1] + 131072) >> 18;
    }
}
