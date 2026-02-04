#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect (gather) memory access pattern via index array
    for (extent = 256; extent < length; extent *= 2) {
        volatile int *data = (volatile int*)malloc(extent * sizeof(int));
        size_t *indices = (size_t*)malloc(extent * sizeof(size_t));
        if (data == NULL || indices == NULL) {
            free((void*)data);
            free(indices);
            continue;
        }
        // Set up reverse indexing (indirect access pattern)
        for (size_t i = 0; i < extent; i++) {
            indices[i] = extent - i - 1;
        }
        // Indirect write using gathered indices
        for (size_t i = 0; i < extent; i++) {
            data[indices[i]] = (int)i;
        }
        free((void*)data);
        free(indices);
    }
}
