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
    // Variant 2: Consecutive Array Access via Pointer Arithmetic (unrolled by 2)
    uint16_t *top_ptr, *bottom_ptr, *dst_ptr;
    for (i = 0; i < height; i++) {
        top_ptr = top;
        bottom_ptr = bottom;
        dst_ptr = dst;
        // Unroll by 2 for consecutive access and better locality
        for (j = 0; j < width - 1; j += 2) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] + bottom_ptr[j]) / 2) - top_ptr[j]) * opacity;
            dst_ptr[j + 1] = top_ptr[j + 1] + (((top_ptr[j + 1] + bottom_ptr[j + 1]) / 2) - top_ptr[j + 1]) * opacity;
        }
        // Handle remaining element
        if (j == width - 1) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] + bottom_ptr[j]) / 2) - top_ptr[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
