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
    uint16_t v = pix[0];
    if (v > 255) {
        pix[1 * stride] = v;
        pix += 1;
        block += 1;
        continue;
    }
    v += block[0];
    pix[1 * stride] = v;
    v += block[4];
    pix[2 * stride] = v;
    v += block[8];
    pix[3 * stride] = v;
    pix[4 * stride] = v + block[12];
    pix++;
    block++;
}
}
