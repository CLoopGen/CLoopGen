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
    dst[0] = cm[(filter[2] * tmp[0] - filter[1] * tmp[-4] + filter[0] * tmp[-8] + filter[3] * tmp[4] - filter[4] * tmp[8] + filter[5] * tmp[12] + 64) >> 7];
    x = 1;
    dst[1] = cm[(filter[2] * tmp[1] - filter[1] * tmp[-3] + filter[0] * tmp[-7] + filter[3] * tmp[5] - filter[4] * tmp[9] + filter[5] * tmp[13] + 64) >> 7];
    x = 2;
    dst[2] = cm[(filter[2] * tmp[2] - filter[1] * tmp[-2] + filter[0] * tmp[-6] + filter[3] * tmp[6] - filter[4] * tmp[10] + filter[5] * tmp[14] + 64) >> 7];
    x = 3;
    dst[3] = cm[(filter[2] * tmp[3] - filter[1] * tmp[-1] + filter[0] * tmp[-5] + filter[3] * tmp[7] - filter[4] * tmp[11] + filter[5] * tmp[15] + 64) >> 7];
    dst += dststride;
    tmp += 4;
}
}
