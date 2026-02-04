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
    // Variant 1: Consecutive memory access pattern using a single linear index
    // Assuming a 2D data layout is flattened into 1D array with row-major order
    size_t total_size = size1 * size2;
    for (size_t idx = 0; idx < total_size; idx++) {
        // Simulate work on data[idx] - consecutive access
        volatile size_t dummy = idx; // Prevent optimization; represents memory access
    }
}
