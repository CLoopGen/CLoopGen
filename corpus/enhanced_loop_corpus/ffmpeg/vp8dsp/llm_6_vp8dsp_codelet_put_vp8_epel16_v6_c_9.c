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
        uint8_t temp[16];
        for (x = 0; x < 16; x++) {
            int sum = 0;
            sum += filter[2] * src[x + 0 * srcstride];
            sum -= filter[1] * src[x - 1 * srcstride];
            sum += filter[0] * src[x - 2 * srcstride];
            sum += filter[3] * src[x + 1 * srcstride];
            sum -= filter[4] * src[x + 2 * srcstride];
            sum += filter[5] * src[x + 3 * srcstride];
            temp[x] = cm[(sum + 64) >> 7];
        }
        for (x = 0; x < 16; x++) {
            dst[x] = temp[x];
        }
        dst += dststride;
        src += srcstride;
    }
}
