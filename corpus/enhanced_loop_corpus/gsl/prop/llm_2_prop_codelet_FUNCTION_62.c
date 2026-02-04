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
    // Simulating a 2D array traversal as a 1D consecutive layout (row-major)
    size_t total_elements = size1 * size2;
    for (size_t idx = 0; idx < total_elements; idx++) {
        // Access is now consecutive: useful for cache locality
        // No actual array, but index computation reflects pattern
        i = idx / size2;  // Recover row
        j = idx % size2;  // Recover column
    }
}
