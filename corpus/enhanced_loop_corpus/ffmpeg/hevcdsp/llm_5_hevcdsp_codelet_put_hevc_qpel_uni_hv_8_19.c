#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height + 7; y++) {
    for (x = 0; x < width; x++) {
        int offset = x;
        if (offset < 3 || offset >= width - 4) {
            tmp[x] = 0;
        } else {
            tmp[x] = (filter[0] * src[offset - 3] + filter[1] * src[offset - 2] + filter[2] * src[offset - 1] + filter[3] * src[offset] + filter[4] * src[offset + 1] + filter[5] * src[offset + 2] + filter[6] * src[offset + 3] + filter[7] * src[offset + 4]) >> (8 - 8);
        }
    }
    src += srcstride;
    tmp += 64;
}
}
