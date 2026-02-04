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
        uint16_t t_val = top[j];
        uint16_t b_val = bottom[j];
        uint32_t numerator = (65535 - t_val);
        numerator *= numerator;
        uint32_t result_div = (b_val == 0) ? 65535 : numerator / b_val;
        uint32_t clamped = (result_div > 65535) ? 65535 : result_div;
        dst[j] = t_val + (clamped - t_val) * opacity;
    }

    if (i + 1 < height) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;

        for (j = 0; j < width; j++) {
            dst[j] = top[j];
        }
    }

    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
