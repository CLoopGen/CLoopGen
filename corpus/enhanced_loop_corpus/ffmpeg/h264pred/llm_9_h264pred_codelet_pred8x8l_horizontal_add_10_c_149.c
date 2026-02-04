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
    uint16_t v0 = pix[-1];
    uint16_t v1 = pix[stride - 1];
    uint16_t v2 = pix[2*stride - 1];
    uint16_t v3 = pix[3*stride - 1];

    v0 += block[0];  pix[0]           = v0;
    v1 += block[8];  pix[stride]      = v1;
    v2 += block[16]; pix[2*stride]    = v2;
    v3 += block[24]; pix[3*stride]    = v3;

    v0 += block[1];  pix[1]           = v0;
    v1 += block[9];  pix[stride + 1]  = v1;
    v2 += block[17]; pix[2*stride + 1]= v2;
    v3 += block[25]; pix[3*stride + 1]= v3;

    v0 += block[2];  pix[2]           = v0;
    v1 += block[10]; pix[stride + 2]  = v1;
    v2 += block[18]; pix[2*stride + 2]= v2;
    v3 += block[26]; pix[3*stride + 2]= v3;

    v0 += block[3];  pix[3]           = v0;
    v1 += block[11]; pix[stride + 3]  = v1;
    v2 += block[19]; pix[2*stride + 3]= v2;
    v3 += block[27]; pix[3*stride + 3]= v3;

    v0 += block[4];  pix[4]           = v0;
    v1 += block[12]; pix[stride + 4]  = v1;
    v2 += block[20]; pix[2*stride + 4]= v2;
    v3 += block[28]; pix[3*stride + 4]= v3;

    v0 += block[5];  pix[5]           = v0;
    v1 += block[13]; pix[stride + 5]  = v1;
    v2 += block[21]; pix[2*stride + 5]= v2;
    v3 += block[29]; pix[3*stride + 5]= v3;

    v0 += block[6];  pix[6]           = v0;
    v1 += block[14]; pix[stride + 6]  = v1;
    v2 += block[22]; pix[2*stride + 6]= v2;
    v3 += block[30]; pix[3*stride + 6]= v3;

    v0 += block[7];  pix[7]           = v0;
    v1 += block[15]; pix[stride + 7]  = v1;
    v2 += block[23]; pix[2*stride + 7]= v2;
    v3 += block[31]; pix[3*stride + 7]= v3;

    pix += 4 * stride;
    block += 32;
}
}
