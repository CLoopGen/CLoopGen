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
    // Simulate a strided access by using a single loop with stride = 2
    // Assuming we are iterating over a conceptual linear array representation of M*N elements
    size_t stride = 2;
    for (i = 0; i < M * N; i += stride) {
        // Dummy access to simulate data processing with stride
        volatile size_t idx = i;
        (void)idx;
    }
}
