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
    for (int offset = 0; offset < 4; offset++) {
        int x = offset;
        dst[x] = cm[(filter[2] * tmp[x + 0 * 4] - filter[1] * tmp[x - 1 * 4] + filter[3] * tmp[x + 1 * 4] - filter[4] * tmp[x + 2 * 4] + 64) >> 7];
    }
    dst += dststride;
    tmp += 4;
}
}
