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
    // Variant 1: Strided memory access with step of 2 (unrolled-like pattern)
    // Accesses every second element in a strided manner, then handles remainder
    for (i = 0; i < height; i++) {
        for (j = 0; j + 1 < width; j += 2) {
            dst[j] = top[j] + ((((65535 - top[j] - bottom[j]) >= 0 ? (65535 - top[j] - bottom[j]) : (-(65535 - top[j] - bottom[j])))) - top[j]) * opacity;
            dst[j+1] = top[j+1] + ((((65535 - top[j+1] - bottom[j+1]) >= 0 ? (65535 - top[j+1] - bottom[j+1]) : (-(65535 - top[j+1] - bottom[j+1])))) - top[j+1]) * opacity;
        }
        // Handle last element if width is odd
        if (j < width) {
            dst[j] = top[j] + ((((65535 - top[j] - bottom[j]) >= 0 ? (65535 - top[j] - bottom[j]) : (-(65535 - top[j] - bottom[j])))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
