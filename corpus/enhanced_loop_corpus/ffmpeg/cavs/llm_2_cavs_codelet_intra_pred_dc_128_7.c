#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and accessing adjacent 64-bit locations
    uint64_t *base = (uint64_t *)d;
    for (y = 0; y < 8; y++) {
        base[y] = a;
    }
}
