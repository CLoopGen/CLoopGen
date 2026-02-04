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
    size_t *index_array = (size_t*)malloc(M * sizeof(size_t));
    if (!index_array) return;
    for (i = 0; i < M; i++) {
        index_array[i] = i * N; // Precompute starting indices for strided access
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += 2) { // Stride of 2 in inner dimension
            size_t pos = index_array[i] + j; // Indirect and strided access
        }
    }
    free(index_array);
}
