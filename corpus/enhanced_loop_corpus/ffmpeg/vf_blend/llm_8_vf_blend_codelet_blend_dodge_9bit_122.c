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
        int top_val = top[j];
        int bottom_val = bottom[j];
        int diff = 511 - top_val;
        int scaled;
        if (diff == 0) {
            scaled = 511;
        } else {
            scaled = (bottom_val << 9) / diff;
            if (scaled > 511) scaled = 511;
        }
        if (top_val == 511) {
            dst[j] = top_val;
        } else {
            dst[j] = top_val + (scaled - top_val) * opacity;
        }
    }
    for (j = 0; j < width; j++) {
        int top_val = top[j] + top_linesize;
        int bottom_val = bottom[j] + bottom_linesize;
        int diff = 511 - top_val;
        int scaled;
        if (diff == 0) {
            scaled = 511;
        } else {
            scaled = (bottom_val << 9) / diff;
            if (scaled > 511) scaled = 511;
        }
        if (top_val == 511) {
            dst[j + dst_linesize] = top_val;
        } else {
            dst[j + dst_linesize] = top_val + (scaled - top_val) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
