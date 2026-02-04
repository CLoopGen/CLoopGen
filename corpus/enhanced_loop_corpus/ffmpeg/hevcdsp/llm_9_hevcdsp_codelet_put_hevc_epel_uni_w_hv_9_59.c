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
for (y = 0; y < height; y++) {
    tmp[0] = (filter[1] * src[0] + filter[2] * src[1]) >> 1;
    for (x = 1; x < width - 1; x++) {
        int16_t sum = filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1];
        tmp[x] = sum >> 1;
    }
    if (width > 1) {
        tmp[width - 1] = (filter[1] * src[width - 1] + filter[2] * src[width]) >> 1;
    }
    src += srcstride;
    tmp += 64;
}
}
