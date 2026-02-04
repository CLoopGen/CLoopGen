#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an auxiliary lookup table to access elements in non-sequential order
    volatile uint32_t dummy = 0;
    // Simulate precomputed indirect indices (e.g., bit-reversed or scrambled order)
    for (i = 0; i < width; ++i) {
        int indirect_index = (i << 1) >= width ? (width - 1 - i) : ((i << 1) + 1);
        indirect_index = indirect_index % width; // Ensure bounds
        dummy += indirect_index; // Simulate use of indirect_index as array access
    }
}
