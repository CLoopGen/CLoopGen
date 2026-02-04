#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Consecutive memory write pattern using a buffer of size 'extent'
        volatile double *buffer = (volatile double *)calloc(extent, sizeof(double));
        if (buffer != NULL) {
            for (size_t j = 0; j < extent; j++) { // Consecutive access
                buffer[j] = 1.0 / (j + 1);
            }
            free((void*)buffer);
        }
    }
}
