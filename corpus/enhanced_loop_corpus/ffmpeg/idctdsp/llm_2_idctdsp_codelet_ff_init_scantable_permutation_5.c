#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes to cover all)
    // First pass: even indices
    for (i = 0; i < 64; i += 2) {
        idct_permutation[i] = (i & 36) | ((i & 3) << 3) | ((i >> 3) & 3);
    }
    // Second pass: odd indices
    for (i = 1; i < 64; i += 2) {
        idct_permutation[i] = (i & 36) | ((i & 3) << 3) | ((i >> 3) & 3);
    }
}
