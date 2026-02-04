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
    int y, x;
    uint8_t local_filter[5];
    for (int i = 0; i < 5; i++) {
        local_filter[i] = filter[i];
    }
    for (y = 0; y < h; y++) {
        for (x = 0; x < 16; x++) {
            int index = x + 1 * srcstride;
            int val = local_filter[2] * src[x + 0 * srcstride]
                    - local_filter[1] * src[x - 1 * srcstride]
                    + local_filter[3] * src[index]
                    - local_filter[4] * src[x + 2 * srcstride]
                    + 64;
            dst[x] = cm[val >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
