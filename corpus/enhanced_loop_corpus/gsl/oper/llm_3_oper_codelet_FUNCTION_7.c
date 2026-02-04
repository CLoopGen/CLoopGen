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
    // Access elements with a fixed stride (every 4th element), wrapping as needed
    int *arr = (int*)malloc(M * N * sizeof(int));
    if (!arr) return;
    size_t stride = 4;
    size_t total = M * N;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t index = (i * N + j) * stride % total; // Strided access with modulo wrap
            arr[index] += 1; // Simulate read-modify-write with non-unit stride
        }
    }
    free(arr);
}
