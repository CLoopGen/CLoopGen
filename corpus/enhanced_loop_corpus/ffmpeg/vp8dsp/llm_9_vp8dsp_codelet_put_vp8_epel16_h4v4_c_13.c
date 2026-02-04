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
        int base_val = filter[2] * tmp[x + 0 * 16] - filter[1] * tmp[x - 1 * 16] +
                       filter[3] * tmp[x + 1 * 16] - filter[4] * tmp[x + 2 * 16] + 64;
        dst[x] = cm[base_val >> 7];

        if (y + 1 < h) {
            int next_offset = 16;
            int next_val = filter[2] * tmp[x + next_offset] - filter[1] * tmp[x - 16 + next_offset] +
                           filter[3] * tmp[x + 16 + next_offset] - filter[4] * tmp[x + 32 + next_offset] + 64;
            dst[dststride + x] = cm[next_val >> 7];
        }
    }
    dst += 2 * dststride;
    tmp += 32;
}
}
