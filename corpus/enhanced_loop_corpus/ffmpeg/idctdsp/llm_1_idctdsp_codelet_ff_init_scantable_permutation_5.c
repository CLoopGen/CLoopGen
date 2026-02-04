#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *idct_permutation;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        int base = i * 4;
        for (int j = 0; j < 4; j++) {
            int idx = base + j;
            idct_permutation[idx] = (idx & 36) | ((idx & 3) << 3) | ((idx >> 3) & 3);
        }
    }
}
