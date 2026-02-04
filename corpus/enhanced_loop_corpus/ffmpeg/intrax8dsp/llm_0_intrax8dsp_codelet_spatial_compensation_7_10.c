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
    x = 0;
    if (x - 2 * y > 0)
        dst[x] = (src[(8 + 8) - 1 + x - 2 * y] + src[(8 + 8) + x - 2 * y] + 1) >> 1;
    else
        dst[x] = src[(8) + 8 - y + (x >> 1)];
    dst += stride;
}
}
