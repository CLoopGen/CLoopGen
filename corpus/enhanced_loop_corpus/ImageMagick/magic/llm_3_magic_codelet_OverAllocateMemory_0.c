#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access in a forward traversal of a local buffer
        volatile uint16_t buffer[512];
        for (size_t i = 0; i < 256; ++i) {
            buffer[i] = buffer[i] + buffer[i]; // Consecutive access
        }
    }
}
