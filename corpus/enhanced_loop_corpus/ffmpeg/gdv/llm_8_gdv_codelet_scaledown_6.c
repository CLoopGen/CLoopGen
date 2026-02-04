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
    for (y = x; y < w && y < w - 1; y += 2) {
        dst[y] = src[2 * y];
        dst[y + 1] = src[2 * (y + 1)];
    }
    if (y == w - 1) {
        dst[y] = src[2 * y];
    }
}
