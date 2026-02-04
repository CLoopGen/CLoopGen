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
        int j1 = j;
        int j2 = j + 1;
        if (j2 >= width) {
            dst[j1] = top[j1] + (((bottom[j1] < 2048) ? ((top[j1]) > (2 * bottom[j1]) ? (2 * bottom[j1]) : (top[j1])) : ((top[j1]) > (2 * (bottom[j1] - 2048)) ? (top[j1]) : (2 * (bottom[j1] - 2048)))) - top[j1]) * opacity;
        } else {
            uint16_t t1 = top[j1], b1 = bottom[j1];
            uint16_t t2 = top[j2], b2 = bottom[j2];

            uint16_t val1 = (b1 < 2048) ? (t1 > (2 * b1) ? (2 * b1) : t1) : (t1 > (2 * (b1 - 2048)) ? t1 : (2 * (b1 - 2048)));
            uint16_t val2 = (b2 < 2048) ? (t2 > (2 * b2) ? (2 * b2) : t2) : (t2 > (2 * (b2 - 2048)) ? t2 : (2 * (b2 - 2048)));

            dst[j1] = t1 + (val1 - t1) * opacity;
            dst[j2] = t2 + (val2 - t2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
