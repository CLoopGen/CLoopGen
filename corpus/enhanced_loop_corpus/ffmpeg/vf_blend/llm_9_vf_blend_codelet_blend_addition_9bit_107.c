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
        uint16_t sum = t_val + b_val;
        uint16_t clamped = (sum > 511) ? 511 : sum;
        dst[j] = t_val + (clamped - t_val) * opacity;

        if (i + 1 < height) {
            t_val = top[j + top_linesize];
            b_val = bottom[j + bottom_linesize];
            sum = t_val + b_val;
            clamped = (sum > 511) ? 511 : sum;
            dst[j + dst_linesize] = t_val + (clamped - t_val) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
