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
    for (x = 0; x < 4; x++) {
        if (2 * x - y < 0)
            dst[x] = src[(8) + 9 + 2 * x - y];
        else
            dst[x] = src[(8 + 8 + 1) + x - ((y + 1) >> 1)];

        int x2 = x + 4;
        if (2 * x2 - y < 0)
            dst[x2] = src[(8) + 9 + 2 * x2 - y];
        else
            dst[x2] = src[(8 + 8 + 1) + x2 - ((y + 1) >> 1)];
    }
    dst += stride;
}
}
