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
    // Variant 2: Strided memory access pattern - access every K-th element across rows
    // Simulate accessing columns with a fixed stride (e.g., every 2nd column)
    size_t stride = 2;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Strided access: skips elements, reduces temporal locality
            // Useful in algorithms like stencil computations or subsampling
        }
    }
}
