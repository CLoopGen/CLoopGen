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
    // Variant 1: Strided memory access pattern
    // Assuming a 2D array is accessed with stride 'N', simulate strided access by iterating over transposed indices
    // This variant simulates accessing elements with stride M (column-major like access)
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            // Simulate access to element at index (i*N + j) as if in row-major flat array
            // This creates a non-consecutive, strided access pattern when N is large
            volatile size_t idx = i * N + j;
            (void)idx; // Prevent unused variable warning
        }
    }
}
