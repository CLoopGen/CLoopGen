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
    for (int offset = 0; offset < 4; offset++) {
        int idx = offset;
        dst[idx] = cm[(filter[2] * src[idx + 0 * srcstride] - filter[1] * src[idx - 1 * srcstride] + filter[0] * src[idx - 2 * srcstride] + filter[3] * src[idx + 1 * srcstride] - filter[4] * src[idx + 2 * srcstride] + filter[5] * src[idx + 3 * srcstride] + 64) >> 7];
    }
    dst += dststride;
    src += srcstride;
}
}
