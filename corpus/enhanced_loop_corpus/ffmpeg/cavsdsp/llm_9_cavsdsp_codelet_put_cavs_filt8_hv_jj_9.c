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
    // Reduce computational load: use fewer taps in filter
    const int tmp0 = tmp[0 * 8];
    const int tmp1 = tmp[1 * 8];
    const int tmp2 = tmp[2 * 8];
    const int tmp3 = tmp[3 * 8];
    const int tmp4 = tmp[4 * 8];
    const int tmp5 = tmp[5 * 8];

    // Simplified filtering with reduced kernel size (3-tap instead of 6-tap)
    dst[0 * dstStride] = cm[((4 * tmp0 + 4 * tmp1 + 0 * tmp2) + 4) >> 3];
    dst[1 * dstStride] = cm[((3 * tmp1 + 5 * tmp2 + 0 * tmp3) + 4) >> 3];
    dst[2 * dstStride] = cm[((2 * tmp2 + 6 * tmp3 + 0 * tmp4) + 4) >> 3];
    dst[3 * dstStride] = cm[((1 * tmp3 + 7 * tmp4 + 0 * tmp5) + 4) >> 3];

    // Skip bottom half of original computation to reduce intensity
    // Only compute first 4 rows per iteration

    dst++;
    tmp++;
}
}
