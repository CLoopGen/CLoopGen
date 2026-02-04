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
    int i1, i2;
    int inner_h = (h + 1) / 2;  // ceil(h/2)
    for (i1 = 0; i1 < inner_h; i1++) {
        for (i2 = 0; i2 < 2 && (i1 * 2 + i2) < h; i2++) {
            i = i1 * 2 + i2;
            s += sq[pix1[0] - pix2[0]];
            s += sq[pix1[1] - pix2[1]];
            s += sq[pix1[2] - pix2[2]];
            s += sq[pix1[3] - pix2[3]];
            pix1 += stride;
            pix2 += stride;
        }
    }
}
