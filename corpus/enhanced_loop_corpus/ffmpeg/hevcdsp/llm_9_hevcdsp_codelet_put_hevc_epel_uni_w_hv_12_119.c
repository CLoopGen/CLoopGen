#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        int16_t val1 = filter[0] * (src[x - 1] + src[x + 2]) + filter[1] * (src[x] + src[x + 1]);
        int16_t val2 = filter[2] * (src[x] + src[x + 1]) + filter[3] * (src[x + 2] + src[x - 1]);
        tmp[x] = (val1 + val2) >> 5;
    }
    src += 2 * srcstride;
    tmp += 2 * 64;
}
}
