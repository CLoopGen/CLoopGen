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
    ptrdiff_t top_offset = i * top_linesize;
    ptrdiff_t bottom_offset = i * bottom_linesize;
    ptrdiff_t dst_offset = i * dst_linesize;

    for (j = 0; j < width; j++) {
        uint16_t t = top[top_offset + j];
        uint16_t b = bottom[bottom_offset + j];
        int is_low = t < 256;
        uint16_t blended;

        if (is_low) {
            blended = (2 * t * b) / 511;
        } else {
            blended = 511 - (2 * (511 - t) * (511 - b)) / 511;
        }

        dst[dst_offset + j] = t + (blended - t) * opacity;

        if (i + 1 < height) {
            ptrdiff_t t2_idx = (i + 1) * top_linesize + j;
            ptrdiff_t b2_idx = (i + 1) * bottom_linesize + j;
            ptrdiff_t d2_idx = (i + 1) * dst_linesize + j;

            uint16_t t2 = top[t2_idx];
            uint16_t b2 = bottom[b2_idx];
            int is_low2 = t2 < 256;
            uint16_t blended2;

            if (is_low2) {
                blended2 = (2 * t2 * b2) / 511;
            } else {
                blended2 = 511 - (2 * (511 - t2) * (511 - b2)) / 511;
            }

            dst[d2_idx] = t2 + (blended2 - t2) * opacity;
        }
    }
}
}
