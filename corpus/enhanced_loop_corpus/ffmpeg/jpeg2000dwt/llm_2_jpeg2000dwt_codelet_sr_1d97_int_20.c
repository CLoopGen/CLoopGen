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
    // Instead of accessing p[2*i] with gaps, reindex to access consecutive elements.
    // We define a new index base to traverse a transformed view where stride-2 becomes stride-1.
    int32_t *base = p - 2; // Adjust base to allow safe access from offset
    int start = (i0 >> 1) - 1;
    int end = (i1 >> 1) + 2;
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        base[idx] -= (29066LL * (base[idx - 1] + (int64_t)base[idx + 1]) + (1 << 15)) >> 16;
    }
}
