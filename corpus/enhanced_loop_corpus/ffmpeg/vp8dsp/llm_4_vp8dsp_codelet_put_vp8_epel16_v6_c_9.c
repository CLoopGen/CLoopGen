#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        if (y % 2 == 0) {
            for (x = 0; x < 16; x++) {
                int val = filter[2] * src[x + 0 * srcstride] - filter[1] * src[x - 1 * srcstride] +
                          filter[0] * src[x - 2 * srcstride] + filter[3] * src[x + 1 * srcstride] -
                          filter[4] * src[x + 2 * srcstride] + filter[5] * src[x + 3 * srcstride] + 64;
                dst[x] = cm[val >> 7];
            }
        } else {
            for (x = 0; x < 16; x += 2) {
                int val1 = filter[2] * src[x + 0 * srcstride] - filter[1] * src[x - 1 * srcstride] +
                           filter[0] * src[x - 2 * srcstride] + filter[3] * src[x + 1 * srcstride] -
                           filter[4] * src[x + 2 * srcstride] + filter[5] * src[x + 3 * srcstride] + 64;
                int val2 = filter[2] * src[x + 1 + 0 * srcstride] - filter[1] * src[x + 1 - 1 * srcstride] +
                           filter[0] * src[x + 1 - 2 * srcstride] + filter[3] * src[x + 1 + 1 * srcstride] -
                           filter[4] * src[x + 1 + 2 * srcstride] + filter[5] * src[x + 1 + 3 * srcstride] + 64;
                dst[x]     = cm[val1 >> 7];
                dst[x + 1] = cm[val2 >> 7];
            }
        }
        dst += dststride;
        src += srcstride;
    }
}
