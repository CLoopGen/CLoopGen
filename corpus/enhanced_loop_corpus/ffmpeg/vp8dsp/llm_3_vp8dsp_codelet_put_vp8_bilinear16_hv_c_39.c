#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstride;
extern int h;
extern int c;
extern int d;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t offset = 0;
for (y = 0; y < h; y++) {
    for (x = 0; x < 16; x++) {
        ptrdiff_t idx = x;
        dst[idx] = (c * tmp[idx] + d * tmp[idx + 16] + 4) >> 3;
    }
    dst += dstride;
    tmp += 16;
}
}
