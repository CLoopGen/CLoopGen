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
    for (j = 0; j < width; j++) {
        int32_t diff1 = top[j] - bottom[j];
        int32_t abs_diff1 = diff1 >= 0 ? diff1 : -diff1;
        dst[j] = top[j] + (abs_diff1 - top[j]) * opacity;

        if (i + 1 < height) {
            uint8_t* top_next = top + top_linesize;
            uint8_t* bottom_next = bottom + bottom_linesize;
            uint8_t* dst_next = dst + dst_linesize;
            int32_t diff2 = top_next[j] - bottom_next[j];
            int32_t abs_diff2 = diff2 >= 0 ? diff2 : -diff2;
            dst_next[j] = top_next[j] + (abs_diff2 - top_next[j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
