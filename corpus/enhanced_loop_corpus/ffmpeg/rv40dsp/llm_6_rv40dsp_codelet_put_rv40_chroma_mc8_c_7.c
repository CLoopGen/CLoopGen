#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int temp0 = A * src[0] + B * src[1] + C * src[stride + 0] + D * src[stride + 1];
    int temp1 = A * src[1] + B * src[2] + C * src[stride + 1] + D * src[stride + 2];
    int temp2 = A * src[2] + B * src[3] + C * src[stride + 2] + D * src[stride + 3];
    int temp3 = A * src[3] + B * src[4] + C * src[stride + 3] + D * src[stride + 4];
    int temp4 = A * src[4] + B * src[5] + C * src[stride + 4] + D * src[stride + 5];
    int temp5 = A * src[5] + B * src[6] + C * src[stride + 5] + D * src[stride + 6];
    int temp6 = A * src[6] + B * src[7] + C * src[stride + 6] + D * src[stride + 7];
    int temp7 = A * src[7] + B * src[8] + C * src[stride + 7] + D * src[stride + 8];

    dst[0] = (temp0 + bias) >> 6;
    dst[1] = (temp1 + bias) >> 6;
    dst[2] = (temp2 + bias) >> 6;
    dst[3] = (temp3 + bias) >> 6;
    dst[4] = (temp4 + bias) >> 6;
    dst[5] = (temp5 + bias) >> 6;
    dst[6] = (temp6 + bias) >> 6;
    dst[7] = (temp7 + bias) >> 6;

    dst += stride;
    src += stride;
}
}
