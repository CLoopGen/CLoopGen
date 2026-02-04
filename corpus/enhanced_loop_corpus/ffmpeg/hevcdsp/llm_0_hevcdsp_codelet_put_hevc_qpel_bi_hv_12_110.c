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
        x = 0;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = 1;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = 2;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = 3;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        for (x = 4; x < width - 4; x++)
            tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = width - 4;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = width - 3;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = width - 2;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        x = width - 1;
        tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (12 - 8);
        src += srcstride;
        tmp += 64;
    }
}
