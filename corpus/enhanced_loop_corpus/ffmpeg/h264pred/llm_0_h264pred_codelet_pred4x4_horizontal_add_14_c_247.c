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
    for (int k = 0; k < 2; k++) {
        for (i = 0; i < 2; i++) {
            uint16_t v = pix[-1];
            pix[0] = v += block[0];
            pix[1] = v += block[1];
            pix[2] = v += block[2];
            pix[3] = v + block[3];
            pix += stride;
            block += 4;
        }
    }
}
