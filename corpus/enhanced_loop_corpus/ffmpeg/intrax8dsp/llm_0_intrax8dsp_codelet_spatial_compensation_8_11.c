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
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 1;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 2;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 3;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 4;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 5;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 6;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    x = 7;
    dst[x] = (src[(0) + 7 - y] + src[(8) + 7 - y] + 1) >> 1;
    dst += stride;
}
}
