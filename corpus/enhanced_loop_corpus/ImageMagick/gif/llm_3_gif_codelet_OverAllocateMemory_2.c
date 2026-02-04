#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access in reverse order to modify access pattern
        volatile uint16_t *buffer = (volatile uint16_t*)calloc(extent, sizeof(uint16_t));
        if (buffer == NULL) continue;
        // Consecutive backward traversal
        for (size_t i = extent; i > 0; --i) {
            buffer[i - 1] = (uint16_t)(i & 0xFF);
        }
        free((void*)buffer);
    }
}
