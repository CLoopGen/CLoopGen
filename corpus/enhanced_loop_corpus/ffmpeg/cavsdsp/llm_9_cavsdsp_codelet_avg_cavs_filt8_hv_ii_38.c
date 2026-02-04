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
    // Reduce computational intensity: collapse multiple taps into a simpler filter
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];

    // Simplified filtering: use only three coefficients instead of five, reduce shifts and adds
    const int val0 = (tmp0 + tmp1 + 1) >> 1;  // avg(tmp0, tmp1)
    const int val1 = (tmp2 + tmp3 + 1) >> 1;  // avg(tmp2, tmp3)

    // Coarser correction using fewer operations
    dst[0 * dstStride] = (dst[0 * dstStride] + cm[(val0 + 32 * src2[0 * srcStride] + 256) >> 9] + 1) >> 1;
    dst[1 * dstStride] = (dst[1 * dstStride] + cm[(val1 + 32 * src2[1 * srcStride] + 256) >> 9] + 1) >> 1;

    // Only update first two rows per column, reduce memory traffic
    dst++;
    tmp += 2;
    src2 += 2;
}
}
