#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    x = 0;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 1;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 2;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 3;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 4;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 5;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 6;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 7;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 8;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 9;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 10;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 11;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 12;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 13;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 14;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    x = 15;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    dst += dststride;
    tmp += 16;
}
}
