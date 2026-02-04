#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern size_t *current_depth;
extern size_t number_threads;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via offset array)
    // Simulates irregular access pattern without additional heap allocation
    ssize_t n = (ssize_t)number_threads;
    size_t indices[n]; // Variable Length Array to hold indirect indices
    ssize_t i;

    // Initialize index map: reverse order access (indirect pattern)
    for (i = 0; i < n; i++) {
        indices[i] = (size_t)(n - 1 - i);
    }

    // Use indirect addressing to assign values
    for (i = 0; i < n; i++) {
        current_depth[indices[i]] = 1;
    }
}
