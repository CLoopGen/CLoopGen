#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Memory Access Pattern Modification: Consecutive access in blocks of size 'extent'
        // Simulate processing consecutive chunks of increasing sizes
        volatile uint32_t sum = 0;
        uint32_t* buffer = (uint32_t*)calloc(extent, sizeof(uint32_t));
        if (!buffer) continue;
        // Touch memory consecutively within the current extent
        for (size_t j = 0; j < extent && j < length; j++) {
            sum += buffer[j]; // Consecutive access pattern
        }
        // Use sum to prevent optimization
        if (sum == 0) extent++; 
        free(buffer);
    }
}
