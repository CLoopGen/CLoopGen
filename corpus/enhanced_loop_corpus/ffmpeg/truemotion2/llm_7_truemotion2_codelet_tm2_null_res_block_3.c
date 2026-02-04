#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int deltas[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    deltas[0] = 0;
    for (i = 1; i < 16; i++) {
        deltas[i] = deltas[i-1] + 1; // Introduces loop-carried RAW dependency
        // Each iteration depends on the previous write to deltas[i-1]
        // Creates cumulative pattern instead of reset, changing semantics but maintaining validity
    }
    // Note: This variant changes behavior to create a sequence 0,1,...,15 instead of all zeros
    // Simulates accumulation with explicit loop-carried flow dependence
}
