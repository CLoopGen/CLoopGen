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
    for (; x < 4; x++) {
        int base_x = x * 4;
        dst[base_x + 0] = cm[(filter[2] * tmp[base_x + 0 + 0 * 16] - filter[1] * tmp[base_x + 0 - 1 * 16] + filter[0] * tmp[base_x + 0 - 2 * 16] + filter[3] * tmp[base_x + 0 + 1 * 16] - filter[4] * tmp[base_x + 0 + 2 * 16] + filter[5] * tmp[base_x + 0 + 3 * 16] + 64) >> 7];
        dst[base_x + 1] = cm[(filter[2] * tmp[base_x + 1 + 0 * 16] - filter[1] * tmp[base_x + 1 - 1 * 16] + filter[0] * tmp[base_x + 1 - 2 * 16] + filter[3] * tmp[base_x + 1 + 1 * 16] - filter[4] * tmp[base_x + 1 + 2 * 16] + filter[5] * tmp[base_x + 1 + 3 * 16] + 64) >> 7];
        dst[base_x + 2] = cm[(filter[2] * tmp[base_x + 2 + 0 * 16] - filter[1] * tmp[base_x + 2 - 1 * 16] + filter[0] * tmp[base_x + 2 - 2 * 16] + filter[3] * tmp[base_x + 2 + 1 * 16] - filter[4] * tmp[base_x + 2 + 2 * 16] + filter[5] * tmp[base_x + 2 + 3 * 16] + 64) >> 7];
        dst[base_x + 3] = cm[(filter[2] * tmp[base_x + 3 + 0 * 16] - filter[1] * tmp[base_x + 3 - 1 * 16] + filter[0] * tmp[base_x + 3 - 2 * 16] + filter[3] * tmp[base_x + 3 + 1 * 16] - filter[4] * tmp[base_x + 3 + 2 * 16] + filter[5] * tmp[base_x + 3 + 3 * 16] + 64) >> 7];
    }
    dst += dststride;
    tmp += 16;
}
}
