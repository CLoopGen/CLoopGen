#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access with a sliding window over a buffer
        volatile uint64_t *buffer = (volatile uint64_t*)calloc(extent, sizeof(uint64_t));
        if (buffer != NULL) {
            for (size_t j = 1; j < extent; j++) {
                buffer[j] = buffer[j-1] + 1; // Consecutive dependent access
            }
            free((void*)buffer);
        }
    }
}
