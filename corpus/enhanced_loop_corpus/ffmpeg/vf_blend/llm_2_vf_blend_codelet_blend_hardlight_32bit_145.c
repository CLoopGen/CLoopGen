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
    // This modifies the access pattern to process elements with a stride of 2 for potential cache utilization improvement
    ptrdiff_t total_elements = height * dst_linesize;
    float *dst_ptr = dst;
    float *top_ptr = top;
    float *bottom_ptr = bottom;

    // Process main loop with stride-2 access
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j += 2) {
            // Process two elements at once with strided access
            dst_ptr[j] = top_ptr[j] + (((bottom_ptr[j] < 0.5) ? 
                (2.0f * (bottom_ptr[j] * top_ptr[j])) : 
                (1.0f - 2.0f * ((1.0f - bottom_ptr[j]) * (1.0f - top_ptr[j])))) - top_ptr[j]) * opacity;
            dst_ptr[j+1] = top_ptr[j+1] + (((bottom_ptr[j+1] < 0.5) ? 
                (2.0f * (bottom_ptr[j+1] * top_ptr[j+1])) : 
                (1.0f - 2.0f * ((1.0f - bottom_ptr[j+1]) * (1.0f - top_ptr[j+1])))) - top_ptr[j+1]) * opacity;
        }
        // Handle last element if width is odd
        if (j == width - 1) {
            dst_ptr[j] = top_ptr[j] + (((bottom_ptr[j] < 0.5) ? 
                (2.0f * (bottom_ptr[j] * top_ptr[j])) : 
                (1.0f - 2.0f * ((1.0f - bottom_ptr[j]) * (1.0f - top_ptr[j])))) - top_ptr[j]) * opacity;
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
