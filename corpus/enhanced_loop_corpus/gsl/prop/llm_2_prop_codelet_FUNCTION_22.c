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
    // Assume we are iterating over a 2D array in row-major order, flattened into 1D
    size_t total_elements = size1 * size2;
    for (i = 0; i < total_elements; i++) {
        // Simulate consecutive access: each iteration accesses next memory location
        // No actual array used, but access pattern is linear
        volatile size_t idx = i; // Use volatile to prevent optimization
        (void)idx;
    }
}
