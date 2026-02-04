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
    for (int yy = y * 8, i = 0; i < 8; i++, yy++) {
        int offset = i;
        ((uint8_t*)dst)[yy % dststride] = cm[(filter[2] * tmp[offset + 0 * 8] - filter[1] * tmp[offset - 1 * 8] + filter[3] * tmp[offset + 1 * 8] - filter[4] * tmp[offset + 2 * 8] + 64) >> 7];
    }
    dst += dststride;
    tmp += 8;
}
}
