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
    const int srcB0 = src[-2 * srcStride];
    const int srcA0 = src[-1 * srcStride];
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
    const int src11 = src[11 * srcStride];
    const int src12 = src[12 * srcStride];

    // First output pixel
    dst[0 * dstStride] = cm[((-1 * srcB0 + -2 * srcA0 + 96 * src0 + 42 * src1 + -7 * src2) + 64) >> 7];
    // Second output pixel (shifted by one in the sequence)
    dst[1 * dstStride] = cm[((-1 * srcA0 + -2 * src0 + 96 * src1 + 42 * src2 + -7 * src3) + 64) >> 7];

    // Process second sample if within bounds
    if (i + 1 < w) {
        const int srcB1 = src[-1 * srcStride];
        const int srcA1 = src[0 * srcStride];
        const int src1_0 = src[1 * srcStride];
        const int src1_1 = src[2 * srcStride];
        const int src1_2 = src[3 * srcStride];
        const int src1_3 = src[4 * srcStride];
        const int src1_4 = src[5 * srcStride];
        const int src1_5 = src[6 * srcStride];

        dst[2 * dstStride] = cm[((-1 * srcB1 + -2 * srcA1 + 96 * src1_0 + 42 * src1_1 + -7 * src1_2) + 64) >> 7];
        dst[3 * dstStride] = cm[((-1 * srcA1 + -2 * src1_0 + 96 * src1_1 + 42 * src1_2 + -7 * src1_3) + 64) >> 7];
        dst += 2;
        src += 2;
    } else {
        dst++;
        src++;
    }
}
}
