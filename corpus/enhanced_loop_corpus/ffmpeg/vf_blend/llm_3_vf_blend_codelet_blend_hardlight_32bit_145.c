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
    // Instead of 2D row-major nested loops, traverse memory sequentially using a single loop
    // assuming that dst_linesize, top_linesize, and bottom_linesize are >= width (row padding possible)
    float *dst_ptr = dst;
    float *top_ptr = top;
    float *bottom_ptr = bottom;

    for (i = 0; i < height; i++) {
        // Compute base pointers for current row
        float *row_dst = dst_ptr + i * dst_linesize;
        float *row_top = top_ptr + i * top_linesize;
        float *row_bottom = bottom_ptr + i * bottom_linesize;

        // Sequentially access all elements in the current row without index recalculation
        for (j = 0; j < width; j++) {
            float t = row_top[j];
            float b = row_bottom[j];
            float result = (b < 0.5) ? 
                (2.0f * b * t) : 
                (1.0f - 2.0f * (1.0f - b) * (1.0f - t));
            row_dst[j] = t + (result - t) * opacity;
        }
    }
}
