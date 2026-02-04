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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements, access every 4th element in a strided manner.
    // We assume width is divisible by 4 for simplicity and process elements in groups of 4 with stride 4.
    ptrdiff_t stride = 4;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += stride) {
            // Process four elements with stride of 1 within the block for better locality
            for (ptrdiff_t s = 0; s < stride && (j + s) < width; s++) {
                int idx = j + s;
                dst[idx] = top[idx] + ((top[idx] + bottom[idx] - 2 * top[idx] * bottom[idx] / 255) - top[idx]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
