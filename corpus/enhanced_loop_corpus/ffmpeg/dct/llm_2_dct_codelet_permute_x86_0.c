#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_simple_mmx_perm[64];
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: src[i] and src[i+1] mapped through permutation to non-consecutive dst indices
    for (i = 0; i < 64; i += 2) {
        dst[idct_simple_mmx_perm[i]] = src[i];
        if (i + 1 < 64) {
            dst[idct_simple_mmx_perm[i + 1]] = src[i + 1];
        }
    }
}
