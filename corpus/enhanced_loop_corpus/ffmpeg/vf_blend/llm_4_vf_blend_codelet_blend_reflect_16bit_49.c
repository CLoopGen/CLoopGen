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
        uint16_t computed;
        if (bottom_val == 65535) {
            computed = 65535;
        } else {
            uint32_t num = (uint32_t)top_val * top_val;
            uint32_t denom = 65535 - bottom_val;
            uint16_t div_result = (denom == 0) ? 65535 : (num / denom);
            computed = (div_result > 65535) ? 65535 : div_result;
        }
        dst[j] = top_val + (computed - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
