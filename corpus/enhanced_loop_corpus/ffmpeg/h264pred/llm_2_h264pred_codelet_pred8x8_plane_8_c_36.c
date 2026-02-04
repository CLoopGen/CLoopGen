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
    // Variant 1: Consecutive memory access with unrolled-like pattern using offset indexing
    int offsets[] = {2, 3, 4};
    for (int idx = 0; idx < 3; ++idx) {
        int k_val = offsets[idx];
        src1 += stride;
        src2 -= stride;
        H += k_val * (src0[k_val] - src0[-k_val]);
        V += k_val * (src1[0] - src2[0]);
    }
}
