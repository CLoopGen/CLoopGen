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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes width is even and accesses two elements per iteration to promote spatial locality
    for (i = 0; i < height; i++) {
        float *dst_ptr = dst;
        float *top_ptr = top;
        float *bottom_ptr = bottom;
        for (j = 0; j < width - 1; j += 2) {
            dst_ptr[j]   = top_ptr[j]   + ((top_ptr[j]   - bottom_ptr[j])   - top_ptr[j])   * opacity;
            dst_ptr[j+1] = top_ptr[j+1] + ((top_ptr[j+1] - bottom_ptr[j+1]) - top_ptr[j+1]) * opacity;
        }
        // Handle last element if width is odd
        if (j < width) {
            dst_ptr[j] = top_ptr[j] + ((top_ptr[j] - bottom_ptr[j]) - top_ptr[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
