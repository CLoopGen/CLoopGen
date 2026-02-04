#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access pattern in a buffer of size proportional to extent
        volatile uint16_t *buffer = (volatile uint16_t*)calloc(extent, sizeof(uint16_t));
        if (buffer == NULL) continue;
        for (size_t j = 0; j < extent; j++) {
            buffer[j] = (uint16_t)(j & 0xFF);
        }
        // Simulate use to prevent optimization
        volatile size_t sink = buffer[extent/2];
        free((void*)buffer);
    }
}
