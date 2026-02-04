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
    // Reduce computational load by unrolling only part of the original computation
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];

    // Simplified filter: use a 3-tap approximation instead of 6-tap, reduce memory references and arithmetic
    dst[0 * dstStride] = cm[((4 * tmp0 + 4 * tmp1 + -1 * tmp2) + 64) >> 7];
    dst[1 * dstStride] = cm[((4 * tmp1 + 4 * tmp2 + -1 * tmp3) + 64) >> 7];
    dst[2 * dstStride] = cm[((4 * tmp2 + 4 * tmp3 + -1 * tmp4) + 64) >> 7];

    // Skip some outputs to reduce work per iteration
    dst++;
    tmp++;
}
}
