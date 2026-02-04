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
    v += block[0];
    pix[1 * stride] = v;
    v += block[8];
    pix[2 * stride] = v;
    v += block[16];
    pix[3 * stride] = v;
    v += block[24];
    pix[4 * stride] = v;
    pix += 2;
    block += 2;
}
}
