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
    ptrdiff_t offset = i * stride;
    uint8_t temp[4];
    temp[0] = ((A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1] + bias) >> 6);
    temp[1] = ((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2] + bias) >> 6);
    temp[2] = ((A * src[offset + 2] + B * src[offset + 3] + C * src[offset + stride + 2] + D * src[offset + stride + 3] + bias) >> 6);
    temp[3] = ((A * src[offset + 3] + B * src[offset + 4] + C * src[offset + stride + 3] + D * src[offset + stride + 4] + bias) >> 6);
    dst[offset + 0] = ((dst[offset + 0] + temp[0] + 1) >> 1);
    dst[offset + 1] = ((dst[offset + 1] + temp[1] + 1) >> 1);
    dst[offset + 2] = ((dst[offset + 2] + temp[2] + 1) >> 1);
    dst[offset + 3] = ((dst[offset + 3] + temp[3] + 1) >> 1);
}
}
