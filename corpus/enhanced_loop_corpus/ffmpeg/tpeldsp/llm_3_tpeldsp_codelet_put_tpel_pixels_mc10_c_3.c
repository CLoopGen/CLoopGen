#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed processing order (column-major traversal)
    // Instead of row-by-row, we process column-by-column with fixed stride jumps, altering cache behavior.
    for (j = 0; j < width; j++) {
        for (i = 0; i < height; i++) {
            uint8_t *src_addr = src + i * stride + j;
            uint8_t *dst_addr = dst + i * stride + j;
            // Ensure we don't go out of bounds on the right edge (j+1)
            if (j + 1 < width) {
                *dst_addr = ((2 * (*src_addr) + *(src_addr + 1) + 1) * 683) >> 11;
            } else {
                // For last column, avoid reading beyond array boundary
                *dst_addr = ((2 * (*src_addr) + (*src_addr) + 1) * 683) >> 11; // Use current instead of next
            }
        }
    }
}
