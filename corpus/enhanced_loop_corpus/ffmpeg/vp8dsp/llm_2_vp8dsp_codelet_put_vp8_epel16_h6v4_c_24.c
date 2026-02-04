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
for (y = 0; y < h + 4 - 1; y++) {
    uint8_t local_filter[6];
    uint8_t local_src[7];
    int center = 2;
    for (int f = 0; f < 6; f++) {
        local_filter[f] = filter[f];
    }
    for (int s = -2; s <= 3; s++) {
        local_src[s + 2] = src[x + s * 1];
    }
    for (x = 0; x < 16; x++) {
        int offset = x;
        tmp[x] = cm[(local_filter[2] * local_src[offset + 0 + 2]
                   - local_filter[1] * local_src[offset - 1 + 2]
                   + local_filter[0] * local_src[offset - 2 + 2]
                   + local_filter[3] * local_src[offset + 1 + 2]
                   - local_filter[4] * local_src[offset + 2 + 2]
                   + local_filter[5] * local_src[offset + 3 + 2] + 64) >> 7];
    }
    tmp += 16;
    src += srcstride;
}
}
