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
    // Consecutive memory access with linearized indexing
    // Treat 2D iteration as a 1D sequential scan
    size_t total_elements = size1 * size2;
    for (size_t idx = 0; idx < total_elements; idx++) {
        // Sequential, unit-stride access pattern
        // Maximizes spatial locality and cache performance
    }
}
