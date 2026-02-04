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
    size_t idx = 0;
    size_t total_elements = M * N;
    for (idx = 0; idx < total_elements; idx++) {
        // Access pattern is now consecutive: linear traversal as if flattening a 2D array
        // This simulates row-major order access, improving spatial locality
        char dummy = 0;
        // Simulated work on "array[idx]" if an array were present
    }
}
