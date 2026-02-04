#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {3, 1, 4, 0, 2}; // Example index permutation
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < src_size1; i++) {
        size_t idx = indices[i % num_indices]; // Indirect access via index array
        // Simulates irregular/indirect memory access pattern
    }
}
