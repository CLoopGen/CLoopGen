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
    ptrdiff_t row_offset = i * width;
    for (j = 0; j < width; j += 2) {
        int idx1 = row_offset + j;
        int idx2 = idx1 + 1;

        uint16_t top1 = ((uint16_t*)top)[j];
        uint16_t bot1 = ((uint16_t*)bottom)[j];
        uint16_t top2 = (j + 1 < width) ? ((uint16_t*)top)[j+1] : top1;
        uint16_t bot2 = (j + 1 < width) ? ((uint16_t*)bottom)[j+1] : bot1;

        uint16_t term1 = (top1 == 0) ? 0 : 1023 - (((1023 - bot1) * (1023 - bot1)) / top1);
        uint16_t bound1 = (term1 > 1023) ? 1023 : term1;
        dst[j] = top1 + (bound1 - top1) * opacity;

        if (j + 1 < width) {
            uint16_t term2 = (top2 == 0) ? 0 : 1023 - (((1023 - bot2) * (1023 - bot2)) / top2);
            uint16_t bound2 = (term2 > 1023) ? 1023 : term2;
            dst[j+1] = top2 + (bound2 - top2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
