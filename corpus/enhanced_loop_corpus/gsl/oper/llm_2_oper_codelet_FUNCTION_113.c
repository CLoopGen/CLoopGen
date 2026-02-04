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
    // Variant 1: Consecutive memory access pattern using a single loop with stride simulation
    // Assume we are working with a 2D array 'arr' of size M x N flattened into 1D
    // Access pattern is now row-major consecutive, improving spatial locality
    size_t idx = 0;
    for (i = 0; i < M * N; i++) {
        idx = i;  // Direct consecutive access
        // Simulate some operation on data[idx]
        __asm__ volatile("" : "+g" (idx) : : "memory"); // Prevent optimization
    }
}
