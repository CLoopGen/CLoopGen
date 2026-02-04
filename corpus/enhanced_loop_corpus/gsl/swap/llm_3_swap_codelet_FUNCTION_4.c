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
    // Using an index map to simulate indirect addressing
    int *data = (int*)malloc(K * K * sizeof(int));
    int *indices = (int*)malloc(K * sizeof(int));
    
    // Initialize index map with shuffled but valid indices
    for (size_t idx = 0; idx < K; idx++) {
        indices[idx] = (idx * 7) % K;  // Arbitrary permutation
    }

    for (i = 0; i < K; i++) {
        for (j = 0; j < i; j++) {
            size_t mapped_index = indices[j];  // Indirect access through index array
            data[i * K + mapped_index] = i + j;
        }
    }

    free(data);
    free(indices);
}
