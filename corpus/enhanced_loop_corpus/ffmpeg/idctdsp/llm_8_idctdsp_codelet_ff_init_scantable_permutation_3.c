#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        idct_permutation[i] = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
        idct_permutation[i + 32] = ((i + 32) & 56) | (((i + 32) & 6) >> 1) | (((i + 32) & 1) << 2);
    }
}
