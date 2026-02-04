#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i += 2) {
    const int srcB = src[-2 * srcStride];
    const int srcA = src[-1 * srcStride];
    const int src0 = src[0 * srcStride];
    const int src1 = src[1 * srcStride];
    const int src2 = src[2 * srcStride];
    const int src3 = src[3 * srcStride];
    const int src4 = src[4 * srcStride];
    const int src5 = src[5 * srcStride];
    const int src6 = src[6 * srcStride];
    const int src7 = src[7 * srcStride];
    const int src8 = src[8 * srcStride];
    const int src9 = src[9 * srcStride];
    const int src10 = src[10 * srcStride];

    // Process two pixels per iteration with reduced updates
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-1 * srcB + -2 * srcA + 96 * src0 + 42 * src1 + -7 * src2) + 64) >> 7] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((-1 * srcA + -2 * src0 + 96 * src1 + 42 * src2 + -7 * src3) + 64) >> 7] + 1) >> 1;

    dst += 2;
    src += 2;
}
}
