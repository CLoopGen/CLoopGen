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
    x = 0;
    dst[y * 64 + x] = (filter[0] * tmp[y * 64 + x - 64] + filter[1] * tmp[y * 64 + x] + filter[2] * tmp[y * 64 + x + 64] + filter[3] * tmp[y * 64 + x + 2 * 64]) >> 6;
    x = 1;
    dst[y * 64 + x] = (filter[0] * tmp[y * 64 + x - 64] + filter[1] * tmp[y * 64 + x] + filter[2] * tmp[y * 64 + x + 64] + filter[3] * tmp[y * 64 + x + 2 * 64]) >> 6;
    x = 2;
    dst[y * 64 + x] = (filter[0] * tmp[y * 64 + x - 64] + filter[1] * tmp[y * 64 + x] + filter[2] * tmp[y * 64 + x + 64] + filter[3] * tmp[y * 64 + x + 2 * 64]) >> 6;
    x = 3;
    dst[y * 64 + x] = (filter[0] * tmp[y * 64 + x - 64] + filter[1] * tmp[y * 64 + x] + filter[2] * tmp[y * 64 + x + 64] + filter[3] * tmp[y * 64 + x + 2 * 64]) >> 6;
    tmp += 64;
    dst += 64;
}
}
