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
        // Simulate row and column indices without nested loops
        size_t current_row = i / N;
        size_t current_col = i % N;
        // Access pattern now is consecutive in memory if used with an array like arr[current_row][current_col]
    }
}
