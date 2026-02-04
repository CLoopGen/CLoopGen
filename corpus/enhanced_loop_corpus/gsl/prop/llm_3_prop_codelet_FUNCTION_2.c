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
    const size_t stride = 4; // Example stride factor
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j += stride) { // Strided iteration in inner loop
            // Simulate accessing arr[i][j], arr[i][j+stride], etc.
            volatile char dummy = 0;
            dummy += i * size2 + j; // Representative address calculation
        }
    }
}
