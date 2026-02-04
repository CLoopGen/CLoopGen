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
        int index;
        if (2 * x - y < 0) {
            index = (8) + 9 + 2 * x - y;
        } else {
            index = (8 + 8 + 1) + x - ((y + 1) >> 1);
        }
        dst[x] = src[index];
    }
    dst += stride;
}
}
