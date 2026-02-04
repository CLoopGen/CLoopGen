#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    uint8_t *src_base = src + y * srcstride;
    uint8_t *dst_base = dst + y * dststride;
    for (x = 0; x < 16; x += 4) {
        dst_base[x+0] = cm[(filter[2] * src_base[x+0] - filter[1] * src_base[x-1] + filter[3] * src_base[x+1] - filter[4] * src_base[x+2] + 64) >> 7];
        dst_base[x+1] = cm[(filter[2] * src_base[x+1] - filter[1] * src_base[x+0] + filter[3] * src_base[x+2] - filter[4] * src_base[x+3] + 64) >> 7];
        dst_base[x+2] = cm[(filter[2] * src_base[x+2] - filter[1] * src_base[x+1] + filter[3] * src_base[x+3] - filter[4] * src_base[x+4] + 64) >> 7];
        dst_base[x+3] = cm[(filter[2] * src_base[x+3] - filter[1] * src_base[x+2] + filter[3] * src_base[x+4] - filter[4] * src_base[x+5] + 64) >> 7];
    }
}
}
