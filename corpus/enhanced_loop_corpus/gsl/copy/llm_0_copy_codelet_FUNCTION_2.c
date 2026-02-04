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
    // Simulate array access with stride of 2 on a flattened 2D index
    // Assume data is accessed in row-major order with strided traversal
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j += 2) {  // Stride of 2 in inner loop
            if (i * N + j < M * N) {
                dummy_array[i * N + j] += 1;  // Simulated strided write access
            }
        }
    }
    free(dummy_array);
}
