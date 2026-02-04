#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Consecutive memory access pattern using a buffer of size 'extent'
        volatile uint16_t *buffer = (volatile uint16_t*)calloc(extent, sizeof(uint16_t));
        if (buffer != NULL) {
            for (size_t j = 0; j < extent; j++) {
                buffer[j] = buffer[j] + j; // Sequential, consecutive access
            }
            free((void*)buffer);
        }
    }
}
