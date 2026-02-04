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
    ptrdiff_t dst_offset = i * dst_linesize;
    ptrdiff_t top_offset = i * top_linesize;
    ptrdiff_t bottom_offset = i * bottom_linesize;

    for (j = 0; j < width; j++) {
        dst[dst_offset + j] = top[top_offset + j] + ((1. - ((1. - top[top_offset + j] - bottom[bottom_offset + j]) >= 0 ? (1. - top[top_offset + j] - bottom[bottom_offset + j]) : 0)) - top[top_offset + j]) * opacity;

        if (i + 1 < height) {
            dst[dst_offset + dst_linesize + j] = top[top_offset + top_linesize + j] + ((1. - ((1. - top[top_offset + top_linesize + j] - bottom[bottom_offset + bottom_linesize + j]) >= 0 ? (1. - top[top_offset + top_linesize + j] - bottom[bottom_offset + bottom_linesize + j]) : 0)) - top[top_offset + top_linesize + j]) * opacity;
        }
    }
}
}
