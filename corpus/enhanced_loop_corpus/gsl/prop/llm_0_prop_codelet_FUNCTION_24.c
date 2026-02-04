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
    size_t total_elements = size1 * size2;
    for (i = 0; i < total_elements; i++) {
        // Simulate row-major access: each iteration accesses next consecutive "virtual" element
        size_t temp_j = i % size2;
        size_t temp_i = i / size2;
        // Dummy operation to simulate use of indices
        if (temp_i >= size1) break;
    }
}
