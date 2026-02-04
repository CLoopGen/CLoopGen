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
    // Simulate accessing elements of a 2D array with stride N, stepping through in a non-unit stride manner
    size_t stride = 4; // Example stride factor
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Perform dummy access over a hypothetical data array with strided access
            volatile char dummy[1024];
            volatile char sink = dummy[j % 1024]; // Simulate meaningful access
            (void)sink;
        }
    }
}
