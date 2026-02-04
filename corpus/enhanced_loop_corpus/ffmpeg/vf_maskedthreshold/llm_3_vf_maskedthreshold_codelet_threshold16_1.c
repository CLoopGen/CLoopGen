#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int threshold;
extern int w;
extern  uint16_t *src;
extern  uint16_t *ref;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order memory access
    // Iterates from the end of the arrays to the beginning
    for (int x = w - 1; x >= 0; x--) {
        int diff = src[x] - ref[x];
        int abs_diff = diff >= 0 ? diff : -diff;
        dst[x] = abs_diff <= threshold ? src[x] : ref[x];
    }
}
