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
    // Variant 2: Strided memory access pattern - process elements with a fixed stride across columns
    size_t stride = 4; // Example stride value
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j += stride) {
            // Access every 'stride'-th element in the inner dimension
            // Simulate work at each strided access
            volatile size_t dummy = i + j; // Prevent optimization
        }
    }
}
