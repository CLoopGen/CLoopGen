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
    for (i = 0; i < 64; i++) {
        int index = (i * 7) % 64; // Strided access with stride of 7 modulo 64
        dst[index] = permutation[src[index]];
    }
}
