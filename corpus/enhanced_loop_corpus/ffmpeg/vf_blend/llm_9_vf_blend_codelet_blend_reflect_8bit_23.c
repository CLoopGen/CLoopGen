#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    uint8_t *top1 = top;
    uint8_t *bottom1 = bottom;
    uint8_t *dst1 = dst;
    uint8_t *top2 = (i + 1 < height) ? top + top_linesize : top;
    uint8_t *bottom2 = (i + 1 < height) ? bottom + bottom_linesize : bottom;
    uint8_t *dst2 = (i + 1 < height) ? dst + dst_linesize : dst;

    for (j = 0; j < width; j++) {
        // First row processing
        dst1[j] = top1[j] + (((bottom1[j] == 255) ? bottom1[j] : ((255) > ((top1[j] * top1[j] / (255.0 - bottom1[j]))) ? ((top1[j] * top1[j] / (255.0 - bottom1[j]))) : (255))) - top1[j]) * opacity;

        // Second row processing (if valid)
        if (i + 1 < height) {
            dst2[j] = top2[j] + (((bottom2[j] == 255) ? bottom2[j] : ((255) > ((top2[j] * top2[j] / (255.0 - bottom2[j]))) ? ((top2[j] * top2[j] / (255.0 - bottom2[j]))) : (255))) - top2[j]) * opacity;
        }
    }

    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
