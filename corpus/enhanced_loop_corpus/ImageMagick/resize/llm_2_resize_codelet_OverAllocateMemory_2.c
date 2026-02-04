#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (extent = 256; extent < length; extent *= 2) {
        // Introduce a strided access pattern via an index array (indirect-like access)
        size_t *indices = (size_t*)malloc(extent * sizeof(size_t));
        if (!indices) continue;
        for (size_t i = 0; i < extent; i += 4) { // Stride of 4
            indices[i] = i;
            // Simulate use to avoid optimization away
            *(volatile size_t*)&indices[i] = indices[i];
        }
        free(indices);
    }
}
