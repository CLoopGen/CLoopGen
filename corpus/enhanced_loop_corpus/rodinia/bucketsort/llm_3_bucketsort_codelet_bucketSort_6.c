#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int size = (1 << 10);
    int indices[size];
    for (int i = 0; i < size; i++) {
        indices[i] = size - i - 1; // Reverse order indices
    }
    for (int i = 1; i < size; i++) {
        int curr_idx = indices[i];
        int prev_idx = indices[i - 1];
        h_offsets[curr_idx] = h_offsets[prev_idx];
    }
}
