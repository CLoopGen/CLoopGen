#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_sse2_row_perm[8];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_perm[64];
    for (i = 0; i < 64; i++) {
        local_perm[i] = (i & 56) | idct_sse2_row_perm[i & 7];
        idct_permutation[i] = local_perm[i]; // Introduces WAW if called repeatedly, but no loop-carried dep
    }
}
