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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        float t = top[j];
        float b = bottom[j];
        float diff = 1.0f - t - b;
        float clamped_diff = diff >= 0.0f ? diff : -diff;
        float value = t + ((1.0f - clamped_diff) - t) * opacity;
        dst[j] = value;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
