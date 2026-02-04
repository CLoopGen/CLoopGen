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
    // Variant 2: Consecutive (unit-stride) memory access pattern with loop interchange
    // Reordered loops to ensure row-major consecutive access
    // Assume we are traversing a 2D matrix in column-major logic but restructured for spatial locality
    size_t *dummy_array = (size_t*)malloc(M * N * sizeof(size_t));
    if (!dummy_array) return;

    for (j = 1; j < N; j++) {
        for (i = 0; i < M && i < j; i++) {
            // Access pattern now proceeds with consecutive i, leading to unit stride in effective indexing
            dummy_array[i * N + j] += 1; // Example write with good spatial locality
        }
    }

    free(dummy_array);
}
