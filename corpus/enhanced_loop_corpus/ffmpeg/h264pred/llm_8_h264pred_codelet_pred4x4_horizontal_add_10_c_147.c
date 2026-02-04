#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern uint16_t *pix;
extern  int32_t *block;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    uint16_t v = pix[-1];
    v += block[0];
    pix[0] = v;
    v += block[1];
    pix[1] = v;
    v += block[2];
    pix[2] = v;
    v += block[3];
    pix[3] = v;
    v += block[4];
    pix[4] = v;
    v += block[5];
    pix[5] = v;
    v += block[6];
    pix[6] = v;
    v += block[7];
    pix[7] = v;
    pix += stride;
    block += 8;
}
}
