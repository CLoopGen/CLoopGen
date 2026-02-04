#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *src;
extern  int32_t *block;
extern uint16_t pix[8];
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint16_t v0 = pix[i];
    uint16_t v1 = pix[(i + 4) & 7];
    src[0] = v0 += block[0];
    src[1] = v0 += block[1];
    src[2] = v0 += block[2];
    src[3] = v0 += block[3];
    src[4] = v1 += block[4];
    src[5] = v1 += block[5];
    src[6] = v1 += block[6];
    src[7] = v1 += block[7];
    src += stride;
    block += 8;
}
}
