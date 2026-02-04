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
for (i = 0; i < height * width; i++) {
    int local_j = i % width;
    int local_i = i / width;
    dst[local_j] = top[local_j] + (((bottom[local_j] < 512) ? ((top[local_j]) > (2 * bottom[local_j]) ? (2 * bottom[local_j]) : (top[local_j])) : ((top[local_j]) > (2 * (bottom[local_j] - 512)) ? (top[local_j]) : (2 * (bottom[local_j] - 512)))) - top[local_j]) * opacity;
    if (local_j == width - 1) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
