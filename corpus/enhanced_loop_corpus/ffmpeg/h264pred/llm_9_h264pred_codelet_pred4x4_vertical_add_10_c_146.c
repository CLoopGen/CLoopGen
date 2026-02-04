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
    uint16_t v1 = pix[0];
    uint16_t v2 = pix[stride];
    v1 += block[0];
    v2 += block[1];
    pix[1 * stride] = v1;
    pix[2 * stride] = v2;
    v1 += block[4];
    v2 += block[5];
    pix[3 * stride] = v1;
    pix[4 * stride] = v2;
    pix += 2;
    block += 2;
}
}
