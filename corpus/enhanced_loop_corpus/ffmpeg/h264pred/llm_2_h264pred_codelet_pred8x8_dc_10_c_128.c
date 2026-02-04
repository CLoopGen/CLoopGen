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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, reorganize to access consecutive elements when possible.
    // We assume stride is a power of two or small enough that we can precompute offsets.
    ptrdiff_t offset0 = -1;
    ptrdiff_t offset1 = -stride;
    ptrdiff_t offset2 = 4 - stride;
    ptrdiff_t offset3 = -1 + 4 * stride;

    for (i = 0; i < 4; i++) {
        dc0 += src[offset0 + i * stride] + src[i + offset1];
        dc1 += src[offset2 + i];
        dc2 += src[offset3 + i * stride];
    }
}
