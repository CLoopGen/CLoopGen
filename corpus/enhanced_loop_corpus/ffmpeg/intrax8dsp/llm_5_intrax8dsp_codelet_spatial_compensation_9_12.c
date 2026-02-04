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
    int base = 14 - y;
    for (x = 0; x < 8; x++) {
        int offset = (x + y >= 6) ? 6 : x + y;
        if (x < 4) {
            dst[x] = src[base - x];
        } else {
            dst[x] = src[8 + 6 - offset];
        }
    }
    dst += stride;
}
}
