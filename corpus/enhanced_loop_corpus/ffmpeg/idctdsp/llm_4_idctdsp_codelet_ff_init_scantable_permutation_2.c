#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if (i % 8 != 7) {
            idct_permutation[i] = i;
        } else {
            idct_permutation[i] = i - 1;
        }
    }
}
