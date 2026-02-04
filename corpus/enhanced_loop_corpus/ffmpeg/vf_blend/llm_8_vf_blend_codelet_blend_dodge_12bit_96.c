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
        uint16_t blended;
        if (t == 4095) {
            blended = t;
        } else {
            int temp = (b << 12) / (4095 - t);
            blended = (temp > 4095) ? 4095 : temp;
        }
        dst[idx] = t + (blended - t) * opacity;
    }
    for (j = 0; j < width; j++) {
        int idx = j;
        uint16_t t = top[idx];
        uint16_t b = bottom[idx];
        uint16_t blended;
        if (t == 0) {
            blended = 0;
        } else {
            int temp = (b * t) >> 12;
            blended = (temp > 4095) ? 4095 : temp;
        }
        dst[idx] = t + (blended - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
    if (i + 1 < height) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
