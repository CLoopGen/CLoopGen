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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        uint8_t t = top[j];
        uint8_t b = bottom[j];
        uint8_t result;
        if (t == 255) {
            result = 255;
        } else {
            int temp = (int)(b * b) / (255 - t);
            result = (temp > 255) ? 255 : temp;
        }
        dst[j] = t + (result - t) * opacity;
    }
    if (i + 1 < height) {
        dst += dst_linesize * 2;
        top += top_linesize * 2;
        bottom += bottom_linesize * 2;
    } else {
        break;
    }
}
}
