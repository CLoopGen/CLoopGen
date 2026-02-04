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
    // Instead of accessing p[2*i] and p[2*i+2] with stride 2, we reindex to access consecutive elements.
    // We precompute the base index and step through pairs consecutively.
    int32_t *base = &p[(i0 >> 1) * 2];
    int start = -1;
    int end = (i1 >> 1) - (i0 >> 1) + 1;
    for (i = start; i < end; i++) {
        int idx = i + 1; // shift to match original 2*i+1 targeting
        base[2*idx + 1] -= (57862LL * (base[2*idx] + (int64_t)base[2*idx + 2]) + (1 << 15)) >> 16;
    }
}
