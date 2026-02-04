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
    for (x = 0; x < 8; x++) {
        int idx1 = (8) + 7 - y % 8;
        int idx2 = (8 + 8 + 1) + x;
        int val1 = src[idx1] * y % 8;
        int val2 = src[idx2] * (8 - (y % 8));
        dst[x] = (val1 + val2 + 4) >> 3;
    }
    dst += stride;
}
}
