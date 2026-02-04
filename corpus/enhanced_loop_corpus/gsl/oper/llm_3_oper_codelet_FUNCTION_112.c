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
    // Access elements with a fixed stride (e.g., every 2nd row), jumping over blocks
    size_t stride = 2; // Stride factor for outer loop
    for (i = 0; i < M; i += stride) {
        for (j = 0; j < N; j++) {
            // Perform operation with strided access — skips rows
            // This creates non-consecutive memory accesses across iterations of i
        }
    }
}
