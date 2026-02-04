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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 2) {
        ptrdiff_t tj0 = j;
        ptrdiff_t tj1 = j + 1;
        if (tj1 >= width) break;

        // Strided access: process two elements per iteration
        uint16_t top0 = top[tj0];
        uint16_t top1 = top[tj1];
        uint16_t bot0 = bottom[tj0];
        uint16_t bot1 = bottom[tj1];

        dst[tj0] = top0 + (((bot0 == 0) ? 0 : 1023 - ((((1023 - top0) * (1023 - top0)) / bot0) > 1023 ? 1023 : (((1023 - top0) * (1023 - top0)) / bot0))) - top0) * opacity;
        dst[tj1] = top1 + (((bot1 == 0) ? 0 : 1023 - ((((1023 - top1) * (1023 - top1)) / bot1) > 1023 ? 1023 : (((1023 - top1) * (1023 - top1)) / bot1))) - top1) * opacity;
    }
    // Handle odd width if needed with scalar fallback (not unrolled)
    if (j < width) {
        dst[j] = top[j] + (((bottom[j] == 0) ? 0 : 1023 - ((((1023 - top[j]) * (1023 - top[j])) / bottom[j]) > (1023) ? (1023) : (((1023 - top[j]) * (1023 - top[j])) / bottom[j]))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
