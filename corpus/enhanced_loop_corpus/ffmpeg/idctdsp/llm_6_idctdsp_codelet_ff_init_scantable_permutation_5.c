#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = (i & 36) | ((i & 3) << 3) | ((i >> 3) & 3);
    }
    for (i = 0; i < 64; i++) {
        idct_permutation[i] = temp[i];
    }
}
