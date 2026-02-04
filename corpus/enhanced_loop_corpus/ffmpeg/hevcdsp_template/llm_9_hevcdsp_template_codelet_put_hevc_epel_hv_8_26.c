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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        int16_t val1 = (filter[0] * tmp[x - 64] + filter[1] * tmp[x] + filter[2] * tmp[x + 64] + filter[3] * tmp[x + 2 * 64]) >> 6;
        dst[x] = val1;
        if (y + 1 < height) {
            int16_t val2 = (filter[0] * tmp[x] + filter[1] * tmp[x + 64] + filter[2] * tmp[x + 2 * 64] + filter[3] * tmp[x + 3 * 64]) >> 6;
            ((int16_t*)dst)[64 + x] = val2;
        }
    }
    tmp += 128;
    dst += 128;
}
}
