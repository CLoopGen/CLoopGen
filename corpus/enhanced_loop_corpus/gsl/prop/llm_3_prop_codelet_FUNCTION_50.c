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
    // Simulate indirect access using an explicitly computed index mapping
    // This models scenarios like sparse or reordered data access
    size_t *indices_i = (size_t*)malloc(M * sizeof(size_t));
    size_t *indices_j = (size_t*)malloc(N * sizeof(size_t));

    // Initialize index arrays to normal sequential order (could be randomized in real use cases)
    for (size_t temp_i = 0; temp_i < M; temp_i++) {
        indices_i[temp_i] = temp_i;
    }
    for (size_t temp_j = 0; temp_j < N; temp_j++) {
        indices_j[temp_j] = temp_j;
    }

    for (size_t k = 0; k < M; k++) {
        i = indices_i[k];
        for (size_t l = 0; l < N; l++) {
            j = indices_j[l];
            // Simulate indirect access: data[i][j] accessed through indirection
            volatile size_t linear_idx = i * N + j;
            (void)linear_idx;
        }
    }

    free(indices_j);
    free(indices_i);
}
