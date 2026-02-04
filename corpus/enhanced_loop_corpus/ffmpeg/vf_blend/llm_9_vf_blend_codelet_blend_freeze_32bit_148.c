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
    float* local_dst = dst;
    float* local_top = top;
    float* local_bottom = bottom;
    for (j = 0; j < width; j++) {
        float t = local_top[j];
        float b = local_bottom[j];
        float term1 = 1.0f - t;
        float sqr_term = term1 * term1;
        float inv_b = (b == 0.0f) ? 0.0f : (sqr_term / b);
        float blend_factor = (inv_b > 1.0f) ? 1.0f : inv_b;
        float diff = blend_factor - t;
        local_dst[j] = t + (diff * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
