#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 3; y += 2) {
    for (x = 0; x < width; x += 4) {
        tmp[x]     = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1]) >> 8;
        tmp[x + 1] = (filter[0] * src[x]     + filter[1] * src[x + 1] + filter[2] * src[x + 2]) >> 8;
        tmp[x + 2] = (filter[0] * src[x + 1] + filter[1] * src[x + 2] + filter[2] * src[x + 3]) >> 8;
        tmp[x + 3] = (filter[0] * src[x + 2] + filter[1] * src[x + 3] + filter[2] * src[x + 4]) >> 8;
    }
    src += 2 * srcstride;
    tmp += 2 * 64;
}
}
