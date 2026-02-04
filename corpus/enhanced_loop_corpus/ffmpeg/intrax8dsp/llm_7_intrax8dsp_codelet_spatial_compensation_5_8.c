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
uint8_t prev_val = 0;
for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
        uint8_t current;
        if (2 * x - y < 0)
            current = src[(8) + 9 + 2 * x - y] ^ prev_val;
        else
            current = src[(8 + 8 + 1) + x - ((y + 1) >> 1)] ^ prev_val;
        dst[x] = current;
        prev_val = current;
    }
    dst += stride;
}
}
