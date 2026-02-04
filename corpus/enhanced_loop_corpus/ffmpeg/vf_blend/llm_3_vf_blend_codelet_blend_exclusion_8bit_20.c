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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    // Traverse the arrays in reverse order (from end to beginning) for both dimensions.
    // This changes spatial locality and may affect cache behavior.
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j--) {
            dst[j] = top[j] + ((top[j] + bottom[j] - 2 * top[j] * bottom[j] / 255) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
