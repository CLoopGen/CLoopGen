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
        int use_alt_path = (y & 1) ^ (filter[0] > 64);
        for (x = 0; x < 4; x++) {
            if (use_alt_path) {
                dst[x] = cm[(tmp[x + 4] * filter[3] + 32) >> 6];
            } else {
                dst[x] = cm[(filter[2] * tmp[x + 0 * 4] - filter[1] * tmp[x - 1 * 4] + 
                             filter[0] * tmp[x - 2 * 4] + filter[3] * tmp[x + 1 * 4] - 
                             filter[4] * tmp[x + 2 * 4] + filter[5] * tmp[x + 3 * 4] + 64) >> 7];
            }
        }
        dst += dststride;
        tmp += 4;
    }
}
