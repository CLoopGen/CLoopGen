#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Simulate indirect access using precomputed indices (common in sparse computations)
    // Assume we have an external array of indices, but since we can't modify globals,
    // we simulate on-stack index calculation for odd positions.
    int start = ((i0 + 1) >> 1);
    int end = (i1 + 1) >> 1;
    int len = end - start;
    if (len <= 0) return;
    
    // Simulated index map: maps iteration j to position 2*(j+start)+1
    for (i = 0; i < len; i++) {
        int idx = 2 * (i + start);
        p[idx + 1] -= (p[idx] + p[idx + 2]) >> 1;
    }
}
