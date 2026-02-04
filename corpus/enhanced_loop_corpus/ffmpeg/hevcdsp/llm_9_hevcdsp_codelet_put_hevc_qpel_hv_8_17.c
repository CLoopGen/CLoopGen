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
        for (int k = 0; k < 4; k++) {
            sum1 += filter[k] * src[x + k - 3];
            sum2 += filter[k + 4] * src[x + k + 1];
        }
        tmp[x] = (sum1 + sum2) >> 8;
    }
    src += 2 * srcstride;
    tmp += 2 * 64;
}
}
