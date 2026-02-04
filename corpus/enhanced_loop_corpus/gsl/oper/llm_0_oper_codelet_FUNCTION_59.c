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
    size_t idx = 0;
    for (i = 0; i < M * N; i += 2) {  // Stride of 2
        idx = i % (M * N);
        // Simulated use of idx to represent strided access
        volatile size_t use = idx;
        (void)use;
    }
}
