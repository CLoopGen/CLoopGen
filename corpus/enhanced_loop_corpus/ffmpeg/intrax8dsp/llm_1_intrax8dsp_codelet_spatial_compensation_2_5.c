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
for (y = 0; y < 64; y++) {
    x = y % 8;
    dst[x] = src[(8 + 8 + 1) + 1 + (y / 8) + x];
    if (x == 7) dst += stride;
}
}
