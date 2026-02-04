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
    for (x = 0; x < 4; x++) {
        dst[x] = cm[(filter[2] * tmp[x + 0 * 4] - filter[1] * tmp[x - 1 * 4] + filter[0] * tmp[x - 2 * 4] + filter[3] * tmp[x + 1 * 4] - filter[4] * tmp[x + 2 * 4] + filter[5] * tmp[x + 3 * 4] + 64) >> 7];
        if (y + 1 < h) {
            uint8_t *dst_next = dst + dststride;
            int offset_next = 4;
            dst_next[x] = cm[(filter[2] * tmp[x + offset_next + 0 * 4] - filter[1] * tmp[x + offset_next - 1 * 4] + filter[0] * tmp[x + offset_next - 2 * 4] + filter[3] * tmp[x + offset_next + 1 * 4] - filter[4] * tmp[x + offset_next + 2 * 4] + filter[5] * tmp[x + offset_next + 3 * 4] + 64) >> 7];
        }
    }
    dst += 2 * dststride;
    tmp += 8;
}
}
