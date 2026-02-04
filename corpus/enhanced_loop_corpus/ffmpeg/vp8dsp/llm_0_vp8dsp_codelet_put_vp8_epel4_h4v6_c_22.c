#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h + 6 - 1; y++) {
        tmp[y * 4 + 0] = cm[(filter[2] * src[0] - filter[1] * src[-1] + filter[3] * src[1] - filter[4] * src[2] + 64) >> 7];
        tmp[y * 4 + 1] = cm[(filter[2] * src[1] - filter[1] * src[0] + filter[3] * src[2] - filter[4] * src[3] + 64) >> 7];
        tmp[y * 4 + 2] = cm[(filter[2] * src[2] - filter[1] * src[1] + filter[3] * src[3] - filter[4] * src[4] + 64) >> 7];
        tmp[y * 4 + 3] = cm[(filter[2] * src[3] - filter[1] * src[2] + filter[3] * src[4] - filter[4] * src[5] + 64) >> 7];
        src += srcstride;
    }
}
