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
    // Variant 2: Consecutive Block Access using pointer arithmetic with local pointers
    for (i = 0; i < height; i++) {
        float *dst_ptr = dst;
        float *top_ptr = top;
        float *bottom_ptr = bottom;
        for (j = 0; j < width; j++) {
            // Use locally incremented pointers to ensure consecutive access pattern
            *dst_ptr = *top_ptr + ((*bottom_ptr == 0 ? 1. : 1. * *top_ptr / *bottom_ptr) - *top_ptr) * opacity;
            dst_ptr++;
            top_ptr++;
            bottom_ptr++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
