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
        uint8_t val1 = src[(0) + 7 - (y % 8)];
        uint8_t val2 = src[(8) + 7 - (y % 8)];
        uint8_t val3 = src[(0) + 7 - ((y + 1) % 8)];
        uint8_t val4 = src[(8) + 7 - ((y + 1) % 8)];
        dst[x] = ((val1 + val2 + val3 + val4 + 2) >> 2);
    }
    dst += stride;
}
}
