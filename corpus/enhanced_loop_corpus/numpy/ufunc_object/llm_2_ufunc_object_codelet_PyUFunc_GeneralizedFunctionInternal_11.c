#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nin;
extern int i;
extern int nop;
extern int iter_ndim;
extern int op_core_num_dims[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive (forward) memory access with unrolling by 2
    // This variant accesses elements in a blocked, consecutive fashion to improve cache locality
    int sum = 0;
    for (i = nin; i < nop - 1; i += 2) {
        sum += op_core_num_dims[i] + op_core_num_dims[i + 1];
    }
    // Handle remaining element if count is odd
    if (i < nop) {
        sum += op_core_num_dims[i];
    }
    iter_ndim += sum;
}
