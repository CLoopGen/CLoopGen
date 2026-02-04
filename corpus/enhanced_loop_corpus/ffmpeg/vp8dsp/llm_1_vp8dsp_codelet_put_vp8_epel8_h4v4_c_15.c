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
    for (int stride_offset = 0; stride_offset < 8; stride_offset++) {
        int index = stride_offset;
        dst[index] = cm[(filter[2] * tmp[index + 0 * 8] - filter[1] * tmp[index - 1 * 8] + filter[3] * tmp[index + 1 * 8] - filter[4] * tmp[index + 2 * 8] + 64) >> 7];
    }
    dst += dststride;
    tmp += 8;
}
}
