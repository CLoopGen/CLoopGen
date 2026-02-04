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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < 4; x++) {
        int base1 = (filter[2] * tmp[x + 0] - filter[1] * tmp[x - 1] + filter[0] * tmp[x - 2] +
                    filter[3] * tmp[x + 1] - filter[4] * tmp[x + 2] + filter[5] * tmp[x + 3] + 64) >> 7;
        int base2 = (filter[2] * tmp[x + 4] - filter[1] * tmp[x + 3] + filter[0] * tmp[x + 2] +
                    filter[3] * tmp[x + 5] - filter[4] * tmp[x + 6] + filter[5] * tmp[x + 7] + 64) >> 7;
        dst[x] = cm[base1];
        dst[dststride + x] = cm[base2];
    }
    dst += 2 * dststride;
    tmp += 8;
}
}
