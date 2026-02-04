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
const int unroll_factor = 4;
ptrdiff_t aligned_width = (width / unroll_factor) * unroll_factor;
for (i = 0; i < height; i++) {
    j = 0;
    for (; j < aligned_width; j += unroll_factor) {
        float t0 = top[j], t1 = top[j+1], t2 = top[j+2], t3 = top[j+3];
        float b0 = bottom[j], b1 = bottom[j+1], b2 = bottom[j+2], b3 = bottom[j+3];

        dst[j]   = t0 + (((t0 == 0) ? 0 : 1. - (((1. - b0)*(1. - b0))/t0 > 1. ? 1. : ((1. - b0)*(1. - b0))/t0)) - t0) * opacity;
        dst[j+1] = t1 + (((t1 == 0) ? 0 : 1. - (((1. - b1)*(1. - b1))/t1 > 1. ? 1. : ((1. - b1)*(1. - b1))/t1)) - t1) * opacity;
        dst[j+2] = t2 + (((t2 == 0) ? 0 : 1. - (((1. - b2)*(1. - b2))/t2 > 1. ? 1. : ((1. - b2)*(1. - b2))/t2)) - t2) * opacity;
        dst[j+3] = t3 + (((t3 == 0) ? 0 : 1. - (((1. - b3)*(1. - b3))/t3 > 1. ? 1. : ((1. - b3)*(1. - b3))/t3)) - t3) * opacity;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((top[j] == 0) ? 0 : 1. - ((((1. - bottom[j]) * (1. - bottom[j])) / top[j]) > (1.) ? (1.) : (((1. - bottom[j]) * (1. - bottom[j])) / top[j]))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
