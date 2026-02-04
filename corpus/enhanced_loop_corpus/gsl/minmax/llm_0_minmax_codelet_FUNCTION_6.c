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
    // Assuming a 1D array representation of a matrix with stride N
    // Access elements with a fixed stride to simulate non-consecutive access
    size_t *array = (size_t*)malloc(M * N * sizeof(size_t));
    if (!array) return;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += 2) {  // Stride of 2: accessing every second element
            array[i * N + j] = i + j;
        }
    }
    free(array);
}
