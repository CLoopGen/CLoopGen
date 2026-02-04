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
    // Assume we are working with a 2D array of size M x N stored in row-major order
    // We flatten the 2D iteration into a 1D consecutive access pattern
    size_t idx;
    for (idx = 0; idx < M * N; idx++) {
        // Access is now consecutive: each iteration accesses next memory location
        // Logical (i,j) can be recovered if needed: i = idx / N, j = idx % N
        __asm__ volatile("" : "+r"(idx)); // Prevent optimization; simulate access
    }
}
