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
    // Simulate accessing a 2D array with stride N, stepping through elements every 2nd row and 3rd column
    size_t stride_i = 2;
    size_t stride_j = 3;
    for (i = 0; i < M; i += stride_i) {
        for (j = 0; j < N; j += stride_j) {
            // Simulated strided access (e.g., A[i*N + j] would be accessed sparsely)
        }
    }
}
