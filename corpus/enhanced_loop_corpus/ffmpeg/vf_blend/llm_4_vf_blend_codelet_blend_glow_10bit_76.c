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
    for (j = 0; j < width; j++) {
        uint16_t top_val = top[j];
        uint16_t bottom_val = bottom[j];
        uint16_t blended;
        if (top_val == 1023) {
            blended = 1023;
        } else {
            uint32_t temp = (uint32_t)bottom_val * bottom_val;
            uint32_t divisor = 1023 - top_val;
            uint16_t result = (divisor > 0) ? (temp / divisor) : 1023;
            blended = (result > 1023) ? 1023 : result;
        }
        dst[j] = top_val + (blended - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
