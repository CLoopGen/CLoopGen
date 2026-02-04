#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access with a fixed-size buffer
        volatile uint32_t buffer[64];
        size_t count = (extent >> 4) % 64;
        for (size_t i = 0; i < count; ++i) { // Consecutive access
            buffer[i] ^= buffer[(i + 1) % count];
        }
    }
}
