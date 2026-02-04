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
    // Variant 2: Strided memory access – process every 2nd element in forward pass, then fill in
    // Simulates a strided traversal pattern, potentially useful for alignment or cache tiling strategies
    for (i = 0; i < height; i++) {
        float *dst_ptr = dst;
        float *top_ptr = top;
        float *bottom_ptr = bottom;
        // Stride-2 access: first pass even indices
        for (j = 0; j < width; j += 2) {
            dst_ptr[j] = top_ptr[j] + ((top_ptr[j] - bottom_ptr[j]) - top_ptr[j]) * opacity;
        }
        // Second pass odd indices
        for (j = 1; j < width; j += 2) {
            dst_ptr[j] = top_ptr[j] + ((top_ptr[j] - bottom_ptr[j]) - top_ptr[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
