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
    // Variant 1: Consecutive memory access with pointer arithmetic and local stride simulation
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;
    uint16_t *dst_ptr = dst;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = j;
            uint16_t t = top_ptr[idx];
            uint16_t b = bottom_ptr[idx];
            dst_ptr[idx] = t + (((t < 256) ? (((2 * t) == 0) ? (2 * t) : ((0) > (511 - ((511 - b) << 9) / (2 * t)) ? (0) : (511 - ((511 - b) << 9) / (2 * t)))) : (((2 * (t - 256)) == 511) ? (2 * (t - 256)) : ((511) > (((b << 9) / (511 - (2 * (t - 256))))) ? (((b << 9) / (511 - (2 * (t - 256))))) : (511)))) - t) * opacity;
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
