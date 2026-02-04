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
for (i = 0; i < M; i++) {
    for (j = i + 1; j < N; j++) {
        // Consecutive memory access pattern via flattened indexing
        // Assuming a 1D array representing a 2D layout accessed row-wise
        // Example: base_array[i * N + j] ensures consecutive access in inner loop
        volatile char dummy;
        &dummy; // Prevent loop from being optimized out
    }
}
}
