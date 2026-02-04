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
        uint16_t t = top[idx];
        uint16_t b = bottom[idx];
        uint16_t result;
        if (b < 256) {
            result = (2 * b * t) / 511;
        } else {
            result = 511 - (2 * (511 - b) * (511 - t)) / 511;
        }
        dst[idx] = t + (result - t) * opacity;
    }
    for (j = 0; j < width; j++) {
        int idx = j;
        uint16_t t = top[idx + width];
        uint16_t b = bottom[idx + width];
        uint16_t result;
        if (b < 256) {
            result = (2 * b * t) / 511;
        } else {
            result = 511 - (2 * (511 - b) * (511 - t)) / 511;
        }
        dst[idx + width] = t + (result - t) * opacity;
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
