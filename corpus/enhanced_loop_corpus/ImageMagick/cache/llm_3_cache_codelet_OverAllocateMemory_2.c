#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access in reverse order on a dynamically allocated buffer
        volatile int *buffer = (volatile int*)calloc(extent, sizeof(int));
        if (buffer == NULL) continue;
        for (size_t i = extent; i > 0; --i) { // Consecutive reverse traversal
            buffer[i-1] = (int)(i * 2);
        }
        free((void*)buffer);
    }
}
