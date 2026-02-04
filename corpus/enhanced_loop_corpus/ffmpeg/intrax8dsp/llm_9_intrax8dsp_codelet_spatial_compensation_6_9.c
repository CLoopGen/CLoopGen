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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 16; x += 2) {
        int offset = 16 + x - y * 2;
        dst[x] = src[offset];
        dst[x + 1] = src[offset + 1];
    }
    dst += stride;
}
}
