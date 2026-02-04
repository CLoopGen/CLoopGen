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
    ptrdiff_t total_elements = height * dst_linesize;
    uint16_t *dst_ptr = dst;
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;

    for (i = 0; i < height; i++) {
        // Process even indices first with stride of 2
        for (j = 0; j < width; j += 2) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] > bottom_ptr[j] ? top_ptr[j] : bottom_ptr[j]) - top_ptr[j]) * opacity);
        }
        // Process odd indices
        for (j = 1; j < width; j += 2) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] > bottom_ptr[j] ? top_ptr[j] : bottom_ptr[j]) - top_ptr[j]) * opacity);
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
