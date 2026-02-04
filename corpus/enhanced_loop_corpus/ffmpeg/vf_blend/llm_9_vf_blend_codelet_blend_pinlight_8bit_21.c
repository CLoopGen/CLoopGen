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
    ptrdiff_t w = width;
    while (w >= 4) {
        uint8_t t0 = top[0], t1 = top[1], t2 = top[2], t3 = top[3];
        uint8_t b0 = bottom[0], b1 = bottom[1], b2 = bottom[2], b3 = bottom[3];
        
        dst[0] = t0 + (((b0 < 128) ? (t0 > (2 * b0) ? (2 * b0) : t0) : (t0 > (2 * (b0 - 128)) ? t0 : (2 * (b0 - 128)))) - t0) * opacity;
        dst[1] = t1 + (((b1 < 128) ? (t1 > (2 * b1) ? (2 * b1) : t1) : (t1 > (2 * (b1 - 128)) ? t1 : (2 * (b1 - 128)))) - t1) * opacity;
        dst[2] = t2 + (((b2 < 128) ? (t2 > (2 * b2) ? (2 * b2) : t2) : (t2 > (2 * (b2 - 128)) ? t2 : (2 * (b2 - 128)))) - t2) * opacity;
        dst[3] = t3 + (((b3 < 128) ? (t3 > (2 * b3) ? (2 * b3) : t3) : (t3 > (2 * (b3 - 128)) ? t3 : (2 * (b3 - 128)))) - t3) * opacity;

        top += 4; bottom += 4; dst += 4;
        w -= 4;
    }
    while (w > 0) {
        dst[0] = top[0] + (((bottom[0] < 128) ? ((top[0]) > (2 * bottom[0]) ? (2 * bottom[0]) : (top[0])) : ((top[0]) > (2 * (bottom[0] - 128)) ? (top[0]) : (2 * (bottom[0] - 128)))) - top[0]) * opacity;
        top++; bottom++; dst++;
        w--;
    }
    dst += dst_linesize - width;
    top += top_linesize - width;
    bottom += bottom_linesize - width;
}
}
