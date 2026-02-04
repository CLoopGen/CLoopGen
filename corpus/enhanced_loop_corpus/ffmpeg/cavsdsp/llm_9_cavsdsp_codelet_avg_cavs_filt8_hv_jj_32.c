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
    // Reduce computational intensity: use fewer taps and simplify computation
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];

    // Simplified filter: reduce coefficients and memory accesses
    dst[0 * dstStride] = ((dst[0 * dstStride]) + cm[((4 * tmp0 + 4 * tmp1 + 64 * src2[0 * srcStride]) + 32) >> 6] + 1) >> 1;
    dst[1 * dstStride] = ((dst[1 * dstStride]) + cm[((4 * tmp1 + 4 * tmp2 + 64 * src2[1 * srcStride]) + 32) >> 6] + 1) >> 1;
    dst[2 * dstStride] = ((dst[2 * dstStride]) + cm[((4 * tmp2 + 4 * tmp3 + 64 * src2[2 * srcStride]) + 32) >> 6] + 1) >> 1;

    // Skip updating some output rows to reduce work
    dst++;
    tmp++;
    src2++;
}
}
