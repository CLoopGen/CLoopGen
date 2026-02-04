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
    // Flatten the 2D iteration into a single loop for sequential traversal
    size_t total_elements = M * N;
    size_t idx;
    for (idx = 0; idx < total_elements; idx++) {
        i = idx / N;  // Recover row index
        j = idx % N;  // Recover column index
        // Simulated consecutive access (e.g., A[idx] in row-major order)
    }
}
