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
    // Flatten the two nested loops into a single loop that accesses elements consecutively,
    // ensuring optimal spatial locality and cache performance.
    int idx;
    for (idx = 0; idx < size; idx++)
        out[idx] = 0.F;
}
