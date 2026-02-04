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
for (i = 0; i < 16; i += 2) {
    uint16_t v = pix[0];
    v += block[0];
    pix[1 * stride] = v;
    v += block[8];
    pix[2 * stride] = v;
    v += block[16];
    pix[3 * stride] = v;
    v += block[24];
    pix[4 * stride] = v;
    v += block[32];
    pix[5 * stride] = v;
    v += block[40];
    pix[6 * stride] = v;
    v += block[48];
    pix[7 * stride] = v;
    // Unrolled second iteration with offset
    if (i + 1 < 16) {
        uint16_t v2 = pix[1];
        v2 += block[1];
        pix[1 * stride + 1] = v2;
        v2 += block[9];
        pix[2 * stride + 1] = v2;
        v2 += block[17];
        pix[3 * stride + 1] = v2;
        v2 += block[25];
        pix[4 * stride + 1] = v2;
        v2 += block[33];
        pix[5 * stride + 1] = v2;
        v2 += block[41];
        pix[6 * stride + 1] = v2;
        v2 += block[49];
        pix[7 * stride + 1] = v2;
        pix[8 * stride + 1] = v2 + block[57];
    }
    pix += 2;
    block += 2;
}
}
