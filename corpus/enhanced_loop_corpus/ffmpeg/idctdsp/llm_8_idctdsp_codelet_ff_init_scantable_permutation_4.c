#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 2) {
        int idx = i >> 1;
        idct_permutation[idx] = ((idx & 7) << 3) | (idx >> 3);
    }
}
