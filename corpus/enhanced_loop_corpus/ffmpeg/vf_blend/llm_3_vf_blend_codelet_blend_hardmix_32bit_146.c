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
    // Variant 2: Consecutive Block Access with Pointer Offsets
    // Unroll the inner loop slightly to access memory in consecutive blocks (e.g., pairs of elements),
    // improving potential for vectorization and cache utilization due to better locality.
    for (i = 0; i < height; i++) {
        for (j = 0; j + 1 < width; j += 2) {
            // Process two elements consecutively
            dst[j]     = top[j]     + (((top[j]     < (1. - bottom[j]))     ? 0 : 1.) - top[j])     * opacity;
            dst[j + 1] = top[j + 1] + (((top[j + 1] < (1. - bottom[j + 1])) ? 0 : 1.) - top[j + 1]) * opacity;
        }
        // Handle remaining element if width is odd
        if (j < width) {
            dst[j] = top[j] + (((top[j] < (1. - bottom[j])) ? 0 : 1.) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
