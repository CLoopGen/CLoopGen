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
    // Variant 1: Strided memory access pattern
    // Assuming a 1D array representation of a matrix with stride N
    // Access elements with a fixed stride to simulate non-consecutive access
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    size_t stride = 2; // Example stride
    if (stride == 0) stride = 1;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            dummy_array[i * N + j] = i + j; // Simulate write with strided access
        }
    }
    free(dummy_array);
}
