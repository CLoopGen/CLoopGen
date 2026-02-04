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
    for (j = 0; j < width; j += 2) {
        float t = top[j];
        float b = bottom[j];
        float ratio = (b == 0) ? 0.0f : ((1.0f - t) * (1.0f - t)) / b;
        float blend = (ratio > 1.0f) ? 1.0f : ratio;
        float result = t + ((blend - t) * opacity);
        dst[j] = result;
        if (j + 1 < width) {
            dst[j + 1] = top[j + 1] + (((bottom[j + 1] == 0) ? 0 : 1. - ((((1. - top[j + 1]) * (1. - top[j + 1])) / bottom[j + 1]) > (1.) ? (1.) : (((1. - top[j + 1]) * (1. - top[j + 1])) / bottom[j + 1]))) - top[j + 1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((bottom[j] == 0) ? 0 : 1. - ((((1. - top[j]) * (1. - top[j])) / bottom[j]) > (1.) ? (1.) : (((1. - top[j]) * (1. - top[j])) / bottom[j]))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
