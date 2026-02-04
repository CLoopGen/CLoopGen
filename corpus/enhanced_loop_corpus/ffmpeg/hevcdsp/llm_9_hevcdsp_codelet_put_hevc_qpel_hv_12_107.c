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
        sum1 += filter[0] * src[x - 3];
        sum1 += filter[1] * src[x - 2];
        sum1 += filter[2] * src[x - 1];
        sum1 += filter[3] * src[x];
        sum1 += filter[4] * src[x + 1];
        sum1 += filter[5] * src[x + 2];
        sum1 += filter[6] * src[x + 3];
        sum1 += filter[7] * src[x + 4];

        // Apply same filter on next row without boundary check (assumed safe)
        sum2 += filter[0] * src[x + srcstride - 3];
        sum2 += filter[1] * src[x + srcstride - 2];
        sum2 += filter[2] * src[x + srcstride - 1];
        sum2 += filter[3] * src[x + srcstride];
        sum2 += filter[4] * src[x + srcstride + 1];
        sum2 += filter[5] * src[x + srcstride + 2];
        sum2 += filter[6] * src[x + srcstride + 3];
        sum2 += filter[7] * src[x + srcstride + 4];

        tmp[x] = sum1 >> (12 - 8);
        tmp[64 + x] = sum2 >> (12 - 8); // Store second result in next row of tmp
    }
    src += 2 * srcstride;
    tmp += 2 * 64;
}
}
