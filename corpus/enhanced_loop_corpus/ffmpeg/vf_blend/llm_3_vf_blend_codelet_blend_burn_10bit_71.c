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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 2) { // Strided access with step 2
        // Process two elements per iteration (unrolled-like pattern)
        if (j + 1 < width) {
            // Handle even index
            dst[j] = top[j] + (((((top[j]) == 0) ? (top[j]) : ((0) > (1023 - ((1023 - (bottom[j])) << 10) / (top[j])) ? (0) : (1023 - ((1023 - (bottom[j])) << 10) / (top[j]))))) - top[j]) * opacity;
            // Handle odd index
            dst[j+1] = top[j+1] + (((((top[j+1]) == 0) ? (top[j+1]) : ((0) > (1023 - ((1023 - (bottom[j+1])) << 10) / (top[j+1])) ? (0) : (1023 - ((1023 - (bottom[j+1])) << 10) / (top[j+1]))))) - top[j+1]) * opacity;
        } else {
            // Handle edge case when width is odd
            dst[j] = top[j] + (((((top[j]) == 0) ? (top[j]) : ((0) > (1023 - ((1023 - (bottom[j])) << 10) / (top[j])) ? (0) : (1023 - ((1023 - (bottom[j])) << 10) / (top[j]))))) - top[j]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
