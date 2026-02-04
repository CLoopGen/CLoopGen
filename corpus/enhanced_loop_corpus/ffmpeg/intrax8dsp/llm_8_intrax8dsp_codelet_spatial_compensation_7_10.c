#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y += 2) {
    for (x = 0; x < 4; x++) {
        int idx = x - y;
        if (idx > 0)
            dst[x] = (src[15 + idx] + src[16 + idx] + src[16 + idx - 1] + 1) >> 2;
        else
            dst[x] = src[12 - (y >> 1) + x];
    }
    dst += stride;
}
}
