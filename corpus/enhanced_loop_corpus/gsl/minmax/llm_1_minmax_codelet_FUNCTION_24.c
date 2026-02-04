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
    // Variant 2: Consecutive (linear) memory access pattern
    // Flatten the 2D loop into a single loop for sequential traversal
    size_t total_elements = M * N;
    size_t idx = 0;
    for (idx = 0; idx < total_elements; idx++) {
        // Simulate processing each element consecutively
        i = idx / N; // Recover row index
        j = idx % N; // Recover column index
    }
}
