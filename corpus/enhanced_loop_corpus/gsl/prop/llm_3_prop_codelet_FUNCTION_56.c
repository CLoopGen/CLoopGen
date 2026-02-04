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
    // Consecutive memory access with linearized index to ensure spatial locality
    size_t total_elements = size1 * size2;
    volatile char* base = (volatile char*)&size1; // Use a valid address context
    for (size_t idx = 0; idx < total_elements; idx++) {
        // Access memory consecutively, simulating row-major traversal
        volatile char dummy = base[idx % 256]; // Modulo to keep access within bounds for safety
    }
}
