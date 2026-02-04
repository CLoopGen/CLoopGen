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
    j = 0;
    while (j < width - 3) {
        int t0 = top[j], t1 = top[j+1], t2 = top[j+2], t3 = top[j+3];
        int b0 = bottom[j], b1 = bottom[j+1], b2 = bottom[j+2], b3 = bottom[j+3];

        dst[j]   = t0 + (((b0 == 0) ? 0 : 255 - ((((255 - t0) * (255 - t0)) / b0) > 255 ? 255 : (((255 - t0) * (255 - t0)) / b0))) - t0) * opacity;
        dst[j+1] = t1 + (((b1 == 0) ? 0 : 255 - ((((255 - t1) * (255 - t1)) / b1) > 255 ? 255 : (((255 - t1) * (255 - t1)) / b1))) - t1) * opacity;
        dst[j+2] = t2 + (((b2 == 0) ? 0 : 255 - ((((255 - t2) * (255 - t2)) / b2) > 255 ? 255 : (((255 - t2) * (255 - t2)) / b2))) - t2) * opacity;
        dst[j+3] = t3 + (((b3 == 0) ? 0 : 255 - ((((255 - t3) * (255 - t3)) / b3) > 255 ? 255 : (((255 - t3) * (255 - t3)) / b3))) - t3) * opacity;

        j += 4;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((bottom[j] == 0) ? 0 : 255 - ((((255 - top[j]) * (255 - top[j])) / bottom[j]) > (255) ? (255) : (((255 - top[j]) * (255 - top[j])) / bottom[j]))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
