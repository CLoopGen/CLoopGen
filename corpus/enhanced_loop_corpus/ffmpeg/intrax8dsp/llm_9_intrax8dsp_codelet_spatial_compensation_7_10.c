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
        int offset = x - 2 * y;
        if (offset >= 0) {
            uint8_t val1 = src[15 + offset];
            uint8_t val2 = src[16 + offset];
            dst[x] = (val1 + val2 + 1) >> 1;
            dst[x+1] = (val1 + val2 + 2) >> 1;
        } else {
            int base = src[16 - y + (x >> 1)];
            dst[x] = base;
            dst[x+1] = base ^ 0xFF;
        }
    }
    dst += stride;
}
}
