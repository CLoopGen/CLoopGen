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
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        if ((src[7 - y] | src[15 - y]) != 0) {
            dst[x] = (src[7 - y] + src[15 - y] + 1) >> 1;
        } else {
            dst[x] = 0;
        }
    }
    dst += stride;
}
}
