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
        if (filter[2] >= filter[1]) {
            for (x = 0; x < 8; x++) {
                int val = (filter[2] * tmp[x + 0 * 8] - filter[1] * tmp[x - 1 * 8] + 
                           filter[3] * tmp[x + 1 * 8] - filter[4] * tmp[x + 2 * 8] + 64) >> 7;
                dst[x] = cm[val];
            }
        } else {
            for (x = 0; x < 8; x++) {
                dst[x] = cm[(tmp[x] + 32) >> 6];
            }
        }
        dst += dststride;
        tmp += 8;
    }
}
