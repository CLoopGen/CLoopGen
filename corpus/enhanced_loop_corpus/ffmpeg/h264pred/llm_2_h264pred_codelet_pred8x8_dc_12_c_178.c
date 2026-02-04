#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, reorganize to access consecutive elements where possible.
    // We assume stride is a power of two or small enough that we can unroll and adjust indices.
    // Here, we change the access pattern to read consecutive src elements in each iteration.

    ptrdiff_t base_idx1 = -1 + stride * 0;
    ptrdiff_t base_idx2 = -stride;
    ptrdiff_t base_idx3 = 4 - stride;
    ptrdiff_t base_idx4 = -1 + 4 * stride;

    for (i = 0; i < 4; i++) {
        dc0 += src[base_idx1 + i] + src[base_idx2 + i];
        dc1 += src[base_idx3 + i];
        dc2 += src[base_idx4 + i];
    }
}
