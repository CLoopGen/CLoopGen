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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;
    uint16_t *dst_ptr = dst;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int idx = j;
            dst_ptr[idx] = top_ptr[idx] + (((top_ptr[idx] + bottom_ptr[idx]) / 2) - top_ptr[idx]) * opacity;
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
