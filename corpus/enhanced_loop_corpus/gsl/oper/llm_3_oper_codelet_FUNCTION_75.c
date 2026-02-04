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
    // Variant 2: Strided memory access pattern
    // Access elements with a fixed stride (e.g., every 2nd element in flattened array)
    // Simulating non-unit stride access to create cache inefficiency
    int *A = (int*)malloc(M * N * sizeof(int));
    size_t stride = 2;
    size_t index = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            index = (i * N + j) * stride; // Strided access pattern
            if (index < M * N) {
                A[index] = i * N + j;
            }
        }
    }
    free(A);
}
