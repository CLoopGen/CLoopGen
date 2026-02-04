#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t col;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[15];
    for (uint32_t i = 0; i < 15; i++) {
        indices[i] = (i * 3) % 15 + 1; // Generate a non-consecutive access pattern
    }
    for (col = 0; col < 15; col++) {
        // Indirect access using precomputed indices
        uint32_t idx = indices[col];
    }
}
