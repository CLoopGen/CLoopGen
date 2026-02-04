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
    // Instead of accessing j-th element directly, use a stride of 2 (process every other pixel),
    // then handle remainder if width is odd. This changes spatial locality and access pattern.
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            // Process two elements with stride: current and next (if within bounds)
            int j1 = j;
            int j2 = j + 1;

            // First element
            dst[j1] = top[j1] + (((((top[j1]) == 255) ? (top[j1]) : ((255) > ((((bottom[j1]) << 8) / (255 - (top[j1])))) ? ((((bottom[j1]) << 8) / (255 - (top[j1])))) : (255)))) - top[j1]) * opacity;

            // Second element, if within bounds
            if (j2 < width) {
                dst[j2] = top[j2] + (((((top[j2]) == 255) ? (top[j2]) : ((255) > ((((bottom[j2]) << 8) / (255 - (top[j2])))) ? ((((bottom[j2]) << 8) / (255 - (top[j2])))) : (255)))) - top[j2]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
