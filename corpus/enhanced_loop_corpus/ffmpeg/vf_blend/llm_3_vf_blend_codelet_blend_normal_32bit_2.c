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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Linear Access with Flattened Indexing
    // Flatten the 2D row-major layout into a single loop over all relevant elements
    // and access arrays consecutively, which improves spatial locality and enables better
    // vectorization and prefetching.
    ptrdiff_t total_active_elements = height * width;
    for (ptrdiff_t idx = 0; idx < total_active_elements; idx++) {
        ptrdiff_t row = idx / width;
        ptrdiff_t col_offset = idx % width;
        float *dst_flat = dst + row * dst_linesize + col_offset;
        float *top_flat = top + row * top_linesize + col_offset;
        float *bottom_flat = bottom + row * bottom_linesize + col_offset;
        dst_flat[0] = top_flat[0] * opacity + bottom_flat[0] * (1. - opacity);
    }
}
