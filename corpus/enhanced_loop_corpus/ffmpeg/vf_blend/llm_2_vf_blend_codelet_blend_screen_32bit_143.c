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
    ptrdiff_t total_elements = height * dst_linesize;
    float *dst_ptr = dst;
    float *top_ptr = top;
    float *bottom_ptr = bottom;

    for (i = 0; i < height; i++) {
        // Strided access: process elements with stride of 2
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                // Process two elements at once with stride pattern
                dst_ptr[j] = top_ptr[j] + (((1. - (1) * ((1. - (top_ptr[j])) * (1. - (bottom_ptr[j])) / 1.))) - top_ptr[j]) * opacity;
                dst_ptr[j+1] = top_ptr[j+1] + (((1. - (1) * ((1. - (top_ptr[j+1])) * (1. - (bottom_ptr[j+1])) / 1.))) - top_ptr[j+1]) * opacity;
            } else {
                // Handle odd-sized width
                dst_ptr[j] = top_ptr[j] + (((1. - (1) * ((1. - (top_ptr[j])) * (1. - (bottom_ptr[j])) / 1.))) - top_ptr[j]) * opacity;
            }
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
