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
    for (x = 0; x < width; x += 2) {
        dst[x] = (filter[0] * tmp[x - 64] + filter[1] * tmp[x] + filter[2] * tmp[x + 64]) >> 6;
        if (x + 1 < width) {
            dst[x + 1] = (filter[1] * tmp[x + 1] + filter[2] * tmp[x + 1 + 64] + filter[3] * tmp[x + 1 + 2 * 64]) >> 6;
        }
    }
    tmp += 64;
    dst += 64;
}
}
