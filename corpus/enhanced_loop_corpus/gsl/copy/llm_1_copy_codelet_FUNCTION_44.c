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
    // Variant 2: Strided memory access pattern with indirect indexing via index array
    size_t *index_map = (size_t*)malloc(N * sizeof(size_t));
    if (!index_map) return;
    for (size_t k = 0; k < N; k++) {
        index_map[k] = (k * 7) % N; // Strided indirect indices (prime stride)
    }
    for (i = 0; i < M; i++) {
        for (j = 1; j < N - i; j++) {
            size_t pos = index_map[j]; // Indirect, strided access
            __asm__ volatile("" : "+g" (pos)); // Simulate use of pos
        }
    }
    free(index_map);
}
