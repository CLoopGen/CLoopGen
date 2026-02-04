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
    ptrdiff_t idx = i * stride;
    pix[0] = v += block[0];
    pix[stride] = v += block[1];
    pix[2*stride] = v += block[2];
    pix[3*stride] = v + block[3];
    pix += stride;
    block += 4;
}
}
