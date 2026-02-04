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
    // Access elements with a fixed stride across the inner dimension
    // Simulate accessing every 2nd column (strided access) in each row
    const size_t stride = 2;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // This creates a strided access pattern: j = 0, 2, 4, ..., skipping elements
            // If used with an array A[i][j], this would skip every other element
        }
        // Handle potential last odd index if N is not divisible by stride
        if (N % stride != 0) {
            j = N - 1;
            // Access last element if needed for completeness
        }
    }
}
