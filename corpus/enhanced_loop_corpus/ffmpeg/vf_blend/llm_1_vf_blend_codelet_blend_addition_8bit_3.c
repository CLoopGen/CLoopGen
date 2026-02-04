#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        dst[j] = top[j] + ((((255) > (top[j] + bottom[j]) ? (top[j] + bottom[j]) : (255))) - top[j]) * opacity;
        if (i + 1 < height) {
            uint8_t *next_dst = dst + dst_linesize;
            uint8_t *next_top = top + top_linesize;
            uint8_t *next_bottom = bottom + bottom_linesize;
            next_dst[j] = next_top[j] + ((((255) > (next_top[j] + next_bottom[j]) ? (next_top[j] + next_bottom[j]) : (255))) - next_top[j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
