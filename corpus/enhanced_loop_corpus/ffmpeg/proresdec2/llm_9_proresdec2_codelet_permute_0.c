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
    uint8_t temp1, temp2;
    for (i = 0; i < 64; i++) {
        temp1 = src[i] ^ 0x0F;
        temp2 = (src[i] >> 4) | (src[i] << 4); // bit reverse upper/lower nibble
        dst[i] = permutation[temp1 & 0x3F] ^ permutation[temp2 & 0x3F];
    }
}
