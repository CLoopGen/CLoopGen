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
        uint16_t b0 = bottom[j], t0 = top[j];
        uint16_t b1 = bottom[j+1], t1 = top[j+1];
        dst[j]   = t0 + (((b0 < 32768) ? ((2) * ((b0 * t0) / 65535)) : (65535 - (2) * ((65535 - b0) * (65535 - t0)) / 65535)) - t0) * opacity;
        dst[j+1] = t1 + (((b1 < 32768) ? ((2) * ((b1 * t1) / 65535)) : (65535 - (2) * ((65535 - b1) * (65535 - t1)) / 65535)) - t1) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
