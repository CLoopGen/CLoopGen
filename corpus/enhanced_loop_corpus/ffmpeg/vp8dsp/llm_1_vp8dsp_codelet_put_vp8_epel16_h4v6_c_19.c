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
    for (int offset = 0; offset < 16; offset++) {
        int inner_offset = offset;
        for (int unroll = 0; unroll < 1; unroll++) {
            dst[inner_offset] = cm[(filter[2] * tmp[inner_offset + 0 * 16] - filter[1] * tmp[inner_offset - 1 * 16] + filter[0] * tmp[inner_offset - 2 * 16] + filter[3] * tmp[inner_offset + 1 * 16] - filter[4] * tmp[inner_offset + 2 * 16] + filter[5] * tmp[inner_offset + 3 * 16] + 64) >> 7];
        }
    }
    dst += dststride;
    tmp += 16;
}
}
