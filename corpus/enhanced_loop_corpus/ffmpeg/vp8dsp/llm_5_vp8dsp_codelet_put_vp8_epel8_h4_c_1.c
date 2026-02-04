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
    int use_fast_path = (filter[1] == 0 && filter[4] == 0);
    for (x = 0; x < 8; x++) {
        int val;
        if (use_fast_path)
            val = (filter[2] * src[x] + filter[3] * src[x + 1] + 64) >> 7;
        else
            val = (filter[2] * src[x] - filter[1] * src[x - 1] + filter[3] * src[x + 1] - filter[4] * src[x + 2] + 64) >> 7;
        dst[x] = cm[val];
    }
    dst += dststride;
    src += srcstride;
}
}
