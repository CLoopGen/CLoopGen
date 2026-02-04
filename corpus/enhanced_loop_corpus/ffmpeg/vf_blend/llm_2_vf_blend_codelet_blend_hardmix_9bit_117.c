#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    ptrdiff_t stride = 2;
    for (i = 0; i < height; i++) {
        // Process even indices in forward direction with stride
        for (j = 0; j < width; j += stride) {
            dst[j] = top[j] + (((top[j] < (511 - bottom[j])) ? 0 : 511) - top[j]) * opacity;
        }
        // Handle odd indices if width is not divisible by stride
        for (j = 1; j < width; j += stride) {
            dst[j] = top[j] + (((top[j] < (511 - bottom[j])) ? 0 : 511) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
