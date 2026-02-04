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
for (y = 0; y < 8; ++y) {
    int skip_row = (y == 2 || y == 5);
    if (!skip_row) {
        for (x = 0; x < 8; x++) {
            int weight = (x < 4) ? (8 - x) : (x - 4) + 1;
            dst[x] = (src[15 - y] * weight + src[25 + x] * (8 - weight) + 4) >> 3;
        }
        dst += stride;
    } else {
        dst += stride;
    }
}
}
