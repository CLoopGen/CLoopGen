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
    // Variant 1: Consecutive memory access pattern using a simulated array access
    // Assume we are working with a 2D array 'arr' of size M x N, accessed in row-major order
    // We modify the inner loop to access elements consecutively in memory by fixing i and iterating j
    int *arr = (int*)malloc(M * N * sizeof(int));
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j++) {
            arr[i * N + j] = arr[i * N + j] + 1;  // Consecutive access along row i
        }
    }
    free(arr);
}
