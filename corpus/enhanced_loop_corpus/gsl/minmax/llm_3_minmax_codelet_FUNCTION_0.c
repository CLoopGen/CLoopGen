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
    // Access elements with a fixed stride across the inner dimension to simulate strided array access
    // For example, stepping by 2 in the j-loop creates non-unit stride
    size_t stride = 2;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            volatile size_t dummy = i * N + j; // Simulate memory access at index [i][j]
        }
        // Handle potential remainder if N is not divisible by stride
        for (j = N - (N % stride); j < N; j++) {
            volatile size_t dummy = i * N + j;
        }
    }
}
