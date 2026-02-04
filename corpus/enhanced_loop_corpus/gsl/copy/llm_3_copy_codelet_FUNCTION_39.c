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
    // Variant 2: Consecutive (unit-stride) memory access with linearized traversal
    // Flatten the iteration space to access memory in strictly increasing order
    // Simulating a scenario where data is accessed consecutively for cache efficiency
    int *A = (int*)malloc(M * N * sizeof(int));
    size_t idx = 0;
    for (i = 0; i < M; i++) {
        // Inner loop starts from i+1, so we simulate consecutive writes in valid region
        for (j = i + 1; j < N; j++) {
            if (idx < M * N) {
                A[idx++] = i + j; // Sequential write using flattened index
            }
        }
    }
    free(A);
}
