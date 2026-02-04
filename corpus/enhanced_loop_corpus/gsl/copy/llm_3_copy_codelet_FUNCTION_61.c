#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) memory access using an index array
    // Access elements based on an indirection array, simulating irregular access
    // Assume 'indices' is an externally defined array of size src_size1 containing valid offsets
    extern size_t* indices; // assumed to be initialized elsewhere
    for (i = 0; i < src_size1; i++) {
        size_t idx = indices[i]; // indirect addressing
        if (idx < src_size1) {
            // Simulate use of idx, e.g., data[idx] = transformed(data[idx]);
        }
    }
}
