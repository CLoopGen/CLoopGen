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
for (i = 0; i < 2; i++) {
    uint8_t v1 = pix[0];
    uint8_t v2 = pix[stride];
    v1 += block[0]; v1 += block[4];
    v2 += block[1]; v2 += block[5];
    pix[1 * stride] = v1;
    pix[2 * stride] = v1 + block[8];
    pix[3 * stride] = v2;
    pix[4 * stride] = v2 + block[9];
    pix += 2;
    block += 2;
}
}
