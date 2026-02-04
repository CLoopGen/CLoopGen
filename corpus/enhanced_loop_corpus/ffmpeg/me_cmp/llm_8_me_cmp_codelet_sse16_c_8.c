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
    s += sq[pix1[0] - pix2[0]];
    s += sq[pix1[2] - pix2[2]];
    s += sq[pix1[4] - pix2[4]];
    s += sq[pix1[6] - pix2[6]];
    s += sq[pix1[8] - pix2[8]];
    s += sq[pix1[10] - pix2[10]];
    s += sq[pix1[12] - pix2[12]];
    s += sq[pix1[14] - pix2[14]];
    pix1 += stride;
    pix2 += stride;
}
}
