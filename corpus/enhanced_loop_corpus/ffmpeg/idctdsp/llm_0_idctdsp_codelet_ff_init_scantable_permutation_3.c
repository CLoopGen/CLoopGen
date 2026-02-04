#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 8; outer++) {
        for (int inner = 0; inner < 8; inner++) {
            int i = (outer << 3) | inner;
            idct_permutation[i] = (i & 56) | ((i & 6) >> 1) | ((i & 1) << 2);
        }
    }
}
