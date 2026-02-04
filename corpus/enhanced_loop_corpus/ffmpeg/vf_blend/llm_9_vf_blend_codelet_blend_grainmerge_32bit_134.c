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
            dst[j] = top[j] * (1.0f - opacity) + bottom[j] * opacity;
        }
        if (i + 1 < height) {
            float *dst_next = (float*)((char*)dst + dst_linesize);
            float *top_next = (float*)((char*)top + top_linesize);
            float *bottom_next = (float*)((char*)bottom + bottom_linesize);
            dst_next[j] = top_next[j] * (1.0f - opacity) + bottom_next[j] * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
