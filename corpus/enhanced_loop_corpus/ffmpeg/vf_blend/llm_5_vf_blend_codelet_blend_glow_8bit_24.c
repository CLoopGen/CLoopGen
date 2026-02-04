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
    for (j = 0; j < width; j++) {
        uint8_t t = top[j];
        uint8_t b = bottom[j];
        double result;

        if (t >= 250) {
            result = t;
        } else if (t < 10) {
            result = b;
        } else {
            double computed = (double)(b * b) / (255 - t);
            result = t + ((computed > 255 ? 255 : computed) - t) * opacity;
        }

        dst[j] = (uint8_t)result;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
