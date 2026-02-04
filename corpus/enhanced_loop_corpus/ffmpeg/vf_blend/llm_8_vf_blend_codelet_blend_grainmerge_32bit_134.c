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
    float opacity_f = (float)opacity;
    for (j = 0; j < width; j += 2) {
        float top_val1 = top[j];
        float bottom_val1 = bottom[j];
        dst[j] = top_val1 + (bottom_val1 - 0.5f) * opacity_f;

        if (j + 1 < width) {
            float top_val2 = top[j+1];
            float bottom_val2 = bottom[j+1];
            dst[j+1] = top_val2 + (bottom_val2 - 0.5f) * opacity_f;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
