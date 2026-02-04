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
    // Variant 2: Strided memory access pattern
    // Access elements with a fixed stride across the inner dimension
    size_t stride = 4; // Example stride value
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Simulate strided access, e.g., array[i][j] with skipping
            volatile size_t dummy = i * size2 + j; // Representing memory address calculation
        }
    }
}
