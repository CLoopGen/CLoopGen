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
    ptrdiff_t idx = 0;
    for (j = 0; j < width; j++, idx += 2) {
        dst[idx] = top[idx] + (((bottom[idx] < 512) ? ((2) * (((bottom[idx]) * (top[idx])) / 1023)) : (1023 - (2) * ((1023 - (bottom[idx])) * (1023 - (top[idx])) / 1023))) - top[idx]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
