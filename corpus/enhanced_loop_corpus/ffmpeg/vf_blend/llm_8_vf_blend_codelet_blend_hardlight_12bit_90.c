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
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        uint32_t product = (uint32_t)b * t;
        uint16_t blended = (b < 2048) ? (uint16_t)((2 * product) / 4095) : (uint16_t)(4095 - (2 * (uint32_t)(4095 - b) * (4095 - t)) / 4095);
        dst[j] = t + (int16_t)((blended - t) * opacity);
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
