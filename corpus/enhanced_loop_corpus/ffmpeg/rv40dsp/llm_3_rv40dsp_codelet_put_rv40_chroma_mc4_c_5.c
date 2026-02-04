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
    uint8_t s0, s1, s2, s3, s4;
    uint8_t t0, t1, t2, t3, t4;
    s0 = src[0]; s1 = src[1]; s2 = src[2]; s3 = src[3]; s4 = src[4];
    t0 = src[stride + 0]; t1 = src[stride + 1]; t2 = src[stride + 2]; t3 = src[stride + 3]; t4 = src[stride + 4];

    dst[0] = (((A * s0 + B * s1 + C * t0 + D * t1 + bias)) >> 6);
    dst[1] = (((A * s1 + B * s2 + C * t1 + D * t2 + bias)) >> 6);
    dst[2] = (((A * s2 + B * s3 + C * t2 + D * t3 + bias)) >> 6);
    dst[3] = (((A * s3 + B * s4 + C * t3 + D * t4 + bias)) >> 6);

    dst += stride;
    src += stride;
}
}
