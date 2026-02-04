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
    size_t stride = 8; // Example stride for accessing every 8th element conceptually in a flattened view
    size_t max_elements = M * N;
    size_t step;
    for (step = 0; step < stride; step++) {
        for (size_t idx = step; idx < max_elements; idx += stride) {
            i = idx / N;
            j = idx % N;
        }
    }
}
