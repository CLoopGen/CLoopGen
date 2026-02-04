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
    // Access elements with a fixed stride (e.g., every 4th element) across rows
    // This simulates non-unit stride access which can affect cache performance
    size_t stride = 4;
    size_t max_elements = M * N;
    for (i = 0; i < max_elements; i += stride) {
        for (j = 0; j < stride && (i + j) < max_elements; j++) {
            // Process element at position i + j with strided outer loop
            // Simulates accessing A[(i+j)/N][(i+j)%N] with stride
        }
    }
}
