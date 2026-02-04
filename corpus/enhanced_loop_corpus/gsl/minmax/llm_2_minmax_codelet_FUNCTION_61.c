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
    // Assume a 2D array is laid out in row-major order and we traverse it consecutively
    size_t idx;
    for (idx = 0; idx < M * N; idx++) {
        // Simulate row i = idx / N, column j = idx % N
        i = idx / N;
        j = idx % N;
    }
}
