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
ptrdiff_t offset;
for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width; x++) {
        offset = x;
        tmp[offset] = (filter[0] * src[offset - 1 + y * (srcstride/sizeof(uint8_t))] +
                       filter[1] * src[offset     + y * (srcstride/sizeof(uint8_t))] +
                       filter[2] * src[offset + 1 + y * (srcstride/sizeof(uint8_t))] +
                       filter[3] * src[offset + 2 + y * (srcstride/sizeof(uint8_t))]) >> 8;
    }
    tmp += 64;
}
}
