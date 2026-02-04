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
    // Variant 2: Consecutive Block Memory Access with Local Caching (tiling/blocking effect)
    const ptrdiff_t block_width = 16;
    for (i = 0; i < height; i++) {
        for (ptrdiff_t bj = 0; bj < width; bj += block_width) {
            // Process a block of data consecutively
            ptrdiff_t end_j = (bj + block_width < width) ? bj + block_width : width;
            for (j = bj; j < end_j; j++) {
                dst[j] = top[j] + (((top[j] < (511 - bottom[j])) ? 0 : 511) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
