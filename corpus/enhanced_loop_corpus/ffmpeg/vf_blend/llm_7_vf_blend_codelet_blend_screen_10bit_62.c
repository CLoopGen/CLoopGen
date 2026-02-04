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
        uint16_t current_top = top[j];
        uint16_t blended = current_top + (((1023 - (1) * ((1023 - current_top) * (1023 - bottom[j]) / 1023)) - current_top) * opacity);
        dst[j] = (j == 0) ? blended : (blended + prev_top_j) >> 1;
        prev_top_j = current_top;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
    prev_top_j = 0;
}
}
