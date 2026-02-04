#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        idct_permutation[i]     = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
        if (i + 1 < 64) idct_permutation[i + 1] = ((i + 1) & 56) | (((i + 1) & 6) >> 1) | (((i + 1) & 1) << 2);
        if (i + 2 < 64) idct_permutation[i + 2] = ((i + 2) & 56) | (((i + 2) & 6) >> 1) | (((i + 2) & 1) << 2);
        if (i + 3 < 64) idct_permutation[i + 3] = ((i + 3) & 56) | (((i + 3) & 6) >> 1) | (((i + 3) & 1) << 2);
    }
}
