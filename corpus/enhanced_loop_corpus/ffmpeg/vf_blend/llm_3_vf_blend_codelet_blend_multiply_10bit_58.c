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
    for (j = 0; j < width; j += 2) {
        ptrdiff_t tj = j;
        ptrdiff_t bj = j;
        ptrdiff_t dj = j;
        if (j + 1 < width) {
            dst[dj] = top[tj] + ((((1) * (((top[tj]) * (bottom[bj])) / 1023))) - top[tj]) * opacity;
            dst[dj + 1] = top[tj + 1] + ((((1) * (((top[tj + 1]) * (bottom[bj + 1])) / 1023))) - top[tj + 1]) * opacity;
        } else {
            dst[dj] = top[tj] + ((((1) * (((top[tj]) * (bottom[bj])) / 1023))) - top[tj]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
