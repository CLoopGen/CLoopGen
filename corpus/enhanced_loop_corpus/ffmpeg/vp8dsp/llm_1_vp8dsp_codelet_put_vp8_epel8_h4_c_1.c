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
    for (int offset = 0; offset < 8; offset++) {
        int effective_x = offset;
        dst[effective_x] = cm[(filter[2] * src[effective_x + 0] - filter[1] * src[effective_x - 1] + filter[3] * src[effective_x + 1] - filter[4] * src[effective_x + 2] + 64) >> 7];
    }
    dst += dststride;
    src += srcstride;
}
}
