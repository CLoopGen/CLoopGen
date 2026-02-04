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
    for (x = 0; x < 8; x += 2) {
        dst[x]     = src[17 + ((y + 1) >> 1) + x];
        dst[x + 1] = src[17 + ((y + 2) >> 1) + x + 1];
    }
    dst += stride;
}
}
