#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        uint8_t low = i & 7;
        uint8_t high = i >> 3;
        idct_permutation[i] = (low << 3) | high;
    }
}
