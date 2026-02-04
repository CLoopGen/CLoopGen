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
    uint16_t v = pix[-1];
    pix[0] = v += block[0];
    if (i != 2) {
        pix[1] = v += block[1];
        pix[2] = v += block[2];
        pix[3] = v + block[3];
    } else {
        // Skip updates for middle iteration
        pix[1] = v;
        pix[2] = v;
        pix[3] = v;
    }
    pix += stride;
    block += 4;
}
}
