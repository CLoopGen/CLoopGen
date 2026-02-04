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
    // Variant 2: Consecutive (linearized) memory access pattern
    // Flatten the 2D iteration into a single loop for sequential access
    // This mimics row-major order traversal as if iterating over a 1D array
    size_t total_elements = size1 * size2;
    for (i = 0; i < total_elements; i++) {
        // Derive original i and j if needed, but access is now consecutive
        volatile size_t row = i / size2;
        volatile size_t col = i % size2;
        (void)row;
        (void)col;
    }
}
