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
    uint8_t local_dst[4];
    for (y = 0; y < h; y++) {
        for (x = 0; x < 4; x++) {
            int val = (filter[2] * tmp[x + 0 * 4] - 
                       filter[1] * tmp[x - 1 * 4] + 
                       filter[0] * tmp[x - 2 * 4] + 
                       filter[3] * tmp[x + 1 * 4] - 
                       filter[4] * tmp[x + 2 * 4] + 
                       filter[5] * tmp[x + 3 * 4] + 64) >> 7;
            local_dst[x] = cm[val];
        }
        for (x = 0; x < 4; x++) {
            dst[x] = local_dst[x];
        }
        dst += dststride;
        tmp += 4;
    }
}
