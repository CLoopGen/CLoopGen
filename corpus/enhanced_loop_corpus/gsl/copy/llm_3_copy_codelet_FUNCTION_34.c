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
    // Variant 2: Strided memory access pattern with indirect indexing via an index array
    size_t *index_map = (size_t*)malloc(M * N * sizeof(size_t));
    if (!index_map) return; // Handle allocation failure
    size_t idx = 0;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            // Populate and use an indirect index with a fixed stride pattern
            index_map[idx] = (i + j) * 2;  // Example strided indirect index
            volatile size_t dummy = index_map[idx]; // Simulate access
            idx++;
        }
    }
    free(index_map);
}
