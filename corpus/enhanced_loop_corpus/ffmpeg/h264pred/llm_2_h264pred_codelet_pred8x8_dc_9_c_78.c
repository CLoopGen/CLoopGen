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
    // Variant 1: Consecutive memory access by reordering and simplifying indexing
    // Instead of strided access, we try to access elements in a more sequential pattern where possible.
    // We assume stride is a power of two or small enough that some accesses can be grouped.
    ptrdiff_t s = stride;
    dc0 += src[-1] + src[-s];
    dc0 += src[-1 + s] + src[1 - s];
    dc0 += src[-1 + 2*s] + src[2 - s];
    dc0 += src[-1 + 3*s] + src[3 - s];

    dc1 += src[4 - s];
    dc1 += src[5 - s];
    dc1 += src[6 - s];
    dc1 += src[7 - s];

    dc2 += src[-1 + 4*s];
    dc2 += src[-1 + 5*s];
    dc2 += src[-1 + 6*s];
    dc2 += src[-1 + 7*s];
}
