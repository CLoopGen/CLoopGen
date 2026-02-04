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
    // Simulating access like A[i][j*stride] or A[i][j] with non-unit stride in j
    const size_t stride = 4; // Example stride factor
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) { // Strided iteration in inner loop
            // Ensure j stays within bounds
            if (j < N) {
                // Dummy access at position (i, j), simulating strided pattern
                // Could represent A[i][j] accessed every 'stride' columns
            }
        }
    }
}
