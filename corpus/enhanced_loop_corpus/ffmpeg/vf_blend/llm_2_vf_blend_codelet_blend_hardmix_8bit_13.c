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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    ptrdiff_t stride = 2;
    for (i = 0; i < height; i++) {
        // Process even indices in forward direction with stride
        for (j = 0; j < width - 1; j += stride) {
            dst[j] = top[j] + (((top[j] < (255 - bottom[j])) ? 0 : 255) - top[j]) * opacity;
            // Handle next element in stride if within bounds
            if (j + 1 < width) {
                dst[j + 1] = top[j + 1] + (((top[j + 1] < (255 - bottom[j + 1])) ? 0 : 255) - top[j + 1]) * opacity;
            }
        }
        // Handle case when width is odd and last element was skipped
        if (width % 2 == 1 && j == width - 1) {
            dst[j] = top[j] + (((top[j] < (255 - bottom[j])) ? 0 : 255) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
