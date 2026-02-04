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
    // Variant 1: Consecutive memory access pattern using a single loop with stride emulation
    // Assume we are iterating over a 2D array A[M][N] stored in row-major order
    // Here, we flatten the iteration into consecutive accesses
    size_t idx = 0;
    for (i = 0; i < M * N; i++) {
        // Simulate processing element at flattened index
        idx = i; // consecutive access index
        // Implied memory access: A[idx] if it were an array
    }
}
