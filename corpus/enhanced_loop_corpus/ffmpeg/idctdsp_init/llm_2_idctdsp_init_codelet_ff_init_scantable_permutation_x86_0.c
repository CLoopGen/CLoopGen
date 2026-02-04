#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t simple_mmx_permutation[64];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to handle even and odd indices
    for (i = 0; i < 64; i += 2) {
        idct_permutation[i] = simple_mmx_permutation[i];
        if (i + 1 < 64) {
            idct_permutation[i + 1] = simple_mmx_permutation[i + 1];
        }
    }
}
