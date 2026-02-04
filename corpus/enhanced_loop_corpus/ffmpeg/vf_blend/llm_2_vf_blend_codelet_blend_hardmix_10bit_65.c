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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing elements sequentially (j = 0 to width-1),
    // access every second element in two passes: first even indices, then odd.
    for (i = 0; i < height; i++) {
        // First pass: even indices
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] < (1023 - bottom[j])) ? 0 : 1023) - top[j]) * opacity;
        }
        // Second pass: odd indices
        for (j = 1; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] < (1023 - bottom[j])) ? 0 : 1023) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
