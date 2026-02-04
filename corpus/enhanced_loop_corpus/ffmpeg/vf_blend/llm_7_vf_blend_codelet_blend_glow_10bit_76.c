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
    for (i = 0; i < height; i++) {
        uint16_t prev_top_j = 0, prev_bottom_j = 0;
        for (j = 0; j < width; j++) {
            uint16_t current_top = top[j];
            uint16_t current_bottom = bottom[j];
            uint16_t computed;
            if (current_top == 1023) {
                computed = 1023;
            } else {
                uint16_t denominator = 1023 - current_top;
                uint32_t product = (uint32_t)current_bottom * current_bottom;
                uint16_t ratio = (denominator == 0) ? 1023 : (product / denominator);
                computed = (ratio > 1023) ? 1023 : ratio;
            }
            dst[j] = current_top + (computed - current_top) * opacity;
            prev_top_j = current_top;
            prev_bottom_j = current_bottom;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
