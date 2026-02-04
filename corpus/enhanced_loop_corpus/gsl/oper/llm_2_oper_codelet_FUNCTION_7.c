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
    // Variant 1: Consecutive memory access pattern using row-major traversal
    // Assume a 2D array 'arr' of size M x N is accessed consecutively in memory
    int *arr = (int*)malloc(M * N * sizeof(int));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t index = i * N + j; // Row-major consecutive access
            arr[index] = index;       // Simulate write with predictable stride
        }
    }
    free(arr);
}
