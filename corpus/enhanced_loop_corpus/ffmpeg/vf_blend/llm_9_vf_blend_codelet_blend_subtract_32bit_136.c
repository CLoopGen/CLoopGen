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
        float diff = top[j] - bottom[j];
        dst[j] = top[j] + diff * opacity;
        if (i + 1 < height) {
            ptrdiff_t next_top_idx = j + top_linesize;
            ptrdiff_t next_bottom_idx = j + bottom_linesize;
            ptrdiff_t next_dst_idx = j + dst_linesize;
            float diff_next = ((float*)top)[next_top_idx] - ((float*)bottom)[next_bottom_idx];
            ((float*)dst)[next_dst_idx] = ((float*)top)[next_top_idx] + diff_next * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
