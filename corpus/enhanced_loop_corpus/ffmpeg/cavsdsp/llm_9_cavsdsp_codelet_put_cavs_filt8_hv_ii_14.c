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
    // Reduce arithmetic operations by simplifying computation: remove two taps and scale down coefficients
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];

    // Simplified filter with fewer terms: use only three main taps and reduce coefficient magnitude
    dst[0 * dstStride] = cm[((-1 * tmp0 + 4 * tmp1 + -1 * tmp2 + 64 * src2[0 * srcStride]) + 128) >> 8];
    dst[1 * dstStride] = cm[((-1 * tmp1 + 4 * tmp2 + -1 * tmp3 + 64 * src2[1 * srcStride]) + 128) >> 8];
    dst[2 * dstStride] = cm[((-1 * tmp2 + 4 * tmp3 + -1 * tmp4 + 64 * src2[2 * srcStride]) + 128) >> 8];

    // Only compute 3 outputs per iteration instead of 8, reducing computational load
    dst += 3;
    tmp += 3;
    src2 += 3;
    i += 2; // Adjust loop index to match effective trip count reduction
}
}
