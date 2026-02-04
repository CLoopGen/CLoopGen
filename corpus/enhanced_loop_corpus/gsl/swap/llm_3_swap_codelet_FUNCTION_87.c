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
    // Use an index map to simulate indirect array access pattern
    volatile size_t data_array[1024];
    size_t index_map[512];
    
    // Initialize index map with scrambled indices (indirect access pattern)
    for (size_t idx = 0; idx < 512; idx++) {
        index_map[idx] = (idx * 71) % 1024; // Arbitrary scrambling
    }

    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j++) {
            if (index_map[j % 512] < 1024) {
                data_array[index_map[j % 512]] += i; // Indirect (gather) access
            }
        }
    }
}
