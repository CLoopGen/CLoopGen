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
        dst[j] = top[j] + ((((1023) > (top[j] + bottom[j]) ? (top[j] + bottom[j]) : (1023))) - top[j]) * opacity;
        if (i + 1 < height) {
            ptrdiff_t next_top = top_linesize;
            ptrdiff_t next_bottom = bottom_linesize;
            ptrdiff_t next_dst = dst_linesize;
            dst[j + next_dst] = top[j + next_top] + ((((1023) > (top[j + next_top] + bottom[j + next_bottom]) ? (top[j + next_top] + bottom[j + next_bottom]) : (1023))) - top[j + next_top]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
