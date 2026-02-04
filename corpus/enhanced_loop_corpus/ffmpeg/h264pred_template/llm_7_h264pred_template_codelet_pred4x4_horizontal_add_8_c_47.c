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
    uint8_t accum = 0;
    for (i = 0; i < 4; i++) {
        uint8_t v = pix[-1] + accum;
        accum = block[0] + block[1] + block[2] + block[3];
        pix[0] = v + block[0];
        pix[1] = v + block[0] + block[1];
        pix[2] = v + block[0] + block[1] + block[2];
        pix[3] = v + accum;
        pix += stride;
        block += 4;
    }
}
