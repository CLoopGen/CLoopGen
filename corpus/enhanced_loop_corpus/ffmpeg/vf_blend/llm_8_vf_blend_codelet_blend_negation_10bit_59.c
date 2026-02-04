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

        int diff1 = 1023 - t1 - b1;
        int abs_diff1 = (diff1 >= 0) ? diff1 : -diff1;
        int result1 = 1023 - abs_diff1;

        int diff2 = 1023 - t2 - b2;
        int abs_diff2 = (diff2 >= 0) ? diff2 : -diff2;
        int result2 = 1023 - abs_diff2;

        dst[idx1] = t1 + (result1 - t1) * opacity;
        if (idx2 < width) {
            dst[idx2] = t2 + (result2 - t2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
