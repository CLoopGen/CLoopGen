#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            // Process current and next row simultaneously with reduced branching
            uint16_t t1 = top[j], t2 = top[j + top_linesize];
            uint16_t b1 = bottom[j], b2 = bottom[j + bottom_linesize];

            // Precompute denominator with safety
            uint16_t denom1 = (t1 == 511) ? 1 : (511 - t1);
            uint16_t denom2 = (t2 == 511) ? 1 : (511 - t2);

            uint16_t blend1 = (t1 == 511) ? 511 : ((uint32_t)b1 * b1 / denom1);
            uint16_t blend2 = (t2 == 511) ? 511 : ((uint32_t)b2 * b2 / denom2);

            blend1 = (blend1 > 511) ? 511 : blend1;
            blend2 = (blend2 > 511) ? 511 : blend2;

            dst[j] = t1 + (blend1 - t1) * opacity;
            dst[j + dst_linesize] = t2 + (blend2 - t2) * opacity;
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        // Handle last odd row
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((top[j] == 511) ? top[j] : ((511) > ((bottom[j] * bottom[j] / (511 - top[j]))) ? ((bottom[j] * bottom[j] / (511 - top[j]))) : (511))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
