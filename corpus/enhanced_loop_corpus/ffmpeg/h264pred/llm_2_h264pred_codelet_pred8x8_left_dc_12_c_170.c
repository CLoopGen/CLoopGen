#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, reorganize to access consecutive elements
    // assuming stride = 1 for consecutive layout. We unroll and access directly.
    ptrdiff_t offset1 = -1 + 0 * stride;
    ptrdiff_t offset2 = -1 + 4 * stride;
    dc0 += src[offset1];
    dc0 += src[offset1 + stride];
    dc0 += src[offset1 + 2*stride];
    dc0 += src[offset1 + 3*stride];
    
    dc2 += src[offset2];
    dc2 += src[offset2 + stride];
    dc2 += src[offset2 + 2*stride];
    dc2 += src[offset2 + 3*stride];
}
