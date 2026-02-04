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
    // Variant 2: Consecutive (Linearized) Memory Access with Pointer Arithmetic
    // Flatten the 2D row-major traversal into a linear loop over total elements,
    // but simulate row updates using conditional pointer advancement.
    float *dst_base = dst;
    float *top_base = top;
    float *bottom_base = bottom;

    ptrdiff_t total_elements = height * width;

    // Use a single loop with manual line progression
    for (i = 0; i < height; i++) {
        float *row_dst = dst_base + i * dst_linesize;
        float *row_top = top_base + i * top_linesize;
        float *row_bottom = bottom_base + i * bottom_linesize;

        // Process entire row with consecutive access
        for (j = 0; j < width; j++) {
            // All accesses are now strictly sequential within the row
            row_dst[j] = row_top[j] + ((1. - ((1. - row_top[j] - row_bottom[j]) >= 0 ? (1. - row_top[j] - row_bottom[j]) : (-(1. - row_top[j] - row_bottom[j])))) - row_top[j]) * opacity;
        }
    }

    // Update global pointers as in original (side-effect preserved)
    dst += dst_linesize * height;
    top += top_linesize * height;
    bottom += bottom_linesize * height;
}
