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
for (i = 1; i < M; i++) {
    size_t limit = ((i) < (N) ? (i) : (N));
    // Modify access pattern to be indirect via an index mapping table
    size_t *indices = (size_t*)malloc(limit * sizeof(size_t));
    if (!indices) return;
    for (size_t k = 0; k < limit; k++) {
        indices[k] = limit - 1 - k; // Reverse order access
    }
    for (j = 0; j < limit; j++) {
        volatile int data[512];
        size_t mapped_index = indices[j] % 512;
        data[mapped_index] *= 3; // Indirect, reversed-index memory access
    }
    free(indices);
}
}
