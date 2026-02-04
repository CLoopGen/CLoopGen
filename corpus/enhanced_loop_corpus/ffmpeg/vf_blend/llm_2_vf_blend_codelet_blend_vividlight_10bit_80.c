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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    ptrdiff_t stride = 2;
    for (i = 0; i < height; i++) {
        // Process elements with stride 2
        for (j = 0; j < width - 1; j += stride) {
            dst[j] = top[j] + (((top[j] < 512) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) > (1023 - ((1023 - (bottom[j])) << 10) / (2 * top[j])) ? (0) : (1023 - ((1023 - (bottom[j])) << 10) / (2 * top[j])))) : (((2 * (top[j] - 512)) == 1023) ? (2 * (top[j] - 512)) : ((1023) > ((((bottom[j]) << 10) / (1023 - (2 * (top[j] - 512))))) ? ((((bottom[j]) << 10) / (1023 - (2 * (top[j] - 512))))) : (1023)))) - top[j]) * opacity;
            dst[j+1] = top[j+1] + (((top[j+1] < 512) ? (((2 * top[j+1]) == 0) ? (2 * top[j+1]) : ((0) > (1023 - ((1023 - (bottom[j+1])) << 10) / (2 * top[j+1])) ? (0) : (1023 - ((1023 - (bottom[j+1])) << 10) / (2 * top[j+1])))) : (((2 * (top[j+1] - 512)) == 1023) ? (2 * (top[j+1] - 512)) : ((1023) > ((((bottom[j+1]) << 10) / (1023 - (2 * (top[j+1] - 512))))) ? ((((bottom[j+1]) << 10) / (1023 - (2 * (top[j+1] - 512))))) : (1023)))) - top[j+1]) * opacity;
        }
        // Handle last element if width is odd
        if (j < width) {
            dst[j] = top[j] + (((top[j] < 512) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) > (1023 - ((1023 - (bottom[j])) << 10) / (2 * top[j])) ? (0) : (1023 - ((1023 - (bottom[j])) << 10) / (2 * top[j])))) : (((2 * (top[j] - 512)) == 1023) ? (2 * (top[j] - 512)) : ((1023) > ((((bottom[j]) << 10) / (1023 - (2 * (top[j] - 512))))) ? ((((bottom[j]) << 10) / (1023 - (2 * (top[j] - 512))))) : (1023)))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
