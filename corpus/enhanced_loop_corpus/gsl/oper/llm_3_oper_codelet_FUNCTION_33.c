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
    // Variant 2: Strided memory access pattern
    // Access elements with a fixed stride across the inner dimension, jumping over elements
    const size_t stride = 2; // Access every second element in the j-loop
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // This creates a strided access pattern, useful in scenarios like processing even-indexed elements
            // If used with arrays, would access arr[i][j], arr[i][j+2], etc.
        }
    }
}
