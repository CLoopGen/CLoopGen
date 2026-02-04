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
    uint8_t v = pix[0];
    pix[1 * stride] = v += block[0];
    pix[2 * stride] = v += block[1];
    pix[3 * stride] = v += block[2];
    pix[4 * stride] = v += block[3];
    pix[5 * stride] = v += block[4];
    pix[6 * stride] = v += block[5];
    pix[7 * stride] = v += block[6];
    pix[8 * stride] = v + block[7];
    pix++;
    block += 8;
}
}
