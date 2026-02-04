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
        int offset = (filter[0] > 32) ? 16 : 0;
        for (x = 0; x < 16; x++) {
            int index = x + offset;
            dst[x] = cm[(filter[2] * tmp[index + 0 * 16] - filter[1] * tmp[index - 1 * 16] + 
                         filter[3] * tmp[index + 1 * 16] - filter[4] * tmp[index + 2 * 16] + 64) >> 7];
        }
        dst += dststride;
        tmp += 16;
    }
}
