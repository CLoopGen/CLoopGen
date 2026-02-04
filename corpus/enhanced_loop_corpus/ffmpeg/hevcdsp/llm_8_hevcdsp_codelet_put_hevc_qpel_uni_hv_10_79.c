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
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x += 2) {
        tmp[x] = (filter[0] * src[x - 2] + filter[1] * src[x - 1] + filter[2] * src[x] + filter[3] * src[x + 1] + filter[4] * src[x + 2]) >> 2;
        if (x + 1 < width) {
            tmp[x + 1] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2] + filter[4] * src[x + 3]) >> 2;
        }
    }
    src += srcstride;
    tmp += 64;
}
}
