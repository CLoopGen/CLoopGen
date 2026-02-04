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
    // Variant 2: Strided memory access by processing every second element forward and backward
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;
    uint16_t *dst_ptr = dst;
    ptrdiff_t stride = 2;

    for (i = 0; i < height; i++) {
        // Forward pass: even indices
        for (j = 0; j < width; j += stride) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] + bottom_ptr[j]) / 2) - top_ptr[j]) * opacity;
        }
        // Backward pass: odd indices
        for (j = 1; j < width; j += stride) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] + bottom_ptr[j]) / 2) - top_ptr[j]) * opacity;
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
