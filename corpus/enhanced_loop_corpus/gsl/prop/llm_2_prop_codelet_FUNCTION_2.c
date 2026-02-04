#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a single loop with stride emulation
    // Assuming a flattened 2D array access pattern with consecutive writes
    size_t total_size = size1 * size2;
    for (i = 0; i < total_size; i++) {
        // Simulate row-major access: e.g., accessing arr[i] consecutively
        volatile char dummy = 0;
        dummy += i; // Prevent loop elimination, simulate memory access
    }
}
