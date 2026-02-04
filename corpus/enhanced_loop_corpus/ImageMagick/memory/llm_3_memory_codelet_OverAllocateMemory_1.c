#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access with a sliding window pattern
        volatile int *buffer = (volatile int *)calloc(extent, sizeof(int));
        if (buffer == NULL) continue;
        // Consecutive write and read access over the allocated range
        for (size_t i = 1; i < extent; i++) {
            buffer[i] = buffer[i-1] + 1;
        }
        // Read back in reverse to create bidirectional access pattern
        for (size_t i = extent; i > 0; i--) {
            (void)buffer[i-1];
        }
        free((void*)buffer);
    }
}
