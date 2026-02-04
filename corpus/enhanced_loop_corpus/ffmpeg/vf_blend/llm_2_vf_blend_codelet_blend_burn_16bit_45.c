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
    ptrdiff_t stride = 2; // Access every second element
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += stride) {
            if (j + 1 < width) { // Ensure we don't go out of bounds
                dst[j] = top[j] + (((((top[j]) == 0) ? (top[j]) : ((0) > (65535 - ((65535 - (bottom[j])) << 16) / (top[j])) ? (0) : (65535 - ((65535 - (bottom[j])) << 16) / (top[j]))))) - top[j]) * opacity;
                dst[j + 1] = top[j + 1] + (((((top[j + 1]) == 0) ? (top[j + 1]) : ((0) > (65535 - ((65535 - (bottom[j + 1])) << 16) / (top[j + 1])) ? (0) : (65535 - ((65535 - (bottom[j + 1])) << 16) / (top[j + 1]))))) - top[j + 1]) * opacity;
            } else {
                dst[j] = top[j] + (((((top[j]) == 0) ? (top[j]) : ((0) > (65535 - ((65535 - (bottom[j])) << 16) / (top[j])) ? (0) : (65535 - ((65535 - (bottom[j])) << 16) / (top[j]))))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
