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
        dst[j] = top[j] + ((511 - ((511 - top[j] - bottom[j]) >= 0 ? (511 - top[j] - bottom[j]) : (-(511 - top[j] - bottom[j])))) - top[j]) * opacity;
        if (i + 1 < height) {
            ptrdiff_t next_top = *(top + top_linesize + j);
            ptrdiff_t next_bottom = *(bottom + bottom_linesize + j);
            ptrdiff_t next_dst = *(dst + dst_linesize + j);
            ptrdiff_t temp = next_top + ((511 - ((511 - next_top - next_bottom) >= 0 ? (511 - next_top - next_bottom) : (-(511 - next_top - next_bottom)))) - next_top) * opacity;
            *(dst + dst_linesize + j) = temp;
        }
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
