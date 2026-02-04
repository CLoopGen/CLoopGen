#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t stride_factor = srcstride / sizeof(uint8_t);
for (y = 0; y < h + 4 - 1; y++) {
    for (x = 0; x < 16; x += 4) {
        int32_t offsets[4] = {x, x+1, x+2, x+3};
        for (int i = 0; i < 4; ++i) {
            int off = offsets[i];
            int val = (filter[2] * src[off + 0 * 1]
                     - filter[1] * src[off - 1 * 1]
                     + filter[0] * src[off - 2 * 1]
                     + filter[3] * src[off + 1 * 1]
                     - filter[4] * src[off + 2 * 1]
                     + filter[5] * src[off + 3 * 1] + 64) >> 7;
            tmp[off] = cm[val];
        }
    }
    tmp += 16;
    src += stride_factor;
}
}
