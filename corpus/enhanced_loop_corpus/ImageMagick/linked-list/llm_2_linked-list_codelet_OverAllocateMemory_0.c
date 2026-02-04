#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern size_t extent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation
    // We simulate a strided traversal by using an index that jumps by a fixed stride
    // assuming 'length' represents array size and we're iterating with stride 4
    for (extent = 256; extent < length; extent = extent + 256) {
        // Simulated strided access, e.g., arr[extent] would be accessed here
        volatile size_t dummy = extent; // Prevent optimization
    }
}
