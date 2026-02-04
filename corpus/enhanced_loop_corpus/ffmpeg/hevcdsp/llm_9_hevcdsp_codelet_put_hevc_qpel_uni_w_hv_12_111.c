#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 15; y += 2) {
    for (x = 0; x < width; x++) {
        int16_t sum1 = 0, sum2 = 0;
        sum1 += filter[0] * (src[x - 3]);
        sum1 += filter[1] * (src[x - 2]);
        sum1 += filter[2] * (src[x - 1]);
        sum1 += filter[3] * (src[x]);
        sum1 += filter[4] * (src[x + 1]);
        sum1 += filter[5] * (src[x + 2]);
        sum1 += filter[6] * (src[x + 3]);
        sum1 += filter[7] * (src[x + 4]);

        if (y + 1 < height + 15) {
            const uint16_t* next_src = (const uint16_t*)((const char*)src + srcstride);
            sum2 += filter[0] * (next_src[x - 3]);
            sum2 += filter[1] * (next_src[x - 2]);
            sum2 += filter[2] * (next_src[x - 1]);
            sum2 += filter[3] * (next_src[x]);
            sum2 += filter[4] * (next_src[x + 1]);
            sum2 += filter[5] * (next_src[x + 2]);
            sum2 += filter[6] * (next_src[x + 3]);
            sum2 += filter[7] * (next_src[x + 4]);
            tmp[64 + x] = sum2 >> 4;
        }

        tmp[x] = sum1 >> 4;
    }
    src += 2 * srcstride;
    tmp += 128;
}
}
