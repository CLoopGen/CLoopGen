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
    // Variant 1: Consecutive memory access pattern using a single loop with linear index
    size_t idx = 0;
    for (i = 0; i < M; i++) {
        for (j = i + 1; j < N; j++) {
            // Simulate consecutive access via flattened index (e.g., accessing a 1D array representation of upper triangle)
            idx = i * N + j;  // Linearized index for row-major access
        }
    }
}
