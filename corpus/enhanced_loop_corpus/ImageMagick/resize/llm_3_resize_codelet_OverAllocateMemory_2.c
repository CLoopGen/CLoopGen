#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Consecutive memory access pattern using a linear buffer walk
        char *buffer = (char*)malloc(extent * sizeof(char));
        if (!buffer) continue;
        for (size_t i = 0; i < extent; ++i) { // Fully consecutive access
            buffer[i] = (char)(i & 0xFF);
            // Ensure side effect
            *(volatile char*)&buffer[i] = buffer[i];
        }
        free(buffer);
    }
}
