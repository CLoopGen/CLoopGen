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
ptrdiff_t offsets[9] = {0, stride, 2*stride, 3*stride, 4*stride, 5*stride, 6*stride, 7*stride, 8*stride};
for (i = 0; i < 8; i++) {
    uint16_t v = pix[0];
    int32_t b0 = block[0], b1 = block[8], b2 = block[16], b3 = block[24],
            b4 = block[32], b5 = block[40], b6 = block[48], b7 = block[56];
    v += b0;
    pix[offsets[1]] = v;
    v += b1;
    pix[offsets[2]] = v;
    v += b2;
    pix[offsets[3]] = v;
    v += b3;
    pix[offsets[4]] = v;
    v += b4;
    pix[offsets[5]] = v;
    v += b5;
    pix[offsets[6]] = v;
    v += b6;
    pix[offsets[7]] = v;
    pix[offsets[8]] = v + b7;
    pix++;
    block++;
}
}
