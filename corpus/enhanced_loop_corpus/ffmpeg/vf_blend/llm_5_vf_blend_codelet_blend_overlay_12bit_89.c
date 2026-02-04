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
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        uint16_t blended;
        uint16_t base = 4095;
        uint16_t threshold = 2048;

        if (t >= threshold && b >= threshold) {
            blended = base - (2 * ((base - t) * (base - b) / base));
        } else if (t < threshold && b < threshold) {
            blended = (2 * (t * b) / base);
        } else {
            blended = (t * b) / base;
        }
        dst[j] = t + (blended - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
