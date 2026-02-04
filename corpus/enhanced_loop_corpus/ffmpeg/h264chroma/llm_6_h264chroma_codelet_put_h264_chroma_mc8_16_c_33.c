#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint16_t *dst;
extern uint16_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint16_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
    uint16_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7], temp8 = src[8];
    uint16_t s0 = temp0, s1 = temp1, s2 = temp2, s3 = temp3;
    uint16_t s4 = temp4, s5 = temp5, s6 = temp6, s7 = temp7, s8 = temp8;
    uint16_t t0 = A * s0 + B * s1 + C * src[stride + 0] + D * src[stride + 1];
    uint16_t t1 = A * s1 + B * s2 + C * src[stride + 1] + D * src[stride + 2];
    uint16_t t2 = A * s2 + B * s3 + C * src[stride + 2] + D * src[stride + 3];
    uint16_t t3 = A * s3 + B * s4 + C * src[stride + 3] + D * src[stride + 4];
    uint16_t t4 = A * s4 + B * s5 + C * src[stride + 4] + D * src[stride + 5];
    uint16_t t5 = A * s5 + B * s6 + C * src[stride + 5] + D * src[stride + 6];
    uint16_t t6 = A * s6 + B * s7 + C * src[stride + 6] + D * src[stride + 7];
    uint16_t t7 = A * s7 + B * s8 + C * src[stride + 7] + D * src[stride + 8];
    dst[0] = ((t0 + 32) >> 6);
    dst[1] = ((t1 + 32) >> 6);
    dst[2] = ((t2 + 32) >> 6);
    dst[3] = ((t3 + 32) >> 6);
    dst[4] = ((t4 + 32) >> 6);
    dst[5] = ((t5 + 32) >> 6);
    dst[6] = ((t6 + 32) >> 6);
    dst[7] = ((t7 + 32) >> 6);
    dst += stride;
    src += stride;
}
}
