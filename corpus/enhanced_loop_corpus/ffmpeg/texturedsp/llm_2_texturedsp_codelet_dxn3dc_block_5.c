#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer and accessing elements in row-major order
    uint8_t *base = dst;
    for (int idx = 0; idx < 16; idx++) {
        int y = idx >> 2;  // Same as idx / 4
        int x = idx & 3;   // Same as idx % 4
        uint8_t *p = base + x * 4 + y * stride;
        uint8_t temp = p[1];
        p[1] = p[0];
        p[0] = temp;
    }
}
