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
        if (t <= 0.0) {
            dst[j] = t + (0.0 - t) * opacity;
        } else {
            double inv_ratio = (1.0 - b) / t;
            double adjusted = 1.0 - inv_ratio;
            double clamped_factor = adjusted < 0.0 ? 0.0 : adjusted;
            dst[j] = t + (clamped_factor - t) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
