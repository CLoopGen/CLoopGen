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
    for (i = 0; i < 4; ++i) {
        uint8_t v = pix[-1];
        if (block[0] >= 0) {
            pix[0] = v += block[0];
            pix[1] = v += block[1];
            pix[2] = v += block[2];
            pix[3] = v + block[3];
        }
        pix += stride;
        block += 4;
    }
}
