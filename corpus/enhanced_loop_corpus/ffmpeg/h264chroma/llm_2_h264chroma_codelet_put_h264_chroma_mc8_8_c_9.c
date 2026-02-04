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
    ptrdiff_t offset = i * stride;
    dst[offset + 0] = ((((A * src[offset + 0] + B * src[offset + 1] + C * src[offset + stride + 0] + D * src[offset + stride + 1])) + 32) >> 6);
    dst[offset + 1] = ((((A * src[offset + 1] + B * src[offset + 2] + C * src[offset + stride + 1] + D * src[offset + stride + 2])) + 32) >> 6);
    dst[offset + 2] = ((((A * src[offset + 2] + B * src[offset + 3] + C * src[offset + stride + 2] + D * src[offset + stride + 3])) + 32) >> 6);
    dst[offset + 3] = ((((A * src[offset + 3] + B * src[offset + 4] + C * src[offset + stride + 3] + D * src[offset + stride + 4])) + 32) >> 6);
    dst[offset + 4] = ((((A * src[offset + 4] + B * src[offset + 5] + C * src[offset + stride + 4] + D * src[offset + stride + 5])) + 32) >> 6);
    dst[offset + 5] = ((((A * src[offset + 5] + B * src[offset + 6] + C * src[offset + stride + 5] + D * src[offset + stride + 6])) + 32) >> 6);
    dst[offset + 6] = ((((A * src[offset + 6] + B * src[offset + 7] + C * src[offset + stride + 6] + D * src[offset + stride + 7])) + 32) >> 6);
    dst[offset + 7] = ((((A * src[offset + 7] + B * src[offset + 8] + C * src[offset + stride + 7] + D * src[offset + stride + 8])) + 32) >> 6);
}
}
