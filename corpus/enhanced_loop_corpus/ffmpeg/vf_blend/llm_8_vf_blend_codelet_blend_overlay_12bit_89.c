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
    ptrdiff_t offset = i * width;
    for (j = 0; j < width; j += 2) {
        int idx1 = offset + j;
        int idx2 = idx1 + 1;

        // Process two elements per iteration to reduce loop overhead
        if (idx2 < offset + width) {
            dst[idx1] = top[idx1] + (((top[idx1] < 2048) ? ((2) * (((top[idx1]) * (bottom[idx1])) / 4095)) : (4095 - (2) * ((4095 - (top[idx1])) * (4095 - (bottom[idx1])) / 4095))) - top[idx1]) * opacity;
            dst[idx2] = top[idx2] + (((top[idx2] < 2048) ? ((2) * (((top[idx2]) * (bottom[idx2])) / 4095)) : (4095 - (2) * ((4095 - (top[idx2])) * (4095 - (bottom[idx2])) / 4095))) - top[idx2]) * opacity;
        } else {
            dst[idx1] = top[idx1] + (((top[idx1] < 2048) ? ((2) * (((top[idx1]) * (bottom[idx1])) / 4095)) : (4095 - (2) * ((4095 - (top[idx1])) * (4095 - (bottom[idx1])) / 4095))) - top[idx1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
