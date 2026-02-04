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
    ptrdiff_t adjusted_width = width / 4 * 4;
    for (j = 0; j < adjusted_width; j += 4) {
        uint32_t temp[4];
        for (int v = 0; v < 4; v++) {
            uint16_t t = top[j + v];
            uint16_t b = bottom[j + v];
            temp[v] = (t == 0) ? t : 
                      (0 > (4095 - ((4095 - b) << 12) / t) ? 0 : 
                       (4095 - ((4095 - b) << 12) / t));
            dst[j + v] = t + (temp[v] - t) * opacity;
        }
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((((top[j]) == 0) ? (top[j]) : ((0) > (4095 - ((4095 - (bottom[j])) << 12) / (top[j])) ? (0) : (4095 - ((4095 - (bottom[j])) << 12) / (top[j]))))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;

    if (i + 1 < height) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((((top[j]) == 0) ? (top[j]) : ((0) > (4095 - ((4095 - (bottom[j])) << 12) / (top[j])) ? (0) : (4095 - ((4095 - (bottom[j])) << 12) / (top[j]))))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
