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
    // Instead of accessing adjacent elements, access every k-th element (e.g., stride of 2)
    // Simulate access on a flattened 2D array with non-unit stride within each row segment
    int *arr = (int*)malloc(M * N * sizeof(int));
    size_t stride = 2;
    for (i = 1; i < M; i++) {
        for (j = 0; j < ((i) < (N) ? (i) : (N)); j += stride) {  // Strided iteration
            if (j < N) {
                arr[i * N + j] = arr[i * N + j] * 2;  // Strided memory access
            }
        }
    }
    free(arr);
}
