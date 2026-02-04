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
    dst[x + 0] = cm[(filter[2] * tmp[x + 0] - filter[1] * tmp[x - 4] + filter[0] * tmp[x - 8] + filter[3] * tmp[x + 4] - filter[4] * tmp[x + 8] + filter[5] * tmp[x + 12] + 64) >> 7];
    x = 1;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0] - filter[1] * tmp[x - 4] + filter[0] * tmp[x - 8] + filter[3] * tmp[x + 4] - filter[4] * tmp[x + 8] + filter[5] * tmp[x + 12] + 64) >> 7];
    x = 2;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0] - filter[1] * tmp[x - 4] + filter[0] * tmp[x - 8] + filter[3] * tmp[x + 4] - filter[4] * tmp[x + 8] + filter[5] * tmp[x + 12] + 64) >> 7];
    x = 3;
    dst[x + 0] = cm[(filter[2] * tmp[x + 0] - filter[1] * tmp[x - 4] + filter[0] * tmp[x - 8] + filter[3] * tmp[x + 4] - filter[4] * tmp[x + 8] + filter[5] * tmp[x + 12] + 64) >> 7];
    dst += dststride;
    tmp += 4;
}
}
