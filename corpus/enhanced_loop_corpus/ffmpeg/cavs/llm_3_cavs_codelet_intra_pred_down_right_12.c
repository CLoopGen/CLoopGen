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
    // Variant 2: Strided memory access with transposed iteration order (column-major)
    // Outer loop over x (columns), inner loop over y (rows) to create strided access in d
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            ptrdiff_t d_index = y * stride + x;  // Strided access due to column-major traversal
            if (x == y) {
                d[d_index] = (left[1] + 2 * top[0] + top[1] + 2) >> 2;
            } else if (x > y) {
                int tidx = x - y;
                d[d_index] = ((top[tidx - 1] + 2 * top[tidx] + top[tidx + 1] + 2) >> 2);
            } else {
                int lidx = y - x;
                d[d_index] = ((left[lidx - 1] + 2 * left[lidx] + left[lidx + 1] + 2) >> 2);
            }
        }
    }
}
