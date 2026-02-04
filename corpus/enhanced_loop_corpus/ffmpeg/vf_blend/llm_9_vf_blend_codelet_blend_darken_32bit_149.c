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
    ptrdiff_t current_dst = i * dst_linesize;
    ptrdiff_t current_top = i * top_linesize;
    ptrdiff_t current_bottom = i * bottom_linesize;

    for (j = 0; j < width; j++) {
        dst[current_dst + j] = top[current_top + j] + 
            ((((top[current_top + j]) > (bottom[current_bottom + j]) ? (bottom[current_bottom + j]) : (top[current_top + j]))) - top[current_top + j]) * opacity;

        if (i + 1 < height) {
            ptrdiff_t next_dst = current_dst + dst_linesize;
            ptrdiff_t next_top = current_top + top_linesize;
            ptrdiff_t next_bottom = current_bottom + bottom_linesize;
            dst[next_dst + j] = top[next_top + j] + 
                ((((top[next_top + j]) > (bottom[next_bottom + j]) ? (bottom[next_bottom + j]) : (top[next_top + j]))) - top[next_top + j]) * opacity;
        }
    }
}
}
