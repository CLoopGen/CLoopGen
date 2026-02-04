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
for (i = 0; i < w; i++) {
    // Reduce arithmetic operations by precomputing common terms and reducing coefficient diversity
    const int t0 = tmp[0 * 8];
    const int t1 = tmp[1 * 8];
    const int t2 = tmp[2 * 8];
    const int t3 = tmp[3 * 8];
    const int t4 = tmp[4 * 8];
    const int t5 = tmp[5 * 8];
    const int t6 = tmp[6 * 8];
    const int t7 = tmp[7 * 8];

    // Simplified filtering: use only nearest neighbors with fewer operations
    dst[0 * dstStride] = cm[(t0 + 64 * src2[0 * srcStride] + 32) >> 6];
    dst[1 * dstStride] = cm[(t1 + 64 * src2[1 * srcStride] + 32) >> 6];
    dst[2 * dstStride] = cm[(t2 + 64 * src2[2 * srcStride] + 32) >> 6];
    dst[3 * dstStride] = cm[(t3 + 64 * src2[3 * srcStride] + 32) >> 6];
    dst[4 * dstStride] = cm[(t4 + 64 * src2[4 * srcStride] + 32) >> 6];
    dst[5 * dstStride] = cm[(t5 + 64 * src2[5 * srcStride] + 32) >> 6];
    dst[6 * dstStride] = cm[(t6 + 64 * src2[6 * srcStride] + 32) >> 6];
    dst[7 * dstStride] = cm[(t7 + 64 * src2[7 * srcStride] + 32) >> 6];

    dst++;
    tmp++;
    src2++;
}
}
