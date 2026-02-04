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
    // Variant 2: Strided memory access pattern with indirect indexing via pointer arithmetic
    size_t *indices = (size_t*)malloc(N * sizeof(size_t));
    for (j = 0; j < N; j++) {
        indices[j] = j * 2; // Simulate strided index generation (e.g., every 2nd element)
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t pos = indices[j]; // Indirect access using precomputed strided indices
        }
    }
    free(indices);
}
