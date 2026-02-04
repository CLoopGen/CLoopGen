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
    float *dst_row = dst;
    float *top_row = top;
    float *bottom_row = bottom;
    for (j = 0; j < width; j += 2) {
        float inv_opacity = 1.0f - opacity;
        float t0 = top_row[j], b0 = bottom_row[j];
        float t1 = top_row[j+1], b1 = bottom_row[j+1];

        float result0 = (b0 == 1.0f) ? b0 : (t0 * t0 / (1.0f - b0));
        float clamped0 = (result0 > 1.0f) ? 1.0f : result0;
        dst_row[j] = t0 + (clamped0 - t0) * opacity;

        float result1 = (b1 == 1.0f) ? b1 : (t1 * t1 / (1.0f - b1));
        float clamped1 = (result1 > 1.0f) ? 1.0f : result1;
        dst_row[j+1] = t1 + (clamped1 - t1) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
