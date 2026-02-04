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
        int idx1 = j;
        int idx2 = j + 1;
        uint16_t t1 = top[idx1], b1 = bottom[idx1];
        uint16_t t2 = (idx2 < width) ? top[idx2] : t1;
        uint16_t b2 = (idx2 < width) ? bottom[idx2] : b1;

        dst[idx1] = t1 + ((511 - ((511 - t1 - b1) >= 0 ? (511 - t1 - b1) : (-(511 - t1 - b1)))) - t1) * opacity;
        if (idx2 < width) {
            dst[idx2] = t2 + ((511 - ((511 - t2 - b2) >= 0 ? (511 - t2 - b2) : (-(511 - t2 - b2)))) - t2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
