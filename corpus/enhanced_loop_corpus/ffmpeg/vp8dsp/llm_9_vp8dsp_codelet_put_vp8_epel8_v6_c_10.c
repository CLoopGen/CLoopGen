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
        int base_val = filter[2] * src[x + 0 * srcstride] - filter[1] * src[x - 1 * srcstride] +
                       filter[0] * src[x - 2 * srcstride] + filter[3] * src[x + 1 * srcstride] -
                       filter[4] * src[x + 2 * srcstride] + filter[5] * src[x + 3 * srcstride] + 64;
        dst[x] = cm[base_val >> 7];

        if (y + 1 < h) {
            int offset_src = srcstride * 1;
            int val_next = filter[2] * src[x + offset_src + 0 * srcstride] - 
                           filter[1] * src[x + offset_src - 1 * srcstride] + 
                           filter[0] * src[x + offset_src - 2 * srcstride] + 
                           filter[3] * src[x + offset_src + 1 * srcstride] - 
                           filter[4] * src[x + offset_src + 2 * srcstride] + 
                           filter[5] * src[x + offset_src + 3 * srcstride] + 64;
            dst[dststride + x] = cm[val_next >> 7];
        }
    }
    dst += 2 * dststride;
    src += 2 * srcstride;
}
}
