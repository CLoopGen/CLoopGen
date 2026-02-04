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
    uint32_t local_s = s;
    for (i = 0; i < h; i++) {
        uint8_t diff0 = pix1[0] - pix2[0];
        uint8_t diff1 = pix1[1] - pix2[1];
        uint8_t diff2 = pix1[2] - pix2[2];
        uint8_t diff3 = pix1[3] - pix2[3];
        local_s += sq[diff0] + sq[diff1];
        local_s += sq[diff2] + sq[diff3];
        uint8_t diff4 = pix1[4] - pix2[4];
        uint8_t diff5 = pix1[5] - pix2[5];
        uint8_t diff6 = pix1[6] - pix2[6];
        uint8_t diff7 = pix1[7] - pix2[7];
        local_s += sq[diff4] + sq[diff5];
        local_s += sq[diff6] + sq[diff7];
        uint8_t diff8 = pix1[8] - pix2[8];
        uint8_t diff9 = pix1[9] - pix2[9];
        uint8_t diff10 = pix1[10] - pix2[10];
        uint8_t diff11 = pix1[11] - pix2[11];
        local_s += sq[diff8] + sq[diff9];
        local_s += sq[diff10] + sq[diff11];
        uint8_t diff12 = pix1[12] - pix2[12];
        uint8_t diff13 = pix1[13] - pix2[13];
        uint8_t diff14 = pix1[14] - pix2[14];
        uint8_t diff15 = pix1[15] - pix2[15];
        local_s += sq[diff12] + sq[diff13];
        local_s += sq[diff14] + sq[diff15];
        pix1 += stride;
        pix2 += stride;
    }
    s = local_s;
}
