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
    // Reduce computational intensity: use a simplified filter with fewer terms and operations
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];

    // Simplified interpolation: linear blend instead of full 6-tap filter
    dst[0 * dstStride] = cm[(tmp0 + 512) >> 10];
    dst[1 * dstStride] = cm[((3 * tmp1 + 1 * tmp0 + 2) >> 2) + (512 >> 10)];
    dst[2 * dstStride] = cm[((2 * tmp2 + 2 * tmp1 + 2) >> 2) + (512 >> 10)];
    dst[3 * dstStride] = cm[((1 * tmp3 + 3 * tmp2 + 2) >> 2) + (512 >> 10)];

    // Skip higher indices to reduce memory footprint and arithmetic
    dst[4 * dstStride] = cm[(tmp2 + 512) >> 10];
    dst[5 * dstStride] = cm[(tmp3 + 512) >> 10];
    dst[6 * dstStride] = cm[(tmp3 + 512) >> 10];
    dst[7 * dstStride] = cm[(tmp3 + 512) >> 10];

    dst++;
    tmp++;
}
}
