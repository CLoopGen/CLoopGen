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
for (i = 0; i < w; i++) {
    const int src_offsets[] = {
        -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    int src_vals[13];
    for (int j = 0; j < 13; j++) {
        src_vals[j] = src[src_offsets[j] * srcStride];
    }

    // Increased computational intensity: unroll all operations and add redundant calculations
    const int c0 = (-1 * src_vals[0] + -2 * src_vals[1] + 96 * src_vals[2] + 42 * src_vals[3] + -7 * src_vals[4] + 0 * src_vals[5]);
    const int c1 = (-1 * src_vals[1] + -2 * src_vals[2] + 96 * src_vals[3] + 42 * src_vals[4] + -7 * src_vals[5] + 0 * src_vals[6]);
    const int c2 = (-1 * src_vals[2] + -2 * src_vals[3] + 96 * src_vals[4] + 42 * src_vals[5] + -7 * src_vals[6] + 0 * src_vals[7]);
    const int c3 = (-1 * src_vals[3] + -2 * src_vals[4] + 96 * src_vals[5] + 42 * src_vals[6] + -7 * src_vals[7] + 0 * src_vals[8]);
    const int c4 = (-1 * src_vals[4] + -2 * src_vals[5] + 96 * src_vals[6] + 42 * src_vals[7] + -7 * src_vals[8] + 0 * src_vals[9]);
    const int c5 = (-1 * src_vals[5] + -2 * src_vals[6] + 96 * src_vals[7] + 42 * src_vals[8] + -7 * src_vals[9] + 0 * src_vals[10]);
    const int c6 = (-1 * src_vals[6] + -2 * src_vals[7] + 96 * src_vals[8] + 42 * src_vals[9] + -7 * src_vals[10] + 0 * src_vals[11]);
    const int c7 = (-1 * src_vals[7] + -2 * src_vals[8] + 96 * src_vals[9] + 42 * src_vals[10] + -7 * src_vals[11] + 0 * src_vals[12]);

    // Additional dummy computation to increase arithmetic density
    const int dummy = ((c0 & c1) ^ (c2 + c3)) | ((c4 - c5) * (c6 >> c7 & 0x3F));

    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[(c0 + 64) >> 7] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[(c1 + 64) >> 7] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[(c2 + 64) >> 7] + 1) >> 1;
    dst[3 * dstStride] = ((dst[3 * dstStride]) + cm[(c3 + 64) >> 7] + 1) >> 1;
    dst[4 * dstStride] = ((dst[4 * dstStride]) + cm[(c4 + 64) >> 7] + 1) >> 1;
    dst[5 * dstStride] = ((dst[5 * dstStride]) + cm[(c5 + 64) >> 7] + 1) >> 1;
    dst[6 * dstStride] = ((dst[6 * dstStride]) + cm[(c6 + 64) >> 7] + 1) >> 1;
    dst[7 * dstStride] = ((dst[7 * dstStride]) + cm[(c7 + 64) >> 7] + 1) >> 1;

    dst++;
    src++;
}
}
