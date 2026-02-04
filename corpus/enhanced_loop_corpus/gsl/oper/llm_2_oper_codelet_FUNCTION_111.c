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
    // Assuming a 2D array 'arr' of dimensions M x N is accessed consecutively in memory
    int *arr = (int*)malloc(M * N * sizeof(int));
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            arr[i * N + j] = i + j;  // Sequential write access
        }
    }
    free(arr);
}
