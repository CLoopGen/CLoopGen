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
    ptrdiff_t local_top_offset = 0;
    ptrdiff_t local_bottom_offset = 0;
    ptrdiff_t local_dst_offset = 0;

    for (j = 0; j < width; j++) {
        dst[local_dst_offset + j] = top[local_top_offset + j] + 
            (((1.0 - (1.0 * ((1.0 - top[local_top_offset + j]) * (1.0 - bottom[local_bottom_offset + j]) / 1.0))) - top[local_top_offset + j]) * opacity);

        if (i + 1 < height) {
            float* next_dst = (float*)((char*)dst + dst_linesize);
            float* next_top = (float*)((char*)top + top_linesize);
            float* next_bottom = (float*)((char*)bottom + bottom_linesize);
            next_dst[local_dst_offset + j] = next_top[local_top_offset + j] + 
                (((1.0 - (1.0 * ((1.0 - next_top[local_top_offset + j]) * (1.0 - next_bottom[local_bottom_offset + j]) / 1.0))) - next_top[local_top_offset + j]) * opacity);
        }
    }

    if (i + 1 < height) {
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    } else {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
