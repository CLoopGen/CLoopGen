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
    for (j = 0; j < width; j++) {
        uint16_t avg = (top[j] + bottom[j]) >> 1;
        dst[j] = top[j] + (avg - top[j]) * opacity;
        if (i + 1 < height) {
            uint16_t next_avg = (top[j + top_linesize] + bottom[j + bottom_linesize]) >> 1;
            dst[j + dst_linesize] = top[j + top_linesize] + (next_avg - top[j + top_linesize]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
