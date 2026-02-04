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
    for (j = 0; j < width; j += 2) {
        ptrdiff_t tj0 = j, tj1 = j+1;
        if (tj1 < width) {
            dst[tj0] = top[tj0] + (((bottom[tj0] == 0) ? 0 : 1. - ((((1. - top[tj0]) * (1. - top[tj0])) / bottom[tj0]) > (1.) ? (1.) : (((1. - top[tj0]) * (1. - top[tj0])) / bottom[tj0]))) - top[tj0]) * opacity;
            dst[tj1] = top[tj1] + (((bottom[tj1] == 0) ? 0 : 1. - ((((1. - top[tj1]) * (1. - top[tj1])) / bottom[tj1]) > (1.) ? (1.) : (((1. - top[tj1]) * (1. - top[tj1])) / bottom[tj1]))) - top[tj1]) * opacity;
        } else {
            dst[tj0] = top[tj0] + (((bottom[tj0] == 0) ? 0 : 1. - ((((1. - top[tj0]) * (1. - top[tj0])) / bottom[tj0]) > (1.) ? (1.) : (((1. - top[tj0]) * (1. - top[tj0])) / bottom[tj0]))) - top[tj0]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
