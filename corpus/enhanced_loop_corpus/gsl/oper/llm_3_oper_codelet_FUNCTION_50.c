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
    // Variant 2: Strided memory access pattern with column-major traversal
    // We reverse the loop nesting and introduce a fixed stride in the outer dimension
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Accessing elements with stride 'N' if mapped to linear memory
            // This creates a strided access pattern typical in transposed operations
            char dummy = 0;
            // Simulated work on "array[i*N + j]" but accessed column by column
        }
    }
}
