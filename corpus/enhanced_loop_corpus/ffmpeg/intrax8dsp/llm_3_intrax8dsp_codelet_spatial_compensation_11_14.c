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
// Use consecutive, precomputed source indices with reversed traversal for better cache locality
ptrdiff_t base1 = 8 + 7;
ptrdiff_t base2 = 8 + 8 + 1;
for (y = 0; y < 8; y++) {
    ptrdiff_t idx1 = base1 - y; // Decreasing index in src
    ptrdiff_t idx2_base = base2 + y; // Increasing base for strided dimension
    for (x = 0; x < 8; x++) {
        ptrdiff_t idx2 = idx2_base + x * 8; // Consecutive vertical access (column-major like)
        dst[x] = ((src[idx1] * y + src[idx2] * (8 - y) + 4) >> 3);
    }
    dst += stride;
}
}
