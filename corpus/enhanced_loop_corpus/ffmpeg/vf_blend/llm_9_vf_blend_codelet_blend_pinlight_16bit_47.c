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
    j = 0;
    while (j < width - 3) {
        uint16_t t0 = top[j], t1 = top[j+1], t2 = top[j+2], t3 = top[j+3];
        uint16_t b0 = bottom[j], b1 = bottom[j+1], b2 = bottom[j+2], b3 = bottom[j+3];

        dst[j]   = t0 + (((b0 < 32768) ? ((t0 > 2*b0) ? (2*b0) : t0) : ((t0 > 2*(b0-32768)) ? t0 : 2*(b0-32768))) - t0) * opacity;
        dst[j+1] = t1 + (((b1 < 32768) ? ((t1 > 2*b1) ? (2*b1) : t1) : ((t1 > 2*(b1-32768)) ? t1 : 2*(b1-32768))) - t1) * opacity;
        dst[j+2] = t2 + (((b2 < 32768) ? ((t2 > 2*b2) ? (2*b2) : t2) : ((t2 > 2*(b2-32768)) ? t2 : 2*(b2-32768))) - t2) * opacity;
        dst[j+3] = t3 + (((b3 < 32768) ? ((t3 > 2*b3) ? (2*b3) : t3) : ((t3 > 2*(b3-32768)) ? t3 : 2*(b3-32768))) - t3) * opacity;

        j += 4;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((bottom[j] < 32768) ? ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : ((top[j]) > (2 * (bottom[j] - 32768)) ? (top[j]) : (2 * (bottom[j] - 32768)))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
