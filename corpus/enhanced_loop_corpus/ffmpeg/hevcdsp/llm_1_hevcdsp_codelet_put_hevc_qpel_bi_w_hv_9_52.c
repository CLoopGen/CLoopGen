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
for (y = 0; y < height + 7; y++) {
    for (int offset = 0; offset < width; offset++) {
        for (x = offset; x < offset + 1 && x < width; x++)
            tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (9 - 8);
    }
    src += srcstride;
    tmp += 64;
}
}
