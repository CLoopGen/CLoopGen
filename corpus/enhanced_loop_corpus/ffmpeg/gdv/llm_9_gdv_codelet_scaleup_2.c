#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int w;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y;
    for (y = x; y < w && y < x + 100; y++) {
        dst[y] = src[(y >> 2) + (y & 1)];
    }
    x = y;
}
