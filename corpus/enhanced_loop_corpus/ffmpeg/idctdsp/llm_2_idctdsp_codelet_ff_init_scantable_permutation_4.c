#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by 2
    // This modifies the access pattern to write two elements per iteration consecutively
    for (i = 0; i < 64; i += 2) {
        idct_permutation[i]     = ((i & 7) << 3) | (i >> 3);
        if (i + 1 < 64) {
            idct_permutation[i + 1] = (((i + 1) & 7) << 3) | ((i + 1) >> 3);
        }
    }
}
