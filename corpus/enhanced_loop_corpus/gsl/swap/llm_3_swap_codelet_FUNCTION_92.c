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
    // Variant 2: Consecutive memory access pattern by reordering iteration
    // Flatten the 2D access into more cache-friendly consecutive writes
    // Assume a linear traversal over a conceptual 2D array stored in row-major order
    volatile char dummy_array[1024 * 1024];
    for (i = 0; i < size1; i++) {
        // Access elements consecutively starting from base index
        size_t base = i * size2;
        for (j = i + 1; j < size2; j++) {
            // Simulate consecutive-like access within bounds
            size_t idx = base + j;
            if (idx < 1024 * 1024) {
                dummy_array[idx] += 1;
            }
        }
    }
}
