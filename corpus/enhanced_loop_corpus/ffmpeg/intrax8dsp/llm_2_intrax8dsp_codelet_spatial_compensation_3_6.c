#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base pointer
    uint8_t *base_src = src + (8 + 8 + 1) + ((1) >> 1); // Base offset for y=0
    for (y = 0; y < 8; y++) {
        uint8_t *src_row = base_src + ((y + 1) >> 1);
        for (x = 0; x < 8; x += 4) { // Unrolled access to promote consecutive loads
            dst[x]     = src_row[x];
            dst[x + 1] = src_row[x + 1];
            dst[x + 2] = src_row[x + 2];
            dst[x + 3] = src_row[x + 3];
        }
        dst += stride;
    }
}
