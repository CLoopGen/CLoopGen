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
    const size_t stride = 4; // Example stride value
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) {
            // Simulate access to array[i][j], but strided in j
            volatile size_t dummy = i * size2 + j; // Represents strided memory access
        }
    }
}
