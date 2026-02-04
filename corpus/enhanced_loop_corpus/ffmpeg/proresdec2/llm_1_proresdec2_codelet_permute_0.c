#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern  uint8_t permutation[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 4) {
        dst[i]     = permutation[src[i]];
        dst[i + 1] = permutation[src[i + 1]];
        dst[i + 2] = permutation[src[i + 2]];
        dst[i + 3] = permutation[src[i + 3]];
    }
}
