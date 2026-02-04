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
    v += block[0];
    v += block[4];
    v += block[8];
    v += block[12];
    pix[1 * stride] = v;
    pix[2 * stride] = v;
    pix[3 * stride] = v;
    pix[4 * stride] = v;
    pix++;
    block++;
}
}
