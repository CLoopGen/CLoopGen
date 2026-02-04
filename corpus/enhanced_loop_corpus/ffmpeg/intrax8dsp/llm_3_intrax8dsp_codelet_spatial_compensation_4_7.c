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
    for (x = 0; x < 8; x += 4) {
        dst[x + 0] = (src[(8 + 8 + 1) + x + 0] + src[(8 + 8 + 1 + 16) + x + 0] + 1) >> 1;
        dst[x + 1] = (src[(8 + 8 + 1) + x + 1] + src[(8 + 8 + 1 + 16) + x + 1] + 1) >> 1;
        dst[x + 2] = (src[(8 + 8 + 1) + x + 2] + src[(8 + 8 + 1 + 16) + x + 2] + 1) >> 1;
        dst[x + 3] = (src[(8 + 8 + 1) + x + 3] + src[(8 + 8 + 1 + 16) + x + 3] + 1) >> 1;
    }
    dst += stride;
}
}
