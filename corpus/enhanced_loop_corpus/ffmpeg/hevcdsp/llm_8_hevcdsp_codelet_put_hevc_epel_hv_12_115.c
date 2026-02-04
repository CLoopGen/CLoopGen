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
for (y = 0; y < height + 6; y += 2) {
    for (x = 0; x < width; x += 2) {
        tmp[x]     = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1]) >> 4;
        if (x + 1 < width)
            tmp[x+1] = (filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 4;
    }
    src += 2 * srcstride;
    tmp += 128;
}
}
