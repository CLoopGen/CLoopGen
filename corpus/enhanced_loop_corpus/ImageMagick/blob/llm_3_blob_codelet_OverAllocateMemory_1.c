#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access pattern in a pre-allocated buffer
    volatile uint32_t *buffer = (volatile uint32_t*)calloc(length, sizeof(uint32_t));
    if (buffer != NULL) {
        for (extent = 256; extent < length; extent *= 2) {
            // Consecutive write access to simulate streaming pattern
            for (size_t i = 0; i < extent; i++) {
                buffer[i] = i;
            }
        }
        free((void*)buffer);
    }
}
