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
    for (x = 0; x < 16; x++) {
        int base1 = filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] + filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16];
        int base2 = filter[2] * tmp[x + 16 + 0 * 16] - filter[1] * tmp[x + 16 - 1 * 16] + filter[3] * tmp[x + 16 + 1 * 16] - filter[4] * tmp[x + 16 + 2 * 16];
        dst[x]                = cm[(base1 + 64) >> 7];
        if (y + 1 < h) 
            dst[dststride + x] = cm[(base2 + 64) >> 7];
    }
    dst += 2 * dststride;
    tmp += 32;
}
}
