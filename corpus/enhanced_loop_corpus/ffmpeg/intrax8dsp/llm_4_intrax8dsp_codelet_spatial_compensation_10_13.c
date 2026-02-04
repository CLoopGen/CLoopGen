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
        if (x >= 2 && x <= 5) {
            dst[x] = (src[15 - y] * (8 - x) + src[25 + x] * x + 4) >> 3;
        } else {
            dst[x] = 0;
        }
    }
    dst += stride;
}
}
