#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access with a fixed-size buffer within the loop scope
        volatile uint16_t buffer[128];
        size_t count = (extent < 128 * sizeof(uint16_t)) ? extent / sizeof(uint16_t) : 128;
        for (size_t i = 0; i < count; ++i) { // Consecutive access
            buffer[i] = (uint16_t)(extent / (i + 1));
        }
    }
}
