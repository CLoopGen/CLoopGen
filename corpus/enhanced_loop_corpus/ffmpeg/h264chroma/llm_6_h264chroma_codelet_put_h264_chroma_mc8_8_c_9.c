#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int h;
extern uint8_t *dst;
extern uint8_t *src;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp0 = src[0], temp1 = src[1], temp2 = src[2], temp3 = src[3];
    uint8_t temp4 = src[4], temp5 = src[5], temp6 = src[6], temp7 = src[7], temp8 = src[8];
    uint8_t s0 = src[stride + 0], s1 = src[stride + 1], s2 = src[stride + 2], s3 = src[stride + 3];
    uint8_t s4 = src[stride + 4], s5 = src[stride + 5], s6 = src[stride + 6], s7 = src[stride + 7], s8 = src[stride + 8];

    dst[0] = ((((A * temp0 + B * temp1 + C * s0 + D * s1)) + 32) >> 6);
    dst[1] = ((((A * temp1 + B * temp2 + C * s1 + D * s2)) + 32) >> 6);
    dst[2] = ((((A * temp2 + B * temp3 + C * s2 + D * s3)) + 32) >> 6);
    dst[3] = ((((A * temp3 + B * temp4 + C * s3 + D * s4)) + 32) >> 6);
    dst[4] = ((((A * temp4 + B * temp5 + C * s4 + D * s5)) + 32) >> 6);
    dst[5] = ((((A * temp5 + B * temp6 + C * s5 + D * s6)) + 32) >> 6);
    dst[6] = ((((A * temp6 + B * temp7 + C * s6 + D * s7)) + 32) >> 6);
    dst[7] = ((((A * temp7 + B * temp8 + C * s7 + D * s8)) + 32) >> 6);

    dst += stride;
    src += stride;
}
}
