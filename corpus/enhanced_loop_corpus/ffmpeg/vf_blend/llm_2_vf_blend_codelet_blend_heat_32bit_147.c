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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    // This changes the access pattern to process elements with a stride of 2 for potential cache optimization or vectorization
    ptrdiff_t stride = 2;
    for (i = 0; i < height; i++) {
        // Process main strided loop
        for (j = 0; j < width - 1; j += stride) {
            dst[j] = top[j] + (((top[j] == 0) ? 0 : 1. - ((((1. - bottom[j]) * (1. - bottom[j])) / top[j]) > (1.) ? (1.) : (((1. - bottom[j]) * (1. - bottom[j])) / top[j]))) - top[j]) * opacity;
            dst[j + 1] = top[j + 1] + (((top[j + 1] == 0) ? 0 : 1. - ((((1. - bottom[j + 1]) * (1. - bottom[j + 1])) / top[j + 1]) > (1.) ? (1.) : (((1. - bottom[j + 1]) * (1. - bottom[j + 1])) / top[j + 1]))) - top[j + 1]) * opacity;
        }
        // Handle last element if width is odd
        if (j < width) {
            dst[j] = top[j] + (((top[j] == 0) ? 0 : 1. - ((((1. - bottom[j]) * (1. - bottom[j])) / top[j]) > (1.) ? (1.) : (((1. - bottom[j]) * (1. - bottom[j])) / top[j]))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
