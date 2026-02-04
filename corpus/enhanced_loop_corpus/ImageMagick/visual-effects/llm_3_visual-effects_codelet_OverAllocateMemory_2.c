#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access with a buffer accessed sequentially
        volatile uint16_t *buffer = (volatile uint16_t*)calloc(extent, sizeof(uint16_t));
        if (buffer == NULL) continue;
        for (size_t j = 0; j < extent; j++) { // Consecutive access
            buffer[j] += (j + 1) * 2;
        }
        free((void*)buffer);
    }
}
