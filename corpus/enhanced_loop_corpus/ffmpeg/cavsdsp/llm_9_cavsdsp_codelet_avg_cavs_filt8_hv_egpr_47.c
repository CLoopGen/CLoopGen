#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src2;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: downsampled processing with simplified coefficients
for (i = 0; i < w; i++) {
    // Reduce number of temporals loaded
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];

    // Simplify computation: use only central terms and reduce arithmetic depth
    // Approximate original behavior with fewer operations
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(tmp0 + 64 * src2[0 * srcStride] + 32) >> 6] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(tmp1 + 64 * src2[1 * srcStride] + 32) >> 6] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(tmp2 + 64 * src2[2 * srcStride] + 32) >> 6] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[(tmp3 + 64 * src2[3 * srcStride] + 32) >> 6] + 1) >> 1;

    // Skip updating bottom half of the block to reduce work per iteration

    dst++;
    tmp++;
    src2++;
}
}
