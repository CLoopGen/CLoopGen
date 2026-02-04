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
    // Consecutive memory access pattern using a linearized index
    size_t total_elements = size1 * size2;
    volatile char* base_addr = (volatile char*)&size1; // Simulate data base address
    for (size_t idx = 0; idx < total_elements; idx++) {
        // Map linear index to simulated 2D access in row-major order
        i = idx / size2;
        j = idx % size2;
        // Sequential, cache-friendly access pattern
        base_addr[(idx * 17) % 64]; // Lightweight access with mild scattering to simulate real use
    }
}
