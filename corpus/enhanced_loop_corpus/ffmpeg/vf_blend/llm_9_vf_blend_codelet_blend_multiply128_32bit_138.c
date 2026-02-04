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
            float t = top[j];
            float b = bottom[j];
            float result = t + (((t - 0.5f) * b / 0.125f + 0.5f) - t) * opacity;
            dst[j] = result;
        }
        if (i + 1 < height) {
            float t_next = top[top_linesize + j];
            float b_next = bottom[bottom_linesize + j];
            float result_next = t_next + (((t_next - 0.5f) * b_next / 0.125f + 0.5f) - t_next) * opacity;
            ((float*)((char*)dst + dst_linesize))[j] = result_next;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
