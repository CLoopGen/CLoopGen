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
    // Variant 2: Strided memory access - transpose the iteration order (column-major)
    // This changes access pattern of 'd' to be column-strided instead of row-wise
    for (x = 0; x < 8; x++) {
        int tx = x + 1;
        uint8_t filtered_top = (top[tx - 1] + 2 * top[tx] + top[tx + 1] + 2) >> 2;
        for (y = 0; y < 8; y++) {
            int ty = y + 1;
            uint8_t filtered_left = (left[ty - 1] + 2 * left[ty] + left[ty + 1] + 2) >> 2;
            d[y * stride + x] = (filtered_top + filtered_left) >> 1;
        }
    }
}
