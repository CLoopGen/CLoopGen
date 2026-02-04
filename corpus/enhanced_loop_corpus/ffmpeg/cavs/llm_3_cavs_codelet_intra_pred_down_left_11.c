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
    // Variant 2: Strided memory access with transposed iteration order (column-major inner loop) to change access pattern
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            int offset = x + y + 2;
            int top_val = ((top[offset - 1] + 2 * top[offset] + top[offset + 1] + 2) >> 2);
            int left_val = ((left[offset - 1] + 2 * left[offset] + left[offset + 1] + 2) >> 2);
            d[y * stride + x] = (top_val + left_val) >> 1;
        }
    }
}
