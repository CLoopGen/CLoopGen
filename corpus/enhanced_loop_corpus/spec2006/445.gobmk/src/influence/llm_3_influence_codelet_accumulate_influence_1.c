#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map
    // Precompute a lookup table of indices and traverse in shuffled order
    int size = (19 + 1) * (19 + 1);
    int indices[400];
    for (ii = 0; ii < size; ii++) {
        // Create indirect access: reverse the order (e.g., 399, 398, ..., 0)
        indices[ii] = size - 1 - ii;
    }
    // Use indirect addressing via the index array
    for (ii = 0; ii < size; ii++) {
        working[indices[ii]] = 0;
    }
}
