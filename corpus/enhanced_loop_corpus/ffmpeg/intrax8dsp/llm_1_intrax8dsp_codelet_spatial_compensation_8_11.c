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
for (y = 0; y < 64; y += 8) {
    for (x = 0; x < 8; x++)
        dst[x] = (src[(0) + 7 - (y / 8)] + src[(8) + 7 - (y / 8)] + 1) >> 1;
    dst += stride;
}
}
