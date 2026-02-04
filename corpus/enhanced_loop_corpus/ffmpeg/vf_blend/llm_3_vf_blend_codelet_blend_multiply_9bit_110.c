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
    // Variant 2: Consecutive Block Access with Local Buffering
    // Process data in small consecutive blocks (e.g., 4 elements at a time) to improve cache reuse
    // This variant increases temporal locality by reusing loaded values
    const int block_size = 4;
    for (i = 0; i < height; i++) {
        for (j = 0; j <= width - block_size; j += block_size) {
            // Unroll loop to process 4 elements consecutively
            dst[j]     = top[j]     + ((((1) * (((top[j])     * (bottom[j]))     / 511))) - top[j])     * opacity;
            dst[j + 1] = top[j + 1] + ((((1) * (((top[j + 1]) * (bottom[j + 1])) / 511))) - top[j + 1]) * opacity;
            dst[j + 2] = top[j + 2] + ((((1) * (((top[j + 2]) * (bottom[j + 2])) / 511))) - top[j + 2]) * opacity;
            dst[j + 3] = top[j + 3] + ((((1) * (((top[j + 3]) * (bottom[j + 3])) / 511))) - top[j + 3]) * opacity;
        }
        // Handle remaining elements not fitting in full block
        for (; j < width; j++) {
            dst[j] = top[j] + ((((1) * (((top[j]) * (bottom[j])) / 511))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
