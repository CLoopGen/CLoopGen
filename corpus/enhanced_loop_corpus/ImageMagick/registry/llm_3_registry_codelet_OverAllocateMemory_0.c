#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access in a block determined by current extent
        volatile uint32_t sum = 0;
        uint32_t *buffer = (uint32_t*)calloc(extent, sizeof(uint32_t));
        if (buffer == NULL) continue;
        for (size_t j = 0; j < extent; j++) {
            sum += buffer[j];  // Consecutive access across increasing extents
        }
        free(buffer);
    }
}
