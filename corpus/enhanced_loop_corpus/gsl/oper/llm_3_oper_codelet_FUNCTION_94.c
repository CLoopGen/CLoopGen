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
    // Variant 2: Consecutive (linearized) memory access pattern
    // Traverse what would be a 2D array as a flat 1D layout to ensure consecutive memory accesses
    size_t total_elements = M * N;
    volatile char linear_array[2048]; // Simulated backing store
    for (size_t idx = 0; idx < total_elements; idx++) {
        // Map linear index back to i,j if needed, but access memory consecutively
        i = idx / N;
        j = idx % N;
        volatile char sink = linear_array[idx % 2048]; // Consecutive access pattern
        (void)sink;
    }
}
