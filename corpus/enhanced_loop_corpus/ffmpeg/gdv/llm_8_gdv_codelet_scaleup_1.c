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
    for (x = 0; x < w - 15; x += 16) {
        dst[x + 0] = dst[x + 1] = src[(x >> 2) + 0];
        dst[x + 2] = dst[x + 3] = src[(x >> 2) + 0];
        dst[x + 4] = dst[x + 5] = src[(x >> 2) + 1];
        dst[x + 6] = dst[x + 7] = src[(x >> 2) + 1];
        dst[x + 8] = dst[x + 9] = src[(x >> 2) + 2];
        dst[x + 10] = dst[x + 11] = src[(x >> 2) + 2];
        dst[x + 12] = dst[x + 13] = src[(x >> 2) + 3];
        dst[x + 14] = dst[x + 15] = src[(x >> 2) + 3];
    }
}
