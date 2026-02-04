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
        float top_val = top[j];
        float bottom_val = bottom[j];
        float ratio = (1.0 - top_val) > 1e-6 ? bottom_val / (1.0 - top_val) : 1.0;
        float blend = (top_val >= 1.0) ? top_val : (ratio > 1.0 ? 1.0 : ratio);
        dst[j] = top_val + (blend - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
