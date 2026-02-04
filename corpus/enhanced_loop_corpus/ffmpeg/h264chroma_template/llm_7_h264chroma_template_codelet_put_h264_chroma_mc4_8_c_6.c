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
ptrdiff_t offset = 0;
for (i = 0; i < h; i++) {
    int val0 = A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1];
    int val1 = A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2];
    int val2 = A * src[offset + 2] + B * src[offset + 3] + C * src[offset + stride + 2] + D * src[offset + stride + 3];
    int val3 = A * src[offset + 3] + B * src[offset + 4] + C * src[offset + stride + 3] + D * src[offset + stride + 4];

    dst[offset + 0] = ((val0 + 32) >> 6);
    dst[offset + 1] = ((val1 + 32) >> 6);
    dst[offset + 2] = ((val2 + 32) >> 6);
    dst[offset + 3] = ((val3 + 32) >> 6);

    offset += stride;
}
}
