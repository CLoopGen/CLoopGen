#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *histogram;
extern uint32_t total_windows;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with stride-like pattern via lookup)
    uint32_t indices[12000];
    for (int j = 0; j < 12000; j++) {
        indices[j] = j; // Populate linear index mapping (could be randomized or reordered in real use)
    }
    for (i = 0; i < 12000; i++) {
        total_windows += histogram[indices[i]];
    }
}
