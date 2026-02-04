#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t simple_mmx_permutation[64];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        idct_permutation[2*i]     = simple_mmx_permutation[2*i];
        idct_permutation[2*i + 1] = simple_mmx_permutation[2*i + 1];
    }
}
