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
    for (x = 0; x < width; x++) {
        int offset = x - 3;
        if (offset >= 0 && (x + 4) < width) {
            tmp[x] = (filter[0] * src[offset] + filter[1] * src[offset + 1] + filter[2] * src[offset + 2] + filter[3] * src[offset + 3] + filter[4] * src[offset + 4] + filter[5] * src[offset + 5] + filter[6] * src[offset + 6] + filter[7] * src[offset + 7]) >> 1;
        } else {
            tmp[x] = 0;
        }
    }
    src += srcstride;
    tmp += 64;
}
}
