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
    // Use consecutive memory access by flattening the 2D iteration into 1D
    // Traverse all elements in row-major order as if accessing a linear buffer
    size_t total_elements = size1 * size2;
    size_t idx;
    for (idx = 0; idx < total_elements; idx++) {
        i = idx / size2;  // Recover row index
        j = idx % size2;  // Recover column index
        // Simulate consecutive access pattern
        // e.g., process data[idx] or data[i][j]
    }
}
