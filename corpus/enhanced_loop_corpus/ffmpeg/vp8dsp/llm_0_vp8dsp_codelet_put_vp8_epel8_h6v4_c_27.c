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
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 1;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 2;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 3;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 4;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 5;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 6;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    x = 7;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0 + 0 * 8] - filter[1] * tmp[x + 0 - 1 * 8] + filter[3] * tmp[x + 0 + 1 * 8] - filter[4] * tmp[x + 0 + 2 * 8] + 64) >> 7];
    dst += dststride;
    tmp += 8;
}
}
