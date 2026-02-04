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
    // Variant 2: Strided memory access pattern - traverse columns with fixed stride
    size_t stride = N; // Assume N is the width of a 2D layout
    size_t col, row;
    for (col = 0; col < N; col++) {
        for (row = 0; row < M; row++) {
            // Access pattern: strided access by iterating column-wise
            // This reverses the original loop order, leading to non-consecutive memory accesses
            // Example: arr[row * N + col] would exhibit stride-N access
        }
    }
}
