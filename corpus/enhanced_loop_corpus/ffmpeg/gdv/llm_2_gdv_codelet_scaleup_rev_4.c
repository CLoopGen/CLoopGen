#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of reverse-order and strided writes, write in forward consecutive order.
    // Adjust loop to start from 0 and increment, processing 8 elements at a time.
    int temp_x = x - 7;
    for (x = temp_x; x < temp_x + ((-temp_x) & ~7); x += 8) {
        dst[x + 0] = dst[x + 1] = src[(x >> 1) + 0];
        dst[x + 2] = dst[x + 3] = src[(x >> 1) + 1];
        dst[x + 4] = dst[x + 5] = src[(x >> 1) + 2];
        dst[x + 6] = dst[x + 7] = src[(x >> 1) + 3];
    }
}
