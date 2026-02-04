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
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        uint16_t result;
        if (b == 4095) {
            result = 4095;
        } else {
            uint32_t num = (uint32_t)t * t;
            result = (num / (4095 - b)) > 4095 ? 4095 : (num / (4095 - b));
        }
        dst[j] = t + (result - t) * opacity;

        if (j + 1 < width) {
            t = top[j+1];
            b = bottom[j+1];
            if (b == 4095) {
                result = 4095;
            } else {
                uint32_t num = (uint32_t)t * t;
                result = (num / (4095 - b)) > 4095 ? 4095 : (num / (4095 - b));
            }
            dst[j+1] = t + (result - t) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
