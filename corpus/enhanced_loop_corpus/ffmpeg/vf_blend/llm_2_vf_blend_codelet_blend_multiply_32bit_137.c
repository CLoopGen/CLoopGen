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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing j from 0 to width sequentially with unit stride,
    // access elements with a fixed stride (e.g., 2), handling even and odd separately.
    // Here we use stride of 2 for demonstration, processing two interleaved sequences.

    ptrdiff_t total_elements = width * height;
    ptrdiff_t stride = 2;

    for (i = 0; i < stride; i++) {
        float *top_ptr = top + i;
        float *bottom_ptr = bottom + i;
        float *dst_ptr = dst + i;

        for (j = i; j < total_elements; j += stride) {
            ptrdiff_t row = j / width;
            ptrdiff_t col_offset = j % width;

            // Adjust pointers at row boundaries using linesizes
            if (col_offset == 0 && j > i) {
                top_ptr += top_linesize;
                bottom_ptr += bottom_linesize;
                dst_ptr += dst_linesize;
            }

            dst_ptr[col_offset] = top_ptr[col_offset] + 
                ((top_ptr[col_offset] * bottom_ptr[col_offset]) - top_ptr[col_offset]) * opacity;
        }
    }
}
