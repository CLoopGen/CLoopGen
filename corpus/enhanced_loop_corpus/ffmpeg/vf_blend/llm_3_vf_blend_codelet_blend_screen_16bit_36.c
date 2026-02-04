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
    // Strided memory access: process every 2nd element in reverse order to change access pattern
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j -= 2) {
            // Access elements with stride of 2, reversed
            dst[j] = top[j] + (((65535 - (1) * ((65535 - (top[j])) * (65535 - (bottom[j])) / 65535))) - top[j]) * opacity;
            if (j > 0) {
                // Handle the intermediate element for completeness
                dst[j-1] = top[j-1] + (((65535 - (1) * ((65535 - (top[j-1])) * (65535 - (bottom[j-1])) / 65535))) - top[j-1]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
