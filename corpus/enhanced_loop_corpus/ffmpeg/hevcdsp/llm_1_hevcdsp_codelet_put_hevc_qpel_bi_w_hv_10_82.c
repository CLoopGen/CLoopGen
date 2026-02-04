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
    for (int inner = 0; inner < width / 4; inner++) {
        x = inner * 4;
        tmp[x]     = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 2;
        tmp[x + 1] = (filter[0] * src[x - 2] + filter[1] * src[x - 1] + filter[2] * src[x]     + filter[3] * src[x + 1] + filter[4] * src[x + 2] + filter[5] * src[x + 3] + filter[6] * src[x + 4] + filter[7] * src[x + 5]) >> 2;
        tmp[x + 2] = (filter[0] * src[x - 1] + filter[1] * src[x]     + filter[2] * src[x + 1] + filter[3] * src[x + 2] + filter[4] * src[x + 3] + filter[5] * src[x + 4] + filter[6] * src[x + 5] + filter[7] * src[x + 6]) >> 2;
        tmp[x + 3] = (filter[0] * src[x]     + filter[1] * src[x + 1] + filter[2] * src[x + 2] + filter[3] * src[x + 3] + filter[4] * src[x + 4] + filter[5] * src[x + 5] + filter[6] * src[x + 6] + filter[7] * src[x + 7]) >> 2;
    }
    // Handle remaining elements if width is not a multiple of 4
    for (x = (width / 4) * 4; x < width; x++) {
        tmp[x] = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
