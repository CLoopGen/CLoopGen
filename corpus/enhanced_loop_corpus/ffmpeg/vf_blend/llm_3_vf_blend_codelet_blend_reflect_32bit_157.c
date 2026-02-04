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
    // Use reversed memory access pattern: process elements from end to beginning
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j--) {
            ptrdiff_t idx = j; // Direct index, but traversed in reverse
            dst[idx] = top[idx] + (((bottom[idx] == 1.) ? bottom[idx] : ((1.) > ((top[idx] * top[idx] / (1. - bottom[idx]))) ? ((top[idx] * top[idx] / (1. - bottom[idx]))) : (1.))) - top[idx]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
