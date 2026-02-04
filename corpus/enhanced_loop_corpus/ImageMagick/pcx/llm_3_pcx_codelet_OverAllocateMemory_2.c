#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Consecutive memory access pattern using a buffer of size proportional to extent
        volatile uint32_t *buffer = (volatile uint32_t*)calloc(extent, sizeof(uint32_t));
        if (buffer != NULL) {
            for (size_t i = 0; i < extent; i++) { // Fully consecutive access
                buffer[i] += (uint32_t)(i * 2);
            }
            free((void*)buffer);
        }
    }
}
