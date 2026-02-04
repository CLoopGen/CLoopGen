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
    // Variant 2: Strided memory access pattern with stride of 2
    // Access elements with a fixed stride, skipping every other element
    int *arr = (int*)malloc(M * N * sizeof(int));
    if (!arr) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += 2) { // Stride of 2
            arr[i * N + j] = i * N + j; // Strided access
        }
    }
    free(arr);
}
