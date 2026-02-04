#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern uint8_t *top;
extern uint8_t *left;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices and local accumulators
    uint8_t temp_top[8];
    uint8_t temp_left[8];
    
    // Precompute filtered top and left values to enable consecutive d writing
    for (x = 0; x < 8; x++) {
        int tx = x + 1;
        temp_top[x] = (top[tx - 1] + 2 * top[tx] + top[tx + 1] + 2) >> 2;
    }
    for (y = 0; y < 8; y++) {
        int ty = y + 1;
        temp_left[y] = (left[ty - 1] + 2 * left[ty] + left[ty + 1] + 2) >> 2;
    }
    
    // Write to d in row-major consecutive order
    uint8_t *d_ptr = d;
    for (y = 0; y < 8; y++) {
        uint8_t val_left = temp_left[y];
        for (x = 0; x < 8; x++) {
            *d_ptr++ = (temp_top[x] + val_left) >> 1;
        }
        d_ptr += stride - 8; // Skip to next row considering stride
    }
}
