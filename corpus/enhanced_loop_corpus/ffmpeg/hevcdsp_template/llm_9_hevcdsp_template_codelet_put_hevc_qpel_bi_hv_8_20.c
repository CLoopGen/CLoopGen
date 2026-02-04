#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 15; y += 2) {
    for (x = 0; x < width; x++) {
        int16_t sum1 = 0, sum2 = 0;
        sum1 += filter[0] * src[x - 3];
        sum1 += filter[1] * src[x - 2];
        sum1 += filter[2] * src[x - 1];
        sum1 += filter[3] * src[x];
        sum1 += filter[4] * src[x + 1];
        sum1 += filter[5] * src[x + 2];
        sum1 += filter[6] * src[x + 3];
        sum1 += filter[7] * src[x + 4];
        tmp[x] = sum1 >> 8;

        if (y + 1 < height + 15) {
            sum2 += filter[0] * src[srcstride + x - 3];
            sum2 += filter[1] * src[srcstride + x - 2];
            sum2 += filter[2] * src[srcstride + x - 1];
            sum2 += filter[3] * src[srcstride + x];
            sum2 += filter[4] * src[srcstride + x + 1];
            sum2 += filter[5] * src[srcstride + x + 2];
            sum2 += filter[6] * src[srcstride + x + 3];
            sum2 += filter[7] * src[srcstride + x + 4];
            tmp[64 + x] = sum2 >> 8;
        }
    }
    src += 2 * srcstride;
    tmp += 128;
}
}
