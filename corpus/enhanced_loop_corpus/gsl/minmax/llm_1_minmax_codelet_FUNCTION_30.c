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
    // Variant 2: Strided memory access pattern - traverse column-major with stride M
    size_t *indices = (size_t*)malloc(M * N * sizeof(size_t));
    if (!indices) return;
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            indices[j * M + i] = j * M + i; // Simulate strided access with explicit indexing
        }
    }
    free(indices);
}
