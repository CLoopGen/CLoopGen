#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix1;
extern uint8_t *pix2;
extern ptrdiff_t stride;
extern int h;
extern int s;
extern int i;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t diff0 = pix1[0] - pix2[0];
        uint8_t diff1 = pix1[1] - pix2[1];
        uint8_t diff2 = pix1[2] - pix2[2];
        uint8_t diff3 = pix1[3] - pix2[3];

        if (diff0 > 4 || diff1 > 4 || diff2 > 4 || diff3 > 4) {
            s += sq[diff0];
            s += sq[diff1];
            s += sq[diff2];
            s += sq[diff3];
        }

        pix1 += stride;
        pix2 += stride;
    }
}
