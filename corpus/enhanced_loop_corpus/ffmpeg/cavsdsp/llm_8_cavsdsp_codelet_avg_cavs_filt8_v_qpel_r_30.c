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

    // Process two output pixels per iteration with reduced updates
    if (i + 0 < w) {
        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-7 * srcA + 42 * src0 + 96 * src1 - 2 * src2 - src3) + 64) >> 7] + 1) >> 1;
        dst++;
        src++;
    }

    if (i + 1 < w) {
        const int nextA = src[-1 * srcStride];
        const int next0 = src[0 * srcStride];
        const int next1 = src[1 * srcStride];
        const int next2 = src[2 * srcStride];
        const int next3 = src[3 * srcStride];
        const int next4 = src[4 * srcStride];
        dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((-7 * nextA + 42 * next0 + 96 * next1 - 2 * next2 - next3) + 64) >> 7] + 1) >> 1;
        dst++;
        src++;
    }
}
}
