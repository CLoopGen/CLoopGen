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
    ptrdiff_t dst_idx = 0;
    ptrdiff_t top_idx = 0;
    ptrdiff_t bottom_idx = 0;
    for (j = 0; j < width; j++) {
        dst[dst_idx] = top[top_idx] + (((bottom[bottom_idx] == 511) ? bottom[bottom_idx] : ((511) > ((top[top_idx] * top[top_idx] / (511 - bottom[bottom_idx]))) ? ((top[top_idx] * top[top_idx] / (511 - bottom[bottom_idx]))) : (511))) - top[top_idx]) * opacity;
        dst_idx++;
        top_idx++;
        bottom_idx++;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
