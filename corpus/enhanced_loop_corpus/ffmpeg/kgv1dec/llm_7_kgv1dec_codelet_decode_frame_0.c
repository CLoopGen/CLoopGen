#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offsets[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    offsets[0] = -1;
    for (i = 1; i < 8; i++) {
        offsets[i] = offsets[i-1]; // Introduce loop-carried WAW and RAW dependency
    }
    // Note: This variant sets all elements to -1 indirectly via propagation,
    // creating a sequential data dependency chain (each write depends on prior write).
}
