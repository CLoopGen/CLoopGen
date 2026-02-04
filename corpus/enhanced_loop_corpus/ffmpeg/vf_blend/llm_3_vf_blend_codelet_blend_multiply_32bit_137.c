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
    // Variant 2: Consecutive Linear Access with Flattened Indexing
    // Flatten the 2D iteration into a single loop over all pixels consecutively.
    // This improves cache locality by ensuring linear traversal of memory,
    // assuming that linesizes match natural row strides (or are at least positive).

    ptrdiff_t total_elements = width * height;
    float *top_ptr = top;
    float *bottom_ptr = bottom;
    float *dst_ptr = dst;

    for (ptrdiff_t idx = 0; idx < total_elements; idx++) {
        // Perform computation on flattened index
        dst_ptr[idx] = top_ptr[idx] + ((top_ptr[idx] * bottom_ptr[idx]) - top_ptr[idx]) * opacity;

        // Check if we need to skip to next row due to linesize padding
        if ((idx + 1) % width == 0) {
            // After finishing a row, account for padding in linesize
            ptrdiff_t actual_step = dst_linesize - width;
            if (actual_step > 0 && idx + 1 < total_elements) {
                dst_ptr += actual_step;
                top_ptr += (top_linesize - width);
                bottom_ptr += (bottom_linesize - width);
            }
        }
    }
}
