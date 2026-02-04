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
for (i = 0; i < 4; i++) {
    uint16_t v0 = pix[-1];
    uint16_t v1, v2, v3, v4, v5, v6, v7;
    v1 = (v0 += block[0]);
    v2 = (v1 += block[1]);
    v3 = (v2 += block[2]);
    v4 = (v3 += block[3]);
    v5 = (v4 += block[4]);
    v6 = (v5 += block[5]);
    v7 = (v6 += block[6]);
    pix[0] = v1;
    pix[1] = v2;
    pix[2] = v3;
    pix[3] = v4;
    pix[4] = v5;
    pix[5] = v6;
    pix[6] = v7;
    pix[7] = v7 + block[7];
    pix += stride;
    block += 8;
}
}
