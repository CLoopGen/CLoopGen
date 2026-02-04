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
    for (i = 0; i < 8; i++) {
        uint16_t v = pix[0];
        int32_t b0 = block[0];
        int32_t b8 = block[8];
        int32_t b16 = block[16];
        int32_t b24 = block[24];
        int32_t b32 = block[32];
        int32_t b40 = block[40];
        int32_t b48 = block[48];
        int32_t b56 = block[56];

        v += b0;
        pix[1 * stride] = v;
        v += b8;
        pix[2 * stride] = v;
        v += b16;
        pix[3 * stride] = v;
        v += b24;
        pix[4 * stride] = v;
        v += b32;
        pix[5 * stride] = v;
        v += b40;
        pix[6 * stride] = v;
        v += b48;
        pix[7 * stride] = v;
        pix[8 * stride] = v + b56;

        pix++;
        block++;
    }
}
