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
    // Variant 2: Consecutive Block Access with Local Buffer Simulation (simulates cache-friendly access)
    const ptrdiff_t block_size = 8;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += block_size) {
            // Process a block of elements consecutively
            ptrdiff_t end = (j + block_size < width) ? j + block_size : width;
            for (ptrdiff_t k = j; k < end; k++) {
                dst[k] = top[k] + (((top[k] == 0) ? 0 : 511 - ((((511 - bottom[k]) * (511 - bottom[k])) / top[k]) > (511) ? (511) : (((511 - bottom[k]) * (511 - bottom[k])) / top[k]))) - top[k]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
