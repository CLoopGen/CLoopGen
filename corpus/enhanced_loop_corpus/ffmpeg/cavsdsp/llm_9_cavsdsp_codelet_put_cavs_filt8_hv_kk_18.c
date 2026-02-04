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
    // Reduce arithmetic complexity: use a simplified filter with fewer taps
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];

    // Simplified computation: 4-tap instead of 6-tap, lower intensity
    dst[0 * dstStride] = cm[((3 * tmp0 + 3 * tmp1 + 512) >> 10)];
    dst[1 * dstStride] = cm[((3 * tmp1 + 3 * tmp2 + 512) >> 10)];
    dst[2 * dstStride] = cm[((3 * tmp2 + 3 * tmp3 + 512) >> 10)];

    // Skip some computations and stride over more data
    dst += 3;
    tmp += 4; // Increase pointer advance to reduce effective trip count impact
}
}
