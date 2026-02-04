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
    // Variant 2: Strided memory access pattern with stride of 2 in both dimensions
    // Simulating strided access by skipping every other element
    int *arr = (int*)malloc(M * N * sizeof(int));
    for (i = 0; i < M; i += 2) {
        for (j = 0; j < N; j += 2) {
            arr[i * N + j] = i * N + j;  // Access with stride-2 in both i and j
        }
    }
    free(arr);
}
