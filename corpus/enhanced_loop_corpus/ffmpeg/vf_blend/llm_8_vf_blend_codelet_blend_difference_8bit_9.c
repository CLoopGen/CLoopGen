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
for (i = 0; i < height; i++) {
    ptrdiff_t offset = i * width;
    for (j = 0; j < width; j += 2) {
        int idx1 = offset + j;
        int idx2 = idx1 + 1;

        dst[idx1] = top[idx1] + ((((top[idx1] - bottom[idx1]) >= 0 ? (top[idx1] - bottom[idx1]) : (-(top[idx1] - bottom[idx1])))) - top[idx1]) * opacity;
        if (j + 1 < width) {
            dst[idx2] = top[idx2] + ((((top[idx2] - bottom[idx2]) >= 0 ? (top[idx2] - bottom[idx2]) : (-(top[idx2] - bottom[idx2])))) - top[idx2]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
