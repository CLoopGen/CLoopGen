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
    // Variant 1: Consecutive memory access with precomputed indices and unrolled inner loop
    // Memory access pattern modified to improve spatial locality by reordering computation
    uint8_t *d_base = d;
    for (y = 0; y < 8; y++) {
        ptrdiff_t dy_stride = y * stride;
        for (x = 0; x < 8; x++) {
            int idx = dy_stride + x;
            if (x == y) {
                d[idx] = (left[1] + 2 * top[0] + top[1] + 2) >> 2;
            } else if (x > y) {
                int offset = x - y;
                d[idx] = ((top[offset - 1] + 2 * top[offset] + top[offset + 1] + 2) >> 2);
            } else {
                int offset = y - x;
                d[idx] = ((left[offset - 1] + 2 * left[offset] + left[offset + 1] + 2) >> 2);
            }
        }
    }
}
