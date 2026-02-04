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
for (y = 0; y < 16; y++) {
    for (x = 0; x < 4; x++) {
        uint8_t val1 = src[(8 + 8 + 1) + x*2];
        uint8_t val2 = src[(8 + 8 + 1 + 16) + x*2];
        uint8_t val3 = src[(8 + 8 + 1) + x*2 + 1];
        uint8_t val4 = src[(8 + 8 + 1 + 16) + x*2 + 1];
        dst[x*2]   = (val1 + val2 + 1) >> 1;
        dst[x*2+1] = (val3 + val4 + 1) >> 1;
    }
    dst += stride;
}
}
