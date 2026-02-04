#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive memory access pattern using a buffer traversed sequentially within the loop
    volatile uint32_t *buffer = (volatile uint32_t*)calloc(length, sizeof(uint32_t));
    if (buffer != NULL) {
        for (extent = 256; extent < length; extent *= 2) {
            // Perform consecutive writes up to current extent
            for (size_t j = 0; j < extent; j++) {
                buffer[j] ^= 0xFFFFFFFF;
            }
        }
        free((void*)buffer);
    }
}
