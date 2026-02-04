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
    float *dst_base = dst;
    float *top_base = top;
    float *bottom_base = bottom;

    for (i = 0; i < height; i++) {
        ptrdiff_t offset = i * dst_linesize;
        for (j = 0; j < width; j++) {
            // Use base pointer with linear offset to promote consecutive access
            ptrdiff_t idx = offset + j;
            dst_base[idx] = top_base[i * top_linesize + j] + 
                           (((1. - (1) * ((1. - (top_base[i * top_linesize + j])) * 
                                          (1. - (bottom_base[i * bottom_linesize + j])) / 1.))) - 
                            top_base[i * top_linesize + j]) * opacity;
        }
    }
}
