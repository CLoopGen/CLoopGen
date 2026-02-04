#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint32_t *d = (uint32_t *)dst;
    ptrdiff_t stride32 = stride / sizeof(uint32_t);
    for (y = 0; y < b_h; y++) {
        d[0 * stride32] = color4;
        d[1 * stride32] = color4;
        d[2 * stride32] = color4;
        d[3 * stride32] = color4;
        d += stride32 * 4; // Move to next row in 32-bit units
    }
}
