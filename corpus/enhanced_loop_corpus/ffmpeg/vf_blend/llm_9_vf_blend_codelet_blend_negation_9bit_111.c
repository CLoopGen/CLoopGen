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
    uint16_t *top1 = top;
    uint16_t *bottom1 = bottom;
    uint16_t *dst1 = dst;
    uint16_t *top2 = (i + 1 < height) ? top + top_linesize : top;
    uint16_t *bottom2 = (i + 1 < height) ? bottom + bottom_linesize : bottom;
    uint16_t *dst2 = (i + 1 < height) ? dst + dst_linesize : dst;

    for (j = 0; j < width; j++) {
        dst1[j] = top1[j] + ((511 - ((511 - top1[j] - bottom1[j]) >= 0 ? (511 - top1[j] - bottom1[j]) : (-(511 - top1[j] - bottom1[j])))) - top1[j]) * opacity;
        if (i + 1 < height) {
            dst2[j] = top2[j] + ((511 - ((511 - top2[j] - bottom2[j]) >= 0 ? (511 - top2[j] - bottom2[j]) : (-(511 - top2[j] - bottom2[j])))) - top2[j]) * opacity;
        }
    }

    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
