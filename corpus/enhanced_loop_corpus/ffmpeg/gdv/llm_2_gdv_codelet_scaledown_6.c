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
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Access pattern changed to load two consecutive elements at once (when possible)
    for (; x + 1 < w; x += 2) {
        dst[x] = src[2 * x];
        dst[x + 1] = src[2 * (x + 1)];
    }
    // Handle remaining element if any
    if (x < w) {
        dst[x] = src[2 * x];
        x++;
    }
}
