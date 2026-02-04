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
    for (j = 0; j < width; j += 4) {
        double opacity_inv = 1.0 - opacity;
        uint8_t t = top[j];
        uint8_t b = bottom[j];
        uint8_t result;

        if (b < 128) {
            result = (uint8_t)((2 * b * t) / 255);
        } else {
            result = (uint8_t)(255 - (2 * (255 - b) * (255 - t)) / 255);
        }

        dst[j] = (uint8_t)(t + (result - t) * opacity);

        // Unroll inner loop by 4 (assuming width is multiple of 4)
        if (j + 1 < width) {
            t = top[j+1]; b = bottom[j+1];
            if (b < 128) {
                result = (uint8_t)((2 * b * t) / 255);
            } else {
                result = (uint8_t)(255 - (2 * (255 - b) * (255 - t)) / 255);
            }
            dst[j+1] = (uint8_t)(t + (result - t) * opacity);
        }
        if (j + 2 < width) {
            t = top[j+2]; b = bottom[j+2];
            if (b < 128) {
                result = (uint8_t)((2 * b * t) / 255);
            } else {
                result = (uint8_t)(255 - (2 * (255 - b) * (255 - t)) / 255);
            }
            dst[j+2] = (uint8_t)(t + (result - t) * opacity);
        }
        if (j + 3 < width) {
            t = top[j+3]; b = bottom[j+3];
            if (b < 128) {
                result = (uint8_t)((2 * b * t) / 255);
            } else {
                result = (uint8_t)(255 - (2 * (255 - b) * (255 - t)) / 255);
            }
            dst[j+3] = (uint8_t)(t + (result - t) * opacity);
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
