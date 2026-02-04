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
    x = 0;
    tmp[x + 0] = cm[(filter[2] * src[0 + 0 * 1] - filter[1] * src[0 - 1 * 1] + filter[0] * src[0 - 2 * 1] + filter[3] * src[0 + 1 * 1] - filter[4] * src[0 + 2 * 1] + filter[5] * src[0 + 3 * 1] + 64) >> 7];
    x = 1;
    tmp[x + 0] = cm[(filter[2] * src[1 + 0 * 1] - filter[1] * src[1 - 1 * 1] + filter[0] * src[1 - 2 * 1] + filter[3] * src[1 + 1 * 1] - filter[4] * src[1 + 2 * 1] + filter[5] * src[1 + 3 * 1] + 64) >> 7];
    x = 2;
    tmp[x + 0] = cm[(filter[2] * src[2 + 0 * 1] - filter[1] * src[2 - 1 * 1] + filter[0] * src[2 - 2 * 1] + filter[3] * src[2 + 1 * 1] - filter[4] * src[2 + 2 * 1] + filter[5] * src[2 + 3 * 1] + 64) >> 7];
    x = 3;
    tmp[x + 0] = cm[(filter[2] * src[3 + 0 * 1] - filter[1] * src[3 - 1 * 1] + filter[0] * src[3 - 2 * 1] + filter[3] * src[3 + 1 * 1] - filter[4] * src[3 + 2 * 1] + filter[5] * src[3 + 3 * 1] + 64) >> 7];
    x = 4;
    tmp[x + 0] = cm[(filter[2] * src[4 + 0 * 1] - filter[1] * src[4 - 1 * 1] + filter[0] * src[4 - 2 * 1] + filter[3] * src[4 + 1 * 1] - filter[4] * src[4 + 2 * 1] + filter[5] * src[4 + 3 * 1] + 64) >> 7];
    x = 5;
    tmp[x + 0] = cm[(filter[2] * src[5 + 0 * 1] - filter[1] * src[5 - 1 * 1] + filter[0] * src[5 - 2 * 1] + filter[3] * src[5 + 1 * 1] - filter[4] * src[5 + 2 * 1] + filter[5] * src[5 + 3 * 1] + 64) >> 7];
    x = 6;
    tmp[x + 0] = cm[(filter[2] * src[6 + 0 * 1] - filter[1] * src[6 - 1 * 1] + filter[0] * src[6 - 2 * 1] + filter[3] * src[6 + 1 * 1] - filter[4] * src[6 + 2 * 1] + filter[5] * src[6 + 3 * 1] + 64) >> 7];
    x = 7;
    tmp[x + 0] = cm[(filter[2] * src[7 + 0 * 1] - filter[1] * src[7 - 1 * 1] + filter[0] * src[7 - 2 * 1] + filter[3] * src[7 + 1 * 1] - filter[4] * src[7 + 2 * 1] + filter[5] * src[7 + 3 * 1] + 64) >> 7];
    tmp += 8;
    src += srcstride;
}
}
