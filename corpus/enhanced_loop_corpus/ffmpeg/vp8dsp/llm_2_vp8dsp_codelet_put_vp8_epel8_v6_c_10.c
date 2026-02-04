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
    // Variant 1: Consecutive memory access with local accumulation buffer
    uint8_t temp_dst[8];
    for (y = 0; y < h; y++) {
        for (x = 0; x < 8; x++) {
            int val = filter[2] * src[x + 0 * srcstride]
                    - filter[1] * src[x - 1 * srcstride]
                    + filter[0] * src[x - 2 * srcstride]
                    + filter[3] * src[x + 1 * srcstride]
                    - filter[4] * src[x + 2 * srcstride]
                    + filter[5] * src[x + 3 * srcstride];
            temp_dst[x] = cm[(val + 64) >> 7];
        }
        // Write back consecutively
        for (x = 0; x < 8; x++) {
            dst[x] = temp_dst[x];
        }
        dst += dststride;
        src += srcstride;
    }
}
