#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t * src0;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern with unrolled stride simulation
    // Instead of updating src1 and src2 via stride, we precompute the effective indices
    // and access elements consecutively in a forward manner for better cache locality.
    int base_idx_src1 = stride * 1;  // initial offset due to prior src1 += stride (k=2 starts)
    int base_idx_src2 = -stride * 1; // initial offset for src2 -= stride
    H = V = 0; // Reset accumulators for standalone behavior
    for (k = 2; k <= 4; ++k) {
        int eff_src1 = base_idx_src1 + (k - 2) * stride;
        int eff_src2 = base_idx_src2 - (k - 2) * stride;
        H += k * (src0[k] - src0[-k]);
        V += k * (src1[eff_src1] - src2[eff_src2]);
    }
}
