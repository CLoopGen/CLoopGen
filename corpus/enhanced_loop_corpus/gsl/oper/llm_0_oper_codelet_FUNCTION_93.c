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
    // Variant 1: Strided memory access pattern
    // Simulate accessing elements of a 2D array with stride N, stepping through in strided manner
    size_t stride = 4; // Example stride for access pattern
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Access every 'stride'-th element, assuming some array A[i*N + j]
            // This creates a non-unit stride access pattern
            volatile size_t idx = i * N + j;
            // Prevent optimization; simulate access
            __asm__ volatile("" : : "r"(idx) : "memory");
        }
    }
}
