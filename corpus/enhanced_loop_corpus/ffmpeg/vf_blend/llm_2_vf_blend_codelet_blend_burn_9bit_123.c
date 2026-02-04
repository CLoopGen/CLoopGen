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
    ptrdiff_t dst_offset = i * dst_linesize;
    ptrdiff_t top_offset = i * top_linesize;
    ptrdiff_t bottom_offset = i * bottom_linesize;
    for (j = 0; j < width; j++) {
        ptrdiff_t idx = j;
        dst[dst_offset + idx] = top[top_offset + idx] + (((((top[top_offset + idx]) == 0) ? (top[top_offset + idx]) : ((0) > (511 - ((511 - (bottom[bottom_offset + idx])) << 9) / (top[top_offset + idx]))) ? (0) : (511 - ((511 - (bottom[bottom_offset + idx])) << 9) / (top[top_offset + idx])))) - top[top_offset + idx]) * opacity;
    }
}
}
