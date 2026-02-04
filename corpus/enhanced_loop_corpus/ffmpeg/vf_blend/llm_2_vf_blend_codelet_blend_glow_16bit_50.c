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
    // Instead of accessing consecutive elements (j), we access with a fixed stride of 2,
    // processing even indices first, then odd in a second pass to maintain coverage.
    ptrdiff_t stride = 2;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += stride) {
            if (j + 1 < width) {
                // Process two elements: j and j+1 (unrolled-like pattern with stride)
                dst[j] = top[j] + (((top[j] == 65535) ? top[j] : ((65535) > ((bottom[j] * bottom[j] / (65535 - top[j]))) ? ((bottom[j] * bottom[j] / (65535 - top[j]))) : (65535))) - top[j]) * opacity;
                dst[j+1] = top[j+1] + (((top[j+1] == 65535) ? top[j+1] : ((65535) > ((bottom[j+1] * bottom[j+1] / (65535 - top[j+1]))) ? ((bottom[j+1] * bottom[j+1] / (65535 - top[j+1]))) : (65535))) - top[j+1]) * opacity;
            } else {
                dst[j] = top[j] + (((top[j] == 65535) ? top[j] : ((65535) > ((bottom[j] * bottom[j] / (65535 - top[j]))) ? ((bottom[j] * bottom[j] / (65535 - top[j]))) : (65535))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
