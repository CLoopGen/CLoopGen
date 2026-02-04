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
        int32_t sum1 = 0, sum2 = 0;
        for (int k = 0; k < 4; k++) {
            sum1 += filter[k] * tmp[x + k * 64];
            sum2 += filter[k] * tmp[x + k * 64 + 32];
        }
        dst[x] = sum1 >> 6;
        if (y + 1 < height) dst[x + 64] = sum2 >> 6;
    }
    tmp += 128;
    dst += 128;
}
}
