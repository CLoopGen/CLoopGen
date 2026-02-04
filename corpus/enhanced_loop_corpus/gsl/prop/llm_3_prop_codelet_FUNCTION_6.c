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
    // Consecutive access pattern using a single loop with linear index
    size_t idx = 0;
    size_t total_size = size1 * size2;
    for (idx = 0; idx < total_size; idx++) {
        // Access elements consecutively as in a flattened 1D array
        i = idx / size2;  // Recover row index
        j = idx % size2;  // Recover column index
    }
}
