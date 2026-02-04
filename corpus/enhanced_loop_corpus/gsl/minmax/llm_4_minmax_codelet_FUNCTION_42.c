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
    // Variant 2: Strided memory access pattern with indirect indexing via precomputed index array
    size_t *indices = (size_t*)malloc(M * sizeof(size_t));
    for (i = 0; i < M; i++) {
        indices[i] = i * N; // Precompute starting indices for each row (strided access)
    }
    for (i = 0; i < M; i++) {
        size_t base_idx = indices[i];
        for (j = 0; j < N; j += 2) { // Stride of 2 for indirect, strided access
            // Simulate access using base + offset
            size_t current = base_idx + j;
        }
    }
    free(indices);
}
