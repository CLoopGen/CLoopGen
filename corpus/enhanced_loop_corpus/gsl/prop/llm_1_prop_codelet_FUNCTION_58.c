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
    // Variant 2: Strided memory access pattern
    // Access elements with a fixed stride (e.g., every 4th element) across the 2D range
    const size_t stride = 4;
    size_t total_size = size1 * size2;
    for (size_t idx = 0; idx < total_size; idx += stride) {
        // Simulate strided access - could map to array[idx]
        volatile size_t dummy = idx; // Represents memory operation with stride
    }
}
