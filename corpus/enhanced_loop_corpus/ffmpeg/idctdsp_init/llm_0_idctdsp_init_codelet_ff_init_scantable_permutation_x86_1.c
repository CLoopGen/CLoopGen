#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_sse2_row_perm[8];
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8; j++) {
        for (i = j * 8; i < (j + 1) * 8; i++) {
            idct_permutation[i] = (i & 56) | idct_sse2_row_perm[i & 7];
        }
    }
}
