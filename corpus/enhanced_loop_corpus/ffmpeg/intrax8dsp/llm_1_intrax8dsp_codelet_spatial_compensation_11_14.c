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
    for (int inner = 0; inner < 8; inner++) {
        x = inner;
        dst[x] = (src[(8) + 7 - y] * y + src[(8 + 8 + 1) + x] * (8 - y) + 4) >> 3;
    }
    dst += stride;
}
}
