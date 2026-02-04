#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an index lookup table to access elements in non-sequential order
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    size_t *indices = (size_t*)malloc(N * sizeof(size_t));
    
    // Initialize index map: reverse order for indirect access
    for (size_t idx = 0; idx < N; idx++) {
        indices[idx] = N - 1 - idx;
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t pos = i * N + indices[j]; // Indirect access using index map
            dummy_array[pos] = i * N + j;
        }
    }

    free(indices);
    free(dummy_array);
}
