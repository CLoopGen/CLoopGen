#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  float *top;
extern  float *bottom;
extern float *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        if (i < height) {
            dst[j] = top[j] + ((bottom[j] == 0 ? 1. : 1. * top[j] / bottom[j]) - top[j]) * opacity;
        }
        if (i + 1 < height) {
            ptrdiff_t next_dst = dst_linesize;
            ptrdiff_t next_top = top_linesize;
            ptrdiff_t next_bottom = bottom_linesize;
            dst[next_dst + j] = top[next_top + j] + 
                ((bottom[next_bottom + j] == 0 ? 1. : 1. * top[next_top + j] / bottom[next_bottom + j]) - top[next_top + j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
