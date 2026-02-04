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
for (i = 0; i < 8; ++i) {
    uint8_t v = pix[0];
    if (block[0] >= 0) {
        v += block[0];
        pix[1 * stride] = v;
        if (block[8] < 10) {
            v += block[8];
            pix[2 * stride] = v;
        } else {
            pix[2 * stride] = v;
        }
        v += block[16]; pix[3 * stride] = v;
        v += block[24]; pix[4 * stride] = v;
        v += block[32]; pix[5 * stride] = v;
        v += block[40]; pix[6 * stride] = v;
        v += block[48]; pix[7 * stride] = v;
        pix[8 * stride] = v + block[56];
    } else {
        pix[1 * stride] = v;
        pix[2 * stride] = v;
        pix[3 * stride] = v;
        pix[4 * stride] = v;
        pix[5 * stride] = v;
        pix[6 * stride] = v;
        pix[7 * stride] = v;
        pix[8 * stride] = v;
    }
    pix++;
    block++;
}
}
