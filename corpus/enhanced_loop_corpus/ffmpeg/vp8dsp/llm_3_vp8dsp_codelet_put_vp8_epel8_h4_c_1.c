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
    uint8_t indices[8];
    for (x = 0; x < 8; x++)
        indices[x] = x + 1;
    for (x = 0; x < 8; x++) {
        int idx = indices[x];
        dst[x] = cm[(filter[2] * src[idx + 0] - filter[1] * src[idx - 2] + filter[3] * src[idx + 1] - filter[4] * src[idx + 3] + 64) >> 7];
    }
    dst += dststride;
    src += srcstride;
}
}
