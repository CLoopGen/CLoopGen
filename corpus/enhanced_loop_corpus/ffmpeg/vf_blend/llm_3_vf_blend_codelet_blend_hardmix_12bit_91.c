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
    // Variant 2: Consecutive Reverse Traversal with Local Pointer Variables
    for (i = 0; i < height; i++) {
        uint16_t *dst_ptr = dst + width - 1;
        uint16_t *top_ptr = top + width - 1;
        uint16_t *bottom_ptr = bottom + width - 1;

        for (j = width - 1; j >= 0; j--) {
            dst_ptr[0] = top_ptr[0] + (((top_ptr[0] < (4095 - bottom_ptr[0])) ? 0 : 4095) - top_ptr[0]) * opacity;
            dst_ptr--;
            top_ptr--;
            bottom_ptr--;
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
