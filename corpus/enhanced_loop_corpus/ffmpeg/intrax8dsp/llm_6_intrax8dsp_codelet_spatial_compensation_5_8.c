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
    uint8_t temp[8];
    for (x = 0; x < 8; x++) {
        if (2 * x - y < 0)
            temp[x] = src[(8) + 9 + 2 * x - y];
        else
            temp[x] = src[(8 + 8 + 1) + x - ((y + 1) >> 1)];
    }
    for (x = 0; x < 8; x++) {
        dst[x] = temp[x];
    }
    dst += stride;
}
}
