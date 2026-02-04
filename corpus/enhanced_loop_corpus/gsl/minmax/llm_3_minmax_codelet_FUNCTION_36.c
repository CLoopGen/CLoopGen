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
    // Variant 2: Strided memory access pattern - traverse columns first with fixed stride
    size_t stride = 8; // Simulate strided access, e.g., every 8th element in flattened logic
    size_t max_elements = M * N;
    size_t idx;
    for (idx = 0; idx < max_elements; idx += stride) {
        i = idx / N;
        j = idx % N;
    }
    // Handle edge case where stride might skip last elements
    if ((max_elements - 1) % stride != 0) {
        i = (max_elements - 1) / N;
        j = (max_elements - 1) % N;
    }
}
