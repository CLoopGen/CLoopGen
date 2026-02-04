#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse iteration
    for (i = 63; i >= 0; i--)
        idct_permutation[63 - i] = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
}
