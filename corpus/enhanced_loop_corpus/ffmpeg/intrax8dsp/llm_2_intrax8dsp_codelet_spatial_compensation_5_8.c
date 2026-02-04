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
    // Variant 1: Consecutive memory access with precomputed indices and linearized addressing
    for (y = 0; y < 8; y++) {
        uint8_t temp[8];
        for (x = 0; x < 8; x++) {
            int index;
            if (2 * x - y < 0)
                index = (8) + 9 + 2 * x - y;
            else
                index = (8 + 8 + 1) + x - ((y + 1) >> 1);
            temp[x] = src[index];
        }
        // Write consecutively to dst
        for (x = 0; x < 8; x++) {
            dst[x] = temp[x];
        }
        dst += stride;
    }
}
