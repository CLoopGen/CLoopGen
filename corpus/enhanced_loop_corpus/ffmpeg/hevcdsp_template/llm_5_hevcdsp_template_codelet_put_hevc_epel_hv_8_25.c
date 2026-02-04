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
for (y = 0; y < height + 3; y++) {
    int valid_row = (y % 2 == 0) ? 1 : 0;
    for (x = 0; x < width; x++) {
        if (valid_row) {
            tmp[x] = (filter[0] * src[x - 1] + filter[1] * src[x] + filter[2] * src[x + 1] + filter[3] * src[x + 2]) >> 8;
        } else {
            tmp[x] = src[x] << 1;
        }
    }
    src += srcstride;
    tmp += 64;
}
}
