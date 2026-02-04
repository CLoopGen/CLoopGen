#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access pattern on a buffer of size 'extent'
        volatile uint32_t *buffer = (volatile uint32_t*)calloc(extent, sizeof(uint32_t));
        if (buffer != NULL) {
            for (size_t i = 0; i < extent; i++) {
                buffer[i] += buffer[i] + i;
            }
            free((void*)buffer);
        }
    }
}
