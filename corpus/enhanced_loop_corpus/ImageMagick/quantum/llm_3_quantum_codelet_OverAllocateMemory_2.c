#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access pattern on a buffer scaled with loop variable
    volatile uint64_t *buffer = (volatile uint64_t *)calloc(length, sizeof(uint64_t));
    if (buffer != NULL) {
        for (extent = 256; extent < length; extent *= 2) {
            // Consecutive write access up to current extent
            for (size_t i = 0; i < extent; i++) {
                buffer[i] = (uint64_t)(i + extent);
            }
        }
        free((void*)buffer);
    }
}
