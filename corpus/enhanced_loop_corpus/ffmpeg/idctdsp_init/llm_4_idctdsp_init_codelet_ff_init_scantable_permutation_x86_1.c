#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_sse2_row_perm[8];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if ((i & 7) != 0) {
            idct_permutation[i] = (i & 56) | idct_sse2_row_perm[i & 7];
        } else {
            idct_permutation[i] = i & 56;
        }
    }
}
