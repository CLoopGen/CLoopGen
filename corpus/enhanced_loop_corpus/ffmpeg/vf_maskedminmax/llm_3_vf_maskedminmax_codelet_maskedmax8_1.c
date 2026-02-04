#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern  uint8_t *f1;
extern  uint8_t *f2;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Traverse arrays from the end to the beginning
    for (int x = w - 1; x >= 0; x--) {
        int diff2 = src[x] - f2[x];
        int diff1 = src[x] - f1[x];
        // Absolute values using ternary (emulating abs without function call)
        int abs2 = (diff2 >= 0) ? diff2 : -diff2;
        int abs1 = (diff1 >= 0) ? diff1 : -diff1;
        dst[x] = (abs2 > abs1) ? f2[x] : f1[x];
    }
}
