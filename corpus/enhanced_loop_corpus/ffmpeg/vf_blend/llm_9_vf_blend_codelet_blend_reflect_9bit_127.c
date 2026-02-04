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
        uint16_t comp;

        if (b_val == 511) {
            comp = 511;
        } else {
            uint32_t sq = (uint32_t)t_val * t_val;
            uint32_t den = 511 - b_val;
            uint16_t div_result = (den == 0) ? 511 : (sq / den);
            comp = (div_result > 511) ? 511 : div_result;
        }
        dst[j] = t_val + (comp - t_val) * opacity;
    }

    if (i + 1 < height) {
        top += top_linesize;
        bottom += bottom_linesize;
        dst += dst_linesize;
        for (j = 0; j < width; j++) {
            uint16_t t_val = top[j];
            uint16_t b_val = bottom[j];
            dst[j] = t_val + (((b_val == 511) ? 511 : ((511) > ((t_val * t_val / (511 - b_val))) ? ((t_val * t_val / (511 - b_val))) : (511))) - t_val) * opacity;
        }
    }

    top += top_linesize;
    bottom += bottom_linesize;
    dst += dst_linesize;
}
}
