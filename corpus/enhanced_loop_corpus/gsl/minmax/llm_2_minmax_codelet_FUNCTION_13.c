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
    // Assuming a 2D array is laid out in row-major order, we traverse all elements consecutively
    size_t total_elements = M * N;
    for (i = 0; i < total_elements; i++) {
        // Simulate j = i % N, i_row = i / N
        j = i % N;
        // Dummy access to simulate data usage at index (i/N, j)
        volatile size_t dummy = (i / N) + j; // Prevent optimization
    }
}
