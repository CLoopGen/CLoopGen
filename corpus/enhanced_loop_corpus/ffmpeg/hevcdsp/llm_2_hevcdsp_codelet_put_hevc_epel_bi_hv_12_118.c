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
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x += 4) {
        int offset = x;
        tmp[offset]     = (filter[0] * src[offset - 1] + filter[1] * src[offset] + filter[2] * src[offset + 1] + filter[3] * src[offset + 2]) >> 4;
        if (x + 1 < width)
            tmp[offset + 1] = (filter[0] * src[offset] + filter[1] * src[offset + 1] + filter[2] * src[offset + 2] + filter[3] * src[offset + 3]) >> 4;
        if (x + 2 < width)
            tmp[offset + 2] = (filter[0] * src[offset + 1] + filter[1] * src[offset + 2] + filter[2] * src[offset + 3] + filter[3] * src[offset + 4]) >> 4;
        if (x + 3 < width)
            tmp[offset + 3] = (filter[0] * src[offset + 2] + filter[1] * src[offset + 3] + filter[2] * src[offset + 4] + filter[3] * src[offset + 5]) >> 4;
    }
    src += srcstride;
    tmp += 64;
}
}
