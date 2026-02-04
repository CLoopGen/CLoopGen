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
    // Access elements with a fixed stride across the inner dimension (e.g., every 2nd column)
    // This mimics scenarios with non-unit stride or data skipping
    const size_t stride = 2;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Strided access: could represent processing only even-indexed columns
            volatile size_t dummy = i * N + j; // Simulated strided array access
        }
    }
}
