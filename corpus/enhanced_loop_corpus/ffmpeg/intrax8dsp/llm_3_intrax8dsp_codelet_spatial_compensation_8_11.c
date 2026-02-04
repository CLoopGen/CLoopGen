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
    // Variant 2: Strided memory access on source with reversed traversal order
    for (int y = 7; y >= 0; y--) {
        ptrdiff_t src_offset1 = (0) + y;   // Reverse indexing: now goes from src[7] down to src[0]
        ptrdiff_t src_offset2 = (8) + y;   // Same for second block
        uint8_t avg_val = (src[src_offset1] + src[src_offset2] + 1) >> 1;
        // Unroll the inner loop: replicate same value across all x positions
        for (int x = 0; x < 8; x++) {
            dst[x] = avg_val;
        }
        dst += stride;
    }
}
