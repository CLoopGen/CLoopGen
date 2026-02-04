#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t prev = 0;
    for (i = 0; i < 64; i++) {
        uint8_t curr = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2) ^ prev;
        idct_permutation[i] = curr;
        prev = curr;
    }
}
