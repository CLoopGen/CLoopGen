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
    // Variant 1: Consecutive memory access pattern using a single loop with stride simulation
    size_t total_iterations = size1 * size2;
    for (i = 0; i < total_iterations; i++) {
        // Simulate row-major consecutive access: index directly maps to linearized iteration
        size_t temp = i; // Dummy use to maintain loop body
    }
}
