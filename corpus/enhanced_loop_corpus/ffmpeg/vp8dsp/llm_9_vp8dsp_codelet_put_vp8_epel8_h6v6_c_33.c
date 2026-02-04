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
    for (x = 0; x < 8; x++) {
        int base_val = filter[2] * tmp[x] + filter[3] * tmp[x + 8] + 64;
        int offset1 = filter[0] * tmp[x - 16] - filter[1] * tmp[x - 8];
        int offset2 = filter[5] * tmp[x + 24] - filter[4] * tmp[x + 16];
        dst[x] = cm[(base_val + offset1 + offset2) >> 7];
        if (y + 1 < h) {
            dst[dststride + x] = cm[(base_val + offset1 + offset2 + 32) >> 7];
        }
    }
    dst += 2 * dststride;
    tmp += 16;
}
}
