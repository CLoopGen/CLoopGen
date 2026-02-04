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
        uint16_t result;
        if (top_val == 65535) {
            result = top_val;
        } else {
            uint32_t temp = (uint32_t)bottom_val * bottom_val;
            uint32_t divisor = 65535 - top_val;
            uint16_t computed = (divisor > 0) ? (temp / divisor) : 65535;
            result = (computed > 65535) ? 65535 : computed;
        }
        dst[j] = top_val + (result - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
