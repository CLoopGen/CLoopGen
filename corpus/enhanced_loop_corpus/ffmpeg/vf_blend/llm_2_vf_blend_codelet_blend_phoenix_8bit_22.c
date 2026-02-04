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
    for (i = 0; i < height; i++) {
        // Process even indices first with stride of 2
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + ((((top[j]) > (bottom[j]) ? (bottom[j]) : (top[j])) - ((top[j]) > (bottom[j]) ? (top[j]) : (bottom[j])) + 255) - top[j]) * opacity;
        }
        // Process odd indices with stride of 2
        for (j = 1; j < width; j += 2) {
            dst[j] = top[j] + ((((top[j]) > (bottom[j]) ? (bottom[j]) : (top[j])) - ((top[j]) > (bottom[j]) ? (top[j]) : (bottom[j])) + 255) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
