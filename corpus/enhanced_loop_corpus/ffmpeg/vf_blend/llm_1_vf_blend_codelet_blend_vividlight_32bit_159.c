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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        dst[j] = top[j] + (((top[j] < 0.5) ? (((2 * top[j]) <= 0.) ? (2 * top[j]) : ((0.) > (1. - (1. - (bottom[j])) / (2 * top[j])) ? (0.) : (1. - (1. - (bottom[j])) / (2 * top[j])))) : (((2 * (top[j] - 0.5)) >= 1.) ? (2 * (top[j] - 0.5)) : ((1.) > (((bottom[j]) / (1. - (2 * (top[j] - 0.5))))) ? (((bottom[j]) / (1. - (2 * (top[j] - 0.5))))) : (1.)))) - top[j]) * opacity;
        if (i + 1 < height) {
            dst[dst_linesize + j] = top[top_linesize + j] + (((top[top_linesize + j] < 0.5) ? (((2 * top[top_linesize + j]) <= 0.) ? (2 * top[top_linesize + j]) : ((0.) > (1. - (1. - (bottom[bottom_linesize + j])) / (2 * top[top_linesize + j])) ? (0.) : (1. - (1. - (bottom[bottom_linesize + j])) / (2 * top[top_linesize + j])))) : (((2 * (top[top_linesize + j] - 0.5)) >= 1.) ? (2 * (top[top_linesize + j] - 0.5)) : ((1.) > (((bottom[bottom_linesize + j]) / (1. - (2 * (top[top_linesize + j] - 0.5))))) ? (((bottom[bottom_linesize + j]) / (1. - (2 * (top[top_linesize + j] - 0.5))))) : (1.)))) - top[top_linesize + j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
