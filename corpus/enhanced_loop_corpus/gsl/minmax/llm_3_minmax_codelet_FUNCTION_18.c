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
    // Variant 2: Indirect (indexed) memory access using an index array
    // Simulate accessing data via an indirection array that defines access order
    // Create and use an index map to traverse in non-sequential order
    size_t *indices = (size_t*)malloc(M * N * sizeof(size_t));
    if (!indices) return;

    // Fill indices with sequential order (could be randomized or reordered in practice)
    for (size_t idx = 0; idx < M * N; idx++) {
        indices[idx] = idx;
    }

    // Access with indirect indexing, row-major order simulation
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t pos = indices[i * N + j]; // Indirect access
            // Simulated use of pos: data[pos] would be accessed here
        }
    }

    free(indices);
}
