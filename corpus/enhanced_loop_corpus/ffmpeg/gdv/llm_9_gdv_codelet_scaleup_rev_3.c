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
    int step = 4;
    for (x = (w - 1) & (~3); x >= 0; x -= step) { // Increase trip count by reducing step logic, but unroll effect via larger jumps
        dst[x]     = src[x >> 1];
        if (x >= 1) dst[x-1] = src[(x-1) >> 1];
        if (x >= 2) dst[x-2] = src[(x-2) >> 1];
        if (x >= 3) dst[x-3] = src[(x-3) >> 1];
    }
    // Clean up remaining elements with original logic
    for (; x < w && ((x + 1) & 7); x++) {
        dst[x] = src[(x >> 1)];
    }
}
