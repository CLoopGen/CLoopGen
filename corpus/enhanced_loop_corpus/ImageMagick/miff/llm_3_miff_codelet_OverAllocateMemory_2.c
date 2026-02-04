#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access pattern in a temporary buffer
        volatile size_t *buffer = (volatile size_t*)calloc(extent, sizeof(size_t));
        if (buffer != NULL) {
            for (size_t j = 0; j < extent; j++) {
                buffer[j] += j + 1;
            }
            free((void*)buffer);
        }
    }
}
