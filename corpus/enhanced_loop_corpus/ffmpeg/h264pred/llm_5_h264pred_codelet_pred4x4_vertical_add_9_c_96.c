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
for (i = 0; i < 4; ++i) {
    uint16_t v = pix[0];
    int offset = i % 2;
    pix[1 * stride] = v += block[0];
    if (offset == 0) {
        pix[2 * stride] = v += block[4];
        pix[3 * stride] = v += block[8];
        pix[4 * stride] = v + block[12];
    } else {
        pix[2 * stride] = v;
        pix[3 * stride] = v;
        pix[4 * stride] = v;
    }
    pix++;
    block++;
}
}
