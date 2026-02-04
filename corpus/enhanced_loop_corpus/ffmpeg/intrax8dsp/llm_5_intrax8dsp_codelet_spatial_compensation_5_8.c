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
    int shift = (y + 1) >> 1;
    for (x = 0; x < 8; x++) {
        int cond = 2 * x - y;
        dst[x] = cond < 0 ? src[17 + 2 * x - y] : src[17 + x - shift];
    }
    dst += stride;
}
}
