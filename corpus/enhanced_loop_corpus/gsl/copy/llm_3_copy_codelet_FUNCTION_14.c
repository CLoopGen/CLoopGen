#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {1, 3, 5, 7, 9, 2, 4, 6}; // Example index set
    size_t num_indices = sizeof(indices) / sizeof(indices[0]);
    for (i = 0; i < src_size1 && i < num_indices; i++) {
        // Indirect memory access via an index array
        // Simulates irregular or gather-style access pattern
        size_t idx = indices[i];
    }
}
