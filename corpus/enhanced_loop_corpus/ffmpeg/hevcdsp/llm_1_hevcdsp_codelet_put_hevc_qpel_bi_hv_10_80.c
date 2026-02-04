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
        tmp[0] = (filter[0] * src[-3] + filter[1] * src[-2] + filter[2] * src[-1] + filter[3] * src[0] + filter[4] * src[1] + filter[5] * src[2] + filter[6] * src[3] + filter[7] * src[4]) >> 2;
        x = 1;
        if (width > 1) tmp[1] = (filter[0] * src[-2] + filter[1] * src[-1] + filter[2] * src[0] + filter[3] * src[1] + filter[4] * src[2] + filter[5] * src[3] + filter[6] * src[4] + filter[7] * src[5]) >> 2;
        x = 2;
        if (width > 2) tmp[2] = (filter[0] * src[-1] + filter[1] * src[0] + filter[2] * src[1] + filter[3] * src[2] + filter[4] * src[3] + filter[5] * src[4] + filter[6] * src[5] + filter[7] * src[6]) >> 2;
        x = 3;
        if (width > 3) tmp[3] = (filter[0] * src[0] + filter[1] * src[1] + filter[2] * src[2] + filter[3] * src[3] + filter[4] * src[4] + filter[5] * src[5] + filter[6] * src[6] + filter[7] * src[7]) >> 2;
        for (x = 4; x < width; x++)
            tmp[x] = (filter[0] * src[x - 3] + filter[1] * src[x - 2] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2] + filter[6] * src[x + 3] + filter[7] * src[x + 4]) >> 2;
        src += srcstride;
        tmp += 64;
    }
}
