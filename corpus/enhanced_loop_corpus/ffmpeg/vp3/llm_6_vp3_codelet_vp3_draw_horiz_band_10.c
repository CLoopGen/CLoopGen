#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried RAW (read-after-write) dependency
    // and modify data access pattern to create sequential dependency.
    offset[3] = 0;
    for (i = 4; i < 8; i++) {
        offset[i] = offset[i - 1] + 0; // RAW dependency: current depends on previous
    }
}
