#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    if (y % 2 == 0) {
        for (x = 0; x < width; x++)
            dst[x] = (filter[0] * tmp[x - 3 * 64] + filter[1] * tmp[x - 2 * 64] + filter[2] * tmp[x - 64] + filter[3] * tmp[x] + filter[4] * tmp[x + 64] + filter[5] * tmp[x + 2 * 64] + filter[6] * tmp[x + 3 * 64] + filter[7] * tmp[x + 4 * 64]) >> 6;
    } else {
        for (x = 0; x < width; x++)
            dst[x] = (filter[7] * tmp[x - 3 * 64] + filter[6] * tmp[x - 2 * 64] + filter[5] * tmp[x - 64] + filter[4] * tmp[x] + filter[3] * tmp[x + 64] + filter[2] * tmp[x + 2 * 64] + filter[1] * tmp[x + 3 * 64] + filter[0] * tmp[x + 4 * 64]) >> 6;
    }
    tmp += 64;
    dst += 64;
}
}
