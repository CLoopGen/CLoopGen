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
for (i = 0; i < 8; i++) {
    uint8_t v = pix[0];
    int offset = 0;
    if (i % 2 == 0) {
        v += block[offset]; offset += 8;
        pix[1 * stride] = v;
        v += block[offset]; offset += 8;
        pix[2 * stride] = v;
        v += block[offset]; offset += 8;
        pix[3 * stride] = v;
        v += block[offset]; offset += 8;
        pix[4 * stride] = v;
    } else {
        // Skip first two accumulations for odd iterations
        offset = 16;
        v += block[16]; pix[3 * stride] = v;
        v += block[24]; pix[4 * stride] = v;
    }
    v += block[32]; pix[5 * stride] = v;
    v += block[40]; pix[6 * stride] = v;
    v += block[48]; pix[7 * stride] = v;
    pix[8 * stride] = v + block[56];
    pix++;
    block++;
}
}
