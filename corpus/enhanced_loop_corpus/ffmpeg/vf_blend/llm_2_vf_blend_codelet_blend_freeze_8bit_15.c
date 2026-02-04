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
        j = 0;
        // Process in chunks of stride size
        for (; j + stride <= width; j += stride) {
            // Unroll the first element in the stride
            dst[j] = top[j] + (((bottom[j] == 0) ? 0 : 255 - ((((255 - top[j]) * (255 - top[j])) / bottom[j]) > (255) ? (255) : (((255 - top[j]) * (255 - top[j])) / bottom[j]))) - top[j]) * opacity;
            // Unroll the second element in the stride
            dst[j+1] = top[j+1] + (((bottom[j+1] == 0) ? 0 : 255 - ((((255 - top[j+1]) * (255 - top[j+1])) / bottom[j+1]) > (255) ? (255) : (((255 - top[j+1]) * (255 - top[j+1])) / bottom[j+1]))) - top[j+1]) * opacity;
        }
        // Handle remaining elements
        for (; j < width; j++) {
            dst[j] = top[j] + (((bottom[j] == 0) ? 0 : 255 - ((((255 - top[j]) * (255 - top[j])) / bottom[j]) > (255) ? (255) : (((255 - top[j]) * (255 - top[j])) / bottom[j]))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
