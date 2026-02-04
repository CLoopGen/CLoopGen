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
    // Variant 2: Indirect (via index array) memory access pattern
    // Use an index map to access elements in a non-sequential, indirect way
    size_t *index_map = (size_t*)malloc(N * sizeof(size_t));
    if (!index_map) exit(1);
    // Initialize index map to reverse order for indirect access
    for (size_t k = 0; k < N; k++) {
        index_map[k] = N - 1 - k;
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t actual_j = index_map[j]; // Indirect access via mapping
            volatile size_t idx = i * N + actual_j;
            // Simulate memory access using computed index
            __asm__ volatile("" : : "r"(idx) : "memory");
        }
    }
    free(index_map);
}
