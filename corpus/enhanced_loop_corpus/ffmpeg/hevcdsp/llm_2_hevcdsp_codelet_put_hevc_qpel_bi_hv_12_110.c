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
    int offset = y * srcstride;
    for (x = 0; x < width; x++) {
        int idx = x;
        tmp[idx] = (filter[0] * src[offset + x - 3] +
                    filter[1] * src[offset + x - 2] +
                    filter[2] * src[offset + x - 1] +
                    filter[3] * src[offset + x] +
                    filter[4] * src[offset + x + 1] +
                    filter[5] * src[offset + x + 2] +
                    filter[6] * src[offset + x + 3] +
                    filter[7] * src[offset + x + 4]) >> 4;
    }
    tmp += 64;
}
}
