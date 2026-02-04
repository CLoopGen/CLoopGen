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
    for (x = 0; x < 4; x++) {
        int val = (filter[2] * tmp[x + 0] + filter[3] * tmp[x + 1] - filter[1] * tmp[x - 1] + 64) >> 7;
        dst[x] = cm[val];
    }
    dst += dststride;
    tmp += 4;
}
}
