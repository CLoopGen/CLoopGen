#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t simple_mmx_permutation[64];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse array from end to beginning
    for (i = 63; i >= 0; i--) {
        idct_permutation[i] = simple_mmx_permutation[i];
    }
}
