#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled and restructured indexing
    // Instead of accessing tmp with varying offsets per x, precompute base pointers for spatial locality
    uint8_t *tmp0 = tmp;
    uint8_t *tmp1 = tmp - 4;
    uint8_t *tmp2 = tmp + 4;
    uint8_t *tmp3 = tmp + 8;

    for (y = 0; y < h; y++) {
        dst[0] = cm[(filter[2] * tmp0[0] - filter[1] * tmp1[0] + filter[3] * tmp2[0] - filter[4] * tmp3[0] + 64) >> 7];
        dst[1] = cm[(filter[2] * tmp0[1] - filter[1] * tmp1[1] + filter[3] * tmp2[1] - filter[4] * tmp3[1] + 64) >> 7];
        dst[2] = cm[(filter[2] * tmp0[2] - filter[1] * tmp1[2] + filter[3] * tmp2[2] - filter[4] * tmp3[2] + 64) >> 7];
        dst[3] = cm[(filter[2] * tmp0[3] - filter[1] * tmp1[3] + filter[3] * tmp2[3] - filter[4] * tmp3[3] + 64) >> 7];

        dst += dststride;
        tmp0 += 4;
        tmp1 += 4;
        tmp2 += 4;
        tmp3 += 4;
    }
}
