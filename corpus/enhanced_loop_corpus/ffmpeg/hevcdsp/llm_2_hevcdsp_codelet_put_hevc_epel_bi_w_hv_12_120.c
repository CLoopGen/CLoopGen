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
            // Unroll and access consecutively for better spatial locality
            if (x + 0 < width) tmp[x + 0] = (filter[0] * src[x + 0 - 1] + filter[1] * src[x + 0] + filter[2] * src[x + 0 + 1] + filter[3] * src[x + 0 + 2]) >> 4;
            if (x + 1 < width) tmp[x + 1] = (filter[0] * src[x + 1 - 1] + filter[1] * src[x + 1] + filter[2] * src[x + 1 + 1] + filter[3] * src[x + 1 + 2]) >> 4;
            if (x + 2 < width) tmp[x + 2] = (filter[0] * src[x + 2 - 1] + filter[1] * src[x + 2] + filter[2] * src[x + 2 + 1] + filter[3] * src[x + 2 + 2]) >> 4;
            if (x + 3 < width) tmp[x + 3] = (filter[0] * src[x + 3 - 1] + filter[1] * src[x + 3] + filter[2] * src[x + 3 + 1] + filter[3] * src[x + 3 + 2]) >> 4;
        }
        src += srcstride;
        tmp += 64;
    }
}
