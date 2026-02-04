#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Simulate accessing elements with a fixed stride (e.g., every 4th element)
    // Assuming a flattened 2D array access pattern with stride = 4
    size_t stride = 4;
    for (i = 0; i < size1; i += stride) {
        for (j = 0; j < size2; j++) {
            // Simulated strided outer loop access
            volatile size_t index = i * size2 + j; // dummy access to create memory pattern
            (void)index;
        }
    }
}
