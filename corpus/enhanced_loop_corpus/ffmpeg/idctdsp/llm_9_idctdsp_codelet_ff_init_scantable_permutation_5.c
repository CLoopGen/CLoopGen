#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        idct_permutation[i] = ((i << 1) & 36) | ((i & 7) << 2) | ((i >> 2) & 3);
        idct_permutation[63 - i] = (i & 36) | ((i & 1) << 4) | ((i >> 1) & 7);
    }
}
