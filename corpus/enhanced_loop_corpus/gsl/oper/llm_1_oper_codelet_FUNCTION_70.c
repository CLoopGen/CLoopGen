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
    if (!indices) return;
    for (j = 0; j < N; j++) {
        indices[j] = j * 2; // Create strided indirect indices (e.g., 0, 2, 4, ...)
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t pos = indices[j]; // Indirect, strided access
            __asm__ volatile("" : "+r" (pos) : : "memory"); // Simulate memory access
        }
    }
    free(indices);
}
