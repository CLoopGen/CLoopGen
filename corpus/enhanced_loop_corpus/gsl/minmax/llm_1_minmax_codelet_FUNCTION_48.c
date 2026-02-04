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
    // Variant 2: Strided memory access pattern - iterate column-wise with fixed stride
    // Access elements with stride M, simulating access to transposed or strided data layout
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Strided access: if accessing a 1D representation of 2D data, index = j + i*N
            // Now outer loop is over columns, inner over rows -> stride of N in memory
            // This creates non-consecutive (strided) memory accesses when fetching elements
            // Example: element at (i,j) maps to linear index i*N + j — accessed with stride N
        }
    }
}
