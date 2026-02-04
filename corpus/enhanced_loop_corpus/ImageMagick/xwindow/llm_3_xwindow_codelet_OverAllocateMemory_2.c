#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access in reverse order
        volatile uint16_t sum = 0;
        uint16_t *buffer = (uint16_t*)calloc(extent, sizeof(uint16_t));
        if (!buffer) continue;
        for (size_t j = extent; j > 0; --j) {
            sum += buffer[j - 1]; // Consecutive access in reverse
        }
        free(buffer);
    }
}
