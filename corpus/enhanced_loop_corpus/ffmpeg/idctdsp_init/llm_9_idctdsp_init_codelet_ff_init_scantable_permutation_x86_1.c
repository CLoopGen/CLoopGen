#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_sse2_row_perm[8];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        idct_permutation[i]     = (i & 56) | idct_sse2_row_perm[i & 7];
        idct_permutation[i + 1] = ((i + 1) & 56) | idct_sse2_row_perm[(i + 1) & 7];
        idct_permutation[i + 2] = ((i + 2) & 56) | idct_sse2_row_perm[(i + 2) & 7];
        idct_permutation[i + 3] = ((i + 3) & 56) | idct_sse2_row_perm[(i + 3) & 7];
    }
}
