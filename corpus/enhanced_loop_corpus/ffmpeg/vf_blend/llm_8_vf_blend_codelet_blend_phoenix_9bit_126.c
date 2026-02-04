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
        int idx1 = j;
        int idx2 = j + 1;
        double opacity_scaled = opacity * 511;
        if (idx2 < width) {
            dst[idx1] = top[idx1] + ((bottom[idx1] - top[idx1]) & ((top[idx1] > bottom[idx1]) - 1)) * opacity;
            dst[idx2] = top[idx2] + ((bottom[idx2] - top[idx2]) & ((top[idx2] > bottom[idx2]) - 1)) * opacity;
        } else {
            dst[idx1] = top[idx1] + ((bottom[idx1] - top[idx1]) & ((top[idx1] > bottom[idx1]) - 1)) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
