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
        uint16_t inverted = 1023 - top_val;
        uint16_t result_sq_div = (bottom_val == 0) ? 1023 : ((inverted * inverted) / bottom_val);
        uint16_t clamped = result_sq_div < 1023 ? result_sq_div : 1023;
        uint16_t blend_component = (bottom_val == 0) ? 0 : (1023 - clamped);
        dst[j] = top_val + (blend_component - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
