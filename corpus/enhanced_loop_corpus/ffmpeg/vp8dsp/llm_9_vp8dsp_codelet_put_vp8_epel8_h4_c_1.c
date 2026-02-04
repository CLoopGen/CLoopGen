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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < 8; x++) {
        int base_val = filter[2] * src[x] - filter[1] * src[x - 1] + filter[3] * src[x + 1] - filter[4] * src[x + 2];
        dst[x] = cm[(base_val + 64) >> 7];
        if (y + 1 < h) {
            dst[dststride + x] = cm[(base_val + 96) >> 7];
        }
    }
    dst += 2 * dststride;
    src += 2 * srcstride;
}
}
