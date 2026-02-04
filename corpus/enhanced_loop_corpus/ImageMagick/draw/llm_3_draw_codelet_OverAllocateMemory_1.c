#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access with a fixed buffer to simulate streaming pattern
    volatile uint32_t buffer[256];
    for (extent = 256; extent < length; extent *= 2) {
        size_t idx = (extent >> 3) & 0xFF; // Map extent to an index in buffer range
        // Consecutive-like access within buffer, repeated as extent grows
        for (size_t j = 0; j < 64; j++) {
            buffer[(idx + j) & 0xFF] += j;
        }
    }
}
