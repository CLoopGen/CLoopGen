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
    for (y = 0; y < h; y++) {
        for (x = 0; x < 16; x++) {
            int offset = x * 4; 
            if (x + 3 < 16) {
                int sum1 = filter[2] * src[offset + 0] - filter[1] * src[offset - 1] + filter[0] * src[offset - 2] +
                           filter[3] * src[offset + 1] - filter[4] * src[offset + 2] + filter[5] * src[offset + 3];
                int sum2 = filter[2] * src[offset + 4] - filter[1] * src[offset + 3] + filter[0] * src[offset + 2] +
                           filter[3] * src[offset + 5] - filter[4] * src[offset + 6] + filter[5] * src[offset + 7];
                dst[offset + 0] = cm[(sum1 + 64) >> 7];
                dst[offset + 4] = cm[(sum2 + 64) >> 7];
            }
        }
        dst += dststride;
        src += srcstride;
    }
}
