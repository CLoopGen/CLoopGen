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
for (y = 0; y < h; y++) {
    for (x = 0; x < 8; x++) {
        if ((c + d) > 0)
            dst[x] = (c * tmp[x] + d * tmp[x + 8] + 4) >> 3;
        else
            dst[x] = tmp[x];
    }
    dst += dstride;
    tmp += 8;
}
}
