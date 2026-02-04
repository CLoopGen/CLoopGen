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
    // Variant 1: Consecutive memory access by unrolling and writing 8 bytes at once
    for (y = 0; y < b_h; y++) {
        uint64_t temp = ((uint64_t)color4 << 32) | color4;
        *(uint64_t *)&dst[0 + y * stride] = temp;
    }
}
