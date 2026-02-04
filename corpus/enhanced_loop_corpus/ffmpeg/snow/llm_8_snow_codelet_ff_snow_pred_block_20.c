#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled inner loop and doubled trip count
    // Simulates higher arithmetic/work per iteration by expanding the number of writes and increasing loop bounds
    int y;
    int double_b_h = b_h << 1;  // Double the trip count using bit shift (more computations)
    for (y = 0; y < double_b_h; y++) {
        int offset = y * stride;
        // Unroll more stores to increase work per iteration
        *(uint32_t *)&dst[0  + offset] = color4;
        *(uint32_t *)&dst[4  + offset] = color4;
        *(uint32_t *)&dst[8  + offset] = color4;
        *(uint32_t *)&dst[12 + offset] = color4;
        *(uint32_t *)&dst[16 + offset] = color4;
        *(uint32_t *)&dst[20 + offset] = color4;
        *(uint32_t *)&dst[24 + offset] = color4;
        *(uint32_t *)&dst[28 + offset] = color4;
    }
}
