#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Offset Adjustment
    // Instead of accessing p[2*i] with stride 2, rewrite the loop to access consecutive elements
    // by changing indexing logic. We effectively map i -> 2*i and work on a logically strided array.
    float *base_p = p - 2*(i0 >> 1); // Adjust base pointer so that base_p[2*i] maps to p[2*i]
    int start = (i0 >> 1);
    int end = (i1 >> 1) + 1;
    for (i = start; i < end; i++) {
        int idx = 2 * i;
        base_p[idx] += 0.0529801175F * (base_p[idx - 1] + base_p[idx + 1]);
    }
}
