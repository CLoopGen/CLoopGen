#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;
extern int j;
extern  int dim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (flattened) memory access pattern
    // Flatten the two-level loop into a single loop that accesses all elements consecutively
    // Ensures optimal spatial locality and coalesced memory access
    int idx;
    for (idx = 0; idx < size; idx++)
        out[idx] = 0.F;
}
