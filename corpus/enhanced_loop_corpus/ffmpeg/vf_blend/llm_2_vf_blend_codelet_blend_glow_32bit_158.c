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
    // Variant 1: Strided Memory Access (access every 2nd element in a strided pattern, then handle remainder)
    ptrdiff_t stride = 2;
    for (i = 0; i < height; i++) {
        // Process elements with stride
        for (j = 0; j < width - (width % stride); j += stride) {
            dst[j] = top[j] + (((top[j] == 1.) ? top[j] : ((1.) > ((bottom[j] * bottom[j] / (1. - top[j]))) ? ((bottom[j] * bottom[j] / (1. - top[j]))) : (1.))) - top[j]) * opacity;
            // Also process next element in stride if within bounds
            if (j + 1 < width) {
                dst[j + 1] = top[j + 1] + (((top[j + 1] == 1.) ? top[j + 1] : ((1.) > ((bottom[j + 1] * bottom[j + 1] / (1. - top[j + 1]))) ? ((bottom[j + 1] * bottom[j + 1] / (1. - top[j + 1]))) : (1.))) - top[j + 1]) * opacity;
            }
        }
        // Handle any remaining element if width is odd
        if (width % stride && j < width) {
            dst[j] = top[j] + (((top[j] == 1.) ? top[j] : ((1.) > ((bottom[j] * bottom[j] / (1. - top[j]))) ? ((bottom[j] * bottom[j] / (1. - top[j]))) : (1.))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
