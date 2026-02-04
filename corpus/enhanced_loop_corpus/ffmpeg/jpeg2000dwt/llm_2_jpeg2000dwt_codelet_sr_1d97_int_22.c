#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing p[2*i] with stride 2, rewrite the loop to traverse elements consecutively
    // by changing indexing logic. We map i to a new index j = 2*i, and adjust bounds accordingly.
    int start = (i0 >> 1) * 2;
    int end = ((i1 >> 1) + 1) * 2;
    for (i = start; i < end; i += 2)
        p[i] += (3472LL * (p[i - 1] + (int64_t)p[i + 1]) + (1 << 15)) >> 16;
}
