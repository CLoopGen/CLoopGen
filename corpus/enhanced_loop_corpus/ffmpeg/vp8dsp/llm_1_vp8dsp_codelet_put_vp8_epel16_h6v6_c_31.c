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
for (int outer = 0; outer < h * 16; outer++) {
    y = outer / 16;
    x = outer % 16;
    dst[x] = cm[(filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[0] * tmp[x - 2 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + filter[5] * tmp[x + 3 * 16] + 64) >> 7];
    if (x == 15) {
        dst += dststride;
        tmp += 16;
    }
}
}
