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
    // Variant 1: Consecutive memory access by precomputing source indices and using a flat traversal
    uint8_t temp[8];
    for (int y = 0; y < 8; y++) {
        // Preload the two rows used in computation for this y
        for (int x = 0; x < 8; x++) {
            ptrdiff_t idx1 = (0) + 7 - y;
            ptrdiff_t idx2 = (8) + 7 - y;
            temp[x] = (src[idx1] + src[idx2] + 1) >> 1;
        }
        // Write consecutively to dst with stride
        for (int x = 0; x < 8; x++) {
            dst[x] = temp[x];
        }
        dst += stride;
    }
}
