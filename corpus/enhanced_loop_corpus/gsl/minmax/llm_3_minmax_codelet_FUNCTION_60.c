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
    // Variant 2: Strided memory access pattern with indirect indexing
    size_t *index_i = (size_t*)malloc(M * sizeof(size_t));
    size_t *index_j = (size_t*)malloc(N * sizeof(size_t));
    
    for (i = 0; i < M; i++) {
        index_i[i] = i * N;  // Precompute row start indices (strided access base)
    }
    
    for (j = 0; j < N; j++) {
        index_j[j] = j;      // Column offsets
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += 2) {  // Stride of 2 in inner loop
            size_t addr = index_i[i] + index_j[j];  // Simulate indirect strided access
        }
    }

    free(index_i);
    free(index_j);
}
