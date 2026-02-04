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
    int y, x;
    uint8_t local_filter[6];
    for (int f = 0; f < 6; f++) {
        local_filter[f] = filter[f];
    }
    for (y = 0; y < h; y++) {
        int offset = y * 4;
        for (x = 0; x < 4; x++) {
            int val = (local_filter[2] * tmp[x + 0] - local_filter[1] * tmp[x - 1] +
                      local_filter[0] * tmp[x - 2] + local_filter[3] * tmp[x + 1] -
                      local_filter[4] * tmp[x + 2] + local_filter[5] * tmp[x + 3] + 64) >> 7;
            dst[x] = cm[val];
        }
        dst += dststride;
        tmp += 4;
    }
}
