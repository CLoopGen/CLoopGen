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
    // Instead of processing elements sequentially (j++), access every 2nd element in two passes.
    // This changes spatial locality and may improve cache behavior for certain architectures.
    ptrdiff_t offset;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            // First pass: even indices
            dst[j] = top[j] + ((((top[j]) > (bottom[j]) ? (bottom[j]) : (top[j]))) - top[j]) * opacity;
            // Second: odd indices, if within bounds
            offset = j + 1;
            if (offset < width) {
                dst[offset] = top[offset] + ((((top[offset]) > (bottom[offset]) ? (bottom[offset]) : (top[offset]))) - top[offset]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
