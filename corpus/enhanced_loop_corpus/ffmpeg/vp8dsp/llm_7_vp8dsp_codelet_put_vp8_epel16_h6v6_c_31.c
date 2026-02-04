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
        for (x = 0; x < 16; x++) {
            int offset = x * 16;
            int val1 = (filter[0] * tmp[offset - 2 * 16] - filter[1] * tmp[offset - 1 * 16] + 
                        filter[2] * tmp[offset + 0 * 16]) >> 7;
            int val2 = (filter[3] * tmp[offset + 1 * 16] - filter[4] * tmp[offset + 2 * 16] + 
                        filter[5] * tmp[offset + 3 * 16] + 64) >> 7;
            int total = val1 + val2;
            dst[x] = cm[total & 0xFF];
        }
        dst += dststride;
        tmp++;
    }
}
