#include <stdio.h>

#include <inttypes.h>

extern size_t i;
extern int *reg_allocno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated static mapping)
    // Create a static index array that defines the access order — reverse order as example
    static size_t indices[53];
    static int initialized = 0;

    // Initialize index map once (conceptual; in real use, could be compile-time)
    if (!initialized) {
        for (size_t j = 0; j < 53; j++) {
            indices[j] = 52 - j;  // reverse access: from last to first
        }
        initialized = 1;
    }

    // Use indirect access via precomputed indices
    for (size_t j = 0; j < 53; j++) {
        size_t idx = indices[j];
        reg_allocno[idx] = -1;
    }
}
