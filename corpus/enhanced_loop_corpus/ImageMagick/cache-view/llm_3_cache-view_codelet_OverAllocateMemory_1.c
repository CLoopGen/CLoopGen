#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Use consecutive memory access in reverse order to modify access pattern
        volatile double *buffer = (volatile double *)calloc(extent, sizeof(double));
        if (buffer != NULL) {
            for (size_t j = extent; j > 0; j--) { // Consecutive backward traversal
                buffer[j-1] = (double)(j * 2);
            }
            free((void*)buffer);
        }
    }
}
