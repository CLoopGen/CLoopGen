#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint8_t *pix;
extern  int16_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    uint8_t v = pix[-1];
    pix[0] = v += block[0];
    pix[1] = v += block[1];
    pix[2] = v += block[2];
    pix[3] = v += block[3];
    pix[4] = v += block[4];
    pix[5] = v += block[5];
    pix[6] = v += block[6];
    pix[7] = v += block[7];
    pix[8] = v += block[8];
    pix[9] = v += block[9];
    pix[10] = v += block[10];
    pix[11] = v += block[11];
    pix[12] = v += block[12];
    pix[13] = v += block[13];
    pix[14] = v += block[14];
    pix[15] = v + block[15];
    pix += stride;
    block += 16;
}
}
