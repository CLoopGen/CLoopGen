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
        int idx = j;
        uint16_t top_val = top[idx];
        uint16_t bottom_val = bottom[idx];
        int diff = 511 - top_val - bottom_val;
        int abs_diff = diff >= 0 ? diff : -diff;
        dst[idx] = top_val + (abs_diff - top_val) * opacity;
    }
    dst += dst_linesize * 2;
    top += top_linesize * 2;
    bottom += bottom_linesize * 2;
    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            int idx = j;
            uint16_t top_val = top[idx] + top_linesize;
            uint16_t bottom_val = bottom[idx] + bottom_linesize;
            int diff = 511 - top_val - bottom_val;
            int abs_diff = diff >= 0 ? diff : -diff;
            dst[idx] = top_val + (abs_diff - top_val) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
