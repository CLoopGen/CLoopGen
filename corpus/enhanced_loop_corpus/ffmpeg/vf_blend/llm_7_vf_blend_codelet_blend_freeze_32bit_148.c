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
    float prev_top_j = 0.0f;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float current_top = top[j];
            float adjusted_opacity = (j == 0) ? opacity : opacity * (prev_top_j / (current_top + 1e-6f));
            dst[j] = current_top + (((bottom[j] == 0) ? 0 : 1. - ((((1. - current_top) * (1. - current_top)) / bottom[j]) > (1.) ? (1.) : (((1. - current_top) * (1. - current_top)) / bottom[j]))) - current_top) * adjusted_opacity;
            prev_top_j = current_top;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
