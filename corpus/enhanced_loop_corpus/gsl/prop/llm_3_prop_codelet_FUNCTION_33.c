#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive access pattern via linearized indexing
    size_t total_elements = size1 * size2;
    for (size_t idx = 0; idx < total_elements; idx++) {
        i = idx / size2;  // Recover row
        j = idx % size2;  // Recover column
        // Access memory in a sequential, cache-friendly manner
    }
}
