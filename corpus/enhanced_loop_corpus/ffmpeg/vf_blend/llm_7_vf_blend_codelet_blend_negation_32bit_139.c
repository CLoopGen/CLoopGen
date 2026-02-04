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
    float prev_dst = 0.0f;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float current_top = top[j];
            float current_bottom = bottom[j];
            float blend_factor = 1. - ((1. - current_top - current_bottom) >= 0 ? (1. - current_top - current_bottom) : (-(1. - current_top - current_bottom)));
            dst[j] = prev_dst + (current_top + (blend_factor - current_top) * opacity);
            prev_dst = dst[j]; // Introduce WAW and RAW dependency within row
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
        prev_dst = 0.0f; // Reset dependency at start of new row
    }
}
