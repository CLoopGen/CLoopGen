#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Change memory access pattern to consecutive access over a simulated buffer
    volatile uint16_t *buffer = (volatile uint16_t*)aligned_alloc(16, length * sizeof(uint16_t));
    if (buffer != NULL) {
        for (extent = 256; extent < length; extent *= 2) {
            // Consecutive write access in increasing order
            for (size_t i = 0; i < extent; i++) {
                buffer[i] = buffer[i] + (uint16_t)i;
            }
        }
        free((void*)buffer);
    }
}
