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
    // Variant 2: Indirect memory access via index array
    // Use an index mapping table to access array elements in non-sequential order
    size_t *array = (size_t*)malloc(M * N * sizeof(size_t));
    size_t *indices = (size_t*)malloc(N * sizeof(size_t));
    if (!array || !indices) {
        free(array); free(indices);
        return;
    }

    // Initialize indirect indices (reverse order for example)
    for (j = 0; j < N; j++) {
        indices[j] = N - 1 - j;
    }

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            size_t idx = i * N + indices[j];  // Indirect access
            array[idx] = i * N + j;
        }
    }

    free(array);
    free(indices);
}
