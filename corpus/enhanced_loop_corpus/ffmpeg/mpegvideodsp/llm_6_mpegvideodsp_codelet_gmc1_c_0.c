#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int stride;
extern int h;
extern int rounder;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1];
    uint8_t temp2 = src[stride + 0], temp3 = src[stride + 1];
    dst[0] = (A * temp0 + B * temp1 + C * temp2 + D * temp3 + rounder) >> 8;

    uint8_t temp4 = src[2];
    uint8_t temp5 = src[stride + 2];
    dst[1] = (A * temp1 + B * temp4 + C * temp3 + D * temp5 + rounder) >> 8;

    uint8_t temp6 = src[3];
    uint8_t temp7 = src[stride + 3];
    dst[2] = (A * temp4 + B * temp6 + C * temp5 + D * temp7 + rounder) >> 8;

    uint8_t temp8 = src[4];
    uint8_t temp9 = src[stride + 4];
    dst[3] = (A * temp6 + B * temp8 + C * temp7 + D * temp9 + rounder) >> 8;

    uint8_t temp10 = src[5];
    uint8_t temp11 = src[stride + 5];
    dst[4] = (A * temp8 + B * temp10 + C * temp9 + D * temp11 + rounder) >> 8;

    uint8_t temp12 = src[6];
    uint8_t temp13 = src[stride + 6];
    dst[5] = (A * temp10 + B * temp12 + C * temp11 + D * temp13 + rounder) >> 8;

    uint8_t temp14 = src[7];
    uint8_t temp15 = src[stride + 7];
    dst[6] = (A * temp12 + B * temp14 + C * temp13 + D * temp15 + rounder) >> 8;

    uint8_t temp16 = src[8];
    uint8_t temp17 = src[stride + 8];
    dst[7] = (A * temp14 + B * temp16 + C * temp15 + D * temp17 + rounder) >> 8;

    dst += stride;
    src += stride;
}
}
