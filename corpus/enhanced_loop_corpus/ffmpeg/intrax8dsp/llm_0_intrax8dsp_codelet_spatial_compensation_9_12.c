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
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 1;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 2;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 3;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 4;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 5;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 6;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    x = 7;
    dst[x] = src[14 - ((x + y) > 6 ? 6 : (x + y))];
    dst += stride;
}
}
