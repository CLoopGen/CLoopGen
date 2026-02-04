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
        int k = j + 1;
        dst[j] = top[j] + (((bottom[j] < 256) ? ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : ((top[j]) > (2 * (bottom[j] - 256)) ? (top[j]) : (2 * (bottom[j] - 256)))) - top[j]) * opacity;
        if (k < width) {
            dst[k] = top[k] + (((bottom[k] < 256) ? ((top[k]) > (2 * bottom[k]) ? (2 * bottom[k]) : (top[k])) : ((top[k]) > (2 * (bottom[k] - 256)) ? (top[k]) : (2 * (bottom[k] - 256)))) - top[k]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
