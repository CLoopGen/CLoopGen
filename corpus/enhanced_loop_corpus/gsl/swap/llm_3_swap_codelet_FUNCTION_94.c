#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (gather-style access)
    // Simulates indirect addressing by using an auxiliary index array
    volatile size_t dummy_array[1024] = {0};
    size_t index_map[512];
    
    // Initialize index map with scrambled but valid indices
    for (size_t idx = 0; idx < 512; idx++) {
        index_map[idx] = (idx * 7 + 3) % 1024; // Arbitrary permutation
    }

    for (i = 0; i < K && i < 512; i++) {
        for (j = 0; j < i; j++) {
            size_t mapped_index = index_map[j]; // Indirect access via lookup
            dummy_array[mapped_index] += 1;
        }
    }
}
