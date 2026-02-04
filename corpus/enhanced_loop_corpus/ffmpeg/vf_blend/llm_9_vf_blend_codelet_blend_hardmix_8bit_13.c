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
        int idx1 = j;
        int idx2 = j;
        dst[idx1] = top[idx1] + ((top[idx1] >= (255 - bottom[idx1])) * 255 - top[idx1]) * opacity;
        if (i + 1 < height) {
            uint8_t *next_top = top + top_linesize;
            uint8_t *next_bottom = bottom + bottom_linesize;
            uint8_t *next_dst = dst + dst_linesize;
            next_dst[idx2] = next_top[idx2] + ((next_top[idx2] >= (255 - next_bottom[idx2])) * 255 - next_top[idx2]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
