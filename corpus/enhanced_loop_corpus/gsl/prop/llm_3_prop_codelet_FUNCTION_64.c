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
    // Consecutive memory access with flattened indexing
    // Simulating row-major order traversal over a 2D layout in linear memory
    size_t total_elements = size1 * size2;
    volatile char* buffer = (volatile char*)malloc(total_elements);
    if (!buffer) return;

    for (i = 0; i < total_elements; i++) {
        buffer[i] = i; // Sequential write access
    }

    free((void*)buffer);
}
