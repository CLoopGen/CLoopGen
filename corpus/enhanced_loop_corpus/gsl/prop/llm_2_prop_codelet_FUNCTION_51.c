#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single loop with stride emulation
    size_t total_iterations = size1 * size2;
    for (i = 0; i < total_iterations; i++) {
        // Simulate row-major consecutive access: index = i, accessing hypothetical array linearly
        // This reflects a flattened traversal of a 2D grid
        volatile size_t idx = i; // Prevent optimization; ensures access is acknowledged
    }
}
