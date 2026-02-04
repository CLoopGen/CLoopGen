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
    // Variant 2: Indirect (indexed) memory access using index array
    // Simulate indirect access via an index map (e.g., for gather operations)
    size_t *indices = (size_t*)malloc(M * N * sizeof(size_t));
    if (!indices) return;
    // Initialize index map to normal order (could be randomized or reordered in real use)
    for (size_t idx = 0; idx < M * N; idx++) {
        indices[idx] = idx;
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t pos = indices[i * N + j]; // Indirect access via index table
            // Simulated use of pos (e.g., data[pos])
        }
    }
    free(indices);
}
