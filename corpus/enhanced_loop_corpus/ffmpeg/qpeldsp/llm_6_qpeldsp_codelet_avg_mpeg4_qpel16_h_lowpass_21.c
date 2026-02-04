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
    uint8_t temp[17];
    src += srcStride;
    for (int j = 0; j < 17; j++) {
        temp[j] = src[j - srcStride];
    }
    dst[0] = (((dst[0]) + cm[(((temp[0] + temp[1]) * 20 - (temp[0] + temp[2]) * 6 + (temp[1] + temp[3]) * 3 - (temp[2] + temp[4])) + 16) >> 5] + 1) >> 1);
    dst[1] = (((dst[1]) + cm[(((temp[1] + temp[2]) * 20 - (temp[0] + temp[3]) * 6 + (temp[0] + temp[4]) * 3 - (temp[1] + temp[5])) + 16) >> 5] + 1) >> 1);
    dst[2] = (((dst[2]) + cm[(((temp[2] + temp[3]) * 20 - (temp[1] + temp[4]) * 6 + (temp[0] + temp[5]) * 3 - (temp[0] + temp[6])) + 16) >> 5] + 1) >> 1);
    dst[3] = (((dst[3]) + cm[(((temp[3] + temp[4]) * 20 - (temp[2] + temp[5]) * 6 + (temp[1] + temp[6]) * 3 - (temp[0] + temp[7])) + 16) >> 5] + 1) >> 1);
    dst[4] = (((dst[4]) + cm[(((temp[4] + temp[5]) * 20 - (temp[3] + temp[6]) * 6 + (temp[2] + temp[7]) * 3 - (temp[1] + temp[8])) + 16) >> 5] + 1) >> 1);
    dst[5] = (((dst[5]) + cm[(((temp[5] + temp[6]) * 20 - (temp[4] + temp[7]) * 6 + (temp[3] + temp[8]) * 3 - (temp[2] + temp[9])) + 16) >> 5] + 1) >> 1);
    dst[6] = (((dst[6]) + cm[(((temp[6] + temp[7]) * 20 - (temp[5] + temp[8]) * 6 + (temp[4] + temp[9]) * 3 - (temp[3] + temp[10])) + 16) >> 5] + 1) >> 1);
    dst[7] = (((dst[7]) + cm[(((temp[7] + temp[8]) * 20 - (temp[6] + temp[9]) * 6 + (temp[5] + temp[10]) * 3 - (temp[4] + temp[11])) + 16) >> 5] + 1) >> 1);
    dst[8] = (((dst[8]) + cm[(((temp[8] + temp[9]) * 20 - (temp[7] + temp[10]) * 6 + (temp[6] + temp[11]) * 3 - (temp[5] + temp[12])) + 16) >> 5] + 1) >> 1);
    dst[9] = (((dst[9]) + cm[(((temp[9] + temp[10]) * 20 - (temp[8] + temp[11]) * 6 + (temp[7] + temp[12]) * 3 - (temp[6] + temp[13])) + 16) >> 5] + 1) >> 1);
    dst[10] = (((dst[10]) + cm[(((temp[10] + temp[11]) * 20 - (temp[9] + temp[12]) * 6 + (temp[8] + temp[13]) * 3 - (temp[7] + temp[14])) + 16) >> 5] + 1) >> 1);
    dst[11] = (((dst[11]) + cm[(((temp[11] + temp[12]) * 20 - (temp[10] + temp[13]) * 6 + (temp[9] + temp[14]) * 3 - (temp[8] + temp[15])) + 16) >> 5] + 1) >> 1);
    dst[12] = (((dst[12]) + cm[(((temp[12] + temp[13]) * 20 - (temp[11] + temp[14]) * 6 + (temp[10] + temp[15]) * 3 - (temp[9] + temp[16])) + 16) >> 5] + 1) >> 1);
    dst[13] = (((dst[13]) + cm[(((temp[13] + temp[14]) * 20 - (temp[12] + temp[15]) * 6 + (temp[11] + temp[16]) * 3 - (temp[10] + temp[16])) + 16) >> 5] + 1) >> 1);
    dst[14] = (((dst[14]) + cm[(((temp[14] + temp[15]) * 20 - (temp[13] + temp[16]) * 6 + (temp[12] + temp[16]) * 3 - (temp[11] + temp[15])) + 16) >> 5] + 1) >> 1);
    dst[15] = (((dst[15]) + cm[(((temp[15] + temp[16]) * 20 - (temp[14] + temp[16]) * 6 + (temp[13] + temp[15]) * 3 - (temp[12] + temp[14])) + 16) >> 5] + 1) >> 1);
    dst += dstStride;
}
}
