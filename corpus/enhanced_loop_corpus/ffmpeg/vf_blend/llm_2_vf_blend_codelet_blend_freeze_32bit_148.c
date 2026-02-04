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
    ptrdiff_t idx = i * dst_linesize;
    for (j = 0; j < width; j++) {
        ptrdiff_t offset = idx + j;
        dst[offset] = top[offset] + (((bottom[offset] == 0) ? 0 : 1. - ((((1. - top[offset]) * (1. - top[offset])) / bottom[offset]) > (1.) ? (1.) : (((1. - top[offset]) * (1. - top[offset])) / bottom[offset]))) - top[offset]) * opacity;
    }
}
}
