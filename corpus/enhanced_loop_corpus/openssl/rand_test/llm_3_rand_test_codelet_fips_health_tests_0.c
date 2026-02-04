#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via calculated indices)
    size_t n = sizeof(buf);
    size_t indices[256]; // Simulate precomputed indirect indices (limited to 256 for stack safety)
    
    for (size_t j = 0; j < 256 && j < n; j++) {
        indices[j] = (j * 3) % n; // Generate scrambled access pattern
    }

    for (size_t j = 0; j < 256 && indices[j % 256] < n; j++) {
        size_t idx = indices[j % 256];
        buf[idx] = 255 & idx;
    }
}
