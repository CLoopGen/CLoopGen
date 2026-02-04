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
for (i = 0; i < 8; i++) {
    uint16_t v = pix[-1];
    int offsets[8] = {0,1,2,3,4,5,6,7};
    v += block[0]; pix[offsets[0]] = v;
    v += block[1]; pix[offsets[1]] = v;
    v += block[2]; pix[offsets[2]] = v;
    v += block[3]; pix[offsets[3]] = v;
    v += block[4]; pix[offsets[4]] = v;
    v += block[5]; pix[offsets[5]] = v;
    v += block[6]; pix[offsets[6]] = v;
    v += block[7]; pix[offsets[7]] = v;
    pix += stride;
    block += 8;
}
}
