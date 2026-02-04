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
    // Variant 1: Consecutive memory access pattern using a single loop with linear index
    size_t idx = 0;
    for (i = 0; i < size1; i++) {
        for (j = i + 1; j < size2 && idx < size1 * size2; j++, idx++) {
            // Simulate consecutive access by processing elements in row-major order
            // Could be used to traverse a flattened 2D array sequentially
        }
    }
}
