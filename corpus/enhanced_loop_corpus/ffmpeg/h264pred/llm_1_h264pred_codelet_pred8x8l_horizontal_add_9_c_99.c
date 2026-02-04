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
        for (int k = 0; k < 2; k++) {
            uint16_t v = pix[-1];
            pix[0] = v += block[0];
            pix[1] = v += block[1];
            pix[2] = v += block[2];
            pix[3] = v += block[3];
            pix[4] = v += block[4];
            pix[5] = v += block[5];
            pix[6] = v += block[6];
            pix[7] = v + block[7];
            pix += stride;
            block += 8;
        }
    }
}
