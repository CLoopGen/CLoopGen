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
    // Variant 2: Strided memory access pattern - iterate with a fixed stride across iterations
    size_t stride = 2;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Access every 'stride'-th element, skipping neighbors
            // This creates a non-consecutive, strided access pattern in the inner dimension
            if (j + 1 < N) {
                // Optionally process next element to maintain workload
                // Simulating use of j and j+1 without while
            }
        }
    }
}
