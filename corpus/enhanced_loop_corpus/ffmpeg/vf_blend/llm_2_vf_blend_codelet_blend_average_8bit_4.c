#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access with Step of 2 (Unrolled-like pattern)
    // Process elements in strides of 2 for all arrays to change access pattern
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                // Process two elements at once with strided access
                dst[j]     = top[j] + (((top[j] + bottom[j]) / 2) - top[j]) * opacity;
                dst[j + 1] = top[j + 1] + (((top[j + 1] + bottom[j + 1]) / 2) - top[j + 1]) * opacity;
            } else {
                // Handle odd width
                dst[j] = top[j] + (((top[j] + bottom[j]) / 2) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
