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
for (i = 0; i < 2; i++) {
    uint16_t v1 = pix[-1];
    uint16_t v2 = pix[stride - 1];
    pix[0]        = v1 += block[0];
    pix[1]        = v1 += block[1];
    pix[stride+0] = v2 += block[2];
    pix[stride+1] = v2 + block[3];
    pix += 2 * stride;
    block += 4;
}
}
