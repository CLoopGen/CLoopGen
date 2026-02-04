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
    float prev_dst_val = 0.0f;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            float comp = (top[j] == 0) ? 0 : 1. - ((((1. - bottom[j]) * (1. - bottom[j])) / top[j]) > 1.0 ? 1.0 : (((1. - bottom[j]) * (1. - bottom[j])) / top[j]));
            dst[j] = prev_dst_val + (top[j] + (comp - top[j]) * opacity);
            prev_dst_val = dst[j]; 
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
        prev_dst_val = 0.0f; 
    }
}
