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
        int16_t sum1 = filter[0] * src[x - 4] + filter[1] * src[x - 3] + filter[2] * src[x - 2] + filter[3] * src[x - 1] +
                       filter[4] * src[x]     + filter[5] * src[x + 1] + filter[6] * src[x + 2] + filter[7] * src[x + 3];
        int16_t sum2 = filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] +
                       filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4];
        tmp[x] = sum1 >> 1;
        tmp[x + 64] = sum2 >> 1;
    }
    src += 2 * srcstride;
    tmp += 128;
}
}
