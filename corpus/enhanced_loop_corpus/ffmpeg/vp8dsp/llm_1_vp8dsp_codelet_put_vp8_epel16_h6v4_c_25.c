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
    for (int block = 0; block < 16; block += 4) {
        dst[block + 0] = cm[(filter[2] * tmp[block + 0 + 0 * 16] - filter[1] * tmp[block + 0 - 1 * 16] + filter[3] * tmp[block + 0 + 1 * 16] - filter[4] * tmp[block + 0 + 2 * 16] + 64) >> 7];
        dst[block + 1] = cm[(filter[2] * tmp[block + 1 + 0 * 16] - filter[1] * tmp[block + 1 - 1 * 16] + filter[3] * tmp[block + 1 + 1 * 16] - filter[4] * tmp[block + 1 + 2 * 16] + 64) >> 7];
        dst[block + 2] = cm[(filter[2] * tmp[block + 2 + 0 * 16] - filter[1] * tmp[block + 2 - 1 * 16] + filter[3] * tmp[block + 2 + 1 * 16] - filter[4] * tmp[block + 2 + 2 * 16] + 64) >> 7];
        dst[block + 3] = cm[(filter[2] * tmp[block + 3 + 0 * 16] - filter[1] * tmp[block + 3 - 1 * 16] + filter[3] * tmp[block + 3 + 1 * 16] - filter[4] * tmp[block + 3 + 2 * 16] + 64) >> 7];
    }
    dst += dststride;
    tmp += 16;
}
}
