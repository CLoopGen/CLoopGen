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
    // Variant 1: Strided memory access pattern simulation
    // Assuming a 2D array accessed in a strided manner through linearized indexing
    // Using stride of 2 for demonstration (simulating non-unit stride access)
    size_t stride = 2;
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    if (!dummy_array) return;

    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j += stride) {
            // Simulate strided access: accessing every 'stride' element
            dummy_array[i * N + j] += 1; // Example operation
        }
    }

    free(dummy_array);
}
