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
        uint16_t compensated = 511 - top_val;
        uint16_t divisor = (bottom_val == 0) ? 1 : bottom_val;
        uint32_t quotient = ((uint32_t)(compensated * compensated)) / divisor;
        uint16_t clamped = quotient & ((quotient <= 511) * 0xFFFF);
        uint16_t adjusted = (quotient > 511) ? 511 : clamped;
        uint16_t blend = (bottom_val == 0) ? 0 : adjusted;

        dst[j] = top_val + (blend - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
