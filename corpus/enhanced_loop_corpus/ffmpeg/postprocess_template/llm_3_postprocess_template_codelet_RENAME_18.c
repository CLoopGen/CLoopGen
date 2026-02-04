#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    uint64_t indices[256];
    for (i = 0; i < 256; i++) {
        indices[i] = i;
    }
    // Simple shuffle simulation (reversed order as deterministic indirect access)
    sum = 0;
    for (i = 0; i < 256; i++) {
        sum += yHistogram[indices[255 - i]];
    }
}
