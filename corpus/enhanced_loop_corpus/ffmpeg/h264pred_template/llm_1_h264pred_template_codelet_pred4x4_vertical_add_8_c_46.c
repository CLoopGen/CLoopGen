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
        for (int k = 0; k < 2; k++) {
            uint8_t v = pix[0];
            pix[1 * stride] = v += block[0];
            pix[2 * stride] = v += block[4];
            pix[3 * stride] = v += block[8];
            pix[4 * stride] = v + block[12];
            pix++;
            block++;
        }
    }
}
