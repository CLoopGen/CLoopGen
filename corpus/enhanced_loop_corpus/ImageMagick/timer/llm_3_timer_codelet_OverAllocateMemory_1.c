#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive memory access pattern using sequential traversal of a buffer
    volatile uint32_t buffer[512];
    size_t idx = 0;
    for (extent = 256; extent < length; extent *= 2) {
        // Perform consecutive writes to simulate predictable memory access
        for (size_t j = 0; j < 128; j++) {
            buffer[(idx + j) % 512] = j; // Sequential access with modulo indexing
        }
        idx = (idx + 128) % 512;
    }
}
