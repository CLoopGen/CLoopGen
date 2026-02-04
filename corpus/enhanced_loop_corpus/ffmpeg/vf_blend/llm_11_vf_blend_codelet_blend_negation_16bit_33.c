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
    ptrdiff_t dst_step = dst_linesize * 2;
    ptrdiff_t top_step = top_linesize * 2;
    ptrdiff_t bottom_step = bottom_linesize * 2;

    for (j = 0; j < width; j++) {
        dst[j] = top[j] + ((65535 - ((65535 - top[j] - bottom[j]) >= 0 ? (65535 - top[j] - bottom[j]) : (-(65535 - top[j] - bottom[j])))) - top[j]) * opacity;
    }

    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;

    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + ((65535 - ((65535 - top[j] - bottom[j]) >= 0 ? (65535 - top[j] - bottom[j]) : (-(65535 - top[j] - bottom[j])))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
