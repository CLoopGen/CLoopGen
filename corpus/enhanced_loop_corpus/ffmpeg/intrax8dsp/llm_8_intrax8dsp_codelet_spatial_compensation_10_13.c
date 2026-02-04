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
        uint16_t val1 = src[15 - y] * (8 - x);
        uint16_t val2 = src[25 + x] * x;
        uint16_t sum = val1 + val2 + 4;
        dst[x] = sum >> 3;
        if (x + 1 < 8) {
            uint16_t val3 = src[15 - y] * (7 - x);
            uint16_t val4 = src[25 + x + 1] * (x + 1);
            dst[x + 1] = (val3 + val4 + 4) >> 3;
        }
    }
    dst += stride;
}
}
