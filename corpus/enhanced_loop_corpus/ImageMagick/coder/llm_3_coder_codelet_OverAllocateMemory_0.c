#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access in a buffer scaled with loop progression
    volatile uint32_t *buffer = (volatile uint32_t*)calloc(length, sizeof(uint32_t));
    if (buffer != NULL) {
        for (extent = 256; extent < length; extent *= 2) {
            // Consecutive write access over increasing power-of-two ranges
            for (size_t idx = 0; idx < extent; idx++) {
                buffer[idx] = extent + idx;
            }
        }
        free((void*)buffer);
    }
}
