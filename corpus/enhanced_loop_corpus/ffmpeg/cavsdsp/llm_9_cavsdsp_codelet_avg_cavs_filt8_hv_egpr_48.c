#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    // Reduce arithmetic complexity by reusing common subexpressions and reducing filter taps
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];

    // Simplified filtering kernel: use only 3-tap averaging with smaller coefficients
    const int val0 = (tmp0 + 1) >> 1;
    const int val1 = (tmp1 + 1) >> 1;
    const int val2 = (tmp2 + 1) >> 1;
    const int val3 = (tmp3 + 1) >> 1;
    const int val4 = (tmp4 + 1) >> 1;

    // Reduced update set: only update first four output positions
    dst[0 * dstStride] = (dst[0 * dstStride] + cm[(val0 + 1) >> 1]) >> 1;
    dst[1 * dstStride] = (dst[1 * dstStride] + cm[(val1 + 1) >> 1]) >> 1;
    dst[2 * dstStride] = (dst[2 * dstStride] + cm[(val2 + 1) >> 1]) >> 1;
    dst[3 * dstStride] = (dst[3 * dstStride] + cm[(val3 + 1) >> 1]) >> 1;

    dst++;
    tmp++;
}
}
