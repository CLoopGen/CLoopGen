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
    // Access elements with a fixed stride (e.g., every second row and every third column)
    size_t stride_i = 2;
    size_t stride_j = 3;
    for (i = 0; i < M; i += stride_i) {
        for (j = 0; j < N; j += stride_j) {
            // This creates a strided access pattern, skipping elements
            // Useful to simulate non-unit stride memory accesses in numerical codes
        }
    }
}
