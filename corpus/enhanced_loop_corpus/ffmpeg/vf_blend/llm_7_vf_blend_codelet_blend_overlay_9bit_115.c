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
    uint16_t prev_top_j = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t adjusted_top = (j == 0) ? top[j] : (top[j] + prev_top_j) / 2;
            dst[j] = adjusted_top + (((adjusted_top < 256) ? ((2) * (((adjusted_top) * (bottom[j])) / 511)) : (511 - (2) * ((511 - adjusted_top) * (511 - (bottom[j])) / 511))) - adjusted_top) * opacity;
            prev_top_j = top[j];
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
