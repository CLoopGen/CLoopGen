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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    // This changes the access pattern to strided by processing elements with a step of 2
    for (i = 0; i < height; i++) {
        j = 0;
        // Process pairs of elements with stride-like access
        for (; j + 1 < width; j += 2) {
            dst[j]     = top[j] * opacity + bottom[j] * (1. - opacity);
            dst[j + 1] = top[j + 1] * opacity + bottom[j + 1] * (1. - opacity);
        }
        // Handle remaining element if width is odd
        if (j < width) {
            dst[j] = top[j] * opacity + bottom[j] * (1. - opacity);
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
