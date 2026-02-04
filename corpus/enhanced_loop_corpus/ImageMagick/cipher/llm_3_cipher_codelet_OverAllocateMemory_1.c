#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use consecutive memory access with a buffer that doubles in effective usage
    volatile char *buffer = (volatile char*)calloc(length, sizeof(char));
    if (buffer != NULL) {
        for (extent = 256; extent < length; extent *= 2) {
            // Consecutive write access over increasing extents
            for (size_t i = 0; i < extent; i++) {
                buffer[i] ^= 0xFF; // Modify each byte consecutively
            }
        }
        free((void*)buffer);
    }
}
