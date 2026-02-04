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
    for (x = 0; x < w - 7; x += 8) {
        dst[x + 0] = src[(x >> 1) + 0];
        dst[x + 1] = dst[x + 0];
        dst[x + 2] = src[(x >> 1) + 1];
        dst[x + 3] = dst[x + 2];
        dst[x + 4] = src[(x >> 1) + 2];
        dst[x + 5] = dst[x + 4];
        dst[x + 6] = src[(x >> 1) + 3];
        dst[x + 7] = dst[x + 6];
    }
}
