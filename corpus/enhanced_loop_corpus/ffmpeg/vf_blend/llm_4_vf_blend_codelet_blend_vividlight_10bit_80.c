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
        int scaled_opacity = (int)(opacity * (1 << 10)); // Fixed-point scaling
        int result;

        if (t < 512) {
            int temp = (2 * t) == 0 ? 0 : (1023 - ((1023 - b) << 10) / (2 * t));
            result = (temp < 0) ? 0 : (temp > 1023 ? 1023 : temp);
        } else {
            int adjusted_t = 2 * (t - 512);
            int denom = 1023 - adjusted_t;
            int temp = (denom == 0) ? 1023 : (((b << 10) / denom));
            result = (temp > 1023) ? 1023 : (temp < 0 ? 0 : temp);
        }
        dst[j] = t + ((result - t) * scaled_opacity >> 10);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
