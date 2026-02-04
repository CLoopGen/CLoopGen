#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, reorganize accesses to be consecutive in memory where possible.
    // We assume stride is a power of two or small enough that we can precompute offsets.
    ptrdiff_t offset1 = -1;
    ptrdiff_t offset2 = -stride;
    ptrdiff_t offset3 = 4 - stride;
    ptrdiff_t offset4 = -1 + 4 * stride;

    for (i = 0; i < 4; i++) {
        dc0 += src[offset1 + i * stride] + src[i + offset2];
        dc1 += src[i + offset3];
        dc2 += src[i * stride + offset4];
    }
}
