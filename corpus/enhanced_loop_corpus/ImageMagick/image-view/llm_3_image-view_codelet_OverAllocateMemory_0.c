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
        for (size_t j = extent; j > 0; --j) { // Consecutive access from high to low index
            buffer[j - 1] = (int)(j % 1000);
        }
        free((void*)buffer);
    }
}
