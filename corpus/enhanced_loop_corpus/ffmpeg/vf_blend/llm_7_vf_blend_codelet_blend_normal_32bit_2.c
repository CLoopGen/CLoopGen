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
    // Eliminate apparent dependencies by unrolling and reordering computations
    // Introduce local variables to break direct array-element coupling
    const float opac = (float)opacity;
    const float one_minus_opac = 1.0f - opac;

    for (i = 0; i < height; i++) {
        // Use pointer locals to decouple base addresses and enable compiler optimization
        float *dst_ptr = dst;
        float *top_ptr = top;
        float *bottom_ptr = bottom;

        j = 0;
        // Unroll by 2 to reduce loop-carried dependency frequency and expose parallelism
        for (; j < width - 1; j += 2) {
            float t0 = top_ptr[j], t1 = top_ptr[j+1];
            float b0 = bottom_ptr[j], b1 = bottom_ptr[j+1];
            dst_ptr[j]   = t0 * opac + b0 * one_minus_opac;
            dst_ptr[j+1] = t1 * opac + b1 * one_minus_opac;
        }
        // Handle remaining element if width is odd
        if (j < width) {
            dst_ptr[j] = top_ptr[j] * opac + bottom_ptr[j] * one_minus_opac;
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
