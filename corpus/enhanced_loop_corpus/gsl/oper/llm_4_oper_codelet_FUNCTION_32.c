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
    // Variant 1: Consecutive memory access using linearized indexing
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    if (!dummy_array) return;
    for (i = 0; i < M * N; i++) {
        dummy_array[i] = i; // Sequential, cache-friendly access
    }
    free(dummy_array);
}
