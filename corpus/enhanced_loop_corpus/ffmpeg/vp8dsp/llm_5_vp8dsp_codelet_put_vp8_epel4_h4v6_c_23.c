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
        int base_val = filter[2] * tmp[x + 0 * 4] - filter[1] * tmp[x - 1 * 4] + filter[0] * tmp[x - 2 * 4] +
                       filter[3] * tmp[x + 1 * 4] - filter[4] * tmp[x + 2 * 4] + filter[5] * tmp[x + 3 * 4] + 64;
        int shifted_val = base_val >> 7;

        if (shifted_val >= 0 && shifted_val < 256) {
            dst[x] = cm[shifted_val];
        } else {
            dst[x] = cm[0];
        }
    }
    dst += dststride;
    tmp += 4;
}
}
