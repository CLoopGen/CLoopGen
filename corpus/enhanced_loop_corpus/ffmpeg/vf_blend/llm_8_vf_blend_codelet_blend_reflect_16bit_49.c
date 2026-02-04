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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        uint16_t top_val = top[j];
        uint16_t bottom_val = bottom[j];
        uint16_t result;
        if (bottom_val == 65535) {
            result = 65535;
        } else {
            uint32_t numerator = (uint32_t)top_val * top_val;
            uint32_t denominator = 65535 - bottom_val;
            uint16_t blend = (denominator > 0) ? (numerator / denominator) : 65535;
            result = (blend < 65535) ? blend : 65535;
        }
        dst[j] = top_val + (result - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
    if (i + 1 < height) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
