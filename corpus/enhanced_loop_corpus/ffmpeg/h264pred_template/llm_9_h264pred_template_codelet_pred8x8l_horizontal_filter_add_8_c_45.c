#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *src;
extern  int16_t *block;
extern uint8_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) { // Doubled trip count
    uint8_t v = pix[i % 8];
    src[0] = v += block[0];
    src[1] = v += block[1];
    src[2] = v += block[2];
    src[3] = v += block[3];
    // Reduce operations: only unroll 4 writes instead of 8
    src[4] = v += block[4];
    src += stride;
    block += 8;
}
}
