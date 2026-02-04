#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3], temp4 = src[4];
    uint8_t temp5 = src[5], temp6 = src[6], temp7 = src[7], temp8 = src[8];

    dst[0] = cm[(((temp0 + temp1) * 20 - (temp0 + temp2) * 6 + (temp1 + temp3) * 3 - (temp2 + temp4)) + 16) >> 5];
    dst[1] = cm[(((temp1 + temp2) * 20 - (temp0 + temp3) * 6 + (temp0 + temp4) * 3 - (temp1 + temp5)) + 16) >> 5];
    dst[2] = cm[(((temp2 + temp3) * 20 - (temp1 + temp4) * 6 + (temp0 + temp5) * 3 - (temp0 + temp6)) + 16) >> 5];
    dst[3] = cm[(((temp3 + temp4) * 20 - (temp2 + temp5) * 6 + (temp1 + temp6) * 3 - (temp0 + temp7)) + 16) >> 5];
    dst[4] = cm[(((temp4 + temp5) * 20 - (temp3 + temp6) * 6 + (temp2 + temp7) * 3 - (temp1 + temp8)) + 16) >> 5];
    dst[5] = cm[(((temp5 + temp6) * 20 - (temp4 + temp7) * 6 + (temp3 + temp8) * 3 - (temp2 + temp8)) + 16) >> 5];
    dst[6] = cm[(((temp6 + temp7) * 20 - (temp5 + temp8) * 6 + (temp4 + temp8) * 3 - (temp3 + temp7)) + 16) >> 5];
    dst[7] = cm[(((temp7 + temp8) * 20 - (temp6 + temp8) * 6 + (temp5 + temp7) * 3 - (temp4 + temp6)) + 16) >> 5];

    dst += dstStride;
    src += srcStride;
}
}
