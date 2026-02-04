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
size_t index = 0;
for (i = 0; i < M; i++) {
    for (j = i + 1; j < N; j++) {
        // Consecutive memory access via flattened index
        // Simulate linear traversal in a 1D view of 2D data
        index = i * N + j;  // Row-major mapping
        // Subsequent operations would use 'index' for array access
    }
}
}
