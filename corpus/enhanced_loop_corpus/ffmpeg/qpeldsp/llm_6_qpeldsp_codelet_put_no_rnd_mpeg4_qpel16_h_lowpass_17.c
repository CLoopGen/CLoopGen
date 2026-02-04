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



void loop() {
    for (i = 0; i < h; i++) {
        uint8_t temp[17];
        temp[0] = src[0]; temp[1] = src[1]; temp[2] = src[2]; temp[3] = src[3];
        temp[4] = src[4]; temp[5] = src[5]; temp[6] = src[6]; temp[7] = src[7];
        temp[8] = src[8]; temp[9] = src[9]; temp[10] = src[10]; temp[11] = src[11];
        temp[12] = src[12]; temp[13] = src[13]; temp[14] = src[14]; temp[15] = src[15];
        temp[16] = src[16];

        dst[0] = cm[(((temp[0] + temp[1]) * 20 - (temp[0] + temp[2]) * 6 + (temp[1] + temp[3]) * 3 - (temp[2] + temp[4])) + 15) >> 5];
        dst[1] = cm[(((temp[1] + temp[2]) * 20 - (temp[0] + temp[3]) * 6 + (temp[0] + temp[4]) * 3 - (temp[1] + temp[5])) + 15) >> 5];
        dst[2] = cm[(((temp[2] + temp[3]) * 20 - (temp[1] + temp[4]) * 6 + (temp[0] + temp[5]) * 3 - (temp[0] + temp[6])) + 15) >> 5];
        dst[3] = cm[(((temp[3] + temp[4]) * 20 - (temp[2] + temp[5]) * 6 + (temp[1] + temp[6]) * 3 - (temp[0] + temp[7])) + 15) >> 5];
        dst[4] = cm[(((temp[4] + temp[5]) * 20 - (temp[3] + temp[6]) * 6 + (temp[2] + temp[7]) * 3 - (temp[1] + temp[8])) + 15) >> 5];
        dst[5] = cm[(((temp[5] + temp[6]) * 20 - (temp[4] + temp[7]) * 6 + (temp[3] + temp[8]) * 3 - (temp[2] + temp[9])) + 15) >> 5];
        dst[6] = cm[(((temp[6] + temp[7]) * 20 - (temp[5] + temp[8]) * 6 + (temp[4] + temp[9]) * 3 - (temp[3] + temp[10])) + 15) >> 5];
        dst[7] = cm[(((temp[7] + temp[8]) * 20 - (temp[6] + temp[9]) * 6 + (temp[5] + temp[10]) * 3 - (temp[4] + temp[11])) + 15) >> 5];
        dst[8] = cm[(((temp[8] + temp[9]) * 20 - (temp[7] + temp[10]) * 6 + (temp[6] + temp[11]) * 3 - (temp[5] + temp[12])) + 15) >> 5];
        dst[9] = cm[(((temp[9] + temp[10]) * 20 - (temp[8] + temp[11]) * 6 + (temp[7] + temp[12]) * 3 - (temp[6] + temp[13])) + 15) >> 5];
        dst[10] = cm[(((temp[10] + temp[11]) * 20 - (temp[9] + temp[12]) * 6 + (temp[8] + temp[13]) * 3 - (temp[7] + temp[14])) + 15) >> 5];
        dst[11] = cm[(((temp[11] + temp[12]) * 20 - (temp[10] + temp[13]) * 6 + (temp[9] + temp[14]) * 3 - (temp[8] + temp[15])) + 15) >> 5];
        dst[12] = cm[(((temp[12] + temp[13]) * 20 - (temp[11] + temp[14]) * 6 + (temp[10] + temp[15]) * 3 - (temp[9] + temp[16])) + 15) >> 5];
        dst[13] = cm[(((temp[13] + temp[14]) * 20 - (temp[12] + temp[15]) * 6 + (temp[11] + temp[16]) * 3 - (temp[10] + temp[16])) + 15) >> 5];
        dst[14] = cm[(((temp[14] + temp[15]) * 20 - (temp[13] + temp[16]) * 6 + (temp[12] + temp[16]) * 3 - (temp[11] + temp[15])) + 15) >> 5];
        dst[15] = cm[(((temp[15] + temp[16]) * 20 - (temp[14] + temp[16]) * 6 + (temp[13] + temp[15]) * 3 - (temp[12] + temp[14])) + 15) >> 5];

        dst += dstStride;
        src += srcStride;
    }
}
